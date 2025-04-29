#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

char teams[19][40];
int byeTeam;
int power[19];
int points[19] = {0};
int win[19] = {0};
int lose[19] = {0};
int draw[19] = {0};
int goalScored[19] = {0};
int goalConceded[19] = {0};
int average[19] = {0};

void siralama() // Takımları puanlarına göre sıralama yapar. (Yeni Eklendi.)
{
    for(int i=0; i<=18; i++)
    {
        for(int j= i+1; j<=18; j++)
        {
            if(points[i]  < points[j] || points[i] == points[j] && average[i] < average[j])
            {
                int temp = points[i];
                points[i] = points[j];
                points[j] = temp;

                temp = average[i];
                average[i] = average[j];
                average[j] = temp;

                temp = win[i];
                win[i] = win[j];
                win[j] = temp;

                temp = lose[i];
                lose[i] = lose[j];
                lose[j] = temp;

                temp = draw[i];
                draw[i] = draw[j];
                draw[j] = temp;

                temp = goalScored[i];
                goalScored[i] = goalScored[j];
                goalScored[j] = temp;

                temp = goalConceded[i];
                goalConceded[i] = goalConceded[j];
                goalConceded[j] = temp;

                char tempTeams[40];
                strcpy(tempTeams, teams[i]);
                strcpy(teams[i], teams[j]);
                strcpy(teams[j], tempTeams);
            }
        }

    }

}
void fikstur() //fikstür eşlestirmesi yapıyor.
{
    int home, away;
    int matchUp[19] = {0}; // 0 olması eşlenmemiş olduğunu gösterir.
    srand(time(NULL));
    FILE *dosya = fopen("fikstur.txt", "w"); // Fikstür dosyasını write modunda açar.
    if(dosya == NULL)
    {
        printf("fikstur.txt dosyasi acilamadi!"); //fikstür dosyası bulunmazsa hata yazısı yazdırır.
        fclose(dosya);
    }
    else
    {
        for(int week = 1; week <= 38; week++)  //38 hafta için döngü oluşturur.
        {   int matchUp[19] = {0}; // Her haftada takımların seçilmemiş olarak değiştirir.

            printf("\n  %d. Hafta \n", week); // Kaçıncı haftada olunduğunu yazar.
            fprintf(dosya, "\n  %d. Hafta \n", week); //Aynısını dosyaya yazdırır.

            byeTeam = rand() % 19; //Bay geçen takımı rastgele seçer.
            printf("Bu hafta bay gecen takim: %s\n", teams[byeTeam]); //Bay geçen takımı yazar.
            fprintf(dosya, "Bu hafta bay gecen takim: %s\n", teams[byeTeam]); // Bay geçen takımı dosyaya yazar.

        matchUp[byeTeam] = 1; // Eşlenmemesi için 1 verilir. (Yani seçilmiş yapar.)
        for(int matchCount = 0; matchCount < 9; matchCount++) 
        {
            do
            {
                home = rand() % 19; // Ev takımı olan maçları eşleştirir.
            }
            while(matchUp[home] == 1);

            matchUp[home] = 1;
            
            do
            {
                away = rand() % 19; // Deplasman takımı olan maçları eşleştirir.
            }
            while(matchUp[away] == 1);
            
            int goalsHome, goalsAway; //Ev ve deplasmanın gol sayılarını tutar.
            matchUp[away] = 1;
            int difference = power[home] - power[away]; //Güç farkını hesaplar ve o farkla skor olasılıkları belirlenir.
            if(difference == 0)
            {
                goalsHome = rand() % 3;
                goalsAway = rand() % 3;
            
            }
            else if(difference == 10)
            {
                goalsHome = rand() % 4;
                goalsAway = rand() % 3;
            
            }
            else if(difference == 20)
            {
                goalsHome = rand() % 4;
                goalsAway = rand() % 2;
            
            }
            else if(difference == 30)
            {
                goalsHome = rand() % 4;
                goalsAway = rand() % 2;
            
            }
            else if(difference == 40)
            {
                goalsHome = rand() % 5;
                goalsAway = rand() % 2;
            
            }
            else if(difference == 50)
            {
                goalsHome = rand() % 6;
                goalsAway = rand() % 2;
            
            }
            else if(difference == -10)
            {
                goalsHome = rand() % 3;
                goalsAway = rand() % 4;
            
            }
            else if(difference == -20)
            {
                goalsHome = rand() % 2;
                goalsAway = rand() % 4;
            
            }
            else if(difference == -30)
            {
                goalsHome = rand() % 2;
                goalsAway = rand() % 4;
            
            }
            else if(difference == -40)
            {
                goalsHome = rand() % 2;
                goalsAway = rand() % 5;
            
            }
            else if(difference == -50)
            {
                goalsHome = rand() % 2;
                goalsAway = rand() % 6;
            
            }
            goalScored[home] += goalsHome;  //Atılan ve yenilen golleri kaydeder.
            goalConceded[home] += goalsAway; 
            goalScored[away] += goalsAway; 
            goalConceded[away] += goalsHome;
            if(goalsHome > goalsAway) //Gollere göre puan verilir.
            {
                points[home] +=3;
                win[home] += 1;
                lose[away] +=1;
            }
            else if(goalsHome < goalsAway)
            {
                points[away] +=3;
                win[away] += 1;
                lose[home] +=1;
            }
            else
            {
                points[home] +=1;
                points[away] +=1;
                draw[home] = +1;
                draw[away] =+1;
            }
            printf(" %s %d X %d %s \n", teams[home], goalsHome, goalsAway, teams[away]); //Takım maçını ve skoru konsola yazdırır.
            fprintf(dosya, " %s %d X %d %s \n", teams[home], goalsHome, goalsAway, teams[away]); //Aynısını fikstür.txt yazdırır.
            
        }
        }
        fclose(dosya);
        siralama();
        
        FILE *dosya = fopen("puanlar.txt", "w"); //puanlar için puanlar.txt açar.
        if(dosya == NULL)
        {
            printf("puanlar.txt dosyasi acilamadi!"); //Açılmazsa hata kodu verir.
            fclose(dosya);
        }
        else
        {
            for(int i=0; i<19; i++) //Takımların istatistiklerini yazdırır.
            {   
            
                average[i] = goalScored[i] - goalConceded[i]; //Averaj hesaplar.
                printf("%s G:%d B:%d M:%d AG:%d YG:%d A:%d Puan:%d\n",teams[i],win[i],draw[i],lose[i],goalScored[i],goalConceded[i],average[i],points[i]);
                fprintf(dosya, "%s G:%d B:%d M:%d AG:%d YG:%d A:%d Puan:%d\n",teams[i],win[i],draw[i],lose[i],goalScored[i],goalConceded[i],average[i],points[i]);
            }
        
            int champion=0;
        
            for(int i=1; i<19; i++) //Şampiyonun kim olduğunu belirler.
            {
            
                if(points[champion] < points[i])
                champion = i;
            
            }
        
            printf("%d puan ile ŞAMPİYON %s",points[champion],teams[champion]); //Şampiyonu konsola yazdırır
            fprintf(dosya, "%d puan ile ŞAMPİYON %s",points[champion],teams[champion]); //Dosyaya yazdırır.
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
            fgets(teams[i], 40, dosya); //Dosyadaki takımları takimlar değişkenine atar.
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