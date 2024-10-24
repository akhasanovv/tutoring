#include <bits/stdc++.h>

using namespace std;
int main() {
    int N; cin >> N;
    vector<long long> p(N + 2, 0), s(N + 2, 0), a(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> a[i];
        p[i] = gcd(p[i - 1], a[i]);
    }
    for (int i = N; i >= 1; --i) {
        s[i] = gcd(s[i + 1], a[i]);
    }
    long long ans = 0;
    for (int i = 1; i <= N; ++i) ans = max(ans, gcd(p[i - 1], s[i + 1]));
    cout << ans << '\n';
}