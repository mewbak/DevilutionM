//HEADER_GOES_HERE
#ifndef __APPFAT_H__
#define __APPFAT_H__

void TermMsg(char *pszFmt, ...);

extern char empty_string;
extern char sz_error_buf[256];
extern int terminating;       // weak
extern int cleanup_thread_id; // weak


void __fastcall DirErrorDlg(char *error);
void TriggerBreak();
#ifdef _DEBUG
LONG __stdcall BreakFilter(PEXCEPTION_POINTERS pExc);
#endif
char *GetErrorStr(DWORD error_code);
void TraceErrorDD(HRESULT hError, char *pszBuffer, DWORD dwMaxChars);
void TraceErrorDS(HRESULT hError, char *pszBuffer, DWORD dwMaxChars);
char *TraceLastError();
void __cdecl app_fatal(const char *pszFmt, ...);
void MsgBox(const char *pszFmt, va_list va);
void FreeDlg();
void __cdecl DrawDlg(char *pszFmt, ...);
#ifdef _DEBUG
void assert_fail(int nLineNo, const char *pszFile, const char *pszFail);
#endif
void __fastcall DDErrMsg(int error_code, int log_line_nr, char *log_file_path);
void DSErrMsg(DWORD error_code, int log_line_nr, char *log_file_path);
void center_window(HWND hDlg);
void ErrDlg(int template_id, DWORD error_code, char *log_file_path, int log_line_nr);
BOOL __stdcall FuncDlg(HWND hDlg, UINT uMsg, WPARAM wParam, char *text);
void TextDlg(HWND hDlg, char *text);
void __fastcall ErrOkDlg(int template_id, int error_code, char *log_file_path, int log_line_nr);
void FileErrDlg(const char *error);
void DiskFreeDlg(char *error);
bool InsertCDDlg();
//void DirErrorDlg(char *error);

#endif /* __APPFAT_H__ */
