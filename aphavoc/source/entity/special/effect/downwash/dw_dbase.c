///////////////////////////////////////////////////////////////////////////////////////////
//	Filename	: DW_DBASE.C
//	Authors		: Xhit (Ingemar Persson)
//	Date		: 2003-03-28
//	Update		:
//
//	Description	: Initialises and Deinitialises the downwash_data in the downwash_database
//				  Functions are called by EN_DBASE.C	
//
///////////////////////////////////////////////////////////////////////////////////////////

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "project.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

downwash_data 
		downwash_database[NUM_DOWNWASH_TYPES];

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void initialise_misc_downwash_database();
static void initialise_land_downwash_database();
static void initialise_water_downwash_database();

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialise_downwash_database()
{

	initialise_misc_downwash_database();
	initialise_land_downwash_database();
	initialise_water_downwash_database();
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void	initialise_misc_downwash_database()
{

	downwash_data
		*this_downwash;

	
	// NONE. FIRST IS EMPTY

	this_downwash = &(downwash_database[ DOWNWASH_TYPE_NONE ]);

	this_downwash->number_of_components	=	0;

	this_downwash->component = NULL;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

static void initialise_land_downwash_database()
{
	downwash_component
		*downwash_info;

	downwash_data
		*this_downwash;

	// LAND DOWNWASH COMPONENTS

	this_downwash = &(downwash_database[ DOWNWASH_TYPE_LAND ]);

	this_downwash->number_of_components	=	1;

	this_downwash->component = (downwash_component *) malloc_fast_mem( sizeof( downwash_component ) * this_downwash->number_of_components);
	
	// FIRST COMPONENT IN LAND DOWNWASH EFFECT, 

	downwash_info = &(this_downwash->component[ 0 ]);

	downwash_info -> trail_count				= 4;
	downwash_info -> create_in_all_quadrants	= TRUE;
	downwash_info -> frequency					= 1.0;
	downwash_info -> generator_lifetime			= 1.0;
	downwash_info -> lifetime_min				= 1.0;
	downwash_info -> lifetime_max				= 2.0;
	downwash_info -> scale_min					= 1.0;
	downwash_info -> scale_max					= 2.5;

	// LAND DOWNWASH COMPONENTS FOR DUAL ROTOR HELICOPTERS

	this_downwash = &(downwash_database[ DOWNWASH_TYPE_LAND_DUAL_ROTORS ]);

	this_downwash->number_of_components	=	1;

	this_downwash->component = (downwash_component *) malloc_fast_mem( sizeof( downwash_component ) * this_downwash->number_of_components);
	
	// FIRST COMPONENT IN LAND DOWNWASH EFFECT FOR DUAL ROTOR HELICOPTERS 

	downwash_info = &(this_downwash->component[ 0 ]);

	downwash_info -> trail_count				= 6;
	downwash_info -> create_in_all_quadrants	= TRUE;
	downwash_info -> frequency					= 1.0;
	downwash_info -> generator_lifetime			= 1.0;
	downwash_info -> lifetime_min				= 1.0;
	downwash_info -> lifetime_max				= 2.0;
	downwash_info -> scale_min					= 1.0;
	downwash_info -> scale_max					= 2.5;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void initialise_water_downwash_database()
{

	downwash_component
		*downwash_info;

	downwash_data
		*this_downwash;

	// WATER DOWNWASH COMPONENTS

	this_downwash = &(downwash_database[ DOWNWASH_TYPE_WATER ]);

	this_downwash->number_of_components	=	1;

	this_downwash->component = (downwash_component *) malloc_fast_mem( sizeof( downwash_component ) * this_downwash->number_of_components);
	
	// FIRST COMPONENT IN WATER DOWNWASH EFFECT, 

	downwash_info = &(this_downwash->component[ 0 ]);

	downwash_info -> trail_count				= 4;
	downwash_info -> create_in_all_quadrants	= TRUE;
	downwash_info -> frequency					= 1.0;
	downwash_info -> generator_lifetime			= 1.0;
	downwash_info -> lifetime_min				= 1.0;
	downwash_info -> lifetime_max				= 2.0;
	downwash_info -> scale_min					= 1.0;
	downwash_info -> scale_max					= 1.5;


	// WATER DOWNWASH COMPONENTS FOR DUAL ROTOR HELICOPTERS

	this_downwash = &(downwash_database[ DOWNWASH_TYPE_WATER_DUAL_ROTORS ]);

	this_downwash->number_of_components	=	1;

	this_downwash->component = (downwash_component *) malloc_fast_mem( sizeof( downwash_component ) * this_downwash->number_of_components);
	
	// FIRST COMPONENT IN WATER DOWNWASH EFFECT FOR DUAL ROTOR HELICOPTERS 

	downwash_info = &(this_downwash->component[ 0 ]);

	downwash_info -> trail_count				= 6;
	downwash_info -> create_in_all_quadrants	= TRUE;
	downwash_info -> frequency					= 1.0;
	downwash_info -> generator_lifetime			= 1.0;
	downwash_info -> lifetime_min				= 1.0;
	downwash_info -> lifetime_max				= 2.0;
	downwash_info -> scale_min					= 1.0;
	downwash_info -> scale_max					= 1.5;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void deinitialise_downwash_database()
{
	downwash_data
		*this_downwash;

	this_downwash = &(downwash_database[ DOWNWASH_TYPE_LAND ]);
	free_mem (this_downwash->component);

	this_downwash = &(downwash_database[ DOWNWASH_TYPE_LAND_DUAL_ROTORS ]);
	free_mem (this_downwash->component);

	this_downwash = &(downwash_database[ DOWNWASH_TYPE_WATER ]);
	free_mem (this_downwash->component);

	this_downwash = &(downwash_database[ DOWNWASH_TYPE_WATER_DUAL_ROTORS ]);
	free_mem (this_downwash->component);

}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
