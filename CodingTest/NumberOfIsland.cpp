#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define endl '\n'

using namespace std;

int w, h; // 지도의 너비, 높이
int map[51][51]; // 입력된 지도
int visited[51][51]; // 방문여부 체크

int moveH[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
int moveW[8] = { 1, 1, 1, 0, 0, -1, -1, -1 };

void clearMap()
{
	for (int i = 0; i < h; ++i)
	{
		for (int j = 0; j < w; ++j)
		{
			map[i][j] = 0;
			visited[i][j] = false;
		}
	}
}
void dfs(int high, int width) // 찾을 집
{
	for (int i = 0; i < 8; ++i)
	{
		int nextH = high + moveH[i];
		int nextW = width + moveW[i];

		if (nextW >= w || nextW < 0 || nextH >= h || nextH < 0)
			continue;

		if (!visited[nextH][nextW] && map[nextH][nextW] == 1) // 존재하는 집, 방문한 적 없음
		{
			visited[nextH][nextW] = true;
			dfs(nextH, nextW);
		}
	}
}
int main()
{
	w = 1; h = 1;
	while (w && h)
	{
		cin >> w >> h;

		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				int temp;
				cin >> temp;

				map[i][j] = temp;
			}
		}
		int result = 0;
		for (int i = 0; i < h; ++i)
		{
			for (int j = 0; j < w; ++j)
			{
				if (map[i][j] == 1 && !visited[i][j]) // 존재하는 땅, 방문한적 없는 땅
				{
					visited[i][j] = true;
					dfs(i, j); // 출발하는 곳이 바뀌도록
					++result;
				}
			}
		}
		if(w && h)
			cout << result << endl;
		clearMap();
	}
}