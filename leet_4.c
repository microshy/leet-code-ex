/*基本思路: 建立一个能存放一半大小数组的table，将两个数组按顺序存入table，并根据奇偶计算中位数
  优化: 发现最后要使用的最多只有最近的两个数，因此，只要两个变量即可存储最近的两个数据即可
  问题: 不满足log(m+n)时间复杂度*/
#define odd 0
#define even 1
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int is_even = 0;
    if ((nums1Size + nums2Size) % 2) is_even = odd;
    else is_even = even;
    int total_num = (nums1Size + nums2Size) / 2 + 1;
    //int tbl[total_num];
    int cnt = 0;
    int cnt1 = 1;
    int cnt2 = 1;
    int last = 0;
    int next = 0;
    while (cnt < total_num)
    {
        last = next;
        if (cnt1 <= nums1Size && cnt2 <= nums2Size)
        {
            if (*nums1 <= *nums2)
            {
                next = *nums1;
                //tbl[cnt] = *nums1;
                cnt1 += 1;
                nums1 += 1;
            }
            else
            {
                next = *nums2;
                //tbl[cnt] = *nums2;
                cnt2 += 1;
                nums2 += 1;
            }
            cnt += 1;
        }
        else if (cnt1 <= nums1Size && cnt2 > nums2Size)
        {
            next = *nums1;
            //tbl[cnt] = *nums1;
            cnt1 += 1;
            nums1 += 1;
            cnt += 1;
        }
        else if (cnt1 > nums1Size && cnt2 <= nums2Size)
        {
            next = *nums2;
            //tbl[cnt] = *nums2;
            cnt2 += 1;
            nums2 += 1;
            cnt += 1;
        }

    }
    double res;
    if (is_even)
    {
        //res = tbl[(nums1Size + nums2Size) / 2 - 1] + tbl[(nums1Size + nums2Size) / 2];
        res = last + next;
        res = res / 2;
    }
    else
        //res = tbl[(nums1Size + nums2Size) / 2];
        res = next;
    return res;
}
