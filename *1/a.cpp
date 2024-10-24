#include <bits/stdc++.h>

const int mod = 1e9 + 7, N = 1e5 + 17;
int sum(int a, int b) {
    return (a + b) % mod;
}
int mul(int a, int b) {
    return (1ll * a * b) % mod;
}
int bpow(int a, int p) {
    int res = 1;
    while (p > 0) {
        if (p & 1) {
            res = mul(res, a);
        }
        p >>= 1;
        a = mul(a, a);
    }
    return res;
}
struct matrix {
    int mat[2][2];
    matrix() {
        memset(mat, 0, sizeof mat);
    }
    matrix(const std::vector<std::vector<int>> a) {
        memset(mat, 0, sizeof mat);
        for (int i = 0; i < a.size(); ++i) {
            for (int j = 0; j < a[0].size(); ++j) {
                mat[i][j] = a[i][j];
            }
        }
    }
    matrix operator*(const matrix& other) {
        matrix result;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 2; ++j) {
                for (int k = 0; k < 2; ++k) {
                    result.mat[i][k] = sum(result.mat[i][k], mul(mat[i][j], other.mat[j][k]));
                }
            }
        }
        return result;
    }
    matrix bpow(int power) {
        matrix result({{1, 0}, {0, 1}});
        matrix a({{mat[0][0], mat[0][1]}, {mat[1][0], mat[1][1]}});
        while (power > 0) {
            if (power & 1) {
                result = result * a;
            }
            power >>= 1;
            a = a * a;
        }
        return result;
    }
};
std::vector<int> g[N];
int depth[N];
void dfs(int v, int par) {
    depth[v] = (par != -1 ? depth[par] + 1 : 0);
    for (int u : g[v]) {
        if (u != par) {
            dfs(u, v);
        }
    }
}
int main() {
    int n, q;
    std::cin >> n >> q;
    for (int i = 0; i < n - 1; ++i) {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0, -1);
    while (q--) {
        int u, v, k;
        std::cin >> u >> v >> k;
        int vs = std::abs(depth[u] - depth[v]) + 1;
        matrix dp({{0}, {1}});
        matrix transition({{k - 2, k - 1}, {1, 0}});
        transition = transition.bpow(vs - 1);
        matrix totDp = transition * dp;
        int other = bpow(k - 1, n - vs);
        int cyc = mul(k, totDp.mat[0][0]);
        std::cout << mul(cyc, other) << '\n';
    }
}























