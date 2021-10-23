/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3359
*/

#include <iostream>
#include <list>
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
	char a;
	int n, m, Case = 0, tmp;
	while (cin >> n >> m && (n || m))
	{
		list<int> dic;
		if (n > 1000) n = 1000;
		for (int i = 1; i <= n; ++i) dic.push_back(i);
		cout << "Case " << ++Case << ":\n";
		for (int i = 0; i < m; ++i)
		{
			cin >> a;

			if (a == 'N')
			{
				cout << dic.front() << "\n";
				dic.push_back(dic.front());
				dic.pop_front();
			}
			else if (a == 'E')
			{
				cin >> tmp;
				dic.remove(tmp);
				dic.push_front(tmp);
			}
		}
	}

	return 0;
}





/*int main()
{
	int N, S, Case = 0, tmp;
	char a;
	list<int> output;
	list<int>::iterator it;

	while (cin >> N >> S && (N || S))
	{
		if (N > 1000) N = 1000; //很重要,因為最多1000筆資料,一次只能服務一個人,如果N>1000的話會TLE
		output.clear();
		for (int i = 1; i <= N; ++i) output.push_back(i); 
		cout << "Case " << ++Case << ":\n";

		while (S--)
		{
			cin >> a;

			if (a == 'N')
			{
				cout << output.front() << "\n";
				output.push_back(output.front());
				output.pop_front();
			}
			else if (a == 'E')
			{
				cin >> tmp;
				output.remove(tmp);
				output.push_front(tmp);
			}
		}
	}

	return 0;
}*/

/*
3 6
N
N
E 1
N
N
N
10 2
N
N
0 0

Case 1:
1
2
1
3
2
Case 2:
1
2
*/