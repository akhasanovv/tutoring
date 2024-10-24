#include <bits/stdc++.h>

using namespace std;
int S, N;
vector<int> A;

void rec(long long sum, int currentIndex) {
    // currentIndex = 0, 1, 2, .., N - 1 -> N (break)
    if (currentIndex == N) {
        if (sum == S) {
            cout << "Yes\n";
            exit(0);
        }
        return ;
    }
    // можем взять элемент A[currentIndex] 0, 1, 2 раза
    rec(sum + 0 * A[currentIndex], currentIndex + 1);
    rec(sum + 1 * A[currentIndex], currentIndex + 1);
}

// дерево высоты N и ширины 3

// 0 -> 0, 1, 2 * A[0]
// 1 -> 0, 1, 2 * A[1]
// ....

int main() {
    cin >> S >> N;
    A = vector<int> (N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    rec(0, 0);
    cout << "No\n";
}