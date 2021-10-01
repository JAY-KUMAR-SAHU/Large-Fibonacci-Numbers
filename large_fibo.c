//  FIRST 20,000 FIBONACCI NUMBERS /////////////////////////////////////////////

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define z 1.6180339887498948

int main()
{
    int n, k = 1, x = 1, X = 1;
    // x : length of first number
    // X : length of second number
    // k : number of digits in answer starting from 1
    printf("Fibonacci Numbers starting from ZERO :: 0 1 1 2 3 5 8 ...    i.e. Fibo(0) = 0,  Fibo(1) = 1\n         Enter n (0 <= n <= 50,000)  :: ");
    scanf("%d", &n);

    if(n<=70){
        printf("%.0lf", round(pow(z, n)/pow(5, 0.5)) ); exit(0);
    }

    else{
        int d = (int)(ceil(n * log10(1.6180339887498948)  -  log10(5) / 2));
        // Number of digits in n-th Fibonacci number
        // Using BINET'S FORMULA
        // n*Log10(1.6180339887498948) - (Log10 5)/2
        // 4180 is the number of digits in 20,000th Fibonacci number

        char f[d+1], s[d+1], ans[d+1];
        f[0] = 1; s[0] = 1;
        int c = 0, i = 0;  // c=carry, i=index  

        n-=2;   // first 2 are already there
        while(n--)
        {
            // Addition till length x
            for (i = 0; i < x; i++)
            {
                ans[i] = ((f[i] + s[i] + c) % 10);
                c = (f[i] + s[i] + c) / 10;
            }

            int j = X - x; // Remaining length

            // Addition till remaining length j = X-x
            while (j--)
            {
                ans[i] = ((s[i] + c) % 10);
                c = (s[i] + c) / 10;
                i++;
            }

            x = X;  // changing length of first array to that of second

            if (c != 0) // Every time , the carry is 1, a digit is increaseed in the    answer
            {
                k++;
                ans[i] = c;
                c = 0;
            }
            X = k;  // changing length of second array to that of answer_array

            for (int y = 0; y < x; y++) { f[y] = s[y];   } // f[x]=s[x]
            for (int y = 0; y < X; y++) { s[y] = ans[y]; } // s[X]=ans[X]
        }

        for (int i = k - 1; i >= 0; i--){
           printf("%d", ans[i]);
        }
    }

   return 0;
}
