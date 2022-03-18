#include "server.h"


void recvData(SOCKET s, int num) // 클라이언트에게 데이터 전송받는 함수
{
	char buffer[PACKET_SIZE] = { 0 };
	recv(s, buffer, sizeof buffer, 0);  // 이름을 전송받는 곳
	Client[num].second = buffer;		// 채팅 내용

	while (true)
	{
		ZeroMemory(buffer, sizeof buffer);
		recv(s, buffer, sizeof buffer, 0); // 메세지를 받는 부분
		std::cout << Client[num].second << " : " << buffer << std::endl; // 클라이언트의 이름과 채팅내역 출력
	}
}

void ACCEPT(SOCKET& s) // 클라이언트들의 접속을 수용하는 함수
{
	int cnt = 0;
	while (true)
	{
		Client.push_back(pii(CLIENT(), "")); // 빈공간
		Client[cnt].first.client = accept(s, (SOCKADDR*)&Client[cnt].first.clientaddr, &Client[cnt].first.clientsize);
		Client[cnt].first.number = cnt;
		std::thread(recvData, Client[cnt].first.client, cnt).detach();

		cnt += 1;
	}
}
int main()
{
	// 서버 열기
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa); // 윈도우 소켓 초기화

	SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // IPv4 인터넷 프로토콜에서 동작하는 연결지향형 TCP 소켓


	std::cout << "서버 오픈" << std::endl;

	SOCKADDR_IN addr = { 0 };
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = PORT;
	addr.sin_family = AF_INET;

	bind(server, (SOCKADDR*)&addr, sizeof addr); //소켓에 주소 할당
	listen(server, SOMAXCONN);					// 연결요청 듣기

	std::thread(ACCEPT, std::ref(server)).detach(); // 연결 받아들이기

	char name[1024] = { 0 };
	char message[1024] = { 0 };

	while (true) // 특정 클라이언트에게 메세지를 전송
	{
		ZeroMemory(name, sizeof name); // 사용 전에 메모리 비우기
		ZeroMemory(message, sizeof message);
		std::cin >> name >> message;

		for (int i = 0; i < Client.size(); ++i)
		{
			if (!strcmp(Client[i].second.c_str(), name))
			{
				send(Client[i].first.client, message, sizeof message, 0); // 데이터 전송
			}
		}
	}
}