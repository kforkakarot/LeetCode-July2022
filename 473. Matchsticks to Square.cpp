class Solution {
public:
    bool help(vector<int> arr,int target,vector<int> &square,int index)
    {
        if(index==arr.size())
        {
            if((square[0] == square[1]) && (square[1]==square[2]) && (square[2]==square[3]))
            {
                return true;
            }
                
            return false;
        }
        
        for(int i=0;i<4;i++)
        {
            if(square[i]+arr[index]>target)
            {
               continue; 
            }  
            
            int j=i-1;
            while(j>=0)
            {
                if(square[j]==square[i])
                {
                     break;
                }   
                j-=1;
            }
            if(j!=-1)
            {
                continue;
            }    
            
            square[i]+=arr[index];
            if( help(arr,target,square,index+1) )
            {
                return true;
            }
            square[i]-=arr[index];
        }
        return false;
    }
    
    bool makesquare(vector<int>& matchsticks) {
        if(matchsticks.size()==0)
            return false;
        
        
        int sum=0;
        for(int i=0;i<matchsticks.size();i++)
        {
            sum+=matchsticks[i];
        }
        int target=sum/4;
        vector<int> square(4,0);
        sort(matchsticks.begin(),matchsticks.end(),greater<int>());
        
        return help(matchsticks,target,square,0);
    }
};
