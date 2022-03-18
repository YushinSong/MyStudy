#include "client.h"

void recvData(SOCKET& s) // �����κ��� ������ �޴� �Լ�
{
	char buffer[PACKET_SIZE];

	while (true)
	{
		ZeroMemory(buffer, sizeof buffer);
		recv(s, buffer, sizeof buffer, 0);
		std::cout << "Server : " << buffer << std::endl; // ������ �޼��� ���
	}
}

int main()
{
	char IP[PACKET_SIZE] = { 0 };
	char name[PACKET_SIZE] = { 0 };

	// ������ Ŭ���̾�Ʈ �̸��� ip�ּ� ����
	std::cout << "�̸��� �Է��ϼ��� : ";
	std::cin >> name;
	std::cout << "�����Ǹ� �Է��ϼ��� : ";
	std::cin >> IP;

	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);
	
	SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); //���� ����

	SOCKADDR_IN addr = { 0 };
	addr.sin_addr.s_addr = inet_addr(IP);
	addr.sin_port = PORT; // ��Ʈ 8080���� ����
	addr.sin_family = AF_INET;

	while (connect(server, (SOCKADDR*)&addr, sizeof addr)); // ���� ��û
	send(server, name, sizeof name/*1024*/, 0); // ���� ���� ���ڸ��� �̸��� �����ϴ� ��

	std::thread(recvData, std::ref(server)).detach(); // ��Ƽ������� �����κ��� �� ����

	while (true) // ������ �޼��� ����
	{
		ZeroMemory(name, sizeof name);
		std::cout << "�޼����� �Է��ϼ��� : ";
		std::cin >> name;
		send(server, name, sizeof name, 0);
	}
}