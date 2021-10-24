/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2077
*/

#include<set>
#include<iostream>
using namespace std;

static auto __ = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

multiset<int> box;
int T, n, m;
long long output;

int main()
{
	while (cin >> T && T)
	{
		output = 0;
		box.clear();
		while (T--)
		{
			cin >> n;
			for (int i = 0; i < n; ++i)
			{
				cin >> m;
				box.insert(m);
			}
			output += *(--box.end()) - *(box.begin());
			box.erase(--box.end()), box.erase(box.begin());
		}

		cout << output << "\n";
	}
	

	return 0;
}




/*int main()
{
	while (cin >> T && T)
	{
		box.clear();
		output = 0;
		while (T--)
		{
			cin >> n;
			for (int i = 0; i < n; ++i)
			{
				cin >> m;
				box.insert(m);
			}
			output += *(--box.end()) - *(box.begin());
			box.erase(--box.end()), box.erase(box.begin());
			//output += *box.rbegin() - *box.begin();
			//box.erase(box.lower_bound(*box.begin())), box.erase(box.lower_bound(*box.rbegin()));
		}
		cout << output << "\n";
	}

	return 0;
}*/

/*
5
3 1 2 3
2 1 1
4 10 5 5 1
0
1 2
2
2 1 2
2 1 2
0

19
2
*/

/*int main() 
{
	int n;

	while (cin >> n && n)
	{
		long long output = 0;
		multiset<int> box;
		while (n--)
		{
			int s = 0;
			cin >> s;
			for (int i = 0; i < s; ++i)
			{
				int d;
				cin >> d;
				box.insert(d);
			}
			output += *box.rbegin() - *box.begin();
			box.erase(box.lower_bound(*box.begin())), box.erase(box.lower_bound(*box.rbegin()));

		}

		cout << output << endl;
	}

	return 0;
}*/