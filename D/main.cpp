#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int testcase = 0; testcase < t; ++testcase) {
        if (testcase > 0) {
            cout << endl; //Упро
        }

        int n, m;
        cin >> n >> m;

        vector<vector<int>> table(n, vector<int>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> table[i][j];
            }
        }

        int k;
        cin >> k;

        vector<int> clicks(k);

        for (int i = 0; i < k; ++i) {
            cin >> clicks[i];
        }

        for (int col : clicks) {
            sort(table.begin(), table.end(), [col](const vector<int>& a, const vector<int>& b) {
                return a[col - 1] < b[col - 1]; //лямбда функция принимает  a и b, сравнивает если значение в col - 1 для a меньше, возвращаем true что значит что a идет перед b после сортировки
                });
        }

        for (const vector<int>& row : table) {
            for (int value : row) {
                cout << value << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
