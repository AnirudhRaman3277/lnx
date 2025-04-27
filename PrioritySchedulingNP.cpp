// Priority Scheduling
#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int pid;
    int bt;
    int priority;
};

bool compare(Process a, Process b) {
    return (a.priority > b.priority);
}

void waitingTime(Process pro[], int n, int wt[]) {
    wt[0] = 0; // First process has 0 waiting time
    for (int i = 1; i < n; i++) {
        wt[i] = pro[i - 1].bt + wt[i - 1];
    }
}

void turnaroundTime(Process pro[], int n, int wt[], int tat[]) {
    for (int i = 0; i < n; i++) {
        tat[i] = pro[i].bt + wt[i];
    }
}

void avgTime(Process pro[], int n) {
    int wt[n], tat[n], total_wt = 0, total_tat = 0;

    waitingTime(pro, n, wt);
    turnaroundTime(pro, n, wt, tat);

    cout << "\nProcess  " << "Priority  " << "Burst Time  "
         << "Waiting Time  " << "Turnaround Time\n";

    for (int i = 0; i < n; i++) {
        cout << "  " << pro[i].pid << "\t    "
             << pro[i].priority << "\t      "
             << pro[i].bt << "\t\t"
             << wt[i] << "\t\t"
             << tat[i] << "\n";
    }

    for (int i = 0; i < n; i++) {
        total_wt += wt[i];
        total_tat += tat[i];
    }

    float WTaverage = (float)total_wt / n;
    float TTaverage = (float)total_tat / n;

    cout << "\nAverage waiting time = " << WTaverage;
    cout << "\nAverage turn around time = " << TTaverage << endl;
}

void scheduling(Process pro[], int n) {
    sort(pro, pro + n, compare);

    cout << "\nOrder in which processes get executed:\n";
    for (int i = 0; i < n; i++)
        cout << pro[i].pid << " ";
    cout << "\n";

    avgTime(pro, n);
}

int main() {
    int n;
    cout << "Priority Scheduling Algorithm\n";
    cout << "Enter the number of processes: ";
    cin >> n;

    Process pro[n];

    for (int i = 0; i < n; i++) {
        cout << "\nEnter Process ID: ";
        cin >> pro[i].pid;
        cout << "Enter Priority: ";
        cin >> pro[i].priority;
        cout << "Enter Burst Time: ";
        cin >> pro[i].bt;
    }

    scheduling(pro, n);
    return 0;
}
