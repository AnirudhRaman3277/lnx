// Scheduling algorithm for FCFS
#include <iostream>
#include <algorithm>
using namespace std;

//Function that uses Arrival time for sorting
void FunctionSorting(int processID[], int n, int arrivalTime[], int burstTime[])
{
    for (int i=0; i<n-1; i++) {
        for (int j=i+1; j<n; j++) {
            if (arrivalTime[i] > arrivalTime[j]) {
                swap(arrivalTime[i], arrivalTime[j]);
                swap(burstTime[i], burstTime[j]);
                swap(processID[i], processID[j]);
            }
        }
    }
}

//Finding waiting time of all processes
void FindWaitingTime(int processID[], int n, int burstTime[], int waitingTime[], int arrivalTime[])
{
    //Initializing Waiting Time to 0 for the first process
    waitingTime[0] = 0;

    //Calculation of time of completion of first process
    int currentTime = arrivalTime[0] + burstTime[0];

    //Calculation after current time is updated
    for (int b=1; b<n; b++)
    {
        if (currentTime < arrivalTime[b])
        {
            //Fixing idle time of CPU
            currentTime = arrivalTime[b];
        }
        waitingTime[b] = currentTime - arrivalTime[b];
        currentTime += burstTime[b];
    }
}

//Finding the Turnaround Time for all processes
void FindTurnaroundTime(int processID[], int n, int burstTime[], int waitingTime[], int turnaroundTime[])
{
    //General formula for Turnaround Time => tt[i] = wt[i] + bt[i]
    for (int j=0; j<n; j++)
    {
        turnaroundTime[j] = waitingTime[j] + burstTime[j];
    }
} 
void AverageWTandTT(int processID[], int n, int burstTime[], int arrivalTime[])
{
    //Initializing 
    int waitingTime[n], turnaroundTime[n];
    float TTtotal = 0.0, WTtotal = 0.0;

    // Sort processes based on arrival time
    FunctionSorting(processID, n, arrivalTime, burstTime);

    //Calling functions to find respective Turnaround Time and Waiting Time
    FindWaitingTime(processID, n, burstTime, waitingTime, arrivalTime);
    
    FindTurnaroundTime(processID, n, burstTime, waitingTime, turnaroundTime);

    //Printing all the details
    cout << "Process  " << "Arrival Time  "<< "Burst Time  " << "Waiting Time  "<< "Turnaround Time  "<< "\n";
    for (int k=0; k<n; k++) 
    {
        cout<< processID[k] << "        " << arrivalTime[k] << "              " << burstTime[k] << "           " << waitingTime[k] << "             " << turnaroundTime[k] << "\n"; 
    }

    //Finding Average TT and Average WT
    for (int a=0; a<n; a++)
    {
        TTtotal = TTtotal + turnaroundTime[a];
        WTtotal = WTtotal + waitingTime[a];
    }

    float TTaverage = TTtotal / n;
    float WTaverage = WTtotal / n;

    //Displaying the Average Times
    cout << "Avg Waiting Time is " << WTaverage << " & ";
    cout << "Avg Turnaround Time is " << TTaverage;
}

int main()
{
    //Initializing...
    int n; 

    //Receiving input from user
    cout << "FCFS Scheduling Algorithm\n";
    cout << "Enter the number of processes: ";
    cin >> n;

    int processID[n], burstTime[n], arrivalTime[n];

    for (int i=0; i<n; i++) {
        cout << "Enter a Procees ID: ";
        cin >> processID[i];
        cout << "Enter Arival Time: ";
        cin >> arrivalTime[i];
        cout << "Enter the Burst Time: ";
        cin >> burstTime[i];
    }

    //Running the Parent Function
    AverageWTandTT(processID, n,  burstTime, arrivalTime);
    return 0;
}