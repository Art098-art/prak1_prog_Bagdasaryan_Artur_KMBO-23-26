#ifndef DECODER_H
#define DECODER_H

#include <stddef.h>

/* Вычитает key из каждого из count ответов, превращает числа в символы
 ASCII и печатает результирующую строку */

void print_decoded(const long long *results, size_t count, long long key);

#endif /* DECODER_H */
