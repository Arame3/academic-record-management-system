#include "Logger.h"

Logger::Logger(const std::string& filePath)
    : outputFile(filePath, std::ios::app)
{
}


bool Logger::isOpen() const
{
    return outputFile.is_open();

}


void Logger::log(LogLevel level, const std::string& message)
{
    if (!isOpen())
    {
        return;
    }

    outputFile << "[" << logLevelToString(level) << "] "
        << message
        << std::endl;

}


void Logger::logInfo(const std::string& message)
{
    log(LogLevel::Info, message);

}


void Logger::logWarning(const std::string& message)
{
    log(LogLevel::Warning, message);

}


void Logger::logError(const std::string& message)
{
    log(LogLevel::Error, message);

}


std::string Logger::logLevelToString(LogLevel level) const
{
    switch (level)
    {
    case LogLevel::Info:
        return "INFO";

    case LogLevel::Warning:
        return "WARNING";

    case LogLevel::Error:
        return "ERROR";

    default:
        return "UNKNOWN";
    }

}