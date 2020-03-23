#include <iostream>
#include <queue>

using namespace std;

int main()
{
    int n, sum_of_time_to_using_atm = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int time_to_using_atm;
        cin >> time_to_using_atm;

        pq.push(time_to_using_atm);
    }

    while (!pq.empty())
    {
        sum_of_time_to_using_atm += pq.top() * pq.size();
        pq.pop();        
    }

    cout << sum_of_time_to_using_atm << endl;

    return 0;
}