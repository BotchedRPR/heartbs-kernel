# SPDX-License-Identifier: GPL-2.0
dtb-y += exynos/s5e5515_p2_nocp.dtb
dtbo-y += samsung/exynos5515-heartbs_usa_open_00.dtbo
dtbo-y += samsung/exynos5515-heartbs_usa_open_01.dtbo
dtbo-y += samsung/exynos5515-heartbs_usa_open_04.dtbo
dtbo-y += samsung/exynos5515-heartbs_usa_open_05.dtbo
dtbo-y += samsung/exynos5515-heartbs_usa_open_06.dtbo
dtbo-y += samsung/exynos5515-heartbs_usa_open_08.dtbo
dtbo-y += samsung/exynos5515-heartbs_usa_open_10.dtbo

targets += dtbs
DTB_LIST  := $(dtb-y) $(dtbo-y)
always    := $(DTB_LIST)

dtbs: $(addprefix $(obj)/, $(DTB_LIST))

clean-files := *.dtb*
