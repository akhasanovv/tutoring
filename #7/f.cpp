#include <bits/stdc++.h>

using namespace std;
vector<long long> A, ans;

void rec(vector<long long> &take, long long sum, int i, int M, int N) {
    if (i == M) {
        if (sum == N) {
            if (ans.empty() || take.size() < ans.size()) {
                ans = take;
            }
        }
        return ;
    }
    for (int cnt = 0; cnt <= 2; ++cnt) {
        for (int j = 0; j < cnt; ++j) {
            take.push_back(A[i]);
            sum += A[i];
        }
        rec(take, sum, i + 1, M, N);
        for (int j = 0; j < cnt; ++j) {
            take.pop_back();
            sum -= A[i];
        }
    }
}

int main() {
    long long N, M;
    cin >> N >> M;
    A = vector<long long> (M);
    long long sum = 0;
    for (int i = 0; i < M; ++i) {
        cin >> A[i];
        sum += A[i];
    }
    if (2 * sum < N) {
        cout << -1 << '\n';
        return 0;
    }
    vector<long long> take;
    rec(take, 0, 0, M, N);
    if (!ans.empty()) {
        cout << ans.size() << '\n';
        for (auto elem : ans) {
            cout << elem << ' ';
        }
        cout << '\n';
        return 0;
    }
    cout << 0 << '\n';
}