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
