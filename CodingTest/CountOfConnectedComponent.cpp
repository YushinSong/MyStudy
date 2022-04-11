#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define endl '\n'

using namespace std;

int N, M; // ������ ��, ������ ��
vector<int> roads[1001]; // �Էµ� ����

bool visited[1001]; // �湮���� üũ

void dfs(int value) // ã�� ����
{
	visited[value] = true;

	for (int i = 0; i < roads[value].size(); ++i) // value�� ���� ����ŭ �˻�
	{
		if (!visited[roads[value][i]]) // ���� �湮�� �� ���� ����
			dfs(roads[value][i]); // ���� �˻�
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
			dfs(i); // ����ϴ� ���� �ٲ��
		}
	}
	cout << result << endl;
}