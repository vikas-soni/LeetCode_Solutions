
#include<assert.h>
class Solution {
public:
    int titleToNumber(string s) {
        // if null string return 0
        if(s.empty())
            return 0;
        // Value of A is 1 in LSB, 26 in 2nd position,26*26 in 3rd and so on
        int col_num=0;
        for(auto c:s)
        {
            // there is nothing fancy here. 
            // just a neat use of c-'A'+1 assuming all character are in caps in input
            // but i never like assuming anything, so i will add assert if see small cap alphabets
            if((c>='a') && (c<='z'))
            {
                assert(0 && "lower case alphabets encountered");
            }
            col_num=col_num*26+(c-'A'+1);
        }
        return col_num;
    }
};