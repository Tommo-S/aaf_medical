#include "BIS_AddonInfo.hpp"
class CfgPatches
{
    class aaf_adv_med
    {
        units[] = {};
        weapons[] = {};
        requiredVersion = 1.68;
        requiredAddons[] = {
			"ace_medical"
		};
		version = "0.1";
		versionStr = "0.1";
		author = "Tommo";
    };
};

class ACE_Medical_Actions
{
	class Advanced
	{
		class FieldDressing;
		class BloodIV: FieldDressing
		{
			displayName="$STR_AAF_Medical_Blood_IV";
			allowSelfTreatment=1;
		};
	};
};

class ACE_Medical_Advanced
{
	class Treatment
	{
		class IV
		{
			class BloodIV
			{
				volume=7000;
				ratio[]=
				{
					"Plasma",
					1
				};
			};
		};
	};
};

class CfgWeapons {
	class ace_ItemCore;
	class ACE_bloodIV: ACE_ItemCore {
		displayName = "$STR_AAF_Medical_Blood_Kit";
	};
};

class CfgVehicles
{
	class Man;
	class CAManBase: Man
	{
		class ACE_SelfActions
		{
			class Medical
			{
				class ACE_ArmLeft
				{
					class FieldDressing;
					class BloodIV: FieldDressing
						{
							displayName="$STR_AAF_Medical_Blood_IV";
							condition="[_player,_target,'hand_l','BloodIV'] call ace_medical_fnc_canTreatCached";
							statement="[_player,_target,'hand_l','BloodIV'] call ace_medical_fnc_treatment";
							exceptions[]=
							{
								"isNotInside"
							};
							icon="\z\ace\addons\medical\UI\icons\iv.paa";
						};
				};
				class ACE_ArmRight
				{
					class FieldDressing;
					class BloodIV: FieldDressing
						{
							displayName="$STR_AAF_Medical_Blood_IV";
							condition="[_player,_target,'hand_r','BloodIV'] call ace_medical_fnc_canTreatCached";
							statement="[_player,_target,'hand_r','BloodIV'] call ace_medical_fnc_treatment";
							exceptions[]=
							{
								"isNotInside"
							};
							icon="\z\ace\addons\medical\UI\icons\iv.paa";
						};
				};
				class ACE_LegLeft
				{
					class FieldDressing;
					class BloodIV: FieldDressing
						{
							displayName="$STR_AAF_Medical_Blood_IV";
							condition="[_player,_target,'leg_l','BloodIV'] call ace_medical_fnc_canTreatCached";
							statement="[_player,_target,'leg_l','BloodIV'] call ace_medical_fnc_treatment";
							exceptions[]=
							{
								"isNotInside"
							};
							icon="\z\ace\addons\medical\UI\icons\iv.paa";
						};
				};
				class ACE_LegRight
				{
					class FieldDressing;
					class BloodIV: FieldDressing
						{
							displayName="$STR_AAF_Medical_Blood_IV";
							condition="[_player,_target,'leg_r','BloodIV'] call ace_medical_fnc_canTreatCached";
							statement="[_player,_target,'leg_r','BloodIV'] call ace_medical_fnc_treatment";
							exceptions[]=
							{
								"isNotInside"
							};
							icon="\z\ace\addons\medical\UI\icons\iv.paa";
						};
				};
			};
		};
		class ACE_Actions
		{
			class ACE_MainActions
			{
				class Medical
				{
					class ACE_ArmLeft
					{
						class FieldDressing;
						class BloodIV: FieldDressing
						{
							displayName="$STR_AAF_Medical_Blood_IV";
						};
					};
					class ACE_ArmRight
					{
						class FieldDressing;
						class BloodIV: FieldDressing
						{
							displayName="$STR_AAF_Medical_Blood_IV";
						};
					};
					class ACE_LegLeft
					{
						class FieldDressing;
						class BloodIV: FieldDressing
						{
							displayName="$STR_AAF_Medical_Blood_IV";
						};
					};
					class ACE_LegRight
					{
						class FieldDressing;
						class BloodIV: FieldDressing
						{
							displayName="$STR_AAF_Medical_Blood_IV";
						};
					};
				};
			};
		};
	};
};