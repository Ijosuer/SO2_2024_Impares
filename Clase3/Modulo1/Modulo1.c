#include <linux/module.h>    // Necesario para modulos
#include <linux/kernel.h>    // Necesario para KERN_INFO 
#include <linux/init.h>      // Necesario para macros

MODULE_LICENSE("GPL");
MODULE_DESCRIPTION("Sistemas Operativos 2 -  Clase 3");
MODULE_AUTHOR("Josue Gramajo");

static int __init _insert(void){
    printk(KERN_INFO "Hola mundo! \n");
    return 0;
}

static void __exit _remove(void){
    printk(KERN_INFO "Goodbye\n");
}

module_init(_insert)
module_exit(_remove)