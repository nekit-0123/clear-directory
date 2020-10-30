#include "Win32.h"
#include "Windows.h"

Win32::Win32()
{
}

Win32::~Win32()
{
}

void Win32::execute()
{
	std::string _dir = GetDir();
	if (_dir.front() != '/' && _dir.front() != '\\')
		_dir.append("\\");

	findDir(_dir);
}

void Win32::findDir(const std::string& _dir)
{
	std::string reg = _dir;
	reg.append("*");
	
	WIN32_FIND_DATA wfd;
	HANDLE const hFind = FindFirstFile(reg.c_str(), &wfd);
	if (INVALID_HANDLE_VALUE != hFind)
	{
		do
		{
			if ((wfd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)  &&
				(lstrcmp(wfd.cFileName, ".") != 0 ) && 
				(lstrcmp(wfd.cFileName, "..") != 0 ))
			{
				findDir(_dir + wfd.cFileName + "\\"); // recursion))
			}
			else 
			{
				if (checkExtension(std::string(wfd.cFileName)))
				{
					std::string _d = _dir + wfd.cFileName;
					DeleteFile(_d.c_str());
				}
				if (GetLastError() == 32)
				{
					//The process cannot access the file because it is being used by another process
				}
			}
		} while (FindNextFile(hFind, &wfd) != NULL);
		FindClose(hFind);
	}
}

bool Win32::checkExtension(std::string& data) const
{
	long lh = GetExt().size()-1;
	long rh = data.size()-1;

	bool res(false);

	while (lh>0 && rh>0)
	{
		if (GetExt()[lh] != data[rh])
		{
			res = false;
			break;
		}
		else 
			res = true;

		--lh; --rh;
	}

	return res;
}