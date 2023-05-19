#include<bits/stdc++.h>
using namespace std;
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < i; ++j)
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
                dp[i] = dp[j] + 1;
    return *max_element(dp.begin(), dp.end());
}

int main()
{
	// vector<int> arr = { 10, 22, 9, 33, 21, 50, 41, 60 };
	vector<int> arr = { 3, 10, 2, 1, 20 };

	cout<<"Length of lis is " << lengthOfLIS(arr);
	return 0;
}
