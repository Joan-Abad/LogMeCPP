#pragma once
#include "LogMeCPP.h"
#include <ostream>

//struct used to change the color of windows console messages
struct LOGGING_API ConsoleTextColor
{

    ConsoleTextColor(const char* AnsiCode)
    {
        this->AnsiCode = AnsiCode;
    }

    static ConsoleTextColor GetRedColor();
    static ConsoleTextColor GetGreenColor();
    static ConsoleTextColor GetYellowColor();
    static ConsoleTextColor GetBlueColor();
    static ConsoleTextColor GetDefaultColor();
    
    friend std::ostream& operator<<(std::ostream& os, const ConsoleTextColor& p)
    {
        os << p.AnsiCode;
        return os; 
    }
    
private:
    const char* AnsiCode;
};

class LOGGING_API Logger
{
public:

    virtual ConsoleTextColor GetMessageColor();
    virtual ConsoleTextColor GetWarningColor();
    virtual ConsoleTextColor GetErrorColor();
    
    //Logs a standard output message. Uses default console text color, represented with ConsoleTextColor::Default. 
    void LogMessage(const char* Msg);

    //Logs a warning output message. Uses ConsoleTextColor::Yellow for the text color. 
    void LogWarning(const char* WarningMsg);

    //Logs a standard output message. Uses default windows console text color. 
    void LogError(const char* ErrorMsg);

    
};
