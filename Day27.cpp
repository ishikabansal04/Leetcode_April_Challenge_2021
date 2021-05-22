class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        bool flag = true;
        while(n>1){
            int rem = n % 3;
            cout << rem << endl;
            n = n/3;
            if(rem!=0){
                flag = false;
                break;
            }
        }
        return flag;
    }
};
