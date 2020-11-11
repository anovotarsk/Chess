#include "chessboard.h"

ChessBoard::ChessBoard(QWidget *parent) : QWidget(parent),
    m_logic(new ChessLogic() ),
    m_from(-1),
    m_to(-1) {
    this->setSizeIncrement(500, 500);
    this->setMinimumSize(400, 400);
}

ChessBoard::~ChessBoard() {
    delete m_logic;
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
    str[0] = '8';
    br.setColor("#FFEDA2");
    x = 0;
    y = size.width() / 10;
    for (int i = 0; i < 8; i++) {
        p->setBrush(br);
        p->drawRect(x, y, size.width() / 10, size.height() / 10);
        p->drawText(x, y, size.width() / 10, size.height() / 10, Qt::AlignCenter, str);
        str[0] -= 1;
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
    str[0] = '8';
    br.setColor("#FFEDA2");
    x =  size.width() /10 * 9;
    y = size.width() / 10;
    for (int i = 0; i < 8; i++) {
        p->setBrush(br);
        p->drawRect(x, y, size.width() / 10, size.height() / 10);
        p->drawText(x, y, size.width() / 10, size.height() / 10, Qt::AlignCenter, str);
        str[0] -= 1;
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

    drawFigures(p);
    delete p;
}

void ChessBoard::mousePressEvent(QMouseEvent *e) {
    QSize size =  this->size();
    int x = e->x() / (size.height() / 10);
    int y = e->y() / (size.height() / 10);

    if (e->button() == Qt::LeftButton) {
        m_from = m_logic->getArea(x - 1, y - 1);
        this->repaint();
    }
    if (e->button() == Qt::RightButton && m_from != -1) {
        m_to = m_logic->getArea(x - 1, y - 1);
        if (m_from != -1 && m_to != -1 && m_from != m_to) {
            auto i = m_logic->selectArea(m_from);
            if (std::find(i.begin(), i.end(), m_to) != i.end()) {
                m_logic->moveFigure(m_from, m_to);
                if (m_logic->getCheckmate() != No) {
                    QMessageBox msgBox;
                    int rez;

                    if (m_logic->getCheckmate() == White)
                        msgBox.setText("White lost!");
                    else {
                        msgBox.setText("Black lost!");
                    }
                    switch (m_logic->getCheckmate()) {
                        case White:
                            msgBox.setText("White lost!");
                            break;
                        case Black:
                            msgBox.setText("Black lost!");
                            break;
                        case Stalemate:
                            msgBox.setText("There was a stalemate!");
                    }
                    msgBox.setInformativeText("Do you want to play again?");
                    msgBox.setStandardButtons(QMessageBox::No | QMessageBox::Ok);
                    msgBox.setDefaultButton(QMessageBox::Ok);
                    rez = msgBox.exec();
                    switch (rez) {
                        case (QMessageBox::Ok):
                            delete m_logic;
                            m_logic = new ChessLogic;
                            break;
                        case (QMessageBox::No):
                            exit(0);
                    }
                }
            }
        }
        m_from = -1;
        m_to = -1;
        this->repaint();
    }
}

void ChessBoard::resizeEvent(QResizeEvent* event) {
    int lesser = std::min(event->size().width(), event->size().height());
    resize(lesser, lesser);
}

void ChessBoard::drawFigures(QPainter *p) {
    auto board = m_logic->getBoard();
    QSize size =  this->size();
    QRect rect(size.height() / 10, size.height() / 10, size.height() / 10, size.width() / 10);
    QPixmap img;

    //Рисует возможные ходы для выбраной фигуры
    if (m_from != -1) {
        QBrush br("#FF9C77");
        auto ways = m_logic->selectArea(m_from);
        int x;
        int y;

        for (auto i : ways) {
            x = (m_logic->getX(i) + 1) * (size.height() / 10);
            y = (m_logic->getY(i) + 1) * (size.height() / 10);
            p->setBrush(br);
            p->drawRect(x, y, size.height() / 10, size.height() / 10);
        }
    }

    //Рисует фигуры
    for (int i = 0; i < 64; i++) {
        if (board[i].first != ChessColor::No) {
            rect.setX(size.height() / 10 * (m_logic->getX(i) + 1));
            rect.setY(size.height() / 10 * (m_logic->getY(i) + 1));
            rect.setHeight(size.height() / 10);
            rect.setWidth(size.height() / 10);
            if (board[i].first == ChessColor::White) {
                switch (board[i].second) {
                    case ChessFigure::King:
                        img.load(WHITE_KING);
                        break;
                    case ChessFigure::Queen:
                        img.load(WHITE_QUEEN);
                        break;
                    case ChessFigure::Knight:
                        img.load(WHITE_KNIGHT);
                        break;
                    case ChessFigure::Rook:
                        img.load(WHITE_ROOK);
                        break;
                    case ChessFigure::Bishop:
                        img.load(WHITE_BISHOP);
                        break;
                    case ChessFigure::Pawn:
                        img.load(WHITE_PAWN);
                        //break;
                }
            }
            else {
                switch (board[i].second) {
                    case ChessFigure::King:
                        img.load(BLACK_KING);
                        break;
                    case ChessFigure::Queen:
                        img.load(BLACK_QUEEN);
                        break;
                    case ChessFigure::Knight:
                        img.load(BLACK_KNIGHT);
                        break;
                    case ChessFigure::Rook:
                        img.load(BLACK_ROOK);
                        break;
                    case ChessFigure::Bishop:
                        img.load(BLACK_BISHOP);
                        break;
                    case ChessFigure::Pawn:
                        img.load(BLACK_PAWN);
                        //break;
                }
            }
            p->drawPixmap(rect, img);
        }
    }
}
