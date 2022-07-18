#ifndef __LIB_MUTIL_MATH
#define __LIB_MUTIL_MATH

#define CLAMP(_VALUE, _MIN, _MAX) { \
    if(_VALUE > _MAX) _VALUE = _MAX;\
    if(_VALUE < _MIN) _VALUE = _MIN;\
} 

#endif // !__SRC_UTIL_MATH
