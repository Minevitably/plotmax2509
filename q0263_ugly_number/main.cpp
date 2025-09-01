#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <string>
#include <map>

using namespace std;

class Solution {
private:
    bool isPrime(int n) {
        if (n <= 1) {
            return false;
        }
        int k = sqrt(n);
        for (int i = 2; i <= k; i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }

    int getFirstPrimeFactor(int n) {
        int k = sqrt(n);
        for (int i = 2; i <= k; i++) {
            if (isPrime(i) && n % i == 0) {
                return i;
            }
        }
        // never happen
        return n;
    }
public:
    bool isUgly(int n) {
        if (n <= 0 || (isPrime(n) && n > 5)) {
            return false;
        }
        while (n > 1) {
            int p = getFirstPrimeFactor(n);
            if (p > 5) {
                return false;
            }
            n /= p;
            if (isPrime(n) && n > 5) {
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
