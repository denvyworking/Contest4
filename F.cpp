#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> keys(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> keys[i];
    }

    vector<int> visited(N + 1, 0);
    int components = 0;

    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            int current = i;
            while (!visited[current]) {
                visited[current] = i;
                current = keys[current];
            }
            
            if (visited[current] == i) {
                components++;
            }
        }
    }

    cout << components << endl;

    return 0;
}
