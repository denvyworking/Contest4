#include <iostream>
#include <vector>
#include <queue>

// Я использовал очередь. Я молодец!

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    if (n == 2) {
        cout << "0 0\n";
        return 0;
    }

    vector<int> left(n), right(n);
    for (int i = 0; i < n; ++i) {
        left[i] = (i - 1 + n) % n;
        right[i] = (i + 1) % n;
    }

    vector<int> res(n, 0);
    queue<int> q;

    int remaining = n;

    for (int i = 0; i < n; ++i) {
        int l = left[i];
        int r = right[i];
        if (a[i] < a[l] && a[i] < a[r]) {
            res[i] = 1;
            q.push(i);
        }
    }

    remaining -= q.size();

    int round = 1;
    while (!q.empty() && remaining > 2) {
        round++;
        queue<int> next_q;
        int current_round_removed = 0;

        while (!q.empty()) {
            int u = q.front();
            q.pop();
            int l = left[u];
            int r = right[u];
            if (res[l] == 0) {
                if (a[l] < a[left[l]] && a[l] < a[r]) {
                    res[l] = round;
                    next_q.push(l);
                    current_round_removed++;
                }
            }
            if (res[r] == 0) {
                if (a[r] < a[l] && a[r] < a[right[r]]) {
                    res[r] = round;
                    next_q.push(r);
                    current_round_removed++;
                }
            }
            left[r] = l;
            right[l] = r;
        }

        remaining -= current_round_removed;
        if (remaining <= 2) break;

        q = next_q;
    }

    for (int i = 0; i < n; ++i) {
        cout << res[i] << " ";
    }
    cout << "\n";

    return 0;
}
