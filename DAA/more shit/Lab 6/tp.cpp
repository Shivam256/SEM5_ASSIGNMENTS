#include <bits/stdc++.h>
using namespace std;


long long fme(int b, int e, int m)
{
    long long result = 1;
    while(e--){
        result *= b ; 
    }
    return result%m;
}

int main()
{
	int b = 3, e = 5, m = 11;
	long long ans = fme(b, e, m);
	cout<<b<<"^"<<e <<" mod "<<m<<" = "<<ans; 
	return 0;
}