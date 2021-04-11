class Solution {
public:
    int countVowels(string subs,unordered_map<char, bool>&mymap){
        int count = 0;
        for(int i=0; i<subs.length(); i++){
            char ch= subs[i];
            if(mymap.count(ch)) count++;
        }
        return count;
    }
    
    bool halvesAreAlike(string s) {
        unordered_map<char, bool>mymap;
        mymap['a']=true;
        mymap['e']=true;
        mymap['i']=true;
        mymap['o']=true;
        mymap['u']=true;
        mymap['A']=true;
        mymap['E']=true;
        mymap['I']=true;
        mymap['O']=true;
        mymap['U']=true;
        int len=s.length();
        int leftcount = countVowels(s.substr(0, len/2), mymap);
        int rightcount = countVowels(s.substr(len/2), mymap);
        cout<<leftcount<<"  "<<rightcount<<endl;
        return leftcount == rightcount;
    }
};
