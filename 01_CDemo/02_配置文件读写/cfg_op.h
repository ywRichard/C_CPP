#pragma once
#ifndef _INC_CFG_OP_H
#define _INC_CFG_OP_H

#ifdef _cplusplus
extern "C" {
#endif

	int GetCfgItem(char *pFileName/*in*/, char *pKey/*in*/, char *pValue/*in*/, int *pValueLen/*out*/);
	int WriteCfgItem(char *pFileName/*in*/, char *pItemName/*in*/, char *pItemValue/*in*/, int itemValueLen/*out*/);

#ifdef _cplusplus
}
#endif // _cplusplus

#endif



