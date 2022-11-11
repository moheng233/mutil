#ifndef __LIB_MUTIL_MATH
#define __LIB_MUTIL_MATH

#include "mutil_conf_inter.h"

/// 将一个值钳制在最大值和最小值之间
#define MATH_CLAMP(_VALUE, _MIN, _MAX)    \
    {                                     \
        if (_VALUE > _MAX) _VALUE = _MAX; \
        if (_VALUE < _MIN) _VALUE = _MIN; \
    }

#define MATH_SIGN(_VALUE) ((_VALUE) == 0 ? 0: (_VALUE) >= 0 ? 1 : -1)

#define MATH_MOVE_TOWARD(_FROM, _TO, _DELTA) (abs(_TO - _FROM) <= _DELTA ? _TO : _FROM + MATH_SIGN(_TO - _FROM) * _DELTA)

/// 将一个数组的内容复制到另外一个数组中
#define MATH_COPY_ARRAY(_SOU, _TAR, _LEN)                        \
    {                                                            \
        for (size_t i = 0; i < _LEN; i++) { _TAR[i] = _SOU[i]; } \
    }

/// 对于数组进行希尔排序
/// 会修改原来的数组
#define MATH_SORT_SHELL(_ARR, _LEN)                                                             \
    {                                                                                           \
        int gap, i, j;                                                                          \
        int temp;                                                                               \
        for (gap = _LEN >> 1; gap > 0; gap = gap >> 1) {                                        \
            for (i = gap; i < _LEN; i++) {                                                      \
                temp = _ARR[i];                                                                 \
                for (j = i - gap; j >= 0 && nadcs[j] > temp; j -= gap) _ARR[j + gap] = _ARR[j]; \
                _ARR[j + gap] = temp;                                                           \
            }                                                                                   \
        }                                                                                       \
    }

#endif // !__SRC_UTIL_MATH
