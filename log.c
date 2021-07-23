#include "log.h"

#include <stdarg.h>
#include <stdio.h>

void car_log(int level, const char *fmt, ...)
{
        va_list args;
        va_start(args, fmt);
        FILE *fd = stdout;
        const char *msg;
        switch (level) {
        default:
                fprintf(fd, "!! LOG CALLED WITH INVALID LEVEL !!\n");
                return;
        case LOG_ERROR:
                msg = "   ERROR";
                break;
        case LOG_CRITICAL:
                msg = "CRITICAL";
                break;
        case LOG_WARNING:
                msg = " WARNING";
                break;
        case LOG_INFO:
                msg = "    INFO";
                break;
        case LOG_DEBUG:
                msg = "   DEBUG";
                break;
        case LOG_TRACE:
                msg = "   TRACE";
                break;
        }
        fprintf(stdout, "%s: ", msg);
        vfprintf(stdout, fmt, args);
        va_end(args);
}
