#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

#define INT_MAX 2147483647

using namespace std;

int k; // �ε�ȣ�� ��
bool visited[11];
vector<string> result; // �ε�ȣ �����ϴ� ������
vector<char> signs; // �Էµ� �ε�ȣ��

bool check(string s)
{
	for (int i = 0; i < k; ++i)
	{
		if (signs[i] == '<')
		{
			if (s[i] > s[i + 1])
				return false;
		}
		else
		{
			if (s[i] < s[i + 1])
				return false;
		}
	}
	return true;
}
void dfs(int cnt, string permu) // �� �� ���� ��
{
	if (cnt == k + 1) // ���� �ϼ����� ��
	{
		if (check(permu))
		{
			result.push_back(permu);
		}
		return;
	}
	for (int i = 0; i <= 9; ++i)
	{
		if (!visited[i]) // �湮�� �� ���� ����
		{
			visited[i] = true;
			dfs(cnt + 1, permu + to_string(i)); // ���� ���� üũ
			visited[i] = false; 
		}
	}
}
int main()
{
	cin >> k;

	for (int i = 0; i < k; ++i)
	{
		char temp;
		cin >> temp;
		signs.push_back(temp);
	}

	dfs(0, "");

	cout << *max_element(result.begin(), result.end()) << '\n' << *min_element(result.begin(), result.end()) << '\n';
}