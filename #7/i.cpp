#include <bits/stdc++.h>

using namespace std;

void rec(vector<int> &els, int sum, int N) {
    if (sum == N) {
        for (auto x : els) {
            cout << x << ' ';
        }
        cout << '\n';
        return ;
    }
    for (int i = 1; i <= N - sum; ++i) {
        if (!els.empty() && els.back() < i) continue;
        els.push_back(i);
        rec(els, sum + i, N);
        els.pop_back();
    }
}

int main() {
    int N; cin >> N;
    vector<int> els;
    rec(els, 0, N);
}