#ifndef TEXT_GAME_ENGINE_CONSOLE_IO_MANAGER_HEADER
#define TEXT_GAME_ENGINE_CONSOLE_IO_MANAGER_HEADER

#include <stdio.h>
#include <stdarg.h>
#include <Windows.h>
#include <stdint.h>
#include "./Colors.hpp"


namespace TextGameEngine
{
    namespace IO
    {
        class ConsoleIOManager
        {
        private:
            HANDLE _stdIn = NULL;
            HANDLE _stdOut = NULL;
        public:
            ConsoleIOManager();
            ConsoleIOManager(const ConsoleIOManager&) = delete;
            ConsoleIOManager(ConsoleIOManager&&) = delete;

            int PrintToConsole(const char* const format, ...);
            int ScanFromConsole_s(const char* const format, ...);
            void SetColor(WORD colorBit);
            bool SetCursorPosition(COORD pos);

            bool IsKeyDown(int vKey);

        };
    }
}

#endif // !TEXT_GAME_ENGINE_CONSOLE_IO_MANAGER_HEADER
