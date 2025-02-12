#include <vector>
#include <iostream>

using namespace std;

class Rabbit
{
    public:
      Rabbit() : month_age_(0)
      {
      }
      int  month_age_;
};

int main()
{
    int month;
    cin >> month;
    vector<Rabbit> rabbits(1);
    for (int ith_month = 1; ith_month < month; ++ith_month)
    {
        int new_rabbits = 0;
        for (auto& rabbit : rabbits)
        {
            ++rabbit.month_age_;
            if (rabbit.month_age_ >= 2)
                ++new_rabbits;
        }
        for (int j = 0; j < new_rabbits; ++j)
            rabbits.push_back(Rabbit());
    }
    cout << rabbits.size();
}
