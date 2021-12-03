#include <stdio.h>
#include <string.h>
int main(void)
{
    float total_amount;
    int transaction;
    scanf("%d", &transaction);
    scanf("%f", &total_amount);
    if (transaction % 5 != 0)
    {
        printf("%0.2f", total_amount);
    }
    else
    {

        if (transaction > total_amount + 0.05)
        {
            printf("%0.2f", total_amount);
        }
        else
        {
            total_amount = (total_amount - transaction) - 0.50;
            printf("%0.2f", total_amount);
        }
    }
}