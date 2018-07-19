#include "stdafx.h"
#include "Txtdeal.h"



vector<CString> spiltcstring(CString strSource, CString ch){
	vector<CString> vecString;
	CString temp;
	int iPos = 0;

	temp =  strSource.Tokenize(ch, iPos);
	while (1){
		if (temp.Trim() != _T("")){
			vecString.push_back(temp);
		}
		else{
			break;
		}
		temp = strSource.Tokenize(ch, iPos);
	}
	return vecString;
	
}