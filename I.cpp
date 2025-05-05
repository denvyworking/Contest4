#include <iostream>
#include <vector>

using namespace std;

struct Snowman {
    int parent;
    int top_mass;
    long long total;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<Snowman> snowmen;
    snowmen.reserve(n + 1);
    snowmen.push_back({-1, 0, 0});

    long long total_sum = 0;

    for (int i = 1; i <= n; ++i) {
        int t, m;
        cin >> t >> m;
        
        if (m != 0) {
            snowmen.push_back({
                t,
                m,
                snowmen[t].total + m
            });
        } else {
            int parent = snowmen[t].parent;
            snowmen.push_back({
                snowmen[parent].parent,
                snowmen[parent].top_mass,
                snowmen[parent].total
            });
        }
        
        total_sum += snowmen.back().total;
    }

    cout << total_sum << endl;
    return 0;
}
