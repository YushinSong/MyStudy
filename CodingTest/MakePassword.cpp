#include <iostream>
#include <vector>
#include <algorithm>

#define endl '\n'

using namespace std;

int L, C;
char arr[9];
bool visited[9];
vector<char> alpha;

bool check()
{
	int vowel = 0, conso = 0;
	for (int i = 0; i < L; ++i)
	{
		if (arr[i] == 'a' || arr[i] == 'e' || arr[i] == 'i' || arr[i] == 'o' || arr[i] == 'u')
			++vowel;
		else
			++conso;
	}
	if (vowel >= 1 && conso >= 2)
		return true;
	else
		return false;
}
void dfs(int now, int num)
{
	if (num == L) // 암호를 완성했을 때
	{
		if(check())
		{
			for (int i = 0; i < L; ++i)
				cout << arr[i];
			cout << '\n';
		}
		return;
	}
	for (int i = now; i < C; ++i)
	{
	    if(!visited[i])
		{
			visited[i] = true;
			arr[num] = alpha[i];
			dfs(i, num + 1);
			visited[i] = false;
		}
	}
}
int main()
{
	cin >> L >> C; // 암호 자릿수, 주어지는 알파벳 수

	for (int i = 0; i < C; ++i)
	{
		char temp;
		cin >> temp;
		alpha.push_back(temp);
	}
	sort(alpha.begin(), alpha.end());

	dfs(0, 0);
}