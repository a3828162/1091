/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=2261
*/

#include <algorithm>
#include <string>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;

static auto __ = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

string input, a[5];
int T;

int main()
{
	while (cin >> T && T)
	{
		cin.ignore();
		map<string, int> dic;
		pair<int, int> ans;
		for (int i = 0; i < T; ++i)
		{
			getline(cin, input);
			stringstream ss(input);
			ss >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
			sort(a, a + 5);
			string output;
			for (int i = 0; i < 5; ++i) output += a[i];
			ans.first = max(ans.first, ++dic[output]);
		}

		for (auto& [l, r] : dic) if (ans.first == r) ans.second += r;

		cout << ans.second << "\n";
	}

	return 0;
}


/*int main()
{
	while (cin >> T && T)
	{
		cin.ignore();
		map<string, int> dic;
		pair<int, int> ans;
		for (int i = 0; i < T; ++i)
		{
			getline(cin, input);
			stringstream ss(input);
			ss >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];

			sort(a, a + 5);
			string output;

			for (auto& j : a) output += j;
			ans.first = max(ans.first, ++dic[output]);
		}

		for (auto& [c, n] : dic) if (n == ans.first) ans.second += n;

		cout << ans.second << "\n";
	}

	return 0;
}*/

/*
3
100 101 102 103 488
100 200 300 101 102
103 102 101 488 100
3
200 202 204 206 208
123 234 345 456 321
100 200 300 400 444
0

2
3
*/
/*typedef long long LL;

using namespace std;

int courses[5];

int main()
{
	int n;
	while (cin >> n && n) {
		map<LL, int> Map;
		int maxv = 1, count = 0;
		for (int t = 0; t < n; ++t) {
			for (int i = 0; i < 5; ++i)
				cin >> courses[i];
			sort(courses, courses + 5);
			LL value = 0LL;
			for (int i = 0; i < 5; ++i) {
				value *= 1000;
				value += courses[i];
				
			}
			maxv = max(maxv, Map[value] += 1);
		}
		for (map<LL, int>::iterator it = Map.begin(); it != Map.end(); ++it)
			if (it->second == maxv)
				count += maxv;

		cout << count << endl;
	}
	return 0;
}*/
