#pragma once
#pragma comment(lib, "ws2_32.lib") // winsock����� ���� ���̺귯��

#define PORT 8080 // ��Ʈ��ũ �ְ�޴� ���μ����� ������
#define PACKET_SIZE 1024 // ���ϳ��� �ְ���� ��Ŷ�� ������

#include <iostream>
#include <WinSock2.h> // ���� �̿��� ��Ʈ��ũ
#include <Windows.h>
#include <vector>
#include <utility> // pair
#include <thread> 
#include <cstdlib> // ���� ����

class CLIENT // ������ ������ Ŭ���̾�Ʈ Ŭ����
{
public:
	SOCKET client; // Ŭ���̾�Ʈ�� ����
	SOCKADDR_IN clientaddr = { 0 }; // ������ �ּ�
	int clientsize = sizeof clientaddr; 
	int number = -1;
	CLIENT() {}
};

typedef std::pair<CLIENT, std::string> pii; // Ŭ���̾�Ʈ Ŭ������ �� �̸�

std::vector<pii> Client; // pii�� ��ҷ� ���� ����