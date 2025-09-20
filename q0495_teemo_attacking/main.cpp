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
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int total = 0;
        for (int i = 0; i < timeSeries.size(); i++) {
            if (i == timeSeries.size() - 1) {
                total += duration;
                break;
            }
            int delta = timeSeries[i + 1] - timeSeries[i];
            if (timeSeries[i + 1] - timeSeries[i] <= duration) {
                total += delta;
            } else {
                total += duration;
            }

        }
        return total;
    }
};


int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}
