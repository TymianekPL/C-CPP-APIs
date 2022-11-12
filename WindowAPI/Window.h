#ifndef WINDOW_H
#define WINDOW_H

#include <windows.h>

class Window
{
private:
     HWND hWnd;
public:
     Window(int width, int height, const char* title, int style);

     void show(void);

     ~Window();
};

#endif
