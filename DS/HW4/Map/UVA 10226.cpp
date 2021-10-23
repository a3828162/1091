/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1167
*/

#include <iostream>
#include<string>
#include <iomanip>
#include <map>
using namespace std;

static auto __ = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

map<string, double> dic;
string input;
int T;
double total;

int main()
{
	cin >> T;
	cin.ignore();
	getline(cin, input);

	while (T--)
	{
		dic.clear();
		total = 0;

		while (getline(cin, input) && input != "")
		{
			++dic[input];
			++total;
		}

		for (auto& [l, r] : dic)
		{
			cout << l << " " << setprecision(4) << fixed << (r / total) * 100 << "\n";
		}
		if (T) cout << "\n";
	}

	return 0;
}







/*int main()
{
	cin >> T;
	cin.ignore();
	getline(cin, input);

	while (T--)
	{
		dic.clear();
		total = 0;
		while (getline(cin, input) && input != "") ++dic[input], ++total;

		for (auto& [tree, num] : dic) cout << tree << " " << setprecision(4) << fixed << num*100/total << "\n";

		if (T) cout << "\n";
	}

	return 0;
}*/

/*
1

Red Alder
Ash
Aspen
Basswood
Ash
Beech
Yellow Birch
Ash
Cherry
Cottonwood
Ash
Cypress
Red Elm
Gum
Hackberry
White Oak
Hickory
Pecan
Hard Maple
White Oak
Soft Maple
Red Oak
Red Oak
White Oak
Poplan
Sassafras
Sycamore
Black Walnut
Willow

Ash 13.7931
Aspen 3.4483
Basswood 3.4483
Beech 3.4483
Black Walnut 3.4483
Cherry 3.4483
Cottonwood 3.4483
Cypress 3.4483
Gum 3.4483
Hackberry 3.4483
Hard Maple 3.4483
Hickory 3.4483
Pecan 3.4483
Poplan 3.4483
Red Alder 3.4483
Red Elm 3.4483
Red Oak 6.8966
Sassafras 3.4483
Soft Maple 3.4483
Sycamore 3.4483
White Oak 10.3448
Willow 3.4483
Yellow Birch 3.4483
*/