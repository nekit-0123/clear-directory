#include "..\implOC.h"

class Win32 : public CImplOC 
{
public:
    Win32();
    ~Win32();

private:
  void execute() override;
  void findDir(const std::string& _dir);
  bool checkExtension(std::string& _data) const;
};

