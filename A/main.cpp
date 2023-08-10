#include <iostream>
 
int main() {
    int t;
    std::cin >> t;
 
    for (int i = 0; i < t; ++i) {
        int a, b;
        std::cin >> a >> b;
        int sum = a + b;
        std::cout << sum << std::endl;
    }
 
    return 0;
}
