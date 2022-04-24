#include <iostream>
#include <vector>
#include <queue>

#define SIZE 100001
#define endl '\n'

using namespace std;

int N, K; // 수빈이의 위치, 동생의 위치
vector<int> visited; // 방문여부 체크, 도착하는데 걸린 시간
vector<int> route; // 각 인덱스마다, 이전의 경로를 저장

void bfs(int start)
{
	visited[start] = 0;
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

			if (visited[next[i]] == -1) // 방문한 적 없음
			{
				visited[next[i]] = visited[now] + 1;
				route[next[i]] = now;
				bfsq.push(next[i]);
			}
		}
	}
}

void printRoute()
{
	cout << visited[K] << endl;

	int nowRoute = K;
	vector<int> realRoute;
	realRoute.push_back(K);
	for (int i = 0; i < visited[K]; ++i)
	{
		realRoute.push_back(route[nowRoute]);
		nowRoute = route[nowRoute];
	}
	for (int i = realRoute.size() - 1; i >= 0; --i)
	{
		cout << realRoute[i] << " ";
	}
}

int main()
{
	cin >> N >> K;

	visited.assign(SIZE, -1);
	route.assign(SIZE, -1);

	bfs(N);
	printRoute();
}