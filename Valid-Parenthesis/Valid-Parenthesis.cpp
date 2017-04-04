#include<stack>
class Solution {
public:
    bool isValid(string s) {
        // this is a classsic question on use of stack.
        // what we will do is to push the character '(','{' and '[' on stack whenever we encounter it
        // if we see a closing brace, we do not push it on stack. instead we pop a brace from stack and see if that matches the opening brace version of the closing brace we encountered. if not then its not a valid parenthesis. We continue this process till the sring is finished.
        // once string is finished, we should have our stack empty else its a invalid case.
        std::stack<char> my_stack;
        int len = s.size();
        if(len<=1)
            return false;
        
        for(auto c:s)
        {
            cout<<"\n char is "<<c;
            if((c=='(') || (c=='{') || (c=='['))
            {
                my_stack.emplace(c);
            }
            else if((c==')') || (c=='}') || (c==']'))
            {
                if(my_stack.empty())
                    return false;
                cout<<"\n stack top is "<<my_stack.top();
                if(!(((my_stack.top()=='(') && (c==')')) ||
                ((my_stack.top()=='{') && (c=='}')) ||
                ((my_stack.top()=='[') && (c==']'))))
                    return false;
                my_stack.pop();
            }
            else
                return false;
        }
        if(my_stack.size()!=0)
            return false;
        else
            return true;
    }
};