class Solution {
public:

    //Enum used to keep track of the direction of the ZigZag
    enum direction{left = 0, right = 1};

    //Recursive Helper function for finding the longest ZigZag
    int longestZigZag(TreeNode* root, direction dir, int length){
        if(!root)
            return length;
        //if root != null increase length
        length++;

        //Get max length of Zigzags in both directions
        if(dir == left)
            length = max(longestZigZag(root->right, right, length), longestZigZag(root->left, left, 0));
        else
            length = max(longestZigZag(root->right, right, 0), longestZigZag(root->left, left, length));

        return length;
    }

    //Return the longest ZigZag in a binary tree
    int longestZigZag(TreeNode* root) {
        return max(longestZigZag(root->left, left, 0), longestZigZag(root->right, right, 0));
    }
};
