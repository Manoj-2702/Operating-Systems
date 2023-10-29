#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
using namespace std;

void first_come_first_serve(vector<int> &requests, int head)
{
    int seek_count = 0;
    int dis, cur_track;
    for (int i = 0; i < requests.size(); i++)
    {
        cur_track = requests[i];
        dis = abs(cur_track - head);
        seek_count += dis;
        head = cur_track;
    }
    cout << "Total no of seek operations: " << seek_count << endl;
    cout << "Seek Sequence is: ";
    for (int i = 0; i < requests.size(); i++)
    {
        cout << requests[i] << " ";
    }
}

int main()
{
    int n, head;
    cout << "Enter the number of process requests: ";
    cin >> n;
    cout << "Enter the requests: ";
    vector<int> requests(n);
    for (int i = 0; i < n; i++)
    {
        cin >> requests[i];
    }
    cout << "Enter the head position: ";
    cin >> head;
    first_come_first_serve(requests, head);
    return 0;
}