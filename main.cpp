#include "tic_tac_toe.hpp"
#include <iostream>
#include <windows.h>

void MaximizeConsoleWindows()
{
    HWND consoleWindow = GetConsoleWindow();
    ShowWindow(consoleWindow, SW_MAXIMIZE);
}

void SetConsoleFontSize(int fontSize)
{
    CONSOLE_FONT_INFOEX cfi;
    cfi.cbSize = sizeof(cfi);
    cfi.nFont = 0;
    cfi.dwFontSize.X = 0; // Width of each character in the font
    cfi.dwFontSize.Y = fontSize; // Height
    cfi.FontFamily = FF_DONTCARE;
    cfi.FontWeight = FW_NORMAL;
    wcscpy_s(cfi.FaceName, L"Consolas"); // Choose your font
    SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

int main() {

    MaximizeConsoleWindows();
    SetConsoleFontSize(30);

    TicTacToe game;
    game.StartGame();

    std::cin.get();
    std::cin.get();
}
