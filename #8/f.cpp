#include <bits/stdc++.h>

using namespace std;

int main() {
    int S, N; cin >> S >> N;
    vector<vector<bool>> can(N + 1, vector<bool> (S + 1, false));
    vector<int> weights(N + 1);
    for (int i = 1; i <= N; ++i) {
        cin >> weights[i];
    }
    can[0][0] = true;
    for (int i = 1; i <= N; ++i) {
        for (int j = 0; j <= S; ++j) {
            if (can[i - 1][j] == true) {
                can[i][j] = true;
            }
            if (j - weights[i] >= 0 && can[i - 1][j - weights[i]] == true) {
                can[i][j] = true;
            }
        }
    }
    for (int i = S; i >= 0; --i) {
        if (can[N][i] == true) {
            cout << i << '\n';
            break;
        }
    }
}