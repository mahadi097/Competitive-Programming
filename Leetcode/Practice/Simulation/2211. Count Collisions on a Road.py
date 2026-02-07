class Solution:
    def countCollisions(self, directions: str) -> int:
        ans = rF = 0
        prv = 'L'
        for i, d in enumerate(directions):
            collision = False
            if d == 'R':
                rF += 1
            else: 
                if d == 'S':
                    ans += rF
                elif d == 'L':
                    if prv == 'R':
                        collision = True
                        ans += rF + 1
                    elif prv == 'S':
                        collision = True
                        ans += 1
                rF = 0
            prv = d if collision == False else 'S'

        return ans