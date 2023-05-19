#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> m;

void printall(int a[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
}

int main(){
    int a[] = { 0, 1, 2};
    int a2[3];
    copy (a, a+3, a2);
        a2[0]=1000;
    printall(a2,3);

    // quickSort(a, 0, n - 1);
    printall(a,3);
    return 0;
}