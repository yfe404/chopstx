#define PERIPH_BASE	0x40000000
#define APBPERIPH_BASE  PERIPH_BASE
#define APB2PERIPH_BASE	(PERIPH_BASE + 0x10000)
#define AHBPERIPH_BASE	(PERIPH_BASE + 0x20000)
#define AHB2PERIPH_BASE	(PERIPH_BASE + 0x08000000)

struct RCC {
  volatile uint32_t CR;
  volatile uint32_t CFGR;
  volatile uint32_t CIR;
  volatile uint32_t APB2RSTR;
  volatile uint32_t APB1RSTR;
  volatile uint32_t AHBENR;
  volatile uint32_t APB2ENR;
  volatile uint32_t APB1ENR;
  volatile uint32_t BDCR;
  volatile uint32_t CSR;
#if defined(MCU_STM32F0)
  volatile uint32_t AHBRSTR;
  volatile uint32_t CFGR2;
  volatile uint32_t CFGR3;
  volatile uint32_t CR2;
#endif
};

#define RCC_BASE		(AHBPERIPH_BASE + 0x1000)
static struct RCC *const RCC = (struct RCC *)RCC_BASE;

#define RCC_APB1ENR_USBEN	0x00800000
#define RCC_APB1RSTR_USBRST	0x00800000

#define RCC_CR_HSION		0x00000001
#define RCC_CR_HSIRDY		0x00000002
#define RCC_CR_HSITRIM		0x000000F8
#define RCC_CR_HSEON		0x00010000
#define RCC_CR_HSERDY		0x00020000
#define RCC_CR_PLLON		0x01000000
#define RCC_CR_PLLRDY		0x02000000

#define RCC_CFGR_SWS		0x0000000C
#define RCC_CFGR_SWS_HSI	0x00000000

#define RCC_AHBENR_DMA1EN       0x00000001
#define RCC_AHBENR_CRCEN        0x00000040

#if defined(MCU_STM32F0)
#define RCC_AHBRSTR_IOPARST	0x00020000
#define RCC_AHBRSTR_IOPBRST	0x00040000
#define RCC_AHBRSTR_IOPCRST	0x00080000
#define RCC_AHBRSTR_IOPDRST	0x00100000
#define RCC_AHBRSTR_IOPFRST	0x00400000

#define RCC_AHBENR_IOPAEN	0x00020000
#define RCC_AHBENR_IOPBEN	0x00040000
#define RCC_AHBENR_IOPCEN	0x00080000
#define RCC_AHBENR_IOPDEN	0x00100000
#define RCC_AHBENR_IOPFEN	0x00400000

#define RCC_APB2RSTR_SYSCFGRST	0x00000001
#define RCC_APB2ENR_SYSCFGEN	0x00000001
#else
#define RCC_APB2ENR_ADC1EN      0x00000200
#define RCC_APB2ENR_ADC2EN      0x00000400
#define RCC_APB2ENR_TIM1EN      0x00000800
#define RCC_APB1ENR_TIM2EN      0x00000001
#define RCC_APB1ENR_TIM3EN      0x00000002
#define RCC_APB1ENR_TIM4EN      0x00000004

#define RCC_APB2RSTR_ADC1RST    0x00000200
#define RCC_APB2RSTR_ADC2RST    0x00000400
#define RCC_APB2RSTR_TIM1RST    0x00000800
#define RCC_APB1RSTR_TIM2RST    0x00000001
#define RCC_APB1RSTR_TIM3RST    0x00000002
#define RCC_APB1RSTR_TIM4RST    0x00000004

#define RCC_APB2RSTR_AFIORST	0x00000001
#define RCC_APB2RSTR_IOPARST	0x00000004
#define RCC_APB2RSTR_IOPBRST	0x00000008
#define RCC_APB2RSTR_IOPCRST	0x00000010
#define RCC_APB2RSTR_IOPDRST	0x00000020
#define RCC_APB2RSTR_IOPERST	0x00000040
#define RCC_APB2RSTR_IOPFRST	0x00000080
#define RCC_APB2RSTR_IOPGRST	0x00000100

#define RCC_APB2ENR_AFIOEN	0x00000001
#define RCC_APB2ENR_IOPAEN	0x00000004
#define RCC_APB2ENR_IOPBEN	0x00000008
#define RCC_APB2ENR_IOPCEN	0x00000010
#define RCC_APB2ENR_IOPDEN	0x00000020
#define RCC_APB2ENR_IOPEEN	0x00000040
#define RCC_APB2ENR_IOPFEN	0x00000080
#define RCC_APB2ENR_IOPGEN	0x00000100
#endif

#define RCC_CFGR_SW_HCI		(0 << 0)
#define RCC_CFGR_SW_PLL		(2 << 0)
#define RCC_CFGR_SW_MASK	(3 << 0)
#define RCC_CFGR_SWS		0x0000000C


struct PWR
{
  volatile uint32_t CR;
  volatile uint32_t CSR;
};
static struct PWR *const PWR = ((struct PWR *)0x40007000);
#define PWR_CR_LPDS 0x0001	/* Low-power deepsleep  */
#define PWR_CR_PDDS 0x0002	/* Power down deepsleep */
#define PWR_CR_CWUF 0x0004	/* Clear wakeup flag    */
