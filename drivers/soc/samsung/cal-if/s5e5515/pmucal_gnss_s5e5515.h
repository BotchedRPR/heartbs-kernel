/* individual sequence descriptor for gnss control - init, reset, release, gnss_active_clear, gnss_reset_req_clear */
struct pmucal_seq gnss_init[] = {
	PMUCAL_SEQ_DESC(PMUCAL_WRITE, "GNSS_CTRL_S", 0x12860000, 0x3894, (0x1 << 3), (0x1 << 3), 0, 0, 0xffffffff, 0),
	PMUCAL_SEQ_DESC(PMUCAL_WRITE, "GNSS_OPTION", 0x12860000, 0x388c, (0x1 << 3), (0x1 << 3), 0, 0, 0xffffffff, 0),
	PMUCAL_SEQ_DESC(PMUCAL_WRITE, "GNSS_OPTION", 0x12860000, 0x388c, (0x1 << 1), (0x1 << 1), 0, 0, 0xffffffff, 0),
	PMUCAL_SEQ_DESC(PMUCAL_DELAY, "delay", 0, 0, 0, 0x3, 0, 0, 0, 0),
	PMUCAL_SEQ_DESC(PMUCAL_SET_BIT_ATOMIC, "SYSTEM_OUT", 0x12860000, 0x3d20, (0xffff << 0), (0x9 << 0), 0, 0, 0xffffffff, 0),
	PMUCAL_SEQ_DESC(PMUCAL_WAIT, "VGPIO_TX_MONITOR", 0x12860000, 0xa14, (0x1 << 29), (0x1 << 29), 0, 0, 0xffffffff, 0),
	PMUCAL_SEQ_DESC(PMUCAL_SET_BIT_ATOMIC, "SYSTEM_OUT", 0x12860000, 0x3d20, (0xffff << 0), (0x1D << 0), 0, 0, 0xffffffff, 0),
	PMUCAL_SEQ_DESC(PMUCAL_WAIT, "VGPIO_TX_MONITOR", 0x12860000, 0xa14, (0x1 << 11), (0x1 << 11), 0, 0, 0xffffffff, 0),
	PMUCAL_SEQ_DESC(PMUCAL_DELAY, "delay", 0, 0, 0, 0x3e8, 0, 0, 0, 0),
	PMUCAL_SEQ_DESC(PMUCAL_WRITE, "GNSS_CONFIGURATION", 0x12860000, 0x3880, (0x1 << 0), (0x1 << 0), 0, 0, 0xffffffff, 0),
	PMUCAL_SEQ_DESC(PMUCAL_WAIT, "GNSS_STATUS", 0x12860000, 0x3884, (0x1 << 0), (0x1 << 0), 0, 0, 0xffffffff, 0),
	PMUCAL_SEQ_DESC(PMUCAL_WAIT, "GNSS_IN", 0x12860000, 0x38a4, (0x1 << 4), (0x1 << 4), 0, 0, 0xffffffff, 0),
	PMUCAL_SEQ_DESC(PMUCAL_WRITE, "GNSS_CTRL_NS", 0x12860000, 0x3890, (0x1 << 8), (0x0 << 8), 0, 0, 0xffffffff, 0),
	PMUCAL_SEQ_DESC(PMUCAL_WRITE, "GNSS_CTRL_NS", 0x12860000, 0x3890, (0x1 << 7), (0x1 << 7), 0, 0, 0xffffffff, 0),
};

struct pmucal_seq gnss_status[] = {
	PMUCAL_SEQ_DESC(PMUCAL_READ, "GNSS_STATUS", 0x12860000, 0x3884, (0x1 << 0), 0, 0, 0, 0xffffffff, 0),
};

struct pmucal_seq gnss_reset_assert[] = {
	PMUCAL_SEQ_DESC(PMUCAL_WRITE, "GNSS_CTRL_NS", 0x12860000, 0x3890, (0x1 << 7), (0x0 << 7), 0, 0, 0xffffffff, 0),
	PMUCAL_SEQ_DESC(PMUCAL_WRITE, "GNSS_CONFIGURATION", 0x12860000, 0x3880, (0x1 << 0), (0x0 << 0), 0, 0, 0xffffffff, 0),
	PMUCAL_SEQ_DESC(PMUCAL_WAIT, "GNSS_STATUS", 0x12860000, 0x3884, (0x1 << 0), (0x0 << 0), 0, 0, 0xffffffff, 0),
};

