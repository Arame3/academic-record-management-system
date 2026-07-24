#include "StudentPersistenceService.h"

#include <string>

#include "StudentFileStorage.h"

StudentPersistenceService::StudentPersistenceService
(
    StudentManager& manager,
    Logger& logger
)
    : manager(manager), logger(logger)
{
}


bool StudentPersistenceService::saveStudentsToCsv(
    const std::string& filePath
)
{
    bool savedSuccessfully = StudentFileStorage::saveToCsv(
        filePath,
        manager.getStudents()
    );

    if (savedSuccessfully)
    {
        logger.logInfo(
            "Saved "
            + std::to_string(manager.getCount())
            + " student record(s) to CSV file: "
            + filePath
        );
    }
    else
    {
        logger.logError(
            "Failed to save student records to CSV file: "
            + filePath
        );
    }

    return savedSuccessfully;
}


StudentPersistenceLoadResult StudentPersistenceService::loadStudentsFromCsv
(
    const std::string& filePath
)

{
    StudentPersistenceLoadResult result;

    result.fileLoadResult = StudentFileStorage::loadFromCsv(filePath);

    if (!result.fileLoadResult.fileOpened)
    {
        logger.logError(
            "Failed to open CSV file for loading: "
            + filePath
        );

        return result;
    }

    result.importResult = manager.importStudents
    (
        result.fileLoadResult.students
    );

    logger.logInfo
    (
        "Processed "
        + std::to_string(result.fileLoadResult.processedLineCount)
        + " CSV record(s) from file: "
        + filePath
    );

    logger.logInfo
    (
        "Imported "
        + std::to_string(result.importResult.importedCount)
        + " student record(s)."
    );

    if (result.fileLoadResult.rejectedCount > 0)
    {
        logger.logWarning
        (
            "Rejected "
            + std::to_string(result.fileLoadResult.rejectedCount)
            + " malformed CSV record(s)."
        );
    }

    if (result.importResult.rejectedCount > 0)
    {
        logger.logWarning
        (
            "Rejected "
            + std::to_string(result.importResult.rejectedCount)
            + " student record(s) because of invalid or duplicate IDs."
        );
    }

    if (result.completedWithoutRejections())
    {
        logger.logInfo
        (
            "CSV import completed without rejected records."
        );
    }

    return result;

}