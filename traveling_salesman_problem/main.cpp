#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9; // Бесконечность

int main() {
    // Входные данные (матрица расстояний между городами)
    int n; // Количество городов
    cin >> n;
    vector<vector<int>> distance(n, vector<int>(n)); // Матрица расстояний
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> distance[i][j];
        }
    }

    // Генерация всех перестановок городов
    vector<int> path(n);
    for (int i = 0; i < n; i++) {
        path[i] = i;
    }
    int minDistance = INF;
    vector<int> optimalPath;
    do {
        // Проверяем текущий путь
        int curDistance = 0;
        for (int i = 1; i < n; i++) {
            curDistance += distance[path[i - 1]][path[i]];
        }
        curDistance += distance[path[n - 1]][path[0]];

        // Обновляем оптимальный путь, если нашли более короткий
        if (curDistance < minDistance) {
            minDistance = curDistance;
            optimalPath = path;
        }
    } while (next_permutation(path.begin() + 1, path.end())); // Генерируем следующую перестановку

    // Вывод ответа
    cout << "Оптимальный путь: ";
    for (int i = 0; i < n; i++) {
        cout << optimalPath[i] << " -> ";
    }
    cout << optimalPath[0] << endl;
    cout << "Длина пути: " << minDistance << endl;

    return 0;
}