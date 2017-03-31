class Solution {
public:
    int hammingWeight(uint32_t n) {
        
        // brute force method is to simply count no of bits by right shifting the number by 1,
        // and checking the LSB for 1.
        // There is a faster approach as well
        // Idea is when we substract 1 from a number, the first 1 bit from LSB becomes 0 and all the other
        // bits till LSB becomes 1.
        // for example. decimal 12 = 1100 in binary
        // 12-1 = 11 = 1011
        // hence we can keep substracting 1 from the number and take its logical and with the original number
        
        if(n==0)
            return 0;
        int total_ones=0;
        while(n!=0)
        {
            ++total_ones;
            n=n&(n-1);
        }
        return total_ones;
    }
};