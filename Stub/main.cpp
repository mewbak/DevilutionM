#include <string>

#include "../types.h"
#include "stubs.h"


#define printf(...) __android_log_print(ANDROID_LOG_DEBUG, "DEBUGMSG", __VA_ARGS__);


static std::string build_cmdline(int argc, char **argv)
{
	std::string str;
	for (int i = 1; i < argc; i++) {
		if (i != 1) {
			str += ' ';
		}
		str += argv[i];
	}
	return str;
}

int main(int argc, char **argv)
{



	auto cmdline = build_cmdline(argc, argv);
	return WinMain(NULL, NULL, cmdline.c_str(), 0);
}
