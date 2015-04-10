/*
 * utils.h
 *
 *  Created on: Apr 9, 2015
 *      Author: lurker
 */

#ifndef UTILS_H_
#define UTILS_H_

#include <gmpxx.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <stdint.h>
#include <string>

typedef mpz_class Int;
typedef mpq_class Rational;
typedef mpf_class Float;
typedef gmp_randclass Rand;

extern void assign(Int& r, Int& a);
extern void assign(Int& r, uint64_t a);

#endif /* UTILS_H_ */
