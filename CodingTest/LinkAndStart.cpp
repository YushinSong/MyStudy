#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define INT_MAX 2147483647

using namespace std;

int N; // ���� ��
int minDiff = INT_MAX;
bool visited[21];
vector<vector<int>> stats; // �Էµ� �ɷ�ġ��
//
//int calculator(vector<int> v)
//{
//	int result = 0;
//	for (int i = 0; i < v.size(); ++i)
//	{
//		for (int j = 0; j < v.size(); ++j)
//		{
//			if (i != j)
//				result += stats[v[i]][v[j]];
//		}
//	}
//	return result;
//}
void dfs(int startNum, int now, int cnt) // ���� �ڸ���, �� �� �� ��
{
	if (startNum == now) // ��ŸƮ�� ���� �Ϸ����� ��
	{
		int start = 0, link = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (i != j)
				{
					if (visited[i] && visited[j]) // ���� ��ŸƮ�� �ɷ�ġ ���
						start += stats[i][j];
					else if (!visited[i] && !visited[j]) // �������� ��ũ�� �ɷ�ġ ���
						link += stats[i][j];
				}
			}
		}
		minDiff = min(minDiff, abs(start - link));

		//vector<int> start, link;
		//
		//for (int i = 0; i < N; ++i)
		//{
		//	if (visited[i])
		//		start.push_back(i);
		//	else
		//		link.push_back(i);
		//}
		//minDiff = min(minDiff, abs(calculator(start) - calculator(link)));
		return;
	}
	for (int i = now; i < N; ++i)
	{
		if (!visited[i]) // �湮�� �� ���� ����
		{
			visited[i] = true; // ���缱�� �湮üũ
			dfs(startNum, i, cnt + 1); // ���� ���� üũ
			visited[i] = false; // ���缱�� �湮üũ �ʱ�ȭ
		}
	}
}
int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		vector<int> tempV;
		for (int i = 0; i < N; ++i)
		{
			int temp;
			cin >> temp;
			tempV.push_back(temp);
		}
		stats.push_back(tempV);
	}
	
	for (int i = 1; i <= N; ++i)
	{
		dfs(i, 0, 0); // ��ŸƮ ���� ��, ���� �ڸ���, �� �� �� ��
	}


	cout << minDiff;
}