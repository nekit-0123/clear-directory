#include "implOC.h"

#pragma once

CImplOC::CImplOC()
	:sDir(""),
	sExt("")
{
}

CImplOC::~CImplOC()
{
}

void CImplOC::SetParam(const std::string & _dir, const std::string & _ext)
{
	this->sDir = _dir;
	this->sExt = _ext;
}

const std::string& CImplOC::GetDir() const
{
	return sDir;
}

const std::string& CImplOC::GetExt() const
{
	return sExt;
}

