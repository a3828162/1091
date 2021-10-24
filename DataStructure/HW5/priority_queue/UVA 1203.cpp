/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3644
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

struct Register
{
	int ID;
	int period;
	int time;
	bool operator<(const Register& s)const {
		return (time > s.time || (time == s.time && ID > s.ID));
	}
};

int main()
{
	priority_queue <Register> pq;
	string input;
	int a, b;
	while (cin >> input && input != "#")
	{
		cin >> a >> b;
		pq.push({ a,b,b });
	}
	int m;
	cin >> m;

	while (m--)
	{
		Register tmp = pq.top();
		pq.pop();
		cout << tmp.ID << "\n";
		pq.push({ tmp.ID,tmp.period,tmp.time + tmp.period });
	}

	return 0;
}





/*int main()
{
	priority_queue<Register> output;
	string s;
	int d, t, k;

	while (cin >> s && s != "#")
	{
		cin >> d >> t;
		output.push(Register{ d,t,t });
	}

	cin >> k;

	while (k--)
	{
		Register tmp = output.top();
		cout << tmp.ID << "\n";
		output.pop();
		output.push(Register{ tmp.ID,tmp.period,tmp.time + tmp.period });
	}

	return 0;
}*/

/*int main()
{
	priority_queue<Register> output;
	char s[10];
	int d, t, k;
	while (cin >> s && s[0] != '#')
	{
		cin >> d >> t;
		output.push(Register{ d,t,t });
	}
	cin >> k;
	while (k--)
	{
		Register tmp = output.top();
		output.pop();
		cout << tmp.ID << endl;
		output.push(Register{ tmp.ID,tmp.period,tmp.time + tmp.period });
	}

	return 0;
}*/

/*
Register 2004 200
Register 2005 300
#
5

2004
2005
2004
2004
2005
*/