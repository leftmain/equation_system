#include <stdio.h>
#include <math.h>
#include <time.h>

#define MAX_ITER 200

void f(double a, double * x, double * y) {
	*y = 0.25 * (a - 1./(1 + pow(tanh(*x), 2)) \
			- 1./(1 + pow(tanh(*y), 2)));
	*x = -0.5 * (cos(*y) + atan(*x) / 2.);
}

double norma(double x, double y) {
	return sqrt(x * x + y * y);
}

int main(int argc, char ** argv) {
	double a = 0.;
	double x0 = 0.;
	double y0 = 0.;
	double E = 1e-19;
	double t = 0;

	printf("input a from (-2, 6), x0 from [-1, 1], y0 from [-2, 2], E\n");
	if (scanf("%lf%lf%lf%lf", &a, &x0, &y0, &E) != 4) { \
		perror("input error\n"); \
		return 0; \
	}

	double x = x0;
	double y = y0;
	double n = 0.;
	int i = 0;
	t = clock();
	for (; i < MAX_ITER; i++) {
		f(a, &x, &y);
		if ((n = norma(x - x0, y - y0)) <= E) break;
		x0 = x;
		y0 = y;
	}
	t = (clock() - t) / CLOCKS_PER_SEC;

	printf("Time: %.2lf\n", t);
	if (i == MAX_ITER) {
		printf("MAX_ITER\nnorma = %le\n", norma(x - x0, y - y0));
	} else {
//		printf("iterations %d\nnorma = %le\n"\
				"x = %.16lf\ny = %.16lf\n", i, n, x, y);
		printf("iterations %d\nnorma = %le\n"\
				"x = %le\ny = %le\n", i, n, x, y);
	}

	return 0;
}

