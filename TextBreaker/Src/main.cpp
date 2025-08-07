#include<stdio.h>
#include <Windows.h>
#include <iostream>
#include "../Include/IO/ConsoleIOManager.hpp"
int main()
{
    TextGameEngine::IO::ConsoleIOManager mgr;


    std::cout <<mgr.SetCursorPosition({ -1,2 });
    std::cout << mgr.SetColor(9999);
}