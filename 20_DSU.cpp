
vector<int> rank, parent;

int find(int i, vector<int> &parent)
{
    if (i == parent[i])
        return i;

    return parent[i] = find(parent[i], parent);
}

void Union(int x, int y, vector<int> &parent, vector<int> &rank)
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
// resize parent and rank by v
// intialize rank by 0 and parent[i]=i;
