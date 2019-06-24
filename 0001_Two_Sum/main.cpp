#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> map;

        for (int i = 0; i < nums.size(); ++i) {
            auto it = map.find(target - nums[i]);
            if (it != map.end()) {
                return {it->second, i};
            }
            map[nums[i]] = i;
        }
        return {-1, -1};
    }
};

bool compare(vector<int> &a, vector<int> &b) {
    if (a.size() != b.size()) {
        return false;
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) {
            return false;
        }
    }

    return true;
}

void test_case_1() {
    vector<int> nums{2, 7, 11, 15};
    int target = 9;
    vector<int> ans{0, 1};
    vector<int> res = Solution().twoSum(nums, target);
}

int main(void) {
    test_case_1();

    return 0;
}