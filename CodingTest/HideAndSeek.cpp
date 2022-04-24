#include <iostream>
#include <vector>
#include <queue>

#define SIZE 100001
#define endl '\n'

using namespace std;

int N, K; // 수빈이의 위치, 동생의 위치
int visited[SIZE]; // 방문여부 체크
int moveTime[SIZE]; // 도착하는데 걸린 시간

void bfs(int start)
{
	visited[start] = true;
	queue<int> bfsq;
	bfsq.push(start);
	int next[3];

	while (!bfsq.empty())
	{
		int now = bfsq.front();
		bfsq.pop();

		if (now == K)
			return;

		next[0] = now + 1;
		next[1] = now - 1;
		next[2] = now * 2;

		for (int i = 0; i < 3; ++i)
		{
			if (next[i] >= SIZE || next[i] < 0) // 칸이 유효한지 확인
				continue;

			if (!visited[next[i]]) // 방문한 적 없음
			{
				visited[next[i]] = true;
				moveTime[next[i]] = moveTime[now] + 1;
				bfsq.push(next[i]);
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