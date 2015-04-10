/*
 * Palindrome.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: lurker
 */

#include "Palindrome.h"

namespace Eureka {

bool Palindrome::isPalindrome(std::string s){

	auto len = s.size();
	size_t n = 0;
	while (n != (len - 1)/2){
		if (s[n] != s[len - 1 - n]){return false;}
		n++;
	}
	return true;
}

bool Palindrome::isPalindrome(int64_t n){
	std::string s = std::to_string(n);
	return isPalindrome(s);
}

bool Palindrome::isPalindrome(Int& a){
	return isPalindrome(a.get_str());
}


} /* namespace Eukera */
