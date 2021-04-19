class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        int level = 1, size=1, sum=0;
        queue<TreeNode*>que;
        que.push(root);
        while(que.size()!=0){
            TreeNode* top = que.front();
            que.pop();
            sum+=top->val;
            if(top->right !=NULL){
                que.push(top->right);
            }
            if(top->left !=NULL){
                que.push(top->left);
            }
            size--;
            if(size== 0){
                if(que.size()==0) return sum;
                else{
                    size= que.size();
                    level++;
                    sum=0;
                }
            }
        }
        return sum;
    }
};
