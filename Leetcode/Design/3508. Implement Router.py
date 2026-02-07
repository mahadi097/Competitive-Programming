class Router:

    def __init__(self, memoryLimit: int):
        self.n = memoryLimit
        self.exist = defaultdict(bool)
        self.p = deque()
        self.d = defaultdict(SortedList)

    def addPacket(self, source: int, destination: int, timestamp: int) -> bool:
        packet = (source, destination, timestamp)
        
        if self.exist[packet]:
            return False
        if len(self.p) == self.n:
            self.forwardPacket()

        self.p.append(packet)
        self.exist[packet] = True
        self.d[destination].add(timestamp)
        return True

    def forwardPacket(self) -> List[int]:
        if not self.p:
            return []
        
        packet = self.p.popleft()
        self.exist[packet] = False
        self.d[packet[1]].discard(packet[2])
        return packet

    def getCount(self, destination: int, startTime: int, endTime: int) -> int:
        return self.d[destination].bisect_right(endTime) - self.d[destination].bisect_left(startTime)


# Your Router object will be instantiated and called as such:
# obj = Router(memoryLimit)
# param_1 = obj.addPacket(source,destination,timestamp)
# param_2 = obj.forwardPacket()
# param_3 = obj.getCount(destination,startTime,endTime)