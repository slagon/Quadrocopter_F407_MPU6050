/*
    ChibiOS/RT - Copyright (C) 2006,2007,2008,2009,2010,
                 2011,2012 Giovanni Di Sirio.

    This file is part of ChibiOS/RT.

    ChibiOS/RT is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 3 of the License, or
    (at your option) any later version.

    ChibiOS/RT is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

                                      ---

    A special exception to the GPL can be applied should you wish to distribute
    a combined work that includes ChibiOS/RT, without being obliged to provide
    the source code for any proprietary components. See the file exception.txt
    for full details of how and when the exception can be applied.
*/

/**
 * @file    STM32F1xx/stm32_rcc.h
 * @brief   RCC helper driver header.
 * @note    This file requires definitions from the ST header file
 *          @p stm32f10x.h.
 *
 * @addtogroup STM32F1xx_RCC
 * @{
 */

#ifndef _STM32_RCC_
#define _STM32_RCC_

/*===========================================================================*/
/* Driver constants.                                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver pre-compile time settings.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Derived constants and error checks.                                       */
/*===========================================================================*/

/*===========================================================================*/
/* Driver data structures and types.                                         */
/*===========================================================================*/

/*===========================================================================*/
/* Driver macros.                                                            */
/*===========================================================================*/

/**
 * @name    Generic RCC operations
 * @{
 */
/**
 * @brief   Enables the clock of one or more peripheral on the APB1 bus.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] mask      APB1 peripherals mask
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableAPB1(mask, lp) {                                           \
  RCC->APB1ENR |= (mask);                                                   \
}

/**
 * @brief   Disables the clock of one or more peripheral on the APB1 bus.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] mask      APB1 peripherals mask
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableAPB1(mask, lp) {                                          \
  RCC->APB1ENR &= ~(mask);                                                  \
}

/**
 * @brief   Resets one or more peripheral on the APB1 bus.
 *
 * @param[in] mask      APB1 peripherals mask
 *
 * @api
 */
#define rccResetAPB1(mask) {                                                \
  RCC->APB1RSTR |= (mask);                                                  \
  RCC->APB1RSTR = 0;                                                        \
}

/**
 * @brief   Enables the clock of one or more peripheral on the APB2 bus.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] mask      APB2 peripherals mask
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableAPB2(mask, lp) {                                           \
  RCC->APB2ENR |= (mask);                                                   \
}

/**
 * @brief   Disables the clock of one or more peripheral on the APB2 bus.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] mask      APB2 peripherals mask
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableAPB2(mask, lp) {                                          \
  RCC->APB2ENR &= ~(mask);                                                  \
}

/**
 * @brief   Resets one or more peripheral on the APB2 bus.
 *
 * @param[in] mask      APB2 peripherals mask
 *
 * @api
 */
#define rccResetAPB2(mask) {                                                \
  RCC->APB2RSTR |= (mask);                                                  \
  RCC->APB2RSTR = 0;                                                        \
}

/**
 * @brief   Enables the clock of one or more peripheral on the AHB bus.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] mask      AHB peripherals mask
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableAHB(mask, lp) {                                            \
  RCC->AHBENR |= (mask);                                                    \
}

/**
 * @brief   Disables the clock of one or more peripheral on the AHB bus.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] mask      AHB peripherals mask
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableAHB(mask, lp) {                                           \
  RCC->AHBENR &= ~(mask);                                                   \
}

/**
 * @brief   Resets one or more peripheral on the AHB bus.
 *
 * @param[in] mask      AHB peripherals mask
 *
 * @api
 */
#define rccResetAHB(mask) {                                                 \
  RCC->AHBRSTR |= (mask);                                                   \
  RCC->AHBRSTR = 0;                                                         \
}
/** @} */

/**
 * @name    ADC peripherals specific RCC operations
 * @{
 */
/**
 * @brief   Enables the ADC1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableADC1(lp) rccEnableAPB2(RCC_APB2ENR_ADC1EN, lp)

/**
 * @brief   Disables the ADC1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableADC1(lp) rccDisableAPB2(RCC_APB2ENR_ADC1EN, lp)

/**
 * @brief   Resets the ADC1 peripheral.
 *
 * @api
 */
#define rccResetADC1() rccResetAPB2(RCC_APB2RSTR_ADC1RST)
/** @} */

/**
 * @name    Backup domain interface specific RCC operations
 * @{
 */
