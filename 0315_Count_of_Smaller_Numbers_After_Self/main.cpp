#include <iostream>
#include <vector>

using namespace std;

class Solution {
  public:
    vector<int> countSmaller(vector<int> &nums) {
        int n = nums.size();
        vector<int> res(n);

        Node *head = nullptr;
        for (int i = n - 1; i >= 0; --i) {
            res[i] = insert(head, nums[i]);
        }
        return res;
    }

  private:
    struct Node {
        int value, count;
        Node *left, *right;
    };

    int insert(Node *&root, int value) {
        if (root == nullptr) {
            root = new Node{value, 0, nullptr, nullptr};
            return 0;
        }
        if (value < root->value) {
            root->count++;
            int res = insert(root->left, value);
            return res;
        }
        int res = root->count + insert(root->right, value) +
                  (value > root->value ? 1 : 0);
        return res;
    }
};

bool compare(vector<int> &nums1, vector<int> &nums2) {
    if (nums1.size() != nums2.size()) {
        return false;
    }
    for (unsigned i = 0; i < nums1.size(); ++i) {
        if (nums1[i] != nums2[i]) {
            return false;
        }
    }

    return true;
}

void test_case_1() {
    vector<int> nums{5, 2, 6, 1};
    vector<int> ans{2, 1, 1, 0};
    vector<int> res = Solution().countSmaller(nums);

    assert(compare(ans, res) == true);
}

void test_case_2() {
    vector<int> nums{-1, -1};
    vector<int> ans{0, 0};
    vector<int> res = Solution().countSmaller(nums);

    assert(compare(ans, res) == true);
}

int main(void) {
    test_case_1();
    test_case_2();

    return 0;
}