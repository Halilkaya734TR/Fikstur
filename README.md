# <center>Fikstür Oluşturma Ödevi</center>

Verilen dosyadan takımları alıp o takımları eşleştirip, eşlesen takımları dosyaya yazan C kodu.

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


## Dikkat Edilmesi Gerekenler

- Takımlar dosyasını örnek dosya formatında olması gerek yoksa hata verebilir.
- Takım eşlesmelerinde rastgele olduğundan 38 haftada 2 farklı takım birlikte ikiden fazla maç yapmış olabiliyor. (Algoritma bulsamda kodsal olarak nasıl yapacağımı bulamadım.)
