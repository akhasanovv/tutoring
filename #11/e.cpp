// https://informatics.msk.ru/mod/statements/view.php?id=86656&chapterid=60#1
#include <bits/stdc++.h>

using namespace std;
int main() {
    deque<int> Q;
    while (true) {
        string query; cin >> query;
        if (query == "push_front") {
            int n; cin >> n;
            Q.push_front(n);
            cout << "ok\n";
        } else if (query == "push_back") {
            int n; cin >> n;
            Q.push_back(n);
            cout << "ok\n";
        } else if (query == "pop_front") {
            cout << Q.front() << '\n';
            Q.pop_front();
        } else if (query == "pop_back") {
            cout << Q.back() << '\n';
            Q.pop_back();
        } else if (query == "front") {
            cout << Q.front() << '\n';
        } else if (query == "back") {
            cout << Q.back() << '\n';
        } else if (query == "size") {
            cout << Q.size() << '\n';
        } else if (query == "clear") {
            while (!Q.empty()) Q.pop_back();
            cout << "ok\n";
        } else {
            cout << "bye\n";
            return 0;
        }
    }
}