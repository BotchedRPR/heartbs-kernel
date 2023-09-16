/*
 * drivers/media/platform/exynos/mfc/mfc_regs.h
 *
 * Copyright (c) 2016 Samsung Electronics Co., Ltd.
 *		http://www.samsung.com/
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 */

#ifndef __MFC_REGS_H
#define __MFC_REGS_H __FILE__

#define MFC_MMU_INTERRUPT_STATUS				0x0060
#define MFC_MMU_FAULT_TRANS_INFO				0x0078
#define MFC_MMU_FAULT_TRANS_INFO_RW_MASK			0x100000
#define MFC_MMU_FAULT_TRANS_INFO_AXID_MASK			0xFFFF

/* Codec Common Registers */
#define MFC_REG_RISC_ON					0x0000
#define MFC_REG_RISC2HOST_INT					0x003C
#define MFC_REG_HOST2RISC_INT					0x0044
#define MFC_REG_RISC_BASE_ADDRESS				0x0054

#define MFC_REG_MFC_FW_CLOCK					0x1060
#define MFC_REG_MFC_RESET					0x1070

#define MFC_REG_HOST2RISC_CMD					0x1100
#define MFC_REG_RISC2HOST_CMD					0x1104

#define MFC_REG_MFC_BUS_STATUS					0x7018
#define MFC_REG_MFC_RPEND					0x7028
#define MFC_REG_MFC_WPEND					0x702C
#define MFC_REG_MFC_BUS_RESET_CTRL				0x7110
#define MFC_REG_MFC_OFF					0x7120
#define MFC_REG_MFC_STATE					0x7124

#define MFC_REG_FW_VERSION					0xF000
#define MFC_REG_INSTANCE_ID					0xF008
#define MFC_REG_CODEC_TYPE					0xF00C
#define MFC_REG_CONTEXT_MEM_ADDR				0xF014
#define MFC_REG_CONTEXT_MEM_SIZE				0xF018
#define MFC_REG_SHARED_MEM_ADDR				0xF01C
#define MFC_REG_PIXEL_FORMAT					0xF020

#define MFC_REG_METADATA_ENABLE				0xF024
#define MFC_REG_MFC_VERSION					0xF028
#define MFC_REG_DBG_INFO_ENABLE				0xF02C
#define MFC_REG_DBG_BUFFER_ADDR				0xF030
#define MFC_REG_DBG_BUFFER_SIZE				0xF034

#define MFC_REG_CODEC_CONTROL					0xF038
#define MFC_REG_TIMEOUT_VALUE					0xF03C
#define MFC_REG_HED_SHARED_MEM_ADDR				0xF040

/* NAL QUEUE */
#define MFC_REG_NAL_QUEUE_INPUT_ADDR				0xF044
#define MFC_REG_NAL_QUEUE_INPUT_SIZE				0xF048
#define MFC_REG_NAL_QUEUE_OUTPUT_ADDR				0xF04C
#define MFC_REG_NAL_QUEUE_OUTPUT_SIZE				0xF050
#define MFC_REG_NAL_QUEUE_INPUT_COUNT				0xF054

#define MFC_REG_RET_INSTANCE_ID				0xF070
#define MFC_REG_ERROR_CODE					0xF074
#define MFC_REG_DBG_BUFFER_OUTPUT_SIZE				0xF078
#define MFC_REG_METADATA_STATUS				0xF07C

#define MFC_REG_DBG_INFO_STAGE_COUNTER				0xF088

/* NAL QUEUE */
#define MFC_REG_NAL_QUEUE_OUTPUT_COUNT				0xF08C
#define MFC_REG_NAL_QUEUE_INPUT_EXE_COUNT			0xF090
#define MFC_REG_NAL_QUEUE_INFO					0xF094

#define MFC_REG_FIRMWARE_STATUS_INFO				0xF0A4

/* Decoder Registers */
#define MFC_REG_D_CRC_CTRL					0xF0B0
#define MFC_REG_D_DEC_OPTIONS					0xF0B4

#define MFC_REG_D_DISPLAY_DELAY				0xF0B8

#define MFC_REG_D_SET_FRAME_WIDTH				0xF0BC
#define MFC_REG_D_SET_FRAME_HEIGHT				0xF0C0

#define MFC_REG_D_SEI_ENABLE					0xF0C4

#define MFC_REG_D_FORCE_PIXEL_VAL				0xF0C8

/* Buffer setting registers */
/* Session return */
#define MFC_REG_D_MIN_NUM_DPB					0xF0F0
#define MFC_REG_D_MIN_FIRST_PLANE_DPB_SIZE			0xF0F4
#define MFC_REG_D_MIN_SECOND_PLANE_DPB_SIZE			0xF0F8
#define MFC_REG_D_MIN_THIRD_PLANE_DPB_SIZE			0xF0FC
#define MFC_REG_D_MIN_NUM_MV					0xF100
#define MFC_REG_D_MVC_NUM_VIEWS				0xF104
#define MFC_REG_D_MIN_SCRATCH_BUFFER_SIZE			0xF108
#define MFC_REG_D_MIN_FIRST_PLANE_2BIT_DPB_SIZE		0xF10C
#define MFC_REG_D_MIN_SECOND_PLANE_2BIT_DPB_SIZE		0xF110
#define MFC_REG_D_POST_FILTER_LUMA_DPB0			0xF120
#define MFC_REG_D_POST_FILTER_LUMA_DPB1			0xF124
#define MFC_REG_D_POST_FILTER_CHROMA_DPB0			0xF128
#define MFC_REG_D_POST_FILTER_CHROMA_DPB1			0xF12C

/* Buffers */
#define MFC_REG_D_NUM_DPB					0xF130
#define MFC_REG_D_NUM_MV					0xF134
#define MFC_REG_D_FIRST_PLANE_DPB_STRIDE_SIZE			0xF138
#define MFC_REG_D_SECOND_PLANE_DPB_STRIDE_SIZE			0xF13C
#define MFC_REG_D_THIRD_PLANE_DPB_STRIDE_SIZE			0xF140
#define MFC_REG_D_FIRST_PLANE_DPB_SIZE				0xF144
#define MFC_REG_D_SECOND_PLANE_DPB_SIZE			0xF148
#define MFC_REG_D_THIRD_PLANE_DPB_SIZE				0xF14C
#define MFC_REG_D_MV_BUFFER_SIZE				0xF150
#define MFC_REG_D_INIT_BUFFER_OPTIONS				0xF154
#define MFC_REG_D_FIRST_PLANE_DPB0				0xF160
#define MFC_REG_D_SECOND_PLANE_DPB0				0xF260
#define MFC_REG_D_THIRD_PLANE_DPB0				0xF360
#define MFC_REG_D_MV_BUFFER0					0xF460
#define MFC_REG_D_SCRATCH_BUFFER_ADDR				0xF560
#define MFC_REG_D_SCRATCH_BUFFER_SIZE				0xF564
#define MFC_REG_D_METADATA_BUFFER_ADDR				0xF568
#define MFC_REG_D_METADATA_BUFFER_SIZE				0xF56C

#define MFC_REG_D_STATIC_BUFFER_ADDR				0xF570
#define MFC_REG_D_STATIC_BUFFER_SIZE				0xF574
#define MFC_REG_D_FIRST_PLANE_2BIT_DPB_SIZE			0xF578
#define MFC_REG_D_SECOND_PLANE_2BIT_DPB_SIZE			0xF57C
#define MFC_REG_D_FIRST_PLANE_2BIT_DPB_STRIDE_SIZE		0xF580
#define MFC_REG_D_SECOND_PLANE_2BIT_DPB_STRIDE_SIZE		0xF584

#define MFC_REG_D_NAL_START_OPTIONS				0xF5AC

