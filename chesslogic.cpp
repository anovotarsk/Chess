#include "chesslogic.h"

ChessLogic::ChessLogic() {
    m_board = std::array<std::pair<ChessColor, ChessFigure>, 64>();
    m_turn = ChessColor::White;
    m_whiteCastling = false;
    m_blackCastling = false;
    m_whiteLeftRookMove = false;
    m_whiteRightRookMove = false;
    m_blackLeftRookMove = false;
    m_blackRightRookMove = false;
    m_check = false;

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
    if (area < 0 || area >= 64)
        return -1;
    return area % 8;
}

int ChessLogic::getY(int area) {
    if (area < 0 || area >= 64)
        return -1;
    return area / 8;
}

int ChessLogic::getArea(int x, int y) {
    int area = 0;
    if (x < 0 || x >= 8 || y < 0 || y >= 8) {
        return -1;
    }

    for (int i = 0; i < y; i++)
        area += 8;
    area += x;
    return area;
}

ChessColor ChessLogic::getTurn() {
    return m_turn;
}

void ChessLogic::moveFigure(int from, int to) {
    if (m_turn != m_board[from].first)
        return;

    m_board[to] = m_board[from];
    m_board[from] = std::pair<ChessColor, ChessFigure>(ChessColor::No, ChessFigure::None);
    if (m_board[to].first == ChessColor::White)
        m_turn = ChessColor::Black;
    else
        m_turn = ChessColor::White;
    if (m_board[to].second == ChessFigure::King) {
        if (from - to == 2) {
            m_board[to + 1] = m_board[to - 2];
            m_board[to - 2] = std::pair<ChessColor, ChessFigure>(ChessColor::No, ChessFigure::None);
        }
        if (from - to == -2) {
            m_board[to - 1] = m_board[to + 1];
            m_board[to + 1] = std::pair<ChessColor, ChessFigure>(ChessColor::No, ChessFigure::None);
        }
        if (m_board[to].first == ChessColor::White)
            m_whiteCastling = true;
        else
            m_blackCastling = true;
    }

    if (m_board[to].second == ChessFigure::Rook && m_board[to].first == ChessColor::Black) {
        if (from == 0)
            m_blackLeftRookMove = true;
        if (from == 7)
            m_blackRightRookMove = true;
    }
    if (m_board[to].second == ChessFigure::Rook && m_board[to].first == ChessColor::White) {
        if (from == 56)
            m_whiteLeftRookMove = true;
        if (from == 63)
            m_whiteRightRookMove = true;
    }

    if (enemy_atack_king() == true)
        m_check = true;
    else
        m_check = false;
    std::cerr << "Check - " << m_check << std::endl;
}

std::list<int> ChessLogic::pawnWays(int area, bool check) {
    std::list<int> ways;

    if (check) {
        if (m_board[area].first == ChessColor::White) {
            if (getX(area) > 0 && getY(area) > 0)
                ways.push_back(area - 9);
            if (getX(area) < 7 && getY(area) > 0)
                ways.push_back(area - 7);
        }
        if (m_board[area].first == ChessColor::Black) {
            if (getX(area) > 0 && getY(area) < 7)
                ways.push_back(area + 7);
            if (getX(area) < 7 && getY(area) < 7)
                ways.push_back(area + 9);
            return ways;
        }
    }

    if (m_board[area].first == ChessColor::White) {
        if (area - 8 > 0 && m_board[area - 8].first == ChessColor::No) {
            ways.push_back(area - 8);
            if (getY(area) == 6 && m_board[area - 16].first == ChessColor::No)
                ways.push_back(area - 16);
        }
        if (getX(area) > 0 && getY(area) > 0 && m_board[area - 9].first == ChessColor::Black)
            ways.push_back(area - 9);
        if (getX(area) < 7 && getY(area) > 0 && m_board[area - 7].first == ChessColor::Black)
            ways.push_back(area - 7);
    }
    if (m_board[area].first == ChessColor::Black) {
        if (area + 8 < 64 && m_board[area + 8].first == ChessColor::No) {
            ways.push_back(area + 8);
            if (getY(area) == 1 && m_board[area + 16].first == ChessColor::No)
                ways.push_back(area + 16);
        }
        if (getX(area) > 0 && getY(area) < 7 && m_board[area + 7].first == ChessColor::White)
            ways.push_back(area + 7);
        if (getX(area) < 7 && getY(area) < 7 && m_board[area + 9].first == ChessColor::White)
            ways.push_back(area + 9);
    }
    return ways;
}

