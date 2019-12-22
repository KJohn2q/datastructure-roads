#ifndef SQQUEUE_H
#define SQQUEUE_H

#define QUEUE_INIT_SIZE 100
#define INCREMENTSIZE 10

#include <stdio.h>
#include <stdlib.h>
#include "../common.h"

typedef int QElemType;

typedef struct {
	QElemType *elem;
	int length;
	int basesize;
}SqQueue;




#endif