/* Nal cmd */
#define MFC_REG_D_CPB_BUFFER_ADDR				0xF5B0
#define MFC_REG_D_CPB_BUFFER_SIZE				0xF5B4
#define MFC_REG_D_AVAILABLE_DPB_FLAG_UPPER			0xF5B8
#define MFC_REG_D_AVAILABLE_DPB_FLAG_LOWER			0xF5BC
#define MFC_REG_D_CPB_BUFFER_OFFSET				0xF5C0
#define MFC_REG_D_SLICE_IF_ENABLE				0xF5C4
#define MFC_REG_D_PICTURE_TAG					0xF5C8
#define MFC_REG_D_STREAM_DATA_SIZE				0xF5D0
#define MFC_REG_D_DYNAMIC_DPB_FLAG_UPPER			0xF5D4
#define MFC_REG_D_DYNAMIC_DPB_FLAG_LOWER			0xF5D8

/* Nal return */
#define MFC_REG_D_DISPLAY_FRAME_WIDTH				0xF600
#define MFC_REG_D_DISPLAY_FRAME_HEIGHT				0xF604
#define MFC_REG_D_DISPLAY_STATUS				0xF608
#define MFC_REG_D_DISPLAY_FIRST_PLANE_ADDR			0xF60C
#define MFC_REG_D_DISPLAY_SECOND_PLANE_ADDR			0xF610
#define MFC_REG_D_DISPLAY_THIRD_PLANE_ADDR			0xF614
#define MFC_REG_D_DISPLAY_FRAME_TYPE				0xF618
#define MFC_REG_D_DISPLAY_CROP_INFO1				0xF61C
#define MFC_REG_D_DISPLAY_CROP_INFO2				0xF620
#define MFC_REG_D_DISPLAY_PICTURE_PROFILE			0xF624
#define MFC_REG_D_DISPLAY_FIRST_PLANE_CRC			0xF628
#define MFC_REG_D_DISPLAY_SECOND_PLANE_CRC			0xF62C
#define MFC_REG_D_DISPLAY_THIRD_PLANE_CRC			0xF630
#define MFC_REG_D_DISPLAY_ASPECT_RATIO				0xF634
#define MFC_REG_D_DISPLAY_EXTENDED_AR				0xF638
#define MFC_REG_D_DECODED_FRAME_WIDTH				0xF63C
#define MFC_REG_D_DECODED_FRAME_HEIGHT				0xF640
#define MFC_REG_D_DECODED_STATUS				0xF644
#define MFC_REG_D_DECODED_FIRST_PLANE_ADDR			0xF648
#define MFC_REG_D_DECODED_SECOND_PLANE_ADDR			0xF64C
#define MFC_REG_D_DECODED_THIRD_PLANE_ADDR			0xF650
#define MFC_REG_D_DECODED_FRAME_TYPE				0xF654
#define MFC_REG_D_DECODED_CROP_INFO1				0xF658
#define MFC_REG_D_DECODED_CROP_INFO2				0xF65C
#define MFC_REG_D_DECODED_PICTURE_PROFILE			0xF660
#define MFC_REG_D_DECODED_NAL_SIZE				0xF664
#define MFC_REG_D_DECODED_FIRST_PLANE_CRC			0xF668
#define MFC_REG_D_DECODED_SECOND_PLANE_CRC			0xF66C
#define MFC_REG_D_DECODED_THIRD_PLANE_CRC			0xF670
#define MFC_REG_D_RET_PICTURE_TAG_TOP				0xF674
#define MFC_REG_D_RET_PICTURE_TAG_BOT				0xF678
#define MFC_REG_D_RET_PICTURE_TIME_TOP				0xF67C
#define MFC_REG_D_RET_PICTURE_TIME_BOT				0xF680
#define MFC_REG_D_CHROMA_FORMAT				0xF684

#define MFC_REG_D_VC1_INFO					0xF688
#define MFC_REG_D_MPEG4_INFO					0xF68C
#define MFC_REG_D_H264_INFO					0xF690
#define MFC_REG_D_HEVC_INFO					0xF6A0
#define MFC_REG_D_VP9_INFO					0xF6A4
#define MFC_REG_D_BPG_INFO					0xF6A8
#define MFC_REG_D_AV1_INFO					0xF6AC

#define MFC_REG_D_METADATA_ADDR_CONCEALED_MB			0xF6B0
#define MFC_REG_D_METADATA_SIZE_CONCEALED_MB			0xF6B4
#define MFC_REG_D_METADATA_ADDR_VC1_PARAM			0xF6B8
#define MFC_REG_D_METADATA_SIZE_VC1_PARAM			0xF6BC
#define MFC_REG_D_METADATA_ADDR_SEI_NAL			0xF6C0
#define MFC_REG_D_METADATA_SIZE_SEI_NAL			0xF6C4
#define MFC_REG_D_METADATA_ADDR_VUI				0xF6C8
#define MFC_REG_D_METADATA_SIZE_VUI				0xF6CC
#define MFC_REG_D_METADATA_ADDR_MVCVUI				0xF6D0
#define MFC_REG_D_METADATA_SIZE_MVCVUI				0xF6D4

#define MFC_REG_D_MVC_VIEW_ID					0xF6D8

#define MFC_REG_D_SEI_AVAIL					0xF6DC
#define MFC_REG_D_FRAME_PACK_ARRGMENT_ID			0xF6E0
#define MFC_REG_D_FRAME_PACK_SEI_INFO				0xF6E4
#define MFC_REG_D_FRAME_PACK_GRID_POS				0xF6E8

#define MFC_REG_D_DISPLAY_RECOVERY_SEI_INFO			0xF6EC
#define MFC_REG_D_DECODED_RECOVERY_SEI_INFO			0xF6F0

#define MFC_REG_D_DISPLAY_FIRST_PLANE_2BIT_CRC			0xF6FC
#define MFC_REG_D_DISPLAY_SECOND_PLANE_2BIT_CRC		0xF700
#define MFC_REG_D_DECODED_FIRST_PLANE_2BIT_CRC			0xF704
#define MFC_REG_D_DECODED_SECOND_PLANE_2BIT_CRC		0xF708

#define MFC_REG_D_VIDEO_SIGNAL_TYPE				0xF70C
#define MFC_REG_D_CONTENT_LIGHT_LEVEL_INFO_SEI			0xF710
#define MFC_REG_D_MASTERING_DISPLAY_COLOUR_VOLUME_SEI_0	0xF714
#define MFC_REG_D_MASTERING_DISPLAY_COLOUR_VOLUME_SEI_1	0xF718

#define MFC_REG_D_USED_DPB_FLAG_UPPER				0xF720
#define MFC_REG_D_USED_DPB_FLAG_LOWER				0xF724

#define MFC_REG_D_MASTERING_DISPLAY_COLOUR_VOLUME_SEI_2	0xF728
#define MFC_REG_D_MASTERING_DISPLAY_COLOUR_VOLUME_SEI_3	0xF72C
#define MFC_REG_D_MASTERING_DISPLAY_COLOUR_VOLUME_SEI_4	0xF730
#define MFC_REG_D_MASTERING_DISPLAY_COLOUR_VOLUME_SEI_5	0xF734

#define MFC_REG_D_BLACK_BAR_START_POS				0xF738
#define MFC_REG_D_BLACK_BAR_IMAGE_SIZE				0xF73C

#define MFC_REG_D_DISPLAY_LUMA_ADDR				0xF60C
#define MFC_REG_D_DISPLAY_CHROMA_ADDR				0xF610

#define MFC_REG_D_DECODED_LUMA_ADDR				0xF648
#define MFC_REG_D_DECODED_CHROMA_ADDR				0xF64C

