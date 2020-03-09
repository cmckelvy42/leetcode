#include <iostream>

using namespace std;

class Solution {
public:
    bool checkRecord(string s) {
        size_t numL = 0;
        size_t numA = 0;
        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == 'L')
                numL++;
            else
                numL = 0;
            if (s[i] == 'A')
                numA++;
            if (numL > 2 || numA > 1) 
                return (false);
            
        }
        return (true);
    }
};