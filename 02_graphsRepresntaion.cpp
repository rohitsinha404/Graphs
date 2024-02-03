#include <bits/stdc++.h>
using namespace std;

int main()
{

    // creating a adj list

    // this is where we will store our graph
    // key-> edge , value -> vector of edges who are adjacent to key edge
    unordered_map<int, vector<int>> adj;

    // cosnider edges in a 2D vector
    vector<vector<int>> edges = {
        {1, 0}, // 1 --------edge-----> 0
        {2, 0},
        {2, 1},
        {3, 1},
    };

    // populating adj list via our edges
    for (auto it : edges)
    {
        int u = it[0], v = it[1];
        adj[u].push_back(v);
        // adj[v].push_back(u);
        // if graph is undirected push in both the vectors  , else only in the required one
    }
    // printing my adj list
    for (auto [key, list] : adj)
    {
        cout << key << "--> ";
        for (auto _ : list)
            cout << _ << " ";
        cout << endl;
    }

    return 0;
}