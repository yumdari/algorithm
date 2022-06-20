#include <iostream>
#include <map>

using namespace std;

class House
{
public:
	int houseName;
	string ownerName;
	House(int houseName,string ownerName)
	{
		this->houseName = houseName;
		this->ownerName = ownerName;
	}
};


int main()
{
	// 집들을 초기화 합니다.
	House h1(1, "one");
	House h2(2, "two");
	House h3(3, "three");
	House h4(4, "four");
	House h5(5, "five");
	House h6(6, "six");
	House h7(7, "seven");
	House h8(8, "eight");
	House h9(9, "nine");

	// 맵을 초기화 합니다.
	map<int, House> myMap;

	// 맵에 값을 넣습니다.
	myMap.insert({ 1, h1 });
	myMap.insert({ 2, h2 });
	myMap.insert({ 3, h3 });
	myMap.insert({ 4, h4 });
	myMap.insert({ 5, h5 });
	myMap.insert({ 6, h6 });
	myMap.insert({ 7, h7 });
	myMap.insert({ 8, h8 });
	myMap.insert({ 9, h9 });

	// 값으로 키를 찾습니다.
	for (auto const& house : myMap)
	{
		if (house.second.ownerName.compare("seven") == 0)
		{
			cout << "값으로 키 찾기 " << house.second.ownerName  << endl;
		}
	}

	// 키로 값을 찾습니다.
	cout << "키로 값 찾기 " << myMap.at(4).ownerName << endl;

}
