#include <bits/stdc++.h>
using namespace std;
void solve();
int main()
{

    //    https://cses.fi/problemset/task/1667

    solve();
    return 0;
}

unordered_map<int, int> parent; // {child ---> parent}

bool bfs(unordered_map<int, vector<int>> &adj, int n)
{
    queue<int> q;
    q.push(1);

    vector<int> vis(n + 1, false);

    parent[1] = 1;
    while (q.size())
    {
        auto curr = q.front();
        q.pop();

        for (auto it : adj[curr])

            if (!vis[it])
            {
                q.push(it);
                vis[it] = true;
                parent[it] = curr;

                if (it == n)
                    return true;
            }
    }

    return false;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    unordered_map<int, vector<int>> adj;

    int cpyM = m;

    while (cpyM--)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool flag = bfs(adj, n); 
    

    if (!flag)
        cout << "IMPOSSIBLE" << endl;

    else
    {

        vector<int> path;

        int itr = n;

        while (itr != 1)
        {
            path.push_back(itr);
            itr = parent[itr];
        }

        path.push_back(1);

        int sz = path.size();

        cout << sz << endl;

        for (int i = sz - 1; i >= 0; i--)
        {
            cout << path[i] << " ";
        }

        cout << endl;
    }
}