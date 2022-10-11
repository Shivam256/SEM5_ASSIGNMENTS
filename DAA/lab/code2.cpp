#include <iostream>
#include <vector>
using namespace std;


int main(){

    double p;
    cout<<"Enter the probability of heads:";
    cin>>p;

    double q = 1-p;

    int pH = 100*p;

    int ctr = 0;


    while(true){
        int random = rand()%100;
        if(random < pH){
            cout<<"Got head!"<<endl;
            break;
        }else{
            ctr++;
            cout<<"Got tails, still going!"<<endl;
            continue;
        }
        
    }

    cout<<ctr<<endl;

    return 0;
}