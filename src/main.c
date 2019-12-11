#include <zephyr.h>
#include <device.h>
#include <drivers/pwm.h>
#include <sys/printk.h>

#define PWM_DEV     DT_ALIAS_LED1_PWMS_CONTROLLER
#define PWM_CH      DT_ALIAS_LED1_PWMS_CHANNEL

#define SLEEP_MS    10
#define PERIOD_US   1000

void main(void)
{
    int width;
    struct device *dev;

    printk("My first app for Zephyr\n");

    if ((dev = device_get_binding(PWM_DEV)) == NULL)
        printk("Failed to find device binding.\n");

    width = 0;

    for (;;) {
        pwm_pin_set_usec(dev, PWM_CH, PERIOD_US, width);

        width += 100;
        if (width > PERIOD_US)
            width = 0;

        k_sleep(SLEEP_MS);
    }
}
