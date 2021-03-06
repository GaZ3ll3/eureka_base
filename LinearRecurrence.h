/*
 * LinearRecurrence.h
 *
 *  Created on: Apr 10, 2015
 *      Author: lurker
 */

#ifndef LINEARRECURRENCE_H_
#define LINEARRECURRENCE_H_

#include "utils.h"

namespace Eureka {

class LinearRecurrence {
public:
	std::vector<Rational> FindLinearRecurrence(std::vector<Int>&);
	std::vector<Int> BuildLinearRecurrence(std::vector<Int>&, std::vector<Int>&);
};

} /* namespace Eukera */

#endif /* LINEARRECURRENCE_H_ */
