#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "fikstur.h"

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

int main()
{
    FILE *teamsfile = fopen("takimlar.txt","r");
    if(teamsfile == NULL)
    {
        printf("takimlar.txt dosyasi acilamadi!"); // Dosya açılmazsa hata kodu verir.
        fclose(teamsfile);
        return 1;
    }

    for(int i=0; i<19; i++)
    {
        fgets(teams[i], 40, teamsfile); //Dosyadaki takımları takimlar değişkenine atar.
    } 
    fclose(teamsfile); 
        
    FILE *powerFile = fopen("power.txt","r"); //power dosyasını açar
    if(powerFile == NULL)
    {
        printf("power.txt dosyasi acilamadi!"); //Açılmazsa hata verir.
        fclose(powerFile);
        return 1;
    }
        
    for(int i=0; i<19; i++)
    {
        fscanf(powerFile, "%d", &power[i]); //Güç değerlerini power dizisine atar.
    } 
    fclose(powerFile); 
    fikstur();
}

int fikstur() //fikstür eşlestirmesi yapıyor.
{
    int home, away;
    int matchUp[19] = {0}; // 0 olması eşlenmemiş olduğunu gösterir.
    int firstHalfMatches[19][2]; // İlk 19 maç ile son 19 maç aynı olsun diye.
    int byeTeams[19]; // Bay geçen takımları sırasıyla kaydeder.
    int byeIndex = 0; // Bay geçen takım sayacı.
    srand(time(NULL));
    FILE *dosya = fopen("fikstur.txt", "w"); // Fikstür dosyasını write modunda açar.
    if(dosya == NULL)
    {
        printf("fikstur.txt dosyasi acilamadi!"); //fikstür dosyası bulunmazsa hata yazısı yazdırır.
        fclose(dosya);
        return 1;
    }
    
    // İlk 19 hafta maçları eşleştirir.
    for(int week = 1; week <= 19; week++)  
    {   
        for(int i = 0; i < 19; i++)
        {
            matchUp[i] = 0;  // Her hafta başında tüm takımları eşleşmemiş olarak işaretler
        }

        printf("\n  %d. Hafta \n", week);
        fprintf(dosya, "\n  %d. Hafta \n", week);

        if(week == 1) // İlk hafta ise direkt seçer.
        {
            byeTeam = rand() % 19;             
        } 
        else 
        {
            do 
            {
                byeTeam = rand() % 19;                 
            } while(matchUp[byeTeam] == 1); //Sonraki haftalarda seçilmemiş kontrol eder.
        }
        
        byeTeams[byeIndex++] = byeTeam; // Bay geçen takım sayısında sorun olmaması için.
        matchUp[byeTeam] = 1;

        printf("Bu hafta bay gecen takim: %s\n", teams[byeTeam]);
        fprintf(dosya, "Bu hafta bay gecen takim: %s\n", teams[byeTeam]);

        for(int matchCount = 0; matchCount < 9; matchCount++) 
        {
            do 
            {
                home = rand() % 19;    
            } while(matchUp[home] == 1);

            matchUp[home] = 1;
            
            do
            {
                away = rand() % 19;   
            } while(matchUp[away] == 1);
            
            matchUp[away] = 1;
            
            firstHalfMatches[matchCount][0] = home;   
            firstHalfMatches[matchCount][1] = away;
            macSonuclari(home, away, dosya);      
        }
    }

    // Son 19 hafta maçları ilk 19 haftayla aynı.
    for(int week = 20; week <= 38; week++)    
    {   
        printf("\n  %d. Hafta \n", week);
        fprintf(dosya, "\n  %d. Hafta \n", week);

        byeTeam = byeTeams[week - 20];
        printf("Bu hafta bay gecen takim: %s\n", teams[byeTeam]);
        fprintf(dosya, "Bu hafta bay gecen takim: %s\n", teams[byeTeam]);

        for(int matchCount = 0; matchCount < 9; matchCount++) 
        {
            away = firstHalfMatches[matchCount][0];
            home = firstHalfMatches[matchCount][1];
            macSonuclari(home, away, dosya);
        }
    }
    fclose(dosya);
    siralama();
}

void macSonuclari(int home, int away, FILE *dosya) //Maçta atılan golları vb. hesaplar.
{
    int goalsHome, goalsAway;
    int difference = ((power[home] - power[away]) /10) +5; //Güç farkını hesaplar ve o farkla skor olasılıkları belirlenir.
    switch (difference)
    {
     case 0:
        goalsHome = rand() % 2;
        goalsAway = rand() % 6;
        break;
     case 1:
        goalsHome = rand() % 2;
        goalsAway = rand() % 5;
        break;
    case 2:
        goalsHome = rand() % 2;
        goalsAway = rand() % 4;
        break;
    case 3:
        goalsHome = rand() % 2;
        goalsAway = rand() % 4;
        break;
    case 4:
        goalsHome = rand() % 3;
        goalsAway = rand() % 4;
        break;
    case 5:
        goalsHome = rand() % 3;
        goalsAway = rand() % 3;
        break;
    case 6:
        goalsHome = rand() % 4;
        goalsAway = rand() % 3;
        break;
    case 7:
        goalsHome = rand() % 4;
        goalsAway = rand() % 2;
        break;
    case 8:
        goalsHome = rand() % 4;
        goalsAway = rand() % 2;
        break;
    case 9:
        goalsHome = rand() % 5;
        goalsAway = rand() % 2;
        break;
    case 10:
        goalsHome = rand() % 6;
        goalsAway = rand() % 2;
        break;
    }

    goalScored[home] += goalsHome;
    goalConceded[home] += goalsAway; 
    goalScored[away] += goalsAway; 
    goalConceded[away] += goalsHome;
    
    if(goalsHome > goalsAway)
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
        draw[home] +=1;
        draw[away] +=1;
    }
    
    printf(" %s %d X %d %s \n", teams[home], goalsHome, goalsAway, teams[away]);
    fprintf(dosya, " %s %d X %d %s \n", teams[home], goalsHome, goalsAway, teams[away]);
}

void siralama() // Takımları puanlarına göre sıralama yapar.
{
    for(int i=0; i<=18; i++)
    {
        for(int j= i+1; j<=18; j++)
        {
            if(points[i] < points[j] || points[i] == points[j] && average[i] < average[j])
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
    yazdirma();
}

int yazdirma()
{
    FILE *dosya = fopen("puanlar.txt", "w"); //puanlar için puanlar.txt açar.
    if(dosya == NULL)
    {
        printf("puanlar.txt dosyasi acilamadi!"); //Açılmazsa hata kodu verir.
        fclose(dosya);
        return 1;
    }
    
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
        
    fclose(dosya);
}