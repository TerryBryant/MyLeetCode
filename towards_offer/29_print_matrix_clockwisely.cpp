// 问题：顺时针打印矩阵
// 思路：首先找到打印停止的条件，即长宽都要大于两倍的index
// 其次找到每一圈的截至条件：从左到右没有；从上到下，必须是终止row大于起始row；从右到左，必须是终止col大于起始col，且终止row大于起始row，
// 即两行两列；从下到上，至少三行两列
// 此题还是有难度的，一下子写出来不容易


void PrintMatrixInCircle(int** numbers, int rows, int cols, int start){
    int endX = cols - 1 - start;
    int endY = rows - 1 - start;

    // 从左到右打印
    for (int i = start; i <= endX; i++) {
        cout<<numbers[start][i]<<" ";
    }

    // 从上到下打印
    if(start < endY){
        for (int i = start+1; i <= endY; i++) {
            cout<<numbers[i][endX]<<" ";
        }
    }

    // 从右到左打印
    if(start < endX && start < endY){
        for (int i = endX - 1; i >= start ; i--) {
            cout<<numbers[endY][i]<<" ";
        }
    }

    // 从下到上打印
    if(start < endX && start < endY - 1){
        for (int i = endY - 1; i >= start + 1; i--) {
            cout<<numbers[i][start]<<" ";
        }
    }
}

void PrintMatrixClockwisely(int** numbers, int rows, int cols){
    if(numbers == nullptr || rows <= 0 || cols <= 0) return;

    int start = 0;

    while (rows > start * 2 && cols > start * 2){
        PrintMatrixInCircle(numbers, rows, cols, start);
        start++;
    }
}
