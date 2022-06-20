#include <iostream>
#include <map>
using namespace std;

int main() {
    map<int, string> temp;

    temp.insert({ 1, "hello" });
    temp.insert(make_pair(2, "world"));
    temp[3] = "map";

    cout << temp[1] << '\n';
    cout << temp[2] << '\n';
    cout << temp[3] << '\n';

    cout << temp.size() << '\n';
    return 0;
}