class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int maxLen = 0;

        unordered_set<int> st;

        for(int num:nums){
            st.insert(num);
        }

        for(int num:st){
            
            if(st.find(num-1) == st.end()){
                int x = num;
                int cnt=1;

                while(st.find(x+1) != st.end()){
                    cnt++;
                    maxLen = max(maxLen,cnt);
                    x++;
                }

                maxLen = max(maxLen,cnt);
            }

        }

        return maxLen;
    }
};
