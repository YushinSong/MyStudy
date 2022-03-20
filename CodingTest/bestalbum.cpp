#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;
// ���� <�帣, �÷��̼�>�� ����
// ��ȸ�ϸ鼭 � �帣 ���� ū�� ��. �� <�帣, �� �÷��̼�> ����
// �� ��ȸ�ϸ鼭 <�� �÷��̼�, �帣> �� �� ����
// {
//     �ʿ��� ���� ū�� ����
//     ���� ��ȸ�ϸ鼭 �ش� �帣 �� <�÷��̼�, ������ȣ>�� ����
//     �ڵ������̴ϱ� ó������ �ι�°����(������) ������
// }
// �� <�帣, �� �÷��̼�> �̰� �� �������� �ݺ�
//
vector<int> solution(vector<string> genres, vector<int> plays)
{
    vector<int> answer;

    vector<pair<string, int>> totalGerensPlays;
    map<string, int> genresTotalPlay;

    for (int i = 0; i < genres.size(); ++i)
    {
        totalGerensPlays.push_back({ genres[i], plays[i] });

        if (genresTotalPlay.find(genres[i]) == genresTotalPlay.end())
        {
            genresTotalPlay.insert(pair<string, int>(genres[i], plays[i]));
        }
        else
        {
            genresTotalPlay[genres[i]] += plays[i];
        }
    }


    map<int, string, greater<int>> totalPlaysGenres;
    map<string, int>::iterator gIter;
    for (gIter = genresTotalPlay.begin(); gIter != genresTotalPlay.end(); ++gIter)
    {
        totalPlaysGenres.insert(pair<int, string>(gIter->second, gIter->first));
    }


    while (!totalPlaysGenres.empty())
    {
        map<int, string>::iterator tIter;
        tIter = totalPlaysGenres.begin();
        string maxGenre = tIter->second;
        totalPlaysGenres.erase(tIter);

        multimap<int, int, greater<int>> playsNum;
        for (int i = 0; i < totalGerensPlays.size(); ++i)
        {
            if (totalGerensPlays[i].first == maxGenre)
            {
                playsNum.insert(pair<int, int>(totalGerensPlays[i].second, i));
            }
        }

        multimap<int, int>::iterator pIter;
        int count = 0;
        for (pIter = playsNum.begin(); pIter != playsNum.end(); ++pIter)
        {
            answer.push_back(pIter->second);
            ++count;
            if (count >= 2)
                break;
        }
    }

    return answer;
}