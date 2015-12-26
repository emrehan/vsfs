#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#include "vsfs.h"

#define BLOCKSIZE       4096 // bytes
#define MAXFILECOUNT    128 // max number of files that FS can support
#define MAXDISKSIZE     (1<<28) // 256MB - max size FS can support
#define MINDISKSIZE     (1<<20) // 1MB - min size FS need
#define MAXFILENAMESIZE 128 // characters - max characters FS can support for file names
#define MAXBLOCKCOUNT   (MAXDISKSIZE / BLOCKSIZE)
#define MAXOPENFILES    128 // files
#define MAXREADWRITE    1024 // bytes; max read/write amount

// Global Variables
char disk_name[128];   // name of virtual disk file
int  disk_size;        // size in bytes - a power of 2
int  disk_fd;          // disk file handle
int  disk_blockcount;  // block count on disk


/*
   Reads block blocknum into buffer buf.
   You will not modify the getblock() function.
   Returns -1 if error. Should not happen.
*/
int getblock (int blocknum, void *buf)
{
    int offset, n;

    if (blocknum >= disk_blockcount)
        return (-1); //error

    offset = lseek (disk_fd, blocknum * BLOCKSIZE, SEEK_SET);
    if (offset == -1) {
        printf ("lseek error\n");
        exit(0);

    }

    n = read (disk_fd, buf, BLOCKSIZE);
    if (n != BLOCKSIZE)
        return (-1);

    return (0);
}


/*
    Puts buffer buf into block blocknum.
    You will not modify the putblock() function
    Returns -1 if error. Should not happen.
*/
int putblock (int blocknum, void *buf)
{
    int offset, n;

    if (blocknum >= disk_blockcount)
        return (-1); //error

    offset = lseek (disk_fd, blocknum * BLOCKSIZE, SEEK_SET);
    if (offset == -1) {
        printf ("lseek error\n");
        exit (1);
    }


    n = write (disk_fd, buf, BLOCKSIZE);
    if (n != BLOCKSIZE)
        return (-1);

    return (0);
}




/*
   IMPLEMENT THE FUNCTIONS BELOW - You can implement additional
   internal functions.
 */



/* format disk of size dsize */
int vsfs_format(char *vdisk, int dsize)
{
    strcpy (disk_name, vdisk);
    disk_size = dsize;
    disk_blockcount = disk_size / BLOCKSIZE;

    disk_fd = open (disk_name, O_RDWR);
    if (disk_fd == -1) {
        printf ("disk open error %s\n", vdisk);
        exit(1);
    }

    // perform your format operations here.
    printf ("formatting disk=%s, size=%d\n", vdisk, disk_size);

    fsync (disk_fd);
    close (disk_fd);

    return (0);
}


/*
   Mount disk and its file system. This is not the same mount
   operation we use for real file systems:  in that the new filesystem
   is attached to a mount point in the default file system. Here we do
   not do that. We just prepare the file system in the disk to be used
   by the application. For example, we get FAT into memory, initialize
   an open file table, get superblock into into memory, etc.
*/
int vsfs_mount (char *vdisk)
{
    struct stat finfo;

    strcpy (disk_name, vdisk);
    disk_fd = open (disk_name, O_RDWR);
    if (disk_fd == -1) {
        printf ("vsfs_mount: disk open error %s\n", disk_name);
        exit(1);
    }

    fstat (disk_fd, &finfo);

    printf ("vsfs_mount: mounting %s, size=%d\n", disk_name,
        (int) finfo.st_size);
    disk_size = (int) finfo.st_size;
    disk_blockcount = disk_size / BLOCKSIZE;

    // perform your mount operations here

    // write your code


    /* you can place these returns wherever you want. Below
       we put them at the end of functions so that compiler will not
       complain.
        */
    return (0);
}


int vsfs_umount()
{
    // perform your unmount operations here

    // write your code

    fsync (disk_fd);
    close (disk_fd);
    return (0);
}


/* create a file with name filename */
int vsfs_create(char *filename)
{

    // write your code

    return (0);
}


/* open file filename */
int vsfs_open(char *filename)
{
    int index = -1;

    // write your code

    return (index);
}

/* close file filename */
int vsfs_close(int fd)
{

    // write your code

    return (0);
}

int vsfs_delete(char *filename)
{

    // write your code

    return (0);
}

int vsfs_read(int fd, void *buf, int n)
{
    int bytes_read = -1;

    // write your code

    return (bytes_read);

}

int vsfs_write(int fd, void *buf, int n)
{
    int bytes_written = -1;

    // write your code

    return (bytes_written);
}

int vsfs_truncate(int fd, int size)
{

    // write your code

    return (0);
}


int vsfs_seek(int fd, int offset)
{
    int position = -1;

    // write your code

    return (position);
}

int vsfs_filesize (int fd)
{
    int size = -1;

    // write your code

    return (size);
}


void vsfs_print_dir ()
{

    // write your code

}


void vsfs_print_fat ()
{

    // write your code

}
