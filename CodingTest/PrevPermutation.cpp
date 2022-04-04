#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solution(int N, vector<int> nums)
{
	if (prev_permutation(nums.begin(), nums.end()))
	{
		for (int i : nums)
			cout << i << " ";
	}
	else
		cout << -1;
}
int main()
{
	int N;
	cin >> N;
	vector<int> nums;

	for (int i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;
		nums.push_back(temp);
	}

	solution(N, nums);
}