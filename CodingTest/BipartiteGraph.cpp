#include <iostream>
#include <vector>

#define endl '\n'
#define RED 1
#define BLUE 2

using namespace std;

vector<vector<int>> roads; // 입력된 간선
vector<int> visited; // 방문여부, 색깔 체크

bool checkBipartite(int V)
{
	for (int i = 1; i <= V; ++i) // 정점은 1부터다
	{
		for (int j = 0; j < roads[i].size(); ++j)
		{
			if (visited[i] == visited[roads[i][j]])
				return false;
		}
	}
	return true;
}
void dfs(int index)
{
	if (!visited[index])
		visited[index] = RED; // 방문한적 없다면 빨간색으로 칠하기

	for (int i = 0; i < roads[index].size(); ++i)
	{
		if (!visited[roads[index][i]]) // 아직 방문한 적 없는 정점이라면
		{
			if (visited[index] == RED) // 인접한 정점 반대색으로 칠하기
				visited[roads[index][i]] = BLUE;
			else
				visited[roads[index][i]] = RED;
			dfs(roads[index][i]);
		}
	}
}
int main()
{
	int K; // 테스트케이스의 수
	cin >> K;
	while(K--)
	{
		int V, E; // 정점의 개수, 간선의 개수
		cin >> V >> E;

		roads.assign(V + 1, vector<int>(0, 0));
		visited.assign(V + 1, 0);

		for (int j = 0; j < E; ++j)
		{
			int u, v; // 정점의 번호, 그 정점과 인접한 정점
			cin >> u >> v;

			roads[u].push_back(v);
			roads[v].push_back(u);
		}

		for (int j = 0; j < V; ++j)
		{
			dfs(j);
		}
		if (checkBipartite(V))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
}