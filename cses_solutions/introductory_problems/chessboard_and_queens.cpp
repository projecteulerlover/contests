#include <bits/stdc++.h>

using namespace std;

constexpr int N = 8;

struct Solver {
    Solver(vector<string>& board) : board_(move(board)) {}

    bool DFS(int r) {
        if (r == N) {
            ++count_;
            return true;
        }
        for (int c=0; c<N; ++c) {
            if (board_[r][c] == '*' || cs_ & (1 << c) || ds_ & (1 << (c + r)) || ss_ & (1 << (N + c - r)))
                continue;
            cs_ ^= 1 << c;
            ds_ ^= 1 << (c+r);
            ss_ ^= 1 << (N+c-r);
            DFS(r+1);
            cs_ ^= 1 << c;
            ds_ ^= 1 << (c+r);
            ss_ ^= 1 << (N+c-r);
        }
        return false;
    }

    vector<string> board_;
    int cs_ = 0, ds_ = 0, ss_ = 0, count_ = 0;
};

int main() {
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<string> board(N);
    for (int i=0; i<N; ++i)
        cin >> board[i];
    
    auto solver = Solver(board);
    solver.DFS(0);
    cout << solver.count_ << '\n';
    return EXIT_SUCCESS;
}