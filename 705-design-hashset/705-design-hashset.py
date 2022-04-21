class MyHashSet:

    def __init__(self):
        self.hashSet = dict()

    def add(self, key: int) -> None:
        self.hashSet[key] = True

    def remove(self, key: int) -> None:
        if key in self.hashSet:
            del self.hashSet[key]

    def contains(self, key: int) -> bool:
        return key in self.hashSet


# Your MyHashSet object will be instantiated and called as such:
# obj = MyHashSet()
# obj.add(key)
# obj.remove(key)
# param_3 = obj.contains(key)