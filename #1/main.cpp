#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    double ans = 10.0 - 10.0; // 10 * a[i] / a[i] = 10
    int ansL = -1, ansR = -1;
    // for (int i = 1; i < n; ++i) { // i - правая
    //     int B = a[i];
    //     for (int j = 0; j < i; ++j) { // j - левая
    //         int A = a[j];
    //         // прибыль = 10 * B / A
    //         double current_price = (double)10 * (double)B / (double)A - 10.0;
    //         if (current_price > ans) {
    //             ans = current_price;
    //             ansL = j;
    //             ansR = i;
    //         }
    //     }
    // }

    vector<int> prefMin(n), prefMinIndex(n);

    // prefMax[i] - максимум на отрезке (префиксе) [0; i]
    for (int i = 0; i < n; ++i) {
        if (i == 0) {
            prefMin[i] = a[i];
            prefMinIndex[i] = i;
        } else { // i > 0
            if (a[i] < prefMin[i - 1]) {
                prefMin[i] = a[i];
                prefMinIndex[i] = i;
            } else {
                prefMin[i] = prefMin[i - 1];
                prefMinIndex[i] = prefMinIndex[i - 1];
            }
        }
    }

    for (int i = 1; i < n; ++i) { // i - правая
        int B = a[i];
        // [0; i - 1]
        // for (int j = 0; j < i; ++j) { // j - левая
        //     int A = a[j];
        //     // прибыль = 10 * B / A - 10
        //     double current_price = (double)10 * (double)B / (double)A - 10.0;
        //     if (current_price > ans) {
        //         ans = current_price;
        //         ansL = j;
        //         ansR = i;
        //     }
        // }
        // прибыль = B / A -> была максимальна
        // знаем B, A - минимально


        int A = prefMin[i - 1];
        int j = prefMinIndex[i - 1];
        // прибыль = 10 * B / A - 10
        double current_price = (double)10 * (double)B / (double)A - 10.0;
        if (current_price > ans) {
            ans = current_price;
            ansL = j;
            ansR = i;
        }
    }


    cout << ansL + 1 << ' ' << ansR + 1 << '\n';
}



