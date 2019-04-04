// 问题：n皇后问题
// 思路：采用回溯法，构建一颗树，写好判断条件，然后不断回溯，
// 代码还是写不出来，估计是对算法认识不够深刻


vector<vector<string>> res;

bool isValid(vector<string>& cur, int row, int col){
    for (int i = 0; i < row; ++i) {
        if(cur[i][col] == 'Q')
            return false;
    }

    for(int i=row-1, j=col-1; i>=0 && j>= 0; --i, --j){
        if(cur[i][j] == 'Q')
            return false;
    }

    for(int i=row-1, j=col+1; i>=0 && j<cur.size(); --i, ++j){
        if(cur[i][j] == 'Q')
            return false;
    }

    return true;
}


void helper(vector<string>& cur, int row){
    if(row == cur.size()){
        res.push_back(cur);
        return;
    }

    for (int col = 0; col < cur.size(); ++col) {
        if(isValid(cur, row, col)){
            cur[row][col] = 'Q';
            helper(cur, row+1);
            cur[row][col] = '.';
        }
    }
}


void solveNQueens(int n){
    vector<string> cur(n, string(n, '.'));
    helper(cur, 0);
}


int main(){
    solveNQueens(8);
    for(auto rr : res){
        for(auto r : rr){
            cout<<r<<endl;
        }

        cout<<"-----------------------------------"<<endl;
    }

    cout<<"has "<<res.size()<<" answers"<<endl;
}