/**
 * @brief   Enables the BKP interface clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableBKPInterface(lp) rccEnableAPB1((RCC_APB1ENR_BKPEN), lp)

/**
 * @brief   Disables BKP interface clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableBKPInterface(lp) rccDisableAPB1((RCC_APB1ENR_BKPEN), lp)

/**
 * @brief   Resets the Backup Domain interface.
 *
 * @api
 */
#define rccResetBKPInterface() rccResetAPB1(RCC_APB1ENR_BKPRST)

/**
 * @brief   Resets the entire Backup Domain.
 *
 * @api
 */
#define rccResetBKP() (RCC->BDCR |= RCC_BDCR_BDRST)
/** @} */

/**
 * @name    PWR interface specific RCC operations
 * @{
 */
/**
 * @brief   Enables the PWR interface clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnablePWRInterface(lp) rccEnableAPB1(RCC_APB1ENR_PWREN, lp)

/**
 * @brief   Disables PWR interface clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisablePWRInterface(lp) rccDisableAPB1(RCC_APB1ENR_PWREN, lp)

/**
 * @brief   Resets the PWR interface.
 *
 * @api
 */
#define rccResetPWRInterface() rccResetAPB1(RCC_APB1RSTR_PWRRST)
/** @} */

/**
 * @name    CAN peripherals specific RCC operations
 * @{
 */
/**
 * @brief   Enables the CAN1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableCAN1(lp) rccEnableAPB1(RCC_APB1ENR_CAN1EN, lp)

/**
 * @brief   Disables the CAN1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableCAN1(lp) rccDisableAPB1(RCC_APB1ENR_CAN1EN, lp)

/**
 * @brief   Resets the CAN1 peripheral.
 *
 * @api
 */
#define rccResetCAN1() rccResetAPB1(RCC_APB1RSTR_CAN1RST)
/** @} */

/**
 * @name    DMA peripherals specific RCC operations
 * @{
 */
/**
 * @brief   Enables the DMA1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableDMA1(lp) rccEnableAHB(RCC_AHBENR_DMA1EN, lp)

/**
 * @brief   Disables the DMA1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableDMA1(lp) rccDisableAHB(RCC_AHBENR_DMA1EN, lp)

/**
 * @brief   Resets the DMA1 peripheral.
 * @note    Not supported in this family, does nothing.
 *
 * @api
 */
#define rccResetDMA1()

/**
 * @brief   Enables the DMA2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableDMA2(lp) rccEnableAHB(RCC_AHBENR_DMA2EN, lp)

/**
 * @brief   Disables the DMA2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableDMA2(lp) rccDisableAHB(RCC_AHBENR_DMA2EN, lp)

/**
 * @brief   Resets the DMA1 peripheral.
 * @note    Not supported in this family, does nothing.
 *
 * @api
 */
#define rccResetDMA2()
/** @} */

/**
 * @name    ETH peripheral specific RCC operations
 * @{
 */
/**
 * @brief   Enables the ETH peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableETH(lp) rccEnableAHB(RCC_AHBENR_ETHMACEN |                 \
                                      RCC_AHBENR_ETHMACTXEN |               \
                                      RCC_AHBENR_ETHMACRXEN, lp)

/**
 * @brief   Disables the ETH peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableETH(lp) rccDisableAHB(RCC_AHBENR_ETHMACEN |               \
                                        RCC_AHBENR_ETHMACTXEN |             \
                                        RCC_AHBENR_ETHMACRXEN, lp)

/**
 * @brief   Resets the ETH peripheral.
 *
 * @api
 */
#define rccResetETH() rccResetAHB(RCC_AHBRSTR_ETHMACRST)
/** @} */

/**
 * @name    I2C peripherals specific RCC operations
 * @{
 */
/**
 * @brief   Enables the I2C1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableI2C1(lp) rccEnableAPB1(RCC_APB1ENR_I2C1EN, lp)

/**
 * @brief   Disables the I2C1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableI2C1(lp) rccDisableAPB1(RCC_APB1ENR_I2C1EN, lp)

/**
 * @brief   Resets the I2C1 peripheral.
 *
 * @api
 */
#define rccResetI2C1() rccResetAPB1(RCC_APB1RSTR_I2C1RST)

/**
 * @brief   Enables the I2C2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableI2C2(lp) rccEnableAPB1(RCC_APB1ENR_I2C2EN, lp)

/**
 * @brief   Disables the I2C2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableI2C2(lp) rccDisableAPB1(RCC_APB1ENR_I2C2EN, lp)

/**
 * @brief   Resets the I2C2 peripheral.
 *
 * @api
 */
