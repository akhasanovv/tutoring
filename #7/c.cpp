#include <bits/stdc++.h>

using namespace std;

void rec(string s, int K, int N) {
    if ((int)s.length() == N) {
        cout << s << '\n';
        return ;
    }
    for (int i = 0; i < K; ++i) {
        s += to_string(i);
        rec(s, K, N);
        s.pop_back();
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    rec("", K, N);
}