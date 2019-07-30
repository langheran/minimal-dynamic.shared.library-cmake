#define MODULE_API_EXPORTS
#include <string>
#include <sstream>
#include "module.h"
#ifdef _WIN32
#  include <windows.h>
#endif

MODULE_API char* module_init(const int param)
{
    std::ostringstream ss;

#ifdef _WIN32
    ss << "Module init called with param: " << param << ".";
    MessageBox(0, ss.str().c_str(), "module.dll", MB_OK);
#endif

    ss.str(""); ss.clear();
    ss << "Module_init result is: " << 2*param;

    std::string tmp = ss.str();
    char* result=(char*)malloc(sizeof(char)*(tmp.length() + 1));
	strcpy_s(result, tmp.length() + 1, tmp.c_str());
    return result;
}