/*
    ---------------------------------------------
    AUTHOR: Gustavo Villar Marinatto.
    Written in 22/06/2022 (dd/mm/yyyy).
    E-mail: marinatto.gustavo@gmail.com.
    Github: github.com/gustavo-villar-dev
    ---------------------------------------------
    UFRJ - Universidade Federal do Rio de Janeiro
    ---------------------------------------------
    Description:
    This code's purpose is to provide a well written build of the Extended Euclidian Algorithm to the world.   
    --------------------------------------------- 
*/

#include <stdlib.h>
#include <stdio.h>

/*global variable*/
int iterations, x1, x2, _y1, _y2;

int extendedEuclides(int a, int b){

    /*variables*/
    int dividend, divisor, remainder,quotient, tempX, tempY;

    /*<algorithm>*/

        dividend = a;
        divisor = b;
        quotient = a/b;
        remainder = a%b;
        iterations = 1;

        x1 = 1; _y1 = 0;
        x2 = 0, _y2 = 1;
        
        tempX = x2;
        x1 = x1 - x2 * quotient;
        x2 = x1;
        x1 = tempX;

        tempY = _y2;
        _y1 = _y1 - _y2 * quotient;
        _y2 = _y1;
        _y1 = tempY;

        while(remainder > 0){
            dividend = divisor;
            divisor = remainder;
            quotient = dividend/divisor;
            remainder = dividend%divisor;

            tempX = x2;
            x1 = x1 - x2 * quotient;
            x2 = x1;
            x1 = tempX;            

            tempY = _y2;
            _y1 = _y1 - _y2 * quotient;
            _y2 = _y1;
            _y1 = tempY;
            
            iterations++;
        }

        return divisor;

    /*</algorithm>*/
    
}

int main(void){

    /*variables*/
    int a,b,gcd;
    char repeat = 'Y';
    int i = 0, j, k, l;

    /*repeats program until input*/
    while(repeat == 'y' || repeat == 'Y'){

        /*variables reset when program repeats*/
            i = 0;

        /*header text ---------------*/
            l = system("cls");
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
            
            gcd = extendedEuclides(a,b);
        
        /*end of calling stage ------ */

        /*============================*/

        /*output stage ---------------*/
        l = system("cls");
            printf("\nIntegers %d and %d greatest common divisor is: %d.",a,b,gcd);
            printf("\ngcd(%d,%d) = %d\n",a,b,gcd);
            printf("\nIt took the algortihm %d steps to find the GCD.\n",iterations);
            printf("\nHow to write gcd as A and B int combination:\n gcd(%d,%d) = %d*(%d) + %d*(%d)\n",a,b,a,x1,b,_y1);


        /*end of output stage --------*/

        /*============================*/

        /*end question ---------------*/
        
            printf("----------------------------------------------------\n\n");
            printf("Do you wish to run the program again? (y/n)\n");

            /*while input is wrong ask for new input*/
            do{
                if(i > 0) printf("Please type a valid character. (y/n)\n");
                l = scanf(" %c",&repeat);
                fflush(stdin);
                i++;
            } while (repeat != 'n' && repeat != 'N' && repeat != 'y' && repeat != 'Y');

        /*program either ends or repeat*/
    } 
    return 0;
}
