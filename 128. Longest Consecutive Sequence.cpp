class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int i=0;i<nums.size();i++)
            set.insert(nums[i]);
        
        int res=0;
        for(int i=0;i<nums.size();i++)
        {
            if(set.find(nums[i]-1)!=set.end())
                continue;
            
            else{
                int current=nums[i];
                int count=0;
                while(set.find(current)!=set.end())
                {
                    count++;
                    current++;
                }
                res=max(res,count);
            }
        }
        return res;
        
    }
};
