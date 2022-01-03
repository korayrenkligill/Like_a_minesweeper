#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

int tahminX,tahminY,xm[3] = {10,10,10},ym[3] = {10,10,10},hamle=0,hamleX[10]={10,10,10,10,10,10,10,10,10,10},hamleY[10]={10,10,10,10,10,10,10,10,10,10},kalanBomba = 3;
int zorluk;
void Yazdir(int xm[],int ym[]);
void Tahmin(void);
void Kontrol(void);
void ZorlukSec(void);
int main()
{
    int i=0;
    time_t t;
    srand((unsigned) time(&t));
    system("CLS");
    ZorlukSec();
    if(zorluk==0)
    {
        for(i=0;i<1;i++)
        {
            xm[i] = rand() % 5;
            ym[i] = rand() % 5;
        }
        kalanBomba = 1;
    }
    else if(zorluk==1)
    {
        for(i=0;i<3;i++)
        {
            xm[i] = rand() % 5;
            ym[i] = rand() % 5;
            if(i == 0)
            {
                if((xm[i] == xm[1] || xm[i] == xm[2]) && (ym[i] == ym[1] || ym[i] == ym[2]))
                    i--;
            }
            else if(i == 1)
            {
                if((xm[i] == xm[0] || xm[i] == xm[2]) && (ym[i] == ym[0] || ym[i] == ym[2]))
                    i--;
            }
            else
            {
                if((xm[i] == xm[0] || xm[i] == xm[1]) && (ym[i] == ym[0] || ym[i] == ym[1]))
                    i--;
            }
        }
    }
    else
    {
        for(i=0;i<3;i++)
        {
            xm[i] = rand() % 7;
            ym[i] = rand() % 7;
            if(i == 0)
            {
                if((xm[i] == xm[1] || xm[i] == xm[2]) && (ym[i] == ym[1] || ym[i] == ym[2]))
                    i--;
            }
            else if(i == 1)
            {
                if((xm[i] == xm[0] || xm[i] == xm[2]) && (ym[i] == ym[0] || ym[i] == ym[2]))
                    i--;
            }
            else
            {
                if((xm[i] == xm[0] || xm[i] == xm[1]) && (ym[i] == ym[0] || ym[i] == ym[1]))
                    i--;
            }
        }
    }
    Yazdir(xm,ym);

    return 0;
}
void Yazdir(int xm[],int ym[])
{
    int x= 0,y= 0;
    system("CLS");
    if(zorluk==0)
    {
        if(hamle<10 && kalanBomba > 0)
        {
            if(y==0)
                printf("   0  1  2  3  4    -------------------\n");
            for(y=0;y<5;y++)
            {
                printf("%d ",y);
                for(x=0;x<5;x++)
                {
                    if ((x==hamleX[0] && y==hamleY[0]) || (x==hamleX[1] && y==hamleY[1]) || (x==hamleX[2] && y==hamleY[2]) || (x==hamleX[3] && y==hamleY[3]) || (x==hamleX[4] && y==hamleY[4]) || (x==hamleX[5] && y==hamleY[5]) || (x==hamleX[6] && y==hamleY[6]) || (x==hamleX[7] && y==hamleY[7]) || (x==hamleX[8] && y==hamleY[8]) || (x==hamleX[9] && y==hamleY[9]))
                        printf("[/]");
                    //else if(x==xm[0] && y==ym[0])
                    //    printf("[+]");
                    else
                        printf("[-]");
                }
                if(y==0)
                    printf("   | Kalan Hamle: %2d |", 10-hamle);
                else if(y==1)
                    printf("   | Kalan Mayin: %2d |", kalanBomba);
                else if(y==2)
                    printf("   -------------------");
                printf("\n");
            }
            Tahmin();
        }
        else if(kalanBomba <= 0)
        {
            printf("TUM MAYINLAR TEMIZLENDI!\n\n");
        }
        else
            printf("HAMLEN TUKENDI!\n\n");
    }
    else if(zorluk==1)
    {
        if(hamle<10 && kalanBomba > 0)
        {
            if(y==0)
                printf("   0  1  2  3  4    -------------------\n");
            for(y=0;y<5;y++)
            {
                printf("%d ",y);
                for(x=0;x<5;x++)
                {
                    if ((x==hamleX[0] && y==hamleY[0]) || (x==hamleX[1] && y==hamleY[1]) || (x==hamleX[2] && y==hamleY[2]) || (x==hamleX[3] && y==hamleY[3]) || (x==hamleX[4] && y==hamleY[4]) || (x==hamleX[5] && y==hamleY[5]) || (x==hamleX[6] && y==hamleY[6]) || (x==hamleX[7] && y==hamleY[7]) || (x==hamleX[8] && y==hamleY[8]) || (x==hamleX[9] && y==hamleY[9]))
                        printf("[/]");
                    //else if(x==xm[0] && y==ym[0] || x==xm[1] && y==ym[1] || x==xm[2] && y==ym[2])
                    //    printf("[+]");
                    else
                        printf("[-]");
                }
                if(y==0)
                    printf("   | Kalan Hamle: %2d |", 10-hamle);
                else if(y==1)
                    printf("   | Kalan Mayin: %2d |", kalanBomba);
                else if(y==2)
                    printf("   -------------------");
                printf("\n");
            }
            Tahmin();
        }
        else if(kalanBomba <= 0)
        {
            printf("TUM MAYINLAR TEMIZLENDI!\n\n");
        }
        else
            printf("HAMLEN TUKENDI!\n\n");
    }
    else
    {
        if(hamle<10 && kalanBomba > 0)
        {
            for(y=0;y<7;y++)
            {
                if(y==0)
                    printf("   0  1  2  3  4  5  6    -------------------\n");
                printf("%d ",y);
                for(x=0;x<7;x++)
                {
                    if ((x==hamleX[0] && y==hamleY[0]) || (x==hamleX[1] && y==hamleY[1]) || (x==hamleX[2] && y==hamleY[2]) || (x==hamleX[3] && y==hamleY[3]) || (x==hamleX[4] && y==hamleY[4]) || (x==hamleX[5] && y==hamleY[5]) || (x==hamleX[6] && y==hamleY[6]) || (x==hamleX[7] && y==hamleY[7]) || (x==hamleX[8] && y==hamleY[8]) || (x==hamleX[9] && y==hamleY[9]))
                        printf("[/]");
                    //else if(x==xm[0] && y==ym[0] || x==xm[1] && y==ym[1] || x==xm[2] && y==ym[2])
                    //    printf("[+]");
                    else
                        printf("[-]");
                }
                if(y==0)
                    printf("   | Kalan Hamle: %2d |", 10-hamle);
                else if(y==1)
                    printf("   | Kalan Mayin: %2d |", kalanBomba);
                else if(y==2)
                    printf("   -------------------");
                printf("\n");
            }
            Tahmin();
        }
        else if(kalanBomba <= 0)
        {
            printf(">>> TUM MAYINLAR TEMIZLENDI!\n\n");
        }
        else
            printf(">>> HAMLEN TUKENDI!\n\n");
    }
}
void Tahmin()
{
    printf("Tahmin kordinati giriniz: ");
    scanf("%d %d", &tahminX, &tahminY);
    if(((tahminX<0 || tahminX > 4 || tahminY <0 || tahminY > 4) && zorluk < 2) || ((tahminX<0 || tahminX > 6 || tahminY <0 || tahminY > 6) && zorluk == 2))
    {
        printf(">>> HATALI KORDINAT GIRDINIZ!!\n\n");
        Tahmin();
    }
    else
    {
        hamleX[hamle] = tahminX;
        hamleY[hamle] = tahminY;
        hamle++;
        Kontrol();
    }
}
void Kontrol()
{
    int j;
    for (j = 0; j < 3; j++)
    {
        if(tahminX == xm[j] && tahminY == ym[j])
        {
            kalanBomba--;
            break;
        }
    }
    Yazdir(xm,ym);
}
void ZorlukSec()
{
    printf("[0]Kolay: 1 Mayin 5x5 Tarla\n[1]Orta: 3 Mayin 5x5 Tarla\n[2]Zor: 3 Mayin 7x7 Tarla\nBir zorluk seciniz: ");
    scanf("%d", &zorluk);
    if(zorluk<0||zorluk>2){
        printf("\n\n>>> Hatali sayi girdiniz!\n");
        ZorlukSec();
    }
}