#define rccResetI2C2() rccResetAPB1(RCC_APB1RSTR_I2C2RST)
/** @} */

/**
 * @name    SDIO peripheral specific RCC operations
 * @{
 */
/**
 * @brief   Enables the SDIO peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableSDIO(lp) rccEnableAHB(RCC_AHBENR_SDIOEN, lp)

/**
 * @brief   Disables the SDIO peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableSDIO(lp) rccDisableAHB(RCC_AHBENR_SDIOEN, lp)

/**
 * @brief   Resets the SDIO peripheral.
 * @note    Not supported in this family, does nothing.
 *
 * @api
 */
#define rccResetSDIO()
/** @} */

/**
 * @name    SPI peripherals specific RCC operations
 * @{
 */
/**
 * @brief   Enables the SPI1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableSPI1(lp) rccEnableAPB2(RCC_APB2ENR_SPI1EN, lp)

/**
 * @brief   Disables the SPI1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableSPI1(lp) rccDisableAPB2(RCC_APB2ENR_SPI1EN, lp)

/**
 * @brief   Resets the SPI1 peripheral.
 *
 * @api
 */
#define rccResetSPI1() rccResetAPB2(RCC_APB2RSTR_SPI1RST)

/**
 * @brief   Enables the SPI2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableSPI2(lp) rccEnableAPB1(RCC_APB1ENR_SPI2EN, lp)

/**
 * @brief   Disables the SPI2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableSPI2(lp) rccDisableAPB1(RCC_APB1ENR_SPI2EN, lp)

/**
 * @brief   Resets the SPI2 peripheral.
 *
 * @api
 */
#define rccResetSPI2() rccResetAPB1(RCC_APB1RSTR_SPI2RST)

/**
 * @brief   Enables the SPI3 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableSPI3(lp) rccEnableAPB1(RCC_APB1ENR_SPI3EN, lp)

/**
 * @brief   Disables the SPI3 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableSPI3(lp) rccDisableAPB1(RCC_APB1ENR_SPI3EN, lp)

/**
 * @brief   Resets the SPI3 peripheral.
 *
 * @api
 */
#define rccResetSPI3() rccResetAPB1(RCC_APB1RSTR_SPI3RST)
/** @} */

/**
 * @name    TIM peripherals specific RCC operations
 * @{
 */
/**
 * @brief   Enables the TIM1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableTIM1(lp) rccEnableAPB2(RCC_APB2ENR_TIM1EN, lp)

/**
 * @brief   Disables the TIM1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableTIM1(lp) rccDisableAPB2(RCC_APB2ENR_TIM1EN, lp)

/**
 * @brief   Resets the TIM1 peripheral.
 *
 * @api
 */
#define rccResetTIM1() rccResetAPB2(RCC_APB2RSTR_TIM1RST)

/**
 * @brief   Enables the TIM2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableTIM2(lp) rccEnableAPB1(RCC_APB1ENR_TIM2EN, lp)

/**
 * @brief   Disables the TIM2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableTIM2(lp) rccDisableAPB1(RCC_APB1ENR_TIM2EN, lp)

/**
 * @brief   Resets the TIM2 peripheral.
 *
 * @api
 */
#define rccResetTIM2() rccResetAPB1(RCC_APB1RSTR_TIM2RST)

/**
 * @brief   Enables the TIM3 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableTIM3(lp) rccEnableAPB1(RCC_APB1ENR_TIM3EN, lp)

/**
 * @brief   Disables the TIM3 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableTIM3(lp) rccDisableAPB1(RCC_APB1ENR_TIM3EN, lp)

/**
 * @brief   Resets the TIM3 peripheral.
 *
 * @api
 */
#define rccResetTIM3() rccResetAPB1(RCC_APB1RSTR_TIM3RST)

/**
 * @brief   Enables the TIM4 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableTIM4(lp) rccEnableAPB1(RCC_APB1ENR_TIM4EN, lp)

/**
 * @brief   Disables the TIM4 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableTIM4(lp) rccDisableAPB1(RCC_APB1ENR_TIM4EN, lp)

/**
 * @brief   Resets the TIM4 peripheral.
 *
 * @api
 */
#define rccResetTIM4() rccResetAPB1(RCC_APB1RSTR_TIM4RST)

