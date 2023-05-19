#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>& A, int i, bool mustPick, vector<vector<int>>& dp) {
    if(i >= A.size()) return mustPick ? 0 : -1e5;
    if(dp[mustPick][i] != -1) return dp[mustPick][i];
    if(mustPick)
        return dp[mustPick][i] = max(0, A[i] + solve(A, i+1, true, dp));
    return dp[mustPick][i] = max(solve(A, i+1, false, dp), A[i] + solve(A, i+1, true, dp));
}


int main(){
    vector<int> nm = {5,1,-9,3};
    vector<vector<int>> dp(2, vector<int>(nm.size(), -1));
    cout<<"Final Answer : "<<solve(nm, 0, false, dp);
    return 0;
}

