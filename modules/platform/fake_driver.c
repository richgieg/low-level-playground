#include <linux/module.h>
#include <linux/platform_device.h>

static int fake_probe(struct platform_device *pdev)
{
	pr_info("fake_driver: probe called for device\n");
	return 0;
}

static void fake_remove(struct platform_device *pdev)
{
	pr_info("fake_driver: remove called\n");
}

static struct platform_driver fake_driver = {
	.driver = {
		.name = "fake_device",
	},
	.probe = fake_probe,
	.remove = fake_remove,
};

static int __init fake_driver_init(void)
{
	pr_info("fake_driver: init\n");
	return platform_driver_register(&fake_driver);
}

static void __exit fake_driver_exit(void)
{
	platform_driver_unregister(&fake_driver);
	pr_info("fake_driver: exit\n");
}

module_init(fake_driver_init);
module_exit(fake_driver_exit);

MODULE_LICENSE("GPL");
