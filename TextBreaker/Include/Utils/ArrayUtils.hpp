#ifndef TEXT_GAME_ENGINE_ARRAY_UTILS_HEADER
#define TEXT_GAME_ENGINE_ARRAY_UTILS_HEADER

#include <stdint.h>

namespace TextGameEngine
{
    namespace Utils
    {
        namespace ArrayUtils
        {
            template<typename T>
            bool FillValue(T* array, const T& value, uint32_t arrayLength);
        }
    }
}

#include "../../../Src/Utils/ArrayUtilsTPP.hpp"

#endif