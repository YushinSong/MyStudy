#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

#define SIZE 51
#define endl '\n'

using namespace std;

int N, M; // �������� ũ��. ����, ����
string dots[SIZE]; // �Էµ� ��Ʈ��
int visited[SIZE][SIZE]; // �湮���� üũ

int startH, startW; // �˻������� ��ġ
char startColor; // ������ġ�� ��

int moveHigh[4] = { -1, 0, 1, 0 };
int moveWidth[4] = { 0, 1, 0, -1 };

void dfs(int high, int width, int depth) // ã�� ��, ����
{
	if (startH == high && startW == width && depth >= 4) // ����Ŭ �ϼ�
	{
		cout << "Yes" << endl;
		exit(0);
	}
	for (int i = 0; i < 4; ++i)
	{
		int nextH = high + moveHigh[i];
		int nextW = width + moveWidth[i];

		if (nextH >= N || nextH < 0 || nextW >= M || nextW < 0)
			continue;

		if (!visited[nextH][nextW] && dots[nextH][nextW] == startColor) // �湮�� �� ����, ���� ���� ��
		{
			visited[nextH][nextW] = true;
			dfs(nextH, nextW, depth + 1);
			visited[nextH][nextW] = false;
		}
	}
}
int main()
{
	cin >> N >> M;

	for (int i = 0; i < N; ++i)
	{
		string temp;
		cin >> temp;

		dots[i] = temp;
	}

	for (int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			if (!visited[i][j]) // �湮���� ���� ĭ
			{
				//visited[i][j] = true;
				startH = i; startW = j;
				startColor = dots[i][j];
				dfs(i, j, 0);
			}
		}
	}
	cout << "No" << endl;
}