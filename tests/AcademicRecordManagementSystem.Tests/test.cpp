#include "pch.h"

#include <filesystem>
#include <fstream>

#include "Student.h"
#include "StudentManager.h"
#include "AcademicPolicy.h"
#include "StudentPersistenceService.h"

TEST
(
	StudentTests,
	ParameterizedConstructorStoresValidValues

)
{
	Student student(1, "Arame", 95.5);

	EXPECT_EQ(student.getId(), 1);
	EXPECT_EQ(student.getName(), "Arame");
	EXPECT_DOUBLE_EQ(student.getScore(), 95.5);

}

TEST
(
	StudentTests,
	ParameterizedConstructorReplacesInvalidValues

)
{
	Student student(-5, "", 120.0);

	EXPECT_EQ(student.getId(), 0);
	EXPECT_EQ(student.getName(), "Unknown");
	EXPECT_DOUBLE_EQ(student.getScore(), 0.0);

}

TEST
(
	StudentManagerTests,
	SupportsCompleteStudentWorkflow

)
{
	StudentManager manager;

	EXPECT_TRUE(manager.addStudent(Student(1, "Arame", 80.0)));
	EXPECT_TRUE(manager.addStudent(Student(2, "Anna", 95.0)));
	EXPECT_FALSE(manager.addStudent(Student(1, "Duplicate", 70.0)));

	EXPECT_EQ(manager.getCount(), 2);
	EXPECT_TRUE(manager.hasStudentById(1));
	EXPECT_DOUBLE_EQ(manager.getAverageScore(), 87.5);

	EXPECT_TRUE(manager.updateStudentScoreById(1, 90.0));
	EXPECT_TRUE(manager.updateStudentNameById(2, "Ani"));

	EXPECT_EQ(manager.findStudentIndexByName("Ani"), 1);
	EXPECT_DOUBLE_EQ(manager.getHighestScore(), 95.0);

	EXPECT_TRUE(manager.removeStudentById(1));
	EXPECT_FALSE(manager.hasStudentById(1));
	EXPECT_EQ(manager.getCount(), 1);

}

TEST
(
	AcademicPolicyTests,
	ClassifiesScoresUsingConfiguredThresholds
)
{
	AcademicPolicy policy(50.0, 90.0);

	EXPECT_DOUBLE_EQ(policy.getPassingScore(), 50.0);
	EXPECT_DOUBLE_EQ(policy.getExcellentScore(), 90.0);

	EXPECT_EQ(policy.getScoreCategory(-1.0), ScoreCategory::Invalid);
	EXPECT_EQ(policy.getScoreCategory(49.0), ScoreCategory::Failed);
	EXPECT_EQ(policy.getScoreCategory(50.0), ScoreCategory::Passed);
	EXPECT_EQ(policy.getScoreCategory(89.0), ScoreCategory::Passed);
	EXPECT_EQ(policy.getScoreCategory(90.0), ScoreCategory::Excellent);
	EXPECT_EQ(policy.getScoreCategory(101.0), ScoreCategory::Invalid);

	EXPECT_EQ
	(
		policy.scoreCategoryToString(ScoreCategory::Excellent),
		"Excellent"
	);

}

TEST
(
	StudentPersistenceServiceTests,
	SavesLoadsAndRejectsInvalidRecords
)
{
	const std::filesystem::path csvPath =
		std::filesystem::temp_directory_path()
		/ "academic_record_persistence_test.csv";

	const std::filesystem::path logPath =
		std::filesystem::temp_directory_path()
		/ "academic_record_persistence_test.log";

	std::filesystem::remove(csvPath);
	std::filesystem::remove(logPath);

	{
		Logger logger(logPath.string());

		ASSERT_TRUE(logger.isOpen());

		StudentManager sourceManager;

		ASSERT_TRUE
		(
			sourceManager.addStudent
			(
				Student(1, "Arame", 88.0)
			)
		);

		ASSERT_TRUE
		(
			sourceManager.addStudent
			(
				Student(2, "Anna", 95.0)
			)
		);

		StudentPersistenceService saveService
		(
			sourceManager,
			logger
		);

		ASSERT_TRUE
		(
			saveService.saveStudentsToCsv
			(
				csvPath.string()
			)
		);

		{
			std::ofstream csvFile
			(
				csvPath,
				std::ios::app
			);

			ASSERT_TRUE(csvFile.is_open());

			csvFile << "2,Duplicate,70" << std::endl;
			csvFile << "invalid,row" << std::endl;
		}

		StudentManager loadedManager;

		StudentPersistenceService loadService
		(
			loadedManager,
			logger
		);

		StudentPersistenceLoadResult result =
			loadService.loadStudentsFromCsv
			(
				csvPath.string()
			);

		EXPECT_TRUE(result.wasFileOpened());

		EXPECT_EQ
		(
			result.fileLoadResult.processedLineCount,
			4
		);

		EXPECT_EQ
		(
			result.fileLoadResult.loadedCount,
			3
		);

		EXPECT_EQ
		(
			result.fileLoadResult.rejectedCount,
			1
		);

		EXPECT_EQ
		(
			result.importResult.importedCount,
			2
		);

		EXPECT_EQ
		(
			result.importResult.rejectedCount,
			1
		);

		EXPECT_TRUE(result.hasImportedAny());
		EXPECT_TRUE(result.hasRejectedRecords());
		EXPECT_FALSE(result.completedWithoutRejections());

		EXPECT_EQ(loadedManager.getCount(), 2);
		EXPECT_TRUE(loadedManager.hasStudentById(1));
		EXPECT_TRUE(loadedManager.hasStudentById(2));
	}

	std::filesystem::remove(csvPath);
	std::filesystem::remove(logPath);

}