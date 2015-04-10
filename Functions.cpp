/*
 * Functions.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: lurker
 */

#include "Functions.h"

namespace Eureka {

void Functions::pow(Int& r, Int& a, Int& b, Int& m){
	mpz_powm(r.get_mpz_t(), a.get_mpz_t(), b.get_mpz_t(), m.get_mpz_t());
}
/*
 * TODO: implement negative power
 */
//wrap for uint64_t modulo
void Functions::pow(Int& r, Int& a, Int& b, uint64_t m){
	Int tmp(m);
	pow(r, a, b, tmp);
}

void Functions::pow(Int& r, Int& a, uint64_t b){
	mpz_pow_ui(r.get_mpz_t(), a.get_mpz_t(), b);
}

void Functions::pow(Int& r, uint64_t a, uint64_t b){
	mpz_ui_pow_ui(r.get_mpz_t(), a, b);
}

void Functions::fac(Int& r, uint64_t a){
	mpz_fac_ui(r.get_mpz_t(), a);
}

void Functions::gcd(Int& r, Int& a, Int& b){
	mpz_gcd(r.get_mpz_t(), a.get_mpz_t(), b.get_mpz_t());
}

void Functions::lcm(Int& r, Int& a, Int& b){
	mpz_lcm(r.get_mpz_t(), a.get_mpz_t(), b.get_mpz_t());
}

int64_t Functions::digit_sum(std::string s){
	int64_t sum = 0;
	for (auto it:s){
		sum += it - '0';
	}
	return sum;
}

int64_t Functions::digit_sum(int64_t n){
	std::string s = std::to_string(n);
	return digit_sum(s);
}

int64_t Functions::digit_sum(Int& r){
	return digit_sum(r.get_str());
}
// F(1) = 1, F(2) = 1;
std::vector<Int> Functions::fibonacci_seq(int64_t n){
	std::vector<Int> res(n);
	if (n < 1) {
		std::cout << "Invalid input." << std::endl;
	}
	else if (n < 2){
		assign(res[0], 1);
	}
	if (n >= 2){
		assign(res[0], 1);
		assign(res[1], 1);
		for (int64_t i = 2; i < n; i++){
			res[i] = res[i - 1] + res[i - 2];
		}
	}
	return std::move(res);
}


void Functions::fibonacci_nth(Int &r, int64_t n){
	mpz_fib_ui (r.get_mpz_t(), n);
}

} /* namespace Eukera */
