#include "globeflags.h"

void setAllFlagsFalse()
{
    FlagDelete = false;
    FlagMove = false;
    FlagRotate = false;
    FlagChange = false;
    FlagBrush = false;
    FlagCopy = false;
}

void setDefaultPen()
{
    pen = QPen(Qt::black, 2);
    CurColor = Qt::black;
    CurPenWidth = 2;
}
