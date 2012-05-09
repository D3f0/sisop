#include "receptormensajes.h"
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include <QMessageBox>
#include <errno.h>
#include <QDebug>
#include "mq/comun.h"

ReceptorMensajes::ReceptorMensajes(QObject *parent) :
    QThread(parent)
{
    attr.mq_flags = 0;
    attr.mq_maxmsg = 100;
    attr.mq_msgsize = 100;
    const char *nombreCola = "/cola";

    cola = mq_open(nombreCola, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR, &attr);

    if (cola == -1) {
        QString s = "No se puede abrir la cola: ";
        s.append(this->trUtf8(strerror(errno)));
        QMessageBox::critical(NULL, "No se puede abrir la cola", s);
    }
}

void ReceptorMensajes::run(){
    if (cola == -1){
        qDebug("No atiendo la cola porque es invalida");
        return;
    }
    qDebug("Esperando mensajes");
    Mensaje m;
    ssize_t len = 0;
    while (1){
        // Espero un nuevo mensaje
        len = mq_receive(cola, (char*) &m, attr.mq_msgsize, 0);
        if (len == -1) {
            QString s = "Error de recepcion de mensaje: ";
            s.append(this->trUtf8(strerror(errno)));
            QMessageBox::critical(NULL, "Recepcion de mensaje", s);
        }
        // qDebug() << "Recibi mensaje" << QString::number((int)len);
        // Emite la señal con el pid y el tipo de mensaje para que
        // la ventana lo dibuje.
        emit recepcionMensaje(m.quien, m.tipo);
    }

}
