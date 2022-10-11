#include <iostream>
#include <vector>
using namespace std;

void firstComeFirstServe()
{
}

void shortestJobFirst()
{
}

void displayVector(vector<int> v)
{
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    int processNum;
    cout << "Enter number of processes:";
    cin >> processNum;
    vector<int> burstTime(processNum);
    vector<int> waitingTime(processNum);
    vector<int> turnAroundTIme(processNum);

    cout << "Enter the burst time of processes\n";
    for (int i = 0; i < processNum; i++)
    {
        int k;
        cin >> k;
        burstTime[i] = k;
    }

    int ctr = 0;

    for (int i = 0; i < processNum; i++)
    {
        waitingTime[i] = ctr;
        ctr += burstTime[i];
    }

    for (int i = 0; i < processNum; i++)
    {
        turnAroundTIme[i] = waitingTime[i] + burstTime[i];
    }

    cout << "Burst time:\n";
    displayVector(burstTime);
    cout << "\nWaiting time:\n";
    displayVector(waitingTime);
    cout << "\nTurn Around Time:\n";
    displayVector(turnAroundTIme);

    cout << "Now for different arival time from secind processes:\n";
    vector<int> arrivalTime(processNum);
    arrivalTime[0] = 0;
    for (int i = 1; i < processNum; i++)
    {
        int x;
        cin >> x;
        arrivalTime[i] = x;
    }

}