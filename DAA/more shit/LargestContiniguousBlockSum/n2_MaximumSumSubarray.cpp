#include<bits/stdc++.h>
using namespace std;

int maxSubArray(vector<int>& nums) {
    int n = nums.size(), ans = INT_MIN;
    for(int i = 0; i < n; i++){
        for(int j = i, curSum = 0; j < n ; j++) {
            curSum += nums[j],
            ans = max(ans, curSum); 
        cout<<ans<<endl;
        }
    }

    return ans;
}

int main(){
    vector<int> nm = {5,1,-9,3};
    cout<<"Final Answer : "<<maxSubArray(nm);
    return 0;
}