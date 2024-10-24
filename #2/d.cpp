#include <bits/stdc++.h>

using namespace std;
constexpr int inf = 1e9;

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> cnt(K, 0), a(N);
    // cnt[i] -> количество деревьев вида i в рассматриваемом отрезке
    // необходимое условие: минимум по cnt[i] должен быть больше нуля
    // т.е. в рассматриваемом отрезке должно быть хотя бы по одному дереву всех видов
    multiset<int> ms;
    for (int i = 0; i < K; ++i) {
        ms.insert(cnt[i]); // cnt[i] = 0
        // добавляем текущее количество рассматриваемых деревьев вида i
    }
    int pointer = 0;
    int ans_L = -inf, ans_R = inf;
    for (int i = 0; i < N; ++i) {
        cin >> a[i]; // 1 <= a[i] <= K
        --a[i]; // 0 <= a[i] <= K - 1 -> для удобства
        ms.erase(ms.find(cnt[a[i]])); // обновляем данные о текущем дереве
        ++cnt[a[i]];
        ms.insert(cnt[a[i]]);
        while (*ms.begin() > 0) {
            if (ans_R - ans_L + 1 > i - pointer + 1) {
                ans_L = pointer;
                ans_R = i;
            }
            ms.erase(ms.find(cnt[a[pointer]])); // обновляем данные о крайнем левом дереве
            --cnt[a[pointer]];
            ms.insert(cnt[a[pointer]]);
            ++pointer; // двигаем указатель вправо
        }
    }
    cout << ans_L + 1 << ' ' << ans_R + 1 << '\n';
}