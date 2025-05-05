#include <bits/stdc++.h>
// сам узнал об этом include только на этих тренировках в одной из статей
// смысла нет, но прикольно!
using namespace std;

const int MAXN = 10000 + 5;

int parent[MAXN], sz[MAXN];

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        sz[i] = 1;
    }
}

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> bridges(M);
    for (int i = 0; i < M; ++i) {
        int u, v;
        cin >> u >> v;
        bridges[i] = {u, v};
    }

    init(N);
    int components = N;
    int answer = -1;

    for (int i = 0; i < M; ++i) {
        int u = bridges[i].first;
        int v = bridges[i].second;
        if (unite(u, v)) {
            components--;
        }
        if (components == 1) {
            answer = i + 1;
            break;
        }
    }

    cout << answer << "\n";

    return 0;
}
