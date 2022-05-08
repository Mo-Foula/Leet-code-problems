class Solution {
public:
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    vector<int> ret(m + n);
    if (m == 0 && n == 0) {
        return;
    }
    if (m == 0){
          nums1 =  nums2;
        return;
    }
      
    if (n == 0)
        return;
    auto itr1 = nums1.begin(), itr2 = nums2.begin();
    int sum = m + n;
    int i = 0;
    while (m > 0 && n > 0) {
        if (*itr1 < *itr2) {
            ret[i] = *itr1;
            itr1++;
            i++;
            m--;
        } else {
            ret[i] = *itr2;
            itr2++;
            i++;
            n--;
        }
    }
    if (m > 0)
        for (; itr1 < nums1.end() && m > 0; itr1++, i++, m--)
            ret[i] = *itr1;
    if (n > 0)
        for (; itr2 < nums2.end() && n > 0; itr2++, i++, n--)
            ret[i] = *itr2;
    nums1 = ret;
}

};