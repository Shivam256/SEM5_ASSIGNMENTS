#include<bits/stdc++.h>
using namespace std;

//n^2
int majorityElement1(vector<int>& nums) {
    // unordered_map<int, int> counter;
    // for (int num : nums) {
    //     if (++counter[num] > nums.size() / 2) {
    //         return num;
    //     }
    // }
    for(int i = 0 ; i<nums.size()-1;i++){
        int cnt = 0;
        for(int j = 0 ; j<nums.size()-1;j++){
            // cout<<nums[j]<<endl;
            if(nums[i] == nums[j]){
                cnt++;
            }
        }   
        if(cnt >=nums.size()/2){
            return nums[i];
        }
    }
    return -1;
}


void printArray(vector<int> arr, int size)
{
    for (int i = 0; i < size; i++)
        cout <<" "<< arr[i];
}


//sort
int majorityElement2(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < (n/2)+1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (nums[j] > nums[j + 1])
                swap(nums[j], nums[j + 1]);
    // printArray(nums,nums.size());
    return nums[(n / 2)];
}


//recursion
int majorityElement3(vector<int>& nums, int l, int r) {
        if (l == r) {
            return nums[l];
        }
        int m = l + (r - l) / 2;
        int lm = majorityElement3(nums, l, m);
        int rm = majorityElement3(nums, m + 1, r);
        if (lm == rm) {
            return lm;
        }
        return count(nums.begin() + l, nums.begin() + r + 1, lm) > count(nums.begin() + l, nums.begin() + r + 1, rm) ? lm : rm;
}

//pair elimination
int majorityElement4(vector<int> nums){
    if(nums.size() == 1){
        return nums[0];
    }
    vector<int> temp;
    for(int i = 0 ; i < nums.size()-2 ; i+=2 ){
        if(nums[i] == nums[i+1]){
            temp.push_back(nums[i]);
        }
    }
    return majorityElement4(temp);
}


int main(){
    vector<int> l {2,5,2,2,1};
    cout<< majorityElement1(l)<<endl;
    cout<<endl;
    cout<< majorityElement2(l)<<endl;
    cout<<endl;
    cout<< majorityElement3(l,0,l.size()-1)<<endl;
    cout<<endl;
    cout<< majorityElement4(l)<<endl;
    return 0;
}