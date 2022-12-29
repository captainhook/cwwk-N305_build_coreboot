/* SPDX-License-Identifier: GPL-2.0-only */

#ifndef __SOC_MEDIATEK_MT8195_DRAMC_SOC_H__
#define __SOC_MEDIATEK_MT8195_DRAMC_SOC_H__

#include <soc/dramc_soc_common.h>

typedef enum {
	CHANNEL_A = 0,
	CHANNEL_B,
	CHANNEL_C,
	CHANNEL_D,
	CHANNEL_MAX,
} DRAM_CHANNEL_T;

typedef enum {
	RANK_0 = 0,
	RANK_1,
	RANK_MAX,
} DRAM_RANK_T;

/* DRAM SHUFFLE register type */
typedef enum {
	DRAM_DFS_SHUFFLE_1 = 0,
	DRAM_DFS_SHUFFLE_2,
	DRAM_DFS_SHUFFLE_3,
	DRAM_DFS_SHUFFLE_4,
	DRAM_DFS_SHUFFLE_5,
	DRAM_DFS_SHUFFLE_6,
	DRAM_DFS_SHUFFLE_7,
	DRAM_DFS_SHUFFLE_MAX,
} DRAM_DFS_SHUFFLE_TYPE_T;

#define DRAM_DFS_SHU_MAX	DRAM_DFS_SHUFFLE_MAX

#endif	/* __SOC_MEDIATEK_MT8195_DRAMC_SOC_H__ */
