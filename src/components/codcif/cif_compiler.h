/*-------------------------------------------------------------------------*\
* $Author$
* $Date$ 
* $Revision$
* $URL$
\*-------------------------------------------------------------------------*/

#ifndef __CIF_COMPILER_H
#define __CIF_COMPILER_H

#include <assert.h>
#include <allocx.h>
#include <stringx.h>
#include <cexceptions.h>
#include <cif_options.h>
#include <cif.h>
#include <value.h>

typedef struct CIF_COMPILER CIF_COMPILER;

CIF_COMPILER *new_cif_compiler( char *filename,
                                       cif_option_t co,
                                       cexception_t *ex );

void delete_cif_compiler( CIF_COMPILER *c );

CIF *cif_compiler_cif( CIF_COMPILER *ccc );

void assert_datablock_exists( CIF_COMPILER *ccc, cexception_t *ex );

int isset_do_not_unprefix_text( CIF_COMPILER *co );
int isset_do_not_unfold_text( CIF_COMPILER *co );
int isset_fix_errors( CIF_COMPILER *co );
int isset_fix_duplicate_tags_with_same_values( CIF_COMPILER *co );
int isset_fix_duplicate_tags_with_empty_values( CIF_COMPILER *co );
int isset_fix_data_header( CIF_COMPILER *co );
int isset_fix_datablock_names( CIF_COMPILER *co );
int isset_fix_string_quotes( CIF_COMPILER *co );
int isset_suppress_messages( CIF_COMPILER *co );

typedef struct typed_value typed_value;

typed_value *new_typed_value( int vline, int vpos, char *vcont, VALUE *v );

void delete_typed_value( typed_value *t );

int typed_value_line( typed_value *t );
int typed_value_pos( typed_value *t );
char *typed_value_content( typed_value *t );
VALUE *typed_value_value( typed_value *t );
void typed_value_detach_value( typed_value *t );

#endif
