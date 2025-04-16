#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Get credit card number
    long number = get_long("number: ");
    // I need this to keep the number unmodified and check for the type of credit card i.e. AMEX below
    long numberForLength = number;
    long numberForStartDigits = number;

    int position = 0;
    int sumA = 0;
    int sumB = 0;
    // Check if number is valid credit card number
    // Loop number in reverse
    while (number > 0)
    {
        int digit = number % 10;
        // Sum A. Second to last digit and every other digit
        if (position % 2 == 1)
        {
            int product = digit * 2;
            // if product has 2 digits split and add i.e. 12 1+2=3
            if (product > 9)
            {
                sumA += (product % 10) + (product / 10);
            }
            // else sum them up
            else
            {
                sumA += product;
            }
        }
        // Sum of the remainder digits to the result
        else
        {
            sumB += digit;
        }
        // Integer division. Removes last digit from the number so it can go to the next one
        number /= 10;
        // Go to next digit
        position++;
    }

    // Add the sum of both group of digits
    int total = sumA + sumB;

    // If total modulo 10 is congruent to 0 valid
    if (total % 10 != 0)
    {
        printf("INVALID\n");
    }
    else
    {
        // Get lenght of number
        int length = 0;
        while (numberForLength > 0)
        {
            numberForLength /= 10;
            length++;
        }

        // Get start numbers
        long startNumbers = numberForStartDigits;
        while (startNumbers >= 100)
        {
            startNumbers /= 10;
        }

        // Check if it is AMEX. 15 digits. Starts with 34 or 37
        // i.e. 378282246310005
        if (length == 15 && (startNumbers == 34 || startNumbers == 37))
        {
            printf("AMEX\n");
        }
        // Check if it is MASTERCARD. 16 digits. Starts with 51, 52, 53, 54, 55
        // i.e. 5555555555554444
        else if (length == 16 && (startNumbers >= 51 && startNumbers <= 55))
        {
            printf("MASTERCARD\n");
        }
        // Check if it is VISA. 13 or 16 digits. Starts with 4
        // i.e. 4012888888881881
        else if ((length == 13 || length == 16) && (startNumbers / 10 == 4))
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
    }
}