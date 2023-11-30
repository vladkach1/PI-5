#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9; // �������������

int main() {
    // ������� ������ (������� ���������� ����� ��������)
    int n; // ���������� �������
    cin >> n;
    vector<vector<int>> distance(n, vector<int>(n)); // ������� ����������
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> distance[i][j];
        }
    }

    // ��������� ���� ������������ �������
    vector<int> path(n);
    for (int i = 0; i < n; i++) {
        path[i] = i;
    }
    int minDistance = INF;
    vector<int> optimalPath;
    do {
        // ��������� ������� ����
        int curDistance = 0;
        for (int i = 1; i < n; i++) {
            curDistance += distance[path[i - 1]][path[i]];
        }
        curDistance += distance[path[n - 1]][path[0]];

        // ��������� ����������� ����, ���� ����� ����� ��������
        if (curDistance < minDistance) {
            minDistance = curDistance;
            optimalPath = path;
        }
    } while (next_permutation(path.begin() + 1, path.end())); // ���������� ��������� ������������

    // ����� ������
    cout << "����������� ����: ";
    for (int i = 0; i < n; i++) {
        cout << optimalPath[i] << " -> ";
    }
    cout << optimalPath[0] << endl;
    cout << "����� ����: " << minDistance << endl;

    return 0;
}