#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define endl '\n'

using namespace std;

vector<vector<int>> treeNode; // 입력된 트리의 간선 정보
vector<int> inputPath; // 입력된 방문 순서.
vector<int> pathIndex; // 각 정점의 인덱스
vector<int> result;
vector<int> visited; // 방문여부 체크

void bfs(int start)
{
	if (start != 1)
	{
		cout << 0 << endl;
		return;
	}

	visited[start] = true;
	queue<int> bfsq;
	bfsq.push(start);
	result.push_back(start);

	while (!bfsq.empty())
	{
		int nowNode = bfsq.front();
		bfsq.pop();

		for(int i = 0; i < treeNode[nowNode].size(); ++i)
		{
			int nextNode = treeNode[nowNode][i];
			if (!visited[nextNode]) // 방문한 적 없음
			{
				visited[nextNode] = true;
				bfsq.push(nextNode);
				result.push_back(nextNode);
			}
		}
	}
}
void checkResult()
{
	for (int i = 0; i < result.size(); ++i)
	{
		if (inputPath[i] != result[i])
		{
			cout << 0 << endl;
			return;
		}
	}
	cout << 1 << endl;
	return;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int N; // 정점의 수
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

	for (int i = 1; i <= N; ++i) // 정점은 1부터
	{
		sort(treeNode[i].begin(), treeNode[i].end(), [](const int& a, const int& b) {
			if (pathIndex[a] < pathIndex[b]) // 정점 인덱스 기준 정렬
				return true;
			else return false;
			});
	}

	bfs(1); // 시작 정점은 1
	checkResult();
}