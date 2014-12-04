/* 
 * File:   q7_challenge2.cpp
 * Author: Simrat
 *
 * Created on November 25, 2014, 6:44 PM
 * Question: 
 * Rotate an array to the right by k steps in place without allocating extra
 * space. For instance, with k = 3, the array [0, 1, 2, 3, 4 ,5, 6] is rotated
 * to [4, 5, 6, 0, 1, 2, 3].
 */

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void rotateStringToTheRight(string &s, int n) {
    if(s.size() <= 1 || !(n % s.size()) ) return;
    n = n % s.size();
    
    // reverse the whole string
    for(int low(0), high(s.size()-1); low < high; swap(s[low++], s[high--]));
    // reverse the first n char
    for(int low(0), high(n-1); low < high; swap(s[low++], s[high--]));
    // reverse the remaining chars
    for(int low(n), high(s.size()-1); low < high; swap(s[low++], s[high--]));
}

/*
 * 
 */
int main() {
    string s = "";
    rotateStringToTheRight(s, 1);
    cout << s << endl;
    
    s = "a";
    rotateStringToTheRight(s, 13);
    cout << s << endl;
    
    s = "0123456";
    rotateStringToTheRight(s, 3);
    cout << s << endl;
    
    s = "0123456";
    rotateStringToTheRight(s, 3428);
    cout << s << endl;
    
    
    return 0;
}

