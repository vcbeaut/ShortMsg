#include "HttpRequest.h"

CString login(CString name, CString password){
	CString body,b_Ret;
	body.Format(_T("action=loginIn&name=%s&password=%s"), name, password);
	b_Ret = postRequest(_T("http://api.xingjk.cn/api/do.php"), _T("POST"), body);
	if (b_Ret.Find('1')){
		return b_Ret;
	}
	else{
		return b_Ret;
	}
}

CString getPhone(CString sid, CString token, CString location = NULL){
	CString body, b_Ret;
	if (location.IsEmpty()){
		body.Format(_T("action=getPhone&sid=%s&token=%s"), sid, token);
		
	}
	else{
		//Only province
		body.Format(_T("action=getPhone&sid=%s&token=%slocationMatching=include&locationLevel=p&location=%s"), sid, token,location);
	}
	b_Ret = postRequest(_T("http://api.xingjk.cn/api/do.php"), _T("POST"), body);
	if (b_Ret.Find('1')){
		return b_Ret;
	}
	else{
		return b_Ret;
	}
}

CString putSendMessage(CString phone, CString sid, CString message,CString recvPhone,CString token){
	CString body, b_Ret;
	body.Format(_T("action=putSentMessage&phone=%s&sid=%s&message=%s&recvPhone=%s&token=%s"), phone, sid,message,recvPhone,token);
	b_Ret = postRequest(_T("http://api.xingjk.cn/api/do.php"), _T("POST"), body);
	if (b_Ret.Find('1')){
		return b_Ret;
	}
	else{
		return b_Ret;
	}
}