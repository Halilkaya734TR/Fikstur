# Available Languages: 
[English](README.eng.md) | [Türkçe](README.md)

# <center>Fikstür Oluşturma Ödevi</center>

Verilen bir `takimlar.txt` dosyasından alınan takımları her hafta eşleştirerek aralarında maçlar oynatan ve sonuçlara göre bir puan tablosu oluşturan bir C kodudur. Maç skorları, takımların güç farklarına bağlı olarak belirlenmektedir.


## İçindekiler
- [Proje Gereksinimleri](#proje-gereksinimleri)  
- [El İle Koşturma](#el-ile-koşturma)  
- [El ile Derleme](#el-ile-derleme)  
- [Kodu Derleme](#kodu-derleme)  
- [Dosya Formatı](#dosya-formatı)  
- [Dikkat Edilmesi Gerekenler](#dikkat-edilmesi-gerekenler)  
- [Yenilikler](#yenilikler-29042024)


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

- Örnek olarak bir tane `fikstur.txt` dosyası konulmuştur.

### Power Dosyası
```
(sayi)
(sayi)
(sayi)
```

### Puan Dosyası

- Örnek olarak bir tane `puanlar.txt` dosyası konulmuştur.

## Dikkat Edilmesi Gerekenler

- Takımlar dosyasını örnek dosya formatında olması gerek yoksa hata verebilir.
- Güç aralığını farkını en fazla 50 olması ve güç sayısı 10 nun katları olmalı. (90 80 70 60 50 40 kullanılmıştır.)
  
## Yenilikler 06.05.2025
- `Difference` değişkenine göre gol atma olasıkları olan kod Switcase ile yapıldı ve ayrı `macSonuclari()` fonksiyonu eklendi.
- Kodlar daha da düzenli hale getirildi.
- Bay geçme sorunu çözüldü.
- İlk 19 hafta ile son 19 hafta maçları aynı şekilde sadece ev ve deplasman yer değiştirilmiş hale getirirdi.(Daha gerçekçi.)
- Türkçe ve ingilizce ReadME ayrıldı.
