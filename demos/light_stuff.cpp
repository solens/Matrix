#include <unistd.h>
#include <iostream>

#include "../cpp/driver/everloop.h"
#include "../cpp/driver/everloop_image.h"
#include "../cpp/driver/wishbone_bus.h"

namespace hal = matrix_hal;

int main() {
  hal::WishboneBus bus;

  bus.SpiInit();

  hal::Everloop everloop;
  hal::EverloopImage image1d;

  everloop.Setup(&bus);

  unsigned counter = 0;

  int colors[18][3] = {
    {255,0,0},
    {255,15,0},
    {255,100,0},
    {255,255,0},
    {192,255,0},
    {96,255,0},
    {0,255,0},
    {0,255,96},
    {0,255,192},
    {0,255,255},
    {0,120,255},
    {0,30,255},
    {0,0,255},
    {30,0,255},
    {120,0,255},
    {255,0,255},
    {255,0,100},
    {255,0,15}
  };

  while (1) {
    for (hal::LedValue& led : image1d.leds) {
      led.red = 0;
      led.green = 0;
      led.blue = 0;
      led.white = 0;
    }

    for (int led_num = 0; led_num < 18; ++led_num){
      image1d.leds[led_num].red = colors[(led_num + counter) % 18][0] / 10;
      image1d.leds[led_num].green = colors[(led_num + counter) % 18][1] / 10;
      image1d.leds[led_num].blue = colors[(led_num + counter) % 18][2] / 10;
      image1d.leds[led_num].white = 0;
    }
    
    

    everloop.Write(&image1d);
    ++counter;
    usleep(200000);
  }

  return 0;
}

