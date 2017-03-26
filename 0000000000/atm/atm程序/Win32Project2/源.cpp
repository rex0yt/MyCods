#include <windows.h>
#include "resource.h"
#include <stdio.h>
#include <string.h>

#define MAXN 10000
#define N 20

struct UserInfo {
	char user_name[N];
	char user_psw[N];
	float money;
};

UserInfo UserArr[MAXN];

int UserCount = 0;
int CurtUser = -1;

int FindUserName(CONST char *s)
{
	for (int i = 0; i < UserCount; ++i)
	{
		if (strcmp(s, UserArr[i].user_name) == 0)
		{
			return i;
		}
	}
	return -1;
}

bool CmpPsw(int ArgUserName,const char *s)
{
	if (strcmp(UserArr[ArgUserName].user_psw, s) == 0)
	{
		return true;
	}
	return false;
}

void CenterWindows(HWND hDlg)
{
	int cx = GetSystemMetrics(SM_CXSCREEN);
	int cy = GetSystemMetrics(SM_CYSCREEN);

	RECT rect;
	GetWindowRect(hDlg, &rect);

	int nWidth = rect.right - rect.left;
	int nHeight = rect.bottom - rect.top;
	int x = (cx - nWidth) / 2;
	int y = (cy - nHeight) / 2;

	MoveWindow(hDlg, x, y, nWidth, nHeight, TRUE);
	
}

BOOL MainOnCommand(HWND   hDlg, UINT   Msg, WPARAM wParam, LPARAM lParam)
{
	int nID = LOWORD(wParam);
	char RestMoney[N],AdtnMoney[N];
	float Rest,Adtn;

	switch (nID)
	{
	case IDQUERY:
	{
		Rest = UserArr[CurtUser].money;
		sprintf_s(RestMoney, "%f", Rest);
		SetDlgItemTextA(hDlg, IDC_MAIN, RestMoney);
		return TRUE;
		break;
	}
	case IDADD:
	{
		Rest = UserArr[CurtUser].money;
		GetDlgItemTextA(hDlg, IDC_MAIN, AdtnMoney, sizeof(AdtnMoney));
		if (strcmp(AdtnMoney, "\0") == 0)
		{
			MessageBoxA(hDlg, "瞎几把乱输！！！", "滚蛋：", MB_ICONWARNING);
			return true;
		}
		Adtn = atof(AdtnMoney);
		UserArr[CurtUser].money += Adtn;
		MessageBoxA(hDlg, "存款成功！", "您好：", MB_OK);
		SetDlgItemTextA(hDlg, IDC_MAIN, '\0');
		/*Rest += Adtn;
		sprintf_s(RestMoney, "%f", Rest);
		SetDlgItemTextA(hDlg, IDC_MAIN, RestMoney);*/
		return TRUE;
		break;
	}
	case IDSUB:
	{
		Rest = UserArr[CurtUser].money;
		GetDlgItemTextA(hDlg, IDC_MAIN, AdtnMoney, sizeof(AdtnMoney));
		if (strcmp(AdtnMoney, "\0") == 0)
		{
			MessageBoxA(hDlg, "瞎几把乱输！！！", "滚蛋：", MB_ICONWARNING);
			return true;
		}
		Adtn = atof(AdtnMoney);
		if (Rest < Adtn)
		{
			MessageBoxA(hDlg, "穷B，钱不够了！！！", "滚蛋：", MB_ICONWARNING);
			SetDlgItemTextA(hDlg, IDC_MAIN, '\0');
		}
		else
		{
			UserArr[CurtUser].money -= Adtn;
			MessageBoxA(hDlg, "取款成功！", "您好：", MB_OK);
			SetDlgItemTextA(hDlg, IDC_MAIN, '\0');
		}
		/*Rest -= Adtn;
		sprintf_s(RestMoney, "%f", Rest);
		SetDlgItemTextA(hDlg, IDC_MAIN, RestMoney);*/
		return TRUE;
		break;
	}
	case IDEXIT:
	case IDCANCEL:
		MessageBoxA(hDlg, "感谢使用 ‘有钱人’ATM！", "您好：", MB_OK);
		EndDialog(hDlg, IDCANCEL);
		return TRUE;
		break;
	}
	return false;
}

