#include <bits/stdc++.h>
using namespace std;
void solve();

int main()
{
    /*
      https://cses.fi/problemset/task/1666

      3 approach count no of components in the graph !

      way 1 DFS --> create graph and count comp
      way 2 BFS --> create graph and count comp
      way 3 DSU --> just count comp using DSU  ( fastest !! )

      */
    solve();
    return 0;
}

void dfs(int u, unordered_map<int, vector<int>> &adj, vector<bool> &visited)
{
    visited[u] = 1;

    for (auto it : adj[u])
    {
        if (!visited[it])
            dfs(it, adj, visited);
    }
}

void bfs(int u, unordered_map<int, vector<int>> &adj, vector<bool> &visited)
{
    queue<int> q;
    q.push(u);
    visited[u] = true;

    while (!q.empty())
    {
        int curr = q.front();
        q.pop();

        for (auto it : adj[curr])
        {
            if (!visited[it])
            {
                q.push(it);
                visited[it] = 1;
            }
        }
    }
}

int find(int i, vector<int> &parent)
{
    if (i == parent[i])
        return i;

    return parent[i] = find(parent[i], parent);
}

void Union(int x, int y, vector<int> &parent, vector<int> &rank)
{

    int parx = find(x, parent);
    int pary = find(y, parent);

    if (parx == pary)
        return;

    if (rank[parx] < rank[pary])
        parent[parx] = pary;

    else if (rank[parx] > rank[pary])
        parent[pary] = parx;
    else
    {
        parent[pary] = parx;
        rank[parx]++;
    }
}

int compL[100001];

void solve()
{
    // using DSU
    int cities, roads;
    cin >> cities >> roads;

    vector<int> parent(cities + 1);
    vector<int> rank(cities + 1, 0);
    iota(parent.begin(), parent.end(), 0);

    while (roads--)
    {
        int u, v;
        cin >> u >> v;

        if (find(u, parent) != find(v, parent))
            Union(u, v, parent, rank);
    }

    unordered_set<int> comp;

    for (int i = 1; i <= cities; i++)
    {

        comp.insert(find(i, parent));
    }

    int itr = 0;
    for (auto it : comp)
        compL[itr++] = it;

    if (comp.size() == 1)
        cout << 0 << endl;
    else
    {
        cout << comp.size() - 1 << endl;
        for (int i = 0; i < comp.size() - 1; i++)
            cout << compL[i] << " " << compL[i + 1] << endl;
    }
}

/* void solve()
{


    int cities, roads;
    cin >> cities >> roads;

    unordered_map<int, vector<int>> adj; // u-- > { v }

    while (roads--) // creating graph !!
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int componetns = 0;

    vector<bool> visited(cities + 1, false);
    vector<int> compL;

    for (int i = 1; i <= cities; i++)
    {
        if (!visited[i])
        {
            // dfs(i, adj, visited);
            bfs(i, adj, visited);
            compL.push_back(i);
            componetns++;
        }
    }

    if (componetns == 1)
        cout << 0 << endl;

    else
    {
        cout << componetns - 1 << endl;
        for (int i = 0; i < compL.size() - 1; i++)
            cout << compL[i] << " " << compL[i + 1] << endl;
    }
}


*/