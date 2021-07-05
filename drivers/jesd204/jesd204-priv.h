#ifndef _JESD204_PRIV_H_
#define _JESD204_PRIV_H_

#include "jesd204.h"
#include "device-states.h"

#define JESD204_MAX_LINKS		16

struct jesd204_dev;
struct jesd204_dev_top;
struct jesd204_link_opaque;
struct jesd204_dev_con_out;
struct jesd204_fsm_data;

#define JESD204_STATE_FSM_OFFSET	100

#define JESD204_STATE_ENUM(x)	\
	JESD204_STATE_##x = (JESD204_FSM_STATE_##x + JESD204_STATE_FSM_OFFSET)

enum jesd204_dev_state {
	JESD204_STATE_UNINIT = 0,
	JESD204_STATE_INITIALIZED,
	JESD204_STATE_PROBED,
	JESD204_STATE_IDLE,
	JESD204_STATE_ENUM(DEVICE_INIT),
	JESD204_STATE_ENUM(LINK_INIT),
	JESD204_STATE_ENUM(LINK_SUPPORTED),
	JESD204_STATE_ENUM(LINK_PRE_SETUP),
	JESD204_STATE_ENUM(CLK_SYNC_STAGE1),
	JESD204_STATE_ENUM(CLK_SYNC_STAGE2),
	JESD204_STATE_ENUM(CLK_SYNC_STAGE3),
	JESD204_STATE_ENUM(LINK_SETUP),
	JESD204_STATE_ENUM(OPT_SETUP_STAGE1),
	JESD204_STATE_ENUM(OPT_SETUP_STAGE2),
	JESD204_STATE_ENUM(OPT_SETUP_STAGE3),
	JESD204_STATE_ENUM(OPT_SETUP_STAGE4),
	JESD204_STATE_ENUM(OPT_SETUP_STAGE5),
	JESD204_STATE_ENUM(CLOCKS_ENABLE),
	JESD204_STATE_ENUM(LINK_ENABLE),
	JESD204_STATE_ENUM(LINK_RUNNING),
	JESD204_STATE_ENUM(OPT_POST_RUNNING_STAGE),
	JESD204_STATE_DONT_CARE = 999,
};

struct jesd204_dev {
	//struct device			dev;
	const struct jesd204_dev_data	*dev_data;
	int				id;
	//struct list_head		entry;
	void				*priv;

	bool				fsm_inited;
	bool				is_top;

	bool				is_sysref_provider;
	bool				is_sec_sysref_provider;
	bool				stop_states[JESD204_FSM_STATES_NUM + 1];

	//struct device_node		*np;

	//struct attribute_group		sysfs_attr_group;

	//struct jesd204_dev_con_out	**inputs;
	//unsigned int			inputs_count;
	//struct list_head		outputs;
	//unsigned int			outputs_count;
};

#endif