s = input()
dp = [0] * (len(s) + 1)
dp[0] = 1
for i in range(1, len(s) + 1):
	dp[i] = dp[i - 1]
	if i >= 2 and 10 <= int(s[i - 2] + s[i - 1]) <= 33:
		dp[i] += dp[i - 2]
print(dp[len(s)])