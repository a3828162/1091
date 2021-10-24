/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=919

*/

#include<queue>
#include<iostream>
#include<vector>
using namespace std;

static auto __ = []()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	return 0;
}();

int n, a, sg, sb, tmp;

int main()
{
	cin >> n;

	while (n--)
	{
		priority_queue<int> g, b;
		cin >> a >> sg >> sb;
		for (int i = 0; i < sg; ++i) cin >> tmp, g.push(tmp);
		for (int i = 0; i < sb; ++i) cin >> tmp, b.push(tmp);

		while (!g.empty() && !b.empty())
		{
			vector<int> c;
			for (int i = 0; i < a; ++i)
			{
				if (g.empty() || b.empty()) break;

				c.push_back(g.top() - b.top());
				g.pop(), b.pop();
			}

			for (int i = 0; i < c.size(); ++i)
			{
				if (c[i] > 0) g.push(c[i]);
				else if (c[i] < 0) b.push(-c[i]);
			}
		}

		if (g.empty() && b.empty()) cout << "green and blue died\n";
		else
		{
			if (g.empty())
			{
				cout << "blue wins\n";
				while (!b.empty()) cout << b.top() << "\n", b.pop();
			}
			else
			{
				cout << "green wins\n";
				while (!g.empty()) cout << g.top() << "\n", g.pop();
			}
		}

		if (n) cout << "\n";
	}

	return 0;
}





/*int main()
{
	cin >> n;

	while (n--)
	{
		priority_queue<int> green, blue;
		cin >> a >> sg >> sb;

		for (int i = 0; i < sg; ++i) cin >> tmp, green.push(tmp);
		for (int i = 0; i < sb; ++i) cin >> tmp, blue.push(tmp);

		while (!green.empty() && !blue.empty())
		{
			vector<int> c;
			for (int i = 0; i < a; ++i)
			{
				if (green.empty() || blue.empty()) break;
				c.push_back(green.top() - blue.top());
				green.pop(), blue.pop();
			}

			for (int i = 0; i < c.size(); ++i)
			{
				if (c[i] > 0) green.push(c[i]);
				else if (c[i] < 0) blue.push(-c[i]);
			}
		}

		if (green.empty() && blue.empty()) cout << "green and blue died\n";
		else
		{
			if (!green.empty())
			{
				cout << "green wins\n";
				while (!green.empty()) cout << green.top() << "\n", green.pop();
			}
			else
			{
				cout << "blue wins\n";
				while (!blue.empty()) cout << blue.top() << "\n", blue.pop();
			}			
		}

		if (n) cout << "\n";
	}

	return 0;
}*/

/*
3
5 1 1
10
10
2 2 3
20
10
10
10
15
3 5 5
50
40
30
40
50
50
30
30
20
60

green and blue died

blue wins
5

green wins
10
10
*/

/*int main()
{
	int n;
	cin >> n;

	while (n--)
	{
		multiset<int> green, blue;
		int b, sg, sb, v;
		cin >> b >> sg >> sb;
		for (int i = 0; i < sg; ++i)
		{
			cin >> v;
			green.insert(v);
		}
		for (int i = 0; i < sb; ++i)
		{
			cin >> v;
			blue.insert(v);
		}

		while (!green.empty() && !blue.empty())
		{
			vector<int> s;
			for (int i = 0; i < b; ++i)
			{
				if (green.empty() || blue.empty()) break;
				s.push_back(*green.rbegin() - *blue.rbegin());
				green.erase(green.lower_bound(*green.rbegin()));
				blue.erase(blue.lower_bound(*blue.rbegin()));
			}
			
			for (size_t i = 0; i < s.size(); ++i)
			{
				if (s[i] > 0) green.insert(s[i]);
				else if (s[i] < 0) blue.insert(-s[i]);
			}
		}

		if (green.empty() && blue.empty()) cout << "green and blue died" << endl;
		else if (blue.empty())
		{
			cout << "green wins" << endl;
			while (!green.empty())
			{
				cout << *green.rbegin() << endl;
				green.erase(green.lower_bound(*green.rbegin()));
			}
		}
		else if(green.empty())
		{
			cout << "blue wins" << endl;
			while (!blue.empty())
			{
				cout << *blue.rbegin() << endl;
				blue.erase(blue.lower_bound(*blue.rbegin()));
			}
		}
		
		if (n) cout << endl;
	}

	return 0;
}*/