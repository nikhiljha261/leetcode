class Solution {
public:
    int ans=INT_MIN;
    int dfs(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        int lt=max(0,dfs(root->left));
        int rt=max(0,dfs(root->right));
        ans=max(lt+rt+root->val,ans);
        return max(lt,rt)+root->val;
    }
    int maxPathSum(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
