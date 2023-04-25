/*
You are given the root of a binary tree.

A ZigZag path for a binary tree is defined as follow:

Choose any node in the binary tree and a direction (right or left).
If the current direction is right, move to the right child of the current node; otherwise, move to the left child.
Change the direction from right to left or from left to right.
Repeat the second and third steps until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. (A single node has a length of 0).

Return the longest ZigZag path contained in that tree.
*/
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
