/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1842
*/

#include<iostream>
#include<queue>
#include<string>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

static auto __ = []
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	return 0;
}();

int T, n, t, m, tmp;
string s;

int main()
{
	cin >> T;
	while (T--)
	{
		cin >> n >> t >> m;
		queue<pair<int, int>> q[2];
		vector<int> ans(m);
		for (int i = 0; i < m; ++i)
		{
			cin >> tmp >> s;
			s == "left" ? q[0].push({ i,tmp }) : q[1].push({ i,tmp });
		}

		int time = 0, cur = 0;

		while (!q[0].empty() || !q[1].empty())
		{
			int closet = INT_MAX;
			if (!q[0].empty()) closet = q[0].front().second;
			if (!q[1].empty()) closet = min(closet, q[1].front().second);

			time = max(time, closet);

			int boats = 0;
			while (!q[cur].empty() && boats < n && q[cur].front().second <= time)
			{
				ans[q[cur].front().first] = time + t;
				q[cur].pop();
				++boats;
			}

			time += t;
			cur = (cur + 1) % 2;
		}

		for (auto& i : ans) cout << i << "\n";
		if (T) cout << "\n";
	}

	return 0;
}



/*int main()
{
	cin >> T;

	while (T--)
	{
		queue < pair<int, int> > R[2];
		cin >> n >> t >> m;
		for (int i = 0; i < m; ++i)
		{
			cin >> tmp >> s;
			s == "left" ? R[0].push(pair<int, int>(i, tmp)) : R[1].push(pair<int, int>(i, tmp));
		}

		vector<int> ans(m);

		int current = 0, time = 0;

		while (!R[0].empty() || !R[1].empty())
		{
			int close = INT_MAX;

			if (!R[0].empty()) close = R[0].front().second;
			if (!R[1].empty()) close = min(close, R[1].front().second);

			time = max(time, close);

			int boatsize = 0;

			while (!R[current].empty() && boatsize < n && R[current].front().second <= time)
			{
				ans[R[current].front().first] = time + t;
				R[current].pop();
				++boatsize;
			}

			current = (current + 1) % 2;
			time += t;
		}

		for (auto& i : ans) cout << i << "\n";
		if (T) cout << "\n";
	}

	return 0;
}*/

/*
2
2 10 10
0 left
10 left
20 left
30 left
40 left
50 left
60 left
70 left
80 left
90 left
2 10 3
10 right
25 left
40 left

10
30
30
50
50
70
70
90
90
110

30
40
60
*/