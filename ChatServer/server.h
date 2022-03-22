#pragma once
#pragma comment(lib, "ws2_32.lib") // winsock사용을 위한 라이브러리

#define PORT 8080 // 네트워크 주고받는 프로세스의 고유값
#define PACKET_SIZE 1024 // 소켓끼리 주고받을 패킷의 사이즈

#include <iostream>
#include <WinSock2.h> // 소켓 이용한 네트워크
#include <Windows.h>
#include <vector>
#include <utility> // pair
#include <thread> 
#include <cstdlib> // 난수 생성

class CLIENT // 서버에 접속할 클라이언트 클래스
{
public:
	SOCKET client; // 클라이언트의 소켓
	SOCKADDR_IN clientaddr = { 0 }; // 소켓의 주소
	int clientsize = sizeof clientaddr; 
	int number = -1;
	CLIENT() {}
};

typedef std::pair<CLIENT, std::string> pii; // 클라이언트 클래스와 그 이름

std::vector<pii> Client; // pii를 요소로 갖는 벡터