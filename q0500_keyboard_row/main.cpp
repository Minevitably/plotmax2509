#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>
#include <set>

using namespace std;


class Solution {
    vector<string> rows = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
private:
    bool canTypedByRow(const string &word) {
        int flag = -1;
        for (char ch: word) {
            for (int i = 0; i < rows.size(); i++) {
                ch = tolower(ch);
                if (rows[i].find(ch) != -1) {
                    if (flag == -1) {
                        flag = i;
                    } else if (flag != i){
                        return false;
                    }
                }
            }
        }
        return true;
    }

public:
    vector<string> findWords(vector<string> &words) {
        vector<string> res;
        for (string word: words) {
            if (canTypedByRow(word)) {
                res.emplace_back(word);
            }
        }
        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
