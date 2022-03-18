#include "client.h"

void recvData(SOCKET& s) // 서버로부터 데이터 받는 함수
{
	char buffer[PACKET_SIZE];

	while (true)
	{
		ZeroMemory(buffer, sizeof buffer);
		recv(s, buffer, sizeof buffer, 0);
		std::cout << "Server : " << buffer << std::endl; // 서버의 메세지 출력
	}
}

int main()
{
	char IP[PACKET_SIZE] = { 0 };
	char name[PACKET_SIZE] = { 0 };

	// 유저의 클라이언트 이름과 ip주소 정의
	std::cout << "이름을 입력하세요 : ";
	std::cin >> name;
	std::cout << "아이피를 입력하세요 : ";
	std::cin >> IP;

	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);
	
	SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //서버 접속

	SOCKADDR_IN addr = { 0 };
	addr.sin_addr.s_addr = inet_addr(IP);
	addr.sin_port = PORT; // 포트 8080으로 통일
	addr.sin_family = AF_INET;

	while (connect(server, (SOCKADDR*)&addr, sizeof addr)); // 연결 요청
	send(server, name, sizeof name/*1024*/, 0); // 서버 접속 하자마자 이름을 전송하는 곳

	std::thread(recvData, std::ref(server)).detach(); // 멀티스레드로 서버로부터 값 받음

	while (true) // 서버로 메세지 전송
	{
		ZeroMemory(name, sizeof name);
		std::cout << "메세지를 입력하세요 : ";
		std::cin >> name;
		send(server, name, sizeof name, 0);
	}
}