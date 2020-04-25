
/*
 *  Simple kernel module
 */

 #include <linux/module.h>          /* Needed by all modules */
 #include <linux/kernel.h>          /* Needed for pr_info*/

 int init_module(void) {
    pr_info("Hello world-1\n");

    /* Non zero return means module is not loaded successfully */
    return 0;
 }

 void cleanup_module(void) {
     pr_info("Goodbye world-1\n");
 }
 MODULE_LICENSE("GPL");
