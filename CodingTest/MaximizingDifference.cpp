#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;
int maxNum;
int arr[9] = { 0, };
bool visited[9] = { 0, };
vector<int> nums;

int calculation()
{
	int result = 0;
	for (int i = 0; i < N - 1; ++i)
	{
		int temp = abs(arr[i] - arr[i + 1]);
		result += temp;
	}
	return result;
}
void dfs(int num)
{
	if (num == nums.size()) // ������ �ϼ����� ��
	{
		maxNum = max(maxNum, calculation());
		return;
	}
	for (int i = 0; i < N; ++i)
	{
		if (!visited[i]) // ���� �鸣�� �ʾ��� ��
		{
			visited[i] = true;
			arr[num] = nums[i];
			dfs(num + 1);
			visited[i] = false;
		}
	}
}
int main()
{
	cin >> N;
	
	for (int i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}
	
	dfs(0);

	cout << maxNum;
}