#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>

using namespace std;


class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b ? -1 : std::max(a.size(), b.size());
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
