#if ARDUINO >= 100
 #include "Arduino.h"
#else
 #include "WProgram.h"
 #include "pins_arduino.h"
#endif
#include <Adafruit_GFX.h>

#ifdef CORE_TEENSY
	#define CLK 22
	#define LAT 21
	#define OE	20
	#define A   7
	#define B   8
	#define C   9
	#define D   23
	#define E   6
	
	#ifdef __IMXRT1062__ //Teensy 4.0

	#define B2_PIN 5
	#define G2_PIN 4
	#define R2_PIN 3
	#define B1_PIN 2
	#define G1_PIN 1
	#define R1_PIN 0
	
	#endif
#endif

class RGBmatrixPanel : public Adafruit_GFX {

 public:
#ifdef CORE_TEENSY
	 RGBmatrixPanel(boolean dbuf, uint16_t width = 64, uint16_t height = 64);
#else
  // Constructor for 16x32 panel:
  RGBmatrixPanel(uint8_t a, uint8_t b, uint8_t c,
    uint8_t sclk, uint8_t latch, uint8_t oe, boolean dbuf);

  // Constructor for 32x32 panel (adds 'd' pin):
  RGBmatrixPanel(uint8_t a, uint8_t b, uint8_t c, uint8_t d,
    uint8_t sclk, uint8_t latch, uint8_t oe, boolean dbuf, uint8_t width=32);
#endif

void Write_REG1(uint16_t REG_DATA);
void Write_REG2(uint16_t REG_DATA);
void FM6126_Init(void);

  void
    begin(void),
    drawPixel(int16_t x, int16_t y, uint16_t c),
    fillScreen(uint16_t c),
    updateDisplay(void),
    swapBuffers(boolean),
    dumpMatrix(void);
  uint8_t
    *backBuffer(void);
  uint16_t
    Color333(uint8_t r, uint8_t g, uint8_t b),
    Color444(uint8_t r, uint8_t g, uint8_t b),
    Color888(uint8_t r, uint8_t g, uint8_t b),
    Color888(uint8_t r, uint8_t g, uint8_t b, boolean gflag),
    ColorHSV(long hue, uint8_t sat, uint8_t val, boolean gflag);

 private:

  uint8_t         *matrixbuff[2];
  uint16_t          nRows;
  volatile uint8_t backindex;
  volatile boolean swapflag;

#ifdef CORE_TEENSY
  IntervalTimer drawTimer;

  // Init/alloc code common to both constructors:
  void init(uint16_t rows, boolean dbuf, uint16_t width);

#else
  // Init/alloc code common to both constructors:
  void init(uint8_t rows, uint8_t a, uint8_t b, uint8_t c,
	  uint8_t sclk, uint8_t latch, uint8_t oe, boolean dbuf,
	  uint8_t width);

  // PORT register pointers, pin bitmasks, pin numbers:
  volatile uint8_t
    *latport, *oeport, *addraport, *addrbport, *addrcport, *addrdport;

  uint8_t
	  sclkpin, latpin, oepin, addrapin, addrbpin, addrcpin, addrdpin,
	  _sclk, _latch, _oe, _a, _b, _c, _d;
#endif

  // Counters/pointers for interrupt handler:
  volatile uint8_t row, plane;
  volatile uint8_t *buffptr;
};

