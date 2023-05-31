#include<stdio.h>  // for: input & output
#include<stdlib.h> // for: exit(0) function
#include<conio.h>  // for: getch() function
#include<math.h>   // for: pow(2,0) function

void welcomeScreen(void);    // Introduction Page & choice screen
void exitScreen(void);       // program end screen with credits
void screenCleaner(void);    // clears the output screen and input buffers
void userInput(int);         // takes the user input and validates for further opertaions
int digitChecker(int, int);  // validates each digit of input number
void conversion_Title(void); // title for all conversion outputs
void tryAgain(int);          // try Again window
void DoAgain(int);           // try again window for scientific calculator

// Binary Conversion functions
void binary_decimal(long int);
void binary_octal(long int);


// Decimal Conversion functions
void decimal_binary(long int);
void decimal_octal(long int);


// Octal Conversion functions
void octal_binary(long int);
void octal_decimal(long int);


// SCINTIFIC CALCULATOR
int scientificcalci();
double add(double a, double b);
double subtract(double a, double b);
double multiply(double a, double b);
double divide(double a, double b);
double power(double base, double exponent);
double squareRoot(double num);
double sine(double angle);
double cosine(double angle);
double tangent(double angle);
double logarithm(double num);
double factorial(double num);
int matrix();


// MATRIX FUNCTIONS
void printMatrix(int **matrix, int rows, int cols);
void addMatrices(int **matrix1, int **matrix2, int **result, int rows, int cols);
void subtractMatrices(int **matrix1, int **matrix2, int **result, int rows, int cols);
void multiplyMatrices(int **matrix1, int **matrix2, int **result, int rows1, int cols1, int cols2);


// C-Program main function
void main()
{
    system("cls");
    welcomeScreen();
}

// Intro screen
void welcomeScreen()
{
    int choice;

label1:
    screenCleaner();
    printf("----------------------------------\n");
    printf(">>> Welcome to SHAP Calculator<<< \n");
    printf("----------------------------------\n\n");

    printf(">> Select Conversion Type: \n");
    printf("> 1. Binary Conversion \n");
    printf("> 2. Decimal Conversion \n");
    printf("> 3. Octal Conversion \n");
    printf("> 4. scientific calculation \n");
    printf("> 5. Exit the Program \n\n");
    printf("Enter the number & Hit ENTER: ");
    scanf("%d", &choice);

    // passes the user input for conversion
    switch(choice)
    {
        case 1:
            userInput(1);
            break;
        case 2:
            userInput(2);
            break;
        case 3:
            userInput(3);
            break;
        case 4:
            userInput(4);
            break;
        case 5:
            exitScreen();
            break;
        default:
            printf("\nError: the number must be between 1 to 5.\n");
            printf("Press any key to continue... \n");
            getch();
            goto label1;
    }
}

// program exit screen (credit page)
void exitScreen()
{
    screenCleaner();
    printf("-------------------------------------\n");
    printf(" >>> Creators:\n \"GORTHY HARI KRISHNA SAI\"\n \"BAKAM SHARATH KUMAR\"\n \"P. PRUDHVI\" \n \"AJAY VARDHAN NAIK\" <<< \n THANK YOU \n");
    printf("-------------------------------------\n\n");


    exit(0);  // exit() function to close the program safely
}
void DoAgain(int choose)
{
    char ch;

    printf("\n\nDo you want to try again [y/N]: ");
    scanf(" %c", &ch);

    switch (ch)
    {
        case 'N':
        case 'n':
            exitScreen();
            break;
        case 'Y':
        case 'y':
            welcomeScreen();
            break;
        default:
            printf("\nError: invalid input. \n");
            printf("Press any key to continue... \n");
            getch();
            welcomeScreen();
    }
}
void screenCleaner()
{
    system("cls");  // clears the output screen
    fflush(stdin);  // clears the input buffer
}

