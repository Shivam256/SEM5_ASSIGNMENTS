#include <bits/stdc++.h>
using namespace std;

int Josephus(int, int);

int Josephus(int n, int k)
{
	k--;
	int arr[n];

	// Makes all the 'n' people alive by
	// assigning them value = 1
	for (int i = 0; i < n; i++) {
		arr[i] = 1;
	}
	int cnt = 0, cut = 0,
		// Cut = 0 gives the sword to 1st person.
		num = 1;

	// Loop continues till n-1 person dies.
	while (cnt < (n - 1)) {

		// Checks next (kth) alive persons.
		while (num <= k) {
			cut++;

			// Checks and resolves overflow
			// of Index.
			cut = cut % n;
			if (arr[cut] == 1) {
				// Updates the number of persons
				// alive.
				num++;
			}
		}

		// Refreshes value to 1 for next use.
		num = 1;

		// Kills the person at position of 'cut'
		arr[cut] = 0;

		// Updates the no. of killed persons.
		cnt++;
		cut++;

		// Checks and resolves overflow of Index.
		cut = cut % n;

		// Checks the next alive person the
		// sword is to be given.
		while (arr[cut] == 0) {
			cut++;

			// Checks and resolves overflow
			// of Index.
			cut = cut % n;
		}
	}

	// Output is the position of the last
	// man alive(Index + 1);
	return cut + 1;
}

// Driver code
int main()
{
	int n = 10, k = 2;
	cout << Josephus(n, k);
	return 0;
}

// THIS CODE IS PRESENTED BY SHISHANK RAWAT
