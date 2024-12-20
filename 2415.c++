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
public:
    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return 0;
        bool isodd = false;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int s = q.size();
            vector<TreeNode*> v;
            for(int i = 0 ; i < s ; i++){
                TreeNode* temp = q.front();
                v.push_back(temp);
                q.pop();
                if(temp->left)q.push(temp->left);
                if(temp->right) q.push(temp->right);


            }
           
            if(isodd){
                int i = 0 ;
                int j = v.size()-1;
                while(i <= j){
                    int x = v[i]->val;
                    v[i]->val = v[j]->val;
                    v[j]->val = x;
                    i++;
                    j--;

                }
            }
            isodd = !isodd;
        }
        return root;
    }
};