void userInput(int choice)
{
    screenCleaner();

    if(choice == 1) // Binary input validation code
    {
        long int bi;
        int flag = 0;

        printf("Enter the binary: ");
        scanf("%ld", &bi);

        flag = digitChecker(bi, choice);

        if(flag == 1)
        {
            printf("\nError: Binary can only have the digits 0, 1. \n");
            printf("Press any key to continue... \n");
            getch();
            welcomeScreen();
        }
        else
        {
            conversion_Title();
            binary_decimal(bi);
            binary_octal(bi);
            tryAgain(choice);
        }
    }
    else if(choice == 2)  // Decimal input validation code
    {
        long int deci;
        int flag = 0;

        printf("Enter the decimal: ");
        scanf("%ld", &deci);

        if(deci > 0)
            flag = digitChecker(deci, choice);
        else
            flag = 1;

        if(flag == 1)
        {
            printf("\nError: Decimal number can't be negative. \n");
            printf("Press any key to continue... \n");
            getch();
            welcomeScreen();
        }
        else
        {
            conversion_Title();
            decimal_binary(deci);
            decimal_octal(deci);
            tryAgain(choice);
        }
    }
    else if(choice == 3)  // Octal input validation code
    {
        long int octal;
        int flag = 0;

        printf("Enter the octal: ");
        scanf("%ld", &octal);

        flag = digitChecker(octal, choice);

        if(flag == 1)
        {
            printf("\nError: Octal digits can only be between 0 to 7. \n");
            printf("Press any key to continue... \n");
            getch();
            welcomeScreen();
        }
        else
        {
            conversion_Title();
            octal_binary(octal);
            octal_decimal(octal);
            tryAgain(choice);
        }
    }

    else if(choice == 4)// initiates scientific calculator code
    {
        scientificcalci();
    }
    else  // Very rare case message
        printf("\n>> Unexpected Error occured. Report to program Administrator << \n");
}

// validation function for each single digit of a number according to conversion condition
int digitChecker(int num, int choice)
{
    long int rem, temp=0, flag=0;
    temp = num;

        while(temp != 0)
        {
            rem = temp % 10;

            if((rem == 0 || rem == 1) && choice == 1) // binary, choice = 1
                temp = temp / 10;
            else if(rem >= 0 && rem <= 9 && choice == 2) // decimal, choice = 2
                temp = temp / 10;
            else if(rem >= 0 && rem <=7 && choice == 3) // octal, choice = 3
                temp = temp / 10;
            else
            {
                flag = 1;
                break;
            }
        }
    return flag;
}

// title for all conversion outputs
void conversion_Title()
{
    printf("\n---------------------------\n");
    printf(">>> Conversion Results <<< \n");
    printf("---------------------------\n");
}

// try Again window
void tryAgain(int choice)
{
    char ch;

    printf("\n\nDo you want to try again [y/N]: ");
    scanf(" %c", &ch);

    switch (ch)
    {
        case 'Y':
        case 'y':
            userInput(choice);
            break;
        case 'N':
        case 'n':
            welcomeScreen();
            break;
        default:
            printf("\nError: invalid input. \n");
            printf("Press any key to continue... \n");
            getch();
            welcomeScreen();
    }
}

// Binary Conversion functions
void binary_decimal(long int bi)
{
    int rem,sum=0,i=0;

    while(bi!=0)
    {
        rem=bi%10;
        bi=bi/10;
        sum=sum+rem*pow(2,i);
        i++;
    }

    printf("\nDecimal Number: %d",sum);
}

void binary_octal(long int bi)
{
    int i=0,rem,sum=0,remain[100],len=0;

    while(bi!=0)
    {
        rem=bi%10;
        bi=bi/10;
        sum=sum+rem*pow(2,i);
        i++;
    }
    i=0;
    while(sum!=0)
    {
        remain[i]=sum%8;
        sum=sum/8;
        i++;
        len++;
    }

    printf("\nOctal Number: ");
    for(i=len-1;i>=0;i--)
    {
        printf("%d",remain[i]);
    }
}