std::list<int> ChessLogic::rookWays(int area, bool check) {
    std::list<int> ways;

    for (int i = 1; i <= getX(area); i++) {
        if (m_board[area - i].second == ChessFigure::None)
            ways.push_back(area - i);
        else {
            if (check
                && m_board[area - i].second == ChessFigure::King
                && m_board[area - i].first != m_board[area].first)
                ways.push_back(area - i);
            else {
                if (m_board[area - i].first != m_board[area].first)
                    ways.push_back(area - i);
                break;
            }
        }
    }

    for (int i = getX(area), j = 1; i < 7; i++, j++) {
        if (m_board[area + j].second == ChessFigure::None)
            ways.push_back(area + j);
        else {
            if (check
                && m_board[area + j].second == ChessFigure::King
                && m_board[area + j].first != m_board[area].first)
                ways.push_back(area + j);
            else {
                if (m_board[area + j].first != m_board[area].first)
                    ways.push_back(area + j);
                break;
            }
        }
    }

    for (int i = 1; i - 1 < getY(area); i++) {
        if (m_board[area - 8 * i].second == ChessFigure::None)
            ways.push_back(area - 8 * i);
        else {
            if (check
                && m_board[area - 8 * i].second == ChessFigure::King
                && m_board[area - 8 * i].first != m_board[area].first)
                ways.push_back(area - 8 * i);
            else {
                if (m_board[area - 8 * i].first != m_board[area].first)
                    ways.push_back(area - 8 * i);
                break;
            }
        }
    }

    for (int i = getY(area), j = 1; i < 7; i++, j++) {
        if (m_board[area + 8 * j].second == ChessFigure::None)
            ways.push_back(area + 8 * j);
        else {
            if (check
                && m_board[area + 8 * j].second == ChessFigure::King
                && m_board[area + 8 * j].first != m_board[area].first)
                ways.push_back(area + 8 * j);
            else {
                if (m_board[area + 8 * j].first != m_board[area].first)
                    ways.push_back(area + 8 * j);
                break;
            }
        }
    }

//    if (m_check) {
//        for (int i = 0;)
//    }
    return ways;
}

std::list<int> ChessLogic::bishopWays(int area, bool check) {
    std::list<int> ways;

    for (int i = 1; i <= getX(area) && area - i - 8 * i > -1; i++) {
        if (m_board[area - i - 8 * i].second == ChessFigure::None)
            ways.push_back(area - i - 8 * i);
        else {
            if (check
                && m_board[area - i - 8 * i].second == ChessFigure::King
                && m_board[area - i - 8 * i].first != m_board[area].first)
                ways.push_back(area - i - 8 * i);
            else {
                if (m_board[area - i - 8 * i].first != m_board[area].first)
                    ways.push_back(area - i - 8 * i);
                break;
            }
        }
    }

    for (int i = getX(area), j = 1; i < 7 && area + j + 8 * j < 64; i++, j++) {
        if (m_board[area + j + 8 * j].second == ChessFigure::None)
            ways.push_back(area + j + 8 * j);
        else {
            if (check
                && m_board[area + j + 8 * j].second == ChessFigure::King
                && m_board[area + j + 8 * j].first != m_board[area].first)
                ways.push_back(area + j + 8 * j);
            else {
                if (m_board[area + j + 8 * j].first != m_board[area].first)
                    ways.push_back(area + j + 8 * j);
                break;
            }
        }
    }

    for (int i = 1;
         i - 1 < getY(area) && area - 8 * i + i > -1 && getX(area) + i < 8;
         i++) {
        if (m_board[area - 8 * i + i].second == ChessFigure::None)
            ways.push_back(area - 8 * i + i);
        else {
            if (check
                && m_board[area - 8 * i + i].second == ChessFigure::King
                && m_board[area - 8 * i + i].first != m_board[area].first)
                ways.push_back(area - 8 * i + i);
            else {
                if (m_board[area - 8 * i + i].first != m_board[area].first)
                    ways.push_back(area - 8 * i + i);
                break;
            }
        }
    }

    for (int i = getY(area), j = 1;
         i < 7 && area + 8 * j - j < 64 && getX(area) - j > -1;
         i++, j++) {
        if (m_board[area + 8 * j - j].second == ChessFigure::None)
            ways.push_back(area + 8 * j - j);
        else {
            if (check
                && m_board[area + 8 * j - j].second == ChessFigure::King
                && m_board[area + 8 * j - j].first != m_board[area].first)
                ways.push_back(area + 8 * j - j);
            else {
                if (m_board[area + 8 * j - j].first != m_board[area].first)
                    ways.push_back(area + 8 * j - j);
                break;
            }
        }
    }

    return ways;
}

