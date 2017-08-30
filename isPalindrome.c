#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef int bool;
bool false = 0;
bool true = 1;

bool isPalindrome(int x) {
#if 0
	int len = 1;
	int left,right;

	if (x < 0)
	    return false;

	if (!x)
	    return true;

	while((x/len) >= 10)
	    len *= 10;

	while(x) {
	    left = x/len;
	    right = x%10;

	    if (left != right)
		return false;

	    x = (x%len)/10;
	    len /= 100;
	}

	return true;
#else
	int y = 0;
	int xx = x;
	int n;

	if (x < 0)
	    return false;
	
	if (!x)
	    return true;

	while(x) {
	    n = x%10;

	    y = y*10 + n;

	    x /= 10;
	}

	return xx==y;
#endif
}

int main(int argc, char* argv[])
{
	printf("%d is %d\n",-1,isPalindrome(-1));
	printf("%d is %d\n",0,isPalindrome(0));
	printf("%d is %d\n",121,isPalindrome(121));
	printf("%d is %d\n",123121321,isPalindrome(123121321));
	printf("%d is %d\n",111,isPalindrome(111));
	printf("%d is %d\n",1231,isPalindrome(1231));
	printf("%d is %d\n",1421,isPalindrome(1421));
	printf("%d is %d\n",15251,isPalindrome(15251));
	printf("%d is %d\n",1652571,isPalindrome(1652571));
	return 0;	
}