/* Encoder Registers */
#define MFC_REG_E_CROPPED_FRAME_WIDTH				0xF778
#define MFC_REG_E_CROPPED_FRAME_HEIGHT				0xF77C
#define MFC_REG_E_FRAME_CROP_OFFSET				0xF780
#define MFC_REG_E_ENC_OPTIONS					0xF784
#define MFC_REG_E_PICTURE_PROFILE				0xF788
#define MFC_REG_E_VBV_BUFFER_SIZE				0xF78C
#define MFC_REG_E_VBV_INIT_DELAY				0xF790
#define MFC_REG_E_FIXED_PICTURE_QP				0xF794
#define MFC_REG_E_RC_CONFIG					0xF798
#define MFC_REG_E_RC_QP_BOUND					0xF79C
#define MFC_REG_E_RC_QP_BOUND_PB				0xF7A0
#define MFC_REG_E_RC_MODE					0xF7A4

#define MFC_REG_E_MB_RC_CONFIG					0xF7A8
#define MFC_REG_E_PADDING_CTRL					0xF7AC
#define MFC_REG_E_AIR_THRESHOLD				0xF7B0

#define MFC_REG_E_MV_HOR_RANGE					0xF7B4
#define MFC_REG_E_MV_VER_RANGE					0xF7B8

#define MFC_REG_E_HIGH_QUALITY_MODE				0xF7C0
#define MFC_REG_E_VIDEO_SIGNAL_TYPE				0xF7C4

#define MFC_REG_E_SAO_WEIGHT0					0xF7C8
#define MFC_REG_E_SAO_WEIGHT1					0xF7CC

#define MFC_REG_E_NUM_DPB					0xF890
#define MFC_REG_E_MIN_SCRATCH_BUFFER_SIZE			0xF894
#define MFC_REG_E_MIN_LUMA_DPB_SIZE				0xF898
#define MFC_REG_E_MIN_CHROMA_DPB_SIZE				0xF89C

#define MFC_REG_E_LUMA_DPB					0xF8C0
#define MFC_REG_E_CHROMA_DPB					0xF904
#define MFC_REG_E_ME_BUFFER					0xF948

#define MFC_REG_E_SCRATCH_BUFFER_ADDR				0xF98C
#define MFC_REG_E_SCRATCH_BUFFER_SIZE				0xF990
#define MFC_REG_E_TMV_BUFFER0					0xF994
#define MFC_REG_E_TMV_BUFFER1					0xF998
#define MFC_REG_E_IR_BUFFER_ADDR				0xF99C
#define MFC_REG_E_SOURCE_VOTF_BUF_INDEX				0xF9CC
#define MFC_REG_E_SOURCE_FIRST_2BIT_ADDR			0xF9D0
#define MFC_REG_E_SOURCE_SECOND_2BIT_ADDR			0xF9D4
#define MFC_REG_E_SOURCE_FIRST_2BIT_STRIDE			0xF9D8
#define MFC_REG_E_SOURCE_SECOND_2BIT_STRIDE			0xF9DC
#define MFC_REG_E_SOURCE_FIRST_ADDR				0xF9E0
#define MFC_REG_E_SOURCE_SECOND_ADDR				0xF9E4
#define MFC_REG_E_SOURCE_THIRD_ADDR				0xF9E8
#define MFC_REG_E_SOURCE_FIRST_STRIDE				0xF9EC
#define MFC_REG_E_SOURCE_SECOND_STRIDE				0xF9F0
#define MFC_REG_E_SOURCE_THIRD_STRIDE				0xF9F4
#define MFC_REG_E_STREAM_BUFFER_ADDR				0xF9F8
#define MFC_REG_E_STREAM_BUFFER_SIZE				0xF9FC
#define MFC_REG_E_ROI_BUFFER_ADDR				0xFA00

#define MFC_REG_E_PARAM_CHANGE					0xFA04
#define MFC_REG_E_IR_SIZE					0xFA08
#define MFC_REG_E_GOP_CONFIG					0xFA0C
#define MFC_REG_E_MSLICE_MODE					0xFA10
#define MFC_REG_E_MSLICE_SIZE_MB				0xFA14
#define MFC_REG_E_MSLICE_SIZE_BITS				0xFA18
#define MFC_REG_E_FRAME_INSERTION				0xFA1C

#define MFC_REG_E_RC_FRAME_RATE				0xFA20
#define MFC_REG_E_RC_BIT_RATE					0xFA24
#define MFC_REG_E_RC_ROI_CTRL					0xFA2C
#define MFC_REG_E_PICTURE_TAG					0xFA30
#define MFC_REG_E_BIT_COUNT_ENABLE				0xFA34
#define MFC_REG_E_MAX_BIT_COUNT				0xFA38
#define MFC_REG_E_MIN_BIT_COUNT				0xFA3C

#define MFC_REG_E_METADATA_BUFFER_ADDR				0xFA40
#define MFC_REG_E_METADATA_BUFFER_SIZE				0xFA44

#define MFC_REG_E_ENCODING_ORDER_TIME_INFO			0xFA50
#define MFC_REG_E_ENCODING_ORDER_INFO				0xFA54
#define MFC_REG_E_STREAM_BUFFER_OFFSET				0xFA58
#define MFC_REG_E_GOP_CONFIG2					0xFA5C
#define MFC_REG_E_WEIGHT_FOR_WEIGHTED_PREDICTION		0xFA60

#define MFC_REG_E_ENCODED_SOURCE_FIRST_ADDR			0xFA70
#define MFC_REG_E_ENCODED_SOURCE_SECOND_ADDR			0xFA74
#define MFC_REG_E_ENCODED_SOURCE_THIRD_ADDR			0xFA78

#define MFC_REG_E_STREAM_SIZE					0xFA80
#define MFC_REG_E_SLICE_TYPE					0xFA84
#define MFC_REG_E_PICTURE_COUNT				0xFA88
#define MFC_REG_E_RET_PICTURE_TAG				0xFA8C

#define MFC_REG_E_RECON_LUMA_DPB_ADDR				0xFA9C
#define MFC_REG_E_RECON_CHROMA_DPB_ADDR			0xFAA0
#define MFC_REG_E_METADATA_ADDR_ENC_SLICE			0xFAA4
#define MFC_REG_E_METADATA_SIZE_ENC_SLICE			0xFAA8

#define MFC_REG_E_NAL_DONE_INFO				0xFAEC

#define MFC_REG_E_MPEG4_OPTIONS				0xFB10
#define MFC_REG_E_MPEG4_HEC_PERIOD				0xFB14

#define MFC_REG_E_BPG_OPTIONS					0xFB1C
#define MFC_REG_E_BPG_EXT_CTB_QP_CTRL				0xFB20
#define MFC_REG_E_BPG_CHROMA_QP_OFFSET				0xFB24
#define MFC_REG_E_BPG_EXTENSION_DATA_SIZE			0xFB28

#define MFC_REG_E_H264_HD_SVC_EXTENSION_0			0xFB44
#define MFC_REG_E_H264_HD_SVC_EXTENSION_1			0xFB48
#define MFC_REG_E_ASPECT_RATIO					0xFB4C
#define MFC_REG_E_EXTENDED_SAR					0xFB50

#define MFC_REG_E_H264_OPTIONS					0xFB54
#define MFC_REG_E_H264_OPTIONS_2				0xFB58
#define MFC_REG_E_H264_LF_ALPHA_OFFSET				0xFB5C
#define MFC_REG_E_H264_LF_BETA_OFFSET				0xFB60
#define MFC_REG_E_H264_REFRESH_PERIOD				0xFB64

#define MFC_REG_E_H264_FMO_SLICE_GRP_MAP_TYPE			0xFB68
#define MFC_REG_E_H264_FMO_NUM_SLICE_GRP_MINUS1		0xFB6C
#define MFC_REG_E_H264_FMO_SLICE_GRP_CHANGE_DIR		0xFB70
#define MFC_REG_E_H264_FMO_SLICE_GRP_CHANGE_RATE_MINUS1	0xFB74
#define MFC_REG_E_H264_FMO_RUN_LENGTH_MINUS1_0			0xFB78
#define MFC_REG_E_H264_FMO_RUN_LENGTH_MINUS1_1			0xFB7C
#define MFC_REG_E_H264_FMO_RUN_LENGTH_MINUS1_2			0xFB80
#define MFC_REG_E_H264_FMO_RUN_LENGTH_MINUS1_3			0xFB84

