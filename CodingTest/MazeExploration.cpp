#include <iostream>
#include <string>
#include <queue>

#define endl '\n'

using namespace std;

int N, M; // 목적지
string maze[101]; // 입력된 미로
int mazeDistance[101][101]; // 시작점부터의 거리
int visited[101][101]; // 방문여부 체크
int minResult = 2147483647;

int moveH[4] = { 0, -1, 1, 0 };
int moveW[4] = { -1, 0, 0, 1 };

//void dfs(int high, int width, int cnt) // 찾을 칸, dfs깊이
//{
//	if (high == N - 1 && width == M - 1) // 목적지 도착
//	{
//		minResult = min(cnt, minResult);
//		return;
//	}
//
//	for (int i = 0; i < 4; ++i)
//	{
//		int nextH = high + moveH[i];
//		int nextW = width + moveW[i];
//	
//		if (nextW >= M || nextW < 0 || nextH >= N || nextH < 0)
//			continue;
//	
//		if (!visited[nextH][nextW] && maze[nextH][nextW] == '1') // 갈수있는 칸, 방문한 적 없음
//		{
//			visited[nextH][nextW] = true;
//			dfs(nextH, nextW, cnt + 1);
//			visited[nextH][nextW] = false;
//		}
//	}
//}

void bfs(int high, int width)
{
	queue<pair<int, int>> bfsq;
	bfsq.push({ high, width });

	while (!bfsq.empty())
	{
		high = bfsq.front().first;
		width = bfsq.front().second;
		bfsq.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nextH = high + moveH[i];
			int nextW = width + moveW[i];

			if (nextW >= M || nextW < 0 || nextH >= N || nextH < 0)
				continue;

			if (!visited[nextH][nextW] && maze[nextH][nextW] == '1') // 갈수있는 칸, 방문한 적 없음
			{
				mazeDistance[nextH][nextW] = mazeDistance[high][width] + 1;
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

	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		string temp;
		cin >> temp;
		maze[i] = temp;
	}

	visited[0][0] = true;
	bfs(0, 0); // 출발하는 곳 항상 같음

	cout << mazeDistance[N - 1][M - 1] + 1 << endl;
}