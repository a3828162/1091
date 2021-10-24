/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3503

題目:     找有幾個stack
*/

#include<iostream>
#include<stack>
#include<string>
#include<vector>
using namespace std;

static auto __ = []
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	return 0;
}();

int main()
{
	int Case = 0;
	string input;

	while (cin >> input && input != "end")
	{
		vector<stack<char>> ans;
		for (int i = 0; i < input.size(); ++i)
		{
			bool b = true;
			for (int j = 0; j < ans.size(); ++j)
			{
				if (input[i] <= ans[j].top())
				{
					ans[j].push(input[i]);
					b = false;
					break;
				}
			}

			if (b)
			{
				stack<char> tmp;
				tmp.push(input[i]);
				ans.push_back(tmp);
			}
		}

		cout << "Case " << ++Case << ": " << ans.size() << "\n";
	}

	return 0;
}






/*int main()
{
	string in;
	int Case = 0;

	while (cin >> in && in != "end")
	{
		vector<stack<char>> lis;

		for (int i = 0; i < in.size(); ++i)
		{
			bool a = true;

			for (int j = 0; j < lis.size(); ++j)
			{
				if (lis[j].top() >= in[i])
				{
					lis[j].push(in[i]);
					a = false;
					break;
				}
			}

			if (a)
			{
				stack<char> tmp;
				tmp.push(in[i]);
				lis.push_back(tmp);
			}
		}

		cout << "Case " << ++Case << ": " << lis.size() << "\n";
	}


	return 0;
}*/

/*
A
CBACBACBACBACBA
CCCCBBBBAAAA
ACMICPC
end

Case 1: 1
Case 2: 3
Case 3: 1
Case 4: 4
*/