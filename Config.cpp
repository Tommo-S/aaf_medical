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
    #include "cfgVehicles.hpp"
};

class cfgFunctions {
    #include "cfgFunctions.hpp"
};