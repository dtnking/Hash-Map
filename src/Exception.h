#ifndef _EXCEPTION_H
#define _EXCEPTION_H


#define HASH_BOUNDARY_ERROR  0
#define HASH_DATA_NULL 			 1
#define HASH_KEY_ERROR 			 2
#define HASH_KEY_NA					 3

typedef struct Exception Exception;
typedef Exception* ExceptionPtr;
struct Exception{
	char *msg;
	int errorCode;
};

Exception *createException(char *msg,int errorCode);
void freeException(Exception *e);
void dumpException(Exception *e);

#endif // _EXCEPTION_H
