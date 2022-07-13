class Solution {
public:
    
    
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        unordered_map<int,vector<int>> res;
        res[0].push_back(root->val);
    queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        int i=0;
        while(!q.empty())
        {   
            pair<TreeNode*,int> temp1=q.front();
            q.pop();
            TreeNode* temp=temp1.first;
            int level=temp1.second;
            if(temp->left!=NULL)
            {q.push({temp->left,level+1});
             res[level+1].push_back(temp->left->val);
            }
            
            if(temp->right!=NULL)
            {
                q.push({temp->right,level+1});
                res[level+1].push_back(temp->right->val);
            }
            
            
        }
        
        vector<vector<int>> res1;
        while(res.find(i)!=res.end()){
            vector<int> temp;
            for(auto j:res[i]){
                temp.push_back(j);
                }
            res1.push_back(temp);
            i++;
        }
        
        return res1;
    
    }
};
