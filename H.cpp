#include <bits/stdc++.h>
using namespace std;

const int MAXN = 50000 + 5;
const int MAXM = 100000 + 5;

int parent[MAXN], sz[MAXN];

int find(int x) {
    return parent[x] == x ? x : parent[x] = find(parent[x]);
}

bool unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y) return false;
    if (sz[x] < sz[y]) swap(x, y);
    parent[y] = x;
    sz[x] += sz[y];
    return true;
}

struct Edge {
    int u, v;
    bool operator < (const Edge &other) const {
        return make_pair(u, v) < make_pair(other.u, other.v);
    }
};

map<Edge, bool> has_edge;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<Edge> edges(m);
    for (int i = 0; i < m; ++i) {
        cin >> edges[i].u >> edges[i].v;
        if (edges[i].u > edges[i].v)
            swap(edges[i].u, edges[i].v);
    }

    vector<string> ops(k);
    vector<int> u_ops(k), v_ops(k);
    set<pair<int, int>> cut_edges;

    for (int i = 0; i < k; ++i) {
        string type;
        cin >> type;
        int u, v;
        cin >> u >> v;
        ops[i] = type;
        u_ops[i] = u;
        v_ops[i] = v;
        if (type == "cut") {
            if (u > v) swap(u, v);
            cut_edges.insert({u, v});
        }
    }

    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }

    for (auto e : edges) {
        int u = e.u, v = e.v;
        if (cut_edges.count({u, v})) continue;
        unite(u, v);
    }

    vector<string> ans;

    for (int i = k - 1; i >= 0; --i) {
        int u = u_ops[i], v = v_ops[i];
        if (ops[i] == "ask") {
            if (find(u) == find(v))
                ans.push_back("YES");
            else
                ans.push_back("NO");
        } else if (ops[i] == "cut") {
            unite(u, v);
        }
    }

    reverse(ans.begin(), ans.end());

    for (auto s : ans)
        cout << s << "\n";

    return 0;
}
