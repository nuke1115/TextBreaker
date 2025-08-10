#ifndef TEXT_GAME_ENGINE_RENDERER_HEADER
#define TEXT_GAME_ENGINE_RENDERER_HEADER

#include <Windows.h>
#include <stdint.h>
#include "Pixel.hpp"
#include "../../Utils/ArrayUtils.hpp"

namespace TextGameEngine
{
    namespace IO
    {
        namespace ConsoleRenderer
        {
            class Renderer
            {
            private:
                HANDLE _stdOut = INVALID_HANDLE_VALUE;
                CHAR_INFO* _pixelBuffer = nullptr;
                int* _zDepthBuffer = nullptr;
                //저것들은 1차원 배열이지만, 접근하는건 2차원처럼 할거 ㅐㅐ
                
                CHAR_INFO _clearPixel;
                int _clearZDepth = 0;
                static constexpr int _clearZDepthMin = -2;
                static constexpr int _clearZDepthMax = 2;
                
                SMALL_RECT _drawRegion = { 0, };
                uint32_t _pixelCount = 0;
                COORD _screenSize = { 0, };
                static constexpr COORD _pixelBufferOriginPos = { 0, };
            public:
                Renderer(short xSize, short ySize, int clearZDepth, Pixel clearPixelData);
                Renderer(const Renderer&) = delete;
                Renderer(Renderer&&) = delete;
                ~Renderer();

                bool Draw(const Pixel* pixels, uint32_t arrayLength);

                bool SendToConsoleScreenBuffer();

                void SetClearZDepth(int zDepth);
                void SetClearPixel(Pixel pixel);

                bool ClearZDepthBuffer();
                bool ClearPixelBuffer();

                bool CopyToBuffer(Pixel* pixels, uint32_t arrayLength);
            };
        }
    }
}

#endif // !TEXT_GAME_ENGINE_RENDERER_HEADER
