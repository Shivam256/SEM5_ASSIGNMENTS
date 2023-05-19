
#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> m;

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
	int random = start + (rand() % ((end-start)+1));
	// cout<<start<<" "<<random<<" "<<end<<endl;
	int pivot = a[random]; // pivot
	// cout<<pivot<<"  ";
	int i
		= (start
		-1); 

	for (int j = start; j <= end ; j++) {
		// cout<<" "<<j<<" "<<a[j]<<" "<<pivot<<endl;
		if(a[j] != pivot){
			cnt+=1;
			i++;
			m[a[j]][pivot] += 1;
			m[pivot][a[j]] += 1;
			//compair
		}
		
	

	}

	// cout<<"S : " <<start<<" E : "<< end <<" P : "<< pivot <<" :Partitioned: ";
	// printall(a,n);
		
	return (i + 1);
}

void quickSort(int a[], int start, int end)
{	

	if (start < end) {

		int pi = partition(a, start, end);

		quickSort(a, start, pi - 1);
		quickSort(a, pi + 1, end);
	}
}


int main()
{
	srand((unsigned)time((unsigned)0) );

	int a[] = { 0, 1, 2, 3, 4, 5 , 6, 7, 8, 9};
	n = sizeof(a) / sizeof(a[0]);
	int repitations = 10000;
	 
	m.resize(n,vector<int>(n));
	for(int i = 0 ;i<repitations;i++){
		quickSort(a, 0, n - 1);
		cout<<endl;
	}
	// cout << "Sorted : \n";
	// printall(a, n);
	for(int i =0  ; i<n; i++ ){
		for(int j=0 ; j<n ; j++){
			cout<<(float)m[i][j]/repitations<<"\t ";
			// cout<<m[i][j]<<"\t ";
			
		}
		cout<<endl;
	}
	// cout<<"Probability : "<<cnt/repitations;
	return 0;
}
