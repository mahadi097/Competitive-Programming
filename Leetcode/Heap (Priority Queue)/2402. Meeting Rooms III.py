class Solution:
    def mostBooked(self, n: int, meetings: List[List[int]]) -> int:
        f = [0] * n
        meetings.sort(key=lambda x: x[0])
        rooms = SortedList()
        
        for i in range(n):
            rooms.add([0, i])
        
        for st, en in meetings:
            duration = en - st
            free_time, free_room = rooms[0]

            if st > free_time:
                i = 0
                while i < len(rooms) and rooms[i][0] <= st:
                    if rooms[i][1] < free_room:
                        free_time, free_room = rooms[i]
                    i += 1

            f[free_room] += 1
            rooms.discard([free_time, free_room])
            rooms.add([max(free_time, st)+duration, free_room])
        
        most_meetings, room = 0, 0
        for i in range(n):
            if f[i] > most_meetings:
                most_meetings = f[i]
                room = i
        
        return room