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
	if (num == M) // 순열을 완성했을 때
	{
		for (int i = 0; i < M; ++i)
			cout << arr[i] << " ";
		cout << '\n';
		return;
	}
	int last = 0;
	for (int i = now; i <= N; ++i)
	{
		if (nums[i - 1] != last) // 아직 들르지 않았을 때, 중복되지 않을 때
		{
			arr[num] = nums[i - 1];
			last = nums[i - 1];

			visited[i] = true;
			dfs(i, num + 1);
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