#include <stdio.h>
#include <ctype.h>
#include <malloc.h>  /* malloc() 等 */
#include <malloc.h>  /* INT_MAX等 */
#include <string.h> 
#include <stdlib.h> /* atoi() 等 */
#include <io.h> /* eof() */
#include <math.h> /* floor(),ceil(),abs()*/


#define TRUE 1
#define FALSE 0
#define OK  1
#define ERROR 0
#define INFEASIBLE -1
#define OVERFLOW -2

typedef int Status;  /* Status是函数的类型，其值是函数结果状态代码，如OK等 */
typedef int Boolean; /* Boolean是布尔类型，其值是TRUE或FALSE */ 
typedef int ElemType;  /* 数据结构中存放的类型 */ 
