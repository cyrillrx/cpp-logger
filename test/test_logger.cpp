#include <iostream>

#include "../src/logger_manager.h"
#include "../src/console_logger.h"

#include "gtest/gtest.h"

TEST(TestLogger, Log)
{

    std::cout << "***************************************" << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "***************************************" << std::endl;
    LoggerManager logger = LoggerManager();
    ConsoleLogger consoleLogger(WARNING);

    logger.AddLogger(&consoleLogger);

    logger.Debug("Test message to log : D");
    logger.Info("Test message to log : I");
    logger.Warning("Test message to log : W");
    logger.Error("Test message to log : E");

    std::cout << "***************************************" << std::endl;
    std::cout << "***************************************" << std::endl;
    std::cout << "***************************************" << std::endl;

    SUCCEED();
}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}