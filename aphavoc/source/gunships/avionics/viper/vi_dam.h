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

union VIPER_DAMAGE_FLAGS
{
	unsigned int
		flags;

	struct
	{
		unsigned int
			flir							:1,	// 1
			dtv							:1,	// 2
			laser_designator			:1,	// 3
			radar_jammer				:1,	// 4
			infra_red_jammer	  		:1,	// 5
			navigation_computer 		:1,	// 6
			communications		  		:1,	// 7
			radar_warning_system		:1,	// 8
			hidss						:1,	// 9
			pilot_lh_mfd						:1,	// 10
			pilot_rh_mfd						:1,	// 11
			co_pilot_lh_mfd						:1,	// 12
			co_pilot_rh_mfd						:1,	// 13
			pilot_dfd						:1,	// 14
			co_pilot_dfd						:1,	// 15
			pnvs							:1,	// 16
			gun_jammed					:1,	// 17
			lh_wing_tip_mount			:1,	// 18
			lh_outer_pylon				:1,	// 19
			lh_inner_pylon				:1,	// 20
			rh_wing_tip_mount			:1,	// 21
			rh_outer_pylon				:1,	// 22
			rh_inner_pylon				:1,	// 23
			chaff_dispenser			:1,	// 24
			flare_dispenser			:1;	// 25
	};
};

typedef union VIPER_DAMAGE_FLAGS viper_damage_flags;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern viper_damage_flags
	viper_damage;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

extern void set_viper_weapon_damage_status (void);

extern void fully_repair_viper_damage (void);

extern void partially_repair_viper_damage (void);

extern void repair_viper_weapon_damage (void);

extern void damage_viper (gunship_damage_levels damage_level);

extern void notify_viper_avionics_of_dynamics_fault (unsigned int damage);

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////