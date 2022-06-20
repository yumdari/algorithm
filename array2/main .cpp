#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <string>

using namespace std;

int solution(string s) {
    int answer = 0;
    int findNum = 0;
    int flag = 0;
    cout << s << endl;

    map<int, string> strandard;
    map<int, string> result;

    string temp = "";
    temp = "test";
    //cout << temp << endl;
    for (int idx = 0 ; idx < 9 ; idx++){
        //findNum = s.find(to_string(idx));
        //cout << s.find(to_string(idx)) << endl;
    }
    for (int idx = 97; idx < 123; idx++) {
        if(s.find(char(idx)) != string::npos){ 
            cout << s.find(char(idx)) << endl; 
        }
            
        //cout << char(idx) << endl;
    }
 /*   s.find("one");
    s.find("two");
    s.find("three");
    s.find("four");
    s.find("five");
    s.find("six");
    s.find("seven");
    s.find("eight");
    s.find("nine");
    s.find("zero");*/
 
    
    return answer;
}

int main() {
    solution("one4seveneight");
}