#define MFC_REG_E_H264_ASO_SLICE_ORDER_0			0xFB88
#define MFC_REG_E_H264_ASO_SLICE_ORDER_1			0xFB8C
#define MFC_REG_E_H264_ASO_SLICE_ORDER_2			0xFB90
#define MFC_REG_E_H264_ASO_SLICE_ORDER_3			0xFB94
#define MFC_REG_E_H264_ASO_SLICE_ORDER_4			0xFB98
#define MFC_REG_E_H264_ASO_SLICE_ORDER_5			0xFB9C
#define MFC_REG_E_H264_ASO_SLICE_ORDER_6			0xFBA0
#define MFC_REG_E_H264_ASO_SLICE_ORDER_7			0xFBA4
#define MFC_REG_E_H264_CHROMA_QP_OFFSET			0xFBA8

#define MFC_REG_E_NUM_T_LAYER					0xFBAC
#define MFC_REG_E_HIERARCHICAL_QP_LAYER0			0xFBB0
#define MFC_REG_E_HIERARCHICAL_QP_LAYER1			0xFBB4
#define MFC_REG_E_HIERARCHICAL_QP_LAYER2			0xFBB8
#define MFC_REG_E_HIERARCHICAL_QP_LAYER3			0xFBBC
#define MFC_REG_E_HIERARCHICAL_QP_LAYER4			0xFBC0
#define MFC_REG_E_HIERARCHICAL_QP_LAYER5			0xFBC4
#define MFC_REG_E_HIERARCHICAL_QP_LAYER6			0xFBC8

/* For backward compatibility */
#define MFC_REG_E_H264_FRAME_PACKING_SEI_INFO			0xFC4C

#define MFC_REG_E_H264_NAL_CONTROL				0xFD14
#define MFC_REG_E_HIERARCHICAL_BIT_RATE_LAYER0			0xFD18
#define MFC_REG_E_HIERARCHICAL_BIT_RATE_LAYER1			0xFD1C
#define MFC_REG_E_HIERARCHICAL_BIT_RATE_LAYER2			0xFD20
#define MFC_REG_E_HIERARCHICAL_BIT_RATE_LAYER3			0xFD24
#define MFC_REG_E_HIERARCHICAL_BIT_RATE_LAYER4			0xFD28
#define MFC_REG_E_HIERARCHICAL_BIT_RATE_LAYER5			0xFD2C
#define MFC_REG_E_HIERARCHICAL_BIT_RATE_LAYER6			0xFD30

#define MFC_REG_E_MVC_FRAME_QP_VIEW1				0xFD40
#define MFC_REG_E_MVC_RC_FRAME_RATE_VIEW1			0xFD44
#define MFC_REG_E_MVC_RC_BIT_RATE_VIEW1			0xFD48
#define MFC_REG_E_MVC_RC_QBOUND_VIEW1				0xFD4C
#define MFC_REG_E_MVC_RC_MODE_VIEW1				0xFD50
#define MFC_REG_E_MVC_INTER_VIEW_PREDICTION_ON			0xFD80

#define MFC_REG_E_VP9_OPTION					0xFD90
#define MFC_REG_E_VP9_FILTER_OPTION				0xFD94
#define MFC_REG_E_VP9_GOLDEN_FRAME_OPTION			0xFD98
#define MFC_REG_E_VP8_OPTION					0xFDB0
#define MFC_REG_E_VP8_FILTER_OPTION				0xFDB4
#define MFC_REG_E_VP8_GOLDEN_FRAME_OPTION			0xFDB8

#define MFC_REG_E_HEVC_OPTIONS_2				0xFDC4

#define MFC_REG_E_HEVC_OPTIONS					0xFDD4
#define MFC_REG_E_HEVC_REFRESH_PERIOD				0xFDD8
#define MFC_REG_E_HEVC_CHROMA_QP_OFFSET			0xFDDC
#define MFC_REG_E_HEVC_LF_BETA_OFFSET_DIV2			0xFDE0
#define MFC_REG_E_HEVC_LF_TC_OFFSET_DIV2			0xFDE4
#define MFC_REG_E_HEVC_NAL_CONTROL				0xFDE8

#define MFC_REG_E_VP8_NAL_CONTROL				0xFDF0
#define MFC_REG_E_VP9_NAL_CONTROL				0xFDF4
#define MFC_REG_E_CONTENT_LIGHT_LEVEL_INFO_SEI			0xFDF8
#define MFC_REG_E_MASTERING_DISPLAY_COLOUR_VOLUME_SEI_0	0xFDFC
#define MFC_REG_E_MASTERING_DISPLAY_COLOUR_VOLUME_SEI_1	0xFE00
#define MFC_REG_E_MASTERING_DISPLAY_COLOUR_VOLUME_SEI_2	0xFE04
#define MFC_REG_E_MASTERING_DISPLAY_COLOUR_VOLUME_SEI_3	0xFE08
#define MFC_REG_E_MASTERING_DISPLAY_COLOUR_VOLUME_SEI_4	0xFE0C
#define MFC_REG_E_MASTERING_DISPLAY_COLOUR_VOLUME_SEI_5	0xFE10

#define MFC_REG_E_ST_2094_40_SEI_0				0xFE14
#define MFC_REG_E_ST_2094_40_SEI_1				0xFE18
#define MFC_REG_E_ST_2094_40_SEI_2				0xFE1C
#define MFC_REG_E_ST_2094_40_SEI_3				0xFE20
#define MFC_REG_E_ST_2094_40_SEI_4				0xFE24
#define MFC_REG_E_ST_2094_40_SEI_5				0xFE28
#define MFC_REG_E_ST_2094_40_SEI_6				0xFE2C
#define MFC_REG_E_ST_2094_40_SEI_7				0xFE30
#define MFC_REG_E_ST_2094_40_SEI_8				0xFE34
#define MFC_REG_E_ST_2094_40_SEI_9				0xFE38
#define MFC_REG_E_ST_2094_40_SEI_10				0xFE3C
#define MFC_REG_E_ST_2094_40_SEI_11				0xFE40
#define MFC_REG_E_ST_2094_40_SEI_12				0xFE44
#define MFC_REG_E_ST_2094_40_SEI_13				0xFE48
#define MFC_REG_E_ST_2094_40_SEI_14				0xFE4C
#define MFC_REG_E_ST_2094_40_SEI_15				0xFE50
#define MFC_REG_E_ST_2094_40_SEI_16				0xFE54
#define MFC_REG_E_ST_2094_40_SEI_17				0xFE58
#define MFC_REG_E_ST_2094_40_SEI_18				0xFE5C
#define MFC_REG_E_ST_2094_40_SEI_19				0xFE60
#define MFC_REG_E_ST_2094_40_SEI_20				0xFE64
#define MFC_REG_E_ST_2094_40_SEI_21				0xFE68
#define MFC_REG_E_ST_2094_40_SEI_22				0xFE6C
#define MFC_REG_E_ST_2094_40_SEI_23				0xFE70
#define MFC_REG_E_ST_2094_40_SEI_24				0xFE74
#define MFC_REG_E_ST_2094_40_SEI_25				0xFE78
#define MFC_REG_E_ST_2094_40_SEI_26				0xFE7C
#define MFC_REG_E_ST_2094_40_SEI_27				0xFE80
#define MFC_REG_E_ST_2094_40_SEI_28				0xFE84
#define MFC_REG_E_ST_2094_40_SEI_29				0xFE88

