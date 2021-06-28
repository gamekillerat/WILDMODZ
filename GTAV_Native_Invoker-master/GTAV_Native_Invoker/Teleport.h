void TeleportToLoc(float x, float y, float z)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
	{
		int vehid = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		ENTITY::SET_ENTITY_COORDS(vehid, x, y, z, 1, 0, 0, 1);
	}
	else
	{
		ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), x, y, z, 1, 0, 0, 1);
	}
}

void TeleportToPed(int TargetPed_Handle)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
	{
		Vector3 Coords12 = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(TargetPed_Handle), 1);
		int vehid = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		ENTITY::SET_ENTITY_COORDS(vehid, Coords12.x, Coords12.y, Coords12.z, 1, 0, 0, 1);
	}
	else
	{
		Vector3 Coords12 = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(TargetPed_Handle), 1);
		ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), Coords12.x, Coords12.y, Coords12.z, 1, 0, 0, 1);
	}
}

void TPtoWaypoint()
{
	int WaypointHandle = UI::GET_FIRST_BLIP_INFO_ID(8);								
	if(UI::DOES_BLIP_EXIST(WaypointHandle))						
	{
		Vector3 Coords13 = UI::GET_BLIP_COORDS(WaypointHandle);	
		int Handle = PLAYER::PLAYER_PED_ID();	
		if (PED::IS_PED_IN_ANY_VEHICLE(Handle, 0))	
		Handle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);	
		ENTITY::SET_ENTITY_COORDS(Handle, Coords13.x, Coords13.y, Coords13.z, 1, 0, 0, 1);
	}
}

void TeleportToCage(int TargetPed_Handle1)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED(TargetPed_Handle1), 0))
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(TargetPed_Handle1), 0));
		int vehid = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(TargetPed_Handle1), 0);
		Vector3 Coords14 = { -24.9955, -1104.9330, 26.7048 };
		ENTITY::SET_ENTITY_COORDS(vehid, Coords14.x, Coords14.y, Coords14.z, 1, 0, 0, 1);
	}
}

void TeleportToCage1(int TargetPed_Handle1)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED(TargetPed_Handle1), 0))
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(TargetPed_Handle1), 0));
		int vehid = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(TargetPed_Handle1), 0);
		Vector3 Coords14 = { -15.7570, -1013.3720, 27.8774 };
		ENTITY::SET_ENTITY_COORDS(vehid, Coords14.x, Coords14.y, Coords14.z, 1, 0, 0, 1);
	}
}

void TpToMe(int TargetPed_Handle2)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED(TargetPed_Handle2), 0))
	{
		NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(TargetPed_Handle2), 0));
		int vehid = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(TargetPed_Handle2), 0);
		Vector3 Coords15 = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		ENTITY::SET_ENTITY_COORDS(vehid, Coords15.x, Coords15.y, Coords15.z, 1, 0, 0, 1);
	}
}

void ToNearestCar()
{
	Vector3 Coords16 = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	int VehID = VEHICLE::GET_CLOSEST_VEHICLE(Coords16.x,Coords16.y,Coords16.z, 150.0, 0, 71);
	PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), VehID, -1);
}


