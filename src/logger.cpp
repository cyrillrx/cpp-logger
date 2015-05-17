//
// Created by Cyril Leroux on 01/05/2015.
//

#include "logger.h"

#include <chrono>  // chrono::system_clock
#include <sstream> // stringstream
#include <iomanip> // put_time


const std::string Logger::PREFIX_DEBUG = "DEBUG: ";
const std::string Logger::PREFIX_INFO = "INFO : ";
const std::string Logger::PREFIX_WARNING = "WARN : ";
const std::string Logger::PREFIX_ERROR = "ERROR: ";

std::string Logger::Prefix(const LogSeverity& severity)
{
    switch (severity) {

        case DEBUG:
            return PREFIX_DEBUG;

        case INFO:
            return PREFIX_INFO;

        case WARNING:
            return PREFIX_WARNING;

        default:
            return PREFIX_ERROR;
    }
}

/**
* %a	Abbreviated weekday name		=> Thu
* %A	Full weekday name				=> Thursday
* %b	Abbreviated month name			=> Aug
* %B	Full month name					=> August
* %c	Date and time representation	=> Thu Aug 23 14:55:02 2001
* %d	Day of the month (01-31)	    => 23
* %H	Hour in 24h format (00-23)		=> 14
* %I	Hour in 12h format (01-12)		=> 02
* %j	Day of the year (001-366)		=> 235
* %m	Month as a decimal number (01-12) =>08
* %M	Minute (00-59)					=> 55
* %p	AM or PM designation			=> PM
* %S	Second (00-61)					=> 02
* %U	Week number with the first Sunday as the first day of week one (00-53) => 33
* %w	Weekday as a decimal number with Sunday as 0 (0-6) => 4
* %W	Week number with the first Monday as the first day of week one (00-53) => 34
* %x	Date representation				=> 08/23/01
* %X	Time representation				=> 14:55:02
* %y	Year, last two digits (00-99)	=> 01
* %Y	Year							=> 2001
* %Z	Timezone name or abbreviation	=> CDT
* %%	A % sign						=> %
*/
std::string Logger::CurrentTime(const std::string& format) {

    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);

    std::stringstream ss;
    // ss << std::put_time(std::localtime(&in_time_t), format);

    const auto buffer_size = 80;
    char buffer[buffer_size];

    // note: localtime() is not threadsafe, lock with a mutex if necessary
    if (strftime(buffer, buffer_size, format.c_str(), localtime(&in_time_t))) {
        ss << buffer;
    }
    return ss.str();
}

void Logger::Debug(const std::string& message) const
{
    Write(LogSeverity::DEBUG, message);
}

void Logger::Info(const std::string& message) const
{
    Write(LogSeverity::INFO, message);
}

void Logger::Warning(const std::string& message) const
{
    Write(LogSeverity::WARNING, message);
}

void Logger::Error(const std::string& message) const
{
    Write(LogSeverity::ERROR, message);
}