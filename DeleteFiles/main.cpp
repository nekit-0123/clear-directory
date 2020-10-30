#include "DelFiles.h"
#include <thread>
#include <memory>

int main(int argc, char* argv[])
{
	std::cout << "Input Directory: ";
	std::string sDir("");
	std::getline(std::cin, sDir);

	std::string sExt("");
	std::cout << "Input Extension: ";
	std::getline(std::cin, sExt);

	if (sDir.empty())
	{
		std::cerr<<"No path";
		return -1;
	}

	std::unique_ptr<CDelFiles> Calc(new  CDelFiles(std::move(sDir), std::move(sExt)));
	std::thread th = std::thread(&CDelFiles::execute, Calc.get());

	th.join();

	return 0;
}

