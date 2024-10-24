#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin >> s;
	int64_t ans = 0, b = 0;
	for (int i = (int)s.length() - 1; i > -1; --i) {
		if (s[i] == 'a') ans += b;
		else ++b;
	}
	cout << ans << '\n';
}