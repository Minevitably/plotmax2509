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
    int distributeCandies(vector<int> &candyType) {
        set<int> s;
        for (int &item: candyType) {
            s.insert(item);
        }
        return std::min(s.size(), candyType.size() / 2);
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
