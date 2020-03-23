#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/init_task.h>
#include <linux/syscalls.h>
#include <linux/module.h>
#include <linux/proc_fs.h>
#include <linux/time.h>
#define for_each_process(p) \
    for (p = &init_task ; (p = next_task(p)) != &init_task ; )
#define task_pid_nr(tsk) ((tsk)->pid)

asmlinkage long sys_prosys(void){
    long count=0,count1=0,count2=0,count3=0,count4=0,count5=0;
    struct task_struct *p;
    long int get_time;
    struct timeval tv;
    
	for_each_process(p){
        if((p->state)==-1){
            printk("unrunnable process %s\t[%d]\t\n",p->comm,task_pid_nr(p));
            count++;
        }
    }
    for_each_process(p){
        if((p->state)==0){
            printk("running process %s\t[%d]\t\n",p->comm,task_pid_nr(p));
            count1++;
        }
    }
    for_each_process(p){
        if((p->state)>=1){
            printk("terminated process %s\t[%d]\t\n",p->comm,task_pid_nr(p));
            count2++;
        }
    }
	for_each_process(p){
        if((p->prio)<120){
            printk("low priority process %s\t[%d]\t\n",p->comm,task_pid_nr(p));
            count3++;
        }
	}
    
    for_each_process(p){
        if((p->prio)==120){
            printk("standard priority process %s\t[%d]\t\n",p->comm,task_pid_nr(p));
            count4++;
        }
    }
    for_each_process(p){
        if((p->prio)>120){
            printk("high priority process %s\t[%d]\t\n",p->comm,task_pid_nr(p));
            count5++;
        }
     }
    printk("no of process which are unrunnable are %ld\n",count); 
    printk("no of process which are runnable are %ld\n",count1);
    printk("no of process which are terminated are %ld\n",count2);
    printk("no of low priority processes are %ld\n",count3); 
    printk("no of standard priority processes are %ld\n",count4);
    printk("no of high priority processes are %ld\n",count5);
    do_gettimeofday(&tv);
    get_time = tv.tv_sec;
    
    printk("Time: %ld\n",get_time);
    return 0;
}
