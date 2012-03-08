Timer:RefuelVehicle(playerID, Float:totalAmount)
{
	new vehicleID = GetPlayerVehicleID(playerID);
	if (GetPVar:playerID[MONEY] >= GetPVar:playerID[CURRENTGASPRICE])
	{
		new Float:maximum = floatsub(vehicleModels[GetVehicleModel(vehicleID) - 400][VEHICLEMODEL_MAXFUEL], vehicles[vehicleID][VEHICLE_CURRENTFUEL]);
		if (totalAmount > 0 && maximum > 0)
		{
			new Float:amount;
			if (maximum < 1)
			{
				amount = maximum;
			}
			else
			{
				amount = 1.0;
			}
			vehicles[vehicleID][VEHICLE_CURRENTFUEL] = floatadd(vehicles[vehicleID][VEHICLE_CURRENTFUEL], amount);
			GivePlayerMoneyEx(playerID, -floatmul(GetPVar:playerID[CURRENTGASPRICE], amount));
			SetTimerEx("Timer_RefuelVehicle", GASSTATION_REFUELSPEED, false, "df", playerID, floatsub(totalAmount, amount));
			return true;
		}
		SendClientMessage(playerID, COLOR_INFO, "Dein Fahrzeug wurde getankt.");
	}
	else
	{
		SendClientMessage(playerID, COLOR_ERROR, "Du hast nicht gen�gend Geld!");
	}
	TogglePlayerControllable(playerID, true);
	return true;
}