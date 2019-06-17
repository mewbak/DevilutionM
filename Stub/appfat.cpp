#include <stdarg.h>

#include "../types.h"
#include "stubs.h"

#include <jni.h>
#include <android/log.h>

//char cwd[1024];
//if (getcwd(cwd, sizeof(cwd)) != NULL)
//    __android_log_print(ANDROID_LOG_INFO, "", cwd);



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

void __fastcall ErrDlg(int template_id, int error_code, char *log_file_path, int log_line_nr)
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
	UNIMPLEMENTED();
}

void __fastcall FileErrDlg(char *error)
{
	UNIMPLEMENTED();
}

void __fastcall DDErrMsg(int error_code, int log_line_nr, char *log_file_path)
{
	UNIMPLEMENTED();
}

void __fastcall DiskFreeDlg(char *error)
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
