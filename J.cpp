#include <iostream>
#include <random>
#include <vector>

// Коряво, много, нооо
// потерпите пожалуйста, это же С++ )

using namespace std;

mt19937 rng(42);

struct Node {
    int value;
    int priority;
    int size;
    Node *left, *right;
    Node(int val) : value(val), priority(rng()), size(1), left(nullptr), right(nullptr) {}
};

int get_size(Node *node) {
    return node ? node->size : 0;
}

void update_size(Node *node) {
    if (node) node->size = get_size(node->left) + get_size(node->right) + 1;
}

void split(Node *node, int key, Node *&left, Node *&right) {
    if (!node) {
        left = right = nullptr;
        return;
    }
    int current_key = get_size(node->left);
    if (current_key < key) {
        split(node->right, key - current_key - 1, node->right, right);
        left = node;
    } else {
        split(node->left, key, left, node->left);
        right = node;
    }
    update_size(node);
}

Node *merge(Node *left, Node *right) {
    if (!left) return right;
    if (!right) return left;
    if (left->priority > right->priority) {
        left->right = merge(left->right, right);
        update_size(left);
        return left;
    } else {
        right->left = merge(left, right->left);
        update_size(right);
        return right;
    }
}

void insert(Node *&root, int pos, int value) {
    Node *left, *right;
    split(root, pos, left, right);
    root = merge(merge(left, new Node(value)), right);
}

void erase(Node *&root, int pos) {
    Node *left, *mid, *right;
    split(root, pos, left, right);
    split(right, 1, mid, right);
    root = merge(left, right);
}

int get_value(Node *root, int pos) {
    Node *left, *mid, *right;
    split(root, pos, left, right);
    split(right, 1, mid, right);
    int value = mid->value;
    root = merge(merge(left, mid), right);
    return value;
}

pair<int, int> split_segment(int len) {
    if (len % 2 == 0)
        return {len / 2, len / 2};
    else
        return {(len - 1) / 2, (len + 1) / 2};
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    Node *root = nullptr;
    long long sum_squares = 0;

    for (int i = 0; i < n; ++i) {
        int a;
        cin >> a;
        insert(root, i, a);
        sum_squares += 1LL * a * a;
    }

    cout << sum_squares << "\n";

    int k;
    cin >> k;

    for (int i = 0; i < k; ++i) {
        int event_type, v;
        cin >> event_type >> v;
        --v;

        if (event_type == 1) { // Банкротство
            int current = get_value(root, v);
            sum_squares -= 1LL * current * current;

            bool has_prev = (v > 0);
            bool has_next = (v < get_size(root) - 1);

            if (!has_prev || !has_next) {
                if (has_prev) {
                    int prev_val = get_value(root, v - 1);
                    sum_squares -= 1LL * prev_val * prev_val;
                    erase(root, v - 1);
                    erase(root, v - 1);
                    insert(root, v - 1, prev_val + current);
                    sum_squares += 1LL * (prev_val + current) * (prev_val + current);
                } else {
                    int next_val = get_value(root, v + 1);
                    sum_squares -= 1LL * next_val * next_val;
                    erase(root, v);
                    erase(root, v);
                    insert(root, v, next_val + current);
                    sum_squares += 1LL * (next_val + current) * (next_val + current);
                }
            } else {
                int prev_val = get_value(root, v - 1);
                int next_val = get_value(root, v + 1);
                sum_squares -= 1LL * prev_val * prev_val;
                sum_squares -= 1LL * next_val * next_val;

                auto [left, right] = split_segment(current);
                erase(root, v - 1);
                erase(root, v - 1);
                erase(root, v - 1);
                insert(root, v - 1, prev_val + left);
                insert(root, v, next_val + right);

                sum_squares += 1LL * (prev_val + left) * (prev_val + left);
                sum_squares += 1LL * (next_val + right) * (next_val + right);
            }
        } else if (event_type == 2) { // Разделение
            int len = get_value(root, v);
            auto [left, right] = split_segment(len);
            sum_squares += 1LL * left * left + 1LL * right * right - 1LL * len * len;
            erase(root, v);
            insert(root, v, right);
            insert(root, v, left);
        }

        cout << sum_squares << "\n";
    }

    return 0;
}
