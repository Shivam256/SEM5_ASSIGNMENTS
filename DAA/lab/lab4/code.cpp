#include <iostream>
#include <vector>

using namespace std;

int bruteForce(vector<int> &v)
{
    int n = v.size();
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (v[i] > v[j])
                res++;
        }
    }

    return res;
}

int getCrossCounters(vector<int> &v1, vector<int> &v2)
{
    int res = 0;
    int i = 0, j = 0;
    int n1 = v1.size();
    int n2 = v2.size();

    while (i < n1 && j < n2)
    {
        if (v1[i] > v2[j])
        {
            res += (n1 - i);
            j++;
        }
        else
        {
            i++;
        }
    }

    return res;
}

int getCrossCountersBinarySearch(vector<int> v1, vector<int> v2)
{
    int res = 0;
    int n1 = v1.size();
    int n2 = v2.size();

    for (int i = 0; i < n2; i++)
    {
        int key = v2[i];

        int low = 0;
        int high = n1 - 1;
        bool flag = false;

        while (low < high)
        {
            int mid = low + (high - low) / 2;
            if (v1[mid] == key)
            {
                res += (n1 - mid - 1);
                flag = true;
                break;
            }
            else if (v1[mid] > key)
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        if (!flag)
        {
            if (!(low == n1 - 1 && key > v1[low]))
            {
                res += (n1 - low);
            }
        }
    }

    return res;
}

int main()
{
    vector<int> v = {2, 3, 1, 5, 10, 8};
    cout << bruteForce(v) << "\n";

    vector<int> v1 = {1, 7, 12, 81, 100};
    vector<int> v2 = {2, 15, 70, 90, 110};

    cout << getCrossCounters(v1, v2) << "\n";
    cout << getCrossCountersBinarySearch(v1, v2) << "\n";

    return 0;
}