/*
 * include/linux/tegra_camera.h
 *
 * Copyright (C) 2010 Google, Inc.
 *
 * This software is licensed under the terms of the GNU General Public
 * License version 2, as published by the Free Software Foundation, and
 * may be copied, distributed, and modified under those terms.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 */

enum {
	TEGRA_CAMERA_MODULE_ISP = 0,
	TEGRA_CAMERA_MODULE_VI,
	TEGRA_CAMERA_MODULE_CSI,
};

enum {
	TEGRA_CAMERA_VI_CLK,
	TEGRA_CAMERA_VI_SENSOR_CLK,
};

struct tegra_camera_clk_info {
	uint id;
	uint clk_id;
	unsigned long rate;
};

#ifdef CONFIG_MACH_N1
int tegra_camera_enable_vi(void);
int tegra_camera_disable_vi(void);
int tegra_camera_enable_csi(void);
int tegra_camera_disable_csi(void);
int tegra_camera_clk_set_rate(struct tegra_camera_clk_info *info);
#endif

#define TEGRA_CAMERA_IOCTL_ENABLE		_IOWR('i', 1, uint)
#define TEGRA_CAMERA_IOCTL_DISABLE		_IOWR('i', 2, uint)
#define TEGRA_CAMERA_IOCTL_CLK_SET_RATE		\
	_IOWR('i', 3, struct tegra_camera_clk_info)
#define TEGRA_CAMERA_IOCTL_RESET		_IOWR('i', 4, uint)

#ifdef CONFIG_TEGRA_DYNAMIC_CAMERA_CLK_RATE
#define CAMERA_USECASE_PREVIEW 0
#define CAMERA_USECASE_CAMERA_CAPTURE 1
#define CAMERA_USECASE_VIDEO_RECORD   2

typedef unsigned long* (*get_clock_freqs)(int, int, int, int);
struct tegra_camera_clk_config {
	char **clk_devs;
	char **clk_cons;
	char **clk_restore_devs;
	char **clk_restore_cons;
	int n_clks;
	int n_restore_clks;
	get_clock_freqs get_graphics_clk_freqs;
};
#define TEGRA_CAMERA_IOCTL_CAMERA_MODE _IOWR('i', 5, int[4])
#define TEGRA_CAMERA_IOCTL_CAMERA_USECASE _IOWR('i', 6, int[2])
#endif
