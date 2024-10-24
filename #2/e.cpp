#include <bits/stdc++.h>

using namespace std;
constexpr int inf = 1e9;

int main() {
    int N, W;
    cin >> N >> W;
    vector<pair<int, int>> coordinates; // значение, индекс
    int L, R;
    cin >> L >> R;
    coordinates.push_back({L, -inf});
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        coordinates.push_back({x, i + 1});
    }
    if (W == 0) {
        cout << 0 << '\n';
        return 0;
    }
    coordinates.push_back({R, inf});
    sort(coordinates.begin(), coordinates.end());
    int pointer = -1;
    int ans_L = -1, ans_R = -1;
    for (int i = 1; i < (int)coordinates.size(); ++i) {
        while (coordinates[i].first - coordinates[pointer + 1].first >= W) {
            ++pointer;
        }
        if (pointer >= 0) {
            // нужно выкопать столбы с номерами [pointer + 1, pointer + 2, ..., i - 1]
            if (ans_L == -1 || i - pointer - 1 < ans_R - ans_L + 1) {
                ans_L = pointer + 1;
                ans_R = i - 1;
            }
        }
    }
    if (ans_L == -1) {
        cout << -1 << '\n'; // нет ответа
        return 0;
    }
    cout << ans_R - ans_L + 1 << '\n';
    for (int i = ans_L; i <= ans_R; ++i) {
        cout << coordinates[i].second << '\n';
    }
}