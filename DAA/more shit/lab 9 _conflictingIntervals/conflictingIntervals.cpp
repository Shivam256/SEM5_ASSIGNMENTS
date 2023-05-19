#include<bits/stdc++.h>
using namespace std;





bool static comp(vector <int>& a, vector <int>& b) {
    return a[1] < b[1];
}

int EOI(vector<vector<int>>& intervals){
    int n = intervals.size();
    sort(intervals.begin(),intervals.end(),comp);
    int end = intervals[0][1];
    int minre = 1;

    for(int i = 1 ; i< n ; i++){
        if(intervals[i][0]>=end){
            minre++;
            end = intervals[i][1];
        }
    }
    return minre;
}

int main(){
    vector<vector<int>> num = {{1,2},{2,3},{3,4},{1,3}};
    // vector<vector<int>> num = {{1,2},{1,2},{1,2}};
    cout<<EOI(num);
    return 0;
}
