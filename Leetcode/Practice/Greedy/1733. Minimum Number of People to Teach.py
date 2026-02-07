class Solution:
    def minimumTeachings(self, n: int, languages: List[List[int]], friendships: List[List[int]]) -> int:
        m = len(languages)
        users = [defaultdict(bool) for _ in range(m)]

        for index, langs in enumerate(languages):
            langs.sort()
            for l in langs:
                users[index][l] = True

        for index, [u, v] in enumerate(friendships):
            good = False
            i = j = 0
            while i < len(languages[u-1]) and j < len(languages[v-1]):
                if languages[u-1][i] == languages[v-1][j]:
                    good = True
                    break
                elif languages[u-1][i] < languages[v-1][j]:
                    i += 1
                else:
                    j += 1
            friendships[index].append(good)

        ans = inf

        for l in range(1, n+1):
            added = []
            for u, v, good in friendships:
                if good:
                    continue
                if not users[u-1][l]:
                    users[u-1][l] = True
                    added.append(u-1)
                if not users[v-1][l]:
                    users[v-1][l] = True
                    added.append(v-1)
            
            ans = min(ans, len(added))
            for u in added:
                users[u][l] = False

        return ans