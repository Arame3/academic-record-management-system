#pragma once

#include <fstream>

#include <string>

enum class LogLevel
{
    Info, 

    Warning,

    Error

};


class Logger
{
private:

    std::ofstream outputFile;

    std::string logLevelToString(LogLevel level) const;

public:

    explicit Logger(const std::string& filePath);

    bool isOpen() const;

    void log(LogLevel level, const std::string& message);

    void logInfo(const std::string& message);

    void logWarning(const std::string& message);

    void logError(const std::string& message);

};