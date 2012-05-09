#include <mqueue.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "comun.h"


void esperaAleatoria(){
    int tiempo = rand() % 100;
    usleep(tiempo * 100000);
}

int main(void){
    mqd_t cola;

    srand(getpid());
    struct mq_attr attr = {
        .mq_flags = 0,    /* Message queue flags.  */
        .mq_maxmsg = 100,   /* Maximum number of messages.  */
        .mq_msgsize = 100,  /* Maximum message size.  */
        .mq_curmsgs = 0,  /* Number of messages currently queued.  */

    };

    cola = mq_open("/cola", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR, &attr);
    if (cola == -1) {
        fprintf(stderr, "Error abirendo la cola %s", strerror(errno));
        exit(1);
    }
    char *buff = "mensaje";
    Mensaje m;

    //printf("Enviando TIPO_CREADO\n");
    m.quien = getpid();
    m.tipo = TIPO_CREADO;
    mq_send(cola, (const char *)&m, sizeof(m), 0);
    esperaAleatoria();

    //printf("Enviando TIPO_ACTIVIDAD_1\n");
    m.quien = getpid();
    m.tipo = TIPO_ACTIVIDAD_1;
    mq_send(cola, (const char *)&m, sizeof(m), 0);
    esperaAleatoria();

    //printf("Enviando TIPO_ACTIVIDAD_2\n");
    m.quien = getpid();
    m.tipo = TIPO_ACTIVIDAD_2;
    mq_send(cola, (const char *)&m, sizeof(m), 0);
    esperaAleatoria();

    //printf("Enviando TIPO_CERRADO\n");
    m.quien = getpid();
    m.tipo = TIPO_CERRADO;
    mq_send(cola, (const char *)&m, sizeof(m), 0);
    esperaAleatoria();
}
       
