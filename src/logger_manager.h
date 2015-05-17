//
// Created by Cyril Leroux on 17/05/2015.
//

#pragma once

#include <vector>
#include <memory>
#include "logger.h"

class LoggerManager
{

private:

    //std::vector<const std::unique_ptr<Logger>> loggers_;
    std::vector<const Logger*> loggers_;

public:

    //void AddLogger(const std::unique_ptr<Logger>& logger);
    void AddLogger(const Logger* logger);

    void Debug(const std::string& message) const;

    void Info(const std::string& message) const;

    void Warning(const std::string& message) const;

    void Error(const std::string& message) const;
};