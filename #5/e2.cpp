#include <bits/stdc++.h>

using namespace std;
constexpr int inf = 1e9 + 17;

long long factorial(long long n) {
	if (n <= 1) {
		return 1;
	}
	return n * factorial(n - 1);
}

int main() {
	int N, M;
	cin >> N >> M;
	// C(m + n - 2, n - 1)
	cout << factorial(M + N - 2) / factorial(N - 1) / factorial(M - 1) << '\n';
}