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
    char highFourBitsToHexStr(int val) {
        int v = (val >> 28) & 0xF;
        ostringstream oss;
        if (v < 10) {
            return (char)(v + '0');
        } else {
            return (char)(v - 10 + 'a');
        }
    }
public:
    string toHex(int num) {
        string res;
        for (int i = 0; i < 8; i++) {
            char ch = highFourBitsToHexStr(num << (i * 4));
            if (res.empty() && ch == '0' && i != 7) {
                continue;
            }
            res += ch;
        }
        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
