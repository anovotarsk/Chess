#include "chesslogic.h"

ChessLogic::ChessLogic() : m_turn(ChessColor::White) {
    m_board = std::array<std::pair<ChessColor, ChessFigure>, 64>();

    for (int i = 0; i < 64; i++)
        m_board[i] = std::pair<ChessColor, ChessFigure>(ChessColor::No, ChessFigure::None);
    for (int i = 8; i < 16; i++)
        m_board[i] = std::pair<ChessColor, ChessFigure>(ChessColor::Black, ChessFigure::Pawn);
    for (int i = 48; i < 56; i++)
        m_board[i] = std::pair<ChessColor, ChessFigure>(ChessColor::White, ChessFigure::Pawn);

    m_board[0] = std::pair<ChessColor, ChessFigure>(ChessColor::Black, ChessFigure::Rook);
    m_board[1] = std::pair<ChessColor, ChessFigure>(ChessColor::Black, ChessFigure::Knight);
    m_board[2] = std::pair<ChessColor, ChessFigure>(ChessColor::Black, ChessFigure::Bishop);
    m_board[3] = std::pair<ChessColor, ChessFigure>(ChessColor::Black, ChessFigure::Queen);
    m_board[4] = std::pair<ChessColor, ChessFigure>(ChessColor::Black, ChessFigure::King);
    m_board[5] = m_board[2];
    m_board[6] = m_board[1];
    m_board[7] = m_board[0];

    m_board[56] = std::pair<ChessColor, ChessFigure>(ChessColor::White, ChessFigure::Rook);
    m_board[57] = std::pair<ChessColor, ChessFigure>(ChessColor::White, ChessFigure::Knight);
    m_board[58] = std::pair<ChessColor, ChessFigure>(ChessColor::White, ChessFigure::Bishop);
    m_board[59] = std::pair<ChessColor, ChessFigure>(ChessColor::White, ChessFigure::Queen);
    m_board[60] = std::pair<ChessColor, ChessFigure>(ChessColor::White, ChessFigure::King);
    m_board[61] = m_board[58];
    m_board[62] = m_board[57];
    m_board[63] = m_board[56];
}

std::array<std::pair<ChessColor, ChessFigure>, 64> ChessLogic::getBoard() {
    return m_board;
}

int ChessLogic::getX(int area) {
    return area % 8;
}

int ChessLogic::getY(int area) {
    return area / 8;
}
