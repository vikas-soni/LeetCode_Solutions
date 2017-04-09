#include<climits>
#include<cmath>

class Solution {
public:
    int reverse(int x) {
        // process to reverse a number is simple
        // we simply take remainder with 10 and multiply it by 10
        // add it to current result. do this until original number/10 is not 0
        // but to take care of underflow/overflow needs some careful coding
        
        // take care of corner case
        if(x==0)
            return x;
        // this case is imp
        if((x==INT_MAX) || (x==INT_MIN))
            return 0;
            
        // get the sign of x
        bool is_neg=false;
        if(x<0)
            is_neg = true;
        x=abs(x);
        // we will do all calculations in double so that we can compare it to INT_MAX when number overflows
        double result=0;
        while(x!=0)
        {
            double rem = x%10;
            result = result*10+rem;
            // this is clever work here. we need to check if result became more than INT_MAX
            if(result>=INT_MAX)
                return 0;
            x=x/10;
        }
        if(is_neg)
            result = 0-result;
        return result;
    }
};