struct pmucal_seq gnss_reset_release[] = {
	PMUCAL_SEQ_DESC(PMUCAL_WRITE, "GNSS_OPTION", 0x12860000, 0x388c, (0x1 << 3), (0x1 << 3), 0, 0, 0xffffffff, 0),
	PMUCAL_SEQ_DESC(PMUCAL_WRITE, "GNSS_OPTION", 0x12860000, 0x388c, (0x1 << 1), (0x1 << 1), 0, 0, 0xffffffff, 0),
	PMUCAL_SEQ_DESC(PMUCAL_DELAY, "delay", 0, 0, 0, 0x3, 0, 0, 0, 0),
	PMUCAL_SEQ_DESC(PMUCAL_SET_BIT_ATOMIC, "SYSTEM_OUT", 0x12860000, 0x3d20, (0xffff << 0), (0x9 << 0), 0, 0, 0xffffffff, 0),
	PMUCAL_SEQ_DESC(PMUCAL_WAIT, "VGPIO_TX_MONITOR", 0x12860000, 0xa14, (0x1 << 29), (0x1 << 29), 0, 0, 0xffffffff, 0),
	PMUCAL_SEQ_DESC(PMUCAL_SET_BIT_ATOMIC, "SYSTEM_OUT", 0x12860000, 0x3d20, (0xffff << 0), (0x1D << 0), 0, 0, 0xffffffff, 0),
	PMUCAL_SEQ_DESC(PMUCAL_WAIT, "VGPIO_TX_MONITOR", 0x12860000, 0xa14, (0x1 << 11), (0x1 << 11), 0, 0, 0xffffffff, 0),
	PMUCAL_SEQ_DESC(PMUCAL_DELAY, "delay", 0, 0, 0, 0x3e8, 0, 0, 0, 0),
	PMUCAL_SEQ_DESC(PMUCAL_WRITE, "GNSS_CONFIGURATION", 0x12860000, 0x3880, (0x1 << 0), (0x1 << 0), 0, 0, 0xffffffff, 0),
	PMUCAL_SEQ_DESC(PMUCAL_WAIT, "GNSS_STATUS", 0x12860000, 0x3884, (0x1 << 0), (0x1 << 0), 0, 0, 0xffffffff, 0),
	PMUCAL_SEQ_DESC(PMUCAL_WAIT, "GNSS_IN", 0x12860000, 0x38a4, (0x1 << 4), (0x1 << 4), 0, 0, 0xffffffff, 0),
	PMUCAL_SEQ_DESC(PMUCAL_WRITE, "GNSS_CTRL_NS", 0x12860000, 0x3890, (0x1 << 8), (0x0 << 8), 0, 0, 0xffffffff, 0),
	PMUCAL_SEQ_DESC(PMUCAL_WRITE, "GNSS_CTRL_NS", 0x12860000, 0x3890, (0x1 << 7), (0x1 << 7), 0, 0, 0xffffffff, 0),
};

struct pmucal_seq gnss_active_clear[] = {
	PMUCAL_SEQ_DESC(PMUCAL_WRITE, "GNSS_CTRL_NS", 0x12860000, 0x3890, (0x1 << 8), (0x1 << 8), 0, 0, 0xffffffff, 0),
};

struct pmucal_seq gnss_reset_req_clear[] = {
};

struct pmucal_gnss pmucal_gnss_list = {
		.init = gnss_init,
		.status = gnss_status,
		.reset_assert = gnss_reset_assert,
		.reset_release = gnss_reset_release,
		.active_clear = gnss_active_clear,
		.gnss_reset_req_clear = gnss_reset_req_clear,
		.num_init = ARRAY_SIZE(gnss_init),
		.num_status = ARRAY_SIZE(gnss_status),
		.num_reset_assert = ARRAY_SIZE(gnss_reset_assert),
		.num_reset_release = ARRAY_SIZE(gnss_reset_release),
		.num_active_clear = ARRAY_SIZE(gnss_active_clear),
		.num_gnss_reset_req_clear = ARRAY_SIZE(gnss_reset_req_clear),
};
unsigned int pmucal_gnss_list_size = 1;
