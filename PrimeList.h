/*
 * PrimeList.h
 *
 *  Created on: Apr 9, 2015
 *      Author: lurker
 */

#ifndef PRIMELIST_H_
#define PRIMELIST_H_

#include "utils.h"

namespace Eureka {

class PrimeList {

private:
	int64_t _limit;
	int64_t _cache;
	int64_t _count;
public:
	PrimeList(int64_t, int);
	~PrimeList();

	std::vector<std::pair<bool, int64_t>> Primes;

	int64_t isPrime(int64_t);
	int64_t getPrime(int64_t);
	int64_t Sieve();
	int64_t Pi(int64_t);
	// trial division
	std::vector<std::pair<int64_t, int64_t>> factorize(int64_t);
	int64_t divisor(int64_t);
	int64_t divisor_sum(int64_t);
};

} /* namespace Eukera */

#endif /* PRIMELIST_H_ */
