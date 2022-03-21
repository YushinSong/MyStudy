#include <string>
#include <vector>
#include <queue>

using namespace std;
vector<int> solution(vector<string> operations)
{
    vector<int> answer;

    priority_queue<int, vector<int>> maxQueue;
    priority_queue<int, vector<int>, greater<int>> minQueue;
    int queueCount = 0;

    for (string s : operations)
    {
        if (queueCount == 0)
        {
            while (!maxQueue.empty())
            {
                maxQueue.pop();
            }
            while (!minQueue.empty())
            {
                minQueue.pop();
            }
        }

        char order = s[0];
        string receive;
        for (int i = 2; i < s.length(); ++i)
        {
            receive += s[i];
        }

        if (order == 'I') // ť�� �־��� ���� ����
        {
            maxQueue.push(stoi(receive));
            minQueue.push(stoi(receive));
            ++queueCount;
        }
        else if (queueCount > 0 && order == 'D' && receive == "1") // ť �ִ� ����
        {
            maxQueue.pop();
            --queueCount;
        }
        else if (queueCount > 0 && order == 'D' && receive == "-1") // ť �ּڰ� ����
        {
            minQueue.pop();
            --queueCount;
        }
    }

    if (queueCount > 0)
    {
        answer.push_back(maxQueue.top());
        answer.push_back(minQueue.top());
    }
    else
    {
        answer.push_back(0);
        answer.push_back(0);
    }
    return answer;
}