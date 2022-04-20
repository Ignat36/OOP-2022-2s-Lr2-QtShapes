#include <QPainter>
#include "figure.h"

bool FlagMove;
bool FlagDelete;
bool FlagChange;
bool FlagRotate;
bool FlagBrush;
bool FlagCopy;

QPen pen;
QColor CurColor;
QColor CurBrushColor;
int CurPenWidth;
Figure *tmpFigure;

void setAllFlagsFalse();
void setDefaultPen();
