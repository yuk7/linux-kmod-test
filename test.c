// SPDX-License-Identifier: GPL-2.0-only
/*
 * test.c -- Test kernel module
 * Copyright yuk7
 *
 * Authors: yuk7 <yukx00@gmail.com>
 */


#include <linux/module.h>

static int __init test_init(void)
{
  printk(KERN_WARNING "test_init\n");
  return 0;
}

static void __exit test_exit(void)
{
  printk(KERN_WARNING "test_exit");
}

module_init(test_init);
module_exit(test_exit);

MODULE_DESCRIPTION("Test kernel module");
MODULE_AUTHOR("yuk7 <yukx00@gmail.com>");
MODULE_LICENSE("GPL v2");