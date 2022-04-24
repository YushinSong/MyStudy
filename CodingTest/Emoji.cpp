#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define SIZE 1001
#define endl '\n'

using namespace std;

int S; // �������ϴ� �̸�Ƽ�� ��
int screen, clip; //��ũ��, Ŭ�������� �̸�Ƽ�� ��
int visited[SIZE][SIZE]; // �湮���� üũ
int makeTime[SIZE][SIZE]; // �ð� üũ

void bfs()
{
	screen = 1; clip = 0;
	visited[screen][clip] = true;
	makeTime[screen][clip] = 0;
	queue<pair<int, int>> bfsq;
	bfsq.push({screen, clip});

	while (!bfsq.empty())
	{
		int nowS = bfsq.front().first;
		int nowC = bfsq.front().second;
		bfsq.pop();

		if (nowS == S)
		{
			cout << makeTime[nowS][nowC] << endl;
			return;
		}

		// 1. ȭ�鿡 �ִ� �̸�Ƽ���� Ŭ�����忡 �����Ѵ�.
		if (nowS < SIZE && !visited[nowS][nowS])
		{
			visited[nowS][nowS] = true;
			makeTime[nowS][nowS] = makeTime[nowS][nowC] + 1;
			bfsq.push({ nowS, nowS }); // ȭ�� �̸�Ƽ�� ���� Ŭ������ ���� ����
		}
		// 2. Ŭ�����忡 �ִ� ��� �̸�Ƽ���� ȭ�鿡 �ٿ��ֱ� �Ѵ�.
		if (nowS + nowC < SIZE && !visited[nowS + nowC][nowC])
		{
			visited[nowS + nowC][nowS] = true;
			makeTime[nowS + nowC][nowC] = makeTime[nowS][nowC] + 1;
			bfsq.push({ nowS + nowC, nowC }); 
		}
		// 3. ȭ�鿡 �ִ� �̸�Ƽ�� �� �ϳ��� �����Ѵ�.
		if (nowS > 0 && !visited[nowS - 1][nowC])
		{
			visited[nowS - 1][nowS] = true;
			makeTime[nowS - 1][nowC] = makeTime[nowS][nowC] + 1;
			bfsq.push({ nowS - 1, nowC });
		}
	}
}

int main()
{
	cin >> S;

	bfs();
}