/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1895
*/

#include<iostream>
#include<queue>
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
	int n, left, right, ans;
	while (cin >> n && n)
	{
		priority_queue<int,vector<int>,greater<int>> pq;
		ans = 0;
		int tmp;
		for (int i = 0; i < n; ++i)
		{
			cin >> tmp;
			pq.push(tmp);
		}

		while (pq.size() > 1)
		{
			left = pq.top();
			pq.pop();
			right = pq.top();
			pq.pop();
			pq.push(left + right);
			ans += left + right;
		}

		cout << ans << "\n";
	}

	return 0;
}



/*int main()
{
	int N, in, left, right, ans;

	while (cin >> N && N)
	{
		priority_queue<int, vector<int>, greater<int>> output;
		ans = 0;

		while (N--)
		{
			cin >> in;
			output.push(in);
		}

		while (output.size() > 1)
		{
			left = output.top();
			output.pop();
			right = output.top();
			output.pop();
			output.push(left + right);
			ans += left + right;
		}

		cout << ans << "\n";
	}

	return 0;
}*/

/*
3
1 2 3
4
1 2 3 4
0

9
19
*/