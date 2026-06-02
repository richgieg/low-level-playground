#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/device.h>

#define DEVICE_NAME "richard"

struct device *root_dev;

static int __init root_dev_init(void)
{
	pr_info("Registering root device!\n");
	root_dev = root_device_register(DEVICE_NAME);
	return 0;
}

static void __exit root_dev_exit(void)
{
	pr_info("Unregistering root device!\n");
	root_device_unregister(root_dev);
}

module_init(root_dev_init);
module_exit(root_dev_exit);

MODULE_LICENSE("GPL");
