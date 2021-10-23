/*
題目連結: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=370

參考:    待補

題目:    有一本字典,
*/

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

static auto __ = []
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

vector<string> dic;
string word, before, after;

void BFS()
{
    queue<string> q;
    q.push(before);
    map<string, int> m;
    m[before] = 0;

    while (!q.empty() && !m.count(after))
    {
        string now = q.front();
        q.pop();
        for (auto& i : dic)
        {
            if (!m.count(i) && i.size() == now.size()) // ****** 要注意
            {
                int diff = 0;
                for (int j = 0; j < i.size(); ++j)
                {
                    if (i[j] != now[j]) ++diff;
                }

                if (diff == 1)
                {
                    q.push(i);
                    m[i] = m[now] + 1;
                }
            }
        }
    }

    cout << before << " " << after << " " << m[after] << "\n";
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        dic.clear();
        while (cin >> word && word != "*")
        {
            dic.push_back(word);
        }
        cin.ignore();
        while (getline(cin, word) && word != "")
        {
            stringstream ss(word);
            ss >> before >> after;
            BFS();
        }

        if (T) cout << "\n";
    }

    return 0;
}





/*void BFS()
{
    queue<string> q;
    q.push(before);
    map<string, int> t;
    t[before] = 0;

    while (!q.empty() && !t.count(after))
    {
        string now = q.front();
        q.pop();

        for (auto& next : dic)
        {
            if (now.length() == next.length() && !t.count(next))
            {
                int diff = 0;
                for (int i = 0; i < next.length(); ++i)
                {
                    if (now[i] != next[i]) ++diff;
                }

                if (diff == 1)
                {
                    q.push(next);
                    t[next] = t[now] + 1;
                }
            }
        }
    }

    cout << before << " " << after << " " << t[after] << "\n";
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        dic.clear();
        while (cin >> word && word != "*") dic.push_back(word);
        cin.ignore();
        while (getline(cin,word)&&word!="")
        {
            stringstream ss(word);
            ss >> before >> after;
            BFS();
        }

        if (T) cout << "\n";
    }

    return 0;
}*/

/*vector<string> dic;
string word, Before, After, Now;
int T, diff;

void BFS()
{
    queue<string> Q;
    map<string, int> trans;
    Q.push(Before);
    trans[Before] = 0;

    while (!Q.empty() && !trans.count(After))
    {
        Now = Q.front();
        Q.pop();

        for (auto& next : dic)
        {
            if (!trans.count(next) && next.length() == Now.length())
            {
                diff = 0;

                for (int i = 0; i < Now.size(); ++i) if (Now[i] != next[i]) ++diff;

                if (diff == 1)
                {
                    trans[next] = trans[Now] + 1;
                    Q.push(next);
                }
            }
        }
    }

    cout << Before << " " << After << " " << trans[After] << "\n";
}

int main()
{
    cin >> T;

    while (T--)
    {
        dic.clear();
        while (cin >> word && word != "*") dic.push_back(word);

        cin.ignore();
        
        while (getline(cin, word) && word != "")
        {
            stringstream ss(word);
            ss >> Before >> After;

            BFS();
        }

        if (T) cout << "\n";
    }

    return 0;
}*/

/*
1


dip
lip`
mad
map
maple
may
pad
pip
pod
pop
sap
sip
slice
slick
spice
stick
stock
*
spice stock
may pod

spice stock 4
may pod 3
*/