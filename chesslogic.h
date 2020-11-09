#ifndef CHESSLOGIC_H
#define CHESSLOGIC_H

#include <list>
#include <array>
#include <iostream>
#include <algorithm>


enum ChessFigure {
    King,
    Queen,
    Rook,
    Knight,
    Bishop,
    Pawn,
    None
};

enum ChessColor {
    White,
    Black,
    No
};

class ChessLogic {
public:
    ChessLogic();

    std::list<int> selectArea(int area);
    void moveFigure(int from, int to);
    std::array<std::pair<ChessColor, ChessFigure>, 64> getBoard();
    ChessColor getTurn();
    int getX(int area);
    int getY(int area);
    int getArea(int x, int y);

private:
    std::list<int> pawnWays(int area, bool check=false);
    std::list<int> rookWays(int area, bool check=false);
    std::list<int> bishopWays(int area, bool check=false);
    std::list<int> queenWays(int area, bool check=false);
    std::list<int> knightWays(int area);
    std::list<int> kingWays(int area, bool check=false);

    bool enemy_atack_king();


    ChessColor m_turn;
    std::array<std::pair<ChessColor, ChessFigure>, 64> m_board;
    bool m_whiteCastling;
    bool m_blackCastling;
    bool m_whiteLeftRookMove;
    bool m_whiteRightRookMove;
    bool m_blackLeftRookMove;
    bool m_blackRightRookMove;
    bool m_check;
};

#endif // CHESSLOGIC_H
