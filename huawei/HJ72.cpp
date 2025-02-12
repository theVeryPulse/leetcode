// 百钱买百鸡

#include <iostream>

int main()
{
    // x has to be multiples of 4
    for (int x = 0; x <= 100 / 5; x += 4)
    {
        int y = 25 - 7 * x / 4;
        int z = 75 + 3 * x / 4;
        if (y >= 0 &&
            z >= 0 &&
            z % 3 == 0 &&
            x + y + z == 100 &&
            5 * x + 3 * y + z / 3 == 100)
            std::cout << x << " " << y << " " << z << "\n";
    }
}
