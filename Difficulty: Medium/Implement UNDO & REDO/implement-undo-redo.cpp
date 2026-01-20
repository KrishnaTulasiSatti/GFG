class Solution {
  public:
    
    string s = "";
    
    stack<char>st;
    
    void append(char x) {
        // append x into document
        s += x;
    }

    void undo() {
        // undo last change
        st.push(s[s.size()-1]);
        s.pop_back();
    }

    void redo() {
        // redo changes
        
        if(!st.empty()) {
            s += st.top();
            st.pop();
        } 
    }

    string read() {
        // read the document
        
        return s;
    }
};