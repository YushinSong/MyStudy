#include <string>
#include <vector>

using namespace std;

bool checkAlpha(string a, string b)
{
    int count = 0;

    for (int i = 0; i < a.length(); ++i)
    {
        if (a[i] != b[i])
            ++count;
    }

    if (count == 1)
        return true;
    return false;
}
void dfs(string begin, string target, vector<string> words, int& answer, vector<bool>& visited, int deep)
{
    if (answer <= deep)
        return;

    if (begin == target)
    {
        answer = min(answer, deep);
        return;
    }

    for (int i = 0; i < words.size(); ++i)
    {
        if (!visited[i] && checkAlpha(begin, words[i]))
        {
            visited[i] = true;
            dfs(words[i], target, words, answer, visited, deep + 1);
            visited[i] = false;
        }
    }
}
int solution(string begin, string target, vector<string> words)
{
    int answer = 50;
    vector<bool> visited;
    for (string s : words)
        visited.push_back(false);

    dfs(begin, target, words, answer, visited, 0);

    if (answer == 50)
        return 0;
    return answer;
}