// Decimal Conversion functions
void decimal_binary(long int deci)
{
    int rem[50],i,len=0;

    do
    {
        rem[i]=deci%2;
        deci=deci/2;
        i++;
        len++;
    }
    while(deci !=0);

    printf("\nBinary Number: ");
    for(i=len-1;i>=0;i--)
    {
        printf("%d",rem[i]);
    }
}

void decimal_octal(long int deci)
{
    int rem[50],i = 0,len=0;

    while (deci > 0) {
        rem[i] = deci% 8;
        deci= deci / 8;
        i++;
    }

    printf("The octal representation is: ");
    for (int j = i - 1; j >= 0; j--) {
        printf("%d", rem[j]);
    }
}

// Octal Conversion functions
void octal_binary(long int oct)
{
    int rem[50],len=0,decimal=0,i=0,num,ans;

    while(oct!=0)
    {
        ans=oct % 10;
        decimal = decimal + ans * pow(8,i);
        i++;
        oct = oct/10;
    }

    i=0;
    do
    {
        rem[i]=decimal%2;
        decimal=decimal/2;
        i++;
        len++;
    }
    while(decimal!=0);

    printf("\nBinary Number: ");
    for(i=len-1;i>=0;i--)
    {
        printf("%d",rem[i]);
    }
}

void octal_decimal(long int oct)
{
    int decimal=0,i=0,num,ans;

    while(oct!=0)
    {
        ans=oct % 10;
        decimal = decimal + ans * pow(8,i);
        i++;
        oct = oct/10;
    }
    printf("\nDecimal Number: %d",decimal);
}

double add(double a, double b) {
    return a + b;
}

double subtract(double a, double b) {
    return a - b;
}

double multiply(double a, double b) {
    return a * b;
}

double divide(double a, double b) {
    if (b != 0) {
        return a / b;
    } else {
        printf("Error: Division by zero\n");
        return 0.0;
    }
}

double power(double base, double exponent) {
    return pow(base, exponent);
}

double squareRoot(double num) {
    if (num >= 0) {
        return sqrt(num);
    } else {
        printf("Error: Invalid input\n");
        return 0.0;
    }
}

double sine(double angle) {
    return sin(angle);
}

double cosine(double angle) {
    return cos(angle);
}

double tangent(double angle) {
    return tan(angle);
}

double logarithm(double num) {
    if (num > 0) {
        return log10(num);
    } else {
        printf("Error: Invalid input\n");
        return 0.0;
    }
}

