from typing import List

def is_valid_mask_part(part: str) -> bool:
    return int(part) in (
        0b11111111,
        0b11111110,
        0b11111100,
        0b11111000,
        0b11110000,
        0b11100000,
        0b11000000,
        0b10000000,
        0b00000000
    )


def main():
    type_a = 0
    type_b = 0
    type_c = 0
    type_d = 0
    type_e = 0
    illegals = 0
    private_ip = 0

    while True:
        try:
            ip, mask = input().split('~')
        except:
            break
        """
        Check IP, if fails, skip rest
        - empty part
        - part is not number
        - part out of scope
        Check Mask for non special, if fails, skip rest
        - empty part
        - part is not number
        - part out of scope
        - part is not valid mask value
        - 1 after 0
        - all 1s or all 0s
        Count types
        Count private
        """
        # Check IP
        ip: List[str] = ip.split('.')
        ip_or_mask_is_illegal: bool = False
        if len(ip) != 4:
            illegals += 1
            continue
        for part in ip:
            if len(part) == 0 \
                    or not part.isdigit() \
                    or int(part) < 0 or int(part) > 255:
                illegals += 1
                ip_or_mask_is_illegal = True
                break
        if ip_or_mask_is_illegal:
            continue

        # Skip checking mask and counting type and private for special IP's
        if int(ip[0]) == 0 or int(ip[0]) == 127:
            continue

        # Check mask
        mask: List[str] = mask.split('.')
        zero_appeared: bool = False
        if len(mask) != 4:
            illegals += 1
            continue
        for part in mask:
            if len(part) == 0 \
                    or not part.isdigit() \
                    or int(part) < 0 or int(part) > 255 \
                    or not is_valid_mask_part(part) \
                    or (zero_appeared and int(part) != 0):
                illegals += 1
                ip_or_mask_is_illegal = True
                break
            if int(part) != 0b11111111:
                zero_appeared = True
        if mask[0] == mask[1] == mask[2] == mask[3] \
                and (mask[0] == "0" or mask[0] == "255"):
            illegals += 1
            ip_or_mask_is_illegal = True

        if ip_or_mask_is_illegal:
            continue

        if 1 <= int(ip[0]) <= 126:
            type_a += 1
        elif 128 <= int(ip[0]) <= 191:
            type_b += 1
        elif 192 <= int(ip[0]) <= 223:
            type_c += 1
        elif 224 <= int(ip[0]) <= 239:
            type_d += 1
        elif 240 <= int(ip[0]) <= 255:
            type_e += 1
        
        if ip[0] == "10" \
                or (ip[0] == "172" and 16 <= int(ip[1]) <=31) \
                or (ip[0] == "192" and ip[1] == "168"):
            private_ip += 1
    
    print(f"{type_a} {type_b} {type_c} {type_d} {type_e} {illegals} {private_ip}")

        

if __name__ == "__main__":
    main()