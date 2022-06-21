#include <string>
#include <vector>
#include <iostream>

using namespace std;
int main() {
    vector<int> answers = { 4,4,4,5,4,5,1,2,4 };

    vector<int> solve1 = { 1,2,3,4,5 };
    vector<int> solve2 = { 2,1,2,3,2,4,2,5 };
    vector<int> solve3 = { 3,3,1,1,2,2,4,4,5,5 };

    vector<int> count(3, 0);    // vector 3개 생성 후 0으로 초기화

    for (auto idx = 0; idx < answers.size(); idx++)
    {
        if (answers[idx] == solve1[idx % 5])
        {
            count[0] ++;
        }
        else if (answers[idx] == solve2[idx % 8])
        {
            count[1] ++;
        }

        else if (answers[idx] == solve3[idx % 10])
        {
            count[2] ++;
        }
    }

    for (auto idx = 0; idx < 3; idx++)
    {
        cout << idx+1 << "번째 사람의 정답 개수 : " << count[idx] << endl;
    }


    return 0;
}