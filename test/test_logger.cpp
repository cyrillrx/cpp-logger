#include <iostream>

#include "../src/logger/logger_manager.h"
#include "../src/logger/console_logger.h"

#include "gtest/gtest.h"

TEST(TestLogger, Log)
{
    auto logger = LoggerManager();
    std::unique_ptr<Logger> consoleLogger(new ConsoleLogger(WARNING));
    logger.AddLogger(consoleLogger);

    logger.Debug("Debug message.");
    logger.Info("Info message");
    logger.Warning("Warning message");
    logger.Error("Error message.");

    SUCCEED();
}

int main(int argc, char **argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}