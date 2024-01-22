#include <iostream>

int main()
{
    int num;

    std::cout << "Entre un nombre à chercher un sous-ensemble égal dans la liste [3, 34, 4, 12, 5, 2]" << std::endl;
    std::cin >> num;
    
}

int SmallestGapSorted(int* tab, int size)
{
    int gap1 = tab[1] - tab[0];
    for(int i = 0; i < size; i++)
    {
        int gap2 = tab[i+1] - tab[i];
        
        if(gap2 < gap1)
        {
            gap1 = gap2;
        }
    }
    return gap1;
}

int SmallestGapUnsorted(int* tab, int size)
{  
    int gap = tab[1] - tab[0];
    
    if (gap < 0) gap = -gap;

    for (int i = 1; i < size-1; ++i) 
    {
        for (int j = i+1; j < size; ++j)
        {
            int gap2 = tab[i] - tab[j];
        
            if (gap2 < 0)
            {
                gap2 = -gap2;
            }
            if (gap2 < gap)
            {
                gap = gap2;
            }
        }
    }
    return gap;
}

bool GivenNumInSubset(int num, int* tab, int size)
{
    for (int i = 0; i < size-1; ++i) 
    {
        for (int j = i+1; j < size; ++j) 
        {
            if (tab[i]+tab[j] == num)
            {
                std::cout << "Un sous-ensemble a été trouvé pour " << num << " " << '[' << tab[i] << tab[j] << ']' << std::endl;
                return true;
            }
        }
    }
    std::cout << "Aucun sous-ensemble a été trouvé pour " << num << std::endl;
    return false;
}