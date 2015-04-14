/*
 * Matrix.cpp
 *
 *  Created on: Apr 14, 2015
 *      Author: lurker
 */

#include "Matrix.h"

namespace Eureka {

Matrix::Matrix(int64_t m, int64_t n) {
	// TODO Auto-generated constructor stub
	row = m;
	col = n;
	sparse = false;
	data.resize(m * n);
}

Matrix::~Matrix() {
	// TODO Auto-generated destructor stub
}


void Matrix::ldivide(Matrix& v){
	if (this->row != this->col || this->row != v.row) {
		std::cout << "Dimension does not match.\n" << std::endl;
		return;
	}
	else{
		// pivoting not necessary, all coefficient must stay integer. So all
		// operations are working on rational numbers.
		// cancelling must be exact.
		// The goal is form a diagonal matrix of BigInt.

		//Pivoting
		std::deque<std::pair<int64_t, int64_t>> pivot;

		for (int64_t i = 0; i < this->col; i++){
			/*
			 * 1. search maximum of the i-th column.
			 */
			int64_t i_max = i;
			Rational m = this->get(i, i);
			for (int64_t j = i + 1; j < this->row; j++){
				if (abs(this->get(j, i)) > abs(m)) {
					m = this->get(j, i);
					i_max = j;
				}
			}
			/*
			 * 2. if maximum on i-th column is 0, singular.
			 */
			if (this->get(i_max, i) == 0){
				std::cout << "Singular detected.\n" << std::endl;
				return;
			}

			/*
			 * 3. swap ith - row and i_max-th row if they are different
			 */
			if (i_max != i){
				for (int64_t j = i; j < this->col;  j++){
					auto swp = this->get(i, j);
					this->data[i * this->col + j] = this->get(i_max, j);
					this->data[i_max * this->col + j] = swp;
				}

				auto swp = v.data[i];
				v.data[i] = v.data[i_max];
				v.data[i_max] = swp;

				pivot.push_back(std::make_pair(i, i_max));
			}
			/*
			 * 4. Eliminate to upper triangle
			 */
			for (int64_t l = i + 1; l < this->row; l++){
				for (int64_t ll = i + 1; ll < this->col; ll++){
					this->data[l * this->col + ll] -= this->get(i, ll) * (this->get(l, i)/this->get(i,i));
				}
				v.data[l] = v.data[l] - v.data[i] * (this->get(l, i)/this->get(i,i));
				this->set(l, i, 0_mpq);
			}
		}

		/*
		 * 5. Backward to get solution stored in v.
		 */
		for (int64_t j = this->row - 1; j >=0; j--){
			auto s = v.data[j];
			for (int64_t k = this->row - 1; k > j; k--){
				s -= v.data[k] * this->get(j, k);
			}
			v.data[j] = s/this->get(j,j);
		}

		/*
		 * use pivot to restore values to correct position
		 */
//		while (!pivot.empty()){
//			auto it = pivot.back();
//			swap(v.data[it.first], v.data[it.second]);
//			pivot.pop_back();
//		}

	}
}


Rational Matrix::get(int64_t i, int64_t j){
	return data[i * this->col + j];
}

void Matrix::set(int64_t i, int64_t j, Rational q){
	data[i * this->col + j] = q;
}

void Matrix::show(){
	for (int64_t i = 0 ; i < this->row; i++){
		for (int64_t j = 0; j < this->col; j++){
			std::cout << this->get(i, j) << ", ";
		}
		std::cout << std::endl;
	}
}

} /* namespace Eureka */
