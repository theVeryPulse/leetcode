from typing import Dict, List


class TimeValue:
    def __init__(self, time: int, value: str):
        self.time = time
        self.value = value
    time: int
    value: str


class TimeMap:

    def __init__(self):
        self.data: Dict[str, List[TimeValue]] = dict()

    def set(self, key: str, value: str, timestamp: int) -> None:
        if self.data.get(key) is None:
            self.data[key] = list()
        self.data[key].append(TimeValue(timestamp, value))

    def get(self, key: str, timestamp: int) -> str:
        if self.data.get(key) is None:
            return ""
        time_values: List[TimeValue] = self.data[key]
        begin: int = 0
        end: int = len(time_values)
        mid: int = (begin + end) // 2
        while begin != mid:
            if time_values[mid].time < timestamp:
                begin = mid
            elif time_values[mid].time > timestamp:
                end = mid
            else:
                return time_values[mid].value
            mid = (begin + end) // 2
        if time_values[end-1].time <= timestamp:
            return time_values[end-1].value
        elif time_values[mid].time <= timestamp:
            return time_values[mid].value
        else:
            return ""

# Your TimeMap object will be instantiated and called as such:
# obj = TimeMap()
# obj.set(key,value,timestamp)
# param_2 = obj.get(key,timestamp)


def run_test(cmds: List[str], params: List):
    time_map = TimeMap()
    for i, cmd in enumerate(cmds):
        if cmd == "set":
            time_map.set(params[i][0], params[i][1], params[i][2])
        elif cmd == "get":
            print(time_map.get(params[i][0], params[i][1]))


def main():
    cmds = ["TimeMap", "set", "get", "get", "set", "get", "get"]
    params = [[], ["foo", "bar", 1], ["foo", 1], ["foo", 3],
              ["foo", "bar2", 4], ["foo", 4], ["foo", 5]]
    run_test(cmds, params)

    cmds = ["TimeMap", "set", "get", "get", "set", "get",
            "get", "set", "set", "set", "set", "set", "get"]
    params = [[], ["foo", "bar", 1], ["foo", 1], ["foo", 3],
              ["foo", "bar2", 4], ["foo", 4], ["foo", 5], ["foo", "zigzag", 7],
              ["foo", "conundrum", 8], ["foo", "hyperbole", 9],
              ["foo", "silhouette", 10], ["foo", "blasphemy", 11], ["foo", 9]]
    run_test(cmds, params)


if __name__ == "__main__":
    main()
