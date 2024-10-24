#include <bits/stdc++.h>

using namespace std;

void rec(vector<int> &a, int N, int K) {
    if ((int)a.size() == K) {
        for (auto el : a) {
            cout << el << ' ';
        }
        cout << '\n';
        return ;
    }
    if (!a.empty() && K - (int)a.size() > a.back() - 1) {
        return ;
    }
    int upper = N;
    if (!a.empty()) {
        upper = a.back() - 1;
    }
    for (int i = 1; i <= upper; ++i) {
        a.push_back(i);
        rec(a, N, K);
        a.pop_back();
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a;
    rec(a, N, K);
}