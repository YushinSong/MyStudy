#include <iostream>
#define endl '\n'

using namespace std;

int N, M;
int arr[9] = { 0, };
bool visited[9] = { 0, };

void dfs(int now, int num)
{
	if (num == M) // ������ �ϼ����� ��
	{
		for (int i = 0; i < M; ++i)
			cout << arr[i] << " ";
		cout << endl;
		return;
	}
	for (int i = now; i <= N; ++i)
	{
		if (!visited[i]) // ���� �鸣�� �ʾ��� ��
		{
			visited[i] = true;
			arr[num] = i;
			dfs(i + 1, num + 1);
			visited[i] = false;
		}
	}
}
int main()
{
	cin >> N >> M;

	dfs(1, 0);
}