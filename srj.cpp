#include <iostream>
#include <climits>
using namespace std;

const int MAX = 10;  // Maximum number of processes

int main() {
    int n;
    cout << "Enter number of processes: ";
    cin >> n;

    int burst_time[MAX], remaining_time[MAX], arrival_time[MAX];
    int completion_time[MAX], waiting_time[MAX], turnaround_time[MAX];
    int current_time = 0;
    int completed = 0;

    // Input burst time and arrival time
    for (int i = 0; i < n; i++) {
        cout << "Process " << i + 1 << " Burst Time: ";
        cin >> burst_time[i];
        remaining_time[i] = burst_time[i];  // Initialize remaining time
        cout << "Process " << i + 1 << " Arrival Time: ";
        cin >> arrival_time[i];
    }

    // Shortest Remaining Job Scheduling
    while (completed < n) {
        int min_remaining_time = INT_MAX;
        int selected_process = -1;

        // Find process with shortest remaining time that has arrived
        for (int i = 0; i < n; i++) {
            if (remaining_time[i] > 0 && arrival_time[i] <= current_time && remaining_time[i] < min_remaining_time) {
                min_remaining_time = remaining_time[i];
                selected_process = i;
            }
        }

        if (selected_process != -1) {
            // Execute the selected process for one time unit
            remaining_time[selected_process]--;
            current_time++;

            // If the process has completed
            if (remaining_time[selected_process] == 0) {
                completion_time[selected_process] = current_time;
                turnaround_time[selected_process] = completion_time[selected_process] - arrival_time[selected_process];
                waiting_time[selected_process] = turnaround_time[selected_process] - burst_time[selected_process];
                completed++;
            }
        } else {
            // If no process is ready to execute, increment time
            current_time++;
        }
    }

    // Display Results
    cout << "\nProcess\tBurst Time\tArrival Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << burst_time[i] << "\t\t" << arrival_time[i] << "\t\t" 
             << completion_time[i] << "\t\t" << turnaround_time[i] << "\t\t" << waiting_time[i] << endl;
    }

    return 0;
}
