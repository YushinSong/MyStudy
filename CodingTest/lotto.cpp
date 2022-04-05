#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int arr[14];
bool visited[14];
vector<int> nums;

void dfs(int now, int cnt)
{
	if (cnt == 6) // ������ �ϼ����� ��
	{
		for (int i = 0; i < 6; ++i)
			cout << arr[i] << " ";
		cout << endl;
		return;
	}
	for (int i = now; i < nums.size(); ++i)
	{
		if (!visited[i]) // ���� �鸣�� �ʾ��� ��
		{
			visited[i] = true;
			arr[cnt] = nums[i];
			dfs(i + 1, cnt + 1);
			visited[i] = false;
		}
	}
}
int main()
{
	int num;
	while (cin >> num && num) // ù��° �� �ԷµǴ� ��ŭ, ù��° ���� 0�� �ƴҶ�����
	{
		vector<int> tempV;
		for (int i = 0; i < num; ++i)
		{
			int temp;
			cin >> temp;
			tempV.push_back(temp);
		}
		nums = tempV;
		dfs(0, 0); // ���� ����, �湮�� ���� ��
		cout << endl;
	}
}