/*
IDEA: Recursive + Bredth First Search

Start swim from (0,0), do bfs for k steps
    if found a island, then bfs to mark all connected island
                            add all surround water to a list
                            for each surround water, do a bfs swim

*/

#include <fstream>
#include <string>

#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

void MarkIsland(vector<vector<char>>& board, int c, int r, int k);
void Swim(vector<vector<char>>& board, int r, int c, int k);
void PrintBoard(vector<vector<char>>& board, int r, int c);

// Direction lists
vector<pair<int, int>> DIRS{ { 0, 1 },{ 0, -1 },{ 1, 0 },{ -1, 0 },{ 1, 1 },{ 1, -1 },{ -1, 1 },{ -1, -1 } }; // 4-directions

// validation for boundry check
bool InBoard(vector<vector<char>>& board, int c, int r) {
    int row = board.size();
    int col = board[0].size();

    if (r < 0 || r >= row || c < 0 || c >= col) {
        return false;
    }

    return true;
}

// BFS - Swimming
void Swim(vector<vector<char>>& board, int r, int c, int k) {
    // corner case
    int row = board.size();
    if (row == 0) { return; }

    int col = board[0].size();
    if (col == 0) { return;}


    set<pair<int, int>> visited;
    queue<pair<int, int>> q;
    q.push({ r, c }); // starting point
    visited.insert({ r, c });

    int nStep = 0;

    while (!q.empty()) {

        if (nStep == k) {
            break;
        }

        int size = q.size();

        // for all moves count as one swimming step
        for (int i = 0; i < size; ++i) {

            pair<int, int> curr = q.front();
            q.pop();

            int x = curr.first;
            int y = curr.second;

            // go all 8-directions
            for (int j = 0; j < DIRS.size(); ++j) {
                pair<int, int> offset = DIRS[j];
                int nextC = x + offset.first;
                int nextR = y + offset.second;

                pair<int, int> next(nextC, nextR);

                if (!InBoard(board, nextC, nextR) || visited.find(next) != visited.end()) {
                    continue;
                }

                if (board[nextR][nextC] == '+') {
                    continue; // island already marked.
                }

                if (board[nextR][nextC] == '*') {
                    // bfs mark connected island
                    MarkIsland(board, nextC, nextR, k);
                    continue;
                }

                q.push(next);
                visited.insert(next);
            }

        }//for each step
        ++nStep;
    }

}

// BFS - mark all connected island
void MarkIsland(vector<vector<char>>& board, int c, int r, int k) {

    int row = board.size();
    int col = board[0].size();

    set<pair<int, int>> visited;
    queue<pair<int, int>> q;

    vector<pair<int, int>> surrondWater;

    pair<int, int> start(r, c);
    q.push(start); // starting point
    visited.insert(start);
    board[r][c] = '+';

    while (!q.empty()) {

        pair<int, int> curr = q.front();
        q.pop();

        int x = curr.first;
        int y = curr.second;

        // go all 8-directions
        for (int j = 0; j < DIRS.size(); ++j) {
            pair<int, int> offset = DIRS[j];
            int nextC = x + offset.first;
            int nextR = y + offset.second;

            pair<int, int> next(nextC, nextR);

            if (!InBoard(board, nextC, nextR) || visited.find(next) != visited.end() || board[nextR][nextC] == '+') {
                continue;
            }

            // if it is connected to water
            if (board[nextR][nextC] == '.') {
                surrondWater.push_back(next); // add to water vector for swimming
                visited.insert(next);         // mark visited
            }else if (board[nextR][nextC] == '*') {
                board[nextR][nextC] = '+';
                q.push(next);
                visited.insert(next);
                PrintBoard(board, row, col);
            }
        }
    }

    // after mark all island, do SWIM for each surround water
    for (pair<int, int> water : surrondWater) {
        Swim(board, water.second, water.first, k);
    }
}

void PrintBoard(vector<vector<char>>& board, int r, int c) {
    cout << "Print Board : " << endl;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            cout << board[i][j] << " ";
        }
        cout << "\r\n";
    }
}

int main() {

    /* 
        Test 
        6 * 6 board

        . . . . . .
        . * * . . .
        . . . . . .
        . . . . . .
        . . . . * *
        . . . . . .

        when k = 1, it only mark the second row
        when k = 2, it shall mark all island to +
    */

    //int r = 6;
    //int c = 6;

    //vector<vector<char>> board(r, vector<char>(c, '.'));
    //board[1][1] = '*';
    //board[1][2] = '*';
    //board[4][4] = '*';
    //board[4][5] = '*';

    ifstream in(".\\Island.txt");
    string line;
    int col = 0;
    int row = 0;
    vector<vector<char>> board;
    while (getline(in, line)) {
        ++row;
        col = 0;
        vector<char> temp;
        for (char c : line) {
            temp.push_back(c);
            ++col;
        }
        
        board.push_back(temp);
    }

    PrintBoard(board, row, col);
  
    int k =7;
    Swim(board, 0, 0, k);
    PrintBoard(board, row, col);
    return 0;
}