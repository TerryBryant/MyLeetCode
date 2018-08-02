// 问题：给定一个数组，数组的元素只有0和1，计算能插入多少个1（1可以和0挨着，但是不能和1挨着），例如10001，只能插入1个1

// 思路：此题级别是easy，不会太难，但是可能的情况很多，共分三种，假设待判断的数组长度为N：
// 1、全0的数组，此时能插入的1有(N+1)/2个，如{0}、{0,0,0}
// 2、0在最左侧或者最右侧，此时为N/2个，如{0,1}、{0,0,1}
// 3、0在两个1之间，此时为(N-1)/2个，如{1,0,0,1}、{1,0,0,0,1}
// 理清楚以上情况之后，还需要搞清楚边界，不然老是弄错，具体看下面的代码。虽然是O(n)，但写得太笨了
// 


// 代码：
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    int N = flowerbed.size();

    // 全0的情况
    int sum = 0;
    for(int i=0; i<N; i++) sum += flowerbed[i];
    if(sum == 0) return (N + 1) / 2 >= n;


    // 其它情况
    int begin = 0, end = 0;
    for(int i=0; i<flowerbed.size(); i++){
        if(flowerbed[i] == 1){
            begin = i;
            break;
        }
    }

    for(int i=flowerbed.size()-1; i>=0; i--){
        if(flowerbed[i] == 1){
            end = i;
            break;
        }
    }

    int cnt = 0;
    int mid = 0;
    for(int i=begin+1; i<end+1; i++){
        if(flowerbed[i] == 0)
            cnt ++;
        else{
            mid += (cnt - 1) / 2;
            cnt = 0;
        }
    }

    return (begin / 2 + (flowerbed.size() - end - 1) / 2 + mid) >= n;
}



// 看了下别人的代码，果然有更优雅的方式，如下
bool canPlaceFlowers(vector<int>& flowerbed, int n) {
    if (n==0) return true;
    auto sz = flowerbed.size()&(~1);
    int l = 0;
    for (int plot=0; plot<sz; plot+=2) {
        if (l==0 && flowerbed[plot]==0 && flowerbed[plot+1]==0) {
            n--;
            flowerbed[plot] = 1;
        }

        l = flowerbed[plot+1];
        if (n==0) return true;
    }
    if (n==1 && l==0) {
        if (sz<flowerbed.size()) {
            if (flowerbed[sz]==0) return true;
        }
        else if (flowerbed[sz-2]==0) return true;
        }        
    return false;
}

