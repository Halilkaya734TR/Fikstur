#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char takimlar[19][40];
int baygecentakim;
int power[19];
int puan[19] = {0};
int galibiyet[19] = {0};
int maglubiyet[19] = {0};
int berabere[19] = {0};
int atilangol[19] = {0};
int yenilengol[19] = {0};
int averaj[19] = {0};

void fikstur() //fikstür eşlestirmesi yapıyor.
{
    int ev, deplasman;
    int eslesme[19] = {0}; // 0 olması eşlenmemiş olduğunu gösterir.
    srand(time(NULL));
    FILE *dosya = fopen("fikstur.txt", "w"); // Fikstür dosyasını write modunda açar.
    if(dosya == NULL)
    {
        printf("fikstur.txt dosyasi acilamadi!"); //fikstür dosyası bulunmazsa hata yazısı yazdırır.
        fclose(dosya);
    }
    else
    {
        for(int hafta = 1; hafta <= 38; hafta++)  //38 hafta için döngü oluşturur.
        {   int eslesme[19] = {0}; // Her haftada takımların seçilmemiş olarak değiştirir.

            printf("\n  %d. Hafta \n", hafta); // Kaçıncı haftada olunduğunu yazar.
            fprintf(dosya, "\n  %d. Hafta \n", hafta); //Aynısını dosyaya yazdırır.

            baygecentakim = rand() % 19; //Bay geçen takımı rastgele seçer.
            printf("Bu hafta bay gecen takim: %s\n", takimlar[baygecentakim]); //Bay geçen takımı yazar.
            fprintf(dosya, "Bu hafta bay gecen takim: %s\n", takimlar[baygecentakim]); // Bay geçen takımı dosyaya yazar.

        eslesme[baygecentakim] = 1; // Eşlenmemesi için 1 verilir. (Yani seçilmiş yapar.)
        for(int macsayisi = 0; macsayisi < 9; macsayisi++) 
        {
            do
            {
                ev = rand() % 19; // Ev takımı olan maçları eşleştirir.
            }
            while(eslesme[ev] == 1);

            eslesme[ev] = 1;
            
            do
            {
                deplasman = rand() % 19; // Deplasman takımı olan maçları eşleştirir.
            }
            while(eslesme[deplasman] == 1);
            
            int golev, goldeplasman; //Ev ve deplasmanın gol sayılarını tutar.
            eslesme[deplasman] = 1;
            int fark = power[ev] - power[deplasman]; //Güç farkını hesaplar ve o farkla skor olasılıkları belirlenir.
            if(fark == 0)
            {
                golev = rand() % 3;
                goldeplasman = rand() % 3;
            
            }
            else if(fark == 10)
            {
                golev = rand() % 4;
                goldeplasman = rand() % 3;
            
            }
            else if(fark == 20)
            {
                golev = rand() % 4;
                goldeplasman = rand() % 2;
            
            }
            else if(fark == 30)
            {
                golev = rand() % 4;
                goldeplasman = rand() % 2;
            
            }
            else if(fark == 40)
            {
                golev = rand() % 5;
                goldeplasman = rand() % 2;
            
            }
            else if(fark == 50)
            {
                golev = rand() % 6;
                goldeplasman = rand() % 2;
            
            }
            else if(fark == -10)
            {
                golev = rand() % 3;
                goldeplasman = rand() % 4;
            
            }
            else if(fark == -20)
            {
                golev = rand() % 2;
                goldeplasman = rand() % 4;
            
            }
            else if(fark == -30)
            {
                golev = rand() % 2;
                goldeplasman = rand() % 4;
            
            }
            else if(fark == -40)
            {
                golev = rand() % 2;
                goldeplasman = rand() % 5;
            
            }
            else if(fark == -50)
            {
                golev = rand() % 2;
                goldeplasman = rand() % 6;
            
            }
            atilangol[ev] += golev;  //Atılan ve yenilen golleri kaydeder.
            yenilengol[ev] += goldeplasman; 
            atilangol[deplasman] += goldeplasman; 
            yenilengol[deplasman] += golev;
            if(golev > goldeplasman) //Gollere göre puan verilir.
            {
                puan[ev] +=3;
                galibiyet[ev] += 1;
                maglubiyet[deplasman] +=1;
            }
            else if(golev < goldeplasman)
            {
                puan[deplasman] +=3;
                galibiyet[deplasman] += 1;
                maglubiyet[ev] +=1;
            }
            else
            {
                puan[ev] +=1;
                puan[deplasman] +=1;
                berabere[ev] = +1;
                berabere[deplasman] =+1;
            }
            printf(" %s %d X %d %s \n", takimlar[ev], golev, goldeplasman, takimlar[deplasman]); //Takım maçını ve skoru konsola yazdırır.
            fprintf(dosya, " %s %d X %d %s \n", takimlar[ev], golev, goldeplasman, takimlar[deplasman]); //Aynısını fikstür.txt yazdırır.
            
        }
        }
        fclose(dosya);
        FILE *dosya = fopen("puanlar.txt", "w"); //puanlar için puanlar.txt açar.
        if(dosya == NULL)
        {
            printf("puanlar.txt dosyasi acilamadi!"); //Açılmazsa hata kodu verir.
            fclose(dosya);
        }
        else
        {for(int i=0; i<19; i++) //Takımların istatistiklerini yazdırır.
        {   
            averaj[i] = atilangol[i] - yenilengol[i]; //Averaj hesaplar.
            printf("%s G:%d B:%d M:%d AG:%d YG:%d A:%d Puan:%d\n",takimlar[i],galibiyet[i],berabere[i],maglubiyet[i],atilangol[i],yenilengol[i],averaj[i],puan[i]);
            fprintf(dosya, "%s G:%d B:%d M:%d AG:%d YG:%d A:%d Puan:%d\n",takimlar[i],galibiyet[i],berabere[i],maglubiyet[i],atilangol[i],yenilengol[i],averaj[i],puan[i]);
        }
        int sampiyon=0;
        for(int i=1; i<19; i++) //Şampiyonun kim olduğunu belirler.
        {
            if(puan[sampiyon]<puan[i])
            sampiyon = i;
            
        }
        printf("%d puan ile ŞAMPİYON %s",puan[sampiyon],takimlar[sampiyon]); //Şampiyonu konsola yazdırır
        fprintf(dosya, "%d puan ile ŞAMPİYON %s",puan[sampiyon],takimlar[sampiyon]); //Dosyaya yazdırır.
    }
    fclose(dosya);
}
}

int main()
{
    FILE *dosya = fopen("takimlar.txt","r");
    if(dosya == NULL)
    {
        printf("takimlar.txt dosyasi acilamadi!"); // Dosya açılmazsa hata kodu verir.
        fclose(dosya);
    }
    else
    {
        for(int i=0; i<19; i++)
        {
            fgets(takimlar[i], 40, dosya); //Dosyadaki takımları takimlar değişkenine atar.
        } 
        fclose(dosya); 
        FILE *dosya = fopen("power.txt","r"); //powerdosyasını açar
        if(dosya == NULL)
        {
            printf("power.txt dosyasi acilamadi!"); //Açılmazsa hata verir.
            fclose(dosya);
        }
        else
        {
            for(int i=0; i<19; i++)
            {
            fscanf(dosya, "%d", &power[i]); //Güç değerlerini power dizisine atar.
            } 
            
            fclose(dosya); 
            fikstur();
        }

    }
    
}
