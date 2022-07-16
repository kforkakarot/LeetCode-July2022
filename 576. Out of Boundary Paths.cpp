/*DP optimizes solution*/

class Solution {
public:
    int memo[51][51][51];
    long mod=pow(10,9)+7;
    long solve(int row,int col,int i,int j,int moves)
    {  if(i<0 || i>=row || j<0 || j>=col )
            return 1;
     
        if(moves<=0 )
            return 0;  
     
        if(memo[i][j][moves]!=-1)
            return memo[i][j][moves];
     
        long res=0;
        res+=solve(row,col,i-1,j,moves-1);        
        res+=solve(row,col,i+1,j,moves-1);
        res+=solve(row,col,i,j-1,moves-1);
        res+=solve(row,col,i,j+1,moves-1);
        return memo[i][j][moves]=res%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(memo,-1,sizeof(memo));
        return solve(m,n,startRow,startColumn,maxMove);
        
    }
};