#define MFC_REG_D_ST_2094_40_SEI_0				0xFF00
#define MFC_REG_D_ST_2094_40_SEI_1				0xFF04
#define MFC_REG_D_ST_2094_40_SEI_2				0xFF08
#define MFC_REG_D_ST_2094_40_SEI_3				0xFF0C
#define MFC_REG_D_ST_2094_40_SEI_4				0xFF10
#define MFC_REG_D_ST_2094_40_SEI_5				0xFF14
#define MFC_REG_D_ST_2094_40_SEI_6				0xFF18
#define MFC_REG_D_ST_2094_40_SEI_7				0xFF1C
#define MFC_REG_D_ST_2094_40_SEI_8				0xFF20
#define MFC_REG_D_ST_2094_40_SEI_9				0xFF24
#define MFC_REG_D_ST_2094_40_SEI_10				0xFF28
#define MFC_REG_D_ST_2094_40_SEI_11				0xFF2C
#define MFC_REG_D_ST_2094_40_SEI_12				0xFF30
#define MFC_REG_D_ST_2094_40_SEI_13				0xFF34
#define MFC_REG_D_ST_2094_40_SEI_14				0xFF38
#define MFC_REG_D_ST_2094_40_SEI_15				0xFF3C
#define MFC_REG_D_ST_2094_40_SEI_16				0xFF40
#define MFC_REG_D_ST_2094_40_SEI_17				0xFF44
#define MFC_REG_D_ST_2094_40_SEI_18				0xFF48
#define MFC_REG_D_ST_2094_40_SEI_19				0xFF4C
#define MFC_REG_D_ST_2094_40_SEI_20				0xFF50
#define MFC_REG_D_ST_2094_40_SEI_21				0xFF54
#define MFC_REG_D_ST_2094_40_SEI_22				0xFF58
#define MFC_REG_D_ST_2094_40_SEI_23				0xFF5C
#define MFC_REG_D_ST_2094_40_SEI_24				0xFF60
#define MFC_REG_D_ST_2094_40_SEI_25				0xFF64
#define MFC_REG_D_ST_2094_40_SEI_26				0xFF68
#define MFC_REG_D_ST_2094_40_SEI_27				0xFF6C
#define MFC_REG_D_ST_2094_40_SEI_28				0xFF70
#define MFC_REG_D_ST_2094_40_SEI_29				0xFF74

/*
 * Below It is valid only for AV1
 * when FILM_GRAIN_AVAIL of D_SEI_AVAIL is enabled
 */
#define MFC_REG_D_FILM_GRAIN_0					0xFE00
#define MFC_REG_D_FILM_GRAIN_1					0xFE04
#define MFC_REG_D_FILM_GRAIN_2					0xFE08
#define MFC_REG_D_FILM_GRAIN_3					0xFE0C
#define MFC_REG_D_FILM_GRAIN_4					0xFE10
#define MFC_REG_D_FILM_GRAIN_5					0xFE14
#define MFC_REG_D_FILM_GRAIN_6					0xFE18
#define MFC_REG_D_FILM_GRAIN_7					0xFE1C
#define MFC_REG_D_FILM_GRAIN_8					0xFE20
#define MFC_REG_D_FILM_GRAIN_9					0xFE24
#define MFC_REG_D_FILM_GRAIN_10					0xFE28
#define MFC_REG_D_FILM_GRAIN_11					0xFE2C
#define MFC_REG_D_FILM_GRAIN_12					0xFE30
#define MFC_REG_D_FILM_GRAIN_13					0xFE34
#define MFC_REG_D_FILM_GRAIN_14					0xFE38
#define MFC_REG_D_FILM_GRAIN_15					0xFE3C
#define MFC_REG_D_FILM_GRAIN_16					0xFE40
#define MFC_REG_D_FILM_GRAIN_17					0xFE44
#define MFC_REG_D_FILM_GRAIN_18					0xFE48
#define MFC_REG_D_FILM_GRAIN_19					0xFE4C
#define MFC_REG_D_FILM_GRAIN_20					0xFE50
#define MFC_REG_D_FILM_GRAIN_21					0xFE54
#define MFC_REG_D_FILM_GRAIN_22					0xFE58
#define MFC_REG_D_FILM_GRAIN_23					0xFE5C
#define MFC_REG_D_FILM_GRAIN_24					0xFE60
#define MFC_REG_D_FILM_GRAIN_25					0xFE64
#define MFC_REG_D_FILM_GRAIN_26					0xFE68
#define MFC_REG_D_FILM_GRAIN_27					0xFE6C
#define MFC_REG_D_FILM_GRAIN_28					0xFE70
#define MFC_REG_D_FILM_GRAIN_29					0xFE74
#define MFC_REG_D_FILM_GRAIN_30					0xFE78
#define MFC_REG_D_FILM_GRAIN_31					0xFE7C
#define MFC_REG_D_FILM_GRAIN_32					0xFE80
#define MFC_REG_D_FILM_GRAIN_33					0xFE84
#define MFC_REG_D_FILM_GRAIN_34					0xFE88
#define MFC_REG_D_FILM_GRAIN_35					0xFE8C
#define MFC_REG_D_FILM_GRAIN_36					0xFE90
#define MFC_REG_D_FILM_GRAIN_37					0xFE94
#define MFC_REG_D_FILM_GRAIN_38					0xFE98
#define MFC_REG_D_FILM_GRAIN_39					0xFE9C
#define MFC_REG_D_FILM_GRAIN_40					0xFEA0
#define MFC_REG_D_FILM_GRAIN_41					0xFEA4
#define MFC_REG_D_FILM_GRAIN_42					0xFEA8
#define MFC_REG_D_FILM_GRAIN_43					0xFEAC

#define MFC0_REG_COMMON_CONTEXT_MEM_ADDR			0xFF90
#define MFC0_REG_RISC_BASE_ADDR					0xFF98
#define MFC1_REG_COMMON_CONTEXT_MEM_ADDR			0xFFDC

#define MFC_REG_CLEAR_BEGIN			0xf000
#define MFC_REG_CLEAR_COUNT			1024


/* Bit Definitions */
/* 0x1100: MFC_REG_HOST2RISC_CMD */
#define MFC_REG_H2R_CMD_EMPTY				0
#define MFC_REG_H2R_CMD_SYS_INIT			1
#define MFC_REG_H2R_CMD_OPEN_INSTANCE			2
#define MFC_REG_H2R_CMD_SEQ_HEADER			3
#define MFC_REG_H2R_CMD_INIT_BUFFERS			4
#define MFC_REG_H2R_CMD_NAL_START			5
#define MFC_REG_H2R_CMD_CLOSE_INSTANCE			6
#define MFC_REG_H2R_CMD_SLEEP				7
#define MFC_REG_H2R_CMD_WAKEUP				8
#define MFC_REG_H2R_CMD_LAST_FRAME			9
#define MFC_REG_H2R_CMD_DPB_FLUSH			10
#define MFC_REG_H2R_CMD_NAL_ABORT			11
#define MFC_REG_H2R_CMD_CACHE_FLUSH			12
#define MFC_REG_H2R_CMD_NAL_QUEUE			13
#define MFC_REG_H2R_CMD_STOP_QUEUE			14
#define MFC_REG_H2R_CMD_MOVE_INSTANCE			19

#define MFC_REG_H2R_CACHE_FLUSH_FLAG			16


