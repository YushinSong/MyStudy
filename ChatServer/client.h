#pragma once
#pragma once
#pragma comment(lib, "ws2_32.lib")

#define _WINSOCK_DEPRECATED_NO_WARNINGS // inet_addr에러 해결
#define PORT 8080
#define PACKET_SIZE 1024

#include <iostream>
#include <WinSock2.h>
#include <Windows.h>
#include <thread>
#include <cstdlib>
#include <string>