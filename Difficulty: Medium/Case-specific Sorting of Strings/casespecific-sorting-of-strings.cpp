class Solution {
  public:
    string caseSort(string& s) {
        // code here
        vector<int>frql(26,0);
        vector<int>frqu(26,0);
        
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] >= 'a' && s[i] <= 'z') frql[s[i]-'a']++;
            else frqu[s[i]-'A']++;
        }
        int a = 0;
        int b = 0;
        
        for(int i = 0 ; i < s.size() ; i++) {
            if(s[i] >= 'a' && s[i] <= 'z') {
                
                while(frql[a] == 0) a++;
                
                s[i] = a+'a';
                frql[a]--;
                
            }
            else {
                while(frqu[b] == 0) b++;
                
                s[i] = b+'A';
                frqu[b]--;
            }
        }
        
        return s;
    }
};