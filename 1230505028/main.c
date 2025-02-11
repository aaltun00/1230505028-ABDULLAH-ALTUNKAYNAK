#include <stdio.h>
#include <time.h>

// Tarih bilgisini saklamak için struct
struct DateTime {
    int year;
    int month;
    int day;
    int hour;
    int minute;
    int second;
};

// Epoch zamanýný saklamak için union
union EpochTime {
    time_t epoch;
};

// Kullanýcýnýn girdiði tarih ve saat bilgilerini epoch formatýna çeviren fonksiyon
time_t convertToEpoch(struct DateTime dt) {
    struct tm t;
    t.tm_year = dt.year - 1900;
    t.tm_mon = dt.month - 1;
    t.tm_mday = dt.day;
    t.tm_hour = dt.hour;
    t.tm_min = dt.minute;
    t.tm_sec = dt.second;
    t.tm_isdst = -1; // Gün ýþýðý tasarrufu bilinmiyor
    return mktime(&t);
}

int main() {
    struct DateTime dt1, dt2;
    union EpochTime et1, et2;

    // Kullanýcýdan ilk tarih ve saat bilgisini alma
    printf("Birinci tarihi girin (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &dt1.year, &dt1.month, &dt1.day, &dt1.hour, &dt1.minute, &dt1.second);
    
    // Kullanýcýdan ikinci tarih ve saat bilgisini alma
    printf("Ikinci tarihi girin (YYYY MM DD HH MM SS): ");
    scanf("%d %d %d %d %d %d", &dt2.year, &dt2.month, &dt2.day, &dt2.hour, &dt2.minute, &dt2.second);
    
    // Epoch zamanlarýný hesaplama
    et1.epoch = convertToEpoch(dt1);
    et2.epoch = convertToEpoch(dt2);

    // Epoch deðerlerini ve zaman farkýný ekrana yazdýrma
    printf("Birinci tarihin epoch zamani: %ld\n", et1.epoch);
    printf("Ikinci tarihin epoch zamani: %ld\n", et2.epoch);
    printf("Iki tarih arasindaki zaman farki (saniye): %ld sn\n", (long)difftime(et2.epoch, et1.epoch));
    
    return 0;
}


