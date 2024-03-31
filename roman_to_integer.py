class Solution:
    roman_value = {
            'IV': 4,
            'IX': 9,
            'I' : 1,
            'V' : 5,
            'XL': 40,
            'XC': 90,
            'X' : 10,
            'L' : 50,
            'CD': 400,
            'CM': 900,
            'C' : 100,
            'D' : 500,
            'M' : 1000
        }

    def romanToInt(self, s: str) -> int:
        sum = 0
        string_length = len(s)
        i = 0
        while (i < string_length):
            if i < string_length - 1 and s[i:i+2] in self.roman_value:
                sum += self.roman_value.get(s[i:i+2])
                i += 2
            else:
                sum += self.roman_value.get(s[i])
                i += 1
        return sum


'''
('I', 'V', 'X', 'L', 'C', 'D', 'M')
1 I
2 II
3 III
4 IV ***
5 V
6 VI
7 VII
8 VIII
9 IX ***
10 X
20 XX
30 XXX
40 XL ***
50 L
60 LX
70 LXX
80 LXXX
90 XC ***
100 C
200 CC
300 CCC
400 CD ***
500 D
600 DC
700 DCC
800 DCCC
900 CM ***
1000 M
1100 MC
'''

def main():
    solution = Solution()
    string = input("Roman to convert: ")
    value = solution.romanToInt(string)
    print(value)

if __name__ == "__main__":
    main()