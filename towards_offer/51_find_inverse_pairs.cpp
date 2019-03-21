// 问题：计算数组的逆序对个数，例如{7, 5, 6, 4}的逆序对共5个
// 思路：此题可以参考归并排序来进行实现
// 归并排序主要就是分治，在治的过程中，可以用于计算逆序对，例如对于2,3,8和1,6两段，首先排序是不改变逆序对的数量
// 2比1大，则2后面的都比1大，假设2对应的指针是i，那么8对应的就是mid，这样逆序对数量就是(mid - i + 1)

int count = 0;
void merge(int* nums, int left, int mid, int right, int* temp){
    int i = left;
    int j = mid + 1;
    int t = 0;

    while (i<=mid && j<=right){
        if(nums[i] <= nums[j])
            temp[t++] = nums[i++];
        else{
            temp[t++] = nums[j++];
            count += (mid -i + 1);
        }


    }

    while (i<=mid){
        temp[t++] = nums[i++];
    }

    while (j<=right){
        temp[t++] = nums[j++];

    }

    t = 0;
    while (left <= right)
        nums[left++] = temp[t++]; // temp里面是排好序的，需要赋回给原始数组
}



void sort(int* nums, int left, int right, int* temp){
    if(left < right){
        int mid = (left + right) / 2;
        sort(nums, left, mid, temp);
        sort(nums, mid + 1, right, temp);
        merge(nums, left, mid, right, temp);
    }
}


void sort(int* nums, int length){
    int* temp = new int[length];
    sort(nums, 0, length - 1, temp);
    delete[] temp;
}
