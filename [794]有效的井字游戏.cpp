//
// Created by zyx on 2021/12/9.
//

// Daily Problem

//leetcode submit region begin(Prohibit modification and deletion)
class Solution {
public:
// OLD
#if 0
    bool validTicTacToe(vector<string>& board) {
        int x_sum,o_sum;
        x_sum = o_sum = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if(board[i][j] == 'X')
                    ++x_sum;
                else if(board[i][j] == 'O')
                    ++o_sum;
            }
        }
        if(x_sum-o_sum!=1 && x_sum != o_sum){
            return false;
        }


        string role;
        bool col_result = false;
        for (int i = 0; i < 3; ++i) {
            if(colFind(board,i)){
                if(col_result)
                    return false;
                col_result = true;
                role = board[0][i];
            }
        }
        bool row_result = false;
        for (int i = 0; i < 3; ++i) {
            if(rowFind(board,i)){
                if(col_result)
                    return true;
                if(row_result)
                    return false;
                row_result = true;
                role = board[i][0];
            }
        }
        bool downLeft_result = false;
        if(downLeftFind(board)){
            if(row_result || col_result){
                return true;
            }
            downLeft_result = true;
            role = board[0][2];
        }
        bool downRight_result = false;
        if(downRightFind(board)) {
            if(row_result || col_result){
                return true;
            }
            if(downLeft_result)
                return true;
            downRight_result = true;
            role = board[0][0];
        }
        if(row_result || col_result || downRight_result || downLeft_result){
            if(role == "X"){
                if(x_sum<=o_sum)
                    return false;
            }else{
                if(x_sum>o_sum)
                    return false;
            }
        }
        return true;
    }
    bool colFind(vector<string>& board,int col){
        bool isX = false;
        bool isO = false;
        for (int i = 0; i < 3; ++i) {
            if(board[i][col]=='X') {
                if(isO)
                    return false;
                isX = true;
            }
            else if(board[i][col]=='O'){
                if(isX)
                    return false;
                isO = true;
            } else{
                return false;
            }
        }
        return true;
    }

    bool rowFind(vector<string>& board,int row){
        bool isX = false;
        bool isO = false;
        for (int i = 0; i < 3; ++i) {
            if(board[row][i]=='X') {
                if(isO)
                    return false;
                isX = true;
            }
            else if(board[row][i]=='O'){
                if(isX)
                    return false;
                isO = true;
            }else
                return false;
        }
        return true;
    }

    bool downRightFind(vector<string>& board){
        bool isX = false;
        bool isO = false;
        for (int i = 0; i < 3; ++i) {
            if(board[i][i]=='X') {
                if(isO)
                    return false;
                isX = true;
            }
            else if(board[i][i]=='O'){
                if(isX)
                    return false;
                isO = true;
            } else
                return false;
        }
        return true;
    }
    bool downLeftFind(vector<string>& board){
        bool isX = false;
        bool isO = false;
        for (int i = 0,j = 2; i < 3 && j>=0; ++i,--j) {
            if(board[i][j]=='X') {
                if(isO)
                    return false;
                isX = true;
            }
            else if(board[i][j]=='O'){
                if(isX)
                    return false;
                isO = true;
            }else
                return false;
        }
        return true;
    }
#endif
    bool validTicTacToe(vector<string> &board) {
        int x_sum, o_sum;
        x_sum = o_sum = 0;
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == 'X')
                    ++x_sum;
                else if (board[i][j] == 'O')
                    ++o_sum;
            }
        }
        if (x_sum - o_sum != 1 && x_sum != o_sum)
            return false;
        // 如果X赢 X的数量与O的差值应该为1
        if (check(board, 'X') && x_sum - o_sum != 1)
            return false;
        // 如果O赢 X的数量与O的差值应该相等
        if (check(board, 'O') && x_sum != o_sum)
            return false;
        return true;
    }
    bool check(vector<string> &board, char p) {
        for (int i = 0; i < 3; ++i) {
            // 行判断
            if (p == board[i][0] && p == board[i][1] && p == board[i][2])
                return true;
            // 列判断
            if (p == board[0][i] && p == board[1][i] && p == board[2][i])
                return true;
        }
        // 对角线判断
        if (p == board[0][0] && p == board[1][1] && p == board[2][2])
            return true;
        if (p == board[0][2] && p == board[1][1] && p == board[2][0])
            return true;
        return false;
    }
};
//leetcode submit region end(Prohibit modification and deletion)
