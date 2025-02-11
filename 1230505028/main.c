#include <stdio.h>
#include <time.h>

// Tarih bilgisini saklamak i�in struct
struct DateTime {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

// Epoch zaman�n� saklamak i�in union
union EpochTime {
    time_t epoch;
};

// Kullan�c�n�n girdi�i tarih ve saat bilgilerini epoch format�na �eviren fonksiyon
time_t convertToEpoch(struct DateTime dt) {
    struct tm t;
    t.tm_year = dt.year - 1900;
    t.tm_mon = dt.month - 1;
    t.tm_mday = dt.day;
    t.tm_hour = dt.hour;
    t.tm_min = dt.minute;
    t.tm_sec = dt.second;
    t.tm_isdst = -1; // G�n ����� tasarrufu bilinmiyor
    return mktime(&t);
}

int main() {
    struct DateTime dt1, dt2;
    union EpochTime et1, et2;

    // Kullan�c�dan ilk tarih ve saat bilgisini alma
    printf("Birinci tarihi girin (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &dt1.year, &dt1.month, &dt1.day, &dt1.hour, &dt1.minute, &dt1.second);
    
    // Kullan�c�dan ikinci tarih ve saat bilgisini alma
    printf("Ikinci tarihi girin (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &dt2.year, &dt2.month, &dt2.day, &dt2.hour, &dt2.minute, &dt2.second);
    
    // Epoch zamanlar�n� hesaplama
    et1.epoch = convertToEpoch(dt1);
    et2.epoch = convertToEpoch(dt2);

    // Epoch de�erlerini ve zaman fark�n� ekrana yazd�rma
    printf("Birinci tarihin epoch zamani: %ld\n", et1.epoch);
    printf("Ikinci tarihin epoch zamani: %ld\n", et2.epoch);
    printf("Iki tarih arasindaki zaman farki (saniye): %ld sn\n", (long)difftime(et2.epoch, et1.epoch));
    
    return 0;
}


