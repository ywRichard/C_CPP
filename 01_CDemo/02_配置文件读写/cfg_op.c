#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>

#define MaxLine 2048

int GetCfgItem(char *pFileName/*in*/, char *pKey/*in*/, char *pValue/*in*/, int *pValueLen/*out*/) {
	int		ret = 0;
	if (pFileName == NULL)
	{
		ret = -1;
		printf("Func GetCfgItem errr: pFileName is NULL\n");
		goto End;
	}

	FILE	*fp = NULL;
	char	*pTmp = NULL;
	char	*pkeyTmp = NULL;

	char lineBuf[MaxLine];

	fp = fopen(pFileName, "r");
	if (fp == NULL)
	{
		printf("Func GetCfgItem errr: fopen err\n");
		ret = -1;
		goto End;
	}

	while (!feof(fp))
	{
		memset(lineBuf, 0, sizeof(lineBuf));
		fgets(lineBuf, MaxLine, fp);

		pTmp = strchr(lineBuf, '=');//判断 = 
		if (pTmp == NULL)
		{
			continue;
		}

		pTmp = strstr(lineBuf, pKey);//判断 键是否存在 
		if (pTmp == NULL)
		{
			continue;
		}
		pTmp = pTmp + strlen(pKey);

		pTmp = strchr(pTmp, '=');//定位到=，并移到后面
		if (pTmp == NULL)
		{
			continue;
		}
		pTmp = pTmp + 1;

		ret = trimStr(&pTmp);
		if (ret != 0)
		{
			goto End;
		}
		strcpy(pValue, pTmp);
		*pValueLen = strlen(pTmp);
	}

End:
	if (fp != NULL)
	{
		fclose(fp);
	}
	return ret;
}

//写配置项
//实现流程
//循环读每一行，检查key配置项是否存在，若存在修改对应value值；若不存在，文件末尾添加 "key = value"
//难点：如何修改文件流中的值
int WriteCfgItem(char *pFileName/*in*/, char *pKey/*in*/, char *pValue/*in*/, int itemValueLen/*out*/) {
	int		ret = 0, iTag = 0, length = 0;
	FILE	*fp = NULL;
	char	lineBuf[MaxLine];
	char	*pTmp = NULL, *pBegin = NULL, *pEnd = NULL;
	char	filebuf[1024 * 8] = { 0 };

	if (pFileName == NULL || pKey == NULL || pValue == NULL)
	{
		ret = -1;
		printf("Func SetCfgItem() err: param err \n");
		goto End;
	}

	fp = fopen(pFileName, "r+");
	if (fp == NULL)
	{
		fp = fopen(pFileName, "w+t");
		if (fp == NULL)
		{
			ret = -2;
			printf("fopen() err\n");
			goto End;
		}
	}

	fseek(fp, 0L, SEEK_END);//把文件指针从0位置开始，移动到文件末尾
	//获取文件长度
	length = ftell(fp);

	fseek(fp, 0, SEEK_SET);

	if (length > 1024 * 8)
	{
		ret = -3;
		printf("文件超过1024*8, unsupport\n");
		goto End;
	}

	while (!feof(fp))
	{
		//读每一行
		memset(lineBuf, 0, sizeof(lineBuf));
		pTmp = fgets(lineBuf, MaxLine, fp);
		if (pTmp == NULL)
		{
			break;
		}
		//key关键词是否在本行
		pTmp = strstr(lineBuf, pKey);
		if (pTmp == NULL)//如果不在，直接copy到filebuf中
		{
			strcat(filebuf, lineBuf);
			continue;
		}
		else
		{
			sprintf(lineBuf, "%s=%s\n", pKey, pValue);
			strcat(filebuf, lineBuf);
			//若存在key
			iTag = 1;
		}
	}
	if (iTag == 0)//key不存在，向文件打开追加
	{
		fprintf(fp, "%s = %s\n", pKey, pValue);//向打开的文件流追加内容
	}
	else//若key关键字存在，则重新创建文件
	{
		if (fp!=NULL)
		{
			fclose(fp);
			fp = NULL;
		}
		fp = fopen(pFileName, "w+t");//用'w'打开已存在的文件写入就会清空原有的文件内容
		if (fp==NULL)
		{
			ret = -4;
			printf("fopen() err. \n");
			goto End;
		}
		fputs(filebuf, fp);
	}

End:
	if (fp != NULL)
	{
		fclose(fp);
		fp = NULL;
	}
	return 0;
}


int trimStr(char **buffer) {
	if (buffer == NULL)
	{
		printf("func trimStr");
		return -1;
	}

	char *tmp = *buffer;
	char *pBegin = NULL, *pEnd = NULL;
	while (1)
	{
		if (*tmp == ' ')
		{
			tmp++;
		}
		else
		{
			break;
		}
	}
	pBegin = tmp;

	while (1)
	{
		if ((*tmp == ' ' || *tmp == '\n'))
		{
			break;
		}
		else
		{
			tmp++;
		}
	}
	pEnd = tmp;
	char pValue[1024] = { 0 };
	memcpy(pValue, pBegin, pEnd - pBegin);
	*buffer = pValue;

	return 0;
}