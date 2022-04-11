#include <iostream>
#include <vector>

#define endl '\n'
#define GOAL 4

using namespace std;

int N, M; // 사람의 수, 친구관계의 수
vector<int> relation[2001]; // 친구 관계
bool visited[2001]; // 방문여부 체크

void dfs(int index, int cnt) // 벡터의 인덱스, 깊이 수
{
	if (cnt >= GOAL)
	{
		cout << 1 << endl;
		exit(0);
	}
	for (int i = 0; i < relation[index].size(); ++i) // index의 친구 수만큼 검색
	{
		if (!visited[relation[index][i]]) // 아직 방문한 적 없는 친구
		{
			visited[relation[index][i]] = true;
		 	dfs(relation[index][i], cnt + 1); // 친구 검색
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
		dfs(i, 0); // 출발하는 곳이 바뀌도록
		visited[i] = false;
	}

	cout << 0 << endl;
}