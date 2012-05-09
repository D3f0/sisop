#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Conexion
    QObject::connect(this->ui->actionSalir, SIGNAL(triggered()), qApp, SLOT(quit()));
    this->escena = new QGraphicsScene(0, 0, 400, 300);
    this->ui->graphicsView->setScene(escena);

    this->escena->addRect(10, 10, 10, 10, QPen("black"), QBrush("red"));

    //QGraphicsItem *i = escena->addPixmap(QPixmap(":/imagenes/ajedrez.png"));
    hilo = new ReceptorMensajes();
    QObject::connect(hilo, SIGNAL(recepcionMensaje(int, int)),
                     this, SLOT(recepcionMensaje(int, int)));
    hilo->start();
    // Cargar una estadistica
    contadorDeProcesos = 0;
}


void MainWindow::actualizarEstadisticas(){
    ui->labelNumero->setText(QString::number(contadorDeProcesos));
}



void MainWindow::recepcionMensaje(int quien, int tipo){
    qDebug() << "Llega mensaje de " << quien << " con el tipo " << tipo;
    QGraphicsRectItem *item;

    if (!asociacionPidItem.contains(quien)){
        if (tipo == TIPO_CREADO) {
            int pos_x = qrand() % (int)escena->width();
            int pos_y = qrand() % (int)escena->height();
            item = escena->addRect(pos_x, pos_y, 10, 10, QPen(Qt::black), QBrush(Qt::yellow));
            asociacionPidItem[quien] = item;
        }
        contadorDeProcesos++;

    } else {
        item = asociacionPidItem[quien];
        switch (tipo) {
        case TIPO_ACTIVIDAD_1:
            item->setBrush(QBrush(Qt::red));
            break;
        case TIPO_ACTIVIDAD_2:
            item->setBrush(QBrush(Qt::blue));
            break;
        case TIPO_CERRADO:
            // Quitar el item de la pantalla
            escena->removeItem(item);
            // Quitar el item del arreglo
            asociacionPidItem.remove(quien);
            this->contadorDeProcesos++;

        }
    }
    // Actualizar
    actualizarEstadisticas();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeEvent(QEvent *e)
{
    QMainWindow::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }
}
