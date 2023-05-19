#include<bits/stdc++.h>
using namespace std;

int LargestContiniguousBlocksum(vector<int>& nums) {
    // int maxsum;

    // for(int i = 0 ; i < nums.size()-1;i++){
        int maxsum = 0;
        int sum = 0;
        int presum = 0;

        for(int i = 0; i < nums.size();i++){
            sum+= nums[i];
            if(presum > sum){
                sum = nums[i];
            }
            if(maxsum < sum ){
                maxsum = sum;
            }
            presum = sum;
        }   
    // }
    return maxsum;
}

int main()
{
	// vector<int> arr = { 10, 22, 9, 33, 21, 50, 41, 60 };
	vector<int> arr = { 3, 10, 2, 1, 20 };

	cout<<"Length of lis is " << LargestContiniguousBlocksum(arr);
	return 0;
}
