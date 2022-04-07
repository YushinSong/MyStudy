#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

#define INT_MAX 2147483647

using namespace std;

int N; // ���� ��
int minDiff = INT_MAX;
int team[21]; // ������ ������ �� ���� ��ŸƮ, �ڴ� ��ũ��
bool visited[21];
vector<vector<int>> stats; // �Էµ� �ɷ�ġ��

void dfs(int now, int cnt) // ���� �ڸ���, �� �� �� ��
{
	if (cnt >= N / 2) // ��ŸƮ�� ���� �Ϸ����� ��
	{
		int start = 0, link = 0;
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < N; ++j)
			{
				if (visited[i] && visited[j]) // ���� ��ŸƮ�� �ɷ�ġ ���
					start += stats[i][j];
				else if (!visited[i] && !visited[j]) // �������� ��ũ�� �ɷ�ġ ���
					link += stats[i][j];
			}
		}
		minDiff = min(minDiff, abs(start - link));
		return;
	}
	for (int i = now; i < N; ++i)
	{
		if (!visited[i]) // �湮�� �� ���� ����
		{
			visited[i] = true; // ���缱�� �湮üũ
			dfs(i + 1, cnt + 1); // ���� ���� üũ
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

	dfs(0, 0); // ��ߵ���, ���絵��, �湮�� ���� ��, �� ��ȸ ���

	cout << minDiff;
}