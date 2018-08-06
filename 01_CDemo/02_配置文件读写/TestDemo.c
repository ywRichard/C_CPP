#define _CRT_SECURE_NO_WARNINGS
# include <stdlib.h>
# include <string.h>
# include <stdio.h>
# include "cfg_op.h"

#define CFGNAME "c:/VDownload/myConfig.ini"

void mymenu() {
	printf("========================\n");
	printf("1:测试写配置文件\n");
	printf("2:测试读配置文件\n");
	printf("0:退出\n");
	printf("========================\n");
}

int TGetCfg() {
	char key[1024] = { 0 };
	char value[1024] = { 0 };
	int len = 0;

	printf("\n请键入key:");
	scanf("%s", key);

	int ret = GetCfgItem(CFGNAME/*in*/, key/*in*/, value/*in*/, &len/*out*/);
	if (ret != 0)
	{
		printf("func GetCfgItem() err\n");
		return ret;
	}

	printf("value =%s\n", value);
	printf("value length=%d\n", len);
	return ret;
}

int TWriteCfg() {
	char key[1024] = { 0 };
	char value[1024] = { 0 };

	printf("\n请键入key:");
	scanf("%s", key);
	printf("\n请键入value:");
	scanf("%s", value);

	int ret = WriteCfgItem(CFGNAME/*in*/, key/*in*/, value/*in*/, strlen(value)/*out*/);
	if (ret != 0)
	{
		printf("func WriteCfgItem() err\n");
	}

	printf("你输入的是: %s = %s\n", key, value);
	return ret;
}

void main() {
	int choice;

	for (;;)
	{
		//显示一个菜单
		mymenu();
		scanf("%d", &choice);
		switch (choice)
		{
		case 1://写配置文件
			TWriteCfg();
			break;
		case 2://读配置文件
			TGetCfg();
			break;
		case 0:
			exit(0);
			break;
		default:
			exit(0);
			break;
		}
	}

}