class Solution {
public:
    int longestValidParentheses(string s) {
        int count=0, maxcount=0;
        stack<int>stk;
        stk.push(-1);
        for(int i=0; i<s.size(); i++){
            if(s[i]=='('){
                stk.push(i);
            }
            else{
                if(stk.top()==-1){
                    stk.push(i);
                }
                else{
                    if(s[stk.top()]=='('){
                        stk.pop();
                        count = (i-stk.top());
                        maxcount = max(maxcount, count);
                    }
                    else{
                        stk.pop();
                        stk.push(i);
                    }
                }
            }
        }
        maxcount = max(maxcount, count);
        return maxcount;
    }
};
