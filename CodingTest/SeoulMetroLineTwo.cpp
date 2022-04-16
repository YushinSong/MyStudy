#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'
#define RED 1
#define BLUE 2

using namespace std;

vector<vector<int>> stations; // �Էµ� ����
vector<int> visited; // �湮����

int startStat; // ����� ��
vector<int> circulationLine; // ã�� ��ȯ��
vector<int> lineVector; // �����ϴ� ��

queue<int> bfsq;
vector<int> circleDistance; // ��ȯ�����κ����� �Ÿ�

void clearVisit()
{
	for (int i = 0; i < visited.size(); ++i)
	{
		visited[i] = false;
	}
}
void dfs(int index, int depth) // ��, dfs����
{
	if (index == startStat && depth > 1) // ��ȯ�� �߰�
	{
		circulationLine = lineVector;
		return;
	}

	visited[index] = true;
	for (int i = 0; i < stations[index].size(); ++i)
	{
		if (!visited[stations[index][i]]) // ���� �湮�� �� ���� ��
		{
			lineVector.push_back(stations[index][i]);
			dfs(stations[index][i], depth + 1);
			lineVector.pop_back();
		}
		else
		{
			if (stations[index][i] == startStat && depth > 1) // �湮�ߴٸ�, ��ȯ������ Ȯ���ϱ�
			{
				dfs(stations[index][i], depth);
			}
		}
	}
}
void bfs()
{
	while (!bfsq.empty())
	{
		int station = bfsq.front();
		bfsq.pop();

		for (int i = 0; i < stations[station].size(); ++i) // ��ȯ���� �̾��� ���� ����
		{
			int nextStat = stations[station][i]; // �̾��� ���� ��

			if (!visited[nextStat]) // �湮���� ���� ��
			{
				visited[nextStat] = true;
				circleDistance[nextStat] = circleDistance[station] + 1;
				bfsq.push(nextStat);
			}
		}
	}
}
int main()
{
	int N; // �뼱�� ��
	cin >> N;

	stations.assign(N + 1, vector<int>(0, 0));
	visited.assign(N + 1, 0);

	for (int i = 0; i < N; ++i)
	{
		int a, b;
		cin >> a >> b;
		stations[a].push_back(b);
		stations[b].push_back(a);
	}

	for (int i = 1; i <= N; ++i)
	{
		if (circulationLine.empty()) // ��ȯ�� ��ã���� ��
			lineVector.clear();
		else
			continue;
		startStat = i;
		lineVector.push_back(i);
		dfs(i, 0); // ��ȯ�� ã��
		clearVisit();
	}

	circleDistance.assign(N + 1, 0);
	for (int i = 0; i < circulationLine.size(); ++i) // ��ȯ�� ť�� �ֱ�
	{
		visited[circulationLine[i]] = true;
		bfsq.push(circulationLine[i]); // ��ȯ���� ���� ť�� �ֱ�
	}

	bfs();

	for (int i = 1; i < circleDistance.size(); ++i) // ��ȯ�� ť�� �ֱ�
	{
		cout << circleDistance[i] << " ";
	}
}