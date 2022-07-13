class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()<2)
            return nums.size();
        int diff=nums[1]-nums[0];
        int count=diff!=0?2:1;
        for(int i=2;i<nums.size();i++)
        {   int diff1=nums[i]-nums[i-1];
            if((diff1 > 0 && diff<=0)||(diff1 < 0 && diff>=0))
            {
                count++;
                diff=diff1;
            }
        }
    
        return count;
    }
    
};
