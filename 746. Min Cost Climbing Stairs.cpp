class Solution {
public:
     int minCostClimbingStairs(vector<int>& cost,int index, vector<int> &memo){
        if(index==cost.size()-1 || index==cost.size()-2){
            return cost[index];
        }
        if(memo[index]!=0){
            return memo[index];
        }
        int x=minCostClimbingStairs(cost,index+1, memo);    
        int y=minCostClimbingStairs(cost,index+2, memo); 
        memo[index]=min(x,y)+cost[index];
        return memo[index];
        
    }
    
    int minCostClimbingStairs(vector<int>& cost) {
        if(cost.size()==2){
            return min(cost[0],cost[1]);
        }
        vector<int> memo(1001);
        int x=minCostClimbingStairs(cost,0,memo);
        int y=minCostClimbingStairs(cost,1,memo);
        return min(x,y);
    }
};
