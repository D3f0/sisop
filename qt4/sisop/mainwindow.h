#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui>
#include "receptormensajes.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void recepcionMensaje(int quien, int tipo);
protected:
    void changeEvent(QEvent *e);

private:
    Ui::MainWindow *ui;
    QGraphicsScene  *escena;
    ReceptorMensajes *hilo;
    QMap<int, QGraphicsRectItem*> asociacionPidItem;
    int contadorDeProcesos;

    void actualizarEstadisticas();
};

#endif // MAINWINDOW_H
