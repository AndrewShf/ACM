/* other people's solution, in this case, I learn more about hash table*/

/*
Design a data structure that supports all following operations in average O(1) time.

insert(val): Inserts an item val to the set if not already present.
remove(val): Removes an item val from the set if present.
getRandom: Returns a random element from current set of elements. 
    Each element must have the same probability of being returned.
*/

/*
Suprisingly the hash map is for keep the position of element in the vector.
Meanwhile, it serves to check if the particular element is in it or not.

the vector serves as the array to place the element.

insert: see in the hash table, if the ans is no, put it in the vector, and record its
position in the hash table

delete: see in the hash table, if the element is in there, get the position through hash
table, and so as follows.

Suppose you have a vector

0 1 2 3 4 5 6
and you want to remove the 3. You can turn this into

0 1 2 6 4 5
in O(1) without any issues.

Here is the pseudo-code

If the element you are trying to remove is the last element in the vector, remove it, done.
Read the last element of the vector and write it over the element-to-be-removed.
Remove the last element of the vector.

*/

class RandomizedSet {
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end()) return false;
        nums.emplace_back(val);
        m[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        int last = nums.back();
        m[last] = m[val];
        nums[m[val]] = last;
        nums.pop_back();
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
private:
    vector<int> nums;
    unordered_map<int, int> m;
};