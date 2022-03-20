#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>

using namespace std;
// 벡터 <장르, 플레이수>로 저장
// 순회하면서 어떤 장르 제일 큰지 비교. 맵 <장르, 총 플레이수> 저장
// 맵 순회하면서 <총 플레이수, 장르> 로 또 저장
// {
//     맵에서 제일 큰거 삭제
//     벡터 순회하면서 해당 장르 값 <플레이수, 고유번호>로 저장
//     자동정렬이니까 처음부터 두번째까지(있으면) 꺼내기
// }
// 맵 <장르, 총 플레이수> 이게 텅 빌때까지 반복
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