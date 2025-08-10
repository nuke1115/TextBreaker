#ifndef TEXT_GAME_ENGINE_ARRAY_UTILS_TPP_HEADER
#define TEXT_GAME_ENGINE_ARRAY_UTILS_TPP_HEADER

#include <stdint.h>

template<typename T>
bool TextGameEngine::Utils::ArrayUtils::FillValue(T* array, const T& value, uint32_t arrayLength)
{
    if (array == nullptr)
    {
        return false;
    }

   
    for (uint32_t index = 0; index < arrayLength; index++)
    {
        array[index] = value;
    }

    return true;
}

#endif