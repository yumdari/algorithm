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
	// ������ �ʱ�ȭ �մϴ�.
	House h1(1, "one");
	House h2(2, "two");
	House h3(3, "three");
	House h4(4, "four");
	House h5(5, "five");
	House h6(6, "six");
	House h7(7, "seven");
	House h8(8, "eight");
	House h9(9, "nine");

	// ���� �ʱ�ȭ �մϴ�.
	map<int, House> myMap;

	// �ʿ� ���� �ֽ��ϴ�.
	myMap.insert({ 1, h1 });
	myMap.insert({ 2, h2 });
	myMap.insert({ 3, h3 });
	myMap.insert({ 4, h4 });
	myMap.insert({ 5, h5 });
	myMap.insert({ 6, h6 });
	myMap.insert({ 7, h7 });
	myMap.insert({ 8, h8 });
	myMap.insert({ 9, h9 });

	// ������ Ű�� ã���ϴ�.
	for (auto const& house : myMap)
	{
		if (house.second.ownerName.compare("seven") == 0)
		{
			cout << "������ Ű ã�� " << house.second.ownerName  << endl;
		}
	}

	// Ű�� ���� ã���ϴ�.
	cout << "Ű�� �� ã�� " << myMap.at(4).ownerName << endl;

}
