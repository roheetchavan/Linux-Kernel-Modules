/*
 *  Multifile modules
 *
 */

#include <linux/module.h>       /* Needed by every module */
#include <linux/kernel.h>       /* Needed by pr_info */
#include <linux/init.h>         /* Needed by init and exit macros */

MODULE_LICENSE("GPL");

static void __exit stop(void) {
    pr_info("Goodbye world. This is from stop.c\n");
}

module_exit(stop);