class Solution {
public:
    static long long int max(int a,int b)
    {
        return a>=b?a:b;
    }
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        sort(horizontalCuts.begin(),horizontalCuts.end());
        sort(verticalCuts.begin(),verticalCuts.end());
        long long int horizontal;
        long long int max1=INT_MIN;
        long long int i,j;
        if(horizontalCuts.size()>1)
        {    for(i=1;i<horizontalCuts.size();i++)
            {
                if(i==1)
                    max1=max(horizontalCuts[0]-0,max1);
                max1=max(horizontalCuts[i]-horizontalCuts[i-1],max1);
            }
            max1=max(h-horizontalCuts[horizontalCuts.size()-1],max1);
        }
        
        else{
            max1=max(horizontalCuts[0]-0,h-horizontalCuts[0]);
        }
        long long int vertical;
        long long int max2=INT_MIN;
        
        if(verticalCuts.size()>1)
        {    for(j=1;j<verticalCuts.size();j++)
            {   
                if(j==1)
                    max2=max(verticalCuts[0]-0,max2);
                max2=max(verticalCuts[j]-verticalCuts[j-1],max2);
            }
            max2=max(w-verticalCuts[verticalCuts.size()-1],max2);
        }
        else{
            max2=max(verticalCuts[0]-0,w-verticalCuts[0]);
        }
        return (max1*max2)%(1000000007);
    }
};
