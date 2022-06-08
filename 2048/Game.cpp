#define _CRT_SECURE_NO_WARNINGS
#include <ctime> 
#include "Game.h"
#include "Header.h"

TCHAR text_1[5];

Game* Game::ptr = NULL;  

int arr[4][4] = { 0,0,0,2,
				  0,0,0,0,
				  0,0,2,0,
				  0,0,0,0 };

void Plus(int choise)
{  
	switch (choise)
	{
	case 1:
	{
		for (short i1 = 0; i1 < 4; i1++)
		{
			for (short i2 = 0; i2 < 4; i2++)
			{
				if (arr[i1][i2] != 0)
				{
					if (arr[i1][i2 + 1] == arr[i1][i2])
					{
						arr[i1][i2 + 1] = arr[i1][i2 + 1] * 2;
						arr[i1][i2] = 0;
					}
				}
			}
		}
	}
	break;
	case 2:
	{
		for (short i1 = 0; i1 < 4; i1++)
		{
			for (short i2 = 0; i2 < 4; i2++)
			{
				if (arr[i1][i2] != 0)
				{
					if (arr[i1][i2 - 1] == arr[i1][i2])
					{
						arr[i1][i2 - 1] = arr[i1][i2 - 1] * 2;
						arr[i1][i2] = 0;
					}
				}
			}
		}
	}
	break;
	case 3:
	{
		for (short i1 = 0; i1 < 4; i1++)
		{
			for (short i2 = 0; i2 < 4; i2++)
			{
				if (arr[i1][i2] != 0)
				{
					if (arr[i1 - 1][i2] == arr[i1][i2])
					{
						arr[i1 - 1][i2] = arr[i1 - 1][i2] * 2;
						arr[i1][i2] = 0;
					}
				}
			}
		}
	}
	break;
	case 4:
	{ 
		for (short i1 = 0; i1 < 4; i1++)
		{
			for (short i2 = 0; i2 < 4; i2++)
			{
				if (arr[i1][i2] != 0)
				{
					if (arr[i1 + 1][i2] == arr[i1][i2])
					{
						arr[i1 + 1][i2] = arr[i1 + 1][i2] * 2;
						arr[i1][i2] = 0;
					}
				}
			}
		}
	}
	break;
	default:
		break;
	}
}

void RandNumber()
{
	srand(time(0));
	int x, y;
	int dd = 0;
	while (dd == 0)
	{
		x = rand() % 3;
		y = rand() % 4;
		if (arr[x][y] == 0)
		{
			arr[x][y] = 2;
			dd++;
		}
	}
}

void Cuality(int i1, int i2, int choise)
{
	srand(time(0));
	int x, y; 
	switch (choise)
	{
	case 1:
	{
		for (short i = 3; i > -1; i--)
		{
			if (arr[i1][i] == 0 && i > i2)
			{
				arr[i1][i] = arr[i1][i2];
				arr[i1][i2] = 0;
			}
		}
	}
		break;
	case 2:
	{
		for (short i = 0; i < 4; i++)
		{
			if (arr[i1][i] == 0 && i < i2)
			{
				arr[i1][i] = arr[i1][i2];
				arr[i1][i2] = 0;
			}
		}
	}
	break;
	case 3:
	{
		for (short i = 0; i < 4; i++)
		{
			if (arr[i][i2] == 0 && i < i1)
			{
				arr[i][i2] = arr[i1][i2];
				arr[i1][i2] = 0;
			}
		}
	}
	break;
	case 4:
	{
		for (short i = 3; i > -1; i--)
		{
			if (arr[i][i2] == 0 && i > i1)
			{
				arr[i][i2] = arr[i1][i2];
				arr[i1][i2] = 0;   
			}
		}  
	}
	break;
	default:
		break;
	}
}

Game::Game(void)
{
	ptr = this;
}

void Game::Cls_OnClose(HWND hwnd)
{
	EndDialog(hwnd, 0);
}

