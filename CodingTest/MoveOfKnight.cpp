#include <iostream>
#include <string>
#include <queue>

#define SIZE 301
#define endl '\n'

using namespace std;

int L; // ü������ ũ��
int chessDistance[SIZE][SIZE]; // ������������ �Ÿ�
int visited[SIZE][SIZE]; // �湮���� üũ

int goalH, goalW;
int moveH[8] = { -1, -2, -2, -1,  1,  2, 2, 1 };
int moveW[8] = { -2, -1,  1,  2, -2, -1, 1, 2 };

void clearChess()
{
	for (int i = 0; i < L; ++i)
	{
		for (int j = 0; j < L; ++j)
		{
			chessDistance[i][j] = 0;
			visited[i][j] = false;
		}
	}
}
void bfs(int high, int width)
{
	visited[high][width] = true;
	queue<pair<int, int>> bfsq;
	bfsq.push({ high, width });

	while (!bfsq.empty())
	{
		high = bfsq.front().first;
		width = bfsq.front().second;
		bfsq.pop();

		if (high == goalH && width == goalW)
			return;

		for (int i = 0; i < 8; ++i)
		{
			int nextH = high + moveH[i];
			int nextW = width + moveW[i];

			if (nextH >= L || nextH < 0 || nextW >= L || nextW < 0)
				continue;

			if (!visited[nextH][nextW]) // �湮�� �� ����
			{
				chessDistance[nextH][nextW] = chessDistance[high][width] + 1;
				visited[nextH][nextW] = true;
				bfsq.push({ nextH , nextW });
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int C; // �׽�Ʈ ���̽��� ��
	cin >> C;

	while (C--)
	{
		cin >> L;
		int startH, startW;
		cin >> startH >> startW >> goalH >> goalW;

		bfs(startH, startW);
		cout << chessDistance[goalH][goalW] << endl;
		clearChess();
	}
}