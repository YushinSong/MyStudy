#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define endl '\n'

using namespace std;

vector<vector<int>> treeNode; // �Էµ� Ʈ���� ���� ����
vector<int> inputPath; // �Էµ� �湮 ����.
vector<int> pathIndex; // �� ������ �ε���
vector<int> result;
vector<int> visited; // �湮���� üũ

void dfs(int now)
{
	result.push_back(now);

	for (int i = 0; i < treeNode[now].size(); ++i)
	{
		int nextNode = treeNode[now][i];
		if (!visited[nextNode]) // �湮�� �� ����
		{
			visited[nextNode] = true;
			dfs(nextNode);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N; // ������ ��
	cin >> N;

	treeNode.assign(N + 1, vector<int>(0, 0));
	pathIndex.assign(N + 1, 0);
	visited.assign(N + 1, 0);
	for (int i = 1; i < N; ++i)
	{
		int a, b;
		cin >> a >> b;

		treeNode[a].push_back(b);
		treeNode[b].push_back(a);
	}
	for (int i = 0; i < N; ++i)
	{
		int road;
		cin >> road;
		inputPath.push_back(road);
		pathIndex[road] = i;
	}

	for (int i = 1; i <= N; ++i) // ������ 1����
	{
		sort(treeNode[i].begin(), treeNode[i].end(), [](const int& a, const int& b) {
			if (pathIndex[a] < pathIndex[b]) // ���� �ε��� ���� ����
				return true;
			else return false;
			});
	}

	int start = inputPath[0];
	if (start != 1)
	{
		cout << 0 << endl;
		return 0;
	}
	visited[start] = true;
	dfs(start); // ���� ������ 1
	if (result == inputPath)
		cout << 1 << endl;
	else
		cout << 0 << endl;
}