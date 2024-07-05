class LinkedNode:
  def __init__(self, key = -1, val = -1, left = None, right = None) -> None:
      self.key = key
      self.val = val
      self.left: LinkedNode = left
      self.right: LinkedNode = right
     
class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = dict()
        
        self.head_LRU = LinkedNode()
        self.tail_LRU = LinkedNode()
        
        self.head_LRU.right = self.tail_LRU
        self.tail_LRU.left = self.head_LRU
        
    def _remove(self, node: LinkedNode) -> None:
        print(node.val)
        # node.left.right = node.right
        # node.right.left = node.left
        
    def _add_to_last(self, key: int, value: int) -> None:
        node = LinkedNode(key, value, self.tail_LRU.left, self.tail_LRU)
        self.tail_LRU.left.right = node
        self.tail_LRU.left = node
        
    def _remove_LRU(self):
        node_LRU = self.head_LRU.right

        self.cache.pop(node_LRU.key)
        
        self._remove(node_LRU)

    def get(self, key: int) -> int:
        if key in self.cache: 
            node = self.cache[key]
            print("node", node.val)
            
            self._remove(node)
            self._add_to_last(key, node.val)
            
            return node.val
        
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            node = self.cache[key]
            
            self._remove(node)
            self._add_to_last(key, value)
        else:
            if len(self.cache) < self.capacity:
                self._add_to_last(key, value)
                self.cache[key] = self.tail_LRU
            else:
                self._remove_LRU()
                self._add_to_last(key, value)

                self.cache[key] = self.tail_LRU



# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)

obj = LRUCache(2)

obj.put(1, 1)
obj.put(2, 2)

print(obj.get(1))

# obj.put(3, 3)

# print()