N = int(input())
dp = []
for i in range(N + 1):
    dp.append([0, 0])
dp[1][0] = 1
dp[1][1] = 1
for i in range(2, N + 1):
    dp[i][0] += dp[i - 1][0] + dp[i - 1][1]
    dp[i][1] += dp[i - 1][0]

print(dp[N][0] + dp[N][1])