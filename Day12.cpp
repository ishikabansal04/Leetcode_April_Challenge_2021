class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int>result;
        int i=1, j=n, x=1;
        bool res=true;
        
        for(x=1; x<=(k/2); x++){
            // cout<<i<<"  "<<j<<endl;
            result.push_back(i);
            if(i!=j){
                 result.push_back(j);
            }
            i++;
            j--;
        }
        if(k%2==0){
            for(;j>=i; j--){
                result.push_back(j);
            }
        }
        else{
            for(;i<=j; i++){
                result.push_back(i);
            }
        }
        return result;
    }
};
