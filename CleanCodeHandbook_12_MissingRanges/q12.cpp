/* 
 * File:   main.cpp
 * Author: Simrat
 *
 * Created on December 3, 2014, 8:46 PM
 * Question:
 * Given a sorted integer array where the range of elements are [0, 99] inclusive,
 * return its missing ranges.
 */

#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

string to_string(int num) {
    if(num == 0) return string{'0'};
    int negative = num>=0? 0 : 1;
    num = num>0 ? num:-num;
    string ret;
    while(num) {
        ret.push_back(num%10 + '0');
        num = num/10;
    }
    if(negative) ret.push_back('-');
    reverse(ret.begin(), ret.end());
    return ret;
}

vector<string> findMissingRanges(int vals[], int n, int start, int end) {
    vector<string> ret;
    vector<int> seg;
    seg.push_back(start);
    for(int i = 0; i < n; ++i) {
        if(vals[i] < start || vals[i] > end) continue;          // to avoid out-of-range numbers.
        seg.push_back(vals[i]-1);
        seg.push_back(vals[i]+1);
    }

    seg.push_back(end);
    for(int i = 0; i < seg.size(); i+=2) {
        int st = seg[i];
        int ed = seg[i+1];
        if(st > ed) continue;
        else if (st == ed) ret.push_back(to_string(seg[i]));
        else ret.push_back(to_string(seg[i]) + "->" + to_string(seg[i+1]));
    }
    return ret;
}

int main() {
    int vals3[] = {};
    auto ret = findMissingRanges(vals3, 0, 0, 10);
    for(auto i:ret) cout << i << ' ';
    cout << endl;
    
    int vals[] = {0, 1, 3, 50, 75};
    ret = findMissingRanges(vals, sizeof(vals)/sizeof(vals[0]), 0, 99);
    for(auto i:ret) cout << i << ' ';
    cout << endl;
    
    int vals2[] = {0, 2, 4, 6, 8, 10};
    ret = findMissingRanges(vals2, sizeof(vals2)/sizeof(vals2[0]), 0, 10);
    for(auto i:ret) cout << i << ' ';
    cout << endl;
    
    int vals4[] = {100, 102, 104, 106, 108, 1010};
    ret = findMissingRanges(vals4, sizeof(vals4)/sizeof(vals4[0]), 0, 10);
    for(auto i:ret) cout << i << ' ';
    cout << endl;
    
    return 0;
}

