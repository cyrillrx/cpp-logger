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

    std::vector<std::unique_ptr<Logger>> loggers_;

public:

    void AddLogger(std::unique_ptr<Logger>& logger);

    void Debug(const std::string& message) const;

    void Info(const std::string& message) const;

    void Warning(const std::string& message) const;

    void Error(const std::string& message) const;
};