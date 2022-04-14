#include <iostream>
#include <string>
#include <queue>

#define SIZE 1001
#define endl '\n'

using namespace std;

int M, N; // ������ ����ĭ, ����ĭ
int box[SIZE][SIZE]; // �Էµ� ����
int visited[SIZE][SIZE]; // �湮���� üũ
int boxDistance[SIZE][SIZE]; // �ʹµ� �ɸ� �ð�
queue<pair<int, int>> bfsq;

int moveH[4] = { 0, -1, 1, 0 };
int moveW[4] = { -1, 0, 0, 1 };

void checkTomato()
{
	int maxDis = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (boxDistance[i][j] == 0) // ��� ���� ������ �� == distance�� 0�� �����Ѵ�.
			{
				cout << -1 << endl;
				return;
			}
			maxDis = max(maxDis, boxDistance[i][j]);
		}
	}

	if (maxDis == 1)// �̹� ��� �;����� �� == distance�� �ִ밪�� 1�̴�.
		cout << 0 << endl;
	else
		cout << maxDis - 1 << endl;// ������������ �ּ� ��¥ == distance�� �ִ밪-1�̴�.
}
void bfs()
{
	int high, width;
	while (!bfsq.empty())
	{
		high = bfsq.front().first;
		width = bfsq.front().second;
		visited[high][width] = true;
		bfsq.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nextH = high + moveH[i];  // ������ ���� ĭ
			int nextW = width + moveW[i];

			if (nextW >= M || nextW < 0 || nextH >= N || nextH < 0) // ĭ�� ��ȿ���� Ȯ��
				continue;

			if (!visited[nextH][nextW] && box[nextH][nextW] == 0) // �����ִ� ĭ, �湮�� �� ����
			{
				visited[nextH][nextW] = true;
				boxDistance[nextH][nextW] = boxDistance[high][width] + 1;
				bfsq.push({ nextH , nextW });
			}
		}
	}
}

int main()
{
	cin >> M >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			int temp;
			cin >> temp;
			box[i][j] = temp;

			if (temp == 1) // ���� �丶���϶� q�� ����
			{
				bfsq.push({ i, j });
				boxDistance[i][j] = 1;
			}
			else if (temp == -1) // �丶�䰡 ���� ĭ
			{
				boxDistance[i][j] = -1;
			}
		}
	} 
	
	bfs();
	checkTomato();
}