#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

// vector�� �ε����� ���ڸ� ���Ѵ�.
// ���� �� ���ڿ� ������ �� �ִ� ����� ���� ���Ѵ�.

int solution(int num)
{
	vector<int> numVector;
	numVector.assign(num + 1, 0);
	
	//numVector[0] = 0; numVector[1] = 0; // 0�� 1�� ������ ����� ������ 0���̴�.

	for (int i = 2; i < num + 1; ++i)
	{
		numVector[i] = numVector[i - 1] + 1; // 1�� ���� ���
		if (i % 2 == 0)
		{
			numVector[i] = min(numVector[i], numVector[i / 2] + 1); // 2�� �������� ���
		}
		if (i % 3 == 0)
		{
			numVector[i] = min(numVector[i], numVector[i / 3] + 1);	// 3���� �������� ���
		}
	}

	return numVector[num];
}

int main()
{
	int num;
	cin >> num;

	cout << solution(num);
}