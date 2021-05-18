class Solution {
public:
    int time = 0;
    void helper(int start, unordered_map<int, vector<int>>&mymap, vector<int>&discovery, vector<int>&low, vector<int>&parent, vector<bool>&stk, vector<vector<int>>&critical, vector<bool>&visited){
       if(visited[start]) return;
        visited[start] = true;
        stk[start] = true;
        discovery[start] = time;
        low[start] = time;
        time++;
        
        for(int ngbr:mymap[start]){
            if(ngbr!=parent[start] && !stk[ngbr]){
            // cout<<start<<"  "<<ngbr<<endl;
                parent[ngbr] = start;
                helper(ngbr, mymap, discovery, low, parent, stk, critical, visited);
                low[start] = min(low[ngbr], low[start]);
            }
            else if(ngbr==parent[start]) continue;
            else if(stk[ngbr]){
                // cout<<"Hello"<<start<<" "<<ngbr<<endl;
                low[start] = min(low[start], discovery[ngbr]);
            }
            if(discovery[start] < low[ngbr]){
                vector<int>temparr;
                temparr.push_back(start);
                temparr.push_back(ngbr);
                critical.push_back(temparr);
            }
        }
        stk[start] = false;
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>critical;
        unordered_map<int, vector<int>>mymap;
        vector<int>discovery(n, -1);
        vector<int>low(n, -1);
        vector<int>parent(n, -1);
        vector<bool>stk(n, false);
        vector<bool>visited(n, false);
        for(int i=0; i<connections.size(); i++){
            mymap[connections[i][0]].push_back(connections[i][1]);
            mymap[connections[i][1]].push_back(connections[i][0]);
        }
        for(int i=0; i<n; i++){
            if(!visited[i]){
                int time = 0;
                helper(i, mymap, discovery, low, parent, stk, critical, visited);
            }
        }
        // for(int i=0; i<n; i++){
        //     cout<<i<<" Discovery: "<<discovery[i] <<" Parent: "<<parent[i]<<" Low: "<<low[i]<<endl;
        // }
        return critical;
    }
};
