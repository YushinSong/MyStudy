#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define endl '\n'

using namespace std;

int N, M, V; // 정점의 수, 간선의 수, 찾아야할 수
vector<int> roads[10001]; // 입력된 간선

bool visited[10001]; // 방문여부 체크

void dfs(int value) // 찾을 정점
{
	visited[value] = true;
	cout << value << " ";
	sort(roads[value].begin(), roads[value].end());

	for (int i = 0; i < roads[value].size(); ++i) // value의 간선 수만큼 검색
		if (!visited[roads[value][i]]) // 아직 방문한 적 없는 정점
			dfs(roads[value][i]); // 정점 검색
}
void bfs(int value) // 찾을 정점
{
	visited[value] = true;
	queue<int> bfsq;
	bfsq.push(value);
	cout << value << " ";

	while (!bfsq.empty())
	{
		value = bfsq.front();
		bfsq.pop();
		sort(roads[value].begin(), roads[value].end());

		for (int i = 0; i < roads[value].size(); ++i) // value의 간선 수만큼 검색
		{
			if (!visited[roads[value][i]]) // 아직 방문한 적 없는 정점
			{
				visited[roads[value][i]] = true;
				bfsq.push(roads[value][i]); // value의 간선들 저장
				cout << roads[value][i] << " ";
			}
		}
	}
}
int main()
{
	cin >> N >> M >> V;

	for (int i = 0; i < M; ++i)
	{
		int a, b;
		cin >> a >> b;

		roads[a].push_back(b);
		roads[b].push_back(a);
	}

	dfs(V); // dfs. V에서 출발
	cout << endl;

	for (int i = 0; i <= N; ++i)
		visited[i] = false;

	bfs(V);
}