class Solution
{
public:
    int minOperations(vector<int> &nums)
    {
        int i = 0;
        int count = 0;
        while (i + 2 < nums.size())
        {
            if (!nums[i])
            {
                count++;
                int next = i;
                int j;
                for (j = i; j < i + 3; j++)
                {
                    if (!(nums[j] = !nums[j]) && next == i)
                        next = j;
                }
                i = (next == i) ? j : next;
            }
            else
                i++;
        }
        if (nums[nums.size() - 1] && nums[nums.size() - 2])
            return count;
        return -1;
    }
};