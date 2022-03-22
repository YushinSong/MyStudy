#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// A�� ������������, B�� �����������
// �ε������� ���� �� ���Ѵ�.
int solution(int num, vector<int> A, vector<int> B)
{
	int result = 0;
	sort(A.rbegin(), A.rend());
	sort(B.begin(), B.end());

	for (int i = 0; i < num; ++i)
	{
		result += A[i] * B[i];
	}

	return result;
}
int main()
{
	int num;
	cin >> num;

	vector<int> A;
	vector<int> B;

	for (int i = 0; i < num * 2; ++i)
	{
		int temp;
		cin >> temp;
		if (i < num)
			A.push_back(temp);
		else
			B.push_back(temp);
	}

	cout << solution(num, A, B);
}