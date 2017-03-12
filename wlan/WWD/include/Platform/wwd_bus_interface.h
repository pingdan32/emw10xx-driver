/*
 * Copyright 2013, Broadcom Corporation
 * All Rights Reserved.
 *
 * This is UNPUBLISHED PROPRIETARY SOURCE CODE of Broadcom Corporation;
 * the contents of this file may not be disclosed to third parties, copied
 * or duplicated in any form, in whole or in part, without the prior
 * written permission of Broadcom Corporation.
 */

/** @file
 *  Defines the Bus part of the WICED Platform Interface.
 *
 *  Provides prototypes for functions that allow WICED to start and stop
 *  the hardware communications bus for a platform.
 */

#ifndef INCLUDED_WWD_BUS_INTERFACE_H_
#define INCLUDED_WWD_BUS_INTERFACE_H_

#include "wiced_utilities.h"  /* for wiced_result_t */
#include "Network/wwd_buffer_interface.h"

#ifdef __cplusplus
extern "C"
{
#endif

/** @addtogroup platif Platform Interface
 *  @{
 */

/** @name Bus Functions
 *  Functions that enable WICED to start and stop
 *  the hardware communications bus for a paritcular platform.
 */
/**@{*/

/******************************************************
 *             Function declarations
 ******************************************************/

/**
 * Initializes the WICED Bus
 *
 * Implemented in the WICED Platform interface which is specific to the
 * platform in use.
 * This function should set the bus GPIO pins to the correct modes,  set up
 * the interrupts for the WICED bus, enable power and clocks to the bus, and
 * set up the bus peripheral.
 *
 * @return WICED_SUCCESS or WICED_ERROR
 */
extern wiced_result_t host_platform_bus_init( void );

/**
 * De-Initializes the WICED Bus
 *
 * Implemented in the WICED Platform interface which is specific to the
 * platform in use.
 * This function does the reverse of @ref host_platform_bus_init
 *
 * @return WICED_SUCCESS or WICED_ERROR
 */
extern wiced_result_t host_platform_bus_deinit( void );


/**
 * Informs WICED of an interrupt
 *
 * This function should be called from the SDIO/SPI interrupt function
 * and usually indicates newly received data is available.
 * It wakes the WICED Thread, forcing it to check the send/receive
 *
 */
extern void wiced_platform_notify_irq( void );

/**
 * Enables the bus interrupt
 *
 * This function is called by WICED during init, once
 * the system is ready to receive interrupts
 */
extern wwd_result_t host_platform_bus_enable_interrupt( void );

/**
 * Disables the bus interrupt
 *
 * This function is called by WICED during de-init, to stop
 * the system supplying any more interrupts in preparation
 * for shutdown
 */
extern wwd_result_t host_platform_bus_disable_interrupt( void );


/**
 * Informs the platform bus implementation that a buffer has been freed
 *
 * This function is called by WICED during buffer release to allow
 * the platform to reuse the released buffer - especially where
 * a DMA chain needs to be refilled.
 */
extern void host_platform_bus_buffer_freed( wiced_buffer_dir_t direction );

/** @} */
/** @} */

#ifdef __cplusplus
} /* extern "C" */
#endif

#endif /* ifndef INCLUDED_WWD_BUS_INTERFACE_H_ */
