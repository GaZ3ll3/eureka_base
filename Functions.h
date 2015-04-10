/*
 * Functions.h
 *
 *  Created on: Apr 9, 2015
 *      Author: lurker
 */

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "utils.h"

namespace Eureka {

class Functions{
public:
	// power functions
	void pow(Int& r, Int& a, Int& b, Int& m);
	void pow(Int& r, Int& a, Int& b, uint64_t m);
	void pow(Int& r, Int& a, uint64_t b);
	void pow(Int& r, uint64_t a, uint64_t b);
	// factorial functions
	void fac(Int& r, uint64_t a);
	// gcd and lcm
	void gcd(Int& r, Int& a, Int& b);
	void lcm(Int& r, Int& a, Int& b);
	// digits related
	int64_t digit_sum(Int& r);
	int64_t digit_sum(int64_t);
	int64_t digit_sum(std::string);
	// Fibonacci related
	std::vector<Int> fibonacci_seq(int64_t);
	void fibonacci_nth(Int &r, int64_t);
	// Modulo used on containers
	// todo:
};

} /* namespace Eukera */

#endif /* FUNCTIONS_H_ */
