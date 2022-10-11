#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Process
{
public:
    string processId;
    int arrivalTime;
    int burstTime;
    int waitingTime;
    int turnAroundTime;

    Process(string processId, int burstTime, int waitingTime, int turnAroundTime, int arrivalTIme)
    {
        this->processId = processId;
        this->burstTime = burstTime;
        this->arrivalTime = arrivalTIme;
        this->turnAroundTime = turnAroundTime;
        this->waitingTime = waitingTime;
    }
};

void displayProcesses(vector<Process *> processes)
{
    for (auto p : processes)
    {
        cout << p->processId << " - " << p->burstTime << " - " << p->waitingTime << " - " << p->turnAroundTime << " - " << p->arrivalTime << "\n";
    }
}

bool mySortFunction(Process *p1, Process *p2)
{
    return p1->arrivalTime < p2->arrivalTime;
}




int main()
{
    int processNum;
    cout << "Enter the number of processes:\n";
    cin >> processNum;
    vector<Process *> processes;

    int ctr = 0;

    for (int i = 0; i < processNum; i++)
    {
        string pid;
        int burstTime;
        int arrivalTime;
        cout << "Enter process id:";
        cin >> pid;
        cout << "Enter burst tine of this process:";
        cin >> burstTime;
        cout << "Enter the arrival time:";
        cin >> arrivalTime;
        int waitingTime = ctr;
        ctr += burstTime;
        int turnAroundTime = waitingTime + burstTime;

        Process *p = new Process(pid, burstTime, waitingTime, turnAroundTime, arrivalTime);
        processes.push_back(p);
    }

    sort(processes.begin(), processes.end(), mySortFunction);

    //now lets do some shit
    
    cout << "There are the processes:\n";
    displayProcesses(processes);
}