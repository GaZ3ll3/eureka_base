/*
 * utils.cpp
 *
 *  Created on: Apr 10, 2015
 *      Author: lurker
 */
#include "utils.h"

extern void assign(Int& r, Int& a){
	mpz_set(r.get_mpz_t(), a.get_mpz_t());
}

extern void assign(Int& r, uint64_t a){
	mpz_set_ui(r.get_mpz_t(), a);
}





