#ifndef CAR_LOG_H
#define CAR_LOG_H

#define LOG_ERROR 0
#define LOG_CRITICAL 1
#define LOG_WARNING 2
#define LOG_INFO 3
#define LOG_DEBUG 4
#define LOG_TRACE 5

void car_log(int level, const char *fmt, ...);

#endif // CAR_LOG_H
