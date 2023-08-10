#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>

void PrintZeroes(int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << "0" << std::endl;
    }
}

int main() {
    int userCount, pairCount; //количкство пользователей, количество пар друзей
    std::map<int, std::map<int, bool>> friendships; /*карта, где каждому пользователю сопоставлена карта других пользователей, 
    с которыми он дружит
    */

    std::cin >> userCount >> pairCount;

    if (pairCount == 0) {
        PrintZeroes(userCount);
        return 0;
    }

    // Заполнение структуры данных пользователямт и их парами друзей
    for (int i = 0; i < pairCount; ++i) {
        int userA, userB;
        std::cin >> userA >> userB;

        friendships[userA][userB] = false;
        friendships[userB][userA] = false;
    }

    
    for (int i = 1; i < userCount + 2; ++i) {
        std::vector<int> mostConnectedFriends; //для хранения идентификаторов наиболее связанных друзей.
        std::map<int, int> friendConnections; // карта для подсчетв количества связей друзей.

        for (auto& friendEntry : friendships[i]) {
            for (auto& friendOfFriend : friendships[friendEntry.first]) {
                int friendOfFriendId = friendOfFriend.first;

                if (friendOfFriendId == i || friendships[i].count(friendOfFriendId) || !friendships[i].count(friendEntry.first)) {
                    continue;
                }
                else {
                    friendConnections[friendOfFriendId]++;
                }
            }
        }

        int maxConnections = 0;
        for (auto& connection : friendConnections) {
            maxConnections = std::max(maxConnections, connection.second);
        }

        for (auto& connection : friendConnections) {
            if (connection.second == maxConnections) {
                mostConnectedFriends.push_back(connection.first);
            }
        }

        std::sort(mostConnectedFriends.begin(), mostConnectedFriends.end());

        if (i != userCount + 1) {
            if (mostConnectedFriends.empty()) {
                std::cout << "0" << std::endl;
            }
            else {
                for (size_t j = 0; j < mostConnectedFriends.size(); ++j) {
                    std::cout << mostConnectedFriends[j];
                    if (j != mostConnectedFriends.size() - 1) {
                        std::cout << " ";
                    }
                }
                std::cout << std::endl;
            }
        }
        else {
            break;
        }
    }

    return 0;
}
