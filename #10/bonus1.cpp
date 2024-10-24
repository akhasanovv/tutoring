#include <bits/stdc++.h>

using namespace std;
const long long inf = 1e18;
int main() {
    long long M, N;
    cin >> M >> N;
    vector<long long> T(N), Z(N), Y(N);
    for (int i = 0; i < N; ++i) {
        cin >> T[i] >> Z[i] >> Y[i];
    }
    long long l = -1, r = inf;
    while (r - l > 1) {
        long long mid = (l + r) / 2, tot = 0;
        for (int i = 0; i < N; ++i) {
            long long full = mid / (T[i] * Z[i] + Y[i]);
            tot += full * Z[i];
            tot = min(tot, inf);
            tot += min(mid - full * (T[i] * Z[i] + Y[i]), T[i] * Z[i]) / T[i];
            tot = min(tot, inf);
        }
        if (tot >= M) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << '\n';
    for (int i = 0; i < N; ++i) {
        long long full = r / (T[i] * Z[i] + Y[i]), tot = 0;
        tot += full * Z[i];
        tot += min(r - full * (T[i] * Z[i] + Y[i]), T[i] * Z[i]) / T[i];
        cout << min(tot, M) << ' ';
        M -= min(tot, M);
    }
    cout << '\n';
}