/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&category=0&problem=1113

題目:     

input:   
output:
*/

#include<queue>
#include<stack>
#include<iostream>
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
	int T, n, s, q, time, cur;
	cin >> T;

	while (T--)
	{
		cin >> n >> s >> q;
		queue<int> Q[101];
		stack<int> truck;

		for (int i = 0; i < n; ++i)
		{
			int m, tmp;
			cin >> m;
			while (m--) cin >> tmp, Q[i].push(tmp - 1);
		}

		time = 0;
		cur = 0;

		while (1)
		{
			while (!truck.empty() && (truck.top() == cur || Q[cur].size() < q))
			{
				if (truck.top() != cur) Q[cur].push(truck.top());
				truck.pop();
				++time;
			}

			while (!Q[cur].empty() && truck.size() < s)
			{
				truck.push(Q[cur].front());
				Q[cur].pop();
				++time;
			}

			bool clear = truck.empty();
			for (int i = 0; i < n; ++i) if (!Q[i].empty())
			{
				clear = false;
				break;
			}
			if (clear) break;

			time += 2;
			cur = (cur + 1) % n;
		}

		cout << time << "\n";
	}

	return 0;
}








/*inline bool unload(stack<int> truck, queue<int> station[], int current, int q) 
{
	return (!truck.empty() && (truck.top() == current || station[current].size() < q));
}

int main()
{
	int N, n, s, q, ns, tmp;

	cin >> N;

	while (N--)
	{
		cin >> n >> s >> q;

		stack<int> truck;
		queue<int> station[101];

		for (int i = 0; i < n; ++i)
		{
			cin >> ns;
			for (int j = 0; j < ns; ++j)
			{
				cin >> tmp;
				station[i].push(tmp - 1);
			}
		}

		int cur = 0;
		int time = 0;

		while (1)
		{
			while (unload(truck, station, cur, q)) //卸貨
			{
				if (truck.top() != cur) station[cur].push(truck.top());
				truck.pop();
				++time;
			}

			while (truck.size() < s && !station[cur].empty()) //裝貨
			{
				truck.push(station[cur].front());
				station[cur].pop();
				++time;
			}

			bool clear = truck.empty();

			for (int i = 0; i < n; ++i) if (!station[i].empty()) clear = false;

			if (clear) break;

			cur = (cur + 1) % n;
			time += 2;
		}

		cout << time << "\n";
	}

	return 0;
}*/

/*
2
5 2 3
3 4 5 2
2 1 3
0
3 3 5 1
1 4
5 2 3
3 4 5 2
2 1 3
0
3 3 5 1
1 4

72
72
*/