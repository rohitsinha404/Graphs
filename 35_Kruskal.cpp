#include <bits/stdc++.h>
using namespace std;

vector<int> parent;
vector<int> rank;

void Union(int x, int y)
{
    int x_parent = find(x);
    int y_parent = find(y);

    if (x_parent == y_parent)
        return;

    if (rank[x_parent] > rank[y_parent])
        parent[y_parent] = x_parent;

    else if (rank[x_parent] < rank[y_parent])
        parent[x_parent] = y_parent;

    else
    {
        parent[y_parent] = x_parent;
        rank[x_parent]++;
    }
}

int find(int i)
{
    if (i == parent[i])
        return i;

    return parent[i] = find(parent[i]);
}

int Kruskal(int n, vector<vector<int>> &edges)
{

    // edges should be something like this ----> {src , dest  , wt}

    int sum = 0;

    auto myCmp = [&](vector<int> &a, vector<int> &b)
    {
        return a[2] < b[2];
    }; // to sort  in decreasing order of wt

    sort(edges.begin(), edges.end(), myCmp);

    // add edge iff both the vertex of the edge are in diff comp
    for (auto &it : edges)
    {
        int src = it[0], dest = it[1], wt = it[2];
        if (find(src) != find(dest))
        {
            Union(src, dest);
            sum += wt;
        }
    }
    return sum;
}

int main()
{

    return 0;
}