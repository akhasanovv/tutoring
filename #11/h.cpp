#include <bits/stdc++.h>

using namespace std;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n; cin >> n;
    if (n == 1) {
        cout << "yes\n";
        return 0;
    }
    string s; cin >> s;
    vector<int> cnt(10, 0);
    int nonZero = 0;
    for (char c : s) {
        if (c != '0') {
            ++nonZero;
        }
        ++cnt[c - '0'];
    }
    for (int i = 1; i < 10; ++i) {
        if (nonZero > 1 && cnt[i] > 1) {
            cout << "yes\n";
            return 0;
        }
    }
    cout << "no\n";
}