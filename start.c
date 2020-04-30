/*
 *  Multifile modules
 *
 */

#include <linux/module.h>       /* Needed by every module */
#include <linux/kernel.h>       /* Needed by pr_info */
#include <linux/init.h>         /* Needed by init and exit macros */

MODULE_LICENSE("GPL");

static int __init start(void) {
    pr_info("Hello world. This is from start.c\n");

    return 0;
}

module_init(start);