#include <string>
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

// 스텍에 자신보다 큰 숫자가 나올때까지 pop하고, push한다.
string solution(string number, int k) {
    string answer = "";
    stack<char> numberStack;

    for (int i = 0; i < number.size(); ++i)
    {
        if (k <= 0)
        {
            numberStack.push(number[i]);
            continue;
        }
        if (numberStack.empty())
        {
            numberStack.push(number[i]);
            continue;
        }

        while (!numberStack.empty() && k > 0 && numberStack.top() < number[i])
        {
            numberStack.pop();
            --k;
        }
        numberStack.push(number[i]);
    }
    while (k != 0)
    {
        numberStack.pop();
        --k;
    }
    string temp;
    while (!numberStack.empty())
    {
        temp += numberStack.top();
        numberStack.pop();
    }
    for (int i = temp.size() - 1; i >= 0; --i)
    {
        answer += temp[i];
    }

    return answer;
}
int main()
{
    string num;
    int k;
    cin >> num >> k;

    cout << solution(num, k);
}