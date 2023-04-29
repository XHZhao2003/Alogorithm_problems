#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution{
    public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k){
        vector<int> result;
        deque<int> index;
        int length = nums.size();
        for (int i = 0; i < k; i++){
            while(!index.empty() && nums[i] > nums[index.back()]){
                index.pop_back();
            }
            index.push_back(i);
        }
        result.push_back(nums[index.front()]);
        for (int i = k; i < length; i++){
            while(!index.empty() && nums[i] > nums[index.back()]){
                index.pop_back();
            }
            index.push_back(i);
            if(index.front() < i - k + 1){
                index.pop_front();
            }
            result.push_back(nums[index.front()]);
        }
        return result;
    }
};
