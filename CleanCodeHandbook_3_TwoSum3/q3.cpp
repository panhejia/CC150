/*
 * Question:
 * Design and implement a TwoSum class. It should support the following operations: add
 * and find.
 * 
 * add(input) – Add the number input to an internal data structure.
 * find(value) – Find if there exists any pair of numbers which sum is equal to the value.
 * 
 * For example,
 * add(1); add(3); add(5); find(4) -> true; find(7) -> false
 */

#include <iostream>
#include <set>
#include <map>
#include <vector>
using namespace std;

/*
 * Naive method
 * Time complexity: Add: O(n), Find O(1), Space O(n^2)
 * Algorithm:       Use a hashmap and a data vector
 * Pros:            Find will be fast. Good if find is used frequently
 * Cons:            Slow add, large space requirement.
 */
class type1 {
public:
    vector<int> dataVector;
    set<int> combinationSet;    // o(n^2)
    
    void add(int x) {   // O(n)
        for(auto e:dataVector) combinationSet.insert( e + x );
        dataVector.push_back(x);
    } 
    
    bool find(int x) {
        return combinationSet.count(x);
    }
};

/*
 * Binary search + Two pointers
 * Time complexity: Add O(logn), Find O(n), Space O(n)
 * Algorithm:       Use sorted array to store data. Use O(n) algorithm to do
 *                  find. 
 *                      -----But how can you do logn time array insertion??
 */
class type2 {
    // TODO: ??
};

/*
 * Single hash table
 * Time complexity: Add O(1), Find O(n), Space O(n)
 * Algorithm:       Yet another naive method. Store all elements in a single
 *                  hash table. When doing find operation, user loops through
 *                  all hash table elements and find the complement element.
 *                  Be careful there might be duplicates.
 * Pros:            Fast insertion.
 */
class type3 {
public:
    map<int, int> dataSet;      // value, count
    
    void add(int x) {   // O(1)
        dataSet[x]++;
    }
    
    bool find(int x) {
        bool found = false;
        for(auto i:dataSet) {
            int complement = x - i.first;
            found = found || ((complement == i.first) ? (i.second-1 > 0) : dataSet.count(complement));
        }
        return found;
    }
};

int main() {
    type1 t1;
    t1.add(0); t1.add(1);
    cout << t1.find(0) << '\n' << t1.find(1) << endl;
    t1.add(2);
    cout << t1.find(1) << '\n' << t1.find(2) << endl;
    
    type3 t3;
    t3.add(0);
    cout << t3.find(0) << endl;
    t3.add(0);
    cout << t3.find(0) << endl;
    t3.add(1);
    cout << t3.find(1) << '\n' << t3.find(2) << endl;
    
    return 0;
}

