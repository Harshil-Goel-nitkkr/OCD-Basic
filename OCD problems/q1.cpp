class Solution
{
public:
    string removeOuterParentheses(string s)
    {
        string ans = "";
        int i = 0, j = 1;
        int oc = 1, cc = 0;
        while (j < s.size())
        {
            if (s[j] == '(')
                oc++;
            else
                cc++;
            if (oc == cc)
            {
                i++;
                while (i < j)
                    ans += s[i++];
                i = j + 1;
                oc = cc = 0;
            }
            j++;
        }
        return ans;
    }
};