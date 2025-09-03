#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Solution {
private:
    vector<string> split(const string str, char delimeter) {
        vector<string> tokens;
        stringstream ss(str);
        string token;
        while (getline(ss, token, delimeter)) {
            tokens.push_back(token);
        }
        return tokens;
    }
public:
    bool wordPattern(string pattern, string s) {
        map<char, string> psMap;
        map<string, char> spMap;
        vector<string> sList = split(s, ' ');
        int n = pattern.size();
        if (n != sList.size()) {
            return false;
        }
        for (int i = 0; i < n; i++) {
            if (!psMap.count(pattern[i])) {
                if (spMap.count(sList[i])) {
                    return false;
                }
                psMap[pattern[i]] = sList[i];
                spMap[sList[i]] = pattern[i];
            } else if (psMap[pattern[i]] != sList[i]){
                return false;
            }
        }
        return true;
    }
};

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
