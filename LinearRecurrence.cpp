/*
 * LinearRecurrence.cpp
 *
 *  Created on: Apr 10, 2015
 *      Author: lurker
 */

#include "LinearRecurrence.h"


namespace Eureka {

std::vector<Int> LinearRecurrence::FindLinearRecurrence(std::vector<Int>& seq){
	std::vector<Int> kernel;

	int64_t list_len = seq.size();
	bool success = false;

	for (int64_t length = 1; length <= list_len/2; length ++){
		Eigen::MatrixXd m(length, length);
		for (int64_t row = 0; row < length; row++){
			for (int64_t col = 0; col < length; col++){
				m(row, col) = seq[row + col].get_d();
			}
		}

		Eigen::VectorXd t(length);
		for (int64_t row = 0; row <  length; row++){
			t(row) = seq[length + row].get_d();
		}

		Eigen::VectorXd x = m.partialPivLu().solve(t);

		for (int64_t row = 2 * length; row < list_len; row ++){

			Int tmp(0);

			for(int64_t i = 0; i < length; i++) {
				double k = x(i);
				tmp += lround(k) * seq[row - length + i];
			}



			if (tmp != seq[row]) {success = false;break;}
			else {success = true;}
		}

		if (success) {
			kernel.resize(length);
			for (int64_t i = 0; i < length; i++){
				double k = x(i);
				kernel[i] = lround(k);
			}
			return std::move(kernel);
		}
	}
	return std::move(kernel);
}
} /* namespace Eukera */
