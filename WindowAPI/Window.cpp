#include "Window.h"
#include <dwmapi.h>


LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
     switch (uMsg)
     {
     case WM_PAINT:
     {
          PAINTSTRUCT ps;
          HDC hdc = BeginPaint(hwnd, &ps);

          // All painting occurs here, between BeginPaint and EndPaint.

          FillRect(hdc, &ps.rcPaint, CreateSolidBrush(RGB(0x11, 0x11, 0x11)));

          EndPaint(hwnd, &ps);
     }
     break;
     case WM_DESTROY:
     {
          PostQuitMessage(0);
     }
     break;
     default:
          return DefWindowProc(hwnd, uMsg, wParam, lParam);
     }
     return 0;
}

Window::Window(int width, int height, const char* title, int style)
{
     const char* CLASS_NAME = "DwMyClass";

     WNDCLASS wc = {};
     wc.lpfnWndProc = WindowProc;
     wc.lpszClassName = CLASS_NAME;

     if (!RegisterClass(&wc))
     {
          MessageBoxA(NULL, (LPCSTR)"Unable to register windows class!", (LPCSTR)"Error", MB_ICONERROR | MB_OK);
          return;
     }

     this->hWnd = CreateWindowEx(0, CLASS_NAME, (LPCSTR)title, style, CW_USEDEFAULT, CW_USEDEFAULT, width, height, NULL, NULL, NULL, NULL);
}

void Window::show(void)
{
     ShowWindow(this->hWnd, 1);
     UpdateWindow(this->hWnd);

     int enabled = 1;
     DwmSetWindowAttribute(this->hWnd, 20, &enabled, sizeof(int));

     MSG msg;
     while (GetMessage(&msg, this->hWnd, 0, 0) > 0)
     {
          TranslateMessage(&msg);
          DispatchMessage(&msg);
     }
}

Window::~Window()
{
     CloseWindow(this->hWnd);
}
