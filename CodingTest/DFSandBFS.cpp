#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define endl '\n'

using namespace std;

int N, M, V; // ������ ��, ������ ��, ã�ƾ��� ��
vector<int> roads[10001]; // �Էµ� ����

bool visited[10001]; // �湮���� üũ

void dfs(int value) // ã�� ����
{
	visited[value] = true;
	cout << value << " ";
	sort(roads[value].begin(), roads[value].end());

	for (int i = 0; i < roads[value].size(); ++i) // value�� ���� ����ŭ �˻�
		if (!visited[roads[value][i]]) // ���� �湮�� �� ���� ����
			dfs(roads[value][i]); // ���� �˻�
}
void bfs(int value) // ã�� ����
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

		for (int i = 0; i < roads[value].size(); ++i) // value�� ���� ����ŭ �˻�
		{
			if (!visited[roads[value][i]]) // ���� �湮�� �� ���� ����
			{
				visited[roads[value][i]] = true;
				bfsq.push(roads[value][i]); // value�� ������ ����
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

	dfs(V); // dfs. V���� ���
	cout << endl;

	for (int i = 0; i <= N; ++i)
		visited[i] = false;

	bfs(V);
}