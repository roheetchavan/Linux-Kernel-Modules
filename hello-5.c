/*
 * Passing command line arguments to module
 *
 * Note: This can be done using below
 * module_param(name, type, permissions) for passing variable
 * module_param_array(name, type, poiner to count var, permission)
 *			for passing array 
 * Description for each module can be added using MODULE_PARAM_DESC()
 *
 */

#include <linux/module.h>		/* needed by every module */
#include <linux/moduleparam.h>	/* needed by module_param */
#include <linux/kernel.h>		/* needed by pr_info */
#include <linux/init.h>			/* needed by init and exit macros */


MODULE_LICENSE("GPL");
MODULE_AUTHOR("Rohit Chavan");

static short int myshort = 1;
static int myint = 2;
static long mylong = 9999;
static char *mystr = "mystring";
static int myarray[2] = {-1, 1};
static int myargc = 0;

/*
 * module_param(name, type, permission)
 * name : paramter name
 * type : data type
 * permission : bits for exposing parameters in sysfs
 *
 */

module_param(myshort, short, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP);
MODULE_PARM_DESC(myshort, "A short int");

module_param(myint, int, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
MODULE_PARM_DESC(myint, "An integer");

module_param(mylong, long, S_IRUSR);
MODULE_PARM_DESC(mylong, "A long integer");

module_param(mystr, charp, 0000);
MODULE_PARM_DESC(mystr, "A character string");

/*
 * module_param_array(name, type, num, permission)
 * name : parameter name
 * type : data type of array elements
 * num : pointer to variable that store num of elements
 * permission : bits for exposing parameters in sysfs
 *
 */
module_param_array(myarray, int, &myargc, 0000);
MODULE_PARM_DESC(myarray, "An array of intergers");

static __init int initialization(void) {
	int i;
	pr_info("hello-5 Init\n");

	pr_info("myshort : %hd\n", myshort);
	pr_info("myint : %d\n", myint);
	pr_info("mylong : %ld\n", mylong);
	pr_info("mystring : %s\n", mystr);

	for (i = 0; i < (sizeof(myarray)/sizeof(myarray[0])); i++) {
		pr_info("myarray[%d] = %d \n", i , myarray[i]);
	}

	pr_info("Elements in myarray=%d\n", myargc);

	return 0;
	
}

static void __exit cleaningup(void) {
	pr_info("hello-5 Goodbye\n");
}

module_init(initialization);
module_exit(cleaningup);
