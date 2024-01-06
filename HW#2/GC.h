// GC.h

#ifndef GC_H
#define GC_H

typedef int bool;
enum {FALSE = -1, TRUE};

#define COMP_NAME_LEN 51
#define str_MAX		  256

#define FIRST_FILE_NAME  "Com_names1.txt"
#define SECOND_FILE_NAME "Com_names2.txt"
#define PRINT_FILE_NAME	 "SeqData.txt"

#define CAPACITY_ORDER 2
#define REC_NUM		   (CAPACITY_ORDER * 2)
#define PTR_NUM		   (REC_NUM + 1)

#endif	// GC_H
