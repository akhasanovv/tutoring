// https://informatics.msk.ru/mod/statements/view.php?id=86656#1
#include <bits/stdc++.h>

using namespace std;
int main() {
    queue<int> Q;
    while (true) {
        string query; cin >> query;
        if (query == "push") {
            int n; cin >> n;
            Q.push(n);
            cout << "ok\n";
        } else if (query == "pop") {
            cout << Q.front() << '\n';
            Q.pop();
        } else if (query == "front") {
            cout << Q.front() << '\n';
        } else if (query == "size") {
            cout << Q.size() << '\n';
        } else if (query == "clear") {
            while (!Q.empty()) Q.pop();
            cout << "ok\n";
        } else {
            cout << "bye\n";
            return 0;
        }
    }
}