/*
 * Matrix.h
 *
 *  Created on: Apr 14, 2015
 *      Author: lurker
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "utils.h"
#include <valarray>

namespace Eureka {

class Matrix {
private:
	int64_t row;
	int64_t col;
	bool sparse;
	std::vector<Rational> data;
public:
	Matrix(int64_t, int64_t);
	virtual ~Matrix();
	void ldivide(Matrix&);
	Rational get(int64_t, int64_t);
	void set(int64_t, int64_t, Rational q);
	void show();
};

} /* namespace Eureka */

#endif /* MATRIX_H_ */
