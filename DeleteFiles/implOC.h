#pragma once

#include <iostream>
#include <string>



class CImplOC
{    
public:
    CImplOC();
    ~CImplOC();

	virtual void execute() = 0;

	void SetParam(const std::string & _dir, const std::string & _ext);
	

protected:
	const std::string& GetDir() const;
	const std::string& GetExt() const;

private:
	std::string sDir;
	std::string sExt;
};




