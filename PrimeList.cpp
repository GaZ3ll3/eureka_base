/*
 * PrimeList.cpp
 *
 *  Created on: Apr 9, 2015
 *      Author: lurker
 */

#include "PrimeList.h"

namespace Eureka {

PrimeList::PrimeList(int64_t limit, int cache){

	_limit = limit;
	_cache = cache;

	Primes.resize(_limit + 1, std::make_pair(false, 0));

	_count = Sieve();
}

PrimeList::~PrimeList(){
	Primes.clear();

}

int64_t PrimeList::Sieve(){
	int sqrt = (int) std::sqrt((double) _limit);

	int64_t count = (_limit < 2) ? 0 : 1;
	int64_t s = 2;
	int64_t n = 3;

	if (_limit > 1) {
		Primes[2] = std::make_pair(true, 1);
	}

	// vector used for sieving
	std::vector<char> sieve(_cache);
	// generate small primes <= sqrt
	std::vector<char> is_prime(sqrt + 1, 1);
	for (int i = 2; i * i <= sqrt; i++){
		if (is_prime[i]){
			for (int j = i * i; j <= sqrt; j += i){
				is_prime[j] = 0;
			}
		}
	}

	std::vector<int> primes;
	std::vector<int> next;

	for (int64_t low = 0; low <= _limit; low += _cache){
		std::fill(sieve.begin(), sieve.end(), 1);

		// current segment = interval [low, high]
		int64_t high = std::min(low + _cache - 1, _limit);

		// store small primes needed to cross off multiples
		for (; s * s <= high; s++){
			if (is_prime[s]){
				primes.push_back((int) s);
				next.push_back((int)(s * s - low));
			}
		}
		// sieve the current segment
		for (std::size_t i = 1; i < primes.size(); i++){
			int j = next[i];
			for (int k = primes[i] * 2; j < _cache; j += k){
				sieve[j] = 0;
			}
			next[i] = j - _cache;
		}

		for (; n <= high; n += 2){
			if (sieve[n - low]){
				count++;
				Primes[n] = std::make_pair(true, count);
			}
			else {
				Primes[n] = std::make_pair(false, count);
			}
		}
	}

    return count;
}

int64_t PrimeList::isPrime(int64_t number){
	if (number > _limit) {
		return -1;
	}
	return Primes[number].first;
}

int64_t PrimeList::getPrime(int64_t index){

	if (index == 1) {
		return 2;
	}

	else {
		int64_t low = 1, high = (_limit - 1)/2, mid = 0, cnt = 0;
		if (Primes[2 * low + 1].second == index) return 2 * low + 1;
		if (low == high) return -1;
		if (index > Primes[2 * high + 1].second){
			return -1;
		}


		while (low <= high){
			cnt ++;
//			std::cout << 2 * low + 1 << ", " << 2 * high + 1 << std::endl;

			mid  = (low + high) / 2;

			if (Primes[2 * low + 1].second < index &&  Primes[2 * mid + 1].second >= index){
				high = mid;
			}

			else if (low == mid){
				if (Primes[2 * high + 1].second == index) {
					return 2 * high + 1;
				}
				else {
					return -1;
				}
			}
			else{
				low = mid;
			}

 		}
		return -1;
	}
}

// include itself.
int64_t PrimeList::Pi(int64_t limit){
	if (limit > _limit) {return -1;}
	if (!(limit & 1)) {return Primes[limit - 1].second;}
	return Primes[limit].second;
}

std::vector<std::pair<int64_t, int64_t>> PrimeList::factorize(int64_t n){
	std::vector<std::pair<int64_t, int64_t>> factors;

	auto tmp = n; auto limit = (int64_t)sqrt(tmp);
	int64_t count = 0;

	if (limit <= _limit){
		for (int64_t pl_it = 0; pl_it < limit; pl_it ++){
			if (1 == isPrime(pl_it) && tmp % pl_it == 0){
				count = 0;
				while (tmp % pl_it == 0){
					tmp /= pl_it;
					count += 1;
				}
				factors.push_back(std::make_pair(pl_it, count));
			}
		}
		if (tmp > 1){
			factors.push_back(std::make_pair(tmp, 1));
		}
	}
	else{
		std::cout << "Prime List not long enough." << std::endl;
	}
	return std::move(factors);
}

int64_t PrimeList::divisor(int64_t n){
	auto tmp = n; auto limit = (int64_t)sqrt(tmp);
	int64_t count = 0, base = 1;

	if (limit <= _limit){
		for (int64_t pl_it = 0; pl_it < limit; pl_it ++){
			if (1 == isPrime(pl_it) && tmp % pl_it == 0){
				count = 0;
				while (tmp % pl_it == 0){
					tmp /= pl_it;
					count += 1;
				}
				base *= (count + 1);
			}
		}
		if (tmp > 1){
			base *= 2;
		}
	}
	else{
		std::cout << "Prime List not long enough." << std::endl;
	}
	return base;
}
// not including itself.
int64_t PrimeList::divisor_sum(int64_t n){
	auto tmp = n; auto limit = (int64_t)sqrt(tmp);
	int64_t count = 0, base = 1;

	if (limit <= _limit){
		for (int64_t pl_it = 0; pl_it < limit; pl_it ++){
			if (1 == isPrime(pl_it) && tmp % pl_it == 0){
				count = 0;
				while (tmp % pl_it == 0){
					tmp /= pl_it;
					count += 1;
				}
				base *= (pow(pl_it, (count + 1))  - 1)/(pl_it - 1);
			}
		}
		if (tmp > 1){
			base *= (1 + tmp);
		}
	}
	else{
		std::cout << "Prime List not long enough." << std::endl;
	}
	return base - n;
}



} /* namespace Eukera */
