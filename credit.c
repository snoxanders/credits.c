#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int every_other_digit();
int mutiplyAndSum();
int every_first_digit();
int sum_both_cheks();
int check_length();
int first_two_digits();
int checkSum();
int validation();
int check_brand();
void alex_credit_algorithm();

int main(void) {
    unsigned long long credit_card;
            printf("Card number: ");
            scanf("%llu", &credit_card);


        alex_credit_algorithm(credit_card);



    return 0;
}

int every_other_digit(unsigned long long credit_card)
{
    int sum;
    sum = 0;
    bool isAlternateDigit = false;

    while(credit_card > 0)
    {
        if(isAlternateDigit == true)
        {
            int last_digit = credit_card % 10;
            int product = mutiplyAndSum(last_digit);
            sum = sum + product;
            credit_card = credit_card / 10;
            isAlternateDigit = !isAlternateDigit;

        }else
        {
            credit_card = credit_card / 10;
            isAlternateDigit = !isAlternateDigit;
        }
    }
    return sum;
}

int every_first_digit(unsigned long long credit_card)
{
    bool isAlternateDigit = true;
    int sum;
    sum = 0;
    while(credit_card > 0)
    {
        if(isAlternateDigit == true)
        {
            int last_digit = credit_card % 10;
            sum = sum + last_digit;
            credit_card = credit_card / 10;
            isAlternateDigit = !isAlternateDigit;
        }
        else
        {
            credit_card = credit_card / 10;
            isAlternateDigit = !isAlternateDigit;
        }
    }
    return sum;
}


int mutiplyAndSum(int last_digit)
{
    int multiply = last_digit * 2;
    int sum = 0;

    while(multiply > 0)
    {
        int last_digit_multiply = multiply % 10;
        sum = sum + last_digit_multiply;
        multiply = multiply / 10;
    }
    return sum;
}

int sum_both_cheks(int sum_every_other_digit, int sum_every_first_digit)
{
    int sum;
    sum = sum_every_other_digit + sum_every_first_digit;

    return sum;
}

int checkSum(unsigned long long credit_card)
{
    int sum_every_other_digit = every_other_digit(credit_card);
        int sum_every_first_digit = every_first_digit(credit_card);
        int checkSum = sum_both_cheks(sum_every_other_digit, sum_every_first_digit);
        return checkSum;
}

int check_length(unsigned long long credit_card)
{
    int length = 0;
    while(credit_card > 0)
    {
        credit_card = credit_card /10;
        length++;
    }
    return length;
}

int first_two_digits(unsigned long long credit_card)
{
    int length = check_length(credit_card);
    unsigned long long two_digits;
    two_digits = credit_card;
    int two_digits_length = length - 2;

    while(two_digits_length > 0)
    {
        two_digits = two_digits / 10;
        two_digits_length--;
    }
    return two_digits;
}

int validation(unsigned long long credit_card)
{
    bool validation = false;
    int checkSumValue = checkSum(credit_card);
    if(checkSumValue % 10 == 0)
    {
        validation = !validation;
        return validation;
    }
    else
    {
        validation = false;
        printf("This credit card is not valid!\n");
        return validation;
    }
}

int check_brand(unsigned long long credit_card)
{
    bool isValid = validation(credit_card);
    if(isValid == true)
    {
        int length = check_length(credit_card);
        int two_digits = first_two_digits(credit_card);

        if(two_digits == 34 && length == 15)
        {
            return 1;
        }
        else if(two_digits == 37 && length == 15)
        {
            return 1;
        }
        else if(two_digits == 51 && length == 16)
        {
            return 2;
        }
        else if(two_digits == 52 && length == 16)
        {
            return 2;
        }
        else if(two_digits == 53 && length == 16)
        {
            return 2;
        }
        else if(two_digits == 54 && length == 16)
        {
            return 2;
        }
        else if(two_digits == 55 && length == 16)
        {
            return 2;
        }
        else if (two_digits / 10 == 4 && length == 13)
        {
            return 3;
        }
        else if (two_digits / 10 == 4 && length == 16)
        {
            return 3;
        }
        else
        {
            return 4;
        }
    }
    else
    {
            return 4;
    }
}

void alex_credit_algorithm(unsigned long long credit_card)
{
        int checkSumValue = checkSum(credit_card);

        if(checkSumValue % 10 == 0)
        {
            int brand = check_brand(credit_card); // can be 1 american express - 2 mastercard , 3 visa , 4 invalid

        if(brand == 1)
        {
            printf("AMEX\n");
        }
        else if(brand == 2)
        {
            printf("MASTERCARD\n");
        }
        else if(brand == 3)
        {
            printf("VISA\n");
        }
        else
        {
            printf("INVALID\n");
        }
        }
        else
        {
            printf("INVALID\n");
        }

}
