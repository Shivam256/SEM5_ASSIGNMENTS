#include<bits/stdc++.h>
#include<windows.h>
using namespace std;

void printall(vector<int> v){
    cout<<endl;
    for(int i = 0; i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

vector<int> merge(vector<int> v1,vector<vector<int>> v2,int n){
    if(n>=v2.size())
        return v1;
    cout<<n<<endl;
    int a=0,b=0;
    vector<int> temp;
    while(a<v1.size() && b<v2[n].size()){
        cout<<"Compair : "<<v1[a]<<" "<<v2[n][b]<<(v1[a]<v2[n][b])<<endl;
        if(v1[a]<v2[n][b]){
            temp.push_back(v1[a]);
            a++;
        }
        else if(v1[a]>v2[n][b]){
            temp.push_back(v2[n][b]);
            b++;
        }
        else{
            temp.push_back(v1[a]);
            a++;
            temp.push_back(v2[n][b]);
            b++;
        }
        cout<<"in"<<endl;
        printall(temp);
        cout<<endl;
        cout<<endl;
    }
    if(v1.size() > v2[n].size()){
            temp.push_back(v1[a]);
            a++;
                    cout<<"in2"<<endl;
        printall(temp);
        cout<<endl;
        cout<<endl;
        }
    }
    else if(v1.size() < v2[n].size()){
        while(b<v2[n].size()){
            temp.push_back(v2[n][b]);
            b++;
                    cout<<"in2"<<endl;
        printall(temp);
        cout<<endl;
        cout<<endl;
        }
    }
    cout<<"temp : ";
    printall(temp);
    // Sleep(5000);
    merge(temp,v2,++n);
    return v1;
}

int main(){
    vector<vector<int>> v1 {{1,2,4},{3,6,7,8,9},{3,4}};
    int n = v1.size();
    // vector<int> temp = v1[0];
    // cout<< temp[0];
    // v1.erase(v1.begin());
    // cout<< v1[0][0];
    vector<int> temp; 
    temp = merge(temp,v1,0);
    printall(temp);
    return 0;
}