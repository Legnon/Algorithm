//
//  quickSort.h
//  HelloCpp
//
//  Created by Legnon on 2018. 3. 20..
//  Copyright © 2018년 Legnon. All rights reserved.
//

#ifndef quickSort_h
#define quickSort_h


#endif /* quickSort_h */

#define MAX_NUM 100

int input[MAX_NUM];
int num;

void quickSort(int first, int last)
{
    int pivot;
    int i;
    int j;
    int temp;
    
    if (first < last)
    {
        pivot = first;
        i = first;
        j = last;
        
        while (i < j)
        {
            while (input[i] <= input[pivot] && i < last)
            {
                i++;
            }
            cout << "i:" << i << endl;
            
            while (input[j] > input[pivot])
            {
                j--;
            }
            cout << "j:" << j << endl;
            if (i < j)
            {
                temp = input[i];
                input[i] = input[j];
                input[j] = temp;
            }
            
            cout << input[i] << input[j] << endl;
            
        }
        
        temp = input[pivot];
        input[pivot] = input[j];
        input[j] = temp;
        
        
        cout << input[pivot] << input[i] << input[j] << endl;
        
        quickSort(first, j - 1);
        quickSort(j + 1, last);
    }
}

void printResult(void)
{
    int i;
    
    for (i = 0; i < num; ++i)
    {
        printf("%d ", input[i]);
    }
    printf("\n");
}

void answer(int test_case)
{
    scanf("%d", &num);
    for (int i = 0; i < num; i++)
    {
        scanf("%d", &input[i]);
    }
    quickSort(0, num - 1);
    printf("#%d ", test_case);
    printResult();
}
