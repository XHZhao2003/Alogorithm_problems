/*
    LeetCode 239 滑动窗口最大值
    滑动窗口经典题目。利用一个双向队列，维护队头元素为最大值（索引）。有两个关键点
    1. 每次遇到新元素时，如果他比队列中一些元素大， 那么这些元素就不再产生任何影响，可以直接删去
    2，随着窗口的滑动，没有因为上述原因删除的元素也会自然地移出窗口。而我们没有维护加入队列先后的信息。我们在push/pop时，对元素的索引（下标）进行操作，这样就携带了这一信息。
       每次只需要判断下标是否超出窗口界限。
*/


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
