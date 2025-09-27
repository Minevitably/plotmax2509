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
    void reverse(string &s, int start, int count) {
        if (start + count > s.size()) {
            count = s.size() - start;
        }
        for (int i = 0; i < count / 2; i++) {
            int left = start + i;
            int right = start + count - i - 1;
            char temp = s[left];
            s[left] = s[right];
            s[right] = temp;
        }
    }
public:
    string reverseWords(string s) {
        for (int i = 0; i < s.size(); i++) {
            int start = i;
            while (i < s.size() && s[i] != ' ') {
                i++;
            }
            reverse(s, start, i - start);
        }
        return s;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
