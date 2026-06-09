class Solution {
  public:
    bool canSeatAllPeople(int k, vector<int> &seats) {
        // code here
        
        int n = seats.size();
        
        for(int i = 0 ; i < n ; i++) {
            
            int p1 = 0;
            int p2 = 0;
            
            if(i-1 >= 0) p1 = seats[i-1];
            if(i+1 < n) p2 = seats[i+1];
            
            if(seats[i] == 0 && p1 == 0 && p2 == 0) {
                seats[i] = 1;
                k--;
            }
            
        }
        if(k <= 0) return true;
        return false;
    }
};