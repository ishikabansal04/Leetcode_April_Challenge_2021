class Solution {
public:
    
    void helper(string ques, string ans, vector<string>&result, vector<string>&alphabets){
        if(ques.size()==0){
            result.push_back(ans);
            return;
        }
        int ch=ques[0]-'0';
        for(int i=0; i<alphabets[ch].length(); i++){
            string temp = ans+ alphabets[ch][i];
            helper(ques.substr(1), temp, result, alphabets);
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string>alphabets={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>result;
        if(digits.size()==0) return result;
        helper(digits, "", result, alphabets);
        return result;
    }
};