/* 0x1104: MFC_REG_RISC2HOST_CMD */
#define MFC_REG_RISC2HOST_CMD_MASK			0x1FFFF
#define MFC_REG_R2H_CMD_EMPTY				0
#define MFC_REG_R2H_CMD_SYS_INIT_RET			1
#define MFC_REG_R2H_CMD_OPEN_INSTANCE_RET		2
#define MFC_REG_R2H_CMD_SEQ_DONE_RET			3
#define MFC_REG_R2H_CMD_INIT_BUFFERS_RET		4
#define MFC_REG_R2H_CMD_CLOSE_INSTANCE_RET		6
#define MFC_REG_R2H_CMD_SLEEP_RET			7
#define MFC_REG_R2H_CMD_WAKEUP_RET			8
#define MFC_REG_R2H_CMD_COMPLETE_SEQ_RET		9
#define MFC_REG_R2H_CMD_DPB_FLUSH_RET			10
#define MFC_REG_R2H_CMD_NAL_ABORT_RET			11
#define MFC_REG_R2H_CMD_FW_STATUS_RET			12
#define MFC_REG_R2H_CMD_FRAME_DONE_RET			13
#define MFC_REG_R2H_CMD_FIELD_DONE_RET			14
#define MFC_REG_R2H_CMD_SLICE_DONE_RET			15
#define MFC_REG_R2H_CMD_ENC_BUFFER_FULL_RET		16
#define MFC_REG_R2H_CMD_QUEUE_DONE_RET			17
#define MFC_REG_R2H_CMD_COMPLETE_QUEUE_RET		18
#define MFC_REG_R2H_CMD_MOVE_INSTANCE_RET		19
#define MFC_REG_R2H_CMD_CACHE_FLUSH_RET		20
#define MFC_REG_R2H_CMD_ERR_RET			32


/* 0xF000: MFC_REG_FW_VERSION */
#define MFC_REG_FW_VER_INFO_MASK			0xFF
#define MFC_REG_FW_VER_INFO_SHFT			24
#define MFC_REG_FW_VER_YEAR_MASK			0xFF
#define MFC_REG_FW_VER_YEAR_SHFT			16
#define MFC_REG_FW_VER_MONTH_MASK			0xFF
#define MFC_REG_FW_VER_MONTH_SHFT			8
#define MFC_REG_FW_VER_DATE_MASK			0xFF
#define MFC_REG_FW_VER_DATE_SHFT			0
#define MFC_REG_FW_VER_ALL_MASK			0xFFFFFF
#define MFC_REG_FW_VER_ALL_SHFT			0


/* 0xF00C: MFC_REG_CODEC_TYPE */
#define MFC_FORMATS_NO_CODEC				-1
/* Decoder */
#define MFC_REG_CODEC_H264_DEC				0
#define MFC_REG_CODEC_H264_MVC_DEC			1
#define MFC_REG_CODEC_MPEG4_DEC			3
#define MFC_REG_CODEC_FIMV1_DEC			4
#define MFC_REG_CODEC_FIMV2_DEC			5
#define MFC_REG_CODEC_FIMV3_DEC			6
#define MFC_REG_CODEC_FIMV4_DEC			7
#define MFC_REG_CODEC_H263_DEC				8
#define MFC_REG_CODEC_VC1_RCV_DEC			9
#define MFC_REG_CODEC_VC1_DEC				10
#define MFC_REG_CODEC_MPEG2_DEC			13
#define MFC_REG_CODEC_VP8_DEC				14
#define MFC_REG_CODEC_HEVC_DEC				17
#define MFC_REG_CODEC_VP9_DEC				18
#define MFC_REG_CODEC_AV1_DEC				19
/* Encoder */
#define MFC_REG_CODEC_H264_ENC				20
#define MFC_REG_CODEC_H264_MVC_ENC			21
#define MFC_REG_CODEC_MPEG4_ENC			23
#define MFC_REG_CODEC_H263_ENC				24
#define MFC_REG_CODEC_VP8_ENC				25
#define MFC_REG_CODEC_HEVC_ENC				26
#define MFC_REG_CODEC_VP9_ENC				27

#define MFC_REG_CODEC_BPG_DEC				32
#define MFC_REG_CODEC_BPG_ENC				33

/* 0xF00C: MFC_REG_CODEC_TYPE */
#define MFC_REG_CLEAR_CTX_MEM_SHIFT			16
#define MFC_REG_CODEC_TYPE_MASK				0xFFFF

/* 0xF028: MFC_REG_MFC_VERSION */
#define MFC_REG_MFC_VER_MASK				0xFFFFFFFF
#define MFC_REG_MFC_VER_SHFT				0

/* 0xF070: MFC_REG_RET_INSTANCE_ID */
#define MFC_REG_RET_INSTANCE_ID_OF_MFC1_MASK		0xFFFF
#define MFC_REG_RET_INSTANCE_ID_OF_MFC1_SHIFT		16
#define MFC_REG_RET_INSTANCE_ID_MASK			0xFFFF

/* 0xF074: MFC_REG_ERROR_CODE */
#define MFC_REG_ERR_STATUS_MASK			0xFFFF
#define MFC_REG_ERR_STATUS_SHIFT			0
#define MFC_REG_WARN_STATUS_MASK			0xFFFF
#define MFC_REG_WARN_STATUS_SHIFT			16
/* Error number */
#define MFC_REG_ERR_INVALID				9
#define MFC_REG_ERR_BUFFER_FULL				18
#define MFC_REG_ERR_WARNINGS_END			222
/* Dump debug error */
#define MFC_REG_ERR_NO_AVAILABLE_DPB			33
#define MFC_REG_ERR_INSUFFICIENT_DPB_SIZE		57
#define MFC_REG_ERR_INSUFFICIENT_NUM_DPB		58
#define MFC_REG_ERR_INSUFFICIENT_MV_BUF_SIZE		60
#define MFC_REG_ERR_INSUFFICIENT_SCRATCH_BUF_SIZE	62
/* Input decoding error */
#define MFC_REG_ERR_NO_KEY_FRAME                        34
#define MFC_REG_ERR_NO_VALID_SEQ_HDR                    66
#define MFC_REG_ERR_NO_VALID_PIC_HDR                    67
#define MFC_REG_ERR_NO_VALID_REF_FOR_SKIP               72
#define MFC_REG_ERR_UNSUPPORTED_FEATURE                 100
#define MFC_REG_ERR_UNSUPPORTED_RESOLUTION              101
#define MFC_REG_ERR_HEADER_NOT_FOUND                    102
#define MFC_REG_ERR_INVALID_NAL_TYPE                    103
#define MFC_REG_ERR_SEQUENCE_HEADER_ERROR               104
#define MFC_REG_ERR_PICTURE_HEADER_ERROR                105
#define MFC_REG_ERR_SLICE_HEADER_ERROR                  106
#define MFC_REG_ERR_MISSING_FIRST_FIELD                 108
#define MFC_REG_ERR_SLICE_COUNT_IS_OVER_ASO		109
#define MFC_REG_ERR_TILE_HEADER_ERROR			111
#define MFC_REG_ERR_MAX_VIEW_NUM_OVER			112
/* Timeout */
#define MFC_REG_ERR_MFC_TIMEOUT				140
#define MFC_REG_ERR_TS_MUX_TIMEOUT			141
#define MFC_REG_ERR_G2D_TIMEOUT				142
/* Frame concealment and warning */
#define MFC_REG_ERR_FRAME_CONCEAL			150
#define MFC_REG_ERR_BROKEN_LINK				161
#define MFC_REG_ERR_SYNC_POINT_NOT_RECEIVED		190
#define MFC_REG_ERR_NON_PAIRED_FIELD			191


/* 0xF0B4: MFC_REG_D_DEC_OPTIONS */
#define MFC_REG_D_DEC_OPT_DISPLAY_DELAY_EN_SHIFT	3
#define MFC_REG_D_DEC_OPT_FMO_ASO_CTRL_MASK		0x1
#define MFC_REG_D_DEC_OPT_FMO_ASO_CTRL_SHIFT		4
#define MFC_REG_D_DEC_OPT_IDR_DECODING_MASK		0x1
#define MFC_REG_D_DEC_OPT_IDR_DECODING_SHIFT		6
#define MFC_REG_D_DEC_OPT_DISCARD_RCV_HEADER_SHIFT	7
#define MFC_REG_D_DEC_OPT_CONCEAL_CONTROL_SHIFT		8
#define MFC_REG_D_DEC_OPT_PARALLEL_DISABLE_SHIFT	11
#define MFC_REG_D_DEC_OPT_REALLOC_CONTROL_SHIFT		13
#define MFC_REG_D_DEC_OPT_SPECIAL_PARSING_SHIFT		15
#define MFC_REG_D_DEC_OPT_THUMBNAIL_DECODING		16
#define MFC_REG_D_DEC_OPT_DECODING_ORDER_ENABLE		17
#define MFC_REG_D_DEC_OPT_AV1_ANNEX_B_FORMAT_SHIFT	18


