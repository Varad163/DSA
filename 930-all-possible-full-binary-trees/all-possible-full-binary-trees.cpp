/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    private:
    unordered_map<int, vector<TreeNode*>> memo;
public:
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0)return {};

        if(n==1)return {new TreeNode(0)};

        if(memo.find(n)!=memo.end()){
            return memo[n];
        }

        vector<TreeNode*> res;

        for(int i=1;i<n;i+=2){
            vector<TreeNode*> leftSubtrees=allPossibleFBT(i);
            vector<TreeNode*> rightSubtrees = allPossibleFBT(n -1-i);

            for(auto left:leftSubtrees){
                for(auto right:rightSubtrees){
                    TreeNode* root=new TreeNode(0,left,right);
                    res.push_back(root);
                }
            }
        }
        return memo[n]=res;
    }
};