#ifndef RECEPTORMENSAJES_H
#define RECEPTORMENSAJES_H
#include <QThread>
#include <mqueue.h>
#include "mq/comun.h"

class ReceptorMensajes : public QThread
{
    Q_OBJECT
public:
    explicit ReceptorMensajes(QObject *parent = 0);
    struct mq_attr attr;
    mqd_t cola;

    virtual void run();
signals:
    void recepcionMensaje(int quien, int tipo);
public slots:

};


#endif // RECEPTORMENSAJES_H
