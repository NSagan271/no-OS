#include <stdlib.h>
#include "error.h"
#include "jesd204.h"
#include "jesd204-priv.h"

int jesd204_dev_register(struct jesd204_dev **jdev, struct jesd204_dev_data *data)
{
	struct jesd204_dev *pjdev;
	static int id = 0;

	if (jdev == NULL)
		return -EINVAL;

	pjdev = calloc(1, sizeof(struct jesd204_dev));
	if (!pjdev)
		return -ENOMEM;

	pjdev->dev_data = data;
	pjdev->id = id++;

	*jdev = pjdev;
	
	return 0;
}