/**
 * @brief   Enables the TIM5 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableTIM5(lp) rccEnableAPB1(RCC_APB1ENR_TIM5EN, lp)

/**
 * @brief   Disables the TIM5 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableTIM5(lp) rccDisableAPB1(RCC_APB1ENR_TIM5EN, lp)

/**
 * @brief   Resets the TIM5 peripheral.
 *
 * @api
 */
#define rccResetTIM5() rccResetAPB1(RCC_APB1RSTR_TIM5RST)

/**
 * @brief   Enables the TIM8 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableTIM8(lp) rccEnableAPB2(RCC_APB2ENR_TIM8EN, lp)

/**
 * @brief   Disables the TIM8 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableTIM8(lp) rccDisableAPB2(RCC_APB2ENR_TIM8EN, lp)

/**
 * @brief   Resets the TIM8 peripheral.
 *
 * @api
 */
#define rccResetTIM8() rccResetAPB2(RCC_APB2RSTR_TIM8RST)
/** @} */

/**
 * @name    USART/UART peripherals specific RCC operations
 * @{
 */
/**
 * @brief   Enables the USART1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableUSART1(lp) rccEnableAPB2(RCC_APB2ENR_USART1EN, lp)

/**
 * @brief   Disables the USART1 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableUSART1(lp) rccDisableAPB2(RCC_APB2ENR_USART1EN, lp)

/**
 * @brief   Resets the USART1 peripheral.
 *
 * @api
 */
#define rccResetUSART1() rccResetAPB2(RCC_APB2RSTR_USART1RST)

/**
 * @brief   Enables the USART2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableUSART2(lp) rccEnableAPB1(RCC_APB1ENR_USART2EN, lp)

/**
 * @brief   Disables the USART2 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableUSART2(lp) rccDisableAPB1(RCC_APB1ENR_USART2EN, lp)

/**
 * @brief   Resets the USART2 peripheral.
 *
 * @api
 */
#define rccResetUSART2() rccResetAPB1(RCC_APB1RSTR_USART2RST)

/**
 * @brief   Enables the USART3 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableUSART3(lp) rccEnableAPB1(RCC_APB1ENR_USART3EN, lp)

/**
 * @brief   Disables the USART3 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableUSART3(lp) rccDisableAPB1(RCC_APB1ENR_USART3EN, lp)

/**
 * @brief   Resets the USART3 peripheral.
 *
 * @api
 */
#define rccResetUSART3() rccResetAPB1(RCC_APB1RSTR_USART3RST)

/**
 * @brief   Enables the UART4 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableUART4(lp) rccEnableAPB1(RCC_APB1ENR_UART4EN, lp)

/**
 * @brief   Disables the UART4 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableUART4(lp) rccDisableAPB1(RCC_APB1ENR_UART4EN, lp)

/**
 * @brief   Resets the UART4 peripheral.
 *
 * @api
 */
#define rccResetUART4() rccResetAPB1(RCC_APB1RSTR_UART4RST)

/**
 * @brief   Enables the UART5 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableUART5(lp) rccEnableAPB1(RCC_APB1ENR_UART5EN, lp)

/**
 * @brief   Disables the UART5 peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableUART5(lp) rccDisableAPB1(RCC_APB1ENR_UART5EN, lp)

/**
 * @brief   Resets the UART5 peripheral.
 *
 * @api
 */
#define rccResetUART5() rccResetAPB1(RCC_APB1RSTR_UART5RST)
/** @} */

/**
 * @name    USB peripheral specific RCC operations
 * @{
 */
/**
 * @brief   Enables the USB peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccEnableUSB(lp) rccEnableAPB1(RCC_APB1ENR_USBEN, lp)

/**
 * @brief   Disables the USB peripheral clock.
 * @note    The @p lp parameter is ignored in this family.
 *
 * @param[in] lp        low power enable flag
 *
 * @api
 */
#define rccDisableUSB(lp) rccDisableAPB1(RCC_APB1ENR_USBEN, lp)

/**
 * @brief   Resets the USB peripheral.
 *
 * @api
 */
#define rccResetUSB() rccResetAPB1(RCC_APB1RSTR_USBRST)
/** @} */

/*===========================================================================*/
/* External declarations.                                                    */
/*===========================================================================*/

#ifdef __cplusplus
extern "C" {
#endif
#ifdef __cplusplus
}
#endif

#endif /* _STM32_RCC_ */

/** @} */
