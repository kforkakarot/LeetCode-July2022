/*Both code work; My first solution , went bit of overboard with the solution, a lot of overlapping cases, i have also given the optimizes code below*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        if(numRows==1)
        {
            return {{1}};
        }
        if(numRows==2)
        {
            return {{1},{1,1}};
        }
        if(numRows>=3)
        {
            int arr[30][30]={0};
            arr[0][0]=1;
            arr[1][0]=1;
            arr[1][1]=1;
            for(int i=2;i<numRows;i++)
            {
                for(int j=0;j<=i;j++)
                {
                    if(j==0|| j==i)
                        arr[i][j]=1;
                    
                    else
                        arr[i][j]=arr[i-1][j-1]+arr[i-1][j];
                }
            }
            
            for(int i=0;i<numRows;i++)
            {   vector<int> temp;
                for(int j=0;j<=i;j++)
                {
                    temp.push_back(arr[i][j]);                 
                }
                res.push_back(temp);
            }
        }
        return res;
    }
};




/*Optimized code*/


class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> nums;
        for(int i=0;i<n;i++){
            vector<int> temp(i+1,1);
            nums.push_back(temp);
        }
        for(int i=2;i<n;i++){
            for(int j=1;j<i;j++){
                nums[i][j]=nums[i-1][j-1]+nums[i-1][j];
            }
        }
        return nums;
    }
};
