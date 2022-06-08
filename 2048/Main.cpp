#include "Game.h"
 
int WINAPI _tWinMain(HINSTANCE hInst, HINSTANCE hPrev, LPTSTR lpszCmdLine, int nCmdShow)
{ 
	Game game;  
	game.HINSTANCE1 = hInst;
	return DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), NULL, Game::DlgProc);
}