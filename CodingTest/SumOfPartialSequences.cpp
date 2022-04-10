#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int N, S; // �Էµ� ������ ��, ���;��ϴ� ��
int countCase; // ����� ��
vector<int> nums; // �Էµ� ������

void dfs(int index, int sum) // ���� ���� �ε���, ���ݱ��� ���� ��
{
	if (index >= N) // ��� ���� Ȯ���� ���
		return;

	sum += nums[index];

	if (sum == S) // ���� ���� ���
		++countCase;

	dfs(index + 1, sum); // ���� �ε����� ���� ������ ���
	dfs(index + 1, sum - nums[index]); // ���� �ε����� ���� �������� ���� ���
}
int main()
{
	cin >> N >> S;

	for (int i = 0; i < N; ++i)
	{
		int temp;
		cin >> temp;

		nums.push_back(temp);
	}

	dfs(0, 0);

	cout << countCase << endl;
}