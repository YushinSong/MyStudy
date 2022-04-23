#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

#define INTMAX 2147483647
#define endl '\n'

using namespace std;

int N; // 지도의 크기
int minResult = INTMAX;
vector<vector<int>> islandMap; // 입력된 섬
vector<vector<int>> dfsVisited; // 방문여부 체크
vector<vector<int>> bfsVisited; // 방문여부 체크
queue<pair<int, int>> islands; // 발견한 섬
vector<vector<int>> islandDistance; // 한 섬으로부터 다른 섬까지의 거리

int moveH[4] = { -1, 0, 1, 0 };
int moveW[4] = { 0, 1, 0, -1 };

void dfs(int high, int width) // 찾을 땅
{
	for (int i = 0; i < 4; ++i)
	{
		int nextH = high + moveH[i];
		int nextW = width + moveW[i];
	
		if (nextH >= N || nextH < 0 || nextW >= N || nextW < 0)
			continue;
	
		if (!dfsVisited[nextH][nextW] && islandMap[nextH][nextW] == 1) // 존재하는 집, 방문한 적 없음
		{
			dfsVisited[nextH][nextW] = true;
			islands.push({ nextH, nextW });
			dfs(nextH, nextW);
		}
	}
}
void bfs()
{ 
	// 시작할때, dfsVisited true인 곳은 찾은 섬이 있는 곳
	while (!islands.empty())
	{
		int high = islands.front().first;
		int width = islands.front().second;
		islands.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nextH = high + moveH[i];
			int nextW = width + moveW[i];

			if (nextH >= N || nextH < 0 || nextW >= N || nextW < 0)
				continue;

			if (!dfsVisited[nextH][nextW] && islandMap[nextH][nextW] == 1) // 찾은 섬이 아니면서, 섬이 있는곳 >> 새로 당도한 섬
			{
				minResult = min(minResult, islandDistance[high][width]); // 현재 pop한 땅 거리 확인
				continue;
			}
			if (!dfsVisited[nextH][nextW] && !bfsVisited[nextH][nextW] && islandMap[nextH][nextW] == 0) // 찾은 섬 아님, 방문한 적 없음, 섬이 없는 칸
			{
				islandDistance[nextH][nextW] = islandDistance[high][width] + 1;
				bfsVisited[nextH][nextW] = true;
				islands.push({ nextH , nextW });
			}
		}
	}
}
void clear()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			bfsVisited[i][j] = false;
			islandDistance[i][j] = 0;
		}
	}
}
int main()
{
	cin >> N;

	islandMap.assign(N + 1, vector<int>(0, 0));
	islandDistance.assign(N + 1, vector<int>(0, 0));
	dfsVisited.assign(N + 1, vector<int>(0, 0));
	bfsVisited.assign(N + 1, vector<int>(0, 0));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int temp;
			cin >> temp;
			islandMap[i].push_back(temp);
			dfsVisited[i].push_back(false);
			bfsVisited[i].push_back(false);
			islandDistance[i].push_back(0);
		}
	}

	int islandCount = 0; // 섬의 수
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (islandMap[i][j] == 1 && !dfsVisited[i][j]) // 존재하는 땅, 방문한적 없는 땅
			{
				islands.push({ i, j });
				dfsVisited[i][j] = true;
				dfs(i, j); // 출발하는 곳이 바뀌도록
				++islandCount; // 섬 하나 발견
				bfs();

				clear();
			}
		}
	}

	cout << minResult << endl;
}