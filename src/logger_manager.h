//
// Created by Cyril Leroux on 17/05/2015.
//

#pragma once

#include <vector>
#include "logger.h"

class LoggerManager
{

private:

    std::vector<Logger> loggers_;

public:

    std::vector<Logger> loggers() const { return loggers_; }

    void AddLogger(const Logger& logger);

    void Debug(const std::string& message) const;

    void Info(const std::string& message) const;

    void Warning(const std::string& message) const;

    void Error(const std::string& message) const;
};