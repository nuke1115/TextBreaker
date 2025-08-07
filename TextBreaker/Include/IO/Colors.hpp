#ifndef TEXT_GAME_ENGINE_COLOR_HEADER
#define TEXT_GAME_ENGINE_COLOR_HEADER

#include <Windows.h>

namespace TextGameEngine
{
    namespace IO
    {
        struct TextColors
        {
            static constexpr WORD BLACK = 0;
            static constexpr WORD DARK_BLUE = FOREGROUND_BLUE;
            static constexpr WORD DARK_GREEN = FOREGROUND_GREEN;
            static constexpr WORD DARK_CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE;
            static constexpr WORD DARK_RED = FOREGROUND_RED;
            static constexpr WORD DARK_MAGENTA = FOREGROUND_RED | FOREGROUND_BLUE;
            static constexpr WORD DARK_YELLOW = FOREGROUND_RED | FOREGROUND_GREEN;
            static constexpr WORD GRAY = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE;

            static constexpr WORD LIGHT_BLACK = FOREGROUND_INTENSITY;
            static constexpr WORD LIGHT_BLUE = FOREGROUND_BLUE | FOREGROUND_INTENSITY;
            static constexpr WORD LIGHT_GREEN = FOREGROUND_GREEN | FOREGROUND_INTENSITY;
            static constexpr WORD LIGHT_CYAN = FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
            static constexpr WORD LIGHT_RED = FOREGROUND_RED | FOREGROUND_INTENSITY;
            static constexpr WORD LIGHT_MAGENTA = FOREGROUND_RED | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
            static constexpr WORD LIGHT_YELLOW = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY;
            static constexpr WORD WHITE = FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY;
        };

        struct BackgroundColors
        {
            static constexpr WORD BLACK = 0;
            static constexpr WORD DARK_BLUE = BACKGROUND_BLUE;
            static constexpr WORD DARK_GREEN = BACKGROUND_GREEN;
            static constexpr WORD DARK_CYAN = BACKGROUND_GREEN | BACKGROUND_BLUE;
            static constexpr WORD DARK_RED = BACKGROUND_RED;
            static constexpr WORD DARK_MAGENTA = BACKGROUND_RED | BACKGROUND_BLUE;
            static constexpr WORD DARK_YELLOW = BACKGROUND_RED | BACKGROUND_GREEN;
            static constexpr WORD GRAY = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE;

            static constexpr WORD LIGHT_BLACK = BACKGROUND_INTENSITY;
            static constexpr WORD LIGHT_BLUE = BACKGROUND_BLUE | BACKGROUND_INTENSITY;
            static constexpr WORD LIGHT_GREEN = BACKGROUND_GREEN | BACKGROUND_INTENSITY;
            static constexpr WORD LIGHT_CYAN = BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
            static constexpr WORD LIGHT_RED = BACKGROUND_RED | BACKGROUND_INTENSITY;
            static constexpr WORD LIGHT_MAGENTA = BACKGROUND_RED | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
            static constexpr WORD LIGHT_YELLOW = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_INTENSITY;
            static constexpr WORD WHITE = BACKGROUND_RED | BACKGROUND_GREEN | BACKGROUND_BLUE | BACKGROUND_INTENSITY;
        };
    }
}

#endif // !TEXT_GAME_ENGINE_COLOR_HEADER
