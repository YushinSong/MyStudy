#include <iostream>
#include <vector>

#define endl '\n'
#define GOAL 4

using namespace std;

int N, M; // ����� ��, ģ�������� ��
vector<int> relation[2001]; // ģ�� ����
bool visited[2001]; // �湮���� üũ

void dfs(int index, int cnt) // ������ �ε���, ���� ��
{
	if (cnt >= GOAL)
	{
		cout << 1 << endl;
		exit(0);
	}
	for (int i = 0; i < relation[index].size(); ++i) // index�� ģ�� ����ŭ �˻�
	{
		if (!visited[relation[index][i]]) // ���� �湮�� �� ���� ģ��
		{
			visited[relation[index][i]] = true;
		 	dfs(relation[index][i], cnt + 1); // ģ�� �˻�
			visited[relation[index][i]] = false;
		}
	}
}
int main()
{
	cin >> N >> M;

	for (int i = 0; i < M; ++i)
	{
		int f1, f2;
		cin >> f1 >> f2;

		relation[f1].push_back(f2);
		relation[f2].push_back(f1);
	}

	for (int i = 0; i < N; ++i)
	{
		visited[i] = true;
		dfs(i, 0); // ����ϴ� ���� �ٲ��
		visited[i] = false;
	}

	cout << 0 << endl;
}