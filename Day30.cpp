class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        if(bound<=1) return {};
        else if(x==1 && y==1) return {2};
        else if(x==1){
            vector<int>base;
            for(int j=0; pow(y, j)+1 <=bound; j++){
                base.push_back(pow(y,j)+1);
            }
            return base;
        }
        else if(y==1){
            vector<int>base;
            for(int j=0; pow(x, j)+1 <=bound; j++){
                base.push_back(pow(x,j)+1);
            }
            return base;
        }
        else{
            unordered_map<int, bool>mymap;
            vector<int>result;
            for(int i=0; pow(x, i)<=bound; i++){
                for(int j=0; pow(y, j)<=bound; j++){
                    int res = pow(x,i)+ pow(y, j);
                    if(res<=bound && mymap.count(res)==0) {
                        result.push_back(res);
                        mymap[res] = true;
                    }
                }
            }
            sort(result.begin(), result.end());
            return result;
        }
    }
};
