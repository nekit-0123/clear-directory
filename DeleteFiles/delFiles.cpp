#include "DelFiles.h"

#pragma once

CDelFiles::CDelFiles()
	: implOC(nullptr)
{
}

CDelFiles::~CDelFiles()
{
	if (implOC)
	{
		delete implOC;
		implOC = nullptr;
	}

}


CDelFiles::CDelFiles(std::string &&dir, std::string &&ext)
{
	std::swap(this->sDir, dir);
    std::swap(this->sExt, ext);
}

void CDelFiles::execute()
{
	#ifdef _WIN32 
		implOC = new (std::nothrow) Win32;
	#endif

	#ifdef linux
		implOC = new (std::nothrow) unix;
	#endif

	#ifdef __APPLE__
		implOC = new (std::nothrow) unix;
	#endif

	if (implOC)
	{
		implOC->SetParam(sDir, sExt);
		implOC->execute();
	}
}


