/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=1975
*/

#include<queue>
#include<iostream>
#include<string>
using namespace std;

static auto __ = []
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	return 0;
}();

int N, c, n, weight, tmp;
string s;

int main()
{
	cin >> N;
	while (N--)
	{
		cin >> c >> n;
		queue<int> q[2];
		for (int i = 0; i < n; ++i)
		{
			cin >> tmp >> s;
			s == "left" ? q[0].push(tmp) : q[1].push(tmp);
		}

		int time = 0, cur = 0;

		while (!q[0].empty() || !q[1].empty())
		{
			weight = c * 100;

			while (!q[cur].empty() && q[cur].front() <= weight)
			{
				weight -= q[cur].front();
				q[cur].pop();
			}

			++time;
			cur = (cur + 1) % 2;
		}

		cout << time << "\n";
	}

	return 0;
}





/*int main()
{
	cin >> N;

	while (N--)
	{
		cin >> c >> n;
		queue<int> R[2];

		for (int i = 0; i < n; ++i)
		{
			cin >> tmp >> s;
			s == "left" ? R[0].push(tmp) : R[1].push(tmp);
		}

		int count = 0, current = 0;

		while (!R[0].empty() || !R[1].empty())
		{
			weight = c * 100;

			while (!R[current].empty() && R[current].front() <= weight) weight -= R[current].front(), R[current].pop();
			
			count++;
			current = (current + 1) % 2;
		}

		cout << count << "\n";
	}

	return 0;
}*/

/*
4
20 4
380 left
720 left
1340 right
1040 left
15 4
380 left
720 left
1340 right
1040 left
15 4
380 left
720 left
1340 left
1040 left
15 4
380 right
720 right
1340 right
1040 right

3
3
5
6
*/