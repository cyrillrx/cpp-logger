//
// Created by Cyril Leroux on 01/05/2015.
//

#pragma once

#include <string>


enum LogSeverity
{
    ERROR = 1, WARNING, INFO, DEBUG
};

class Logger
{
private:

    static const std::string PREFIX_DEBUG;
    static const std::string PREFIX_INFO;
    static const std::string PREFIX_WARNING;
    static const std::string PREFIX_ERROR;

protected:
    static std::string Prefix(const LogSeverity& severity);

    static std::string CurrentTime(const std::string& format);

    LogSeverity severity_filter_;

    virtual void Write(const LogSeverity& severity, const std::string& message) const = 0;

public:

    Logger(const LogSeverity& severity_filter) : severity_filter_(severity_filter) { }

    Logger() : severity_filter_(ERROR) { }

    void Debug(const std::string& message) const;

    void Info(const std::string& message) const;

    void Warning(const std::string& message) const;

    void Error(const std::string& message) const;
};

