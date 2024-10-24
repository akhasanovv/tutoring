s = input()
ans, b = 0, 0
for i in range(len(s) - 1, -1, -1):
	if s[i] == 'a':
		ans += b
	else:
		b += 1
print(ans)