std::list<int> ChessLogic::queenWays(int area, bool check) {
    std::list<int> ways;

    for (auto i : rookWays(area, check))
        ways.push_back(i);

    for (auto i : bishopWays(area, check))
        ways.push_back(i);

    return ways;
}

std::list<int> ChessLogic::knightWays(int area) {
    std::list<int> ways;


    if (getX(area) > 0
        && getX(area + 15) != -1
        && getY(area + 15) != -1
        && m_board[area + 15].first != m_board[area].first) {
        ways.push_back(area + 15);
    }
    if (getX(area) > 1
        && getX(area + 6) != -1
        && getY(area + 6) != -1
        && m_board[area + 6].first != m_board[area].first) {
        ways.push_back(area + 6);
    }
    if (getX(area) < 7
        && getX(area + 17) != -1
        && getY(area + 17) != -1
        && m_board[area + 17].first != m_board[area].first) {
        ways.push_back(area + 17);
    }
    if (getX(area) < 6
        && getX(area + 10) != -1
        && getY(area + 10) != -1
        && m_board[area + 10].first != m_board[area].first) {
        ways.push_back(area + 10);
    }
    if (getX(area) < 7
        && getX(area - 15) != -1
        && getY(area - 15) != -1
        && m_board[area - 15].first != m_board[area].first) {
        ways.push_back(area - 15);
    }
    if (getX(area) < 6
        && getX(area - 6) != -1
        && getY(area - 6) != -1
        && m_board[area - 6].first != m_board[area].first) {
        ways.push_back(area - 6);
    }
    if (getX(area) > 0
        && getX(area - 17) != -1
        && getY(area - 17) != -1
        && m_board[area - 17].first != m_board[area].first) {
        ways.push_back(area - 17);
    }
    if (getX(area) > 1
        && getX(area - 10) != -1
        && getY(area - 10) != -1
        && m_board[area - 10].first != m_board[area].first) {
        ways.push_back(area - 10);
    }

    return ways;
}

