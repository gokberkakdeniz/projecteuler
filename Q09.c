#include <stdio.h>

int main() {
	/* a=2mn
	 * b=m^2-n^2
	 * c=m^2+n^2
	 *
	 * m>n>1 and m^2+mn=500, a*b*c=?
	 */
	
	int m, n;
	for (m=3;m<22;m++) {
		for (n=m-1; m > n && n > 1; n--)
			if (500 == m*m+m*n)
				printf("m=%d, n=%d, a=%d, b=%d, c=%d\ta*b*c=%d\n", m, n, 2*m*n, m*m-n*n, m*m+n*n, 2*m*n*(m*m-n*n)*(m*m+n*n));
	}
	return 0;
}