BOOL OnCommand(HWND   hDlg, UINT   Msg, WPARAM wParam, LPARAM lParam)
{
	int nID = LOWORD(wParam);
	char username[N], pasword[N];

	switch (nID)
	{
	case IDLOGIN:
	{
		GetDlgItemTextA(hDlg, IDC_USERNAME, username, sizeof(username));
		GetDlgItemTextA(hDlg, IDC_PSW, pasword, sizeof(pasword));
		if (strcmp(username, "\0") == 0|| strcmp(pasword, "\0") == 0)
		{
			MessageBoxA(hDlg, "瞎几把乱输！！！", "滚蛋：", MB_ICONWARNING);
			return true;
		}
		int ArgUserName = FindUserName(username);
		if (ArgUserName != -1)
		{
			if (CmpPsw(ArgUserName, pasword))
			{
				CurtUser = ArgUserName;
				EndDialog(hDlg, IDLOGIN);
			}
			else
			{
				MessageBoxA(hDlg, "密码错误！", "错误提示：", MB_ICONWARNING);
			}
		}
		else
		{
			MessageBoxA(hDlg, "用户不存在！", "错误提示：", MB_ICONWARNING);
		}
		return TRUE;
		break;
	}
	case IDREG:
	{
		GetDlgItemTextA(hDlg, IDC_USERNAME, username, sizeof(username));
		GetDlgItemTextA(hDlg, IDC_PSW, pasword, sizeof(pasword));
		if (strcmp(username, "\0") == 0 || strcmp(pasword, "\0") == 0)
		{
			MessageBoxA(hDlg, "瞎几把乱输！！！", "滚蛋：", MB_ICONWARNING);
			return true;
		}
		int ArgUserName = FindUserName(username);
		if (ArgUserName != -1)
		{
			MessageBoxA(hDlg, "用户存在！", "错误提示：", MB_ICONWARNING);
		}
		else
		{
			strcpy_s(UserArr[UserCount].user_name, username);
			strcpy_s(UserArr[UserCount].user_psw, pasword);
			UserArr[UserCount].money = 0;
			UserCount++;
			MessageBoxA(hDlg, "注册成功！", "提示：", MB_OK);
		}
		return TRUE;
		break;
	}

	case IDQUIT:
	case IDCANCEL:
		EndDialog(hDlg, IDCANCEL);
		return TRUE;
		break;
	}
	return false;
}

BOOL WINAPI DlgLogProc( HWND   hDlg, UINT   Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_INITDIALOG:
		CenterWindows(hDlg);
		return TRUE;
		break;
	case WM_COMMAND:
		return OnCommand(hDlg, Msg, wParam, lParam);
		break;
	}

	return FALSE;
}

BOOL WINAPI DlgMainProc(HWND   hDlg, UINT   Msg, WPARAM wParam, LPARAM lParam)
{
	switch (Msg)
	{
	case WM_INITDIALOG:
		CenterWindows(hDlg);
		return TRUE;
		break;
	case WM_COMMAND:
		return MainOnCommand(hDlg, Msg, wParam, lParam);
		break;
	}

	return FALSE;
}

void InputData()
{
	FILE *fp;
	if (fopen_s(&fp, "data.txt", "r+"))
	{
		exit(-1);
	}
	else
	{
		fscanf_s(fp, "%d", &UserCount);
		int i;
		for (i = 0; i < UserCount; ++i)
		{
			fscanf_s(fp, "%s", UserArr[i].user_name,N*sizeof(char));
			fscanf_s(fp, "%s", UserArr[i].user_psw,N*sizeof(char));
			fscanf_s(fp, "%f", &UserArr[i].money);
		}
		fclose(fp);
	}
	return;
}

void OutputData()
{
	FILE *fdata;
	int i;

	if (fopen_s(&fdata, "data.txt", "r+"))
	{
		exit(-1);
	}
	else
	{
		fprintf(fdata, "%d\n", UserCount);
		for (i = 0; i < UserCount; ++i) {
			fprintf(fdata, "%s\n", UserArr[i].user_name);
			fprintf(fdata, "%s\n", UserArr[i].user_psw);
			fprintf(fdata, "%.2f\n", UserArr[i].money);
		}
		fclose(fdata);
	}
	return ;
}

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE prevInstance,LPSTR lpCmdLine,int nShowCmd)
{
	//DWORD	dwFileSize, dwByteRead;

	InputData();

	MessageBoxA(NULL, "欢迎使用  有钱人！  ATM", "用户你好：", MB_OK);

log:	int DlgLogRtnVal = DialogBox(hInstance, (LPCSTR)IDD_DIALOG1, NULL, DlgLogProc);
	
	if (DlgLogRtnVal == IDLOGIN)
	{
		DialogBox(hInstance, (LPCSTR)IDD_DIALOG2, NULL, DlgMainProc);
		CurtUser = -1;
		goto log;
	}
	//HANDLE fdata = CreateFileA("d:\data.txt", GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	//ReadFile(fdata, &UserCount, sizeof(int), NULL, NULL);
	/*
	if (fdata != INVALID_HANDLE_VALUE)	//若打开文件成功
	{
		dwFileSize = GetFileSize(fdata, NULL);	//读取文件大小
		if (dwFileSize != INVALID_FILE_SIZE)	//若读取文件大小成功
		{
			char *szFileContent = new char[dwFileSize];
			if (szFileContent != NULL)
			{
				//读取文件
				ReadFile(fdata,	//文件句柄
					(LPVOID)szFileContent,	//文件缓冲区指针
					dwFileSize,	     //文件大小
					&dwByteRead,	//记录读入了多少字节
					NULL);	//从文件当前位置读取
				int length = strlen(szFileContent);
				if (dwByteRead != 0)
				{
					CloseHandle(fdata);
					return true;
				}
			}
		}
	}*/
	OutputData();
	return 0;
}