#include <iostream>
#include <vector>

using std::vector;
using std::cout;
using std::endl;

void swap(int &a, int &b){
    int tmp = a;
    a = b;
    b = tmp;
}

void bubbleSort(vector<int>& nums){
    int N = (int)nums.size();

    for(int i=0; i<N; i++){
        bool flag = true;
        for(int j=i+1; j<N; j++){
            if(nums[j] < nums[i]){
                swap(nums[i], nums[j]);
                flag = false;
            }
        }
        if(flag) break;     // sort done
    }
}

void chooseSort(vector<int>& nums){
    int N = (int)nums.size();

    for(int i=0; i<N; i++){
        int min = nums[i];
        int index = i;
        for(int j=i+1; j<N; j++){
            if(nums[j] < min){
                min = nums[j];
                index = j;
            }
        }
        swap(nums[i], nums[index]);
    }
}

void insertSort(vector<int>& nums){
    int N = (int)nums.size();

    for(int i=1; i<N; i++){
        for(int j=0; j<i; j++){
            if(nums[i] < nums[j]) swap(nums[i], nums[j]);
        }

    }
}

void hillSort(vector<int>& nums){
    ;
}

void merge(int* nums, int left, int mid, int right, int* temp){
    int i = left;
    int j = mid + 1;
    int t = 0;

    while (i<=mid && j<=right){
        if(nums[i] <= nums[j])
            temp[t++] = nums[i++];
        else
            temp[t++] = nums[j++];
    }

    while (i<=mid){
        temp[t++] = nums[i++];
    }

    while (j<=right){
        temp[t++] = nums[j++];
    }

    t = 0;
    while (left <= right)
        nums[left++] = temp[t++];
}

void mergeSort(int* nums, int left, int right, int* temp){
    if(left < right){
        int mid = (left + right) / 2;
        sort(nums, left, mid, temp);
        sort(nums, mid + 1, right, temp);
        merge(nums, left, mid, right, temp);
    }
}


void mergeSort(int* nums, int length){
    int* temp = new int[length];
    sort(nums, 0, length - 1, temp);
}


int main(){
    int nums[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    sort(nums, sizeof(nums) / sizeof(int));

    for(int num: nums) cout<<num<<" ";

    return 1;
}

int main() {
    vector<int> nums = {34, 2, 4, 567, 18, 999, 450};

    //bubbleSort(nums);
    //chooseSort(nums);
    //insertSort(nums);
    hillSort(nums);


    for(int num: nums) cout<<num<<" ";
    cout<<endl;


    return 0;
}