std::list<int> ChessLogic::kingWays(int area, bool check) {
    std::list<int> ways;
    std::list<int> tmp;
    std::list<int> enemy;
    std::list<std::list<int>> enemy_ways;

    if (getX(area) > 0 && m_board[area - 1].first != m_board[area].first)
        tmp.push_back(area - 1);
    if (getY(area) > 0 && m_board[area - 8].first != m_board[area].first)
        tmp.push_back(area - 8);
    if (getX(area) > 0 && getY(area) > 0 && m_board[area - 9].first != m_board[area].first)
        tmp.push_back(area - 9);

    if (getY(area) < 7 && m_board[area + 8].first != m_board[area].first)
        tmp.push_back(area + 8);
    if (getX(area) > 0 && getY(area) < 7 && m_board[area + 7].first != m_board[area].first)
        tmp.push_back(area +7);

    if (getX(area) < 7 && m_board[area + 1].first != m_board[area].first)
        tmp.push_back(area + 1);
    if (getX(area) < 7 && getY(area) > 0 && m_board[area - 7].first != m_board[area].first)
        tmp.push_back(area - 7);
    if (getX(area) < 7 && getY(area) < 7 && m_board[area + 9].first != m_board[area].first)
        tmp.push_back(area + 9);

    if (check)
        return tmp;
    for (int i = 0; i < 64; i++) {
        if (m_board[i].first != ChessColor::No
            && m_board[i].first != m_board[area].first) {
            switch (m_board[i].second) {
                case (ChessFigure::Pawn):
                    enemy_ways.push_back(pawnWays(i, true));
                    break;
                case (ChessFigure::Rook):
                    enemy_ways.push_back(rookWays(i, true));
                    break;
                case (ChessFigure::Bishop):
                    enemy_ways.push_back(bishopWays(i, true));
                    break;
                case (ChessFigure::Queen):
                    enemy_ways.push_back(queenWays(i, true));
                    break;
                case (ChessFigure::Knight):
                    enemy_ways.push_back(knightWays(i));
                    break;
                case (ChessFigure::King):
                    enemy_ways.push_back(kingWays(i, true));
                    break;
            }
        }
    }

    for (auto i : tmp) {
        bool flag = true;
        for (auto j : enemy_ways) {
            if (std::find(j.begin(), j.end(), i) != j.end()) {
                flag = false;
                break;
            }
        }
        if (flag)
            ways.push_back(i);
    }

    if ((m_board[area].first == ChessColor::White && m_whiteCastling == false)
        || (m_board[area].first == ChessColor::Black && m_blackCastling == false)) {
        if (m_board[area + 1].first == ChessColor::No
            && m_board[area + 2].first == ChessColor::No
            && ((!m_whiteRightRookMove && m_board[area].first == ChessColor::White)
                || (!m_blackRightRookMove && m_board[area].first == ChessColor::Black))) {
            bool flag = true;
            for (auto j : enemy_ways) {
                if (std::find(j.begin(), j.end(), area + 1) != j.end()
                    && std::find(j.begin(), j.end(), area + 2) != j.end()) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ways.push_back(area + 2);
        }
        if (m_board[area - 1].first == ChessColor::No
            && m_board[area - 2].first == ChessColor::No
            && m_board[area - 3].first == ChessColor::No
            && ((!m_whiteLeftRookMove && m_board[area].first == ChessColor::White)
                || (!m_blackLeftRookMove && m_board[area].first == ChessColor::Black))) {
            bool flag = true;
            for (auto j : enemy_ways) {
                if (std::find(j.begin(), j.end(), area - 1) != j.end()
                    || std::find(j.begin(), j.end(), area - 2) != j.end()
                    || std::find(j.begin(), j.end(), area - 3) != j.end()) {
                    flag = false;
                    break;
                }
            }
            if (flag)
                ways.push_back(area - 2);
        }
    }

    return ways;
}

std::list<int> ChessLogic::selectArea(int area) {
    if (m_board[area].first == ChessColor::No || m_board[area].first != m_turn)
        return std::list<int>();
    switch (m_board[area].second) {
        case (ChessFigure::Pawn):
            return pawnWays(area);
        case (ChessFigure::Rook):
            return rookWays(area);
        case (ChessFigure::Bishop):
            return bishopWays(area);
        case (ChessFigure::Queen):
            return queenWays(area);
        case (ChessFigure::Knight):
            return knightWays(area);
        case (ChessFigure::King):
            return kingWays(area);
    }
    return std::list<int>();
}

bool ChessLogic::enemy_atack_king() {
    std::list<std::list<int>> enemy_ways;
    int king;

    for (king = 0; king < 64; king++) {
        if (m_board[king].first == m_turn && m_board[king].second == ChessFigure::King) {
            break;
        }
    }

    for (int i = 0; i < 64; i++) {
        if (m_board[i].first != ChessColor::No
            && m_board[i].first != m_board[king].first) {
            switch (m_board[i].second) {
                case (ChessFigure::Pawn):
                    enemy_ways.push_back(pawnWays(i, true));
                    break;
                case (ChessFigure::Rook):
                    enemy_ways.push_back(rookWays(i, true));
                    break;
                case (ChessFigure::Bishop):
                    enemy_ways.push_back(bishopWays(i, true));
                    break;
                case (ChessFigure::Queen):
                    enemy_ways.push_back(queenWays(i, true));
                    break;
                case (ChessFigure::Knight):
                    enemy_ways.push_back(knightWays(i));
                    break;
                case (ChessFigure::King):
                    enemy_ways.push_back(kingWays(i, true));
                    break;
            }
        }
    }

    for (auto i : enemy_ways) {
        if (std::find(i.begin(), i.end(), king) != i.end()) {
            return true;
        }
    }
    return false;
}
