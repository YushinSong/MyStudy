#include <iostream>
#include <vector>
#include <queue>
#include <utility>

#define SIZE 1001
#define endl '\n'

using namespace std;

int S; // 만들어야하는 이모티콘 수
int screen, clip; //스크린, 클립보드의 이모티콘 수
int visited[SIZE][SIZE]; // 방문여부 체크
int makeTime[SIZE][SIZE]; // 시간 체크

void bfs()
{
	screen = 1; clip = 0;
	visited[screen][clip] = true;
	makeTime[screen][clip] = 0;
	queue<pair<int, int>> bfsq;
	bfsq.push({screen, clip});

	while (!bfsq.empty())
	{
		int nowS = bfsq.front().first;
		int nowC = bfsq.front().second;
		bfsq.pop();

		if (nowS == S)
		{
			cout << makeTime[nowS][nowC] << endl;
			return;
		}

		// 1. 화면에 있는 이모티콘을 클립보드에 저장한다.
		if (nowS < SIZE && !visited[nowS][nowS])
		{
			visited[nowS][nowS] = true;
			makeTime[nowS][nowS] = makeTime[nowS][nowC] + 1;
			bfsq.push({ nowS, nowS }); // 화면 이모티콘 수와 클립보드 수가 같다
		}
		// 2. 클립보드에 있는 모든 이모티콘을 화면에 붙여넣기 한다.
		if (nowS + nowC < SIZE && !visited[nowS + nowC][nowC])
		{
			visited[nowS + nowC][nowS] = true;
			makeTime[nowS + nowC][nowC] = makeTime[nowS][nowC] + 1;
			bfsq.push({ nowS + nowC, nowC }); 
		}
		// 3. 화면에 있는 이모티콘 중 하나를 삭제한다.
		if (nowS > 0 && !visited[nowS - 1][nowC])
		{
			visited[nowS - 1][nowS] = true;
			makeTime[nowS - 1][nowC] = makeTime[nowS][nowC] + 1;
			bfsq.push({ nowS - 1, nowC });
		}
	}
}

int main()
{
	cin >> S;

	bfs();
}