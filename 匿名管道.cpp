#include<iostream>
#include<Windows.h>
int main()
{
	STARTUPINFO si;
	PROCESS_INFORMATION  pi;
	char ReadBuf[100];
	DWORD ReadNum;
	HANDLE hRead;
	HANDLE hWrite;
	BOOL bRet = CreatePipe(&hRead,&hWrite,NULL,0);
	if(bRet == TRUE)
	{
		printf("创建匿名管道成功\n");
	}
	else
	{
		printf("创建管道失败 错误代码：%d\n",GetLastError());
	}
	HANDLE hTemp = GetStdHandle(STD_OUTPUT_HANDLE);
	SetStdHandle(STD_OUTPUT_HANDLE,hWrite);
	GetStartupInfo(&si);
	bRet =  CreateProcess(NULL,"c.exe",NULL,NULL,TRUE,NULL,NULL,NULL,&si,&pi);
	SetStdHandle(STD_OUTPUT_HANDLE,hTemp);
	if(bRet == TRUE)
		printf("成功创建子进程\n");
	else
		printf("创建子进程失败 错误代码：%d\n",GetLastError());
	CloseHandle(hWrite);
	while (ReadFile(hRead,ReadBuf,100,&ReadNum,NULL))
	{
		ReadBuf[ReadNum] = '\0';
		printf("从管道[%s]读取%d字节数据\n",ReadBuf,ReadNum);
	}
	if(GetLastError() == ERROR_BROKEN_PIPE)
		printf("管道被子进程关闭\n");
	else
		printf("读数据错误，错误代码：%d\n",GetLastError());
	system("pause");
	return 0;
}
