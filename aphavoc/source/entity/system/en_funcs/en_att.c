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

#include "project.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#define DEBUG_MODULE 0

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void (*fn_set_local_entity_raw_attitude_matrix[NUM_ENTITY_TYPES]) (entity *en, matrix3x3 attitude);

void (*fn_set_local_entity_attitude_matrix[NUM_ENTITY_TYPES]) (entity *en, matrix3x3 attitude);

void (*fn_set_client_server_entity_attitude_matrix[NUM_ENTITY_TYPES][NUM_COMMS_MODEL_TYPES]) (entity *en, matrix3x3 attitude);

void (*fn_get_local_entity_attitude_matrix[NUM_ENTITY_TYPES]) (entity *en, matrix3x3 attitude);

matrix3x3 *(*fn_get_local_entity_attitude_matrix_ptr[NUM_ENTITY_TYPES]) (entity *en);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void (*fn_set_local_entity_raw_attitude_angles[NUM_ENTITY_TYPES]) (entity *en, float heading, float pitch, float roll);

void (*fn_set_local_entity_attitude_angles[NUM_ENTITY_TYPES]) (entity *en, float heading, float pitch, float roll);

void (*fn_set_client_server_entity_attitude_angles[NUM_ENTITY_TYPES][NUM_COMMS_MODEL_TYPES]) (entity *en, float heading, float pitch, float roll);

void (*fn_get_local_entity_attitude_angles[NUM_ENTITY_TYPES]) (entity *en, float *heading, float *pitch, float *roll);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void default_set_entity_attitude_matrix (entity *en, matrix3x3 attitude)
{
	ASSERT (attitude);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void default_get_entity_attitude_matrix (entity *en, matrix3x3 attitude)
{
	ASSERT (attitude);

	get_identity_matrix3x3 (attitude);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static matrix3x3 *default_get_entity_attitude_matrix_ptr (entity *en)
{
	return (NULL);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void default_set_entity_attitude_angles (entity *en, float heading, float pitch, float roll)
{
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void default_get_entity_attitude_angles (entity *en, float *heading, float *pitch, float *roll)
{
	ASSERT (heading);

	ASSERT (pitch);

	ASSERT (roll);

	*heading = 0.0;

	*pitch = 0.0;

	*roll = 0.0;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialise_entity_attitude_default_functions (void)
{
	int
		i;

	for (i = 0; i < NUM_ENTITY_TYPES; i++)
	{
		//
		// matrix
		//

		fn_set_local_entity_raw_attitude_matrix[i]									= default_set_entity_attitude_matrix;

		fn_set_local_entity_attitude_matrix[i]											= default_set_entity_attitude_matrix;

		fn_set_client_server_entity_attitude_matrix[i][COMMS_MODEL_SERVER]	= default_set_entity_attitude_matrix;

		fn_set_client_server_entity_attitude_matrix[i][COMMS_MODEL_CLIENT]	= default_set_entity_attitude_matrix;

		fn_get_local_entity_attitude_matrix[i]					  						= default_get_entity_attitude_matrix;

		fn_get_local_entity_attitude_matrix_ptr[i]									= default_get_entity_attitude_matrix_ptr;

		//
		// angles
		//

		fn_set_local_entity_raw_attitude_angles[i]	  								= default_set_entity_attitude_angles;

		fn_set_local_entity_attitude_angles[i]											= default_set_entity_attitude_angles;

		fn_set_client_server_entity_attitude_angles[i][COMMS_MODEL_SERVER]	= default_set_entity_attitude_angles;

		fn_set_client_server_entity_attitude_angles[i][COMMS_MODEL_CLIENT]	= default_set_entity_attitude_angles;

		fn_get_local_entity_attitude_angles[i]					  						= default_get_entity_attitude_angles;
	}
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void pack_attitude_matrix (entity *en, matrix3x3 attitude)
{
	float
		heading,
		pitch,
		roll;

	ASSERT (attitude);

	heading = get_heading_from_attitude_matrix (attitude);

	pack_float_value (en, FLOAT_TYPE_HEADING, heading);

	pitch = get_pitch_from_attitude_matrix (attitude);

	pack_float_value (en, FLOAT_TYPE_PITCH, pitch);

	roll = get_roll_from_attitude_matrix (attitude);

	pack_float_value (en, FLOAT_TYPE_ROLL, roll);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void unpack_attitude_matrix (entity *en, matrix3x3 attitude)
{
	float
		heading,
		pitch,
		roll;

	ASSERT (attitude);

	heading = unpack_float_value (en, FLOAT_TYPE_HEADING);

	pitch = unpack_float_value (en, FLOAT_TYPE_PITCH);

	roll = unpack_float_value (en, FLOAT_TYPE_ROLL);

	get_3d_transformation_matrix (attitude, heading, pitch, roll);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void pack_attitude_angles (entity *en, float heading, float pitch, float roll)
{
	pack_float_value (en, FLOAT_TYPE_HEADING, heading);

	pack_float_value (en, FLOAT_TYPE_PITCH, pitch);

	pack_float_value (en, FLOAT_TYPE_ROLL, roll);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void unpack_attitude_angles (entity *en, float *heading, float *pitch, float *roll)
{
	ASSERT (heading);

	ASSERT (pitch);

	ASSERT (roll);

	*heading = unpack_float_value (en, FLOAT_TYPE_HEADING);

	*pitch = unpack_float_value (en, FLOAT_TYPE_PITCH);

	*roll = unpack_float_value (en, FLOAT_TYPE_ROLL);
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
