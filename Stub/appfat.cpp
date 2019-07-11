#include <stdarg.h>

#include "../types.h"
#include "stubs.h"

//#include <jni.h>
//#include <android/log.h>

//char cwd[1024];
//if (getcwd(cwd, sizeof(cwd)) != NULL)
//    __android_log_print(ANDROID_LOG_INFO, "", cwd);



void __cdecl app_fatal(const char *pszFmt, ...)
{
	va_list va;

	va_start(va, pszFmt);
	FreeDlg();
#ifdef _DEBUG
	TriggerBreak();
#endif

	if (pszFmt)
		MsgBox(pszFmt, va);

	va_end(va);

	init_cleanup(FALSE);
	exit(1);
}




char empty_string = 0;

void TermMsg(char *pszFmt, ...)
{

	char buf[256];
	va_list args;
	va_start(args, pszFmt);


	vsnprintf(buf, sizeof(buf), pszFmt, args);
	eprintf("%s: %s\n", __FUNCTION__, buf);
	abort();
}

void ErrDlg(int template_id, DWORD error_code, char *log_file_path, int log_line_nr)
{
	UNIMPLEMENTED();
}

void __fastcall ErrOkDlg(int template_id, int error_code, char *log_file_path, int log_line_nr)
{
	UNIMPLEMENTED();
}

void __fastcall DirErrorDlg(char *error)
{
	UNIMPLEMENTED();
}

bool __cdecl InsertCDDlg()
{
	DUMMY();
}

void FileErrDlg(const char *error)
{
	UNIMPLEMENTED();
}

void __fastcall DDErrMsg(int error_code, int log_line_nr, char *log_file_path)
{
	UNIMPLEMENTED();
}

void FreeDlg()
{
	UNIMPLEMENTED();
}

void DrawDlg(char *pszFmt, ...)
{
	UNIMPLEMENTED();
}

char *__cdecl TraceLastError()
{
	DUMMY();

	return NULL;
}