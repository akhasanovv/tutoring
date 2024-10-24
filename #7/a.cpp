#include <bits/stdc++.h>

using namespace std;

void rec(string s, int N) {
    if ((int)s.length() == N) {
        cout << s << '\n';
        return ;
    }
    s += '0';
    rec(s, N);
    s.pop_back();
    s += '1';
    rec(s, N);
    s.pop_back();
}

int main() {
    int N; cin >> N;
    rec("", N);
}