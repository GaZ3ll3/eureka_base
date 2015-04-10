/*
 * Combinatorics.h
 *
 *  Created on: Apr 9, 2015
 *      Author: lurker
 */

#ifndef COMBINATORICS_H_
#define COMBINATORICS_H_

#include "utils.h"

namespace Eureka {

class Combinatoric{
public:
	// general purpose
	void nchoosek(Int& r, int64_t a, int64_t b);
	void nchoosek(Int& r, Int& a, Int& b, int64_t p);
	void nchoosek(Int& r, int64_t a, int64_t b, int64_t p);
	// prebuilt function
	void triangle(Int& r, Int& a);
	void triangle(Int& r, int64_t a);
};
} /* namespace Eukera */

#endif /* COMBINATORICS_H_ */
