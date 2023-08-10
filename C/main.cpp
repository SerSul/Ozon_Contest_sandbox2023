#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

struct Developer {
    int id;
    int skill;

    bool operator<(const Developer& other) const {
        return skill < other.skill;
    }
};

int main() {
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i) {
        int n;
        std::cin >> n;

        std::vector<Developer> developers(n);
        for (int j = 0; j < n; ++j) {
            developers[j].id = j + 1;
            std::cin >> developers[j].skill;
        }


        for (int j = 0; j < n - 1; ++j) {
            int minDifference = std::abs(developers[j].skill - developers[j + 1].skill);
            int minIndex1 = j;
            int minIndex2 = j + 1;

            for (int k = j + 2; k < n; ++k) {
                int difference = std::abs(developers[j].skill - developers[k].skill);
                if (difference < minDifference) {
                    minDifference = difference;
                    minIndex1 = j;
                    minIndex2 = k;
                }
            }

            std::cout << developers[minIndex1].id << " " << developers[minIndex2].id << std::endl;

            developers.erase(developers.begin() + minIndex2);
            developers.erase(developers.begin() + minIndex1);
            n -= 2;

            j--; 
        }
    }

    return 0;
}
