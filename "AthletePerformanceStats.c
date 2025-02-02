#include <stdio.h>

#define athletes 8

int main() {
    double best_before_finals[athletes];
    double timing_final[athletes];
    double max = 0.0;
    double min = 10.50;
    double greater_improvement = 0.0;
    double improvement;
    int count_below_9_80 = 0;
    int best_athlete = -1;

    // Β.1 Εισαγωγή στοιχείων και σωστός έλεγχος τιμών με αμυντικό προγραμματισμό.
    for (int i = 0; i < athletes; i++) {
        do {
            printf("Δώσε τον καλύτερο χρόνο πριν από τους ολυμπιακούς αγώνες για τον αθλητή: %d\n", i + 1);
            scanf("%lf", &best_before_finals[i]);
            if (best_before_finals[i] < 9.50 || best_before_finals[i] > 10.50) {
                printf("Ο χρόνος πρέπει να είναι μεταξύ 9.50 και 10.50 δευτερολέπτων\n");
            }
        } while (best_before_finals[i] < 9.50 || best_before_finals[i] > 10.50);

        do {
            printf("Δώσε τον χρόνο στον τελικό για τον αθλητή: %d\n", i + 1);
            scanf("%lf", &timing_final[i]);
            if (timing_final[i] < 9.50 || timing_final[i] > 10.50) {
                printf("Ο χρόνος πρέπει να είναι μεταξύ 9.50 και 10.50 δευτερολέπτων\n");
            }
        } while (timing_final[i] < 9.50 || timing_final[i] > 10.50);
    }

    // Β.2 Υπολογισμός χειρότερου και καλύτερου χρόνου πριν απο Ολυμπιακούς Αγώνες
    for (int i = 0; i < athletes; i++) {
        if (best_before_finals[i] > max) {
            max = best_before_finals[i];
        }
        if (best_before_finals[i] < min) {
            min = best_before_finals[i];
        }
    }

    // Β.3 Υπολογισμός του πλήθους των αθλητών με χρόνο κάτω από 9.80
    for (int i = 0; i < athletes; i++) {
        if (timing_final[i] < 9.80) {
            count_below_9_80++;
        }
    }

    // Β.4 Υπολογισμός αθλητή με τη μεγαλύτερη βελτίωση
    for (int i = 0; i < athletes; i++) {
        improvement = best_before_finals[i] - timing_final[i];
        if (improvement > greater_improvement) {
            greater_improvement = improvement;
            best_athlete = i + 1;
        }
    }

    // Εμφάνιση τελικών αποτελεσμάτων
    printf("Ο χειρότερος χρόνος πριν τους Ολυμπιακούς Αγώνες είναι: %.2lf\n", max);
    printf("Ο καλύτερος χρόνος πριν τους Ολυμπιακούς Αγώνες είναι: %.2lf\n", min);

    if (count_below_9_80 > 0) {
        printf("Το πλήθος των αθλητών που είχαν χρόνο κάτω από 9.80 στον τελικό: %d\n", count_below_9_80);
    } else {
        printf("Κανένας αθλητής δεν είχε χρόνο κάτω από 9.80 στον τελικό.\n");
    }

    if (best_athlete > 0) {
        printf("Η μεγαλύτερη βελτίωση σημειώθηκε από τον αθλητή %d και ήταν %.2lf δευτερόλεπτα\n", best_athlete, greater_improvement);
    } else {
        printf("Κανένας αθλητής δεν βελτιώθηκε.\n");
    }

    return 0;
}
