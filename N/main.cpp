#include <vector>   // vector
#include <iostream> //  cout
#include <set>      // set

using namespace std;

int solution(int N, int number) {   //  N : ����� ���� (1 ~ 9)
                                    //  number : ��������ϴ� ���� (1 ~ 32000)

    int answer = -1;    // answer ���� �� -1�� �ʱ�ȭ. 
                        // answer : N�� ��Ģ������ �̿��ؼ� number�� ǥ���� �� �ִ� N�� �ּ� ���Ƚ�� (-1, 1~8)
                        // answer = ��� Ƚ���� 9ȸ �̻��� ���

    int temp = 0;

    vector<set<int>>numbers(9); // vector of sets
                                // N�� 1���� 9���� �̹Ƿ� ũ�Ⱑ 9

    for (int idx = 1; idx < 9; idx++)   // idx : ���ڸ� ����ϴ� Ƚ��
    {                                   // idx : 1 -> numbers[1]�� N�� ����
        temp = (temp * 10) + N;         //     :  
        numbers[idx].insert(temp);      //     :  
    }                                   // idx : 9 -> numbers[9]�� NNNNNNNNN�� ����

    if (number == N) return 1;  // ���ڿ� ��ǥ���� ������ 1�� ��ȯ. (���ڸ� �� ���� ����Ͽ� ��ǥ ���� ǥ���� �� ����)

    for (int idx = 2; idx < 9; idx++)                                               // idx�� ���� ���Ƚ�� (2 ~ 8). 1���� ����ϸ� N�� ���� �� ����                                    
    {
        for (int jdx = 1; jdx < idx; jdx++)
        {
            int kdx = idx - jdx;                                                    
            for (int m : numbers[jdx])
            {
                for (int n : numbers[kdx])
                {                                                                   // ��Ģ���� ��� ���� �����ϴ� �κ�
                    numbers[idx].insert(m + n);                                     // ���� ���� vector�� ����
                    if (m - n >= 0)numbers[idx].insert(m - n);                      // ���� ���� ����̸� ���� vector�� ����
                    numbers[idx].insert(m * n);                                     // ���� ���� vector�� ����
                    if (m != 0 && n != 0 && m / n >= 1)numbers[idx].insert(m / n);  // �и� 0�� �ƴϸ� ���� vector�� ����
                }
            }
        }
        if (numbers[idx].find(number) != numbers[idx].end())    // numbers vector�� ��ǥ���� ������ idx ��ȯ
            return idx;                                         // idx�� ������ ��� Ƚ�� (1 ~ 9)
    }
    return answer;
}

int main() {
    int N = 5;  // ����� ���� (1 ~ 9)
    int number = 12;    // ǥ���ϰ� ���� ���� (1 ~ 32000)
    cout << solution(N, number) << endl;
}