/* 0xF0C4: MFC_REG_D_SEI_ENABLE */
#define MFC_REG_D_SEI_ENABLE_NEED_INIT_BUFFER_SHIFT	1
#define MFC_REG_D_SEI_ENABLE_RECOVERY_PARSING_SHIFT	2
#define MFC_REG_D_SEI_ENABLE_CONTENT_LIGHT_SHIFT	4
#define MFC_REG_D_SEI_ENABLE_MASTERING_DISPLAY_SHIFT	5
#define MFC_REG_D_SEI_ENABLE_ST_2094_40_SEI_SHIFT	6
#define MFC_REG_D_SEI_ENABLE_FILM_GRAIN_SHIFT	7


/* 0xF154: MFC_REG_D_INIT_BUFFER_OPTIONS */
#define MFC_REG_D_INIT_BUF_OPT_LF_CTRL_MASK		0x3
#define MFC_REG_D_INIT_BUF_OPT_LF_CTRL_SHIFT		1
#define MFC_REG_D_INIT_BUF_OPT_DYNAMIC_DPB_SET_SHIFT	3
#define MFC_REG_D_INIT_BUF_OPT_COPY_NOT_CODED_SHIFT	4
#define MFC_REG_D_INIT_BUF_OPT_DITHERING_EN_SHIFT	6
#define MFC_REG_D_INIT_BUF_OPT_STRIDE_SIZE_ALIGN	7
#define MFC_REG_D_INIT_BUF_OPT_TWO_MODE_ENABLE_SHIFT	9


/* 0xF5AC: MFC_REG_D_NAL_START_OPTIONS */
#define MFC_REG_D_NAL_START_OPT_TWO_MFC_ENABLE_SHIFT	4
#define MFC_REG_D_NAL_START_OPT_BLACK_BAR_SHIFT		3
#define MFC_REG_D_NAL_START_OPT_NEW_SCRATCH_SHIFT	2
#define MFC_REG_D_NAL_START_OPT_NEW_DPB_SHIFT		1


/* 0xF608: MFC_REG_D_DISPLAY_STATUS */
#define MFC_REG_DISP_STATUS_DISPLAY_STATUS_MASK	0x7
#define MFC_REG_DISP_STATUS_INTERLACE_MASK		0x1
#define MFC_REG_DISP_STATUS_INTERLACE_SHIFT		3
#define MFC_REG_DISP_STATUS_RES_CHANGE_MASK		0x3
#define MFC_REG_DISP_STATUS_RES_CHANGE_SHIFT		4
#define MFC_REG_DISP_STATUS_NEED_DPB_CHANGE_MASK	0x1
#define MFC_REG_DISP_STATUS_NEED_DPB_CHANGE_SHIFT	9
#define MFC_REG_DISP_STATUS_NEED_SCRATCH_CHANGE_MASK	0x1
#define MFC_REG_DISP_STATUS_NEED_SCRATCH_CHANGE_SHIFT	10
#define MFC_REG_DISP_STATUS_NEED_EMPTY_DPB_MASK	0x1
#define MFC_REG_DISP_STATUS_NEED_EMPTY_DPB_SHIFT	12
#define MFC_REG_DISP_STATUS_BLACK_BAR_DETECT_MASK	0x3
#define MFC_REG_DISP_STATUS_BLACK_BAR_DETECT_SHIFT	13
#define MFC_REG_DISP_STATUS_NOT_DETECTED		0x0
#define MFC_REG_DISP_STATUS_BLACK_BAR			0x1
#define MFC_REG_DISP_STATUS_BLACK_SCREEN		0x2
#define MFC_REG_DISP_STATUS_COMP_SHIFT			19
#define MFC_REG_DISP_STATUS_COMP_MASK			0x1
#define MFC_REG_DISP_STATUS_UNCOMP_SHIFT		21
#define MFC_REG_DISP_STATUS_UNCOMP_MASK			0x1


/* 0xF618: MFC_REG_D_DISPLAY_FRAME_TYPE */
#define MFC_REG_DISPLAY_TEMP_INFO_MASK			0x1
#define MFC_REG_DISPLAY_TEMP_INFO_SHIFT			7
#define MFC_REG_DISPLAY_IDR_FLAG_MASK			0x1
#define MFC_REG_DISPLAY_IDR_FLAG_SHIFT			6
#define MFC_REG_DISPLAY_FRAME_MASK			0x7
#define MFC_REG_DISPLAY_FRAME_NOT_CODED			0
#define MFC_REG_DISPLAY_FRAME_I				1
#define MFC_REG_DISPLAY_FRAME_P				2
#define MFC_REG_DISPLAY_FRAME_B				3


/* 0xF61C: MFC_REG_D_DISPLAY_CROP_INFO1 */
#define MFC_REG_D_SHARED_CROP_LEFT_MASK		0xFFFF
#define MFC_REG_D_SHARED_CROP_RIGHT_SHIFT		16


/* 0xF620: MFC_REG_D_DISPLAY_CROP_INFO2 */
#define MFC_REG_D_SHARED_CROP_TOP_MASK			0xFFFF
#define MFC_REG_D_SHARED_CROP_BOTTOM_SHIFT		16


/* 0xF644: MFC_REG_D_DECODED_STATUS */
#define MFC_REG_DEC_STATUS_DECODED_STATUS_MASK		0x7
#define MFC_REG_DEC_STATUS_DECODING_ONLY		0
#define MFC_REG_DEC_STATUS_DECODING_DISPLAY		1
#define MFC_REG_DEC_STATUS_DISPLAY_ONLY		2
#define MFC_REG_DEC_STATUS_DECODING_EMPTY		3
#define MFC_REG_DEC_STATUS_NUM_OF_TILE_MASK		0xF
#define MFC_REG_DEC_STATUS_NUM_OF_TILE_SHIFT		15
#define MFC_REG_DEC_STATUS_INTERLACE_MASK		0x1
#define MFC_REG_DEC_STATUS_INTERLACE_SHIFT		3
#define MFC_REG_DEC_STATUS_UNCOMP_SHIFT			21
#define MFC_REG_DEC_STATUS_UNCOMP_MASK			0x1


/* 0xF654: MFC_REG_D_DECODED_FRAME_TYPE */
#define MFC_REG_DECODED_IDR_FLAG_MASK			0x1
#define MFC_REG_DECODED_IDR_FLAG_SHIFT			3
#define MFC_REG_DECODED_FRAME_MASK			0x7
#define MFC_REG_DECODED_FRAME_NOT_CODED			0
#define MFC_REG_DECODED_FRAME_I				1
#define MFC_REG_DECODED_FRAME_P				2
#define MFC_REG_DECODED_FRAME_B				3


/* 0xF660: MFC_REG_D_DECODED_PICTURE_PROFILE */
#define MFC_REG_D_TWO_MFC_MODE_MASK			0x3
#define MFC_REG_D_TWO_MFC_MODE_SHIFT			28
#define MFC_REG_D_DISPLAY_DELAY_MASK			0x1F
#define MFC_REG_D_DISPLAY_DELAY_SHIFT			23
#define MFC_REG_D_BIT_DEPTH_CHROMA_MINUS8_MASK		0x7
#define MFC_REG_D_BIT_DEPTH_CHROMA_MINUS8_SHIFT		19
#define MFC_REG_D_BIT_DEPTH_LUMA_MINUS8_MASK		0x7
#define MFC_REG_D_BIT_DEPTH_LUMA_MINUS8_SHIFT		16
#define MFC_REG_D_PIC_LEVEL_MASK			0xFF
#define MFC_REG_D_PIC_LEVEL_SHIFT			8
#define MFC_REG_D_DECODED_PIC_PROFILE_MASK		0x1F
#define MFC_REG_D_PROFILE_HEVC_MAIN			1
#define MFC_REG_D_PROFILE_HEVC_MAIN_10			2
#define MFC_REG_D_PROFILE_HEVC_RANGE_EXT		4


