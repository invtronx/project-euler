num, deno = 0, 1
ans = 0

// GG -- Python
for _ in range(1000):
    num += 2 * deno
    num, deno = deno, num
    ans += len(str(num + deno)) > len(str(deno))

print(ans)

