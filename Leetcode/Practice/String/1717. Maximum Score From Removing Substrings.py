from collections import defaultdict


class Solution:
    def maximumGain(self, s: str, x: int, y: int) -> int:
        f = defaultdict(int)
        points = 0

        for c in s:
            if c != 'a' and c != 'b':
                points += min(x, y) * min(f['a'], f['b'])
                f.clear()
            else:
                if c == 'a':
                    if x >= y or f['b'] == 0:
                        f[c] += 1
                    else:
                        f['b'] -= 1
                        points += y
                else:
                    if y >= x or f['a'] == 0:
                        f[c] += 1
                    else:
                        f['a'] -= 1
                        points += x

        points += min(x, y) * min(f['a'], f['b'])
        return points