BOOL Game::Cls_OnInitDialog(HWND hwnd, HWND hwndFocus, LPARAM lParam)
{ 
	hButtonStrelk[0] = GetDlgItem(hwnd, IDC_RIGHT);
	hButtonStrelk[1] = GetDlgItem(hwnd, IDC_LEFT);
	hButtonStrelk[2] = GetDlgItem(hwnd, IDC_UP);
	hButtonStrelk[3] = GetDlgItem(hwnd, IDC_DOWN);  

	hStrelki[0] = (HBITMAP)LoadImage(HINSTANCE1, MAKEINTRESOURCE(IDB_BITMAP1), IMAGE_BITMAP, 0, 0, 0);
	hStrelki[1] = (HBITMAP)LoadImage(HINSTANCE1, MAKEINTRESOURCE(IDB_BITMAP2), IMAGE_BITMAP, 0, 0, 0); 
	hStrelki[2] = (HBITMAP)LoadImage(HINSTANCE1, MAKEINTRESOURCE(IDB_BITMAP3), IMAGE_BITMAP, 0, 0, 0);
	hStrelki[3] = (HBITMAP)LoadImage(HINSTANCE1, MAKEINTRESOURCE(IDB_BITMAP4), IMAGE_BITMAP, 0, 0, 0);

	SendMessage(hButtonStrelk[0], BM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hStrelki[0]));
	SendMessage(hButtonStrelk[1], BM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hStrelki[1]));
	SendMessage(hButtonStrelk[2], BM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hStrelki[2]));
	SendMessage(hButtonStrelk[3], BM_SETIMAGE, WPARAM(IMAGE_BITMAP), LPARAM(hStrelki[3]));
	
	 
	for (short i = 0; i < 16; i++)
	{
		hEdit[i] = GetDlgItem(hwnd, IDC_EDIT1 + i);
		EnableWindow(hEdit[i], SW_HIDE); 
	}
	
	int i = 0;
	for (short i1 = 0; i1 < 4; i1++)
	{
		for (short i2 = 0; i2 < 4; i2++)
		{
			wsprintf(text_1, TEXT("%d"), arr[i1][i2]);
			SetWindowText(hEdit[i], text_1);
			i++;
		}
	}

	return TRUE;
}

void Game::Cls_OnCommand(HWND hwnd, int id, HWND hwndCtl, UINT codeNotify)
{ 
	
	 
	switch (id)
	{
	case IDC_RIGHT: 
	{
		for (short i1 = 0; i1 < 4; i1++)
		{
			for (short i2 = 0; i2 < 4; i2++)
			{
				if (arr[i1][i2] != 0 && i2 != 3)
				{
					Cuality(i1, i2, 1);
					Plus(1);
				}
			}
		}
		RandNumber();
		int i = 0;
		for (short i1 = 0; i1 < 4; i1++)
		{
			for (short i2 = 0; i2 < 4; i2++)
			{
				wsprintf(text_1, TEXT("%d"), arr[i1][i2]);
				SetWindowText(hEdit[i], text_1);
				i++;
			}
		}
	}
		break;
	case IDC_LEFT: 
	{
		for (short i1 = 0; i1 < 4; i1++)
		{
			for (short i2 = 0; i2 < 4; i2++)
			{
				if (arr[i1][i2] != 0 && i2 != 0)
				{
					Cuality(i1, i2, 2);
					Plus(2);
				}
			}
		}
		RandNumber();
		int i = 0;
		for (short i1 = 0; i1 < 4; i1++)
		{
			for (short i2 = 0; i2 < 4; i2++)
			{
				wsprintf(text_1, TEXT("%d"), arr[i1][i2]);
				SetWindowText(hEdit[i], text_1);
				i++;
			}
		}
	}
		break;
	case IDC_UP: 
	{
		for (short i1 = 0; i1 < 4; i1++)
		{
			for (short i2 = 0; i2 < 4; i2++)
			{
				if (arr[i1][i2] != 0 && i1 != 0)
				{
					Cuality(i1, i2, 3);
					Plus(3);
				}
			}
		}
		RandNumber();
		int i = 0;
		for (short i1 = 0; i1 < 4; i1++)
		{
			for (short i2 = 0; i2 < 4; i2++)
			{
				wsprintf(text_1, TEXT("%d"), arr[i1][i2]);
				SetWindowText(hEdit[i], text_1);
				i++;
			}
		}
	}
		break;
	case IDC_DOWN: 
	{  
		for (short i1 = 0; i1 < 4; i1++)
		{
			for (short i2 = 0; i2 < 4; i2++)
			{
				if (arr[i1][i2] != 0 && i1 != 3)
				{
					Cuality(i1, i2, 4); 
					Plus(4);
				}
			}
		}
		RandNumber();
		int i = 0;
		for (short i1 = 0; i1 < 4; i1++)
		{
			for (short i2 = 0; i2 < 4; i2++)
			{
				wsprintf(text_1, TEXT("%d"), arr[i1][i2]);
				SetWindowText(hEdit[i], text_1);
				i++;
			}
		}
	}
		break;
	  
	} 
}

BOOL CALLBACK Game::DlgProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{ 
	switch (message)
	{
		HANDLE_MSG(hwnd, WM_CLOSE, ptr->Cls_OnClose);
		HANDLE_MSG(hwnd, WM_INITDIALOG, ptr->Cls_OnInitDialog);
		HANDLE_MSG(hwnd, WM_COMMAND, ptr->Cls_OnCommand);
	}
	return FALSE;
}