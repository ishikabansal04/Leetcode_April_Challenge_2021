class Solution {
public:
    unordered_map<char, int>mymap;
    bool compare(string& s1, string& s2){
        for(int i=0; i<min(s1.size(), s2.size()); i++){
            if(s1[i]==s2[i]) continue;
            else if(mymap[s1[i]]>mymap[s2[i]]) return false;
            else{
                return true;
            }
        }
        return s1.size()<=s2.size();
    }
    
    bool isAlienSorted(vector<string>& words, string order) {
        for(int i=0; i<order.length(); i++){
            mymap[order[i]]=i;
        }
        for(int j=0; j<words.size()-1; j++){
            bool res = compare(words[j], words[j+1]);
            if(res==false) return false;
        }
        
        return true;
    }
};
