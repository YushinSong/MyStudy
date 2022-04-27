#include <iostream>
#include <string>
#include <queue>
#include <map>

#define SIZE 101
#define endl '\n'

using namespace std;

int N, M; // ��ٸ��� ��, ���� ��
int moveDistance[SIZE]; // ������������ �Ÿ�
int visited[SIZE]; // �湮���� üũ
map<int, int> mustMove;

int moving[6] = { 1, 2, 3, 4, 5, 6 };

void bfs(int start, int goal)
{
	visited[start] = true;
	queue<int> bfsq;
	bfsq.push(start);

	while (!bfsq.empty())
	{
		int now = bfsq.front();
		bfsq.pop();

		if (now == goal)
			return;

		if (mustMove[now] != NULL)
		{
			moveDistance[mustMove[now]] = moveDistance[now];
			now = mustMove[now]; // ��ٸ��� �� Ÿ�� �̵�
			visited[now] = true;
		}
		for (int i = 0; i < 6; ++i)
		{
			int next = now + moving[i];

			if (next > goal)
				continue;

			if (!visited[next]) // �湮�� �� ����
			{
				moveDistance[next] = moveDistance[now] + 1;
				visited[next] = true;
				bfsq.push(next);
			}
		}
	}
}

int main()
{
	cin >> N >> M;
	int sum = N + M;
	while (sum--)
	{
		int x, y;
		cin >> x >> y;
		mustMove[x] = y;;
	}

	bfs(1, 100);
	cout << moveDistance[100] << endl;
}