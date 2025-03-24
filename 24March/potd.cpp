class Solution {
    public:
        static bool comp(vector<int>& a, vector<int>& b){
            return a[0]<b[0];
        }
        int countDays(int days, vector<vector<int>>& meetings) {
            sort(meetings.begin(),meetings.end(),comp);
            int count = meetings[0][0]-1;
            int curr = meetings[0][1];
            for(int i=1; i<meetings.size(); i++){
                if(meetings[i][0]>curr){
                    count += meetings[i][0]-curr-1;
                }
                curr = max(curr,meetings[i][1]);
            }
            count += days - curr;
    
            return count;
    
        }
    };