
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> m;

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int n;
int cnt=0;

void printall(int a[], int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << a[i] << " ";
	cout << endl;
}


int partition(int a[], int start, int end)
{
    int pivot = a[start];
    int i
        = (end+1); 
 
    for (int j = end; j >= start+1; j--) {
		// cout<<"k "<<j<<" "<<a[j]<<" "<<pivot<<endl;
        cnt+=1;m[a[j]][pivot] += 1;
		m[pivot][a[j]] += 1;

        if (a[j] > pivot) {
			
			i--;
			
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i-1], &a[start]);
	// cout<<"S : " <<start<<" E : "<< end <<" P : "<< pivot <<" :Partitioned: ";printall(a,n);

    return (i - 1);
}

void quickSort(int a[], int start, int end)
{	

	if (start < end) {

		int pi = partition(a, start, end);

		quickSort(a, start, pi - 1);
		quickSort(a, pi + 1, end);
	}
}

int fact(int n) {
   if (n == 0 || n == 1)
   return 1;
   else
   return n * fact(n - 1);
}
int main()
{
	int a[] = { 0, 1, 2,3,4,5};
	n = sizeof(a) / sizeof(a[0]);
	int repitations = 10; 
	m.resize(n,vector<int>(n));
	do{
        int a2[n];
        copy (a, a+n, a2);
        printall(a2,n);
		quickSort(a2, 0, n - 1);
        // cout<< "aap";
		// printall(a2,n);

        
	}while(next_permutation(a, a + n));
	// cout << "Sorted : \n";
	// printall(a, n);
	int comb = fact(n);
	for(int i =0  ; i<n; i++ ){
		for(int j=0 ; j<n ; j++){
			cout<<(float)m[i][j]/comb<<"\t "<<setprecision(3);
			
		}
		cout<<endl;
	}
	// cout<<"Probability : "<<(float)cnt/(repitations);
	return 0;
}
