#include <stdio.h>
#include <stdlib.h>



int reverse(int x) {
	unsigned int res = 0,tmp;
	unsigned int ten_max_value = (0x80000000/10);
	int below_zero = 0;

	if (x == 0)
		return x;

	if (x < 0) {
		below_zero = 1;
		x = 0 - x;
	}

	while(x) {
		tmp = x%10;

		if (res > ten_max_value)
			return 0;

		res = res*10;
		res += tmp;

		if (res > 0x80000000)
			return 0;

		x = x/10;
	}

	if (below_zero)
		return (0-res);
	return res;
}



int main(int argc, char* argv[])
{
	printf("%d\n",reverse(1534236469));
	printf("%d\n",reverse(-12345));
	printf("%d\n",reverse(1000000));
	return 0;
}
