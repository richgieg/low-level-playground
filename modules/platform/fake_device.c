#include <linux/module.h>
#include <linux/platform_device.h>

static struct platform_device *fake_device;

static int __init fake_device_init(void)
{
	fake_device = platform_device_register_simple(
		"fake_device", 0, NULL, 0);

	if (IS_ERR(fake_device))
		return PTR_ERR(fake_device);

	pr_info("fake_device: registered\n");
	return 0;
}

static void __exit fake_device_exit(void)
{
	platform_device_unregister(fake_device);
	pr_info("fake_device: unregistered\n");
}

module_init(fake_device_init);
module_exit(fake_device_exit);

MODULE_LICENSE("GPL");
