#include <iostream>
#include <string>
#include <queue>

#define SIZE 1001
#define endl '\n'

using namespace std;

int M, N; // 상자의 가로칸, 세로칸
int box[SIZE][SIZE]; // 입력된 상자
int visited[SIZE][SIZE]; // 방문여부 체크
int boxDistance[SIZE][SIZE]; // 익는데 걸린 시간
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
			if (boxDistance[i][j] == 0) // 모두 익지 못했을 때 == distance에 0이 존재한다.
			{
				cout << -1 << endl;
				return;
			}
			maxDis = max(maxDis, boxDistance[i][j]);
		}
	}

	if (maxDis == 1)// 이미 모두 익어있을 때 == distance의 최대값이 1이다.
		cout << 0 << endl;
	else
		cout << maxDis - 1 << endl;// 익을때까지의 최소 날짜 == distance의 최대값-1이다.
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
			int nextH = high + moveH[i];  // 다음에 익을 칸
			int nextW = width + moveW[i];

			if (nextW >= M || nextW < 0 || nextH >= N || nextH < 0) // 칸이 유효한지 확인
				continue;

			if (!visited[nextH][nextW] && box[nextH][nextW] == 0) // 갈수있는 칸, 방문한 적 없음
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

			if (temp == 1) // 익은 토마토일때 q에 삽입
			{
				bfsq.push({ i, j });
				boxDistance[i][j] = 1;
			}
			else if (temp == -1) // 토마토가 없는 칸
			{
				boxDistance[i][j] = -1;
			}
		}
	} 
	
	bfs();
	checkTomato();
}