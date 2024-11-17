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
    void test(TreeNode *p, TreeNode* q, vector<int>&v){
        if(p==NULL && q!=NULL){
            v.push_back(0);
            return;
        }else if(q==NULL && p!=NULL){
            v.push_back(0);
            return;
        }else if(p==NULL && q==NULL){
            v.push_back(1);
            return;
        }else if(p->val != q->val){
            v.push_back(0);
            return;
        }
        test(p->left,q->left,v);
        test(p->right,q->right,v);
       
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        vector<int>vec;
        test(p,q,vec);
        sort(vec.begin(),vec.end());
        if(vec[0]==0){
            return 0;
        }else{
            return 1;
        }
    }
};