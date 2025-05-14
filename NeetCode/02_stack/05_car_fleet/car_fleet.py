from typing import List


class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        cars = [(position[i], (target - position[i]) / speed[i])
                for i in range(len(position))]
        cars.sort(key=lambda car: car[0])
        # print(cars)

        fleet_amount = 1
        last_time = cars.pop()[1]
        for position, time in reversed(cars):
            if time > last_time:  # Doesn't catch up the last fleet
                fleet_amount += 1
                last_time = time
        return fleet_amount


if __name__ == "__main__":
    solution = Solution()
    position = [10, 8, 0, 5, 3]
    speed = [2, 4, 1, 1, 3]
    target = 12
    print(solution.carFleet(target, position, speed))
