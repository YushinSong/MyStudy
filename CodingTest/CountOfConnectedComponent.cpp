#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define endl '\n'

using namespace std;

int N, M; // 정점의 수, 간선의 수
vector<int> roads[1001]; // 입력된 간선

bool visited[1001]; // 방문여부 체크

void dfs(int value) // 찾을 정점
{
	visited[value] = true;

	for (int i = 0; i < roads[value].size(); ++i) // value의 간선 수만큼 검색
	{
		if (!visited[roads[value][i]]) // 아직 방문한 적 없는 정점
			dfs(roads[value][i]); // 정점 검색
	}
}
int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;

		roads[a].push_back(b);
		roads[b].push_back(a);
	}

	int result = 0;
	for (int i = 1; i <= N; ++i)
	{
		if (!visited[i])
		{
			++result;
			dfs(i); // 출발하는 곳이 바뀌도록
		}
	}
	cout << result << endl;
}