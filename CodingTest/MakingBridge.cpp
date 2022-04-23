#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

#define INTMAX 2147483647
#define endl '\n'

using namespace std;

int N; // ������ ũ��
int minResult = INTMAX;
vector<vector<int>> islandMap; // �Էµ� ��
vector<vector<int>> dfsVisited; // �湮���� üũ
vector<vector<int>> bfsVisited; // �湮���� üũ
queue<pair<int, int>> islands; // �߰��� ��
vector<vector<int>> islandDistance; // �� �����κ��� �ٸ� �������� �Ÿ�

int moveH[4] = { -1, 0, 1, 0 };
int moveW[4] = { 0, 1, 0, -1 };

void dfs(int high, int width) // ã�� ��
{
	for (int i = 0; i < 4; ++i)
	{
		int nextH = high + moveH[i];
		int nextW = width + moveW[i];
	
		if (nextH >= N || nextH < 0 || nextW >= N || nextW < 0)
			continue;
	
		if (!dfsVisited[nextH][nextW] && islandMap[nextH][nextW] == 1) // �����ϴ� ��, �湮�� �� ����
		{
			dfsVisited[nextH][nextW] = true;
			islands.push({ nextH, nextW });
			dfs(nextH, nextW);
		}
	}
}
void bfs()
{ 
	// �����Ҷ�, dfsVisited true�� ���� ã�� ���� �ִ� ��
	while (!islands.empty())
	{
		int high = islands.front().first;
		int width = islands.front().second;
		islands.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nextH = high + moveH[i];
			int nextW = width + moveW[i];

			if (nextH >= N || nextH < 0 || nextW >= N || nextW < 0)
				continue;

			if (!dfsVisited[nextH][nextW] && islandMap[nextH][nextW] == 1) // ã�� ���� �ƴϸ鼭, ���� �ִ°� >> ���� �絵�� ��
			{
				minResult = min(minResult, islandDistance[high][width]); // ���� pop�� �� �Ÿ� Ȯ��
				continue;
			}
			if (!dfsVisited[nextH][nextW] && !bfsVisited[nextH][nextW] && islandMap[nextH][nextW] == 0) // ã�� �� �ƴ�, �湮�� �� ����, ���� ���� ĭ
			{
				islandDistance[nextH][nextW] = islandDistance[high][width] + 1;
				bfsVisited[nextH][nextW] = true;
				islands.push({ nextH , nextW });
			}
		}
	}
}
void clear()
{
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			bfsVisited[i][j] = false;
			islandDistance[i][j] = 0;
		}
	}
}
int main()
{
	cin >> N;

	islandMap.assign(N + 1, vector<int>(0, 0));
	islandDistance.assign(N + 1, vector<int>(0, 0));
	dfsVisited.assign(N + 1, vector<int>(0, 0));
	bfsVisited.assign(N + 1, vector<int>(0, 0));

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			int temp;
			cin >> temp;
			islandMap[i].push_back(temp);
			dfsVisited[i].push_back(false);
			bfsVisited[i].push_back(false);
			islandDistance[i].push_back(0);
		}
	}

	int islandCount = 0; // ���� ��
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (islandMap[i][j] == 1 && !dfsVisited[i][j]) // �����ϴ� ��, �湮���� ���� ��
			{
				islands.push({ i, j });
				dfsVisited[i][j] = true;
				dfs(i, j); // ����ϴ� ���� �ٲ��
				++islandCount; // �� �ϳ� �߰�
				bfs();

				clear();
			}
		}
	}

	cout << minResult << endl;
}