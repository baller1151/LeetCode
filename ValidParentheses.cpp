/*
Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.
*/

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        char top;
        for(auto x : s){
            if(x == '{' || x == '[' || x == '(')
                st.push(x);
            else{
                if(st.empty())
                    return false;
                top = st.top();
                st.pop();
                if((top == '{' && x!= '}')||(top == '[' && x!= ']')||(top == '(' && x != ')'))
                    return false;
            }
        }
        
        return st.empty();
    }
};
