class Solution:
    def countMentions(self, numberOfUsers: int, events: List[List[str]]) -> List[int]:
        events.sort(key=lambda x: x[0], reverse=True)
        events.sort(key=lambda x: int(x[1]))
        mentions = [0 for _ in range(numberOfUsers)]
        online = [0 for _ in range(numberOfUsers)]

        for event_type, timestamp, ids in events:
            if event_type == "OFFLINE":
                online[int(ids)] = int(timestamp) + 60
            else:
                if ids == "ALL":
                    for i in range(numberOfUsers):
                        mentions[i] += 1
                elif ids == "HERE":
                    for i in range(numberOfUsers):
                        if online[i] <= int(timestamp):
                            mentions[i] += 1
                else:
                    id_list = ids.split()
                    for id_string in id_list:
                        id_num = int(id_string[2:])
                        mentions[id_num] += 1
        
        return mentions