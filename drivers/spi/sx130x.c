#include <linux/module.h>

static int __init sx130x_init(void)
{
	pr_info("Hello!\n");
	return 0;
}
module_init(sx130x_init);

static void __exit sx130x_exit(void)
{
	pr_info("Goodbye!\n");
}
module_exit(sx130x_exit);

MODULE_LICENSE("GPL");
