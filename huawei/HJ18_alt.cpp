#include <iostream>
#include <string>
#include <vector>
#include <sstream>

// clang-format off

bool isLegalMaskPart(int byte)
{
    return byte == 0b11111111 ||
           byte == 0b11111110 ||
           byte == 0b11111100 ||
           byte == 0b11111000 ||
           byte == 0b11110000 ||
           byte == 0b11100000 ||
           byte == 0b11000000 ||
           byte == 0b10000000 ||
           byte == 0b00000000;
}

// clang-format on

int main()
{
    int type_a = 0;
    int type_b = 0;
    int type_c = 0;
    int type_d = 0;
    int type_e = 0;
    int illegal_ip_or_mask = 0;
    int private_ip = 0;

    while (true)
    {
        std::string line;
        std::getline(std::cin, line);
        if (std::cin.eof())
            break;
        if (line.empty())
            continue;
        std::stringstream ip_ss(line.substr(0, line.find_first_of('~')));
        int ip_parts[4];
        /* 
         - Check IP is legal: 
           - empty partvalue
           - not a number
           - out of scope
         - Skip mask check and type count for special IP's 0.*.*.* and 127.*.*.*
         - Check mask is legal
           - empty partvalue
           - not a number
           - out of scope
           - 1 after 0
           - all 1s and 0s
         - Count type and private: Only for valid IP AND mask combination
         */

        // Check IP
        bool ip_is_valid = true;
        for (int i = 0; i < 4; ++i)
        {
            std::string part_str;
            std::getline(ip_ss, part_str, '.');
            if (part_str.empty()) // Illegal IP: empty part
            {
                ++illegal_ip_or_mask;
                ip_is_valid = false;
                break;
            }
            try
            {
                int part_value = std::stoi(part_str);
                ip_parts[i] = part_value;
            }
            catch(...) // Illegal IP: is not a number
            {
                ++illegal_ip_or_mask;
                ip_is_valid = false;
                break;
            }
            if (ip_parts[i] < 0 || ip_parts[i] > 255) // Illegal IP: out of scope
            {
                ++illegal_ip_or_mask;
                ip_is_valid = false;
                break;
            }
            int mask_parts[4];
        }

        // Skip counting type and checking masks for invalid ip
        // Skip checking mask for 0.*.*.* and 127.*.*.* and invalid ip
        if (!ip_is_valid || ip_parts[0] == 0 || ip_parts[0] == 127)
            continue;

        // Check mask
        int  mask_parts[4];
        bool zero_appeared = false;
        bool mask_is_valid = true;
        std::stringstream mask_ss(line.substr(1 + line.find_first_of('~')));
        for (int i = 0; i < 4; ++i)
        {
            std::string part_str;
            std::getline(mask_ss, part_str, '.');
            if (part_str.empty()) // Illegal mask: empty part
            {
                ++illegal_ip_or_mask;
                mask_is_valid = false;
            }
            try
            {
                int part_value = std::stoi(part_str);
                mask_parts[i] = part_value;
            }
            catch(...) // Illegal mask: not a number
            {
                ++illegal_ip_or_mask;
                mask_is_valid = false;
                break;
            }
            if (!isLegalMaskPart(mask_parts[i])) // Illegal mask: impossible value
            {
                ++illegal_ip_or_mask;
                mask_is_valid = false;
                break;
            }
            if (zero_appeared && mask_parts[i] != 0) // Illegal mask: 1 after 0
            {
                ++illegal_ip_or_mask;
                mask_is_valid = false;
                break;
            }
            if (mask_parts[i] != 0b11111111)
                zero_appeared = true;
        }
        if (!mask_is_valid)
            continue;
        // clang-format off
        if ((mask_parts[0] == 0 &&
             mask_parts[1] == 0 &&
             mask_parts[2] == 0 &&
             mask_parts[3] == 0)
             ||
            (mask_parts[0] == 0b11111111 &&
             mask_parts[1] == 0b11111111 &&
             mask_parts[2] == 0b11111111 &&
             mask_parts[3] == 0b11111111))
        {
            ++illegal_ip_or_mask; // Illegal mask: all 1s or all 0s
            continue;
        }

        // clang-format on
        // Count type: A B C D E
        if (ip_parts[0] >= 1 && ip_parts[0] <= 126)
            ++type_a;
        else if (ip_parts[0] >= 128 && ip_parts[0] <= 191)
            ++type_b;
        else if (ip_parts[0] >= 192 && ip_parts[0] <= 223)
            ++type_c;
        else if (ip_parts[0] >= 224 && ip_parts[0] <= 239)
            ++type_d;
        else if (ip_parts[0] >= 240 && ip_parts[0] <= 255)
            ++type_e;
        // clang-format off

        // Count private
        if ((ip_parts[0] == 10) ||
            (ip_parts[0] == 172 && ip_parts[1] >= 16 && ip_parts[1] <= 31) ||
            (ip_parts[0] == 192 && ip_parts[1] == 168))
            ++private_ip;
    }
    std::cout << type_a << " "
              << type_b << " "
              << type_c << " "
              << type_d << " "
              << type_e << " "
              << illegal_ip_or_mask << " "
              << private_ip << std::endl;
    // clang-format on
}

/* 
42.53.252.112~255.0.0.0          -> A
166.237.7.68~255.0.0.0           -> B
136.3.73.64~255.255.0.0          -> B
204.29.136.133~255.255.0.245     -> illegal
195.30.208.94~255.255.0.213      -> illegal
154.253.86.183~255.200.255.0     -> illegal
94.164.187.131~255.255.0.0       -> A
167.79.164.186~255.0.0.0         -> B
194.172.2.64~255.255.0.0         -> C
210.212.79.137~255.255.255.42    -> Illegal
143.151.137.40~255.255.255.255   -> B
184.145.79.157~255.0.0.0         -> B
100.214.131.51~255.255.255.255   ->
233.10.182.98~255.0.0.125        ->
99.184.165.228~255.0.0.82        ->
92.20.159.86~255.0.0.0           ->
198.198.174.83~255.0.0.0         ->
17.158.122.89~255.255.75.255     ->
149.253.103.237~255.0.26.0       ->
91.243.182.7~255.0.0.0           ->
36.76.55.4~255.255.255.255       ->
126.54.86.143~255.0.0.0          ->
 */

/* 
42.53.252.112~255.0.0.0       
166.237.7.68~255.0.0.0        
136.3.73.64~255.255.0.0       
204.29.136.133~255.255.0.245  
195.30.208.94~255.255.0.213   
154.253.86.183~255.200.255.0  
94.164.187.131~255.255.0.0    
167.79.164.186~255.0.0.0      
194.172.2.64~255.255.0.0      
210.212.79.137~255.255.255.42 
143.151.137.40~255.255.255.255
184.145.79.157~255.0.0.0      
100.214.131.51~255.255.255.255
233.10.182.98~255.0.0.125     
99.184.165.228~255.0.0.82     
92.20.159.86~255.0.0.0        
198.198.174.83~255.0.0.0      
17.158.122.89~255.255.75.255  
149.253.103.237~255.0.26.0    
91.243.182.7~255.0.0.0        
36.76.55.4~255.255.255.255    
126.54.86.143~255.0.0.0       
 */