#include <string>   // C++ STL ���ڿ� Ŭ���� �̿��� ���� �������
#include <iostream> // C++ ������� ���� �������

using namespace std;

int solution(string s) {
    int answer = 0;

    string number[10] = { "zero", "one","two","three","four","five","six","seven","eight","nine" }; // number reference

    for (int idx = 0; idx < 10; idx++)  // iterate 0 to 9
    {
        while (s.find(number[idx]) != string::npos)     // number[i]�� ã���� ���� �ε����� ��ȯ
                                                        // �� ã���� string::npos ��ȯ
                                                        // find() �Լ��� ���ؼ� found ���� ���ϴ� ��� npos���� ����

            s.replace(s.find(number[idx]), number[idx].length(), to_string(idx));   // s.find(number[i]) : ã�� ���ڿ��� ��ġ
                                                                                    // number[i].length() : ã�� ���ڿ��� ����
                                                                                    // to_string(i) : ��ü�� ���ο� ���ڿ�
    }

    answer = stoi(s);   // string to integer. ��ȯ���� int
    return answer;
}

int main() {
    cout << solution("twothree45sixtwo") << endl;
}