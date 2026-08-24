class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 1) return strs[0];

        string longestCommonPrefix = "";

        for(int i=1;i<strs.size();i++){

            int j = 0;
            string a = strs[i-1];
            string b = strs[i];

            if( a== "" || b == ""){
                return "";
            }

            string commonPrefix = "";
            int n = min(a.size(),b.size());

            while(j<n){
                if(a[j] != b[j]) break;
                else commonPrefix += a[j];
                
                j++;
            }

            if(longestCommonPrefix != ""){
                longestCommonPrefix = min(commonPrefix,longestCommonPrefix);
            }else{
                longestCommonPrefix = commonPrefix;
            }

        }

        return longestCommonPrefix;
    }
};