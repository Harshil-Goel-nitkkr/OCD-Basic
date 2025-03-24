class Solution {
    public:
        int minAddToMakeValid(string s) {
            int oc = 0, cc = 0;
            int i=0;
            int ans = 0;
            while(i<s.size()){
                if(s[i]=='(') oc++;
                else{
                    if(oc==cc){
                        ans++;
                        oc++;
                    }
                    cc++;
                }
                i++;
            }
            ans += oc - cc;
            return ans;
        }
    };