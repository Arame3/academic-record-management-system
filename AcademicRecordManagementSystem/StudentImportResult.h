#pragma once

#include <cstddef>

struct StudentImportResult
{

    std::size_t receivedCount = 0;

    std::size_t importedCount = 0;

    std::size_t rejectedCount = 0;

    bool hasImportedAny() const
    {
        return importedCount > 0;

    }

    bool allImported() const
    {
        return receivedCount > 0 && rejectedCount == 0; 

    }

};