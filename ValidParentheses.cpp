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
