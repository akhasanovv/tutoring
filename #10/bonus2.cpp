#include <bits/stdc++.h>

using namespace std;
int main() {
    string s; cin >> s;
    int N = (int)s.length();
    int Q;
    cin >> Q;
    vector<int> a(N + 1), p(N + 1);
    vector<pair<int, int>> segments(Q);
    for (int i = 0; i < Q; ++i) {
        cin >> segments[i].first >> segments[i].second;
    }
    for (int i = 1; i <= N; ++i) {
        cin >> p[i];
    }
    int l = -1, r = N + 1;
    while (r - l > 1) {
        int mid = (l + r) / 2;
        string S = s;
        for (int i = 1; i <= mid; ++i) {
            int index = p[i];
            S[index - 1] = '*';
        }
        bool ok = true;
        for (int letter = 0; letter < 26; ++letter) {
            vector<int> prefixSum(N + 1, 0);
            for (int i = 0; i < N; ++i) {
                prefixSum[i + 1] = prefixSum[i];
                if (S[i] == (char)('a' + letter)) {
                    ++prefixSum[i + 1];
                }
            }
            for (auto [l, r] : segments) {
                if (prefixSum[r] - prefixSum[l - 1] > 1) {
                    ok = false;
                    break;
                }
            }
            if (!ok) break;
        }
        if (ok) {
            r = mid;
        } else {
            l = mid;
        }
    }
    cout << r << '\n';
}