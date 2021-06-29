#include <windows.h>
#include "vlc/vlc.h"

#define APPNAME "Advance Video Player"
char szAppName[] = APPNAME;  
char szTitle[]   = APPNAME;  

int w = 500;
int h = 500;

int IDD_VideoView = 0;
int IDD_Playbtn = 1;
int IDD_Stopbtn = 2;
int IDD_Pausebtn = 3;

HWND VideoView,Playbtn,Stopbtn,Pausebtn;
libvlc_media_player_t* MediaPlayer;

void SetMedia(HWND hwnd)
{
	libvlc_instance_t* Instance = libvlc_new(0, NULL);
    libvlc_media_t*  Media = libvlc_media_new_path (Instance, "cuc_ieschool.flv");
    MediaPlayer = libvlc_media_player_new_from_media (Media);
	libvlc_media_player_set_hwnd(MediaPlayer, hwnd);
    libvlc_media_release(Media);
}

HWND DrawButton(HWND hwnd, const char* Text, int x, int y, HMENU code)
{
	return CreateWindowA(TEXT("button"),(LPCTSTR)Text,WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, x, y, 70, 40, hwnd,code,NULL,NULL);
}

void DrawUI(HWND hwnd)
{
    VideoView = CreateWindow("STATIC", NULL, WS_VISIBLE | WS_CHILD | SS_BITMAP,10, 10, w - 20, h - 20, hwnd, (HMENU)IDD_VideoView, NULL, NULL);		
    Playbtn = DrawButton(hwnd, "Play",   70, h + 20, (HMENU)IDD_Playbtn);
    Stopbtn = DrawButton(hwnd, "Stop",   70*2  , h + 20, (HMENU)IDD_Stopbtn);
    Pausebtn = DrawButton(hwnd, "Pause", 70*3 , h + 20, (HMENU)IDD_Pausebtn);
	
	SetMedia(VideoView);
}


LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message) 
	{
        case WM_CREATE:
		    DrawUI(hwnd);
		    break;
		case WM_COMMAND:
		{
		    int no = LOWORD(wParam);
	    	if (no == IDD_Playbtn) libvlc_media_player_play(MediaPlayer);
	    	else if (no == IDD_Stopbtn) libvlc_media_player_stop(MediaPlayer);
	    	else if (no == IDD_Pausebtn) libvlc_media_player_pause(MediaPlayer);
			break;
        }
        case WM_DESTROY: 
		    PostQuitMessage(0);
			break;
        default: return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}
int APIENTRY WinMain(
        HINSTANCE hInstance,
        HINSTANCE hPrevInstance,
        LPSTR lpCmdLine,
        int nCmdShow
        )
{
    MSG msg;
    WNDCLASS wc;
    HWND hwnd;
    ZeroMemory(&wc, sizeof wc);
    wc.hInstance     = hInstance;
    wc.lpszClassName = szAppName;
    wc.lpfnWndProc   = (WNDPROC)WndProc;
    wc.style         = CS_DBLCLKS|CS_VREDRAW|CS_HREDRAW;
    wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
    wc.hIcon         = LoadIcon(NULL, IDI_APPLICATION);
    wc.hCursor       = LoadCursor(NULL, IDC_ARROW);
    if (FALSE == RegisterClass(&wc))
        return 0;
        hwnd = CreateWindow(
        szAppName,
        szTitle,
        WS_OVERLAPPEDWINDOW|WS_VISIBLE,
        CW_USEDEFAULT,
        CW_USEDEFAULT,
        w, h, 0,
        0,
        hInstance,
        0);
    if (NULL == hwnd)
        return 0;
        while (GetMessage(&msg, NULL, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    return msg.wParam;
}