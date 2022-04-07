#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define INT_MAX 2147483647

using namespace std;

int N; // 팀의 수
int minDiff = INT_MAX;
int team[21]; // 반으로 나눴을 때 앞은 스타트, 뒤는 링크팀
bool visited[21];
vector<vector<int>> stats; // 입력된 능력치들

void dfs(int now, int cnt) // 현재 자릿수, 총 본 팀 수
{
	if (cnt >= N / 2) // 스타트팀 편성을 완료했을 때
	{
		int start = 0, link = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (visited[i] && visited[j]) // 편성한 스타트팀 능력치 계산
					start += stats[i][j];
				else if (!visited[i] && !visited[j]) // 나머지는 링크팀 능력치 계산
					link += stats[i][j];
			}
		}
		minDiff = min(minDiff, abs(start - link));
		return;
	}
	for (int i = now; i < N; ++i)
	{
		if (!visited[i]) // 방문한 적 없는 선수
		{
			visited[i] = true; // 현재선수 방문체크
			dfs(i + 1, cnt + 1); // 다음 선수 체크
			visited[i] = false; // 현재선수 방문체크 초기화
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
		stats.push_back(tempV);
	}

	dfs(0, 0); // 출발도시, 현재도시, 방문한 도시 수, 총 순회 비용

	cout << minDiff;
}