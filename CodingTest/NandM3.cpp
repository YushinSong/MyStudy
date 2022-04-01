#include <iostream>

using namespace std;

int N, M;
int arr[9] = { 0, };
bool visited[9] = { 0, };

void dfs(int num)
{
	if (num == M) // 순열을 완성했을 때
	{
		for (int i = 0; i < M; ++i)
			cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; ++i)
	{
		visited[i] = true;
		arr[num] = i;
		dfs(num + 1);
		visited[i] = false;
	}
}
int main()
{
	cin >> N >> M;

	dfs(0);
}