//
// Created by Cyril Leroux on 16/05/2015.
//

#pragma once

#include "logger.h"

class ConsoleLogger : public Logger
{

protected:
    virtual void Write(const LogSeverity& severity, const std::string& message) const override;

public:
    ConsoleLogger(const LogSeverity& severity_filter) : Logger(severity_filter) { }

    ConsoleLogger() : Logger() { }
};
