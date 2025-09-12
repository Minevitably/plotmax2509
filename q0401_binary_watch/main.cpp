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
    string lightsToStr(bool lights[]) {
        int hour = 0;
        int minute = 0;
        ostringstream oss;
        for (int i = 6; i < 10; i++) {
            int v = lights[i] ? 1 : 0;
            hour |= (v << (i - 6));
        }
        for (int i = 0; i < 6; i++) {
            int v = lights[i] ? 1 : 0;
            minute |= (v << i);
        }
        if (hour > 11 || minute > 59) {
            return "";
        }
        oss << hour << ":" << (minute < 10 ? "0" : "") << minute;
        return oss.str();
    }

    void rank(vector<string> &res, int turnedOn, bool lights[], int start) {
        if (turnedOn == 0) {
            string str = lightsToStr(lights);
            if (!str.empty() &&
                std::find(res.begin(), res.end(), str) == res.end()) {
                res.push_back(str);
            }
        }
        for (int i = start; i < 10; i++) {
            if (lights[i]) {
                continue;
            }
            lights[i] = true;
            rank(res, turnedOn - 1, lights, start + 1);
            lights[i] = false;
        }
    }

public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        bool lights[10] = {};
        rank(res, turnedOn, lights, 0);
        std::sort(res.begin(), res.end());
        return res;
    }
};

int main() {
    (new Solution())->readBinaryWatch(2);
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
