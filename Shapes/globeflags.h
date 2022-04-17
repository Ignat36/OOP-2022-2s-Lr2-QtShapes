#include <QPainter>

bool FlagMove;
bool FlagDelete;
bool FlagChange;
bool FlagRotate;

QPen pen;
QColor CurColor;
QColor CurBrushColor;
int CurPenWidth;

void setAllFlagsFalse();
void setDefaultPen();
