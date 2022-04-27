#include <iostream>
#include <vector>

#define endl '\n'
#define INTMAX 2147483647

using namespace std;

int N; // ������ ��
vector<int> nums; // �Էµ� ����
int minNum = INTMAX;
int maxNum = INTMAX * -1;

int operators[4]; // �����ڸ����� ���� + - * /
bool visited[101]; // ������ �湮���� üũ

void dfs(int result, int cnt) // ���� ���, ���� ��
{
	if (cnt >= N)
	{
		minNum = min(minNum, result);
		maxNum = max(maxNum, result);
		return;
	}
	for (int i = 0; i < 4; ++i) // �����ڸ��� �˻�
	{
		if (operators[i] > 0) // �ش� ������ �� ��� ������ ��
		{
			--operators[i];
			if (i == 0) // +
				dfs(result + nums[cnt], cnt + 1);
			else if (i == 1) // -
				dfs(result - nums[cnt], cnt + 1);
			else if (i == 2) // *
				dfs(result * nums[cnt], cnt + 1);
			else if (i == 3) // /
				dfs(result / nums[cnt], cnt + 1);
			++operators[i]; // ��������
		}
	}
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
	for (int i = 0; i < 4; ++i)
	{
		cin >> operators[i];
	}

	dfs(nums[0], 1); // �̹� ù��° ���� �����Ŵϱ� ���� 1

	cout << maxNum << endl << minNum;
}