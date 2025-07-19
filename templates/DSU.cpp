struct DSU
{
    vector<int> par, rnk, sz;
    int c;
    DSU(int n) : par(n + 1), rnk(n + 1, 0), sz(n + 1, 1), c(n)
    {
        for (int i = 1; i <= n; ++i)
            par[i] = i;
    }
    int find(int i) // find the parent of node i
    {
        return (par[i] == i ? i : (par[i] = find(par[i])));
    }
    bool same(int i, int j) // check if node i and node j belongs to same component (same parent)
    {
        return find(i) == find(j);
    }
    int get_size(int i) // size of the component where node i belongs
    {
        return sz[find(i)];
    }
    int count()
    {
        return c; // number of connected components
    }
    int merge(int i, int j)
    {
        if ((i = find(i)) == (j = find(j)))
            return -1;
        else
            --c;
        if (rnk[i] > rnk[j])
            swap(i, j);
        par[i] = j;
        sz[j] += sz[i];
        if (rnk[i] == rnk[j])
            rnk[j]++;
        return j;
    }
};
