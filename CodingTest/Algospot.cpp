#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>

#define INTMAX 2147483647

using namespace std;

int N, M; // 도착지, 가로세로
vector<vector<int>> maze; // 입력된 미로
vector<vector<int>> brokeDoor; // 해당 위치에 부순 문의 수

int moveX[4] = {1, 0, -1, 0}; // 가로이동
int moveY[4] = {0, 1, 0, -1}; // 세로이동

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

			if (nextX >= M || nextX < 0 || nextY >= N || nextY < 0) // 칸이 유효한지 확인
				continue;

			if (maze[nextX][nextY] == 1 && brokeDoor[nextX][nextY] > brokeDoor[x][y] + 1) // 문이 있는 곳
			{
				brokeDoor[nextX][nextY] = brokeDoor[x][y] + 1;
				bfsq.push({ nextX , nextY });
			} 
			else if (maze[nextX][nextY] == 0 && brokeDoor[nextX][nextY] > brokeDoor[x][y]) // 문이 없는 곳
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