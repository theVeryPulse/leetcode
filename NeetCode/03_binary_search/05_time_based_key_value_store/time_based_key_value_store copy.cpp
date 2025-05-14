#include <string>
#include <unordered_map>
#include <vector>
#include <numeric>

using namespace std;

class TimeMap
{
  public:
    struct TimestampValue {
        int    timestamp;
        string value;
    };

    TimeMap()
    {
    }

    void set(string key, string value, int timestamp)
    {
        data_[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp)
    {
        if (!data_.contains(key))
            return "";
        else
            return binarySearch(data_[key], timestamp);
    }

  private:
    const string& binarySearch(
        const vector<TimestampValue>& timestamp_value_vec, int timestamp)
    {
        size_t start = 0;
        size_t end = timestamp_value_vec.size();
        size_t mid = midpoint(start, end);
        while (start != mid)
        {
            if (timestamp_value_vec[mid].timestamp < timestamp)
                start = mid;
            else if (timestamp_value_vec[mid].timestamp > timestamp)
                end = mid;
            else
                return timestamp_value_vec[mid].value;
            mid = midpoint(start, end);
        }
        if (timestamp_value_vec[end - 1].timestamp <= timestamp)
            return timestamp_value_vec[end - 1].value;
        else if (timestamp_value_vec[mid].timestamp <= timestamp)
            return timestamp_value_vec[mid].value;
        else
            return empty_;
    }

    unordered_map<string, vector<TimestampValue>> data_;
    string                                        empty_ {""};
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */

#include <iostream>
#define TEST3 1
int main()
{
    TimeMap* time_map;
#ifdef TEST1
    time_map = new TimeMap();
    // store the key "foo" and value "bar" along with timestamp = 1.
    time_map->set("foo", "bar", 1);
    std::cout << time_map->get("foo", 1) << "\n"; // return "bar"
    std::cout << time_map->get("foo", 3) << "\n"; // return "bar"
    // store the key "foo" and value "bar2" along with timestamp = 4.
    time_map->set("foo", "bar2", 4);
    std::cout << time_map->get("foo", 4) << "\n"; // return "bar2"
    std::cout << time_map->get("foo", 5) << "\n"; // return "bar2"
    delete time_map;
#endif
#ifdef TEST2
    time_map = new TimeMap();
    time_map->set("love", "high", 10);
    time_map->set("love", "low", 20);
    std::cout << time_map->get("love", 5) << "\n";  // return ""
    std::cout << time_map->get("love", 10) << "\n"; // return "high"
    std::cout << time_map->get("love", 15) << "\n"; // return "high"
    std::cout << time_map->get("love", 20) << "\n"; // return "low"
    std::cout << time_map->get("love", 25) << "\n"; // return "low"
    delete time_map;
#endif
#ifdef TEST3
    time_map = new TimeMap();
    time_map->set("a", "bar", 1);
    time_map->set("x", "b", 3);
    std::cout << time_map->get("b", 3) << "\n"; // return ""
    time_map->set("foo", "bar2", 4);
    std::cout << time_map->get("foo", 4) << "\n"; // return ""
    std::cout << time_map->get("foo", 5) << "\n"; // return ""
    delete time_map;
#endif
}