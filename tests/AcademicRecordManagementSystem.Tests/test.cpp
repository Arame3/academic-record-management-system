#include "pch.h"
#include "Student.h"
#include "StudentManager.h"

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