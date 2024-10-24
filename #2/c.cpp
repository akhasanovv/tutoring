#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> countLetter(26, 0);
	// 26 букв в латинском алфавите
	string s;
	cin >> s;
	int pointer = 0, ans = 0, firstLetter = 0;
	for (int i = 0; i < n; ++i) {
		++countLetter[s[i] - 'a'];
		// s[i] - 'a' -> число в отрезке [0, 25]
		// ('a' - 'a') = 0, ('b' - 'a') = 1, ...
		while (*max_element(countLetter.begin(), countLetter.end()) > k) {
			--countLetter[s[pointer] - 'a'];
			++pointer;
		}
		if (i - pointer + 1 > ans) {
			ans = i - pointer + 1;
			firstLetter = pointer + 1;
		}
		// отрезок [pointer, i] -> наибольший по длине хороший отрезок с правым концом в i
		// отрезки [pointer, i], [pointer + 1, i], ..., [i, i] являются хорошими
		// любой отрезок [0, i], [1, i], ..., [pointer - 1, i] является плохим
	}
	cout << ans << ' ' << firstLetter << '\n';
}