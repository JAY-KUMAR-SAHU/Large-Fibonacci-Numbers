//  FIRST 20,000 FIBONACCI NUMBERS /////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

int f[4181] = {0}, s[4181] = {0}, ans[4181] = {0};
// Number of digits in n-th Fibonacci number
// Using BINET'S FORMULA
// n*Log10(1.6180339887498948) - (Log10 5)/2
// 4180 is the number of digits in 20,000th Fibonacci number

int main()
{
    int n, k = 1, x = 1, X = 1;
    // x : length of first number
    // X : length of second number
    // k : number of digits in answer starting from 1
    printf("Fibonacci Numbers starting from 0 1 1 2 3 5 8 ...\n         Enter n (n <= 20,000)  :: ");
    scanf("%d", &n);

    f[0] = 0; s[0] = 1;
    int c = 0, i = 0;  // c=carry, i=index  

    if (n == 1)      {printf("0"); exit(1);}
    else if (n == 2) {printf("1"); exit(1);}
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

        if (c != 0) // Every time , the carry is 1, a digit is increaseed in the answer
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

   return 0;
}
