class Solution {
public:
    int addDigits(int num) {
        // here if we do this add digits manually for few numbers lets say from 1-30 (also try few 3 and 4 digits numbers,
        // we will be able to understand that there is a pattern.
        // we see that if a number is multiple of 9, then the add digits is 9 always
        // when number is not a multiple of 9, then result is number%9.
        if(num == 0)
            return 0;
        if(num%9 == 0)
            return 9;
        else
            return (num%9);
    }
};