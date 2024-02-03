#include <bits/stdc++.h>
using namespace std;

void DFS(int i, vector<int> adj[], vector<bool> &visited, stack<int> &st)
{

    visited[i] = true;

    // first push all the children
    for (auto it : adj[i])
        if (!visited[it])
            DFS(it, adj, visited, st);
    // then push the parent  (this wil ensure that no child is placed before its parent )
    // and logic to add it here  is ,,,, since after this line i wont call anyone  , i.e sare child iske phele aa chuke hai  !!
    st.push(i);
}

vector<int> topoSort(int v, vector<int> adj[])
{

    // DFS + stack => toposort

    // req of toposort ---> DAG (Directed acyclic graph)
    // TC --> O(v+E)   , SC-->O(N)

    vector<bool> visited(v, false);
    stack<int> st;

    for (int i = 0; i < v; i++)
        if (!visited[i])
            DFS(i, adj, visited, st);

    vector<int> res;

    while (!st.empty())
    {
        res.push_back(st.top());
        st.pop();
    }

    return res;
}

int main()
{

    return 0;
}