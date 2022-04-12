#include <iostream>
#include <vector>

#define endl '\n'
#define RED 1
#define BLUE 2

using namespace std;

vector<vector<int>> roads; // �Էµ� ����
vector<int> visited; // �湮����, ���� üũ

bool checkBipartite(int V)
{
	for (int i = 1; i <= V; ++i) // ������ 1���ʹ�
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
		visited[index] = RED; // �湮���� ���ٸ� ���������� ĥ�ϱ�

	for (int i = 0; i < roads[index].size(); ++i)
	{
		if (!visited[roads[index][i]]) // ���� �湮�� �� ���� �����̶��
		{
			if (visited[index] == RED) // ������ ���� �ݴ������ ĥ�ϱ�
				visited[roads[index][i]] = BLUE;
			else
				visited[roads[index][i]] = RED;
			dfs(roads[index][i]);
		}
	}
}
int main()
{
	int K; // �׽�Ʈ���̽��� ��
	cin >> K;
	while(K--)
	{
		int V, E; // ������ ����, ������ ����
		cin >> V >> E;

		roads.assign(V + 1, vector<int>(0, 0));
		visited.assign(V + 1, 0);

		for (int j = 0; j < E; ++j)
		{
			int u, v; // ������ ��ȣ, �� ������ ������ ����
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