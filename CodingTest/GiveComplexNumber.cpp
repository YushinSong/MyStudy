#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define endl '\n'

using namespace std;

int N; // 지도의 크기
int map[25][25]; // 입력된 지도
int visited[25][25]; // 방문여부 체크
vector<int> complex; // 단지
int cnt; // 단지의 집 수 카운트

int moveRow[4] = { -1, 0, 1, 0 };
int moveCol[4] = { 0, 1, 0, -1 };

void dfs(int row, int col) // 찾을 집
{
	for (int i = 0; i < 4; ++i)
	{
		int nextRow = row + moveRow[i];
		int nextCol = col + moveCol[i];

		if (nextRow >= N || nextRow < 0 || nextCol >= N || nextCol < 0)
			continue;

		if (!visited[nextRow][nextCol] && map[nextRow][nextCol] == 1) // 존재하는 집, 방문한 적 없음
		{
			visited[nextRow][nextCol] = true;
			++cnt;
			dfs(nextRow, nextCol);
		}
	}
}
int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			char temp;
			cin >> temp;

			if(temp == '1')
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
	}

	int result = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (map[i][j] == 1 && !visited[i][j]) // 존재하는 집, 방문한적 없는 집
			{
				visited[i][j] = true;
				cnt = 1;
				dfs(i, j); // 출발하는 곳이 바뀌도록
				++result;
				complex.push_back(cnt);
			}
		}
	}
	sort(complex.begin(), complex.end());
	cout << result << endl;
	for (int i : complex)
		cout << i << endl;
}