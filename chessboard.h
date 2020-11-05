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

#define WHITE_KING      "..\\Chess\\resources\\king_white.png"
#define WHITE_QUEEN     "..\\Chess\\resources\\queen_white.png"
#define WHITE_ROOK       "..\\Chess\\resources\\rook_white.png"
#define WHITE_KNIGHT    "..\\Chess\\resources\\knight_white.png"
#define WHITE_BISHOP    "..\\Chess\\resources\\bishop_white.png"
#define WHITE_PAWN      "..\\Chess\\resources\\pawn_white.png"

#define BLACK_KING      "..\\Chess\\resources\\king_black.png"
#define BLACK_QUEEN     "..\\Chess\\resources\\queen_black.png"
#define BLACK_ROOK       "..\\Chess\\resources\\rook_black.png"
#define BLACK_KNIGHT    "..\\Chess\\resources\\knight_black.png"
#define BLACK_BISHOP    "..\\Chess\\resources\\bishop_black.png"
#define BLACK_PAWN      "..\\Chess\\resources\\pawn_black.png"

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
