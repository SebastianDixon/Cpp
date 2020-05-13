#include "Handle.h"


Handle::Handle()
{
    body = new Body;
}

Handle::~Handle()
{
    delete body;
}

void Handle::bodyOperation()
{
    body->dataPiece = 54;
}
