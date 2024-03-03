#include <bits/stdc++.h>
using namespace std;

vector<int> rank, parent, size;

int find(int i, vector<int> &parent)
{
    if (i == parent[i])
        return i;

    return parent[i] = find(parent[i], parent);
}

void Union_by_Rank(int x, int y, vector<int> &parent, vector<int> &rank)
{
    int x_parent = find(x, parent);
    int y_parent = find(y, parent);

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

void Union_by_Size(int x, int y, vector<int> &parent, vector<int> &size)
{
    int x_parent = find(x, parent);
    int y_parent = find(y, parent);

    if (x_parent == y_parent)
        return;

    if (size[x_parent] > size[y_parent])
    {
        parent[y_parent] = x_parent;
        size[x_parent] += size[y_parent];
    }
    else if (size[x_parent] <= size[y_parent])
    {
        parent[x_parent] = y_parent;
        size[y_parent] += size[x_parent];
    }
}

void disconnect(int i, vector<int> &parent)
{
    parent[i] = i;
}
// resize parent and rank by v
// intialize rank by 0 and parent[i]=i;

rank.resize(n, 0);
parent.resize(n, 0);
size.resize(n, 1);
iota(parent.begin(), parent.end(), 0);

int main()
{

    return 0;
}