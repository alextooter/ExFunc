#include "stdafx.h"
#include "windows.h"
#include "TCalcFuncSets.h"
#include "Funcs.h"

void TestPlugin1(int DataLen,float* pfOUT,float* pfINa,float* pfINb,float* pfINc)
{
	for(int i=0;i<DataLen;i++)
		pfOUT[i]=i;
}

void TestPlugin2(int DataLen,float* pfOUT,float* pfINa,float* pfINb,float* pfINc)
{
	if (verifyLicense(licenseFilename, logFilename)) {
		for (int i = 0; i<DataLen; i++)
		{
			pfOUT[i] = pfINa[i] + pfINb[i] + pfINc[i];
			pfOUT[i] = pfOUT[i] / 3;
		}
	}
	else
	{
		TestPlugin1(DataLen, pfOUT, pfINa, pfINb, pfINc);
	}
	
}

//���صĺ���
PluginTCalcFuncInfo g_CalcFuncSets[] = 
{
	{1,(pPluginFUNC)&TestPlugin1},
	{2,(pPluginFUNC)&TestPlugin2},
	{0,NULL},
};

//������TCalc��ע�ắ��
BOOL RegisterTdxFunc(PluginTCalcFuncInfo** pFun)
{
	if(*pFun==NULL)
	{
		(*pFun)=g_CalcFuncSets;
		return TRUE;
	}
	return FALSE;
}
