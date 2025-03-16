#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char takimlar[19][40];
int baygecentakim;

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
            
            eslesme[deplasman] = 1;
            printf(" %s X %s\n", takimlar[ev], takimlar[deplasman]);
            fprintf(dosya, " %s X %s\n", takimlar[ev], takimlar[deplasman]);
            
        }
        }
    }
    fclose(dosya);
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
        fikstur();
    }
    
}