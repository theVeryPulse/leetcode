// 坐标移动

#include <iostream>
#include <string>

struct Coord
{
    int x_ = 0;
    int y_ = 0;

  public:
    void tryMove(const std::string&& s)
    {
        if ((s.length() == 2 && isADWS(s[0]) && isdigit(s[1])) ||
             s.length() == 3 && isADWS(s[0]) && isdigit(s[1]) && isdigit(s[2]))
        {
            int steps = std::stoi(s.substr(1));
            if (s[0] == 'A')
                x_ -= steps;
            else if (s[0] == 'D')
                x_ += steps;
            else if (s[0] == 'W')
                y_ += steps;
            else if (s[0] == 'S')
                y_ -= steps;
        }
    }

  private:
    bool isADWS(char c)
    {
        return c == 'A' || c == 'D' || c == 'W' || c == 'S';
    }
};

int main()
{
    std::string line;
    std::getline(std::cin, line);
    Coord  coord;
    size_t i = 0;
    do
    {
        coord.tryMove(line.substr(i, line.find_first_of(';', i) - i));
        i = line.find_first_of(';', i) + 1;
    } while (i < line.length());
    std::cout << coord.x_ << "," << coord.y_ << "\n";
}
