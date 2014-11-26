/*
 * Question:
 * Reverse words in a string 2:
 * If the input string does not contain leading or trailing spaces and the words
 * are separated by a single space, could you do it in-place without allocating 
 * extra space.
 *
 */

#include <iostream>
#include <cstring>
using namespace std;

/*
 * Algorithm: Reverse the whole string, then reverse each word separately.
 * Time complexity:         O(n)
 * Space complexity:        O(1)
 */
void rev(char* s, int begin, int end) {
    while(begin<end) swap(s[begin++], s[end--]);
}

void reverseWords(char* s) {
    int len = strlen(s);
    if(len <= 1) return;
    // reverse the whole string
    rev(s, 0, len-1);
    int low(0), high(0);
    for(; high < len; ++high) {
        if(s[high] != ' ') continue;
        while(s[low] == ' ') ++low;
        rev(s, low, high-1);
        low = high;
    }
    while(s[low] == ' ') ++low;
    rev(s, low, high-1);
}

int main() {
    char s[] = "a";
    reverseWords(&s[0]);
    cout << s << endl;
    char s2[] = "";
    reverseWords(&s2[0]);
    cout << s2 << endl;
    char s3[] = "come to me";
    reverseWords(&s3[0]);
    cout << s3 << endl;
    char s4[] = "The input string does not contain leading or trailing spaces and the words \
are always separated by a single space.";
    reverseWords(&s4[0]);
    cout << s4 << endl;
    return 0;
}