#ifndef TEXT_GAME_ENGINE_PIXEL_HEADER
#define TEXT_GAME_ENGINE_PIXEL_HEADER

#include <Windows.h>
#include "Vector3Int.hpp"

namespace TextGameEngine
{
    namespace IO
    {
        namespace ConsoleRenderer
        {
            struct Pixel
            {
                Vector3Int pos;
                CHAR_INFO pixelData;
            };
        }
    }
}


#endif // !TEXT_GAME_ENGINE_PIXEL_HEADER
