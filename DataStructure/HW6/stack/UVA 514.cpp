/*
題目連結: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&category=0&problem=455
*/

#include <iostream>
#include <stack>
#include <queue>
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
	int n;

	while (cin >> n && n)
	{
		int tmp;
		while (cin >> tmp && tmp)
		{
			stack<int> s;
			queue<int> q;
			q.push(tmp);
			for (int i = 1; i < n; ++i) cin >> tmp, q.push(tmp);
			
			for (int i = 1; i <= n; ++i)
			{
				s.push(i);
				while (!s.empty() && s.top() == q.front()) q.pop(), s.pop();
			}

			if (s.empty()) cout << "Yes\n";
			else cout << "No\n";
		}
		cout << "\n";
	}

	return 0;
}





/*int main()
{
	int N, tmp;
	while (cin >> N && N)
	{
		while (cin >> tmp && tmp)
		{
			queue<int> a1;
			stack<int> train;

			a1.push(tmp);
			for (int i = 1; i < N; ++i) cin >> tmp, a1.push(tmp);

			for (int i = 1; i <= N; ++i)
			{
				train.push(i);
				while (!train.empty() && train.top() == a1.front()) a1.pop(), train.pop();
			}

			if (train.empty()) cout << "Yes\n";
			else cout << "No\n";
		}
		cout << "\n";
	}

	return 0;
}*/


/*int train[1005];

int main()
{
	int n;
	while (cin >> n && n)
	{
		while (cin >> train[0] && train[0])
		{
			for (size_t i = 1; i < n; i++) cin >> train[i];

			int i = 1;
			stack<int> stain;
			bool iss = false;
			for (size_t j = 0; j < n;)
			{
				if (i == train[j]) i++, j++;
				else if (!stain.empty() && stain.top() == train[j]) j++, stain.pop();
				else if (i <= n) stain.push(i++);
				else
				{
					iss = true;
					break;
				}
			}
			iss ? cout << "No" << endl : cout << "Yes" << endl;
		}
		cout << endl;
	}

	return 0;
}*/

/*
5
1 2 3 4 5
5 4 1 2 3
0
6
6 5 4 3 2 1
0
0

Yes
No

Yes
*/