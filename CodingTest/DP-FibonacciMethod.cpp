#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 1003��: �Ǻ���ġ �Լ�
// 0�� ������ �� �ε����� 1�� ����
// 1�� ������ �� �ε��� 0�� 1�� ���� ��
int zero[10000];
int one[10000];

void solution(int num)
{
	zero[0] = 1; one[0] = 0;

	for (int i = 1; i < num + 1; ++i)
	{
		zero[i] = one[i - 1];
		one[i] = zero[i - 1] + one[i - 1];
	}
}
int main()
{
	int num;
	cin >> num;
	vector<int> testCase;

	for (int i = 0; i < num; ++i)
	{
		int temp;
		cin >> temp;

		testCase.push_back(temp);
	}

	solution(*max_element(testCase.begin(), testCase.end()));

	for (int i = 0; i < num; ++i)
	{
		cout << zero[testCase[i]] << " " << one[testCase[i]] << endl;
	}
}