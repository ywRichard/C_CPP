#pragma once
typedef int(*EncData)(unsigned char *inData, int inDataLen, unsigned char *outDatalen, void *ref, int refLen);
typedef int(*DecData)(unsigned char *inData, int inDataLen, unsigned char *outDatalen, void *ref, int refLen);


//客户端初始化, 获取handle上下文
int cltSocketInit(void **handle /*out*/);
//客户端发报文
int cltSocketSend(void *handle/*in*/, unsigned char *buf/*in*/, int bufflen/*in*/);
//客户端收报文
int cltSocketRev(void *handle/*in*/, unsigned char *buf/*in*/, int *bufflen/*in out*/);
//客户端释放资源
int cltSocketDestroy(void *handle/*in*/);
int cltSocket_EncAndSend(void *handle, unsigned char *buf, int buflen, EncData encDataCallback, void *ref, int refLen);
