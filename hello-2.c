/*
 * Preffered way over init() and cleanup()
 * Note: You can create own named init and exit functions for module.
 */
 
 #include <linux/module.h>          /* required by each module */
 #include <linux/kernel.h>          /* required for pr_info */
 #include <linux/init.h>            /* required for module_init() and module_exit() */

 MODULE_LICENSE("GPL");

 static int my_init(void) {
     pr_info("hello-2 my_init()\n");

     /* Non zero return value means module doesn't loaded properly */
     return 0;
 }

 void my_cleanup(void) {
     pr_info("hello-2 my_exit()\n");
 }

 module_init(my_init);
 module_exit(my_cleanup);
