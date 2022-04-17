#include <QPainter>

bool FlagMove;
bool FlagDelete;
bool FlagChange;
bool FlagRotate;
bool FlagBrush;

QPen pen;
QColor CurColor;
QColor CurBrushColor;
int CurPenWidth;

void setAllFlagsFalse();
void setDefaultPen();
