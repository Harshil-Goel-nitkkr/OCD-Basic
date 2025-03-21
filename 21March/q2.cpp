class Solution {
    public:
        int romanToInt(string s) {
            unordered_map<char,int> mp;
            mp['I'] = 1;
            mp['V'] = 5;
            mp['X'] = 10;
            mp['L'] = 50;
            mp['C'] = 100;
            mp['D'] = 500;
            mp['M'] = 1000;
            int prev = mp[s[0]];
            int ans = mp[s[0]];
            for(int i=1; i<s.size(); i++){
                int temp = mp[s[i]];
                if(prev<temp) ans -= 2*prev;
                ans += temp;
                prev = temp;
            }
            return ans;
        }
    };