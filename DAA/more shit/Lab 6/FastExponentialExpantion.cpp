#include <bits/stdc++.h>
using namespace std;


string tobinary(int n, int len)
{
    string binary;
    for (unsigned i = (1 << len - 1); i > 0; i = i / 2) {
        binary += (n & i) ? "1" : "0";
    }
 
    return binary;
}

int fme(int b, int e, int m)
{
	int result = 1;
	if (1 & e)
		result = b;
	cout<<result<<endl;
	cout<<"e "<<tobinary(e,10)<<endl;
	while (1) {
		if (!e) break;
		e >>= 1;
		cout<<"\ne "<<tobinary(e,10)<<" b*b : "<<b*b<< " "<<" e & 1 : "<<(e & 1)<<" ";
		b = (b * b) % m;
		cout<<"B : "<<b<<" ";
		if (e & 1){		    
			result = (result * b) % m;
			cout<<" result : "<< result<<endl;
		}
		cout<<"result : "<<result<<endl; 
	}
	cout<<"result : "<<result<<endl; 
	return result;
}

int main()
{
	int b = 5, e = 117, m = 19;
	int ans = fme(b, e, m);
	cout<<b<<"^"<<e <<" mod "<<m<<" = "<<ans; 
	return 0;
}