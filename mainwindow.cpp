#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setCentralWidget(new ChessBoard);
    //this->add
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void changeColor(QBrush &br) {
//    if (br.color() == "white")
//        br.setColor(Qt::black);
//    else
//        br.setColor(Qt::white);
//}

//void MainWindow::paintEvent(QPaintEvent *event) {
//    QPainter *p = new QPainter(ui->widget);

//    int x = 0;
//    int y = 0;
//    QBrush br(Qt::white);
//    QSize size =  this->size();

//    for (int i = 0; i < 8; i++) {
//        for (int j = 0; j < 8; j++) {
//            p->setBrush(br);
//            p->drawRect(x, y, x + size.width() / 8, y + size.height() / 8);
//            changeColor(br);
//            x += size.width() / 8;
//        }
//        changeColor(br);
//        x = 0;
//        y += size.height() / 8;
//    }

//    delete p;
//}
