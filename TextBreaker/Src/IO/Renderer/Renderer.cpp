#include "../../../Include/IO/Renderer/Renderer.hpp"

TextGameEngine::IO::ConsoleRenderer::Renderer::Renderer(short xSize, short ySize, int clearZDepth, Pixel clearPixelData)
{
    _stdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    _screenSize.X = xSize;
    _screenSize.Y = ySize;

    _clearZDepth = clearZDepth;
    _clearPixel = clearPixelData.pixelData;

    if (_screenSize.X < 0 || _screenSize.Y < 0)
    {
        _pixelCount = 0;
        _screenSize.X = 0;
        _screenSize.Y = 0;
    }

    if (_clearZDepth < _clearZDepthMin)
    {
        _clearZDepth = _clearZDepthMin;
    }
    else if (_clearZDepth > _clearZDepthMax)
    {
        _clearZDepth = _clearZDepthMax;
    }

    _pixelCount = static_cast<uint32_t>(_screenSize.X) * static_cast<uint32_t>(_screenSize.Y);

    _drawRegion.Left = 0;
    _drawRegion.Top = 0;
    _drawRegion.Right = _screenSize.X;
    _drawRegion.Bottom = _screenSize.Y;

    _zDepthBuffer = new int[_pixelCount];
    _pixelBuffer = new CHAR_INFO[_pixelCount];

    ClearPixelBuffer();
    ClearZDepthBuffer();
}

TextGameEngine::IO::ConsoleRenderer::Renderer::~Renderer()
{
    if (_zDepthBuffer != nullptr)
    {
        delete[] _zDepthBuffer;
    }

    if (_pixelBuffer != nullptr)
    {
        delete[] _pixelBuffer;
    }
}

bool TextGameEngine::IO::ConsoleRenderer::Renderer::Draw(const Pixel* pixels, uint32_t arrayLength)
{
    if (pixels == nullptr || _pixelBuffer == nullptr || _zDepthBuffer == nullptr)
    {
        return false;
    }

    for (uint32_t index = 0; index < arrayLength; index++)
    {
        int xPos = pixels[index].pos.x, yPos = pixels[index].pos.y, zPos = pixels[index].pos.z;

        if (xPos < 0 || xPos >= _screenSize.X || yPos < 0 || yPos >= _screenSize.Y)
        {
            continue;
        }

        uint32_t pixelCoord = static_cast<uint32_t>(yPos) * _screenSize.X + static_cast<uint32_t>(xPos);
        
        if (zPos < _zDepthBuffer[pixelCoord])
        {
            continue;
        }

        _zDepthBuffer[pixelCoord] = zPos;
        _pixelBuffer[pixelCoord] = pixels[index].pixelData;
    }

    return true;
}

bool TextGameEngine::IO::ConsoleRenderer::Renderer::SendToConsoleScreenBuffer()
{

    if (_pixelBuffer == nullptr || _stdOut == INVALID_HANDLE_VALUE)
    {
        return false;
    }

    return WriteConsoleOutputA(_stdOut, _pixelBuffer, _screenSize, _pixelBufferOriginPos, &_drawRegion);
}

void TextGameEngine::IO::ConsoleRenderer::Renderer::SetClearZDepth(int zDepth)
{
    _clearZDepth = zDepth;

    if (zDepth < _clearZDepthMin)
    {
        _clearZDepth = _clearZDepthMin;
    }
    else if (zDepth > _clearZDepthMax)
    {
        _clearZDepth = _clearZDepthMax;
    }
}
void TextGameEngine::IO::ConsoleRenderer::Renderer::SetClearPixel(Pixel pixel)
{
    _clearPixel = pixel.pixelData;
}

bool TextGameEngine::IO::ConsoleRenderer::Renderer::ClearZDepthBuffer()
{

    if (_zDepthBuffer == nullptr)
    {
        return false;
    }

    Utils::ArrayUtils::FillValue<int>(_zDepthBuffer, _clearZDepth, _pixelCount);

    return true;
}
bool TextGameEngine::IO::ConsoleRenderer::Renderer::ClearPixelBuffer()
{
    if (_pixelBuffer == nullptr)
    {
        return false;
    }

    Utils::ArrayUtils::FillValue<CHAR_INFO>(_pixelBuffer, _clearPixel, _pixelCount);

    return true;
}

bool TextGameEngine::IO::ConsoleRenderer::Renderer::CopyToBuffer(Pixel* pixels, uint32_t arrayLength)
{
    if (pixels == nullptr || _pixelBuffer == nullptr || _zDepthBuffer == nullptr || _pixelCount != arrayLength)
    {
        return false;
    }

    for (uint32_t index = 0, y = -1, x = 0; index < _pixelCount; index++)
    {
        x = index % _screenSize.X;

        if (index % _screenSize.Y == 0)
        {
            y++;
        }

        pixels[index].pixelData = _pixelBuffer[index];
        pixels[index].pos.x = x;
        pixels[index].pos.y = y;
        pixels[index].pos.z = _zDepthBuffer[index];
    }

    return true;
}