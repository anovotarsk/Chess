#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QWidget>
#include <QPainter>
#include <QString>
#include <QColor>
#include <QBrush>
#include <iostream>
#include <QResizeEvent>
#include <QImage>
#include <QPixmap>
#include <QRect>
#include <chesslogic.h>
#include <algorithm>
#include <QMessageBox>

#define WHITE_KING      "resources\\king_white.png"
#define WHITE_QUEEN     "resources\\queen_white.png"
#define WHITE_ROOK      "resources\\rook_white.png"
#define WHITE_KNIGHT    "resources\\knight_white.png"
#define WHITE_BISHOP    "resources\\bishop_white.png"
#define WHITE_PAWN      "resources\\pawn_white.png"

#define BLACK_KING      "resources\\king_black.png"
#define BLACK_QUEEN     "resources\\queen_black.png"
#define BLACK_ROOK      "resources\\rook_black.png"
#define BLACK_KNIGHT    "resources\\knight_black.png"
#define BLACK_BISHOP    "resources\\bishop_black.png"
#define BLACK_PAWN      "resources\\pawn_black.png"

class ChessBoard : public QWidget {
    Q_OBJECT
public:
    explicit ChessBoard(QWidget *parent = nullptr);
    ~ChessBoard();

protected:
    void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent* event);
    void mousePressEvent(QMouseEvent *e);

//signals:
private:
    void drawFigures(QPainter *p);

    ChessLogic *m_logic;
    int m_from;
    int m_to;
};

#endif // CHESSBOARD_H
