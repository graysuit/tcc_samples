#include <windows.h>

HWND RESULTS;
int w = 50;
int h = 50;

void DrawButton(HWND hwnd, const char* Text, int x, int y, int code)
{
	CreateWindowA(TEXT("button"),(LPCTSTR)Text,WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON, x, y, w, h, hwnd,(HMENU)code,NULL,NULL);
}

const char* texts[] = {
    "7","8","9","/",
    "4","5","6","*",
    "1","2","3","-",
    "0",".","=","+"
};
int textsLenght = (int)(sizeof(texts) / sizeof(texts[0]));
int TotalColms = 4;

void DrawControls(HWND hwnd)
{
	RESULTS = CreateWindowEx(WS_EX_TRANSPARENT, TEXT("Edit"), TEXT(""), WS_CHILD | WS_VISIBLE | SS_LEFT | WS_SYSMENU, w, h - 25, w * TotalColms, h - 30, hwnd, (HMENU)20, NULL, NULL);
	int colm = 1;
	int row = 1;
	for (int text = 0; text < textsLenght; text++)
	{
		DrawButton(hwnd, texts[text], w * colm, h * row, text);
		if (textsLenght / colm == TotalColms)
		{ 
			colm = 0;
			row++;
		}
		colm++;
	}
}

void appendText(LPARAM Text)
{
	int Lenght = GetWindowTextLength(RESULTS);
	SendMessage(RESULTS, EM_SETSEL, Lenght, Lenght);
	SendMessage(RESULTS, EM_REPLACESEL, TRUE, Text);
}
void Calculate()
{
    //This is an calculator which can't really calculate currently. LOL
    //yes, because, lack of knowledge
	//I was thinking of evaluating expression via string and displaying on screen
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	    case WM_CREATE:
	    	DrawControls(hwnd);
	    	break;
	    case WM_COMMAND:
	    {
	    	int no = LOWORD(wParam);
	    	if (no > -1 && no < textsLenght)
	    	{
	    		if (strcmp(texts[no], "=") == 0) Calculate();
				else appendText((LPARAM)texts[no]);
			}
	    	break;
	    }
	    case WM_DESTROY: PostQuitMessage(0);
	    default: return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return 0;
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MSG msg;
	WNDCLASS wc;
	HWND hwnd;
	ZeroMemory(&wc, sizeof wc);
	wc.hInstance = hInstance;
	wc.lpszClassName = TEXT("Calculator");
	wc.lpfnWndProc = (WNDPROC)WndProc;
	wc.style = CS_DBLCLKS | CS_VREDRAW | CS_HREDRAW;
	wc.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	if (FALSE == RegisterClass(&wc)) return 0;
	hwnd = CreateWindowW(
		L"Calculator", L"Calculator"
		, WS_OVERLAPPEDWINDOW | WS_VISIBLE, CW_USEDEFAULT, CW_USEDEFAULT,
		w * (TotalColms + 2) , (h * (TotalColms + 2)) + 25 
		, 0, 0, hInstance, 0);
	if (NULL == hwnd) return 0;
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return msg.wParam;
}