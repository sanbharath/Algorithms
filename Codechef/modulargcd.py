from fractions import gcd
p = 1000000007


def power(x, y, diff):
    res = 1
    x = x % diff
    while y > 0:
        if y & 1:
            res = (res*x) % diff

        y = y >> 1
        x = (x*x) % diff

    return res


t = int(input())
while t:
    a,b,n = map(int,input().split(' '))
    d = a - b
    if d == 0:
        s = power(a, n, p) + power(b, n, p)
        s = s % p
        print(s)
    else:
        s = (power(a, n, d) + power(b, n, d)) % d
        #if s == 0:
        #    res = d % p
        #    print(res)
        #    continue
        g = gcd(s, d)
        g = g % p
        print(g)
    t = t-1

