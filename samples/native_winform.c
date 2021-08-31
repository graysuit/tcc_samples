#include <windows.h>

#define NAME "Sample"
#define TITLE "Hello"

//WndProc() will handle all form events like form created, button size changed etc..
LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message) 
	{
        case WM_DESTROY:
            PostQuitMessage(0);
            break;
        default:
            return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}

//WinMain() where code starts
int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    MSG msg;
    WNDCLASS wc;
  
    ZeroMemory(&wc, sizeof wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = NAME;
    wc.lpfnWndProc   = (WNDPROC)WndProc;                     //WndProc() will handle events like form created, button size changed etc..
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);  //Form Back color as WHITE
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);

    if (FALSE == RegisterClass(&wc)) return 0;
    HWND hwnd = CreateWindow(NAME, TITLE, WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT, 360, 240, 0, 0, hInstance, 0);
    
	if (NULL == hwnd) return 0;
	
	while (GetMessage(&msg, NULL, 0, 0) > 0) 
	{
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return msg.wParam;
}
