// 问题：在一个m*n的棋盘上，每一格都放有一定价值的礼物，求从左上角到右下角，每次走一步，最多可以得到多少礼物
// 思路：这是一个典型的动态规划问题，当前格子的礼物和f(i,j)=max(f(i-1, j) + f(i, j-1)) + g(i, j)，其中g(i, j)为当前值
// 最直观的写法还是很简单的，但是书中给出了改进版本，一直没看明白，直到跟了代码，才清楚是怎么回事。。。

int getMaxValue_solution1(const int* values, int rows, int cols){
    if(values == nullptr || rows <= 0 || cols <= 0) return 0;
    
    int** maxValues = new int*[rows];
    for(int i=0; i<rows; i++)
        maxValues[i] = new int[cols];
    
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++){
            int left = 0;
            int up = 0;
            
            if(i > 0) up = maxValues[i-1][j];
            if(j > 0) left = maxValues[i][j-1];
            
            maxValues[i][j] = std::max(left, up) + values[i*cols + j];
        }
    }
    
    int result = maxValues[rows-1][cols-1];
    
    for(int i=0; i<rows; i++)
        delete[] maxValues[i];
    
    delete[] maxValues;
    
    return result;
}

// 改进后的结果，只需要申请一个长度为cols的数组即可
int getMaxValue_solution2(const int* values, int rows, int cols){
    if(values == nullptr || rows <= 0 || cols <= 0) return 0;

    int* maxValues = new int[cols];
    for(int i=0; i<rows; i++){
        for (int j = 0; j < cols; j++) {
            int up = 0;
            int left = 0;

            if(i > 0) up = maxValues[j];
            if(j > 0) left = maxValues[j-1];

            maxValues[j] = std::max(up, left) + values[i*cols + j];

        }
    }

    int maxValue = maxValues[cols - 1];
    delete[] maxValues;

    return maxValue;
}




int main(){
    int data[4][4] = {1, 10, 3, 8, 12, 2, 9, 6, 5, 7, 4, 11, 3, 7, 16, 5};
    cout<< getMaxValue_solution2(*data, 4, 4)<<endl;

    return 1;
}
