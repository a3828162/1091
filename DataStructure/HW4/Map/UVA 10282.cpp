/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1223
*/

#include<iostream>
#include<string>
#include<map>
#include<sstream>
using namespace std;

static auto __ = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

string input, a, b;
map<string, string> dic;

int main()
{
	while (getline(cin, input) && input != "")
	{
		stringstream ss(input);
		ss >> a >> b;
		dic[b] = a;
	}

	while (getline(cin, input) && input != "")
	{
		if (dic.count(input)) cout << dic[input] << "\n";
		else cout << "eh\n";
	}

	return 0;
}



/*int main()
{
	while (getline(cin, input) && input != "")
	{
		stringstream ss(input);
		ss >> a >> b;
		dic[b] = a;
	}

	while (getline(cin, input)) dic.count(input) ? cout << dic[input] << "\n" : cout << "eh\n";

	return 0;
}*/

/*
dog ogday
cat atcay
pig igpay
froot ootfray
loops oopslay

atcay
ittenkay
oopslay

cat
eh
loops
*/