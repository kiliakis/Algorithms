#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

bool isPalindrome(long int num){
	
	long int rev = 0;
	long int i = num;
	while(num > 0){
		rev = 10*rev + num%10;
		num /= 10;
	}
	return rev == i;
	
	/*
	string rev = to_string(num);
	reverse(rev.begin(), rev.end());
	return to_string(num) == rev;
	*/
}


long int lpd(int digits){
	long int max = 0;
	const long int low = pow(10, digits-1);
	for(long int num1 = pow(10, digits)-1; num1>low; num1--){
		if(num1 * num1 <= max) return max;
		for(long int num2 = num1; num2>low; num2--){
			long int prod = num1*num2;
			if(isPalindrome(prod) && prod> max)
				max = prod;
		}
	}
	return max;
}

int main(int argc, char *argv[]){
	cout << lpd(2) << "\n";
	cout << lpd(3) << "\n";

	return 0;
}