/* 0xF684: MFC_REG_D_CHROMA_FORMAT */
#define MFC_REG_D_CHROMA_FORMAT_MASK			0x3
#define MFC_REG_D_COLOR_RANGE_MASK			0x1
#define MFC_REG_D_COLOR_RANGE_SHIFT			3
#define MFC_REG_D_COLOR_SPACE_MASK			0xF
#define MFC_REG_D_COLOR_SPACE_SHIFT			4
#define MFC_REG_D_COLOR_UNKNOWN			0
#define MFC_REG_D_CHROMA_400				0
#define MFC_REG_D_CHROMA_420				1
#define MFC_REG_D_CHROMA_422				2
#define MFC_REG_D_CHROMA_444				3


/* 0xF690: MFC_REG_D_H264_INFO */
#define MFC_REG_D_H264_INFO_MBAFF_FRAME_FLAG_SHIFT	9
#define MFC_REG_D_H264_INFO_MBAFF_FRAME_FLAG_MASK	0x1
#define MFC_REG_D_H264_INFO_TEMPORAL_ID_SHIFT	6
#define MFC_REG_D_H264_INFO_TEMPORAL_ID_MASK	0x7


/* 0xF6A0: MFC_REG_D_HEVC_INFO */
#define MFC_REG_D_HEVC_INFO_LCU_SIZE_MASK		0x3

/* 0xF6A4: MFC_REG_D_VP9_INFO */
#define MFC_REG_D_VP9_INFO_DISP_RES_SHIFT		14
#define MFC_REG_D_VP9_INFO_DISP_RES_MASK		0x1

/* 0xF6AC: MFC_REG_D_AV1_INFO */
#define MFC_REG_D_AV1_INFO_FILMGRAIN_PRESENT_SHIFT	18
#define MFC_REG_D_AV1_INFO_FILMGRAIN_PRESENT_MASK	0x1
#define MFC_REG_D_AV1_INFO_MULTIPLE_SHOW_SHIFT		17
#define MFC_REG_D_AV1_INFO_MULTIPLE_SHOW_MASK		0x1
#define MFC_REG_D_AV1_INFO_DISP_RES_SHIFT		14
#define MFC_REG_D_AV1_INFO_DISP_RES_MASK		0x1
#define MFC_REG_D_AV1_INFO_SHOWABLE_FRAME_SHIFT		5
#define MFC_REG_D_AV1_INFO_SHOWABLE_FRAME_MASK		0x1

/* 0xF6D8: MFC_REG_D_MVC_VIEW_ID */
#define MFC_REG_D_MVC_VIEW_ID_DISP_MASK		0xFFFF


/* 0xF6DC: MFC_REG_D_SEI_AVAIL */
#define MFC_REG_D_SEI_AVAIL_FRAME_PACK_MASK		0x1
#define MFC_REG_D_SEI_AVAIL_CONTENT_LIGHT_MASK		0x1
#define MFC_REG_D_SEI_AVAIL_CONTENT_LIGHT_SHIFT	1
#define MFC_REG_D_SEI_AVAIL_MASTERING_DISPLAY_MASK	0x1
#define MFC_REG_D_SEI_AVAIL_MASTERING_DISPLAY_SHIFT	2
#define MFC_REG_D_SEI_AVAIL_ST_2094_40_MASK		0x1
#define MFC_REG_D_SEI_AVAIL_ST_2094_40_SHIFT		3
#define MFC_REG_D_SEI_AVAIL_FILM_GRAIN_MASK		0x1
#define MFC_REG_D_SEI_AVAIL_FILM_GRAIN_SHIFT		4


/* 0xF70C: MFC_REG_D_VIDEO_SIGNAL_TYPE */
#define MFC_REG_D_VIDEO_SIGNAL_TYPE_FLAG_MASK		0x1
#define MFC_REG_D_VIDEO_SIGNAL_TYPE_FLAG_SHIFT		29
#define MFC_REG_D_COLOUR_DESCRIPTION_FLAG_MASK		0x1
#define MFC_REG_D_COLOUR_DESCRIPTION_FLAG_SHIFT	24


/* 0xF738: MFC_REG_D_BLACK_BAR_START_POS */
#define MFC_REG_D_BLACK_BAR_START_X_SHIFT		0
#define MFC_REG_D_BLACK_BAR_START_X_MASK		0xFFFF
#define MFC_REG_D_BLACK_BAR_START_Y_SHIFT		16
#define MFC_REG_D_BLACK_BAR_START_Y_MASK		0xFFFF


/* 0xF73C: MFC_REG_D_BLACK_BAR_IMAGE_SIZE */
#define MFC_REG_D_BLACK_BAR_IMAGE_W_SHIFT		0
#define MFC_REG_D_BLACK_BAR_IMAGE_W_MASK		0xFFFF
#define MFC_REG_D_BLACK_BAR_IMAGE_H_SHIFT		16
#define MFC_REG_D_BLACK_BAR_IMAGE_H_MASK		0xFFFF


/* 0xF780:  MFC_REG_E_FRAME_CROP_OFFSET */
#define MFC_REG_E_FRAME_CROP_OFFSET_TOP		16
#define MFC_REG_E_FRAME_CROP_OFFSET_LEFT		0
#define MFC_REG_E_FRAME_CROP_OFFSET_MASK		0x3FFF


/* 0xF788: MFC_REG_E_PICTURE_PROFILE */
#define MFC_REG_E_PROFILE_H264_BASELINE		0
#define MFC_REG_E_PROFILE_H264_MAIN			1
#define MFC_REG_E_PROFILE_H264_HIGH			2
#define MFC_REG_E_PROFILE_H264_CONSTRAINED_BASELINE	3
#define MFC_REG_E_PROFILE_H264_CONSTRAINED_HIGH	5
#define MFC_REG_E_PROFILE_MPEG4_SIMPLE			0
#define MFC_REG_E_PROFILE_MPEG4_ADVANCED_SIMPLE	1
#define MFC_REG_E_PROFILE_HEVC_MAIN			0
#define MFC_REG_E_PROFILE_HEVC_MAIN_422_10_INTRA	2
#define MFC_REG_E_PROFILE_HEVC_MAIN_10			3
#define MFC_REG_E_PROFILE_HEVC_MAIN_422_10		4
#define MFC_REG_E_PROFILE_VP9_PROFILE0			0
#define MFC_REG_E_PROFILE_VP9_PROFILE1			1
#define MFC_REG_E_PROFILE_VP9_PROFILE2			2
#define MFC_REG_E_PROFILE_VP9_PROFILE3			3


/* 0xF7A4: MFC_REG_E_RC_MODE */
#define MFC_REG_E_RC_CBR_FIX				0
#define MFC_REG_E_RC_CBR_VAR				1
#define MFC_REG_E_RC_VBR				2
#define MFC_REG_E_RC_CBR_I_LIMIT			3


/* 0xFA84: MFC_REG_E_SLICE_TYPE */
#define MFC_REG_E_SLICE_TYPE_NOT_CODED			0
#define MFC_REG_E_SLICE_TYPE_MASK			0xF
#define MFC_REG_E_SLICE_TYPE_I				1
#define MFC_REG_E_SLICE_TYPE_P				2
#define MFC_REG_E_SLICE_TYPE_B				3
#define MFC_REG_E_SLICE_TYPE_SKIPPED			4

/* 0xFAEC: MFC_REG_E_NAL_DONE_INFO */
#define MFC_REG_E_NAL_DONE_INFO_IDR_MASK		0x1
#define MFC_REG_E_NAL_DONE_INFO_IDR_SHIFT		20

#endif /* __MFC_REGS_H */
