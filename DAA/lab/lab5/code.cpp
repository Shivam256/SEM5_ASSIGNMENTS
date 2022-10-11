#include <iostream>
#include <vector>
using namespace std;

int countFrequency(vector<int> v, int l, int r, int majority)
{
    int ctr = 0;
    for (int i = l; i <= r; i++)
    {
        if (v[i] == majority)
        {
            ctr++;
        }
    }

    return ctr;
}

int getMajority(vector<int> v, int l, int r)
{
    if (l == r)
        return v[l];
    int mid = l + (r - l) / 2;
    int leftMajority = getMajority(v, l, mid);
    int rightMajority = getMajority(v, mid + 1, r);

    if (leftMajority == rightMajority)
        return leftMajority;

    int lcount = countFrequency(v, l, r, leftMajority);
    int rcount = countFrequency(v, l, r, rightMajority);

    if (lcount > rcount)
    {
        return leftMajority;
    }
    else
    {
        return rightMajority;
    }
}

int divideAndConquer(vector<int> v)
{
    int n = v.size();
    return getMajority(v, 0, n - 1);
}

int randomizedElement(vector<int> v)
{
    int n = v.size();
    while (true)
    {
        int random = rand() % n;
        int randomEl = v[random];
        int p = countFrequency(v, 0, n, randomEl);
        if (p > n / 2)
            return randomEl;
    }
}

int deterministic(vector<int> v){
    //
}

int main()
{
    vector<int> arr = {1, 3, 4, 5, 3, 3, 3, 2, 4, 3, 3, 3, 3, 1};
    cout << "DIVIDE AND CONQUER: " << divideAndConquer(arr) << endl;
    cout << "RANDOMIZED APPROACH: " << randomizedElement(arr) << endl;
}