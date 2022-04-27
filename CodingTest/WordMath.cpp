#include <iostream>
#include <string>
#include <map>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;



int main()
{
	int N; // �ܾ��� ��
	cin >> N;
	map<char, int> words; // ���ڿ�, �ڸ���

	for (int i = 0; i < N; ++i)
	{
		string temp;
		cin >> temp;

		for (int j = 0; j < temp.length(); ++j)
		{
			words[temp[j]] += pow(10, temp.length() - 1 - j);
		}
	}

	vector<int> nums;
	auto iter = words.begin();
	while (iter != words.end())
	{
		nums.push_back(iter->second);
		++iter;
	}

	sort(nums.begin(), nums.end(), greater<>());

	int result = 0;
	for (int i = 0; i < nums.size(); ++i)
	{
		result += (9 - i) * nums[i];
	}
	cout << result;
}