// Array implimentation of josephres problem

#include<bits/stdc++.h>
using namespace std;





int main(){
    int n = 9;
    vector<int> a(n, 1);


	// index = ((index + k) % person.size());

    int cnt = n-1;
    int i = 0;
    do{
        ///////////////////////printing stuff
        for(int j = 0 ; j<n  ; j++){
            if(j != i%n){
                cout<<j<<"  ";
            }else{
                cout<<"|"<<j<<"|  ";
            }
        }
        cout<<endl;
        for(int j = 0 ; j<n  ; j++){
            if(j != i%n){
                cout<<a[j]<<"  ";
            }else{
                cout<<"|"<<a[j]<<"|  ";
            }
        }     
        cout<<endl;
        ///////////////////////


        ///////////////////////Working
        i++;

        while(a[i%n] != 1){
            i++;
        }  
        

        cout<<"Killing : "<<i%n<<endl;
        a[i%n] = 0;
        cnt--;

        
        while(a[i%n] != 1){
            i++;
        }
        // cout<<i%n<<endl;

        ///////////////////////

        cout<<endl;
    }while(cnt != 0);
    cout<<"Last One Alive :" <<i%n<<endl;



    
}


