/*
 * LinearRecurrence.cpp
 *
 *  Created on: Apr 10, 2015
 *      Author: lurker
 */

#include "LinearRecurrence.h"
#include "Matrix.h"

namespace Eureka {

std::vector<Rational> LinearRecurrence::FindLinearRecurrence(std::vector<Int>& seq){
	std::vector<Rational> kernel;

	int64_t list_len = seq.size();
	bool success = false;

	for (int64_t length = 1; length <= list_len/2; length ++){
		Matrix m(length, length);
		for (int64_t row = 0; row < length; row++){
			for (int64_t col = 0; col < length; col++){
				m.set(row, col, Rational(seq[row + col]));
			}
		}

		Matrix t(length, 1);
		for (int64_t row = 0; row <  length; row++){
			t.set(row, 0, Rational(seq[length + row]));
		}

		m.ldivide(t);


		for (int64_t row = 2 * length; row < list_len; row ++){
			Rational tmp(Rational(0));
			for(int64_t i = 0; i < length; i++) {
				Rational k = t.get(i, 0);
				tmp += k * Rational(seq[row - length + i]);
			}
			if (tmp != Rational(seq[row])) {success = false;break;}
			else {success = true;}
		}

		if (success) {
			kernel.resize(length);
			for (int64_t i = 0; i < length; i++){
				auto k = t.get(i, 0);
				kernel[i] = k;
			}
			return std::move(kernel);
		}
	}
	return std::move(kernel);
}
} /* namespace Eukera */
