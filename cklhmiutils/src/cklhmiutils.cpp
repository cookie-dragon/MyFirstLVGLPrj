#include "cklhmiutils.h"

CklHmiUtils::CklHmiUtils()
{
}

CklHmiUtils::~CklHmiUtils()
{
}

void *createCklHmiUtils()
{
    return new CklHmiUtils();
}

void destroyCklHmiUtils(void *obj)
{
    delete static_cast<CklHmiUtils *>(obj);
}
