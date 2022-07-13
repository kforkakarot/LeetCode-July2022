lass Solution {
public:
    // vector<int> res;
    void fun(TreeNode* temp,int level,vector<int>& res)
    {
        if(temp==NULL)
            return;
        if(level==res.size())
            res.push_back(temp->val);
        
        fun(temp->right,level+1,res);
        fun(temp->left,level+1,res);
    }
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
            return{};
        
        vector<int> res;
        fun(root,0,res);
        return res;
    }
};
