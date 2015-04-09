/*
 * libeureka.h
 *
 *  Created on: Apr 3, 2015
 *      Author: lurker
 */

#ifndef LIBEUREKA_H_
#define LIBEUREKA_H_

#include <gmpxx.h>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <stdint.h>

typedef mpz_class Int;
typedef mpq_class Rational;
typedef mpf_class Float;
typedef gmp_randclass Rand;

class PrimeList {

private:
	int64_t _limit;
	int64_t _cache;
	int64_t _count;
public:
	PrimeList(int64_t, int);
	~PrimeList();

	std::vector<std::pair<bool, int>> Primes;

	int64_t isPrime(int64_t);
	int64_t getPrime(int);
	int64_t Sieve();
	int64_t Pi(int64_t);
};

class Combinatoric{
public:
	// general purpose
	void nchoosek(Int& r, Int& a, Int& b);
	void nchoosek(Int& r, Int& a, Int& b, int64_t p);
	// prebuilt function
	void triangle(Int& r, Int& a);
};

/*
 * m : general modulo.
 * p : prime modulo.
 * r : residual
 */
class Functions{
public:
	Functions(int64_t limit, int cache);
	~Functions();
	void assign(Int& r, Int& a);
	void assign(Int& r, uint64_t a);
	// power functions
	void pow(Int& r, Int& a, Int& b, Int& m);
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
	std::vector<int64_t> fibonacci_seq(int64_t);
	int64_t fibonacci_nth(int64_t);
};


class Palindrome {
public:
	bool isPalindrome(int64_t);
	bool isPalindrome(std::string);
};

#endif /* LIBEUREKA_H_ */
