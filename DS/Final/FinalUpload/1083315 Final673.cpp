#include<string>
#include<stack>
#include<iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	cin.ignore();
	while (T--)
	{
		stack<char> s;
		string str;
		getline(cin, str);
		if (str == "") cout << "Yes\n";
		else
		{
			for (int i = 0; i < str.size(); ++i)
			{
				if (!s.empty())
				{
					if (str[i] == ' ') continue;
					if (s.top() == '(' && str[i] == ')')
					{
						s.pop();
						continue;
					}
					else if (s.top() == '[' && str[i] == ']')
					{
						s.pop();
						continue;
					}
					s.push(str[i]);
				}
				else
				{
					s.push(str[i]);
				}
			}
			if (s.empty()) cout << "Yes\n";
			else cout << "No\n";
		}
	}

	return 0;
}

/*
3
([])
(([()])))
([()[]()])()

Yes
No
Yes
*/