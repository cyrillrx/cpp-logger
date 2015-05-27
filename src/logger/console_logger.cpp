//
// Created by Cyril Leroux on 16/05/2015.
//

#include "console_logger.h"

#include <iostream>

void ConsoleLogger::DoWrite(const std::string& message) const
{
    std::cout << message << std::endl;
}