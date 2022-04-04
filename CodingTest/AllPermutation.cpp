#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solution(vector<int> nums)
{
	do {
		for (int i : nums)
			cout << i << " ";
		cout << '\n';
	} while (next_permutation(nums.begin(), nums.end()));
}
int main()
{
	int N;
	cin >> N;
	vector<int> nums;

	for (int i = 1; i <= N; ++i)
	{
		nums.push_back(i);
	}

	solution(nums);
}