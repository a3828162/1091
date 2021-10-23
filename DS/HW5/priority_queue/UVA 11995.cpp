/*
題目連結: https://onlinejudge.org/index.php?option=onlinejudge&Itemid=8&page=show_problem&problem=3146
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
};

int main()
{

    bool isq, iss, ispq;
    int n;
    while (cin >> n)
    {
        queue<int> q;
        stack<int> s;
        priority_queue<int> pq;
        isq = iss = ispq = true;
        int a, b;
        for (int i = 0; i < n; ++i)
        {
            cin >> a >> b;
            if (a == 1)
            {
                q.push(b);
                s.push(b);
                pq.push(b);

            }
            else if (a == 2)
            {
                if (isq)
                {
                    if (q.front() == b) q.pop(); //要判斷是否為空 不然會超時
                    else isq = false;
                }
                if (iss)
                {
                    if (s.top() == b) s.pop();
                    else iss = false;
                }
                if (ispq)
                {
                    if (pq.top() == b) pq.pop();
                    else ispq = false;
                }
            }
        }

        if ((isq && iss) || (iss && ispq) || (isq && ispq))
        {
            cout << "not sure\n";
        }
        else
        {
            if (iss) cout << "stack\n";
            else if (isq) cout << "queue\n";
            else if (ispq) cout << "priority queue\n";
            else cout << "impossible\n";
        }
    }

    return 0;
}

/*int main()
{
    bool isq, iss, ispq;
    int n, cmd, num;

    while (cin >> n)
    {
        stack<int> s;
        queue<int> q;
        priority_queue<int> pq;

        isq = iss = ispq = true;

        while (n--)
        {
            cin >> cmd >> num;
            if (cmd == 1)
            {
                s.push(num), q.push(num), pq.push(num);
            }
            else if (cmd == 2)
            {
                if (iss)
                {
                    if (!s.empty() && s.top() == num) s.pop();
                    else iss = false;
                }
                if (isq)
                {
                    if (!q.empty() && q.front() == num) q.pop();
                    else isq = false;
                }
                if (ispq)
                {
                    if (!pq.empty() && pq.top() == num) pq.pop();
                    else ispq = false;
                }
            }
        }

        if ((iss && isq) || (isq && ispq) || (iss && ispq)) cout << "not sure\n";
        else if (iss) cout << "stack\n";
        else if (isq) cout << "queue\n";
        else if (ispq) cout << "priority queue\n";
        else cout << "impossible\n";
    }

    return 0;
}*/

/*
6
1 1
1 2
1 3
2 1
2 2
2 3
6
1 1
1 2
1 3
2 3
2 2
2 1
2
1 1
2 2
4
1 2
1 1
2 1
2 2
7
1 2
1 5
1 1
1 3
2 5
1 4
2 4

queue
not sure
impossible
stack
priority queue
*/