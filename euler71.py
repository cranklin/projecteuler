import bisect
import math

def isReduced(n, d):
    if d % n == 0:
        return False
    if d % 2 == 0 and n % 2 == 0:
        return False
    for i in range(3, int(math.sqrt(n)), 2):
        if d % i == 0 and n % i == 0:
            return False
    return True

current = None
for d in range(1000000, 999900, -1):
#for d in range(8, 4, -1):
    if d % 7 == 0:
        continue
    for n in range(int((3/7) * d), int((2/5) * d) - 1, -1):
        print(str(n) + "/" + str(d))
        if current is None or current[0]*d < n*current[1]:
            current = (n, d)
            print(f'new current: {n}/{d}')
            break

print(current)
