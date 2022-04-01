#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[9] = { 0, };
bool visited[9] = { 0, };
vector<int> nums;

void dfs(int now, int num)
{
	if (num == M) // ������ �ϼ����� ��
	{
		for (int i = 0; i < M; ++i)
			cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	for (int i = now; i <= N; ++i)
	{
		if (!visited[i]) // ���� �鸣�� �ʾ��� ��
		{
			visited[i] = true;
			arr[num] = nums[i - 1];
			dfs(i + 1, num + 1);
			visited[i] = false;
		}
	}
}
int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	sort(nums.begin(), nums.end());

	dfs(1, 0);
}