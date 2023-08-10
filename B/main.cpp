#include <iostream>
#include <unordered_map>
int main() {
    int t;
    std::cin >> t;
    int num_of_prod, price;
 
    for (int i = 0; i < t; ++i) {
        std::unordered_map<int, int> product_count;
        std::cin >> num_of_prod;
        for (int j = 0; j < num_of_prod; ++j) {
            std::cin >> price;
            product_count[price]++;
        }
 
        long long total_payment = 0;
        for (const auto& entry : product_count) {
            int count = entry.second;
            int price = entry.first;
            total_payment += (count / 3) * 2 * price + (count % 3) * price;
        }
 
        std::cout << total_payment << std::endl;
    }
 
    return 0;
}
