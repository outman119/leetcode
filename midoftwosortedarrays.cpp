class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int total = m + n;
        if (total & 0x1)
        {
            return findkth(nums1, m, nums2, n, total / 2 + 1);
        }
        else
        {
            return (findkth(nums1, m, nums2, n, total / 2 ) +
                findkth(nums1, m, nums2, n, total / 2 + 1)) / 2;
        }
    }
private:
    double findkth(vector<int>&nums1, int lena, vector<int>&nums2, int lenb, int k)
    {
        if (lena > lenb)
        {
            return findkth(nums2, lenb, nums1, lena, k);
        }
        if (lena == 0)
        {
            return nums2[k - 1];
        }
        if (k == 1)
        {
            return min(nums1[0], nums2[0]);
        }
        int pa = min(k / 2, lena);
        int pb = k - pa;
        if (nums1[pa - 1] < nums2[pb - 1])
        {
            vector<int>nums;
            nums.assign(nums1.begin() + pa, nums1.end());
            return findkth(nums, lena - pa, nums2, lenb, k - pa);
        }
        else if (nums1[pa-1] > nums2[pb-1])
        {
            vector<int>nums;
            nums.assign(nums2.begin() + pb, nums2.end());
            return findkth(nums1, lena, nums, lenb - pb, k - pb);
        }
        else
        {
            return nums1[pa-1];
        }
    }
};
