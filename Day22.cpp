class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int>mymap;
        for(int i=0; i<wall.size(); i++){
            int sum = 0;
            for(int j=0; j<wall[i].size()-1; j++){
                sum = sum + wall[i][j];
                mymap[sum]+=1;
            }
        }
        int maxidx = 0, maxnum = 0;
        unordered_map<int, int>:: iterator it = mymap.begin();
        while(it!= mymap.end()){
            // cout << it->first <<"   " << it->second <<endl;
            if(maxnum < it->second){
                // cout<<"Hello"<<endl;
                maxnum = it->second;
                maxidx = it->first;
            }
            it++;
        }
        return wall.size()-maxnum;
    }
};
