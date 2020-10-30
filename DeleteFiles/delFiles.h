#include "Win32\Win32.h"
#include "unix\unix.h"

class CDelFiles
{
public:
	CDelFiles();
	~CDelFiles();

	explicit CDelFiles(std::string &&dir, std::string &&ext);
	void execute();

protected:
	CImplOC* implOC; 

private:
	std::string sDir;
	std::string sExt;
};



