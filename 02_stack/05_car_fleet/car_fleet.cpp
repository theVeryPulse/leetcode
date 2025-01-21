#include <vector>
#include <algorithm>

using std::vector;

class Solution
{
  public:
    struct Car
    {
        int   position_;
        float time_;

        Car(int position, float time) : position_(position), time_(time)
        {
        }
    };

    int carFleet(int target, vector<int>& position, vector<int>& speed)
    {
        vector<Car> cars;
        for (size_t i = 0; i < position.size(); i++)
        {
            cars.push_back(
                Car(position[i],
                    (target - position[i]) / static_cast<float>(speed[i])));
        }
        std::sort(cars.begin(), cars.end(), [](const Car& a, const Car& b) {
            return a.position_ < b.position_;
        });

        int   fleet_amount = 1;
        float last_time    = cars.back().time_;

        for (auto car = ++cars.rbegin(); car != cars.rend(); ++car)
        {
            if (car->time_ > last_time)
            {
                ++fleet_amount;
                last_time = car->time_;
            }
        }
        return fleet_amount;
    }
};

#include <iostream>

int main()
{
    Solution    solution;
    int         target   = 12;
    vector<int> position = {10, 8, 0, 5, 3};
    vector<int> speed    = {2, 4, 1, 1, 3};
    std::cout << solution.carFleet(target, position, speed) << "\n";
}
