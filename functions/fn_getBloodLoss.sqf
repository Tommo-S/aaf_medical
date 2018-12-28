/*
 * Author: Glowbal
 * Edited by Tommo
 * Calculate the total blood loss of a unit.
 *
 * Arguments:
 * 0: The Unit <OBJECT>
 *
 * Return Value:
 * Total blood loss of unit <NUMBER>
 *
 * Example:
 * [bob] call ACE_medical_fnc_getBloodLoss
 *
 * Public: No
 */

//Tommo - Each open wound seems to be formatted like [x, size/type of wound represented by a signle identifying number, limb, how many of this type/how much partial left, default blood loss for this type]. Dunno what X is.

#define BLOODLOSSRATE_BASIC 0.2

// TODO Only use this calculation if medium or higher, otherwise use vanilla calculations (for basic medical).
params ["_unit"];

private _totalBloodLoss = 0;
private _tourniquets = _unit getVariable ["ace_medical_tourniquets", [0,0,0,0,0,0]];
{
    //Tommo - Check if wound has been fully bandaged.
    if ((_x select 3) > 0) then {
        //total bleeding ratio * percentage of injury left
        private _thisWoundBleed = (_x select 4) * (_x select 3);
        
        //Check if this limb has a tourniquet on it. Remembering tourniquets record the CBA mission time it was applied. i.e. [0,0,30,0,0,0] value for tourniquets means a tourniquet was applied at CBAmissiontime 30 to... left arm I think that is.
        if ((_tourniquets select (_x select 2)) > 0) then {
            //Reduce this wounds bleeding amount by 80%.
            _thisWoundBleed = _thisWoundBleed * 0.2;
        };
        
        //Add current wound to total blood loss.
        _totalBloodLoss = _totalBloodLoss + _thisWoundBleed;
        
        // (((BLOODLOSS_SMALL_WOUNDS * (_x select 0))) + ((BLOODLOSS_MEDIUM_WOUNDS * (_x select 1))) + ((BLOODLOSS_LARGE_WOUNDS * (_x select 2))) * (_cardiacOutput / DEFAULT_CARDIAC_OUTPUT));
    };
} forEach (_unit getVariable ["ace_medical_openWounds", []]);

{
    _totalBloodLoss = _totalBloodLoss + ((_x select 4) * (_x select 3));
} forEach (_unit getVariable ["ace_medical_internalWounds", []]);

_totalBloodLoss * ((_unit getVariable ["ace_medical_bleedingCoefficient", ace_medical_bleedingCoefficient]) max 0);




//As we're ignoring tourniquets, can just look for open wounds, calculate blood loss from that, the apply tourniquet reduction.


