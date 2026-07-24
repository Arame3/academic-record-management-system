#pragma once

#include <string>

#include "Logger.h"
#include "StudentManager.h"
#include "StudentPersistenceLoadResult.h"

class StudentPersistenceService
{
private:

    StudentManager& manager;

    Logger& logger;

public:
   
    StudentPersistenceService
    (
        StudentManager& manager,
        Logger& logger
    );

    bool saveStudentsToCsv(const std::string& filePath);

    StudentPersistenceLoadResult loadStudentsFromCsv(
        const std::string& filePath
    );

};