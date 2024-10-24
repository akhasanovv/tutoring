#include <bits/stdc++.h>

using namespace std;
int main() {
    int n; cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    string s; cin >> s;
    for (int i = 0; i < n; ++i) {
        a[i + 1] = a[i], b[i + 1] = b[i];
        if (s[i] == 'a') ++a[i + 1];
        else ++b[i + 1];
    }
    // a[i] - a[j] = b[i] - b[j]
    // a[i] - b[i] = a[j] - b[j]
    map<int, int> cnt;
    long long ans = 0;
    for (int i = 0; i <= n; ++i) {
        ans += cnt[a[i] - b[i]];
        ++cnt[a[i] - b[i]];
    }
    cout << ans << '\n';
}