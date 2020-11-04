#ifndef CHESSBOARD_H
#define CHESSBOARD_H

#include <QWidget>
#include <QPainter>
#include <QString>
#include <QColor>
#include <QBrush>
#include <iostream>
#include <QResizeEvent>

class ChessBoard : public QWidget
{
    Q_OBJECT
public:
    explicit ChessBoard(QWidget *parent = nullptr);

protected:
    void paintEvent(QPaintEvent *event);
    virtual void resizeEvent(QResizeEvent* event);

//signals:

};

#endif // CHESSBOARD_H
