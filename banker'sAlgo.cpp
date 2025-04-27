#include <iostream>
using namespace std;

const int MAX_PROCESSES = 5;
const int MAX_RESOURCES = 3;
 
int main() {
    int n, m; // n = number of processes, m = number of resources
    int alloc[MAX_PROCESSES][MAX_RESOURCES];
    int max[MAX_PROCESSES][MAX_RESOURCES];
    int avail[MAX_RESOURCES];

    cout << "Enter number of processes: ";
    cin >> n;
    cout << "Enter number of resources: ";
    cin >> m;

    cout << "Enter Allocation Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> alloc[i][j];

    cout << "Enter Maximum Requirement Matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> max[i][j];

    cout << "Enter Available Resources:\n";
    for (int i = 0; i < m; i++)
        cin >> avail[i];

    int need[MAX_PROCESSES][MAX_RESOURCES];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            need[i][j] = max[i][j] - alloc[i][j];

    bool finished[MAX_PROCESSES] = {false};
    int safeSequence[MAX_PROCESSES];
    int work[MAX_RESOURCES];

    for (int i = 0; i < m; i++)
        work[i] = avail[i];

    int count = 0;
    while (count < n) {
        bool found = false;
        for (int p = 0; p < n; p++) {
            if (!finished[p]) {
                bool canAllocate = true;
                for (int j = 0; j < m; j++) {
                    if (need[p][j] > work[j]) {
                        canAllocate = false;
                        break;
                    }
                }
                if (canAllocate) {
                    for (int k = 0; k < m; k++)
                        work[k] += alloc[p][k];

                    safeSequence[count++] = p;
                    finished[p] = true;
                    found = true;
                }
            }
        }
        if (!found) {
            cout << "System is not in a safe state.\n";
            return 0;
        }
    }

    cout << "System is in a safe state.\nSafe sequence is: ";
    for (int i = 0; i < n; i++)
        cout << "P" << safeSequence[i] << " ";
    cout << endl;

    return 0;
}
