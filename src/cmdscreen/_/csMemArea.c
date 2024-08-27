#include "csMemArea.h"

#include "clingo/container/pile.h"
#include "clingo/lang/math.h"

static inline REALLOC_PILE_C_(
   realloc_area,  // FuncName
   csMemArea,     // PileType
   csMemBlock     // Type
)

static inline PUT_C_( 
   put_block_on_area,   // FuncName
   csMemArea,           // PileType
   csMemBlock,          // ParaType
   do_not_deref_c_,     // DoDeref
   realloc_area         // ReallocFunc
)

/*******************************************************************************
********************************************************************* Functions
********************************************************************************

*******************************************************************************/

bool init_mem_area_cs( csMemArea area[static 1], int64_t size )
{
   csMemBlock* blocks = alloc_array_c_( csAREA_SIZE_, csMemBlock );
   if ( blocks == NULL )
   {
      return false;
   }

   csMemBlock block = heap_mem_block_cs_( size );
   if ( block.mem == NULL )
   {
      free( blocks );
      return false;
   }

   blocks[0] = block;

   area->s = 1;
   area->v = blocks;
   area->cap = 8;
   return true;
}

void cleanup_mem_area_cs( csMemArea area[static 1] )
{
   if ( area->v == NULL )
   {
      return;
   }

   each_c_( csMemBlock*, block, *area )
   {
      free_mem_block_cs( block );
   }
   free( area->v );
   area->s = 0;
   area->v = NULL;
   area->cap = 0;
}

int64_t mem_area_cap_cs( csMemArea const area[static 1] )
{
   int64_t res = 0;
   each_c_( csMemBlock const*, block, *area )
   {
      res += mem_block_cap_cs( block );
   }
   return res;
}

int64_t count_area_mem_cs( csMemArea const area[static 1] )
{
   int64_t res = 0;
   each_c_( csMemBlock const*, block, *area )
   {
      res += block->pos;
   }
   return res;
}

static inline bool grow_area( csMemArea area[static 1], int64_t size )
{
   int64_t baseNewSize = csBLOCK_SIZE_;
   if ( area->s > 0 )
   {
      csMemBlock last = last_c_( *area );
      baseNewSize = max_c_( baseNewSize, mem_block_cap_cs( &last ) );
   }

   csMemBlock block = heap_mem_block_cs_( baseNewSize );
   if ( block.mem == NULL )
   {
      return false;
   }
   if ( not put_block_on_area( area, block ) )
   {
      free( block.mem );
      return false;
   }

   return true;
}

void* area_alloc_cs( csMemArea area[static 1], int64_t size )
{
   must_be_positive_c_( size );

   each_c_( csMemBlock*, block, *area )
   {
      void* res = block_alloc_cs( block, size );
      if ( res != NULL )
      {
         return res;
      }
   }

   int64_t const i = area->s;
   if ( not grow_area( area, size ) )
   {
      return NULL;
   }

   return block_alloc_cs( &area->v[i], size );
}

void* area_alloc_array_cs( csMemArea area[static 1], int64_t num, int64_t size )
{
   must_be_positive_c_( num );
   must_be_positive_c_( size );

   int64_t fullSize = 0;
   if ( not imul64_c( num, size, &fullSize ) )
   {
      return NULL;
   }

   return area_alloc_cs( area, fullSize );
}

void reset_mem_area_cs( csMemArea area[static 1] )
{
   each_c_( csMemBlock*, block, *area )
   {
      reset_mem_block_cs( block );
   }
}

/*******************************************************************************

*******************************************************************************/

int64_t mem_block_cap_cs( csMemBlock const block[static 1] )
{
   return block->pos + block->space;
}

void* block_alloc_cs( csMemBlock block[static 1], int64_t size )
{
   must_be_positive_c_( size );

   if ( block->space < size )
   {
      return NULL;
   }

   void* res = block->mem;
   block->pos += size;
   block->space -= size;
   block->mem += size;
   return res;
}

void* block_alloc_array_cs( csMemBlock block[static 1],
                            int64_t num,
                            int64_t size )
{
   must_be_positive_c_( num );
   must_be_positive_c_( size );

   int64_t fullSize = 0;
   if ( not imul64_c( num, size, &fullSize ) )
   {
      return NULL;
   }

   return alloc_c( fullSize );
}

void free_mem_block_cs( csMemBlock block[static 1] )
{
   reset_mem_block_cs( block );
   free( block->mem );
}

void reset_mem_block_cs( csMemBlock block[static 1] )
{
   int64_t const offset = block->pos;
   block->pos -= offset;
   block->space += offset;
   block->mem -= offset;
}