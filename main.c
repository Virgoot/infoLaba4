#include <stdio.h>
#include <math.h>

int Fun(int n){
    if (n < 2) {
        return 1;
    }
    else if (n >= 2 && n % 3 == 0){
        return Fun(n / 3) + 1;
    }
    else{
        return Fun(n - 2) + 5;
    }        
    
}

long long DoubleFactorial(int n) {
    long long r = 1;
    for (int i = 1; i <= n; i += 2)
        r *= i;
    return r;
}

double DirectSum(int N, double x) {
    double sum = 0.0;

    for (int n = 1; n <= N; n++) {
        long long df = DoubleFactorial(2*n - 1);
        double t = 2.0*n * pow(x, 2*n - 1) / df;
        sum += t;
    }

    return sum;
}

double RecurSum(int N, double x) {

    double a = 2 * x;
    double sum = a;
    
    for (int n = 1; n < N; n++){
        a = a * ((n + 1) * x * x) / (n * (2*n + 1));
        sum += a;
    }
    
    return sum;

}

int main() {
    int count = 0;

    for (int i = 1; i < 100000; i++) {
        if (Fun(i) == 55) { 
            count++;    
        }
    }


    int x = 0;
    printf("Enter a number: ");
    scanf("%d", &x);

    int userResult = Fun(x);
    int r = userResult;
    int userCount = 0;

    while (userResult > 0) {
        if ((userResult % 10 ) % 2 == 1) {
            userCount++;
        }
        userResult /= 10;
    }
    
    printf("Task 1 Results: ");
    printf("%d\n", count);
    
    printf("Task 2 Results: ");
    printf("%d\n", r);
    printf("Odd numbers count: ");
    printf("%d\n", userCount);
    


    // ----------Task 2-------------------
    
    int N;
    double X;

    printf("Enter N and X: ");
    scanf("%d %lf", &N, &X);

    double s1 = RecurSum(N, X);
    double s2 = DirectSum(N, X);

    printf("Recurrent: %lf\n", s1);
    printf("Direct: %lf\n", s2);
    printf("Difference: %lf\n", fabs(s1-s2));

    return 0;
}
