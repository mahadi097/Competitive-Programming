class TaskManager:

    def __init__(self, tasks: List[List[int]]):
        self.task_pu = defaultdict(list)
        self.tasks = SortedList()
        for user, task, priority in tasks:
            self.task_pu[task] = [user, priority]
            self.tasks.add([priority, task])
        
    def add(self, userId: int, taskId: int, priority: int) -> None:
        self.task_pu[taskId] = [userId, priority]
        self.tasks.add([priority, taskId])

    def edit(self, taskId: int, newPriority: int) -> None:
        self.tasks.discard([self.task_pu[taskId][1], taskId])
        self.tasks.add([newPriority, taskId])
        self.task_pu[taskId][1] = newPriority

    def rmv(self, taskId: int) -> None:
        self.tasks.discard([self.task_pu[taskId][1], taskId])
        self.task_pu[taskId].clear()

    def execTop(self) -> int:
        if not self.tasks:
            return -1
        taskId = self.tasks[-1][1]
        userId = self.task_pu[taskId][0]
        self.tasks.pop()
        self.task_pu[taskId].clear()

        return userId
        


# Your TaskManager object will be instantiated and called as such:
# obj = TaskManager(tasks)
# obj.add(userId,taskId,priority)
# obj.edit(taskId,newPriority)
# obj.rmv(taskId)
# param_4 = obj.execTop()