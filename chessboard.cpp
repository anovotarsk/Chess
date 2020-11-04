#include "chessboard.h"

ChessBoard::ChessBoard(QWidget *parent) : QWidget(parent)
{
    this->setSizeIncrement(500, 500);
    this->setMinimumSize(400, 400);
}

void changeColor(QBrush &br) {
    if (br.color() == "#FDE273")
        br.setColor("#FF8000");
    else
        br.setColor("#FDE273");
}

void ChessBoard::paintEvent(QPaintEvent *event) {
    QPainter *p = new QPainter(this);

    int x = 0;
    int y = 0;
    QBrush br(Qt::white);
    QSize size =  this->size();
    char str[] = "A";

    //Рисуем верхний ряд
    br.setColor("#FFEDA2");
    for (int i = 0; i < 10; i++) {
        p->setBrush(br);
        p->drawRect(x, y, size.width() / 10, size.height() / 10);
        if (i == 0 || i == 9)
            p->drawText(x, y, size.width() / 10, size.height() / 10, Qt::AlignCenter, " ");
        else {
            p->drawText(x, y, size.width() / 10, size.height() / 10, Qt::AlignCenter, str);
            str[0] += 1;
        }
        x += size.width() / 10;
    }
    //Рисуем левый столбик
    str[0] = '1';
    br.setColor("#FFEDA2");
    x = 0;
    y = size.width() / 10;
    for (int i = 0; i < 8; i++) {
        p->setBrush(br);
        p->drawRect(x, y, size.width() / 10, size.height() / 10);
        p->drawText(x, y, size.width() / 10, size.height() / 10, Qt::AlignCenter, str);
        str[0] += 1;
        y += size.width() / 10;
    }

    //Рисуем саму доску
    x = size.width() / 10;
    y = x;
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            changeColor(br);
            p->setBrush(br);
            p->drawRect(x, y, size.width() / 10, size.height() / 10);
            //changeColor(br);
            x += size.width() / 10;
        }
        changeColor(br);
        x = size.width() / 10;
        y += size.height() / 10;
    }

    //Рисуем правый столбик
    str[0] = '1';
    br.setColor("#FFEDA2");
    x =  size.width() /10 * 9;
    y = size.width() / 10;
    for (int i = 0; i < 8; i++) {
        p->setBrush(br);
        p->drawRect(x, y, size.width() / 10, size.height() / 10);
        p->drawText(x, y, size.width() / 10, size.height() / 10, Qt::AlignCenter, str);
        str[0] += 1;
        y += size.width() / 10;
    }

    //Рисуем нижний ряд
    x = 0;
    str[0] = 'A';
    br.setColor("#FFEDA2");
    for (int i = 0; i < 10; i++) {
        p->setBrush(br);
        p->drawRect(x, y, size.width() / 10, size.height() / 10);
        if (i == 0 || i == 9)
            p->drawText(x, y, size.width() / 10, size.height() / 10, Qt::AlignCenter, " ");
        else {
            p->drawText(x, y, size.width() / 10, size.height() / 10, Qt::AlignCenter, str);
            str[0] += 1;
        }
        x += size.width() / 10;
    }

    delete p;
}




void ChessBoard::resizeEvent(QResizeEvent* event) {
    int lesser = std::min(event->size().width(), event->size().height());
    resize(lesser, lesser);
}
