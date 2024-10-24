#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	long double max_income = 1.0;
	int mn_index = -1, mn = 1e9;
	pair<int, int> answer = {0, 0};

	for (int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if ((long double)x / (long double)mn > max_income) {
			max_income = (long double)x / (long double)mn;
			answer = {mn_index + 1, i + 1};
		}
		if (x < mn) {
			mn = x;
			mn_index = i;
		}
	}
	cout << answer.first << ' ' << answer.second << '\n';
}