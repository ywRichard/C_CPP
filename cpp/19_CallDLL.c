#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef int(*CltSocketInit)();
typedef int(*CltSocketSend)(unsigned char *buf /*in*/, int buflen/*in*/);
typedef int(*CltSocketRev)(unsigned char *buf /*in*/, int *buflen/*in*/);
typedef int(*CltSocketDestroy)();

int main() {
	//HINSTANCE hInstance = GetModuleHandle(NULL);
	HINSTANCE hInstance;

	hInstance = LoadLibrary("C:\\SocketClient.dll");
	CltSocketInit cltSocketInit;//define func pointer var
	CltSocketSend cltSocketSend;
	CltSocketRev cltSocketRev;
	CltSocketDestroy cltSocketDestroy;

	cltSocketInit = (CltSocketInit)GetProcAddress(hInstance, "cltSocketInit");
	cltSocketSend = (CltSocketSend)GetProcAddress(hInstance, "cltSocketSend");
	cltSocketRev = (CltSocketRev)GetProcAddress(hInstance, "cltSocketRev");
	cltSocketDestroy = (CltSocketDestroy)GetProcAddress(hInstance, "cltSocketDestroy");

	unsigned char buf[1024];
	int buflen = 0;
	strcpy(buf, "12344");
	buflen = strlen(buf);
	int ret = cltSocketInit();
	ret = cltSocketSend(buf, buflen);
	ret = cltSocketRev(buf, &buflen);
	ret = cltSocketDestroy();

	printf("hello...\n");
	system("pause");
	return 0;
}
