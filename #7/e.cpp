#include <bits/stdc++.h>

using namespace std;

void rec(vector<int> &a, int K, int N) {
    if ((int)a.size() == N) {
        for (auto element : a) {
            cout << element << ' ';
        }
        cout << '\n';
        return ;
    }
    for (int i = 1; i <= K; ++i) {
        a.push_back(i);
        rec(a, K, N);
        a.pop_back();
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> a;
    rec(a, K, N);
}