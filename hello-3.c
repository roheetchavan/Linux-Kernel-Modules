/*
 * __init and __exit macros
 * 
 * Description: Useful for built in modules. 
 * __init : Discards the init function and frees 
 * its memory after module loading.
 * __exit :  Omits cleanup function for built in modules.
 * __init_data : used similarly but for variables.
 * 
 * Note: Don't have any impacts as above for loadable modules
 * 
 */

#include <linux/module.h>          /* needed for every module */
#include <linux/kernel.h>           /* needed for pr_info */
#include <linux/init.h>             /* needed for init exit macros */

MODULE_LICENSE("GPL");

static int __init my_init(void) {
    pr_info("hello-3 my_init()\n");

    return 0;
}

void __exit my_exit(void) {
    pr_info("hello-3 my_exit()\n");
}

module_init(my_init);
module_exit(my_exit);
