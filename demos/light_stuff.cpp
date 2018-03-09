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

  while (1) {
    for (hal::LedValue& led : image1d.leds) {
      led.red = 0;
      led.green = 0;
      led.blue = 0;
      led.white = 0;
    }
    image1d.leds[counter % 35].white = 10;

    everloop.Write(&image1d);
    ++counter;
    usleep(20000);
  }

  return 0;
}

