#define BOARD_NAME "Turtle Auth"
/* echo -n "Turtle Auth" | shasum -a 256 | sed -e 's/^.*\(........\)  -$/\1/' */
#define BOARD_ID    0xcff5fffd

#define MCU_STM32F1 1
#define STM32F10X_MD		/* Medium-density device */

#define STM32_PLLXTPRE                  STM32_PLLXTPRE_DIV1
#define STM32_PLLMUL_VALUE              9
#define STM32_HSECLK                    8000000

#define GPIO_LED_BASE           GPIOC_BASE
#define GPIO_LED_SET_TO_EMIT      13
#define GPIO_USB_BASE           GPIOA_BASE
#define GPIO_OTHER_BASE         GPIOA_BASE
#define GPIO_BUTTON_PIN			  8

/*
 * Port A setup.
 * PA11 - Push Pull output 10MHz 0 default (until USB enabled) (USBDM)
 * PA12 - Push Pull output 10MHz 0 default (until USB enabled) (USBDP)
 *
 * Port C setup.
 * PC13 - Push pull output 50MHz (LED 1:ON 0:OFF)
 * ------------------------ Default
 * PAx  - input with pull-up
 * PCx  - input with pull-up
 */
#define VAL_GPIO_USB_ODR            0xFFFFE6FF
#define VAL_GPIO_USB_CRL            0x88888888      /*  PA7...PA0 */
#define VAL_GPIO_USB_CRH            0x88811888      /* PA15...PA8 */

#define VAL_GPIO_OTHER_ODR          VAL_GPIO_USB_ODR
#define VAL_GPIO_OTHER_ODR          VAL_GPIO_USB_CRL
#define VAL_GPIO_OTHER_ODR          VAL_GPIO_USB_CRH

#define VAL_GPIO_LED_ODR            0xFFFFFFFF
#define VAL_GPIO_LED_CRL            0x88888888      /*  PC7...PC0 */
#define VAL_GPIO_LED_CRH            0x88388888      /* PC15...PC8 */

#define RCC_ENR_IOP_EN      (RCC_APB2ENR_IOPAEN | RCC_APB2ENR_IOPCEN)
#define RCC_RSTR_IOP_RST    (RCC_APB2RSTR_IOPARST | RCC_APB2RSTR_IOPCRST)
