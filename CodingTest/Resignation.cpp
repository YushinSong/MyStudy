#include <iostream>
#include <algorithm>
#include <utility>
#include <vector>

using namespace std;

int N;  // ���� ��
vector<pair<int, int>> counseling;
int maxProfit;

void solution(int i, int p) // ������ �ε���, ��������� ����
{
	if (i > N) // ������ �ʰ��� ���
		return;
	if (i == N) // ������ ��� Ȯ���� ���
	{
		if (p > maxProfit)
			maxProfit = p;
		return;
	}

	solution(i + counseling[i].first, p + counseling[i].second); // ������ ������ ���
	solution(i + 1, p); // �������� ���� ���
}
int main()
{
	cin >> N; 

	for (int i = 0; i < N; ++i)
	{
		int T, P;
		cin >> T >> P;

		counseling.push_back(make_pair(T, P));
	}
	
	solution(0, 0);

	cout << maxProfit;

	return 0;
}