double factorial(double num) {
    if (num >= 0) {
        double result = 1;
        int i;

        for (i = 1; i <= num; i++) {
            result *= i;
        }

        return result;
    } else {
        printf("Error: Invalid input\n");
        return 0.0;
    }
}
int scientificcalci() {
    int choose;
    double num1, num2, result;

    printf("Scientific Calculator\n");
    printf("---------------------\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Power\n");
    printf("6. Square Root\n");
    printf("7. Sine\n");
    printf("8. Cosine\n");
    printf("9. Tangent\n");
    printf("10. Logarithm\n");
    printf("11. Factorial\n");
    printf("12. Matrix\n");
    printf("Enter your choice (1-12): ");
    scanf("%d", &choose);

    switch (choose) {
        case 1:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = add(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 2:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = subtract(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 3:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = multiply(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 4:
            printf("Enter two numbers: ");
            scanf("%lf %lf", &num1, &num2);
            result = divide(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 5:
            printf("Enter the base number: ");
            scanf("%lf", &num1);
            printf("Enter the exponent: ");
            scanf("%lf", &num2);
            result = power(num1, num2);
            printf("Result: %.2lf\n", result);
            break;
        case 6:
            printf("Enter a number: ");
            scanf("%lf", &num1);
            result = squareRoot(num1);
            printf("Result: %.2lf\n", result);
            break;
        case 7:
            printf("Enter the angle in radians: ");
            scanf("%lf", &num1);
            result = sine(num1);
            printf("Result: %.2lf\n", result);
            break;
        case 8:
            printf("Enter the angle in radians: ");
            scanf("%lf", &num1);
            result = cosine(num1);
            printf("Result: %.2lf\n", result);
            break;
        case 9:
            printf("Enter the angle in radians: ");
            scanf("%lf", &num1);
            result = tangent(num1);
            printf("Result: %.2lf\n", result);
            break;
        case 10:
            printf("Enter a positive number: ");
            scanf("%lf", &num1);
            result = logarithm(num1);
            printf("Result: %.2lf\n", result);
            break;
        case 11:
            printf("Enter a non-negative number: ");
            scanf("%lf", &num1);
            result = factorial(num1);
            printf("Result: %.2lf\n", result);
            break;
        case 12:
            matrix();
            break;
        default:
            printf("Invalid choice\n");
    }
    DoAgain(choose);

    return 0;
}
// Function to print a matrix
void printMatrix(int **matrix, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

// Function to add two matrices
void addMatrices(int **matrix1, int **matrix2, int **result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
}

// Function to subtract two matrices
void subtractMatrices(int **matrix1, int **matrix2, int **result, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrix1[i][j] - matrix2[i][j];
        }
    }
}

// Function to multiply two matrices
void multiplyMatrices(int **matrix1, int **matrix2, int **result, int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            result[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }
}
int matrix() {
    int rows1, cols1, rows2, cols2;

    printf("Enter the number of rows for Matrix 1: ");
    scanf("%d", &rows1);

    printf("Enter the number of columns for Matrix 1: ");
    scanf("%d", &cols1);

    printf("Enter the number of rows for Matrix 2: ");
    scanf("%d", &rows2);

    printf("Enter the number of columns for Matrix 2: ");
    scanf("%d", &cols2);

    if (cols1 != rows2) {
        printf("Matrix multiplication not possible.\n");
        return 0;
    }

    // Dynamic memory allocation for matrix 1
    int **matrix1 = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        matrix1[i] = (int *)malloc(cols1 * sizeof(int));
    }

    // Dynamic memory allocation for matrix 2
    int **matrix2 = (int **)malloc(rows2 * sizeof(int *));
    for (int i = 0; i < rows2; i++) {
        matrix2[i] = (int *)malloc(cols2 * sizeof(int));
    }

    // Dynamic memory allocation for result matrix
    int **result = (int **)malloc(rows1 * sizeof(int *));
    for (int i = 0; i < rows1; i++) {
        result[i] = (int *)malloc(cols2 * sizeof(int));
    }

    printf("Enter elements for Matrix 1:\n");
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols1; j++) {
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements for Matrix 2:\n");
    for (int i = 0; i < rows2; i++) {
        for (int j = 0; j < cols2; j++) {
            scanf("%d", &matrix2[i][j]);
        }
    }

    printf("Matrix 1:\n");
    printMatrix(matrix1, rows1, cols1);

    printf("Matrix 2:\n");
    printMatrix(matrix2, rows2, cols2);



    int chooseit;
    printf("matrix calculations :\n");
    printf("---------------------\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. exit\n");

    printf("enter your choice:");
    scanf("%d", &chooseit);

    switch(chooseit){
    case 1 :
        printf("Matrix Addition:\n");
    addMatrices(matrix1, matrix2, result, rows1, cols1);
    printMatrix(result, rows1, cols1);

    break;

    case 2:
      printf("Matrix Subtraction:\n");
    subtractMatrices(matrix1, matrix2, result, rows1, cols1);
    printMatrix(result, rows1, cols1);

      for (int i = 0; i < rows1; i++) {
        free(result[i]);
    }
    free(result);
    break;

    case 3:
       printf("Matrix Multiplication:\n");
    multiplyMatrices(matrix1, matrix2, result, rows1, cols1, cols2);
    printMatrix(result, rows1, cols2);

      for (int i = 0; i < rows1; i++) {
        free(result[i]);
    }
    free(result);
    break;

    case 4:
        exitScreen();
        break;

    default:
         printf("Invalid choice\n");

    }

    return 0;
}
