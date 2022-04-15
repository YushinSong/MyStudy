#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define SIZE 51
#define endl '\n'

using namespace std;

int N, M; // 게임판의 크기. 세로, 가로
string dots[SIZE]; // 입력된 도트들
int visited[SIZE][SIZE]; // 방문여부 체크

int startH, startW; // 검색시작한 위치
char startColor; // 시작위치의 색

int moveHigh[4] = { -1, 0, 1, 0 };
int moveWidth[4] = { 0, 1, 0, -1 };

void dfs(int high, int width, int depth) // 찾을 집, 깊이
{
	if (startH == high && startW == width && depth >= 4) // 사이클 완성
	{
		cout << "Yes" << endl;
		exit(0);
	}
	for (int i = 0; i < 4; ++i)
	{
		int nextH = high + moveHigh[i];
		int nextW = width + moveWidth[i];

		if (nextH >= N || nextH < 0 || nextW >= M || nextW < 0)
			continue;

		if (!visited[nextH][nextW] && dots[nextH][nextW] == startColor) // 방문한 적 없고, 같은 색일 때
		{
			visited[nextH][nextW] = true;
			dfs(nextH, nextW, depth + 1);
			visited[nextH][nextW] = false;
		}
	}
}
int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		string temp;
		cin >> temp;

		dots[i] = temp;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (!visited[i][j]) // 방문한적 없는 칸
			{
				//visited[i][j] = true;
				startH = i; startW = j;
				startColor = dots[i][j];
				dfs(i, j, 0);
			}
		}
	}
	cout << "No" << endl;
}