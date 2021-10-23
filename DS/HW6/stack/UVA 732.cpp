/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&category=0&problem=673

題目說明: 有個stack,輸入input跟target來,輸出所有透過stack來把input變成target,i代表放進stack, o代表輸出stack最上方的
		  , 輸出所有方法

code說明: 用DFS來做, 用is1,is2來記錄現在是第幾個字母跟順序, 因為要找所有的可能, 所以DFS完之後要把push的pop回來, pop的push回來

input:    輸入input跟target
output:   把所有可能輸出
*/

#include<iostream>
#include<vector>
#include<stack>
#include<string>
using namespace std;

static auto __ = []
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	return 0;
}();

vector<string> outputs;
string output, input, target;
stack<char> s;
int is1, is2;

void DFS()
{
	if (is1 == input.size() && is2 == target.size())
	{
		outputs.push_back(output);
		return;
	}

	if (is1 < input.size())
	{
		output.push_back('i');
		s.push(input[is1]);
		++is1;
		DFS();
		output.pop_back();
		s.pop();
		--is1;
	}

	if (!s.empty() && s.top() == target[is2])
	{
		output.push_back('o');
		char tmp = s.top();
		s.pop();
		++is2;
		DFS();
		output.pop_back();
		s.push(tmp);
		--is2;
	}
}

int main()
{
	while (cin >> input >> target)
	{
		output.clear();
		while (!s.empty()) s.pop();
		outputs.clear();
		is1 = is2 = 0;

		DFS();

		cout << "[\n";

		for (int i = 0; i < outputs.size(); ++i)
		{
			cout << outputs[i][0];
			for (int j = 1; j < outputs[i].size(); ++j) cout << " " << outputs[i][j];
			cout << "\n";
		}

		cout << "]\n";
	}

	return 0;
}







/*void Dfs()
{
	if (is1 == input.size() && is2 == target.size())
	{
		outputs.push_back(output);
		return;
	}

	if (is1 < input.size())
	{
		output.push_back('i');
		s.push(input[is1]);
		is1++;
		Dfs();
		output.pop_back();
		s.pop();
		is1--;
	}

	if (!s.empty() && s.top() == target[is2])
	{
		auto tmp = s.top();
		output.push_back('o');
		s.pop();
		is2++;
		Dfs();
		output.pop_back();
		s.push(tmp);
		is2--;
	}
}

int main()
{
	while (cin >> input >> target)
	{
		output.clear();
		outputs.clear();
		while (!s.empty()) s.pop();
		is1 = is2 = 0;

		cout << "[\n";

		Dfs();

		for (size_t i = 0; i < outputs.size(); ++i) {
			for (size_t j = 0; j < outputs[i].size(); j++)
			{
				cout << outputs[i][j];
				if (j != outputs[i].size() - 1)
					cout << " ";
			}
			cout << "\n";
		}
		cout << "]\n";
	}

	return 0;
}*/

/*
madam
adamm
bahama
bahama
long
short
eric
rice

[
i i i i o o o i o o
i i i i o o o o i o
i i o i o i o i o o
i i o i o i o o i o
]
[
i o i i i o o i i o o o
i o i i i o o o i o i o
i o i o i o i i i o o o
i o i o i o i o i o i o
]
[
]
[
i i o i o i o o
]
*/

/*void DFS(vector<string>& outputs, string s1, int is1, string s2, int is2, stack<char> s, string output)
{
	if (is1 == s2.size() && is2 == s2.size())
	{
		outputs.push_back(output);
		return;
	}
	if (is1 < s1.size())
	{
		output.push_back('i');
		s.push(s1[is1]);
		is1++;
		DFS(outputs, s1, is1, s2, is2, s, output);
		s.pop();
		is1--;
		output.pop_back();
	}

	if (!s.empty() && s.top() == s2[is2])
	{
		output.push_back('o');
		s.pop();
		is2++;
		DFS(outputs, s1, is1, s2, is2, s, output);
	}
}

int main()
{
	string input, target;

	while (cin >> input >> target)
	{
		vector<string> outputs;
		stack<char> s;
		string output;
		cout << "[\n";
		DFS(outputs, input, 0, target, 0, s, output);
		for (size_t i = 0; i < outputs.size(); ++i) {
			for (size_t j = 0; j < outputs[i].size(); j++)
			{
				cout << outputs[i][j];
				if (j != outputs[i].size() - 1)
					cout << " ";
			}
			cout << endl;
		}
		cout << "]\n";
	}

	return 0;
}*/