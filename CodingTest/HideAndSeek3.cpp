#include <iostream>
#include <vector>
#include <deque>

#define SIZE 100001
#define endl '\n'

using namespace std;

int N, K; // �������� ��ġ, ������ ��ġ
int visited[SIZE]; // �湮���� üũ
int moveTime[SIZE]; // �����ϴµ� �ɸ� �ð�


void bfs(int start)
{
	deque<int> bfsd;
	visited[start] = true;
	bfsd.push_front(start);
	int next[3];

	while (!bfsd.empty())
	{
		int now = bfsd.front();
		bfsd.pop_front();

		if (now == K)
			return;

		next[0] = now * 2;
		next[1] = now + 1;
		next[2] = now - 1;

		for (int i = 0; i < 3; ++i)
		{
			if (next[i] >= SIZE || next[i] < 0) // ĭ�� ��ȿ���� Ȯ��
				continue;

			if (!visited[next[i]]) // �湮�� �� ����
			{
				visited[next[i]] = true;
				if (i != 0)
				{
					moveTime[next[i]] = moveTime[now] + 1;
					bfsd.push_back(next[i]);
				}
				else // �����̵�
				{
					moveTime[next[i]] = moveTime[now];
					bfsd.push_front(next[i]);
				}
			}
		}
	}
}

int main()
{
	cin >> N >> K;

	bfs(N);
	cout << moveTime[K] << endl;
}