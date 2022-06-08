#pragma once
#include "Header.h"

class Game
{ 
public:
	Game(void);
	static BOOL CALLBACK DlgProc(HWND hWnd, UINT mes, WPARAM wp, LPARAM lp);
	static Game* ptr;
	BOOL Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam);
	void Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify);
	void Cls_OnClose(HWND hwnd);
	HWND hEdit[16], hStart, hRadio[3], hButtonStrelk[4];
	HINSTANCE HINSTANCE1;
	HBITMAP hStrelki[4];
};