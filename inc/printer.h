#ifndef PRINTER_H
#define PRINTER_H

#include <stdint.h>
#include <stdarg.h>

/* printf support */
void putc(char c);
void puts(const char *s);
void puthex(uint64_t n);
void putdec(uint64_t n);

void vprintf(const char* fmt, va_list ap);
void sprintf(char* out, const char* fmt, ...);
void printf(const char* fmt, ...);
void trace(const char* fmt, ...);
/* debug() declared in debug.h */

#endif /* PRINTER_H */