class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char, int>>stk;
        int i=0;
        while(true){
            if(i == s.length()){
                break;
            }
            if(stk.size()==0 || stk.top().first!=s[i]){
                stk.push(make_pair(s[i], 1));
            }
            else if(stk.top().first == s[i] && stk.top().second<k){
                pair rpair = stk.top();
                stk.pop();
                int newval = rpair.second+1;
                if(newval < k)
                    stk.push(make_pair(s[i], newval));
            }
            i++;
        }
        string res="";
        while(stk.size()!=0){
            pair rpair = stk.top();
            stk.pop();
            for(int j=0; j<rpair.second; j++)
                res = rpair.first + res;
        }
        return res;
    }
};
