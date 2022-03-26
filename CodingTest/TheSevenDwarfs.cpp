#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void print(vector<int> heights, int num1, int num2)
{
	for (int i = 0; i < 9; ++i)
	{
		if(i != num1 && i != num2)
			cout << heights[i] << endl;
	}
}
void solution(vector<int> heights)
{
	sort(heights.begin(), heights.end());
	int sum = 0;
	for (int i : heights)
		sum += i;

	for (int i = 0; i < 9; ++i)
	{
		for (int j = 0; j < 9; ++j)
		{
			if (i == j)
				continue;

			if (sum - heights[i] - heights[j] == 100)
			{
				print(heights, i, j);
				return;
			}
		}
	}
}
int main()
{
	vector<int> heights;

	for (int i = 0; i < 9; ++i)
	{
		int temp;
		cin >> temp;
		heights.push_back(temp);
	}
	cout << endl;
	solution(heights);
}