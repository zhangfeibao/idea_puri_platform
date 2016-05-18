#ifndef MACRO_DEFINE_H
#define MACRO_DEFINE_H

#define BIT0    (0x01)
#define BIT1    (0x02)
#define BIT2    (0x04)
#define BIT3    (0x08)
#define BIT4    (0x10)
#define BIT5    (0x20)
#define BIT6    (0x40)
#define BIT7    (0x80)

#define ABIT0   (~0x01)
#define ABIT1   (~0x02)
#define ABIT2   (~0x04)
#define ABIT3   (~0x08)
#define ABIT4   (~0x10)
#define ABIT5   (~0x20)
#define ABIT6   (~0x40)
#define ABIT7   (~0x80)

#define LENGTH_ARR(arr)     (sizeof(arr) / sizeof(arr[0]))

#define BIT_SET(_byte,n)    ((_byte) |= (0x01 << (n)))
#define BIT_CLR(_byte,n)    ((_byte) &= (~(0x01 << (n))))
#define BIT_TEST(_byte,n)   ((_byte) & (0x01 << (n)))
#define BIT_TOGGLE(_byte,n) ((_byte) ^= (0x01 << (n)))

#define B0(n)    (n * 0x01)
#define B1(n)    (n * 0x02)
#define B2(n)    (n * 0x04)
#define B3(n)    (n * 0x08)
#define B4(n)    (n * 0x10)
#define B5(n)    (n * 0x20)
#define B6(n)    (n * 0x40)
#define B7(n)    (n * 0x80)


#define BITS(a,b,c,d,e,f,g,h)   (B7(a) + B6(b) + B5(c) + B4(d) + \
    B3(e) + B2(f) + B1(g) + B0(h))


#define LONG_TO_BIN(n)  \
    (                     \
    ((n >> 21) & 0x80) |  \
    ((n >> 18) & 0x40) |  \
    ((n >> 15) & 0x20) |  \
    ((n >> 12) & 0x10) |  \
    ((n >>  9) & 0x08) |  \
    ((n >>  6) & 0x04) |  \
    ((n >>  3) & 0x02) |  \
    ((n      ) & 0x01)    \
    )

#define BIN(n)  LONG_TO_BIN(0x##n##l)


#endif

