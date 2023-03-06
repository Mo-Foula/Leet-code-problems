class Solution
{
    public:

        bool isAvailable(vector<string> &board, int x, int y)
        {
            char c = board[x][y];
            return c == '.';
        }

    bool fillForDiagonal(vector<string> &board, int x, int y)
    {
        if (x < board.size() && y < board[x].size())
        {
            board[x][y] = 'X';
            return true;
        }
        return false;
    }

    void fillDiagonallyRight(vector<string> &board, int x, int y)
    {
        if (fillForDiagonal(board, x, y))
            fillDiagonallyRight(board, x + 1, y + 1);
    }

    void fillDiagonallyLeft(vector<string> &board, int x, int y)
    {
        if (fillForDiagonal(board, x, y))
            fillDiagonallyLeft(board, x + 1, y - 1);
    }

    void fillDiagonally(vector<string> &board, int x, int y)
    {
        fillDiagonallyLeft(board, x + 1, y - 1);
        fillDiagonallyRight(board, x + 1, y + 1);
    }

    void fillVerticallyAndDiagonally(vector<string> &board, int x, int y)
    {
       	// Fill vertically
        for (int i = x + 1; i < board.size(); i++)
        {
            board[i][y] = 'X';
        }

       	// Fill diagonally
        fillDiagonally(board, x, y);
    }

    void cleanBoard(vector<string> &board)
    {
        int n = board.size();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (board[i][j] == 'X')
                    board[i][j] = '.';
            }
        }
    }

    vector<vector < string>> soln;

    void solve(vector<string> &board, int x, int y)
    {
        while (y < board[x].size())
        {

            if (isAvailable(board, x, y))
            {
                vector<string> newBoard(board);
                newBoard[x][y] = 'Q';
                fillVerticallyAndDiagonally(newBoard, x, y);
                if (x + 1 < newBoard.size())
                {
                    solve(newBoard, x + 1, 0);
                }
                else
                {
                    cleanBoard(newBoard);
                    soln.push_back(newBoard);
                }
            }
            ++y;
        }
    }

    int totalNQueens(int n)
    {
        string empty(n, '.');
        vector<string> board = vector<string> (n, empty);
        solve(board, 0, 0);

        return soln.size();
    }
};