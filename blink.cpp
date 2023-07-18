#include <iostream>
#include <gpiod.h>
#include <unistd.h>


int main() {
const char *chipname = "gpiochip0";
struct gpiod_chip *chip;
struct gpiod_line *led;

chip = gpiod_chip_open_by_name(chipname);

led = gpiod_chip_get_line(chip, 23);
gpiod_line_request_output(led, "blink", 0);

int i = 0;
while(true) {
    gpiod_line_set_value(led, i%2);
    usleep(100000);
    i++;
}

return 0;
}