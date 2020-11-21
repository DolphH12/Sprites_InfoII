#include "sprite.h"

sprite::sprite(QObject *parent) : QObject(parent)
{

    timer = new QTimer();
    filas = 0;
    columnas = 0;

    pixmap = new QPixmap(":/imagenes/amongus.png");

    //dimensiones de cada imagen
    ancho = 80;
    alto = 100;

    timer->start(50);
    connect(timer,&QTimer::timeout,this,&sprite::Actualizacion);


}

void sprite::Actualizacion()
{
    columnas += 80;
    if(columnas >= 960){
        columnas =0;
    }
    this->update(-ancho/2,-alto/2,ancho,alto);
}

QRectF sprite::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2,-alto/2,*pixmap,columnas,0,ancho,alto);
}

