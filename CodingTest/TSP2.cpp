#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define INT_MAX 2147483647

using namespace std;

int N;
int minCost = INT_MAX;
int route[11][11];
bool visited[11];
vector<vector<int>> roads;

void dfs(int start, int now, int cnt, int cost)
{
	if (cnt >= N) // 모든 도시를 방문했을 때.
	{
		if(roads[now][start] > 0) // 출발도시로 돌아갈 수 있는 경우
			minCost = min(minCost, cost + roads[now][start]);
		return;
	}
	for (int i = 0; i < N; ++i)
	{
		if (!visited[i] && roads[now][i] > 0) // 방문한 적 없는 도시, 갈 수 있는 경로
		{
			visited[i] = true; // 현재도시 방문체크 초기화
			dfs(start, i, cnt + 1, cost + roads[now][i]); // 다음 도시 체크
			visited[i] = false; // 현재도시 방문체크 초기화
		}
	}
}
int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		vector<int> tempV;
		for (int i = 0; i < N; ++i)
		{
			int temp;
			cin >> temp;
			tempV.push_back(temp);
		}
		roads.push_back(tempV);
	}

	for (int i = 0; i < N; ++i)
	{
		visited[i] = true; // 출발도시 방문체크
		dfs(i, i, 1, 0); // 출발도시, 현재도시, 방문한 도시 수, 총 순회 비용
		visited[i] = false; // 출발도시 방문체크 초기화
	}

	cout << minCost;
}