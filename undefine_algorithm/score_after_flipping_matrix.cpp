// 问题：
// 给定一个二维矩阵，矩阵中每个元素的值只可能是0和1，现在可以改变每行或者每列的值，但必须同时改变，例如"0,0,1,1"-->"1,1,0,0"
// 最终再计算每一行的元素组成的二进制数的和，例如
// Input: [[0,0,1,1],[1,0,1,0],[1,1,0,0]]，可修改为[[1,1,1,1],[1,0,0,1],[1,1,1,1]]
// Output: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39


// 思路：
// 此题虽然是medium，但还挺简单的，而且不需要什么特别的算法。其实就是遍历每一行的第一个元素，将其替换为1，因为二进制的1000比0111
// 然后再看每一列，如果0的数量比1的数量多，那么该列也需要替换，就可以了
// 另外看别人的代码时学到了一个东西，就是你不确定2和3/2谁大时，可以用2*2和3来比较，真是机智！


// 代码：
int matrixScore(vector<vector<int>>& A) {
    int rows = (int)A.size();
    int cols = (int)A[0].size();
        
    // 最高位为0，则翻转
    for(int i=0; i<rows; i++){
        if(A[i][0] == 0){
            for(int j=0; j<cols; j++)
                A[i][j] = 1 - A[i][j];
        }
    }

    // 每一列含0超过一半多，翻转
    for(int j=0; j<cols; j++){
        int cnt = 0;
        for(int i=0; i<rows; i++){
            if(A[i][j] == 0)
                cnt ++;
        }

        // 这里就是前面思路里提到的比较方法
        if(cnt * 2 > rows){
            for(int i=0; i<rows; i++){
                A[i][j] = 1 - A[i][j];
            }
        }
    }

    // calculate final answer
    int ret = 0;
    for(int i=0; i<rows; i++){
        for(int j=0; j<cols; j++)
            ret += A[i][j] * pow(2, cols - j - 1);
    }

    return ret;
}
