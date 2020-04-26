/*
 * Adding Module Description.
 * 
 */

#include <linux/module.h>           /* Needed by every module */
#include <linux/kernel.h>           /* Needed for pr_info */
#include <linux/init.h>             /* Needed for init and exit macros */

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rohit Chavan");
MODULE_DESCRIPTION("Adding description to module");
MODULE_SUPPORTED_DEVICE("test device");

static int __init start(void) {
    pr_info("hello-4 init()\n");

    return 0;
}

void __exit stop(void) {
    pr_info("hello-4 exit()\n");
}

module_init(start);
module_exit(stop);