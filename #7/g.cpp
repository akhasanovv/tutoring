#include <bits/stdc++.h>

using namespace std;

void rec(string &s, int ones, int N, int K) {
    if (s.length() == N) {
        if (ones == K) {
            cout << s << '\n';
        }
    }
    if (ones + N - (int)s.length() < K) {
        return ;
    }
    s += '0';
    rec(s, ones, N, K);
    s.pop_back();
    if (ones < K) {
        s += '1';
        rec(s, ones + 1, N, K);
        s.pop_back();
    }
}

int main() {
    int N, K;
    cin >> N >> K;
    string s;
    rec(s, 0, N, K);
}