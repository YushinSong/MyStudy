#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

#define endl '\n'

using namespace std;

int N; // ������ ũ��
int map[25][25]; // �Էµ� ����
int visited[25][25]; // �湮���� üũ
vector<int> complex; // ����
int cnt; // ������ �� �� ī��Ʈ

int moveRow[4] = { -1, 0, 1, 0 };
int moveCol[4] = { 0, 1, 0, -1 };

void dfs(int row, int col) // ã�� ��
{
	for (int i = 0; i < 4; ++i)
	{
		int nextRow = row + moveRow[i];
		int nextCol = col + moveCol[i];

		if (nextRow >= N || nextRow < 0 || nextCol >= N || nextCol < 0)
			continue;

		if (!visited[nextRow][nextCol] && map[nextRow][nextCol] == 1) // �����ϴ� ��, �湮�� �� ����
		{
			visited[nextRow][nextCol] = true;
			++cnt;
			dfs(nextRow, nextCol);
		}
	}
}
int main()
{
	cin >> N;

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			char temp;
			cin >> temp;

			if(temp == '1')
				map[i][j] = 1;
			else
				map[i][j] = 0;
		}
	}

	int result = 0;
	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < N; ++j)
		{
			if (map[i][j] == 1 && !visited[i][j]) // �����ϴ� ��, �湮���� ���� ��
			{
				visited[i][j] = true;
				cnt = 1;
				dfs(i, j); // ����ϴ� ���� �ٲ��
				++result;
				complex.push_back(cnt);
			}
		}
	}
	sort(complex.begin(), complex.end());
	cout << result << endl;
	for (int i : complex)
		cout << i << endl;
}