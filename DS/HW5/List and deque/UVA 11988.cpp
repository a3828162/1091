/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3139
*/

#include<iostream>
#include<list>
#include<string>
using namespace std;

static auto __ = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

int main()
{
	string input;
	while (getline(cin, input))
	{
		list<char> ans;
		auto it = ans.end();
		for (int i = 0; i < input.size(); ++i)
		{
			if (input[i] == '[') it = ans.begin();
			else if (input[i] == ']') it = ans.end();
			else ans.insert(it, input[i]);
		}
		for (auto& i : ans) cout << i;
		cout << "\n";

	}

	return 0;
}





/*int main()
{
	string input;
	while (getline(cin, input))
	{
		list<char> output;
		list<char>::iterator it = output.begin();

		for (auto i : input)
		{
			i == '[' ? it = output.begin() : i == ']' ? it = output.end() : output.insert(it, i);
		}

		for (auto& i : output) cout << i;
		cout << "\n";
	}

	return 0;
}*/

/*
This_is_a_[Beiju]_text
[[]][][]Happy_Birthday_to_Tsinghua_University

BeijuThis_is_a__text
Happy_Birthday_to_Tsinghua_University
*/