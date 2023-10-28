#include <iostream>
#include <stdlib.h>
using namespace std;

class Process
{
    int id, burstTime, arrivalTime, waitingTime, turnAroundTime, completionTime;

public:
    void input(Process *, int);
    void display(Process *, int);
    void sort(Process *, int);
    void calc(Process *, int);
};

int main()
{
    int n;
    cout << "\nEnter the number of processes: \n";
    cin >> n;
    Process *p = new Process[n];
    Process f;
    f.input(p, n);
    f.sort(p, n);
    f.calc(p, n);
    f.display(p, n);
    return 0;
}

void Process::input(Process *p, int n)
{
    cout << "\nEnter the arrival time and burst time of each process: \n";
    for (int i = 0; i < n; i++)
    {
        cout << "\nProcess " << i + 1 << "\n";
        cout << "Arrival time: ";
        cin >> p[i].arrivalTime;
        cout << "Burst time: ";
        cin >> p[i].burstTime;
        p[i].id = i + 1;
    }
}

void Process::calc(Process *p, int n)
{
    int sum = 0;
    sum = sum + p[0].arrivalTime;
    for (int i = 0; i < n; i++)
    {
        sum = sum + p[i].burstTime;
        p[i].completionTime = sum;
        p[i].turnAroundTime = p[i].completionTime - p[i].arrivalTime;
        p[i].waitingTime = p[i].turnAroundTime - p[i].burstTime;
        if (sum < p[i + 1].arrivalTime)
        {
            int t = p[i + 1].arrivalTime - sum;
            sum = sum + t;
        }
    }
}

void Process::sort(Process *p, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (p[i].arrivalTime > p[j + 1].arrivalTime)
            {
                int temp;
                temp = p[j].burstTime;
                p[j].burstTime = p[j + 1].burstTime;
                p[j + 1].burstTime = temp;

                temp = p[j].arrivalTime;
                p[j].arrivalTime = p[j + 1].arrivalTime;
                p[j + 1].arrivalTime = temp;

                temp = p[j].id;
                p[j].id = p[j + 1].id;
                p[j + 1].id = temp;
            }
        }
    }
}

void Process::display(Process *p, int n)
{
    cout << "\nProcess\tArrival Time\tBurst Time\tWaiting Time\tTurn Around Time\tCompletion Time\n";
    for (int i = 0; i < n; i++)
    {
        cout << p[i].id << "\t\t" << p[i].arrivalTime << "\t\t" << p[i].burstTime << "\t\t" << p[i].waitingTime << "\t\t" << p[i].turnAroundTime << "\t\t" << p[i].completionTime << "\n";
    }
    cout << "\n";

    int avgWaitingTime = 0, avgTurnAroundTime = 0;
    for (int i = 0; i < n; i++)
    {
        avgWaitingTime = avgWaitingTime + p[i].waitingTime;
        avgTurnAroundTime = avgTurnAroundTime + p[i].turnAroundTime;
    }
    avgWaitingTime = float(avgWaitingTime) / float(n);
    avgTurnAroundTime = float(avgTurnAroundTime) / float(n);
    cout << "\nAverage Waiting Time: " << avgWaitingTime;
    cout << "\nAverage Turn Around Time: " << avgTurnAroundTime;
}