#pragma once

#include "StudentFileLoadResult.h"
#include "StudentImportResult.h"

struct StudentPersistenceLoadResult
{
    StudentFileLoadResult fileLoadResult;

    StudentImportResult importResult;


    bool wasFileOpened() const
    {
        return fileLoadResult.fileOpened;

    }

    bool hasImportedAny() const
    {
        return importResult.importedCount > 0;

    }

    bool hasRejectedRecords() const
    {
        return fileLoadResult.rejectedCount > 0
            || importResult.rejectedCount > 0;

    }

    bool completedWithoutRejections() const
    {
        return wasFileOpened() && !hasRejectedRecords();

    }

};