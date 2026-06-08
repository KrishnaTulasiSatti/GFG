class Solution {
  public:
    
    int getPriority(char ch) {
        if(ch == '^') return 3;
        if(ch == '*' || ch == '/') return 2;
        if(ch == '+' || ch == '-') return 1;
        
        return 0;
    }
    string infixToPostfix(string& s) {
        // code here
        
        // Operand -- ans += operand
        // Operator -- pop the operators which have greater or equal precedence
        // and push it into the stack
        // If it is a open bracket , push it into the stack
        // If it is a close bracket, pop until ( is found and add the operators to ans
        
        stack<char>st;
        
        string res = "";
        
        for(int i = 0 ; i < s.size() ; i++) {
            
            if((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
                res += s[i];
            }
            else if(s[i] == '(') st.push(s[i]);
            else if(s[i] == ')') {
                while(!st.empty() && st.top() != '(') {
                    res += st.top();
                    st.pop();
                }
                
                if(!st.empty()) st.pop();
            }
            else {
                int pr = getPriority(s[i]);
                
                while(!st.empty() && 
                ((getPriority(st.top()) > pr) ||
       (getPriority(st.top()) == pr && s[i] != '^'))) {
                    res += st.top();
                    st.pop();
                }
                
                st.push(s[i]);
            }
        }
        
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        
        return res;
        
        
    }
};
