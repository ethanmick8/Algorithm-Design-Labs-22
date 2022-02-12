#include <stdio.h>

// creates my own data type called myDataType
typedef struct {
    char joemama[2020], test[80];
    int x, y, z;
    float avgsalary;
} myDataType;

void setSalary( myDataType * ptr, float avgsalary )
{
    ptr -> avgsalary; // same as (*ptr)avgsalary = avgsalary, just more straightforward
}

int main(void)
{

}