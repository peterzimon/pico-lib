#ifndef _PICO_LIB_UTILS_H
#define _PICO_LIB_UTILS_H

#include <inttypes.h>
#include <pico/stdlib.h>

class Utils
{
    public:
        static inline long map(long x, long in_min, long in_max, long out_min, long out_max) {
            return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
        }

        static inline float lerp(uint16_t a, uint16_t b, float ratio) {
            return (a + ((b - a) * ratio));
        }

        static inline uint16_t adcGetSampleAvgNDeleteX(uint8_t n, uint8_t x, uint16_t *samples) {
            uint32_t avgSample = 0x00;
            
            sortTab(samples, n);
            for (int i = x / 2; i < n - x / 2; i++) {
                avgSample += samples[i];
            }

            avgSample /= (n - x);
            return avgSample;
        }

        static inline void sortTab(uint16_t tab[], uint8_t length) {
            uint8_t l = 0x00, exchange = 0x01;
            uint16_t tmp = 0x00;

            while (exchange == 1) {
                exchange = 0;
                for (l = 0; l < length - 1; l++) {
                    if (tab[l] > tab[l + 1]) {
                        tmp = tab[l];
                        tab[l] = tab[l + 1];
                        tab[l + 1] = tmp;
                        exchange = 1;
                    }
                }
            }
        }
};

#endif