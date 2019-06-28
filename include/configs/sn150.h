/* SPDX-License-Identifier: GPL-2.0+ */
/*
 * (C) Copyright 2019
 * Nabil Bendafi <nabil@bendafi.fr>
 *
 * Based on work by:
 * Marvell Semiconductor <www.marvell.com>
 * Written-by: Nabil Bendafi <nabil@bendafi.fr>
 */

#ifndef _CONFIG_SN150_H
#define _CONFIG_SN150_H

/*
 * High Level Configuration Options (easy to change)
 */
#define CONFIG_FEROCEON_88FR131	1	/* CPU Core subversion */
#define CONFIG_MACH_TYPE	MACH_TYPE_RD88F6281

/*
 * Commands configuration
 */

/*
 * mv-plug-common.h should be defined after CMD configs since it used them
 * to enable certain macros
 */
#include "mv-plug-common.h"

/*
 *  Environment variables configurations
 */
#ifdef CONFIG_SPI_FLASH
#define CONFIG_ENV_SECT_SIZE		0x10000	/* 64k */
#endif

#define CONFIG_ENV_SIZE			0x20000	/* 128k */
#define CONFIG_ENV_ADDR			0x60000
#define CONFIG_ENV_OFFSET		0x60000	/* env starts here */

/*
 * Environment is right behind U-Boot in flash. Make sure U-Boot
 * doesn't grow into the environment area.
 */
#define CONFIG_BOARD_SIZE_LIMIT		CONFIG_ENV_OFFSET

/*
 * Default environment variables
 */
#define CONFIG_BOOTCOMMAND \
	"mmc init;"								\
	"ext2load mmc 0:1 0x1c00000 /boot/dts/kirkwood-rd88f6281-a1.dtb ;"	\
	"ext2load mmc 0:1 0x1100000 /boot/uInitrd ;"				\
	"ext2load mmc 0:1 0x8000000 /boot/uImage ;"				\
	"bootm 0x800000 - 0x1c00000"

#define CONFIG_EXTRA_ENV_SETTINGS \
	"console=ttyS0,115200\0"	\
	"root=/dev/sda1 rootdelay=3\0"
/*
 * Ethernet Driver configuration
 */
#ifdef CONFIG_CMD_NET
#define CONFIG_MVGBE_PORTS	{1, 1}	/* enable both ports */
#define CONFIG_PHY_BASE_ADR	0
#endif /* CONFIG_CMD_NET */

/*
 * SDIO/MMC Card Configuration
 */
#ifdef CONFIG_CMD_MMC
#define CONFIG_MVEBU_MMC
#define CONFIG_SYS_MMC_BASE KW_SDIO_BASE
#endif /* CONFIG_CMD_MMC */

/*
 * SATA Driver configuration
 */
#ifdef CONFIG_IDE
#define __io
#define CONFIG_IDE_PREINIT
#define CONFIG_MVSATA_IDE_USE_PORT0
#define CONFIG_MVSATA_IDE_USE_PORT1
#define CONFIG_SYS_ATA_IDE0_OFFSET	MV_SATA_PORT0_OFFSET
#define CONFIG_SYS_ATA_IDE1_OFFSET	MV_SATA_PORT1_OFFSET
#endif /* CONFIG_IDE */

#endif /* _CONFIG_SN150_H */
