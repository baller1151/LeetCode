class Solution {
public:
    
    bool isCompleteTree(TreeNode* root) {
        queue<TreeNode*> nodes;
        nodes.push(root);
        TreeNode* temp;
        bool noMore = false;
        while(!nodes.empty()){
            temp = nodes.front();
            nodes.pop();
            if(noMore && temp) return false;
            if(temp == NULL) noMore = true;
            else{
                nodes.push(temp->left);
                nodes.push(temp->right);
            }
        }
        return true;
    }
};
