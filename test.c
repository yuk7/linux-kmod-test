// SPDX-License-Identifier: GPL-2.0-only
/*
 * test.c -- Test kernel module
 * Copyright yuk7
 *
 * Authors: yuk7 <yukx00@gmail.com>
 */


#include <linux/module.h>
#include <linux/device.h>
#include <linux/kernel.h>
#include <linux/fs.h>

#define DRIVER_NAME "test_drv"
#define DRIVER_MAJOR 0

static int testdev_open(struct inode *inode, struct file *file)
{
    printk(KERN_WARNING "testdev_open\n");
    return 0;
}

static ssize_t testdev_read(struct file *file, char __user *buf, size_t count, loff_t *offset)
{
    printk(KERN_WARNING "testdev_read\n");
    return 0;
}

static ssize_t testdev_write(struct file *file, const char __user *buf, size_t count, loff_t *offset)
{
    printk(KERN_WARNING "testdev_write\n");
    return 0;
}

static int testdev_release(struct inode *inode, struct file *file)
{
    printk(KERN_WARNING "testdev_release\n");
    return 0;
}

static const struct file_operations testdev_fops = {
    .open    = testdev_open,
    .read    = testdev_read,
    .write   = testdev_write,
    .release = testdev_release
};

static int __init test_init(void)
{
  int ret;
  printk(KERN_WARNING "module_exit called by insmod\n");
  printk(KERN_INFO "Hello test module\n");
  printk(KERN_DEBUG "debug message\n");
  printk(KERN_WARNING "test_init\n");

  ret = register_chrdev(DRIVER_MAJOR, DRIVER_NAME, &testdev_fops);
  printk(KERN_WARNING "register_chrdev returns: %d\n", ret);
  return 0;
}

static void __exit test_exit(void)
{
  printk(KERN_WARNING "module_exit called by rmmod\n");
  printk(KERN_INFO "Goodbye test module\n");
  printk(KERN_INFO "test_exit");
  //unregister_chrdev(DRIVER_MAJOR, DRIVER_NAME);
}

module_init(test_init);
module_exit(test_exit);

MODULE_DESCRIPTION("Test kernel module");
MODULE_AUTHOR("yuk7 <yukx00@gmail.com>");
MODULE_LICENSE("GPL v2");
