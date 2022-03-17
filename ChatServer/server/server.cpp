#include "server.h"

int main()
{
	// 서버 열기
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa); // 윈도우 소켓 초기화
}