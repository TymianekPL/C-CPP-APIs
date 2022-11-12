#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>
#include "../Logger/Logger.h"

#ifdef __cplusplus

class Window
{
private:
    HWND hWnd;
    Logger* log;
public:
    Window(int width, int height, const char* title, int style);

    void show(void);

    ~Window();
};

#else // ! C++

#error C is not suppoted yet!

#endif // ! C++

#endif
