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
	if (cnt >= N) // ��� ���ø� �湮���� ��.
	{
		if(roads[now][start] > 0) // ��ߵ��÷� ���ư� �� �ִ� ���
			minCost = min(minCost, cost + roads[now][start]);
		return;
	}
	for (int i = 0; i < N; ++i)
	{
		if (!visited[i] && roads[now][i] > 0) // �湮�� �� ���� ����, �� �� �ִ� ���
		{
			visited[i] = true; // ���絵�� �湮üũ �ʱ�ȭ
			dfs(start, i, cnt + 1, cost + roads[now][i]); // ���� ���� üũ
			visited[i] = false; // ���絵�� �湮üũ �ʱ�ȭ
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
		visited[i] = true; // ��ߵ��� �湮üũ
		dfs(i, i, 1, 0); // ��ߵ���, ���絵��, �湮�� ���� ��, �� ��ȸ ���
		visited[i] = false; // ��ߵ��� �湮üũ �ʱ�ȭ
	}

	cout << minCost;
}