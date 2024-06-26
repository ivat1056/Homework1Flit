#include <stdio.h>
#include <stdlib.h> // для конвертации строки в числовой вид
#include <locale.h> // язык
#include <ctype.h> // для типа является ли символ - числом

int CountNum, NumOfArray, sizeArray=0; // количество элементов, элемент, размер массива
char count_number[100]; // количество значений
char checkArrayDec[1]; // для проверки


int Check_number(char check[]) // для конвертации строки (массива) в числовой вид
{
    int num;
    fgets(check, sizeof(check), stdin);
    char *check1 = check;
    int count = 0;
    while (*check1++ != 0) {
        check1++;
        count++;
    }
    for (int i = 0; i < count; i++)
    {
        if (isdigit(check[i]) == 0)
        {
            return 0;
        }
    }
    num = atoi(check);
    return num;
}

void InputCountNumbers()
{
    while(1)
    {
        printf("Введите количество вводимых чисел: ");
        CountNum = Check_number(count_number);
        
        if ((CountNum <= 0) )
        {
            printf("Введенная строка равна нулю или не является числом или меньше нуля\n");
        }
        else
        {
            break;
        }
    }
    sizeArray = atoi(count_number);
}

void InputNumbersOfArray(long array[], int size)
{
    int flag;
    int counter=1;
    for (long i = 0; i < sizeArray; i++)
    {
        while(1)
        {
            printf("Введите элемент [%d] ",counter);
            NumOfArray = Check_number(checkArrayDec);
            if (NumOfArray <= 0) {
                printf("Введенная строка равна нулю или не является числом или меньше нуля\n");
            }
            else
            {
                if (i!= 0)
                {
                    for (int j = 0; j < i; j++)
                    {
                        if (array[j] != NumOfArray)
                        {
                            flag =0;
                        }
                        else
                        {
                            printf("Введенный элемент уже есть во множестве \n");
                            flag = 1;
                            break;
                        }
                    }
                }
                else
                {
                    break;
                }
                if(flag != 1 )
                {
                    break;
                }
            }
        }
        array[i] = NumOfArray;
        counter++;
    }
}

long* decimalToBinary(long decimals[], long size)
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
long main(void)
{
    setlocale(LC_ALL, "Rus");
    InputCountNumbers();
    long arrayDec[sizeArray];
    InputNumbersOfArray(arrayDec, sizeArray);
    printf("Исходное множество чисел ");
    PrintArray(arrayDec,sizeArray);
    printf("\n");
    long* binaries = decimalToBinary(arrayDec, sizeArray);
    PrintArray(binaries,sizeArray);
    return 0;
}
