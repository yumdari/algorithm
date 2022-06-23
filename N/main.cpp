#include <vector>   // vector
#include <iostream> //  cout
#include <set>      // set

using namespace std;

int solution(int N, int number) {   //  N : 사용할 숫자 (1 ~ 9)
                                    //  number : 만들고자하는 숫자 (1 ~ 32000)

    int answer = -1;    // answer 선언 및 -1로 초기화. 
                        // answer : N과 사칙연산을 이용해서 number를 표현할 수 있는 N의 최소 사용횟수 (-1, 1~8)
                        // answer = 사용 횟수가 9회 이상일 경우

    int temp = 0;

    vector<set<int>>numbers(9); // vector of sets
                                // N이 1부터 9까지 이므로 크기가 9

    for (int idx = 1; idx < 9; idx++)   // idx : 숫자를 사용하는 횟수
    {                                   // idx : 1 -> numbers[1]에 N을 삽입
        temp = (temp * 10) + N;         //     :  
        numbers[idx].insert(temp);      //     :  
    }                                   // idx : 9 -> numbers[9]에 NNNNNNNNN을 삽입

    if (number == N) return 1;  // 숫자와 목표값이 같으면 1을 반환. (숫자를 한 번만 사용하여 목표 값을 표현할 수 있음)

    for (int idx = 2; idx < 9; idx++)                                               // idx는 숫자 사용횟수 (2 ~ 8). 1번만 사용하면 N만 만들 수 있음                                    
    {
        for (int jdx = 1; jdx < idx; jdx++)
        {
            int kdx = idx - jdx;                                                    
            for (int m : numbers[jdx])
            {
                for (int n : numbers[kdx])
                {                                                                   // 사칙연산 결과 값을 저장하는 부분
                    numbers[idx].insert(m + n);                                     // 덧셈 값을 vector에 저장
                    if (m - n >= 0)numbers[idx].insert(m - n);                      // 뺄셈 값이 양수이면 값을 vector에 저장
                    numbers[idx].insert(m * n);                                     // 곱셈 값을 vector에 저장
                    if (m != 0 && n != 0 && m / n >= 1)numbers[idx].insert(m / n);  // 분모가 0이 아니면 값을 vector에 저장
                }
            }
        }
        if (numbers[idx].find(number) != numbers[idx].end())    // numbers vector에 목표값이 있으면 idx 반환
            return idx;                                         // idx는 숫자의 사용 횟수 (1 ~ 9)
    }
    return answer;
}

int main() {
    int N = 5;  // 사용할 숫자 (1 ~ 9)
    int number = 12;    // 표현하고 싶은 숫자 (1 ~ 32000)
    cout << solution(N, number) << endl;
}