/*
 * Combinatorics.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: lurker
 */

#include "Combinatorics.h"

namespace Eureka {
void Combinatoric::nchoosek(Int& r, int64_t a, int64_t b){
	mpz_bin_uiui(r.get_mpz_t(), a, b);
}

void Combinatoric::nchoosek(Int& r, Int& a, Int& b, int64_t p){
	Int tmp, t ,s;
	assign(r, 1);
	while (b != 0 || a != 0) {
		t = a % p;
		s = b % p;
		a /= p;
		b /= p;
		nchoosek(tmp , t.get_ui() , s.get_ui());
		r *= tmp;
		r %= p;
		if (r == 0) {
			return;
		}
	}
}

void Combinatoric::nchoosek(Int& r, int64_t a, int64_t b, int64_t p){
	Int tmp;
	int64_t s, t;
	assign(r, 1);
	while (b != 0 || a != 0) {
		t = a % p;
		s = b % p;
		a /= p;
		b /= p;
		nchoosek(tmp , t , s);
		r *= tmp;
		r %= p;
		if (r == 0) {
			return;
		}
	}
}

void Combinatoric::triangle(Int& r, Int& a){
	Int tmp;
	tmp = a * (a - 1)/2;
	assign(r, tmp);
}


void Combinatoric::triangle(Int& r, int64_t a){
	Int tmp; assign(tmp, a);
	tmp *= (tmp - 1);
	tmp /= 2;
	assign(r, tmp);
}
} /* namespace Eukera */
