#include"Header.h"
int methood1(double* arr, int length, int rounds)
{
    double save;
    for (int i = 0; i < length; i++)
    {
        for (int j = i; j < length; j++)
        {
            rounds++;
            if ((arr[j] > arr[i]))
            {
                save = arr[j];
                arr[j] = arr[i];
                arr[i] = save;
                /*
                    system("cls");
                    for (int i = 0; i < sizeof(arr) / sizeof(double); i++)
                    {
                        cout << first[i] << ",";
                    }
                    cout << endl << endl;
                    for (int i = 0; i < sizeof(arr) / sizeof(double); i++)
                    {
                        cout << arr[i] << ",";
                    }
                    cout << endl << endl << rounds;
                    */
            }
        }
    }
    return rounds;
}
int methood1(FailBlock* arr, int length, int rounds)
{
    FailBlock save;
    for (int i = 0; i < length; i++)
    {
        for (int j = i; j < length; j++)
        {
            rounds++;
            if ((arr[j].estpos < arr[i].estpos))
            {
                save = arr[j];
                arr[j] = arr[i];
                arr[i] = save;
                /*
                    system("cls");
                    for (int i = 0; i < sizeof(arr) / sizeof(double); i++)
                    {
                        cout << first[i] << ",";
                    }
                    cout << endl << endl;
                    for (int i = 0; i < sizeof(arr) / sizeof(double); i++)
                    {
                        cout << arr[i] << ",";
                    }
                    cout << endl << endl << rounds;
                    */
            }
        }
    }
    return rounds;
}
int methood2(double* arr, int length, int rounds)
{
    bool keep = true,pw=true;
    double save, newarr[512],nl=sizeof(newarr)/sizeof(double), biggest = -9999, smallest = 99999, RangePerPlace;
    int place,k=0,g=0, Nlength = sizeof(newarr) / sizeof(double),fc=0;
    FailBlock *start= new FailBlock{0,0,nullptr}, * next = start, * temp = next;
    //makes created array into 0 so its more simple
    for (int i = 0; i < Nlength; i++)
    {
        newarr[i] = -1;
    }
    //find biggest
    for (int i = 0; i < length; i++)
    {
        if (arr[i] > biggest)
        {
            biggest = arr[i];
        }
    //find lowest
        if (arr[i] < smallest)
        {
            smallest = arr[i];
        }
    }
    //gets avarage 
    RangePerPlace = (biggest - smallest) / (Nlength-1);
    //places
    for (int i = 0; i < length; i++)
    {
        place = Nlength - ((arr[i] - smallest) / RangePerPlace)-1;
        if (place >= 0 && place < Nlength)
        {
            if (newarr[place] == -1)
            {
                newarr[place] = arr[i];
            }
            else
            {
                if(arr[i]!=arr[i-1])
                {
                    g = 0;
                }
                else
                {
                    g--;
                }
                keep = true;
                pw = true;
                while(++g<length&&keep&&pw)
                {
                    k = g;
                    if (arr[i] == biggest)
                    {
                        if (place + k >= Nlength - 1)
                        {
                            k = Nlength - place - 1;
                        }
                        if (newarr[place + k] == -1)
                        {
                            newarr[place + k] = arr[i];
                            keep = false;
                        }else
                        {
                            if (arr[i] > newarr[place + k] && pw)
                            {
                                cout << "crashing" << arr[i] << " ";
                                fc++;
                                next = new FailBlock{ arr[i],0,nullptr };
                                temp->next = next;
                                temp = next;
                                pw = false;
                            }
                        }
                    }else
                    {
                        if (arr[i] < newarr[place])
                        {
                            if (place + k > Nlength - 1)
                            {
                                k = Nlength - place - 1;
                            }
                                if (arr[i] > newarr[place + k]&&pw)
                                {
                                    cout << "crashing" << arr[i] << " ";
                                    next = new FailBlock{ arr[i],0,nullptr };
                                    temp->next = next;
                                    temp = next;
                                    fc++;
                                    pw = false;
                                }
                            if (newarr[place + k] == -1)
                            {

                                newarr[place + k] = arr[i];
                                keep = false;
                            }
                        }else
                        {
                            if (place < k)
                            {
                                k = place;
                            }
                                if (arr[i] < newarr[place - k] && newarr[place - k] > -1&&pw)
                                {
                                    cout << "crashing" << arr[i] << " ";
                                    next = new FailBlock{ arr[i],0,nullptr };
                                    temp->next = next;
                                    temp = next;
                                    fc++;
                                    pw = false;
                                }
                            if (newarr[place - k] == -1)
                            {
                                newarr[place - k] = arr[i];
                                keep = false;
                            }

                        }
                    }
                }
            }
        }
        else
        {
            cout << "out of borders";
        }
    }
    cout << endl << endl << fc << endl << endl;
    for (int i = 0; i < Nlength; i++)
    {
        cout << newarr[i] << ",";
    }
    int z = 0;
    for (int i = 0; i < Nlength; i++)
    {
        if (newarr[i] != -1)
        {
            arr[z] = newarr[i];
            z++;
        }
    }
    cout << endl << endl <<(double(z) / length * 100) << "%" << endl << endl;
    for (z; z < length; z++)
    {
        arr[z] = -1;
    }
    for (int i = 0; i < length; i++)
    {
        cout << arr[i] << ",";
    }
    if(fc>0)
    {
        next = start->next;
        cout << endl << endl;
        int flength = 0;
        RangePerPlace = (biggest - smallest) / (length - 1);
        while (next != nullptr)
        {
            next->estpos = length - ((next->value - smallest) / RangePerPlace) - 1;
            cout << next->estpos << ",";
            next = next->next;
            flength++;
        }
        FailBlock* ar = nullptr;
        ar = new FailBlock[flength];
        next = start->next;
        int y = 0;
        while (next != nullptr)
        {
            ar[y] = *next;
            y++;
            next = next->next;
        }
        cout << endl << endl << methood1(ar, flength, 0) << endl << endl;
        for (int i = 0; i < flength; i++)
        {
            cout << ar[i].estpos << ",";
        }
        cout << endl << endl;
        double* result = failfix(arr, ar, length, flength);

        for (int i=0 ;i < length; i++)
        {
            cout << result[i] << ",";
        }
    }
    return rounds;
}
int methood3(double* arr, int length, int rounds)
{
    node *start = new node{arr[0],NULL};
    node *temp = start;
    node *next = start;
    ////biulding node array
    //for (int i = 0; i < length-1; i++)
    //{/*
    //    if (arr[i] < next->value)
    //    {*/
    //        temp = next;
    //        next = new node{ arr[i],temp };

    //    //}
    //}
    for (int i = 1; i < length; i++)
    {
        next = new node{ arr[i],NULL };
        temp->next = next;
        temp = next;
    }
    node* pron=start,*fr=start;
    cout << endl << endl << 2131232312 << endl;
    for (int i = 0; i < length; i++)
    {
        cout << pron->value << ",";
        pron = pron->next;
        free(fr);
        fr = pron;
    }
    cout << endl << endl << "cleaned";
    return 0;
}
double* failfix(double* arr, FailBlock* ar, int length,int flength)
{
    int fplace = 0,jump=0,whijump=0;
    double* newarr;
    newarr = new double[length];
    for (int i = 0; i < length; i++)
    {
        if (i == ar[fplace].estpos)
        {
            whijump = 0;
            while (ar[fplace].estpos == i)
            {
                newarr[i+whijump] = ar[fplace].value;
                jump++;
                fplace++;
                whijump++;
            }
            i += whijump;
        }
        else
        {
            newarr[i] = arr[i-jump];
        }
    }
    return newarr;
}