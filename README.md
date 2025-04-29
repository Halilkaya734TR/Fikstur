# <center> Dil || Language </center>
Dilinize uygun olanı seçiniz. || Choose your language.

-[Türkçe/Turkish](#Türkçe/Turkish)
-[English/İngilizce](#English/İngilizce)

#Türkçe/Turkish
# <center>Fikstür Oluşturma Ödevi</center>

Verilen bir takimlar.txt dosyasından alınan takımları her hafta eşleştirerek aralarında maçlar oynatan ve sonuçlara göre bir puan tablosu oluşturan bir C kodudur. Maç skorları, takımların güç farklarına bağlı olarak belirlenmektedir.


## İçindekiler
-[Proje Gereksinimleri](#Proje-Gereksinimleri)
-[El İle Koşturma](#El-ile-Koşturma)
-[El ile Derleme](#El-ile-Derleme)
-[Kodu Derleme](#Kodu-Derleme)
-[Dosya Formatı](#Dosya-Formatı)
-[Dikkat Edilmesi Gerekenler](#Dikkat-Edilmesi-Gerekenler)
-[Yenilikler](#Yenilikler)

## Proje Gereksinimleri

### Kod derleme araçları

```
gcc
```

## Desteklenen İşletim Sistemleri

- Windows
- Linux

## El ile Koşturma

### Windows

```
./fikstur.exe
```

### Linux

```
./fikstur.o
```

## El ile Derleme

### Gereksinimleri İndirme

#### Fedora

```
sudo dnf install gcc
```

#### Ubuntu

```
sudo apt-get install gcc
```

#### Windows

```
Mingw64-gcc
```

### Kodu Derleme

#### Windows
```
gcc -o fikstur.exe fikstur.c
```

#### Windows
```
gcc -o fikstur.o fikstur.c
```

## Dosya Formatı

### Takımlar Dosyası

Örnek dosya formatı

```
(Takım Adı)
(Takım Adı)
(Takım Adı)
(Takım Adı)
```

### Fikstur Çıktı Dosyası

- Örnek olarak bir tane fikstur.txt dosyası konulmuştur.

### Power Dosyası
```
(sayi)
(sayi)
(sayi)
```

### Puan Dosyası

- Örnek olarak bir tane puanlar.txt dosyası konulmuştur.

## Dikkat Edilmesi Gerekenler

- Takımlar dosyasını örnek dosya formatında olması gerek yoksa hata verebilir.
- Takım eşlesmelerinde rastgele olduğundan 38 haftada 2 farklı takım birlikte ikiden fazla maç yapmış olabiliyor. (Çözüm aranıyor.)
- Güç aralığını farkını en fazla 50 olması ve güç sayısı 10 nun katları olmalı. (90 80 70 60 50 40 kullanılmıştır.)
- Bay geçen takım bazen aynı takım olabiliyor.(Sorun çözümü deneniyor.)

## Yenilikler 29.04.2024

- puanlar.txt de takım karışıklığı olmaması için puanlar en yüksekten en düşüğe göre sıralandı.
- Değişkenler daha evrensel olması için ingilizce değiştirildi.


#English/İngilizce

# <center>Fixture Generation Assignment</center>

This is a C program that reads team names from a given `takimlar.txt` file, matches them weekly, simulates matches, and generates a points table based on the results. Match scores are determined randomly according to the power differences between teams.

## Table of Contents
-[Project Requirements](#project-requirements)  
-[Manual Execution](#manual-execution)  
-[Manual Compilation](#manual-compilation)  
-[Compiling the Code](#compiling-the-code)  
-[File Format](#file-format)  
-[Important Notes](#important-notes)  
-[Changelog](#changelog)

## Project Requirements

### Compilation Tools

```
gcc
```

## Supported Operating Systems

- Windows  
- Linux  

## Manual Execution

### Windows

```
./fikstur.exe
```

### Linux

```
./fikstur.o
```

## Manual Compilation

### Installing Requirements

#### Fedora

```
sudo dnf install gcc
```

#### Ubuntu

```
sudo apt-get install gcc
```

#### Windows

```
Mingw64-gcc
```

## Compiling the Code

#### Windows
```
gcc -o fikstur.exe fikstur.c
```

#### Linux
```
gcc -o fikstur.o fikstur.c
```

## File Format

### Teams File

Example format:

```
(Team Name)
(Team Name)
(Team Name)
(Team Name)
```

### Fixture Output File

- An example `fikstur.txt` file is included.

### Power File
```
(number)
(number)
(number)
```

### Points File

- An example `puanlar.txt` file is included.

## Important Notes

- The teams file must follow the example format; otherwise, the program may throw an error.
- Due to the randomness in match pairings, some teams may play each other more than twice over 38 weeks. (A fix is being worked on.)
- The power range difference should not exceed 50, and power values should be multiples of 10. (90, 80, 70, 60, 50, 40 are used.)
- The same team may sometimes get a bye multiple times. (A solution is in progress.)

## Changelog 29.04.2024

- In `puanlar.txt`, teams are now sorted from highest to lowest points to avoid confusion.
- Variable names have been updated to English for better general understanding.
