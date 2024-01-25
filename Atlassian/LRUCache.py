class LRUCache:
    def __init__(self, capacity: int):
        self.cap = capacity
        self.cache = {}
    def get(self, key: int) -> int:
        try:
            v = self.cache[key] = self.cache.pop(key)
            return v
        except:
            return -1
    def put(self, key:int, value: int) -> None:
        d = self.cache
        if key in d:
            del d[key]
        elif len(d) == self.cap:
            del d[next(iter(d))]
        d[key] = value