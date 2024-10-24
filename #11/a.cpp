// https://informatics.msk.ru/mod/statements/view.php?id=84893&chapterid=111951#1
#include <bits/stdc++.h>

using namespace std;
int main() {
    long long N, K;
    cin >> N >> K;
    long long l = -1, r = 2e9 + 17;
    while (r - l > 1) {
        long long mid = (l + r) / 2;
        // необходимое условие - (mid + K) / (mid + N) >= 1/3
        // переведем в целые - (mid + K) / (mid + N) * 3 >= 1
        if (3 * (mid + K) / (mid + N) >= 1) r = mid;
        else l = mid;
    }
    cout << r << '\n';
}