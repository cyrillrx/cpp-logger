//
// Created by Cyril Leroux on 16/05/2015.
//

#include "console_logger.h"

#include <iostream>


/**
 * Add date and time.
 * Specify the file to write in.
 * Write in the file.
 * @param message The message to log.
 */
void ConsoleLogger::Write(const LogSeverity& severity, const std::string& message) const
{
    if (severity > severity_filter_) {
        return;
    }
    std::cout << CurrentTime("%Y-%m-%d %H:%M:%S") + " - " + Prefix(severity) + message << std::endl;
}