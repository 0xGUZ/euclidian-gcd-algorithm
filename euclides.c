/*
    ---------------------------------------------
    AUTHOR: Gustavo Villar Marinatto.
    Written in 21/06/2022 (dd/mm/yyyy).
    E-mail: marinatto.gustavo@gmail.com.
    Github: github.com/gustavo-villar-dev
    ---------------------------------------------
    UFRJ - Universidade Federal do Rio de Janeiro
    ---------------------------------------------
    Description:
    This code's purpose is to provide a well written build of the Euclidian Algorithm to the world.   
    --------------------------------------------- 
*/

#include <stdio.h>

/*global variable*/
int iterations;

int euclides(int a, int b){

    /*variables*/
    int dividend, divisor, remainder;

    /*<algorithm>*/

        dividend = a;
        divisor = b;
        remainder = a%b;
        iterations = 1;

        while(remainder > 0){
            dividend = divisor;
            divisor = remainder;
            remainder = dividend%divisor;
            iterations++;
        }

        return divisor;

    /*</algorithm>*/
    
}

int main(void){

    /*variables*/
    int a,b,gcd;
    char repeat = 'Y';
    int i = 0, j, k;

    /*repeats program until input*/
    while(repeat == 'y' || repeat == 'Y'){

        /*variables reset when program repeats*/
            i = 0;

        /*header text ---------------*/

            printf("\n\tGreatest Common Divisor Calculator\n");
            printf("----------------------------------------------------\n\n");
            printf("This calculator uses the Euclidian Algorithm to \nfind the GCD between int A and int B.\n\n");
            printf("----------------------------------------------------\n");


        /*end of header text ---------*/
    
        /*============================*/

        /*input stage ----------------*/
            
            /*integer a*/
            printf("Integer A = ");
            j = scanf(" %d",&a);
            fflush(stdin);

            /*validation*/
            if(j != 1){
                printf("\nThat's not a valid input.\n");
                return 1;
            }
        
            /*integer b*/
            printf("Integer B = ");
            k = scanf(" %d",&b);
            fflush(stdin);

            /*validation*/
            if(k != 1){
                printf("\nThat's not a valid input.\n");
                return 1;
            }
        
        /*end of input stage ---------*/

        /*============================*/

        /* calling stage ------------ */
            
            gcd = euclides(a,b);
        
        /*end of calling stage ------ */

        /*============================*/

        /*output stage ---------------*/

            printf("\nIntegers %d and %d greatest common divisor is: %d.",a,b,gcd);
            printf("\nIt took the algortihm %d steps to find the GCD.\n",iterations);

        /*end of output stage --------*/

        /*============================*/

        /*end question ---------------*/
        
            printf("----------------------------------------------------\n\n");
            printf("Do you wish to run the program again? (y/n)\n");

            /*while input is wrong ask for new input*/
            do{
                if(i > 0) printf("Please type a valid character. (y/n)\n");
                scanf(" %c",&repeat);
                fflush(stdin);
                i++;
            } while (repeat != 'n' && repeat != 'N' && repeat != 'y' && repeat != 'Y');

        /*program either ends or repeat*/
    } 
    return 0;
}
