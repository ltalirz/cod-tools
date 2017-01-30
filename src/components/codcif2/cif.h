/*---------------------------------------------------------------------------*\
**$Author$
**$Date$ 
**$Revision$
**$URL$
\*---------------------------------------------------------------------------*/

#ifndef __CIF_H
#define __CIF_H

#include <stdlib.h>
#include <stdarg.h>
#include <datablock.h>
#include <cifmessage.h>
#include <cexceptions.h>

typedef struct CIF CIF;

typedef enum {
    CIF_UNKNOWN = 0,
    CIF_INT,
    CIF_FLOAT,
    CIF_UQSTRING,
    CIF_SQSTRING,
    CIF_DQSTRING,
    CIF_TEXT,
    CIF_LIST,
    last_CIF_VALUE
} cif_value_type_t;

typedef enum {
  CIF_OK = 0,
  CIF_UNRECOVERABLE_ERROR,
  CIF_COMPILATION_ERROR,
  CIF_NO_DATABLOCK_ERROR,
  CIF_OUT_OF_MEMORY_ERROR,

  last_CIF_ERROR
} cif_error_t;

extern void *cif_subsystem;

void cif_debug_on( void );
void cif_debug_off( void );
int cif_debug_is_on( void );

CIF *new_cif( cexception_t *ex );

void delete_cif( CIF *bc );

void create_cif( CIF * volatile *cif, cexception_t *ex );

void dispose_cif( CIF * volatile *cif );

CIFMESSAGE *cif_messages( CIF *cif );
CIFMESSAGE *cif_insert_message( CIF *cif, CIFMESSAGE *message );

void cif_start_datablock( CIF * volatile cif, const char *name,
                          cexception_t *ex );

void cif_start_save_frame( CIF * volatile cif, const char *name,
                          cexception_t *ex );

void cif_finish_save_frame( CIF * volatile cif );

void cif_dump( CIF * volatile cif );
void cif_print( CIF * volatile cif );
void cif_list_tags( CIF * volatile cif );
ssize_t cif_tag_index( CIF * cif, char *tag );

void cif_insert_value( CIF * cif, char *tag,
                       char *value, datablock_value_type_t vtype,
                       cexception_t *ex );
void cif_overwrite_value( CIF * cif, ssize_t tag_nr, ssize_t val_nr,
                          char *value, datablock_value_type_t vtype,
                          cexception_t *ex );

void cif_start_loop( CIF *cif, cexception_t *ex );
void cif_finish_loop( CIF *cif, cexception_t *ex );

void cif_push_loop_value( CIF * cif, char *value, datablock_value_type_t vtype,
                          cexception_t *ex );

void cif_set_nerrors( CIF *cif, int nerrors );
int cif_nerrors( CIF *cif );

DATABLOCK * cif_datablock_list( CIF *cif );
DATABLOCK * cif_last_datablock( CIF *cif );

void cif_print_tag_values( CIF *cif, char ** tagnames, int tagcount,
    char * volatile prefix, int append_blkname, char * separator,
    char * vseparator );

void cif_revert_message_list( CIF *cif );

void cif_set_yyretval( CIF *cif, int yyretval );
int cif_yyretval( CIF *cif );

void cif_set_message( CIF *cif,
                      const char *filename,
                      const char *errlevel,
                      const char *message,
                      const char *syserror,
                      cexception_t *ex );

#endif
