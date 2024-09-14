#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct {  //burada iki noktanın da 2’şer bileşeni olduğu için x ve y adında 2 adet double değişkenli struct kullandım
    double x;
    double y;
} Nokta;

double mesafe_hesapla(const Nokta* p1, const Nokta* p2) {
    if (p1 == NULL || p2 == NULL) {
        fprintf(stderr, "Hata: Geçersiz nokta referansı.\n");
        return -1;
    }
    return sqrt(pow(p2->x - p1->x, 2) + pow(p2->y - p1->y, 2));
}

int nokta_al(Nokta* p) {
    if (p == NULL) return 0;

    printf("Noktanın x ve y koordinatlarını girin (örneğin: 1.2 3.4): ");
    if (scanf("%lf %lf", &p->x, &p->y) != 2) {
        fprintf(stderr, "Hata: Hatalı giriş! Lütfen geçerli sayısal değerler girin.\n");
        return 0;
    }
    return 1;
}

void mesafe_hesapla_ve_goster(const Nokta* p1, const Nokta* p2) {
    double mesafe = mesafe_hesapla(p1, p2);
    if (mesafe >= 0) {
        printf("İki nokta arasındaki kuş uçuşu mesafe: %.2f birim\n", mesafe);
    } else {
        printf("Hata: Mesafe hesaplanamadı.\n");
    }
}

void programi_calistir() {
    Nokta p1, p2;

    printf("Birinci nokta:\n");
    if (!nokta_al(&p1)) {
        fprintf(stderr, "Hata: Birinci nokta girişi hatalı. Program sonlandırılıyor.\n");
        return;
    }

    printf("İkinci nokta:\n");
    if (!nokta_al(&p2)) {
        fprintf(stderr, "Hata: İkinci nokta girişi hatalı. Program sonlandırılıyor.\n");
        return;
    }

    mesafe_hesapla_ve_goster(&p1, &p2);
}

int main() {
    programi_calistir();
    return EXIT_SUCCESS;
}
