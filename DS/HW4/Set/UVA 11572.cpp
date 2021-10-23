/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2619

*/

#include <set>
#include <vector>
#include <iostream>

using namespace std;

static auto __ = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

vector<int> a;
set<int> snow;
int n, s;

int main()
{
	cin >> n;

	while (n--)
	{
		cin >> s;
		a.assign(s, 0);
		snow.clear();

		for (int i = 0; i < s; ++i) cin >> a[i];
		int now = 0;
		pair<int, int> ans;

		for (int i = 0; i < s; ++i)
		{
			while (snow.count(a[i]))
			{
				snow.erase(a[now++]);
				--ans.first;
			}

			snow.insert(a[i]);
			++ans.first;

			if (ans.first > ans.second) ans.second = ans.first;
		}

		cout << ans.second << "\n";
	}

	return 0;
}




/*int main()
{
	cin >> n;

	while (n--)
	{
		cin >> s;
		snow.clear();
		a.assign(s, 0);
		for (int i = 0; i < s; ++i) cin >> a[i];

		int now = 0;
		pair<int, int> ans;

		for (int i = 0; i < s; ++i)
		{
			while (snow.count(a[i]))
			{
				snow.erase(a[now++]);
				ans.first--;
			}

			snow.insert(a[i]);
			++ans.first;
			if (ans.first > ans.second) ans.second = ans.first;
		}

		cout << ans.second << "\n";
	}

	return 0;
}*/

/*
1
5
1
2
3
2
1

3
*/