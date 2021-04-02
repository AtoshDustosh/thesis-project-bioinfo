#ifndef AUXILIARYMETHODS_H_INCLUDED
#define AUXILIARYMETHODS_H_INCLUDED

#pragma once

#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "debug.h"

void _testSet_auxiliaryMethods();

/**
 * @brief Insert a string into the specific position of another string.
 *
 * @param original string to insert into
 * @param inserted string to insert
 * @param insertPos 0-based position of insertion on the orignal string. For
 * example, if you need to insert "123" into "045" and make it "012345", pos
 * should be "1", which means this method will insert the inserted string
 * directly into the insertPos and push away the original char behind. And thus
 * if you want to insert "456" to the end of "0123", the pos should be "4",
 * which is larger than the length of the original string. But in this case,
 * strcat() from C library may be a better alternative.
 * Still, there are some situations where the input is invalid. For example,
 * (orignal, inserted, insertPos) = ("0123", "5", 5). This method does not allow
 * @return char* inserted string. Note that the successfully returned string
 * must be freed later manually.
 */
char *insertStr(const char *original, const char *inserted,
                const int insertPos);

#endif