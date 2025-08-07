#ifndef TEXT_GAME_ENGINE_COLOR_HEADER
#define TEXT_GAME_ENGINE_COLOR_HEADER

#include <Windows.h>

namespace TextGameEngine
{
    namespace IO
    {
        struct TextColors
        {
            static constexpr DWORD BLACK = 0;
            static constexpr DWORD DARK_BLUE = FOREGROUND_BLUE;
            static constexpr DWORD DARK_GREEN = FOREGROUND_GREEN;
            static constexpr DWORD DARK_CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE;
            static constexpr DWORD DARK_RED = FOREGROUND_RED;
            static constexpr DWORD DARK_MAGENTA = FOREGROUND_RED | FOREGROUND_BLUE;
            static constexpr DWORD DARK_YELLOW = FOREGROUND_RED | FOREGROUND_GREEN;
            static constexpr DWORD GRAY = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;

            static constexpr DWORD LIGHT_BLACK = FOREGROUND_INTENSITY;
            static constexpr DWORD LIGHT_BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
            static constexpr DWORD LIGHT_GREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
            static constexpr DWORD LIGHT_CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
            static constexpr DWORD LIGHT_RED = FOREGROUND_RED | FOREGROUND_INTENSITY;
            static constexpr DWORD LIGHT_MAGENTA = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
            static constexpr DWORD LIGHT_YELLOW = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
            static constexpr DWORD WHITE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        };

        struct BackgroundColors
        {
            static constexpr DWORD BLACK = 0;
            static constexpr DWORD DARK_BLUE = BACKGROUND_BLUE;
            static constexpr DWORD DARK_GREEN = BACKGROUND_GREEN;
            static constexpr DWORD DARK_CYAN = BACKGROUND_GREEN | BACKGROUND_BLUE;
            static constexpr DWORD DARK_RED = BACKGROUND_RED;
            static constexpr DWORD DARK_MAGENTA = BACKGROUND_RED | BACKGROUND_BLUE;
            static constexpr DWORD DARK_YELLOW = BACKGROUND_RED | BACKGROUND_GREEN;
            static constexpr DWORD GRAY = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;

            static constexpr DWORD LIGHT_BLACK = BACKGROUND_INTENSITY;
            static constexpr DWORD LIGHT_BLUE = BACKGROUND_BLUE | BACKGROUND_INTENSITY;
            static constexpr DWORD LIGHT_GREEN = BACKGROUND_GREEN | BACKGROUND_INTENSITY;
            static constexpr DWORD LIGHT_CYAN = BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
            static constexpr DWORD LIGHT_RED = BACKGROUND_RED | BACKGROUND_INTENSITY;
            static constexpr DWORD LIGHT_MAGENTA = BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
            static constexpr DWORD LIGHT_YELLOW = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
            static constexpr DWORD WHITE = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
        };
    }
}

#endif // !TEXT_GAME_ENGINE_COLOR_HEADER
