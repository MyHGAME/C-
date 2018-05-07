#include<stdio.h>
#include<winsock.h>
#include<iostream>

void usage(char *prog)
{
	printf("Usage:GSGBannerScan.exe 127.0.0.1 1 65535\n");
	printf("GSGBannerScan.exe IP Startport Endport\n");
}

int main(int argc,char *argv[])
{
	if(argc != 4)
	{
		usage(argv[0]);
		return -1;
	}
	WSADATA wsa;
	if(WSAStartup(MAKEWORD(2,2),&wsa) != 0)
	{
		printf("WinSock DLL init Failed\n");
		return -1;
	}
	int nowport = 0,count = 0;
	struct sockaddr_in sa;
	int startport = atoi(argv[2]);
	int endport = atoi(argv[3]);
	if(endport < startport)
	{
		printf("don#39;t doing,endport < startport\n");
		return -1;
	}
	nowport = startport;
	printf("Start Scan....");
	for(nowport;nowport < endport;nowport++)
	{
		sa.sin_family = AF_INET;
		sa.sin_addr.S_un.S_addr = inet_addr(argv[1]);
		sa.sin_port = htons(nowport);
		SOCKET sockFD = socket(AF_INET,SOCK_STREAM,0);
		if(sockFD == INVALID_SOCKET)
		{
			printf("Socket create Error");
			return -1;
		}
		int iTimeOut = 5000;
		setsockopt(sockFD,SOL_S)
	}
}
