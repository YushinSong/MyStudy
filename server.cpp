#include "server.h"


void recvData(SOCKET s, int num) // Ŭ���̾�Ʈ���� ������ ���۹޴� �Լ�
{
	char buffer[PACKET_SIZE] = { 0 };
	recv(s, buffer, sizeof buffer, 0);  // �̸��� ���۹޴� ��
	Client[num].second = buffer;		// ä�� ����

	while (true)
	{
		ZeroMemory(buffer, sizeof buffer);
		recv(s, buffer, sizeof buffer, 0); // �޼����� �޴� �κ�
		std::cout << Client[num].second << " : " << buffer << std::endl; // Ŭ���̾�Ʈ�� �̸��� ä�ó��� ���
	}
}

void ACCEPT(SOCKET& s) // Ŭ���̾�Ʈ���� ������ �����ϴ� �Լ�
{
	int cnt = 0;
	while (true)
	{
		Client.push_back(pii(CLIENT(), "")); // �����
		Client[cnt].first.client = accept(s, (SOCKADDR*)&Client[cnt].first.clientaddr, &Client[cnt].first.clientsize);
		Client[cnt].first.number = cnt;
		std::thread(recvData, Client[cnt].first.client, cnt).detach();

		cnt += 1;
	}
}
int main()
{
	// ���� ����
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa); // ������ ���� �ʱ�ȭ

	SOCKET server = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP); // IPv4 ���ͳ� �������ݿ��� �����ϴ� ���������� TCP ����


	std::cout << "���� ����" << std::endl;

	SOCKADDR_IN addr = { 0 };
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = PORT;
	addr.sin_family = AF_INET;

	bind(server, (SOCKADDR*)&addr, sizeof addr); //���Ͽ� �ּ� �Ҵ�
	listen(server, SOMAXCONN);					// �����û ���

	std::thread(ACCEPT, std::ref(server)).detach(); // ���� �޾Ƶ��̱�

	char name[1024] = { 0 };
	char message[1024] = { 0 };

	while (true) // Ư�� Ŭ���̾�Ʈ���� �޼����� ����
	{
		ZeroMemory(name, sizeof name); // ��� ���� �޸� ����
		ZeroMemory(message, sizeof message);
		std::cin >> name >> message;

		for (int i = 0; i < Client.size(); ++i)
		{
			if (!strcmp(Client[i].second.c_str(), name))
			{
				send(Client[i].first.client, message, sizeof message, 0); // ������ ����
			}
		}
	}
}