#ifndef CMDSCREEN_INTERN_CSMEMAREA_H
#define CMDSCREEN_INTERN_CSMEMAREA_H

#include "clingo/lang/slice.h"

/*******************************************************************************
********************************************************* Types and Definitions
*******************************************************************************/

#define csAREA_SIZE_ 8
#define csBLOCK_SIZE_ 100*cKib_

struct csMemBlock
{
   int64_t pos;
   int64_t space;
   void* mem;
};
typedef struct csMemBlock csMemBlock;

struct csMemArea
{
   int64_t s;
   csMemBlock* v;
   int64_t cap;
};
typedef struct csMemArea csMemArea;

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

bool init_mem_area_cs( csMemArea area[static 1], int64_t size );

void cleanup_mem_area_cs( csMemArea area[static 1] );

int64_t count_area_mem_cs( csMemArea const area[static 1] );

#define area_alloc_cs_( Area, Type )                                           \
   area_alloc_cs( (Area), sizeof_c_( Type ) )
void* area_alloc_cs( csMemArea area[static 1], int64_t size );

#define area_alloc_array_cs_( Area, Number, Type )                             \
   area_alloc_array_cs( (Area), (Number), sizeof_c_( Type ) )
void* area_alloc_array_cs( csMemArea area[static 1], int64_t num, int64_t size );

void reset_mem_area_cs( csMemArea area[static 1] );

/*******************************************************************************

*******************************************************************************/

#define heap_mem_block_cs_( Size )                                             \
(                                                                              \
   (csMemBlock)                                                                \
   { .pos=0, .space=(Size), .mem=alloc_c(Size) }                               \
)

int64_t mem_block_cap_cs( csMemBlock const block[static 1] );

#define block_alloc_cs_( Block, Type )                                         \
   block_alloc_cs( (Block), sizeof_c_( Type ) )
void* block_alloc_cs( csMemBlock block[static 1], int64_t size );

#define block_alloc_array_cs_( Block, Number, Type )                           \
   block_alloc_array_cs( (Block), (Number), sizeof_c_( Type ) )
void* block_alloc_array_cs( csMemBlock block[static 1],
                            int64_t num,
                            int64_t size );

void free_mem_block_cs( csMemBlock block[static 1] );

void reset_mem_block_cs( csMemBlock block[static 1] );

#endif