#include <bits/stdc++.h>

using namespace std;

struct fenwick {
    vector<long long> t;
    fenwick(int n) {
        t.assign(n, 0);
    }
    void add(int i, long long x) {
        while (i < (int)t.size()) {
            t[i] += x;
            i |= (i + 1);
        }
    }
    long long get(int r) {
        long long res = 0;
        while (r > -1) {
            res += t[r];
            r = (r & (r + 1)) - 1;
        }
        return res;
    }
    long long get(int l, int r) {
        return get(r) - get(l - 1);
    }
};

int main() {
    int k1, k2, n;
    scanf("%d%d%d", &k1, &k2, &n);
    vector<pair<int, int>> a(n);
    vector<long long> pre(n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &a[i].first, &a[i].second);
    }
    if (k1 == 0 && k2 == 0) {
        printf("0\n");
        return 0;
    }
    sort(a.rbegin(), a.rend());
    long long cur = 0;
    multiset<long long> ms;
    for (int i = 0; i < n; ++i) {
        cur += a[i].first;
        ms.insert(a[i].second - a[i].first);
        while (ms.size() > k1) {
            cur += *prev(ms.end());
            ms.erase(prev(ms.end()));
        }
        pre[i] = cur;
    }
    ms.clear();
    vector<int> b(n);
    for (int i = 0; i < n; ++i) {
        b[i] = a[i].second;
    }
    sort(b.begin(), b.end());
    b.erase(unique(b.begin(), b.end()), b.end());
    long long ans = pre[k1 + k2 - 1];
    fenwick f1(n), f2(n);
    for (int i = n - 1; i >= k1; --i) {
        int j = (lower_bound(b.begin(), b.end(), a[i].second) - b.begin());
        f1.add(j, +1);
        f2.add(j, a[i].second);
        if (k2 - i + k1 <= 0) continue;
        long long s = 0;
        {
            int l = 0, r = n;
            while (r - l > 1) {
                int mid = (l + r) / 2;
                if (f1.get(mid, n - 1) >= k2 - i + k1) {
                    l = mid;
                } else {
                    r = mid;
                }
            }
            s = f2.get(l, n - 1) - 1ll * (f1.get(l, n - 1) - (k2 - i + k1)) * b[l];
        }
        ans = max(ans, (i > 0 ? pre[i - 1] : 0) + s);
    }
    printf("%lld\n", ans);
}



