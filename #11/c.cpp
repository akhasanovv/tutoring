// https://informatics.msk.ru/mod/statements/view.php?id=86656&chapterid=49#1
#include <bits/stdc++.h>

using namespace std;
int main() {
    int grade; string surname;
    vector<string> grade9, grade10, grade11;
    while (cin >> grade >> surname) {
        if (grade == 9) grade9.push_back(surname);
        else if (grade == 10) grade10.push_back(surname);
        else grade11.push_back(surname);
    }
    for (auto sname : grade9) cout << "9 " << sname << '\n';
    for (auto sname : grade10) cout << "10 " << sname << '\n';
    for (auto sname : grade11) cout << "11 " << sname << '\n';
}