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
    vector<string> medals = {"Gold Medal", "Silver Medal", "Bronze Medal"};
private:
    string getRank(int n) {
        if (n <= 3) {
            return medals[n - 1];
        } else {
            ostringstream oss;
            oss << n;
            return oss.str();
        }
    }
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<int> sortedScore = score;
        map<int, string> scoreOrderMap;
        vector<string> res;
        std::sort(sortedScore.begin(), sortedScore.end());
        std::reverse(sortedScore.begin(), sortedScore.end());
        for (int i = 0; i < sortedScore.size(); i++) {
            scoreOrderMap[sortedScore[i]] = getRank(i + 1);
        }
        for (int i : score) {
            res.emplace_back(scoreOrderMap[i]);
        }
        return res;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
