#include <iostream>
#define endl '\n'

using namespace std;

int N, M;
int arr[9] = { 0, };
bool visited[9] = { 0, };

void dfs(int now, int num)
{
	if (num == M) // 순열을 완성했을 때
	{
		for (int i = 0; i < M; ++i)
			cout << arr[i] << " ";
		cout << endl;
		return;
	}
	for (int i = now; i <= N; ++i)
	{
		visited[i] = true;
		arr[num] = i;
		dfs(i, num + 1);
		visited[i] = false;
	}
}
int main()
{
	cin >> N >> M;

	dfs(1, 0);
}