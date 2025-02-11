#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

const std::vector<int> legal_masks = {0b11111111, 0b11111110, 0b11111100,
                                      0b11111000, 0b11110000, 0b11100000,
                                      0b11000000, 0b10000000, 0b00000000};

class IP
{
  public:
    //--------------- Types: Classes, Enums, and Aliases (using) ---------------
    //----------------- Constructors, Assignments, Destructor ------------------
    IP(const std::string& addr, const std::string& mask)
    {
        size_t start = 0;
        int    byte = 0;
        for (size_t end = 0; end < addr.length(); ++end)
        {
            if (addr[end] == '.' || (end == addr.length() - 1 && ++end))
            {
                addr_[byte] = (std::stoi(addr.substr(start, end - start)));
                start = end + 1;
                ++byte;
            }
        }
        start = 0;
        byte = 0;
        for (size_t end = 0; end < mask.length(); ++end)
        {
            if (mask[end] == '.' || (end == mask.length() - 1 && ++end))
            {
                mask_[byte] = (std::stoi(mask.substr(start, end - start)));
                start = end + 1;
                ++byte;
            }
        }

        // Determin IP type
        if (addr_[0] >= 1 && addr_[0] <= 126)
            type_ = 'A';
        else if (addr_[0] >= 128 && addr_[0] <= 191)
            type_ = 'B';
        else if (addr_[0] >= 192 && addr_[0] <= 223)
            type_ = 'C';
        else if (addr_[0] >= 224 && addr_[0] <= 239)
            type_ = 'D';
        else if (addr_[0] >= 240 && addr_[0] <= 255)
            type_ = 'E';
        else if (addr_[0] == 0 || addr_[0] == 127)
            type_ = 'S'; // Special

        // Determine if IP is private
        is_private_ = addr_[0] == 10
                      || (addr_[0] == 172 && addr_[1] >= 16 && addr_[1] <= 31)
                      || (addr_[0] == 192 && addr_[1] == 168);
    }

    //------------------------------- Functions --------------------------------
    bool isSpecialIP()
    {
        return addr_[0] == 0 || addr_[0] == 127;
    }

    static bool isValidAddr(const std::string& addr)
    {
        std::vector<int> nums;
        size_t           start = 0;
        for (size_t end = 0; end < addr.length(); ++end)
        {
            if (!isdigit(addr[end]) && addr[end] != '.')
                return false;
            if (addr[end] == '.' || (end == addr.length() - 1 && ++end))
            {
                if (start == end)
                    return false;
                nums.emplace_back(std::stoi(addr.substr(start, end - start)));
                start = end + 1;
                if (nums.back() > 255 || nums.back() < 0)
                    return false;
            }
        }
        if (nums.size() != 4)
            return false;
        return true;
    }

    static bool isValidMask(const std::string& mask)
    {
        std::vector<int> nums;
        size_t           start = 0;
        for (size_t end = 0; end < mask.length(); ++end)
        {
            if (!isdigit(mask[end]) && mask[end] != '.')
                return false;
            if (mask[end] == '.' || (end == mask.length() - 1 && ++end))
            {
                if (start == end)
                    return false;
                nums.emplace_back(std::stoi(mask.substr(start, end - start)));
                start = end + 1;
                if (nums.back() > 255 || nums.back() < 0)
                    return false;
            }
        }
        if (nums.size() != 4)
            return false;
        if (nums[0] == 0) // first byte being 0
            return false;
        bool is_end = false;
        bool all_ones = true;
        for (int num : nums)
        {
            // Invalid value
            if (std::find(legal_masks.begin(), legal_masks.end(), num)
                == legal_masks.end())
                return false;
            // 1 after 0
            if (is_end && num != 0)
                return false;
            if (num != 0xFF)
            {
                is_end = true;
                all_ones = false;
            }
        }
        if (all_ones)
            return false;
        return true;
    }

    //---------------------------------- Data ----------------------------------
    unsigned char addr_[4];
    unsigned char mask_[4];
    char          type_;
    bool          is_private_;
};

int main()
{

    int illegal_ip_or_mask = 0;

    std::vector<IP> ip_vector;
    while (true)
    {
        std::string line;
        std::cin >> line;
        if (std::cin.eof())
            break;
        std::string addr = line.substr(0, line.find_first_of('~'));
        std::string mask = line.substr(line.find_first_of('~') + 1);
        if (!IP::isValidAddr(addr))
        {
            ++illegal_ip_or_mask;
            continue;
        }
        ip_vector.emplace_back(IP(addr, mask));
        if (!ip_vector.back().isSpecialIP() && !IP::isValidMask(mask))
        {
            ++illegal_ip_or_mask;
            ip_vector.pop_back();
        }
    }

    int types[5] = {0, 0, 0, 0, 0};
    int private_ip = 0;
    for (const auto& ip : ip_vector)
    {
        if (ip.type_ >= 'A' && ip.type_ <= 'E')
            types[ip.type_ - 'A'] += 1;
        if (ip.is_private_)
            ++private_ip;
    }
    std::cout << types[0] << " " << types[1] << " " << types[2] << " "
              << types[3] << " " << types[4] << " " << illegal_ip_or_mask << " "
              << private_ip << "\n";
}