#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

#define INTMAX 2147483647

using namespace std;

int N, M; // ������, ���μ���
vector<vector<int>> maze; // �Էµ� �̷�
vector<vector<int>> brokeDoor; // �ش� ��ġ�� �μ� ���� ��

int moveX[4] = {1, 0, -1, 0}; // �����̵�
int moveY[4] = {0, 1, 0, -1}; // �����̵�

void bfs()
{
	queue<pair<int, int>> bfsq;
	bfsq.push({ 0, 0 });
	brokeDoor[0][0] = 0;

	while (!bfsq.empty())
	{
		int x = bfsq.front().first;
		int y = bfsq.front().second;
		bfsq.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nextX = x + moveX[i];
			int nextY = y + moveY[i];

			if (nextX >= M || nextX < 0 || nextY >= N || nextY < 0) // ĭ�� ��ȿ���� Ȯ��
				continue;

			if (maze[nextX][nextY] == 1 && brokeDoor[nextX][nextY] > brokeDoor[x][y] + 1) // ���� �ִ� ��
			{
				brokeDoor[nextX][nextY] = brokeDoor[x][y] + 1;
				bfsq.push({ nextX , nextY });
			} 
			else if (maze[nextX][nextY] == 0 && brokeDoor[nextX][nextY] > brokeDoor[x][y]) // ���� ���� ��
			{
				brokeDoor[nextX][nextY] = brokeDoor[x][y];
				bfsq.push({ nextX , nextY });
			}
		}
	}
}
int main()
{
	cin >> N >> M;

	maze.assign(M, vector<int>(0, 0));
	brokeDoor.assign(M, vector<int>(0, 0));

	for (int i = 0; i < M; ++i)
	{
		string temp;
		cin >> temp;
		for (int j = 0; j < N; ++j)
		{
			maze[i].push_back(temp[j] - '0');
			brokeDoor[i].push_back(INTMAX);
		}
	}

	bfs();
	cout << brokeDoor[M - 1][N - 1];
}