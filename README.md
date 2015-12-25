# VSFS
##### very simple file system

---

* Note that the code here can be updated at any time without any notice. 


* The following are the source files here: 
   
   - vsfs.c: You will write your code here. 
   
   - vsfs.h: You should not need to modify this file. This is the interface of the library. Do not change function prototypes defined here. 
   
   - app.c: A sample test application. You can write similar applications. We will write our own applications/test-programs. 
   
   - makedisk.c: This is a program that you can use to create a virtual disk (i.e., a Linux file that of a given size that will act as the storage that your FS will manage and store files). 
   
   - formatdisk.c: This is a program that you can use to format the virtual disk it your file system. Normally, you will not need to modify this C file. You will write a vsfs_format() function in your library. 


* The sequence of steps that you will follow to run an App: 
   
   - Create a virtual disk of certain size using "makedisk" program. 
   
   - Format the disk using the "formatdisk" program. 
   
   - Run an application linked with your library: for example "./app". 
   
   - You can run other applications, or the same application many times. They will use your file system. 
