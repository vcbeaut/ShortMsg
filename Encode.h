#include "stdafx.h"
#include <string>

using namespace std;

void C2W(const char* szSrc, WCHAR* wszDst, int nMaxLen)
{
	int vMinLen = MultiByteToWideChar(CP_ACP, 0, szSrc, -1, NULL, 0);
	if (vMinLen > nMaxLen)
	{
		MessageBoxA(NULL, szSrc, "×ª»»³ÉUNICODE×Ö´®Ê§°Ü", MB_ICONWARNING);
		return;
	}
	MultiByteToWideChar(CP_ACP, 0, szSrc, -1, wszDst, vMinLen);
}

// WCHAR×ªchar 
void W2C(const WCHAR* wszSrc, char* szDst, int nMaxLen)
{
	int vMinLen = WideCharToMultiByte(CP_ACP, 0, wszSrc, -1, NULL, 0, NULL, FALSE);
	if (vMinLen > nMaxLen)
	{
		MessageBoxW(NULL, wszSrc, L"×ª»»³ÉANSI×Ö´®Ê§°Ü", MB_ICONWARNING);
		return;
	}
	WideCharToMultiByte(CP_ACP, 0, wszSrc, -1, szDst, vMinLen, NULL, FALSE);
}
CString ANSIToUnicode(char * szChar)
{
	int len = 0;
	len = MultiByteToWideChar(CP_ACP, 0, szChar, -1, NULL, 0);
	TCHAR * p;
	p = new TCHAR[len + 1];
	memset(p, 0, (len + 1) * sizeof(TCHAR));
	MultiByteToWideChar(CP_ACP, 0, szChar, -1, p, len);
	CString ss;
	ss.Format(_T("%s"), p);
	delete[]p;
	return ss;
}
string UnicodeToANSI(CString & szStr)
{
	int len = 0;
	len = WideCharToMultiByte(CP_ACP, 0, szStr, -1, NULL, 0, NULL, NULL);

	char * pElementText;
	pElementText = new char[len + 1];
	memset(pElementText, 0, sizeof(len + 1));
	WideCharToMultiByte(CP_ACP, 0, szStr, -1, pElementText, len, NULL, NULL);

	string ss;
	ss = pElementText;
	delete[]pElementText;
	return ss;

}


//URL GBK±à½âÂë
char dec2hexChar(short int n) {
	if (0 <= n && n <= 9) {
		return char(short('0') + n);
	}
	else if (10 <= n && n <= 15) {
		return char(short('A') + n - 10);
	}
	else {
		return char(0);
	}
}

short int hexChar2dec(char c) {
	if ('0' <= c && c <= '9') {
		return short(c - '0');
	}
	else if ('a' <= c && c <= 'f') {
		return (short(c - 'a') + 10);
	}
	else if ('A' <= c && c <= 'F') {
		return (short(c - 'A') + 10);
	}
	else {
		return -1;
	}
}

string escapeURL(const string &URL)
{
	string result = "";
	for (unsigned int i = 0; i<URL.size(); i++) {
		char c = URL[i];
		if (
			('0' <= c && c <= '9') ||
			('a' <= c && c <= 'z') ||
			('A' <= c && c <= 'Z') ||
			c == '/' || c == '.'
			) {
			result += c;
		}
		else {
			int j = (short int)c;
			if (j < 0) {
				j += 256;
			}
			int i1, i0;
			i1 = j / 16;
			i0 = j - i1 * 16;
			result += '%';
			result += dec2hexChar(i1);
			result += dec2hexChar(i0);
		}
	}
	return result;
}

string deescapeURL(const string &URL) {
	string result = "";
	for (unsigned int i = 0; i<URL.size(); i++) {
		char c = URL[i];
		if (c != '%') {
			result += c;
		}
		else {
			char c1 = URL[++i];
			char c0 = URL[++i];
			int num = 0;
			num += hexChar2dec(c1) * 16 + hexChar2dec(c0);
			result += char(num);
		}
	}
	return result;
}
