#include "LogMeCPP.h"
#include "Logger.h"

#include <iostream>

//LOGGING_API ConsoleTextColor ConsoleTextColor::RED("\033[31m");
//LOGGING_API ConsoleTextColor ConsoleTextColor::GREEN("\033[32m"); 
//LOGGING_API ConsoleTextColor ConsoleTextColor::YELLOW("\033[33m"); 
//LOGGING_API ConsoleTextColor ConsoleTextColor::BLUE("\033[34m");
//LOGGING_API ConsoleTextColor ConsoleTextColor::DEFAULT("\033[0m");

ConsoleTextColor ConsoleTextColor::GetRedColor()
{
    static ConsoleTextColor RED("\033[31m");
    return RED;
}

ConsoleTextColor ConsoleTextColor::GetGreenColor()
{
    static ConsoleTextColor GREEN("\03332m");
    return GREEN;                             
}

ConsoleTextColor ConsoleTextColor::GetYellowColor()
{
    static ConsoleTextColor YELLOW("\033[33m");
    return YELLOW;                             
}

ConsoleTextColor ConsoleTextColor::GetBlueColor()
{
    static ConsoleTextColor BLUE("\033[34m");
    return BLUE;                             
}

ConsoleTextColor ConsoleTextColor::GetDefaultColor()
{
    static ConsoleTextColor DEFAULT("\033[30m");
    return DEFAULT;                             
}

ConsoleTextColor Logger::GetMessageColor()
{
    return ConsoleTextColor::GetDefaultColor(); 
}

ConsoleTextColor Logger::GetWarningColor()
{
    return ConsoleTextColor::GetYellowColor();     
}

ConsoleTextColor Logger::GetErrorColor()
{
    return ConsoleTextColor::GetRedColor();     
}


void Logger::LogMessage(const char* Msg)
{
    std::cout << GetMessageColor() << Msg << "\033[0m\n";
}

void Logger::LogWarning(const char* WarningMsg)
{
    std::cout << GetWarningColor() << WarningMsg << "\033[0m\n";
}

void Logger::LogError(const char* ErrorMsg)
{
    std::cerr << GetErrorColor() << ErrorMsg << "\033[0m\n";
}
