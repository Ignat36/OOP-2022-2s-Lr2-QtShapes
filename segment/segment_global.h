#ifndef SEGMENT_GLOBAL_H
#define SEGMENT_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(SEGMENT_LIBRARY)
#  define SEGMENT_EXPORT Q_DECL_EXPORT
#else
#  define SEGMENT_EXPORT Q_DECL_IMPORT
#endif

#endif // SEGMENT_GLOBAL_H
