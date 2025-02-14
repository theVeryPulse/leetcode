// HJ97 记负均正

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num_count;
    cin >> num_count;
    vector<int> positives;
    vector<int> negatives;
    for (int i = 0; i < num_count; ++i)
    {
        int num;
        cin >> num;
        if (num > 0)
            positives.push_back(num);
        else if (num < 0)
            negatives.push_back(num);
    }
    int sum = 0;
    for (int positive : positives)
        sum += positive;
    double average = 0;
    if (!positives.empty())
        average = (double)sum / (double)positives.size();
    cout << negatives.size() << " " << average << "\n";
}
