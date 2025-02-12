// 放苹果

#include <iostream>

using namespace std;

int countSolution(int apple, int plates)
{
    if (apple <= 1 || plates <= 1)
        return 1;
    else if (plates > apple)
        return countSolution(apple, apple);
    else
    {
        return countSolution(apple - plates, plates)
               + countSolution(apple, plates - 1);
    }
}

int main()
{
    int apples;
    int plates;
    cin >> apples >> plates;
    cout << countSolution(apples, plates) << "\n";
}
