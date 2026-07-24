#pragma once

#include <cstddef>
#include <vector>

#include "Student.h"

struct StudentFileLoadResult
{
    bool fileOpened = false;

    std::size_t processedLineCount = 0;

    std::size_t loadedCount = 0;

    std::size_t rejectedCount = 0;


    std::vector<Student> students;


    bool hasLoadedAny() const
    {
        return loadedCount > 0;

    }

    bool hasRejectedRecords() const
    {
        return rejectedCount > 0;

    }

    bool allRecordsLoaded() const
    {
        return fileOpened
            && processedLineCount > 0
            && rejectedCount == 0;

    }

}; 