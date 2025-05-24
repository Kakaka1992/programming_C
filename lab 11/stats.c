#include "stats.h"
#include <stdarg.h>
#include <float.h>


double sum(int count, ...) {
    va_list args;
    va_start(args, count);
    double total = 0.0;
    int i;
    
    for (i = 0; i < count; i++) {
        total += va_arg(args, double);
    }
    
    va_end(args);
    return total;
}


double max(int count, ...) {
    va_list args;
    va_start(args, count);
    double max_val = -DBL_MAX; 
    int i;
    
    for (i = 0; i < count; i++) {
        double num = va_arg(args, double);
        if (num > max_val) max_val = num;
    }
    
    va_end(args);
    return max_val;
}


double min(int count, ...) {
    va_list args;
    va_start(args, count);
    double min_val = DBL_MAX; 
    int i;
    
    for (i = 0; i < count; i++) {
        double num = va_arg(args, double);
        if (num < min_val) min_val = num;
    }
    
    va_end(args);
    return min_val;
}


double average(int count, ...) {
    va_list args;
    va_start(args, count);
    double total = 0.0;
    int i;
    
    for (i = 0; i < count; i++) {
        total += va_arg(args, double);
    }
    
    va_end(args);
    return (count == 0) ? 0 : total / count;
}
