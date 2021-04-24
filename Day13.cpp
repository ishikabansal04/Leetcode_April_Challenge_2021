/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
public:
    
    vector<int>result;
    int idx=0;
    
    void helper(NestedInteger x){
        if(x.isInteger()){
            result.push_back(x.getInteger());
        }
        else{
            for(auto i: x.getList()){
                helper(i);
            }
        }
    }
    
    NestedIterator(vector<NestedInteger> &nestedList) {
        for(int i=0; i<nestedList.size(); i++){
            NestedInteger value = nestedList[i];
            helper(value);
        }   
    }
    
    int next() {
        int val;
        if(idx<result.size()){
            val=result[idx];
            idx++;
        }
        return val;
    }
    
    bool hasNext() {
        if(idx<result.size()){
            return true;
        }
        return false;
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */
