#include <iostream>
#include <vector>
#include <queue>

#define endl '\n'
#define RED 1
#define BLUE 2

using namespace std;

vector<vector<int>> stations; // 입력된 역들
vector<int> visited; // 방문여부

int startStat; // 출발한 역
vector<int> circulationLine; // 찾은 순환선
vector<int> lineVector; // 저장하는 역

queue<int> bfsq;
vector<int> circleDistance; // 순환선으로부터의 거리

void clearVisit()
{
	for (int i = 0; i < visited.size(); ++i)
	{
		visited[i] = false;
	}
}
void dfs(int index, int depth) // 역, dfs깊이
{
	if (index == startStat && depth > 1) // 순환선 발견
	{
		circulationLine = lineVector;
		return;
	}

	visited[index] = true;
	for (int i = 0; i < stations[index].size(); ++i)
	{
		if (!visited[stations[index][i]]) // 아직 방문한 적 없는 역
		{
			lineVector.push_back(stations[index][i]);
			dfs(stations[index][i], depth + 1);
			lineVector.pop_back();
		}
		else
		{
			if (stations[index][i] == startStat && depth > 1) // 방문했다면, 순환선인지 확인하기
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

		for (int i = 0; i < stations[station].size(); ++i) // 순환선과 이어진 역들 보기
		{
			int nextStat = stations[station][i]; // 이어진 다음 역

			if (!visited[nextStat]) // 방문한적 없는 역
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
	int N; // 노선의 수
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
		if (circulationLine.empty()) // 순환선 못찾았을 때
			lineVector.clear();
		else
			continue;
		startStat = i;
		lineVector.push_back(i);
		dfs(i, 0); // 순환선 찾기
		clearVisit();
	}

	circleDistance.assign(N + 1, 0);
	for (int i = 0; i < circulationLine.size(); ++i) // 순환선 큐에 넣기
	{
		visited[circulationLine[i]] = true;
		bfsq.push(circulationLine[i]); // 순환선의 역들 큐에 넣기
	}

	bfs();

	for (int i = 1; i < circleDistance.size(); ++i) // 순환선 큐에 넣기
	{
		cout << circleDistance[i] << " ";
	}
}