// 
// 	 Enemy Engaged RAH-66 Comanche Versus KA-52 Hokum
// 	 Copyright (C) 2000 Empire Interactive (Europe) Ltd,
// 	 677 High Road, North Finchley, London N12 0DA
// 
// 	 Please see the document LICENSE.TXT for the full licence agreement
// 
// 2. LICENCE
//  2.1 	
//  	Subject to the provisions of this Agreement we now grant to you the 
//  	following rights in respect of the Source Code:
//   2.1.1 
//   	the non-exclusive right to Exploit  the Source Code and Executable 
//   	Code on any medium; and 
//   2.1.2 
//   	the non-exclusive right to create and distribute Derivative Works.
//  2.2 	
//  	Subject to the provisions of this Agreement we now grant you the
// 	following rights in respect of the Object Code:
//   2.2.1 
// 	the non-exclusive right to Exploit the Object Code on the same
// 	terms and conditions set out in clause 3, provided that any
// 	distribution is done so on the terms of this Agreement and is
// 	accompanied by the Source Code and Executable Code (as
// 	applicable).
// 
// 3. GENERAL OBLIGATIONS
//  3.1 
//  	In consideration of the licence granted in clause 2.1 you now agree:
//   3.1.1 
// 	that when you distribute the Source Code or Executable Code or
// 	any Derivative Works to Recipients you will also include the
// 	terms of this Agreement;
//   3.1.2 
// 	that when you make the Source Code, Executable Code or any
// 	Derivative Works ("Materials") available to download, you will
// 	ensure that Recipients must accept the terms of this Agreement
// 	before being allowed to download such Materials;
//   3.1.3 
// 	that by Exploiting the Source Code or Executable Code you may
// 	not impose any further restrictions on a Recipient's subsequent
// 	Exploitation of the Source Code or Executable Code other than
// 	those contained in the terms and conditions of this Agreement;
//   3.1.4 
// 	not (and not to allow any third party) to profit or make any
// 	charge for the Source Code, or Executable Code, any
// 	Exploitation of the Source Code or Executable Code, or for any
// 	Derivative Works;
//   3.1.5 
// 	not to place any restrictions on the operability of the Source 
// 	Code;
//   3.1.6 
// 	to attach prominent notices to any Derivative Works stating
// 	that you have changed the Source Code or Executable Code and to
// 	include the details anddate of such change; and
//   3.1.7 
//   	not to Exploit the Source Code or Executable Code otherwise than
// 	as expressly permitted by  this Agreement.
// 



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

enum CHAR_TYPES
{
	CHAR_TYPE_TAG,
	CHAR_TYPE_VALUE,
	NUM_CHAR_TYPES
};

typedef enum CHAR_TYPES char_types;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define NUM_CHAR_TYPE_PACK_BITS (2)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

struct CHAR_TYPE_DATA
{
	char
		*name;

	int
		debug_pack;
};

typedef struct CHAR_TYPE_DATA char_type_data;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern char_type_data
	char_type_database[NUM_CHAR_TYPES];

#define get_char_type_name(CHAR_TYPE) (char_type_database[(CHAR_TYPE)].name)

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern const char
	*overload_invalid_char_type_message,
	*debug_fatal_invalid_char_type_message;

#ifdef DEBUG

#define validate_char_type(CHAR_TYPE) ((((CHAR_TYPE) >= 0) && ((CHAR_TYPE) < NUM_CHAR_TYPES)) ? ((CHAR_TYPE)) : (process_assert (overload_invalid_char_type_message, __FILE__, __LINE__), 0))

#else

#define validate_char_type(CHAR_TYPE) ((CHAR_TYPE))

#endif

#define debug_fatal_invalid_char_type(EN,CHAR_TYPE) (debug_fatal (debug_fatal_invalid_char_type_message, get_local_entity_type_name ((EN)), get_local_entity_index ((EN)), get_char_type_name ((CHAR_TYPE)), __FILE__, __LINE__))

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern void (*fn_set_local_entity_raw_char_value[NUM_ENTITY_TYPES][NUM_CHAR_TYPES]) (entity *en, char_types type, char value);

#define set_local_entity_raw_char_value(EN,CHAR_TYPE,VALUE) (fn_set_local_entity_raw_char_value[get_local_entity_type ((EN))][validate_char_type ((CHAR_TYPE))] ((EN), (CHAR_TYPE), (VALUE)))

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern void (*fn_set_local_entity_char_value[NUM_ENTITY_TYPES][NUM_CHAR_TYPES]) (entity *en, char_types type, char value);

#define set_local_entity_char_value(EN,CHAR_TYPE,VALUE) (fn_set_local_entity_char_value[get_local_entity_type ((EN))][validate_char_type ((CHAR_TYPE))] ((EN), (CHAR_TYPE), (VALUE)))

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern void (*fn_set_client_server_entity_char_value[NUM_ENTITY_TYPES][NUM_CHAR_TYPES][NUM_COMMS_MODEL_TYPES]) (entity *en, char_types type, char value);

#define set_client_server_entity_char_value(EN,CHAR_TYPE,VALUE) (fn_set_client_server_entity_char_value[get_local_entity_type ((EN))][validate_char_type ((CHAR_TYPE))][get_comms_model ()] ((EN), (CHAR_TYPE), (VALUE)))

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern char (*fn_get_local_entity_char_value[NUM_ENTITY_TYPES][NUM_CHAR_TYPES]) (entity *en, char_types type);

#define get_local_entity_char_value(EN,CHAR_TYPE) (fn_get_local_entity_char_value[get_local_entity_type ((EN))][validate_char_type ((CHAR_TYPE))] ((EN), (CHAR_TYPE)))

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern void initialise_entity_char_value_default_functions (void);

extern void pack_char_value (entity *en, char_types type, char value);

extern char unpack_char_value (entity *en, char_types type);

extern void pack_char_type (char_types type);

extern char_types unpack_char_type (void);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
