#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "des.h"

#define MaxSize 4096

int FileSymFunc(const char *pfile1, const char *pfile2) {
	int ret = 0;
	if (pfile1 == NULL || pfile2 == NULL)
	{
		ret = -1;
		goto End;
	}

	FILE *fp1 = NULL, *fp2 = NULL;
	fp1 = fopen(pfile1, "rb");
	if (fp1 == NULL)
	{
		ret = -1;
		goto End;
	}
	fp2 = fopen(pfile2, "wb");
	if (fp2 == NULL)
	{
		ret = -1;
		goto End;
	}

	unsigned char plain[4096] = { 0 };
	int plainlen = 0, tmplen = 0;
	unsigned char cryptbuf[4096] = { 0 };
	int cryptlen = 0;

	while (!feof(fp1))//feof(),文件没有结束就返回0，结束了就返回非零值
	{
		plainlen = fread(plain, 1, 4096, fp1);
		if (feof(fp1))//读取完数据后，判断文件是否结束
		{
			break;
		}

		ret = DesEnc_raw(plain, plainlen, cryptbuf, &cryptlen);//完整读取4096个字节的数据，不padding
		if (ret != 0)
		{
			printf("Func DesEnc() err:%d\n", ret);
			goto End;
		}

		tmplen = fwrite(cryptbuf, 1, cryptlen, fp2);
		if (tmplen != cryptlen)
		{
			ret = -1;
			printf("写入大于4K文件失败，请检查是否磁盘已满\n");
			goto End;
		}
	}

	//加密小于4k的文件
	ret = DesEnc(plain, plainlen, cryptbuf, &cryptlen);
	if (ret != 0)
	{
		printf("Func DesEnc() err:%d\n", ret);
		goto End;
	}

	tmplen = fwrite(cryptbuf, 1, cryptlen, fp2);
	if (tmplen != cryptlen)
	{
		ret = -1;
		printf("写入小于4K文件失败，请检查是否磁盘已满\n");
		goto End;
	}

End:
	if (fp1 != NULL)
	{
		fclose(fp1);
	}
	if (fp2 != NULL)
	{
		fclose(fp2);
	}
	return ret;
}

int FileSymDec(const char *pfile1, const char *pfile2) {
	int ret = 0;
	FILE *fp1 = NULL, *fp2 = NULL;
	if (pfile1 == NULL || pfile2 == NULL)
	{
		ret = -1;
		goto End;
	}

	fp1 = fopen(pfile1, "rb");
	if (fp1 == NULL)
	{
		ret = -1;
		goto End;
	}
	fp2 = fopen(pfile2, "wb");
	if (fp2 == NULL)
	{
		ret = -1;
		goto End;
	}

	unsigned char encData[MaxSize] = { 0 }, decBuf[MaxSize] = { 0 };
	int	encDatalen = 0, decBuflen = 0, tmpLen = 0;

	while (!feof(fp1))
	{
		encDatalen = fread(encData, 1, MaxSize, fp1);
		if (feof(fp1)) {//读完文件后判断是否结束，未结束则读取数据的字节 = 4096；最后一次就读取的字节数小于等于4096
			break;
		}

		//解密4k文件
		ret = DesDec_raw(encData, encDatalen, decBuf, &decBuflen);
		if (ret != 0)
		{
			printf("Func DesEnc() err:%d\n", ret);
			goto End;
		}
		tmpLen = fwrite(decBuf, 1, decBuflen, fp2);
		if (tmpLen != decBuflen)
		{
			printf("写入小于4K文件失败，请检查是否磁盘已满\n");
			ret = -1;
			goto End;
		}
	}

	//解密小于4k文件
	ret = DesDec_raw(encData, encDatalen, decBuf, &decBuflen);
	if (ret != 0)
	{
		printf("Func DesEnc() err:%d\n", ret);
		goto End;
	}
	tmpLen = fwrite(decBuf, 1, decBuflen, fp2);
	if (tmpLen != decBuflen)
	{
		printf("写入小于4K文件失败，请检查是否磁盘已满\n");
		ret = -1;
		goto End;
	}

End:
	if (fp1 != NULL)
	{
		fclose(fp1);
	}
	if (fp2 != NULL)
	{
		fclose(fp2);
	}

	return ret;
}

int main() {
	int		ret = 0;
	const char *file1 = "c:/VDownload/plain.txt";
	const char *file2 = "c:/VDownload/Encrption.txt";
	const char *file3= "c:/VDownload/Decrption_1.txt";

	//ret = FileSymFunc(file1, file2);
	ret = FileSymDec(file2, file3);
	if (ret != 0)
	{
		printf("Func FileSymFunc err\n");
	}
	system("pause");
	return;
}