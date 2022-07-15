//bfs based solution , there is also a dfs based solution which has lines of code

class Solution {
public:
    
    int vis[50][50]={0};
    bool isvalid(int i,int j,vector<vector<int>>& grid)
    {
        if(i>=0 && j>=0 && i<grid.size() && j<grid[0].size() && vis[i][j]==0 && grid[i][j]==1)
            return true;
        return false;
    }
    int bfs(int i, int j,vector<vector<int>>& grid)
    {   int area=0;
        pair<int,int> p={i,j};
        queue<pair<int,int>> q;
        q.push(p);
        vis[i][j]=1;
        
        while(!q.empty())
        {
            pair<int,int> temp=q.front();
            q.pop();
            area+=1;
            int i=temp.first;
            int j=temp.second;
             
            if(isvalid(i-1,j,grid))
            {
              vis[i-1][j]=1;
              q.push({i-1,j});  
            }          
            
            if(isvalid(i,j-1,grid))
             {
              vis[i][j-1]=1;
              q.push({i,j-1});  
            }
            if(isvalid(i,j+1,grid))
             {
              vis[i][j+1]=1;
              q.push({i,j+1});  
            }
            if(isvalid(i+1,j,grid))
             {
              vis[i+1][j]=1;
              q.push({i+1,j});  
             }
            
            
        }
        return area;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area=0,count=0;
        
        int n=grid.size();
        for(int i=0;i<50;i++)
            for(int j=0;j<50;j++)
                vis[i][j]=0;
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1 && vis[i][j]==0)
                {   
                    count=bfs(i,j,grid);
                }
                area=max(area,count);
                
            }
            
            
        }
        return area;
        
    }
};
