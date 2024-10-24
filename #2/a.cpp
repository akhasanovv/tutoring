#include <bits/stdc++.h>

using namespace std;
constexpr int inf = 1e9;

int main() {
	int N;
	cin >> N;
	vector<int> shirts(N);
	for (int i = 0; i < N; ++i) {
		cin >> shirts[i];
	}
	int M;
	cin >> M;
	vector<int> pants(M);
	for (int i = 0; i < M; ++i) {
		cin >> pants[i];
	}
	int pointer = -1;
	int ans_shirt = -inf, ans_pants = inf;
	for (int i = 0; i < M; ++i) {
		while (pointer + 1 < N && shirts[pointer + 1] <= pants[i]) {
			++pointer;
		}
		if (pointer >= 0) {
			if (abs(pants[i] - shirts[pointer]) < abs(ans_shirt - ans_pants)) {
				ans_shirt = shirts[pointer];
				ans_pants = pants[i];
			}
		}
		if (abs(pants[i] - shirts[pointer + 1]) < abs(ans_shirt - ans_pants)) {
			ans_shirt = shirts[pointer + 1];
			ans_pants = pants[i];
		}
	}
	cout << ans_shirt << ' ' << ans_pants << '\n';
}