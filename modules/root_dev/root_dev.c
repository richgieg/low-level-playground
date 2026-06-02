#include <linux/module.h>
#include <linux/device.h>

#define DEVICE_NAME "richard"

static struct device *root_dev;
static unsigned int bird_val = 0;

static ssize_t dog_show(struct device *dev, struct device_attribute *attr,
			char *buf)
{
	return sysfs_emit(buf, "%s\n", "woof");
}

static ssize_t cat_store(struct device *dev, struct device_attribute *attr,
			 const char *buf, size_t count)
{
	pr_info("count=%zu strlen=%zu\n", count, strlen(buf));
	return count;
}

static ssize_t bird_show(struct device *dev, struct device_attribute *attr,
			 char *buf)
{
	return sysfs_emit(buf, "%u\n", bird_val);
}

static ssize_t bird_store(struct device *dev, struct device_attribute *attr,
			  const char *buf, size_t count)
{
	if (kstrtouint(buf, 10, &bird_val))
		return -EINVAL;
	return count;
}

static struct device_attribute attributes[] = {
	__ATTR_RO(dog),
	__ATTR_WO(cat),
	__ATTR_RW(bird)
};

static void root_dev_sysfs_init(void)
{
	unsigned int i;
	for (i = 0; i < ARRAY_SIZE(attributes); i++)
		device_create_file(root_dev, &attributes[i]);
}

static void root_dev_sysfs_exit(void)
{
	unsigned int i;
	for (i = 0; i < ARRAY_SIZE(attributes); i++)
		device_remove_file(root_dev, &attributes[i]);
}

static int __init root_dev_init(void)
{
	pr_info("Registering root device!\n");
	root_dev = root_device_register(DEVICE_NAME);
	root_dev_sysfs_init();
	return 0;
}

static void __exit root_dev_exit(void)
{
	pr_info("Unregistering root device!\n");
	root_dev_sysfs_exit();
	root_device_unregister(root_dev);
}

module_init(root_dev_init);
module_exit(root_dev_exit);

MODULE_LICENSE("GPL");
