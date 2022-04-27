#include <iostream>
#include <vector>

#define endl '\n'

using namespace std;

int N; // �Էµ� ������ ��
vector<int> nums; // �Էµ� ������
vector<bool> able(2000001); // ���� �� �ִ� ����

void dfs(int sum, int index) // ���ݱ��� ���� ��, nums�ε��� 
{
	able[sum] = true;
	if (index >= N) // ��� ���� Ȯ���� ���
		return;

	dfs(sum, index + 1); // ���� �ε����� ���� ������ ���
	dfs(sum + nums[index], index + 1); // ���� �ε����� ���� �������� ���� ���
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

	dfs(0, 0);
	for (int i = 1; i < able.size(); ++i)
	{
		if (able[i] == false)
		{
			cout << i;
			break;
		}
	}
}