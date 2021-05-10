/**
    main.cpp

    @author Matheus Peschke
    @version 1.0.0 2021-05-09
*/
#include "stdafx.h"

#ifndef WIN32
#define _tmain main
#else
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#endif

using namespace BLL;

int _tmain(int argc, ::TCHAR* argv[])
{
    return 0;
}
