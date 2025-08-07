#include "../../Include/IO/ConsoleIOManager.hpp"

TextGameEngine::IO::ConsoleIOManager::ConsoleIOManager()
{
    _stdIn = GetStdHandle(STD_INPUT_HANDLE);
    _stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
}


int TextGameEngine::IO::ConsoleIOManager::PrintToConsole(const char* const format, ...)
{
    va_list args;
    va_start(args, format);

    int retValue = vprintf(format, args);

    va_end(args);
    return retValue;
}

int TextGameEngine::IO::ConsoleIOManager::ScanFromConsole_s(const char* const format, ...)
{
    va_list args;
    va_start(args, format);

    int retValue = vscanf_s(format, args);

    va_end(args);
    return retValue;
}

void TextGameEngine::IO::ConsoleIOManager::SetColor(WORD colorBit)
{
    SetConsoleTextAttribute(_stdOut, colorBit);
}