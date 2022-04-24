#ifndef TRAPEZE_GLOBAL_H
#define TRAPEZE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(TRAPEZE_LIBRARY)
#  define TRAPEZE_EXPORT Q_DECL_EXPORT
#else
#  define TRAPEZE_EXPORT Q_DECL_IMPORT
#endif

#endif // TRAPEZE_GLOBAL_H
