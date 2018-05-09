#include<stdio.h>
#include<winsock.h>
#include<iostream>

void usage(char *prog)
{
	printf("Usage:GSGBannerScan.exe 127.0.0.1 1 65535\n");
	printf("GSGBannerScan.exe IP Startport Endport\n");
}

int main()
{
	
	WSADATA wsa;
	if(WSAStartup(MAKEWORD(2,2),&wsa) != 0)
	{
		printf("WinSock DLL init Failed\n");
		return -1;
	}
	int nowport = 0,count = 0;
	struct sockaddr_in sa;
	int startport = 0;
	int endport = 0;
	char addr[] = "127.0.0.1";
	scanf("%d",&startport);
	scanf("%d",&endport);
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
		sa.sin_addr.S_un.S_addr = inet_addr(addr);
		sa.sin_port = htons(nowport);
		SOCKET sockFD = socket(AF_INET,SOCK_STREAM,0);
		if(sockFD == INVALID_SOCKET)
		{
			printf("Socket create Error");
			return -1;
		}
		int iTimeOut = 5000;
		setsockopt(sockFD,SOL_SOCKET,SO_RCVTIMEO,(char *)&iTimeOut,sizeof(iTimeOut));
		if(connect(sockFD,(const sockaddr*)&sa,sizeof(sa)) == SOCKET_ERROR)
		{
			closesocket(sockFD);
		}
		else
		{
			count +=1;
			printf("%s Find %d Port is Opend!\n",addr,nowport);
		}
	}
}
