#include "..\implOC.h"

class unix : public CImplOC
{
private:
	void execute() override;
    void findDir();
public:
    unix();
    ~unix();
};


