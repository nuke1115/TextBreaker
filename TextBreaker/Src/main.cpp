#include<stdio.h>
#include <Windows.h>
#include <iostream>
#include "../Include/IO/ConsoleIOManager.hpp"



void f(PCHAR_INFO c, char b)
{
    c->Char.AsciiChar = b;
    c->Attributes = b;
}

void cls(HANDLE hConsole)
{
    
}
#include "../Include/Utils/ArrayUtils.hpp"
#include "../Include/IO/Renderer/Renderer.hpp"
using namespace TextGameEngine;
using namespace IO;
using namespace ConsoleRenderer;

void Set(Pixel* p, char c, Vector3Int pos, int attrib)
{
    p->pos = pos;
    p->pixelData.Char.AsciiChar = c;
    p->pixelData.Attributes = attrib;
}

int main()
{
    Pixel p = { 0, };
    Renderer rdr(2, 2, 0, p);

    Pixel obj[2][2], obj2[2][2];


    Set(&obj[0][0], 'a', Vector3Int{ 0,0,0 }, BackgroundColors::GRAY | TextColors::BLACK);
    Set(&obj[0][1], 'b', Vector3Int{ 0,1,0 }, BackgroundColors::GRAY | TextColors::BLACK);
    Set(&obj[1][0], 'c', Vector3Int{ 1,0,0 }, BackgroundColors::GRAY | TextColors::BLACK);
    Set(&obj[1][1], 'd', Vector3Int{ 1,1,0 }, BackgroundColors::GRAY | TextColors::BLACK);

    rdr.Draw(obj[0], 4);
    rdr.SendToConsoleScreenBuffer();
    
    rdr.CopyToBuffer(obj2[0], 4);
    rdr.ClearPixelBuffer();
    rdr.ClearZDepthBuffer();
   

    while (1)
    {
        for (int y = 0; y < 2; y++)
        {
            for (int x = 0; x < 2; x++)
            {
                obj2[y][x].pixelData.Attributes++;
            }
        }

        rdr.Draw(obj2[0], 4);
        rdr.SendToConsoleScreenBuffer();

        getchar();
    }

    
}