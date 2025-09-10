#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>

using namespace std;

class Solution {
private:
    /**
     * find ch in s, return index of ch
     * range [start, s.size() - 1]
     * @param s
     * @param start
     * @param ch
     * @return
     */
    int find(string s, int start, char ch) {
        for (int i = start; i < s.size(); i++) {
            if (s[i] == ch) {
                return i;
            }
        }
        return -1;
    }
public:
    bool isSubsequence(string s, string t) {
        if (s.size() > t.size()) {
            return false;
        }
        int j = 0;
        for (char ch: s) {
            j = find(t, j, ch);
            if (j == -1) {
                return false;
            } else {
                j++;
            }
        }
        return true;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
