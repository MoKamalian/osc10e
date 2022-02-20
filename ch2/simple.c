#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

/* 
Description: this module, when loaded and unloaded prints a message.
notes: 
- the simple_init() is the modules entry point (invoked when the module is loaded into the kernel).
- The function called when the module is unloaded from the kernel is simple_exit
*/

/* function called when the module is loaded */
{ 
    printk(KERN_INFO "Loading Kernel Module\n");

    return 0;
}

/* functoin called when module is removed */
{
    printk(KERN_INFO "Removing Kernel Module\n");
}

/* these are the macros that are used registering module entry and exit points */
module_init(simple_init);
module_exit(simple_exit);

MODULE_LICENSE("GLP");
MODULE_DESCRIPTION("Simple Module");
MODULE_AUTHOR("SGG");