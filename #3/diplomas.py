l, r = 0, int(10**18)
w, h, n = map(int, input().split())

while r - l > 1:
	m = (l + r) // 2
	if (m // h) * (m // w) >= n:
		r = m 
	else:
		l = m

print(r)