// 问题：在排序数组中寻找数字的出现次数
// 思路：出现排序数组，一般都是要用二分查找，速度可以达到O(logn)
// 本题目中，对于出现多个重复数字的情况时，可以单独用一种处理方式，分别计算出左边界和右边界

int GetFirstK(vector<int>data, int k, int start, int end){
    if(start > end) return -1;

    int mid = (start + end) / 2;
    if(data[mid] == k){
        if((mid > 0 && data[mid - 1] != k) || mid == 0)
            return mid;
        else
            end = mid - 1;
    } else if (data[mid] > k)
        end = mid - 1;
    else
        start = mid + 1;

    return GetFirstK(data, k, start, end);
}

int GetLastK(vector<int>data, int k, int start, int end){
    if(start > end) return -1;

    int mid = (start + end) / 2;
    int length = data.size();
    if(data[mid] == k){
        if((mid < length - 1 && data[mid + 1] != k) || mid == length - 1)
            return mid;
        else
            end = mid + 1;
    } else if (data[mid] > k)
        end = mid - 1;
    else
        start = mid + 1;

    return GetLastK(data, k, start, end);
}

int GetNumberOfK(vector<int>data, int k){
    int res = 0;
    int length = data.size();
    if(length > 0){
        int first = GetFirstK(data, k, 0, length - 1);
        int last = GetLastK(data, k, 0, length - 1);

        if(first > -1 && last > -1) res = last - first + 1;
    }

    return res;
}
