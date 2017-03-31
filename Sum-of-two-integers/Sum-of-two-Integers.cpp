class Solution {
public:
    int getSum(int a, int b) {
        
        // here we have to design out own adder
        // if we remember boolean logic, adder is designed using xor gate.
        // we can make a truth table for sum and carry and extract boolean logic from there
        //
        // |A|B|Carry_in|Sum|Carry_out|
        // |0|0|  0     | 0 |  0      |
        // |0|0|  1     | 1 |  0      |
        // |0|1|  0     | 1 |  0      |
        // |0|1|  1     | 0 |  1      |
        // |1|0|  0     | 1 |  0      |
        // |1|0|  1     | 0 |  1      |
        // |1|1|  0     | 0 |  1      |
        // |1|1|  1     | 1 |  1      |
        // From above truth table, we can see that sum = A xor B xor carry_in, carry_out = B.carry_in+A.carry_in+A.B+A.B.carry_in
        int sum = a ^ b;// cin is 0
        int carry_out = a&b; // since c_in is 0, rest of terms will be 0
        int temp_sum=0,temp_carry=0;
        // now resulting carry out bits needs to be shifted left by 1 and added back to the sum.
        // this process needs to continue till resultng carry out is 0
        while(carry_out!=0)
        {
            temp_carry = carry_out;
            temp_sum = sum;
            temp_carry = temp_carry<<1;
            sum = temp_sum ^ temp_carry; 
            carry_out = temp_sum&temp_carry;
        }
        return sum;
    }
};