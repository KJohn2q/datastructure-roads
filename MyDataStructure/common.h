#include <stdio.h>
#include <ctype.h>
#include <malloc.h>  /* malloc() �� */
#include <malloc.h>  /* INT_MAX�� */
#include <string.h> 
#include <stdlib.h> /* atoi() �� */
#include <io.h> /* eof() */
#include <math.h> /* floor(),ceil(),abs()*/


#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;  /* Status�Ǻ��������ͣ���ֵ�Ǻ������״̬���룬��OK�� */
typedef int Boolean; /* Boolean�ǲ������ͣ���ֵ��TRUE��FALSE */ 
typedef int ElemType;  /* ���ݽṹ�д�ŵ����� */ 
