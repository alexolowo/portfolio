#include <stdio.h>
#include <math.h>
#include <stdbool.h>

int factorial(int n1);
int choose(int n, int r);
void triangle(int rowNumInput);
void spaces(int rowNumInput, int rowNum);

int main(int argc, char **argv)
{
    int userRowInput;
    //Loop to keep prompting the user and stop when input is negative
    bool done;
    
    done = false;
    while(done==false)
    {
        printf("Enter the number of rows: ");
        scanf("%d",&userRowInput);
        (userRowInput<0)?done=true:triangle(userRowInput);
    }	
	return 0;
}

int factorial(int n1)//factorial function
{
    int i, prod=1;
    for(i=1;i<=n1;i++){
    prod = prod * i;
    }
    return prod;
}

int choose(int n, int r)
{
    return (factorial(n)/(factorial(r)*factorial(n-r)));//n!/((n-r)!r!)
}

void triangle(int rowNumInput)
{
    int rowNum;
    rowNum=1;//declaring the starting row number: 1
    for (rowNum=1; rowNum <=rowNumInput;rowNum++)
    {
        spaces(rowNumInput,rowNum);//calling spaces function
        
        for (int j=rowNum-1; j>=0; j--)//this prints the numbers and the spaces between them
        {
            printf("%-3d   ",choose((rowNum-1),j));
        }
        printf("\n");
    }
}

void spaces(int rowNumInput, int rowNum)//function that inserts the spaces before the first number on each line
{
    for (int i=1; i <= 3*(rowNumInput-rowNum); printf(" "), i++);
}