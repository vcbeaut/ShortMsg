#include "stdafx.h"
#import "C:\\Windows\\System32\\winhttp.dll"
using namespace WinHttp;

CString postRequest(CString url,CString method,CString body){
	IWinHttpRequestPtr pHttpReq;
	HRESULT hr = pHttpReq.CreateInstance(_uuidof(WinHttpRequest));
	if (FAILED(hr)){
		return;
	}
	_bstr_t h_method = method;
	_bstr_t h_url = url;
	hr = pHttpReq->Open(h_method, h_url);
	if (FAILED(hr)){
		return;
	}
	_variant_t h_body = body;
	hr = pHttpReq->Send(h_body);
	if (FAILED(hr)){
		return;
	}
	BSTR bstr = pHttpReq->ResponseText;
	CString b_Str = bstr;
	return b_Str;
}