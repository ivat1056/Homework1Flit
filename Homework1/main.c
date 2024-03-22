#include <stdio.h>
#include <stdlib.h> // для конвертации строки в числовой вид
#include <locale.h> // язык

int CountNum, NumOfArray, sizeArray; // количество элементов, элемент, размер массива
char count_number[100]; // количество значений
char checkArrayDec [1]; // для проверки

int Check_number(char check [])  // для конвертации строки (массива) в числовой вид
{
    int num;
    fgets(check, sizeof(check), stdin);
    num = atoi(check);
    return num;
}
 
void InputCountNumbers()
{
    while(1)
    {
        printf("Введите количество вводимых чисел: ");
        CountNum = Check_number(count_number);
        if (CountNum <= 0) {
            printf("Введенная строка равна нулю или не является числом.\n");
        }
        else {
            break;
        }
    }
    sizeArray = atoi(count_number);
}

long* InputNumbersOfArray()
{
    int counter=1;
    int array [sizeArray];
    for (int i = 0; i < sizeArray; i++)
    {
        while(1)
        {
            printf("Введите элемент [%d] ",counter);
            NumOfArray = Check_number(checkArrayDec);
            if (NumOfArray == 0) {
                printf("Введенная строка не является числом.\n");
            }
            else {
                array[i]=NumOfArray;
                counter++;
                break;
            }
        }
    }
    return array;
}


long* decimalToBinary(int decimals[], int size)
{
    long array[100];
    for(long i=0; i<size; i++)
    {
        long long  dec, remainder, binary_number = 0, j = 1;
        dec = decimals[i];
        while(dec != 0) {
            remainder = dec % 2;
            dec = dec / 2;
            binary_number += remainder * j;
            j = j * 10;
        }
        array[i] = binary_number;
    }
    return array;
}

void PrintArray(long array[], long size)
{
    for (long i = 0; i < size; i++)
    {
        printf("%lld ", array[i]);
    }
}
int main(void)
{
    setlocale(LC_ALL, "Rus");
    InputCountNumbers();
    long* arrayDec = InputNumbersOfArray();
    
    printf("Исходное множество чисел ");
    PrintArray(arrayDec,sizeArray);
    printf("\n");
    long* binaries = decimalToBinary(arrayDec, sizeArray);
    PrintArray(binaries,sizeArray);
    
    return 0;
     
}
