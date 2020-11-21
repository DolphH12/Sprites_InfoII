#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QRect Desktop = QApplication::desktop()->screenGeometry();
    x = Desktop.x();
    y = Desktop.y();
    ancho = Desktop.width();
    alto = Desktop.height();

    scene = new QGraphicsScene(x,y,ancho,alto);
    scene->setBackgroundBrush(QPixmap(":/imagenes/PC Computer - Among Us - Cafeteria Skeld.png"));
    ui->graphicsView->setScene(scene);

    personaje = new sprite();

    scene->addItem(personaje);

    personaje->setPos(900,500);

}

MainWindow::~MainWindow()
{
    delete ui;
}

