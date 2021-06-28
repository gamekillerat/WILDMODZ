
void Maxupgrade(int VehicleHandle) 
{
	VEHICLE::SET_VEHICLE_MOD_KIT(VehicleHandle, 0);
	VEHICLE::SET_VEHICLE_COLOURS(VehicleHandle, 120, 120);
	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(VehicleHandle, "WILDEMODZ");
	//VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(VehicleHandle, 1);;
	VEHICLE::TOGGLE_VEHICLE_MOD(VehicleHandle, 18, 1);
	VEHICLE::TOGGLE_VEHICLE_MOD(VehicleHandle, 22, 1);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 16, 5, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 12, 2, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 11, 3, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 14, 14, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 15, 3, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 13, 2, 0);
	VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehicleHandle, 6);
	VEHICLE::SET_VEHICLE_WINDOW_TINT(VehicleHandle, 5);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 23, 18, 1);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 0, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 1, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 2, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 3, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 4, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 5, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 6, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 7, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 8, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 9, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 10, 1, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 16, 4, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 3, 0, 0);
	VEHICLE::SET_VEHICLE_MOD_KIT(VehicleHandle, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 16, 4, 0);
}
void MaxUpgrades(int cli, bool type = false)
{

	Vehicle VehicleHandle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(cli), true);

	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehicleHandle);
	if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(VehicleHandle))
	{
		VEHICLE::SET_VEHICLE_MOD_KIT(VehicleHandle, 0);
		VEHICLE::SET_VEHICLE_COLOURS(VehicleHandle, 120, 120);
		VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(VehicleHandle, "WILDEMODZ");
		//VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(VehicleHandle, 1);
		VEHICLE::TOGGLE_VEHICLE_MOD(VehicleHandle, 18, 1);
		VEHICLE::TOGGLE_VEHICLE_MOD(VehicleHandle, 22, 1);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 16, 5, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 12, 2, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 11, 3, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 14, 14, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 15, 3, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 13, 2, 0);
		VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehicleHandle, 6);
		VEHICLE::SET_VEHICLE_WINDOW_TINT(VehicleHandle, 5);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 23, 19, 1);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 0, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 1, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 2, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 3, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 4, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 5, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 6, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 7, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 8, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 9, 1, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 10, 1, 0);
		VEHICLE::SET_VEHICLE_MOD_KIT(VehicleHandle, 0);
		VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 16, 4, 0);
	}
}

void changeplate(int platetype)
{
	VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0);
	VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), platetype);
}

void changecolori(int Colorindex_1, int Colorindex_2)
{
	VEHICLE::SET_VEHICLE_MOD_KIT(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0);
	VEHICLE::SET_VEHICLE_COLOURS(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), Colorindex_1, Colorindex_2);
}

void DeleteVehicle(int VehicleHandle1)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED(VehicleHandle1),0))
	{
		int veh = PED::GET_VEHICLE_PED_IS_USING(PLAYER::GET_PLAYER_PED(VehicleHandle1));
		int tries = 0;
		while (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(veh) && tries < 10000)
		{
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(veh);
			tries++;		
			ENTITY::SET_ENTITY_AS_MISSION_ENTITY(veh, 0, 1);
			VEHICLE::DELETE_VEHICLE(&veh);
		}
	}	
}

void KickFromCar(int VehicleHandle) 
{
	AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED(VehicleHandle));
}

int GET_FREE_SEAT(int VehicleHandle)
{
	int SeatIndex = -1;  //Driver seat = -1
	while (-1 < VEHICLE::GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS(VehicleHandle))
	{
		if (VEHICLE::IS_VEHICLE_SEAT_FREE(VehicleHandle, SeatIndex))
			return SeatIndex;
		SeatIndex++;
	}
	return -2;
}

void SET_INTO_VEHICLE(int VehicleHandle) 
{
	bool Max = VEHICLE::GET_VEHICLE_MAX_NUMBER_OF_PASSENGERS(VehicleHandle), Existing = VEHICLE::GET_VEHICLE_NUMBER_OF_PASSENGERS(VehicleHandle);
	if (!Max == Existing) 
	{
		for (int SeatIndex = -1; SeatIndex <= Max; SeatIndex++) 
		{
			if (VEHICLE::IS_VEHICLE_SEAT_FREE(VehicleHandle, SeatIndex)) 
			{
				PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), VehicleHandle, SeatIndex);
				SeatIndex = Max + 1;
			}
		}
	}
}


bool doFreezeCar = false;
bool freezePlayersCar(int Client)
{
	int PedHandle = PLAYER::GET_PLAYER_PED(Client);
	if(PED::IS_PED_IN_ANY_VEHICLE(PedHandle, 0))
	{
		int VehHandle = PED::GET_VEHICLE_PED_IS_IN(PedHandle, 0);
		if(NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehHandle))
		{	
			ENTITY::FREEZE_ENTITY_POSITION(VehHandle, true);	
			return true;
		}
		else return false;
	}
	else
	{
		doFreezeCar = false;
		return false;
	}				
}
bool doUnfreezeCar = false;
bool unfreezePlayersCar(int Client)
{
	int PedHandle = PLAYER::GET_PLAYER_PED(Client);
	if(PED::IS_PED_IN_ANY_VEHICLE(PedHandle, 0))
	{
		int VehHandle = PED::GET_VEHICLE_PED_IS_IN(PedHandle, 0);
		if(NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehHandle))
		{	
			ENTITY::FREEZE_ENTITY_POSITION(VehHandle, false);	
			return true;
		}
		else return false;
	}
	else
	{
		doUnfreezeCar = false;
		return false;
	}				
}

bool doUndriveableCar = false;
bool undriveablePlayersCar(int Client)
{
	int PedHandle = PLAYER::GET_PLAYER_PED(Client);
	if(PED::IS_PED_IN_ANY_VEHICLE(PedHandle, 0))
	{
		int VehHandle = PED::GET_VEHICLE_PED_IS_IN(PedHandle, 0);
		if(NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehHandle))
		{				
			VEHICLE::SET_VEHICLE_UNDRIVEABLE(VehHandle, true);
			return true;
		}
		else return false;
	}
	else
	{
		doUndriveableCar = false;
		return false;
	}				
}

bool doLockCar = false;
bool lockPlayersCar(int Client)
{
	int PedHandle = PLAYER::GET_PLAYER_PED(Client);
	if(PED::IS_PED_IN_ANY_VEHICLE(PedHandle, 0))
	{
		int VehHandle = PED::GET_VEHICLE_PED_IS_IN(PedHandle, 0);
		if(NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehHandle))
		{
			VEHICLE::SET_VEHICLE_DOORS_LOCKED(VehHandle, 4);
			return true;
		}
		else return false;
	}
	else
	{
		doLockCar = false;
		return false;
	}				
}
bool doUnlockCar = false;
bool unlockPlayersCar(int Client)
{
	int PedHandle = PLAYER::GET_PLAYER_PED(Client);
	if(PED::IS_PED_IN_ANY_VEHICLE(PedHandle, 0))
	{
		int VehHandle = PED::GET_VEHICLE_PED_IS_IN(PedHandle, 0);
		if(NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehHandle))
		{
			VEHICLE::SET_VEHICLE_DOORS_LOCKED(VehHandle, 0);
			return true;
		}
		else return false;
	}
	else
	{
		doUnlockCar = false;
		return false;
	}				
}

void StealPlayerVehicle(int Client)
{				
	int pedHandle = PLAYER::GET_PLAYER_PED(Client); 
	if (PED::IS_PED_IN_ANY_VEHICLE(pedHandle, 0)) 
	{ 
		AI::CLEAR_PED_TASKS_IMMEDIATELY(pedHandle);
		int VehID = PED::GET_VEHICLE_PED_IS_IN(pedHandle, 0);	
		PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), VehID, -1); 
	}
}

void TpIntoPlayerVehicle(int Client)
{
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::GET_PLAYER_PED(Client), 0)) 
	{ 
		int veh = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(Client), 0);
		PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), veh, GET_FREE_SEAT(veh));
	}
}

void drawneons(int R, int G, int B)
{
	int VehicleID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	Vector3 Coords = ENTITY::GET_ENTITY_COORDS(VehicleID, true);
	GRAPHICS::DRAW_LIGHT_WITH_RANGE(Coords.x, Coords.y, Coords.z, R, G, B, 4.0f, 2.0f);
}




//MODDED VEHICLE
bool doTrolley = false;
bool spawnTrolley()
{
		uint Handle = PLAYER::PLAYER_PED_ID();
		Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		Vector3 null; null.x = 0, null.y = 0; null.z = 0;
		Vector3 a; a.x = 0, a.y = 0, a.z = 0;
		Vector3 b; b.x = 0, b.y = 2, b.z = 0;
		int hash = GAMEPLAY::GET_HASH_KEY("carbonrs");
		int hash2 = GAMEPLAY::GET_HASH_KEY("prop_rub_trolley01a");
		STREAMING::REQUEST_MODEL(hash);
		STREAMING::REQUEST_MODEL(hash2);
		if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
		{
			int Object = OBJECT::CREATE_OBJECT(hash2, null.x, null.y, null.z, 1, 0, 1);
			if (ENTITY::DOES_ENTITY_EXIST(Object))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
				{
					PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, false);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
					//drawNotification("Spawned: ~g~Trolley~HUD_COLOUR_WHITE~!");
					ENTITY::SET_ENTITY_VISIBLE(Handle, true);
					return true;
				}
				return false;
			}
			return false;
		}
		return false;
		
	}
    bool doToilet = false;
	bool spawnToilet()
	{
		uint Handle = PLAYER::PLAYER_PED_ID();
		Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		Vector3 null; null.x = 0, null.y = 0; null.z = 0;
		Vector3 a; a.x = 0, a.y = -0.4f, a.z = 0.1f;
		Vector3 b; b.x = 0, b.y = 0, b.z = 180;
		int hash = GAMEPLAY::GET_HASH_KEY("blazer");
		int hash2 = GAMEPLAY::GET_HASH_KEY("prop_ld_toilet_01");
		STREAMING::REQUEST_MODEL(hash);
		STREAMING::REQUEST_MODEL(hash2);
		if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
		{
			int Object = OBJECT::CREATE_OBJECT(hash2, null.x, null.y, null.z, 1, 0, 1);
			if (ENTITY::DOES_ENTITY_EXIST(Object))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
				{
					PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, false);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
					//drawNotification("Spawned: ~g~Toilet~HUD_COLOUR_WHITE~!");
					ENTITY::SET_ENTITY_VISIBLE(Handle, true);
					return true;
				}
				return false;
			}
			return false;														
		}
		return false;
	}

	bool doCouch = false;
	bool spawnCouch()
	{
		uint Handle = PLAYER::PLAYER_PED_ID();
		Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		Vector3 null; null.x = 0, null.y = 0; null.z = 0;
		Vector3 a; a.x = 0, a.y = -0.4f, a.z = 0;
		Vector3 b; b.x = 0, b.y = 0, b.z = 180.0f;
		int hash = GAMEPLAY::GET_HASH_KEY("dune");
		int hash2 = GAMEPLAY::GET_HASH_KEY("prop_t_sofa");
		STREAMING::REQUEST_MODEL(hash);
		STREAMING::REQUEST_MODEL(hash2);
		if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
		{
			int Object = OBJECT::CREATE_OBJECT(hash2, null.x, null.y, null.z, 1, 0, 1);
			if (ENTITY::DOES_ENTITY_EXIST(Object))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
				{
					PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, false);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
					//drawNotification("Spawned: ~b~Couch~HUD_COLOUR_WHITE~!");
					ENTITY::SET_ENTITY_VISIBLE(Handle, true);	
					return true;
				}
				return false;
			}		
			return false;														
		}
		return false;
	}

	bool doWheelchair = false;
	bool spawnWheelchair()
	{
		uint Handle = PLAYER::PLAYER_PED_ID();
		Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		Vector3 null; null.x = 0, null.y = 0; null.z = 0;
		Vector3 a; a.x = -0.27, a.y = -0.24, a.z = 0.13f;
		Vector3 b; b.x = 0, b.y = 0, b.z = 180;
		int hash = GAMEPLAY::GET_HASH_KEY("caddy2");
		int hash2 = GAMEPLAY::GET_HASH_KEY("prop_wheelchair_01");
		STREAMING::REQUEST_MODEL(hash);
		STREAMING::REQUEST_MODEL(hash2);
		if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
		{
			int Object = OBJECT::CREATE_OBJECT(hash2, null.x, null.y, null.z, 1, 0, 1);
			if (ENTITY::DOES_ENTITY_EXIST(Object))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
				{
					PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, false);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
					//drawNotification("Spawned: ~b~Wheelchair~HUD_COLOUR_WHITE~!");
					ENTITY::SET_ENTITY_VISIBLE(Handle, true);	
					return true;
				}
				return false;
			}		
			return false;														
		}
		return false;
	}

	bool doBumpercar = false;
	bool spawnBumpercar()
	{
		uint Handle = PLAYER::PLAYER_PED_ID();
		Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		Vector3 null; null.x = 0, null.y = 0; null.z = 0;
		Vector3 a; a.x = -0.34, a.y = 0.32, a.z = -0.25;
		Vector3 b; b.x = 0, b.y = 0, b.z = 180;
		int hash = GAMEPLAY::GET_HASH_KEY("blista");
		int hash2 = GAMEPLAY::GET_HASH_KEY("prop_bumper_car_01");
		STREAMING::REQUEST_MODEL(hash);
		STREAMING::REQUEST_MODEL(hash2);
		if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
		{
			int Object = OBJECT::CREATE_OBJECT(hash2, null.x, null.y, null.z, 1, 0, 1);
			if (ENTITY::DOES_ENTITY_EXIST(Object))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
				{
					PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, false);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
					//drawNotification("Spawned: ~b~Bumper Car~HUD_COLOUR_WHITE~!");
					ENTITY::SET_ENTITY_VISIBLE(Handle, true);	
					return true;
				}
				return false;
			}	
			return false;														
		}
		return false;
	}

	bool doWheelbarrow = false;
    bool spawnWheelbarrow()
	{
		uint Handle = PLAYER::PLAYER_PED_ID();
		Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		Vector3 null; null.x = 0, null.y = 0; null.z = 0;
		Vector3 a; a.x = 0, a.y = -0.62, a.z = 0.12;
		Vector3 b; b.x = 0, b.y = 41.0, b.z = 90.0;
		int hash = GAMEPLAY::GET_HASH_KEY("bati");
		int hash2 = GAMEPLAY::GET_HASH_KEY("prop_wheelbarrow01a");
		STREAMING::REQUEST_MODEL(hash);
		STREAMING::REQUEST_MODEL(hash2);
		if (STREAMING::HAS_MODEL_LOADED(hash) && STREAMING::HAS_MODEL_LOADED(hash2))
		{
			int Object = OBJECT::CREATE_OBJECT(hash2, null.x, null.y, null.z, 1, 0, 1);
			if (ENTITY::DOES_ENTITY_EXIST(Object))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);
				if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
				{
					PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, false);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Object, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
					//drawNotification("Spawned: ~b~Wheelbarrow~HUD_COLOUR_WHITE~!");
					ENTITY::SET_ENTITY_VISIBLE(Handle, true);	
					return true;
				}
				return false;
			}		
			return false;														
		}
		return false;
	}



bool doTeddycar  = false;
bool spawnTeddycar()
 { 
  uint Handle = PLAYER::PLAYER_PED_ID();
  Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
  //hash2_RollerCar
  Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
  Vector3 a; a.x = 0.0, a.y = 0.0, a.z = -0.5;//X Coord - Y Coord - Z Coord
  Vector3 b; b.x = 0.0, b.y = 0.0, b.z = 180.0;//Pitch - Roll - Yaw
  //hash3_Seats
  Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
  Vector3 a1; a1.x = 0.0, a1.y = 0.0, a1.z = 0.0;
  Vector3 b1; b1.x = 0.0, b1.y = 0.0, b1.z = 0.0;
  //hash3_FLWheel1
  Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
  Vector3 a2; a2.x = -0.97, a2.y = 1.0, a2.z = -0.25;
  Vector3 b2; b2.x = 0.0, b2.y = 0.0, b2.z = -89.0;
  //hash3_RLWheel1
  Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
  Vector3 a3; a3.x = -1.00, a3.y = -1.10, a3.z = -0.24;
  Vector3 b3; b3.x = 0.0, b3.y = 0.0, b3.z = -89.0;
  //hash3_RFWheel1
  Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
  Vector3 a4; a4.x = 0.97, a4.y = 1.00, a4.z = -0.24;
  Vector3 b4; b4.x = 0.0, b4.y = 0.0, b4.z = 89.0;
  //hash3_RRWheel1
  Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
  Vector3 a5; a5.x = 1.00, a5.y = -1.10, a5.z = -0.24;
  Vector3 b5; b5.x = 0.0, b5.y = 0.0, b5.z = 89.0;

  int hash_T20 = GAMEPLAY::GET_HASH_KEY("t20");
  int hash2_RollerCar = GAMEPLAY::GET_HASH_KEY("ind_prop_dlc_roller_car");
  int hash3_Seats = GAMEPLAY::GET_HASH_KEY("prop_hd_seats_01");
  int hash4_Wheel = GAMEPLAY::GET_HASH_KEY("prop_wheel_01");

  STREAMING::REQUEST_MODEL(hash_T20);
  STREAMING::REQUEST_MODEL(hash2_RollerCar);
  STREAMING::REQUEST_MODEL(hash3_Seats);
  STREAMING::REQUEST_MODEL(hash4_Wheel);

  if (STREAMING::HAS_MODEL_LOADED(hash_T20) && STREAMING::HAS_MODEL_LOADED(hash2_RollerCar) && STREAMING::HAS_MODEL_LOADED(hash3_Seats) && STREAMING::HAS_MODEL_LOADED(hash4_Wheel))
  {
   int RollerCar = OBJECT::CREATE_OBJECT(hash2_RollerCar, null.x, null.y, null.z, 1, 0, 1);
   int Seats = OBJECT::CREATE_OBJECT(hash3_Seats, null1.x, null1.y, null1.z, 1, 0, 1);
   int FLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null2.x, null2.y, null2.z, 1, 0, 1);
   int RLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null3.x, null3.y, null3.z, 1, 0, 1);
   int RFWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null4.x, null4.y, null4.z, 1, 0, 1);
   int RRWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null5.x, null5.y, null5.z, 1, 0, 1);

   if (ENTITY::DOES_ENTITY_EXIST(RollerCar) && ENTITY::DOES_ENTITY_EXIST(Seats) && ENTITY::DOES_ENTITY_EXIST(FLWheel1)  && ENTITY::DOES_ENTITY_EXIST(RLWheel1) && ENTITY::DOES_ENTITY_EXIST(RFWheel1) && ENTITY::DOES_ENTITY_EXIST(RRWheel1))
   {
    int Vehicle = VEHICLE::CREATE_VEHICLE(hash_T20, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);

    if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
    {
     PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
     STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash_T20);    
     ENTITY::SET_ENTITY_VISIBLE(Vehicle, false);
     ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true);

     ENTITY::ATTACH_ENTITY_TO_ENTITY(RollerCar, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
     ENTITY::ATTACH_ENTITY_TO_ENTITY(Seats, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, 1, 0, 0, 2, 1);
     ENTITY::ATTACH_ENTITY_TO_ENTITY(FLWheel1, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, 1, 0, 0, 2, 1);
     ENTITY::ATTACH_ENTITY_TO_ENTITY(RLWheel1, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, 1, 0, 0, 2, 1);
     ENTITY::ATTACH_ENTITY_TO_ENTITY(RFWheel1, Vehicle, 0, a4.x, a4.y, a4.z, b4.x, b4.y, b4.z, 0, 1, 0, 0, 2, 1);
     ENTITY::ATTACH_ENTITY_TO_ENTITY(RRWheel1, Vehicle, 0, a5.x, a5.y, a5.z, b5.x, b5.y, b5.z, 0, 1, 0, 0, 2, 1);
     
     return true;
    }
    return false;
   }  
   return false;              
  }
  return false;
 }


	bool batbike = false;
    bool spawnBatBike()
	{
		uint Handle = PLAYER::PLAYER_PED_ID();
		Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		//hash2_minigun1
		Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
		Vector3 a; a.x = -0.4040, a.y = 1.5000, a.z = 0.1000;//X Coord - Y Coord - Z Coord
		Vector3 b; b.x = 0.0, b.y = 0.0, b.z = 91.1810;//Pitch - Roll - Yaw
        //hash2_minigun2
		Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
		Vector3 a1; a1.x = 0.4040, a1.y = 1.5000, a1.z = 0.1000;
		Vector3 b1; b1.x = 0.0, b1.y = 0.0, b1.z = 91.1810;
        //hash2_minigun3
		Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
		Vector3 a2; a2.x = 0.4000, a2.y = -0.8000, a2.z = 0.0;
		Vector3 b2; b2.x = 0.0, b2.y = 0.0, b2.z = 89.9000;
        //hash2_minigun4
		Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
		Vector3 a3; a3.x = -0.4000, a3.y = -0.8000, a3.z = 0.0;
		Vector3 b3; b3.x = 0.0, b3.y = 0.0, b3.z = 89.9000;
        //hash3_cell1
		Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
		Vector3 a4; a4.x = 0.3200, a4.y = -0.3670, a4.z = -0.0200;
		Vector3 b4; b4.x = 0.0, b4.y = 0.0, b4.z = 0.0;
        //hash3_cell2
		Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
		Vector3 a5; a5.x = -0.3200, a5.y = -0.3670, a5.z = -0.0200;
		Vector3 b5; b5.x = 0.0, b5.y = 0.0, b5.z = 0.0;
        //hash3_cell3
		Vector3 null6; null6.x = 0.0, null6.y = 0.0; null6.z = 0.0;
		Vector3 a6; a6.x = 0.0, a6.y = -0.4870, a6.z = 0.4400;
		Vector3 b6; b6.x = -21.1200, b6.y = -0.0100, b6.z = 0.0;
        //hash4_FLWheel1
		Vector3 null7; null7.x = 0.0, null7.y = 0.0; null7.z = 0.0;
		Vector3 a7; a7.x = -0.2000, a7.y = 1.1000, a7.z = 0.0;
		Vector3 b7; b7.x = 0.0, b7.y = 0.0, b7.z = 87.1992;
		//hash4_RLWheel1
		Vector3 null8; null8.x = 0.0, null8.y = 0.0; null8.z = 0.0;
		Vector3 a8; a8.x = -0.2340, a8.y = -1.1000, a8.z = -0.0300;
		Vector3 b8; b8.x = 0.0, b8.y = 0.0, b8.z = -89.0;
		//hash4_RFWheel1
		Vector3 null9; null9.x = 0.0, null9.y = 0.0; null9.z = 0.0;
		Vector3 a9; a9.x = 0.1660, a9.y = 1.1000, a9.z = -0.0;
		Vector3 b9; b9.x = 0.0, b9.y = 0.0, b9.z = 87.1992;
		//hash4_RRWheel1
		Vector3 null10; null10.x = 0.0, null10.y = 0.0; null10.z = 0.0;
		Vector3 a10; a10.x = 0.1660, a10.y = -1.0800, a10.z = -0.0300;
		Vector3 b10; b10.x = 0.0, b10.y = 0.0, b10.z = -87.1992;

		//hash5_engine
		Vector3 null11; null11.x = 0.0, null11.y = 0.0; null11.z = 0.0;
		Vector3 a11; a11.x = -0.1000, a11.y = 0.2000, a11.z = -0.2000;
		Vector3 b11; b11.x = 0.0, b11.y = 0.0, b11.z = 0.0;

		int hash_bati2 = GAMEPLAY::GET_HASH_KEY("bati2");
		int hash2_minigun1 = GAMEPLAY::GET_HASH_KEY("prop_minigun_01");
		int hash3_cell1 = GAMEPLAY::GET_HASH_KEY("prop_power_cell");
		//int hash4_minigun3 = GAMEPLAY::GET_HASH_KEY("prop_minigun_01");
		//int hash5_minigun4 = GAMEPLAY::GET_HASH_KEY("prop_minigun_01");
		int hash4_Wheel = GAMEPLAY::GET_HASH_KEY("prop_wheel_03");
		int hash5_engine = GAMEPLAY::GET_HASH_KEY("prop_car_engine_01");

		STREAMING::REQUEST_MODEL(hash_bati2);
		STREAMING::REQUEST_MODEL(hash2_minigun1);
        STREAMING::REQUEST_MODEL(hash3_cell1);
		//STREAMING::REQUEST_MODEL(hash4_minigun3);
		//STREAMING::REQUEST_MODEL(hash5_minigun4);
		STREAMING::REQUEST_MODEL(hash4_Wheel);
		STREAMING::REQUEST_MODEL(hash5_engine);

		if (STREAMING::HAS_MODEL_LOADED(hash_bati2) && STREAMING::HAS_MODEL_LOADED(hash2_minigun1) && STREAMING::HAS_MODEL_LOADED(hash3_cell1) && STREAMING::HAS_MODEL_LOADED(hash4_Wheel) && STREAMING::HAS_MODEL_LOADED(hash5_engine))
		{
			int minigun1 = OBJECT::CREATE_OBJECT(hash2_minigun1, null.x, null.y, null.z, 1, 0, 1);
			int minigun2 = OBJECT::CREATE_OBJECT(hash2_minigun1, null1.x, null1.y, null1.z, 1, 0, 1);
			int minigun3 = OBJECT::CREATE_OBJECT(hash2_minigun1, null2.x, null2.y, null2.z, 1, 0, 1);
			int minigun4 = OBJECT::CREATE_OBJECT(hash2_minigun1, null3.x, null3.y, null3.z, 1, 0, 1);
			int cell1 = OBJECT::CREATE_OBJECT(hash3_cell1, null4.x, null4.y, null4.z, 1, 0, 1);
			int cell2 = OBJECT::CREATE_OBJECT(hash3_cell1, null5.x, null5.y, null5.z, 1, 0, 1);
			int cell3 = OBJECT::CREATE_OBJECT(hash3_cell1, null6.x, null6.y, null6.z, 1, 0, 1);
			int FLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null7.x, null7.y, null7.z, 1, 0, 1);
			int RLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null8.x, null8.y, null8.z, 1, 0, 1);
			int RFWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null9.x, null9.y, null9.z, 1, 0, 1);
			int RRWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null10.x, null10.y, null10.z, 1, 0, 1);
			int engine = OBJECT::CREATE_OBJECT(hash5_engine, null11.x, null11.y, null11.z, 1, 0, 1);

			if (ENTITY::DOES_ENTITY_EXIST(minigun1) && ENTITY::DOES_ENTITY_EXIST(minigun2) && ENTITY::DOES_ENTITY_EXIST(minigun3) && ENTITY::DOES_ENTITY_EXIST(minigun4) && ENTITY::DOES_ENTITY_EXIST(cell1) && ENTITY::DOES_ENTITY_EXIST(cell2) && ENTITY::DOES_ENTITY_EXIST(cell3) && ENTITY::DOES_ENTITY_EXIST(FLWheel1)  && ENTITY::DOES_ENTITY_EXIST(RLWheel1) && ENTITY::DOES_ENTITY_EXIST(RFWheel1) && ENTITY::DOES_ENTITY_EXIST(RRWheel1) && ENTITY::DOES_ENTITY_EXIST(engine))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash_bati2, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);

				if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
				{
					PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash_bati2);
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, false);

					ENTITY::ATTACH_ENTITY_TO_ENTITY(minigun1, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(minigun2, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(minigun3, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(minigun4, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(cell1, Vehicle, 0, a4.x, a4.y, a4.z, b4.x, b4.y, b4.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(cell2, Vehicle, 0, a5.x, a5.y, a5.z, b5.x, b5.y, b5.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(cell3, Vehicle, 0, a6.x, a6.y, a6.z, b6.x, b6.y, b6.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(FLWheel1, Vehicle, 0, a7.x, a7.y, a7.z, b7.x, b7.y, b7.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(RLWheel1, Vehicle, 0, a8.x, a8.y, a8.z, b8.x, b8.y, b8.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(RFWheel1, Vehicle, 0, a9.x, a9.y, a9.z, b9.x, b9.y, b9.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(RRWheel1, Vehicle, 0, a10.x, a10.y, a10.z, b10.x, b10.y, b10.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(engine, Vehicle, 0, a11.x, a11.y, a11.z, b11.x, b11.y, b11.z, 0, 1, 0, 0, 2, 1);

					ENTITY::SET_ENTITY_VISIBLE(Handle, true);	
					return true;
				}
				return false;
			}		
			return false;														
		}
		return false;
	}

	bool minigun = false;
    bool spawnMiniguncar()
	{		
		uint Handle = PLAYER::PLAYER_PED_ID();
		Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		//hash2_EMP
		Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
		Vector3 a; a.x = 0.0, a.y = 1.61, a.z = -0.12;//X Coord - Y Coord - Z Coord
		Vector3 b; b.x = -12.0, b.y = 0.0, b.z = 0.0;//Pitch - Roll - Yaw
		//hash2_EMP2
		Vector3 null6; null6.x = 0.0, null6.y = 0.0; null6.z = 0.0;
		Vector3 a6; a6.x = 0.0, a6.y = -1.8300, a6.z = 0.0;//X Coord - Y Coord - Z Coord
		Vector3 b6; b6.x = 0.0, b6.y = 0.0, b6.z = 0.0;//Pitch - Roll - Yaw
		//hash3_MiniGun
		Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
		Vector3 a1; a1.x = -0.60, a1.y = 1.60, a1.z = 0.20;
		Vector3 b1; b1.x = 0.0, b1.y = 0.0, b1.z = 88.0;
		//hash3_MiniGun2
		Vector3 null0; null0.x = 0.0, null0.y = 0.0; null0.z = 0.0;
		Vector3 a0; a0.x = 0.60, a0.y = 1.60, a0.z = 0.20;
		Vector3 b0; b0.x = 0.0, b0.y = 0.0, b0.z = 88.0;
		//hash4_FLWheel1
		Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
		Vector3 a2; a2.x = -0.9000, a2.y = 1.3300, a2.z = -0.4000;
		Vector3 b2; b2.x = 9.0000, b2.y = 0.0, b2.z = 92.0000;
		//hash4_RLWheel1
		Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
		Vector3 a3; a3.x = 0.9000, a3.y = 1.3300, a3.z = -0.4000;
		Vector3 b3; b3.x = 9.0000, b3.y = 0.0, b3.z = -92.0000;
		//hash4_RFWheel1
		Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
		Vector3 a4; a4.x = -0.9000, a4.y = -1.3100, a4.z = -0.4000;
		Vector3 b4; b4.x = 9.0000, b4.y = 26.0, b4.z = 92.0000;
		//hash4_RRWheel1
		Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
		Vector3 a5; a5.x = 0.9000, a5.y = -1.3200, a5.z = -0.4000;
		Vector3 b5; b5.x = 9.0000, b5.y = 0.0, b5.z = -92.0000;
		//hash5_Fire
		Vector3 null7; null7.x = 0.0, null7.y = 0.0; null7.z = 0.0;
		Vector3 a7; a7.x = 0.0, a7.y = -2.0000, a7.z = 0.0;
		Vector3 b7; b7.x = 0.0, b7.y = 0.0, b7.z = 0.0;
		//hash6_alarm
		Vector3 null8; null8.x = 0.0, null8.y = 0.0; null8.z = 0.0;
		Vector3 a8; a8.x = 0.3000, a8.y = 0.0, a8.z = 0.6800;
		Vector3 b8; b8.x = -97.0000, b8.y = 0.0, b8.z = 0.0;
		//hash6_alarm2
		Vector3 null9; null9.x = 0.0, null9.y = 0.0; null9.z = 0.0;
		Vector3 a9; a9.x = -0.3000, a9.y = 0.0, a9.z = 0.6800;
		Vector3 b9; b9.x = -97.0000, b9.y = 0.0, b9.z = 0.0;

		int hash_kuruma2 = GAMEPLAY::GET_HASH_KEY("kuruma2");
		int hash2_EMP = GAMEPLAY::GET_HASH_KEY("hei_prop_heist_emp");
		int hash3_MiniGun = GAMEPLAY::GET_HASH_KEY("prop_minigun_01");
		int hash4_Wheel = GAMEPLAY::GET_HASH_KEY("prop_wheel_01");
		int hash5_Fire = GAMEPLAY::GET_HASH_KEY("prop_beach_fire");
		int hash6_alarm = GAMEPLAY::GET_HASH_KEY("hei_prop_wall_alarm_on");

		STREAMING::REQUEST_MODEL(hash_kuruma2);
		STREAMING::REQUEST_MODEL(hash2_EMP);
        STREAMING::REQUEST_MODEL(hash3_MiniGun);
		STREAMING::REQUEST_MODEL(hash4_Wheel);
		STREAMING::REQUEST_MODEL(hash5_Fire);
		STREAMING::REQUEST_MODEL(hash6_alarm);

		if (STREAMING::HAS_MODEL_LOADED(hash_kuruma2) && STREAMING::HAS_MODEL_LOADED(hash2_EMP) && STREAMING::HAS_MODEL_LOADED(hash3_MiniGun) && STREAMING::HAS_MODEL_LOADED(hash4_Wheel) && STREAMING::HAS_MODEL_LOADED(hash5_Fire) && STREAMING::HAS_MODEL_LOADED(hash6_alarm))
		{
			int EMP = OBJECT::CREATE_OBJECT(hash2_EMP, null6.x, null6.y, null6.z, 1, 0, 1);
			int EMP2 = OBJECT::CREATE_OBJECT(hash2_EMP, null.x, null.y, null.z, 1, 0, 1);
			int MiniGun = OBJECT::CREATE_OBJECT(hash3_MiniGun, null1.x, null1.y, null1.z, 1, 0, 1);
			int MiniGun2 = OBJECT::CREATE_OBJECT(hash3_MiniGun, null0.x, null0.y, null0.z, 1, 0, 1);
			int FLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null2.x, null2.y, null2.z, 1, 0, 1);
			int RLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null3.x, null3.y, null3.z, 1, 0, 1);
			int RFWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null4.x, null4.y, null4.z, 1, 0, 1);
			int RRWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null5.x, null5.y, null5.z, 1, 0, 1);
			int Fire = OBJECT::CREATE_OBJECT(hash5_Fire, null7.x, null7.y, null7.z, 1, 0, 1);
			int alarm = OBJECT::CREATE_OBJECT(hash6_alarm, null8.x, null8.y, null8.z, 1, 0, 1);
			int alarm2 = OBJECT::CREATE_OBJECT(hash6_alarm, null9.x, null9.y, null9.z, 1, 0, 1);

			if (ENTITY::DOES_ENTITY_EXIST(EMP) && ENTITY::DOES_ENTITY_EXIST(EMP2) && ENTITY::DOES_ENTITY_EXIST(MiniGun) && ENTITY::DOES_ENTITY_EXIST(MiniGun2) && ENTITY::DOES_ENTITY_EXIST(FLWheel1)  && ENTITY::DOES_ENTITY_EXIST(RLWheel1) && ENTITY::DOES_ENTITY_EXIST(RFWheel1) && ENTITY::DOES_ENTITY_EXIST(RRWheel1) && ENTITY::DOES_ENTITY_EXIST(Fire) && ENTITY::DOES_ENTITY_EXIST(alarm) && ENTITY::DOES_ENTITY_EXIST(alarm2))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash_kuruma2, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);

				if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
				{
					PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash_kuruma2);
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
					ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true);

					ENTITY::ATTACH_ENTITY_TO_ENTITY(EMP, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(EMP2, Vehicle, 0, a6.x, a6.y, a6.z, b6.x, b6.y, b6.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(MiniGun, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(MiniGun2, Vehicle, 0, a0.x, a0.y, a0.z, b0.x, b0.y, b0.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(FLWheel1, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(RLWheel1, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(RFWheel1, Vehicle, 0, a4.x, a4.y, a4.z, b4.x, b4.y, b4.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(RRWheel1, Vehicle, 0, a5.x, a5.y, a5.z, b5.x, b5.y, b5.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(Fire, Vehicle, 0, a7.x, a7.y, a7.z, b7.x, b7.y, b7.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(alarm, Vehicle, 0, a8.x, a8.y, a8.z, b8.x, b8.y, b8.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(alarm2, Vehicle, 0, a9.x, a9.y, a9.z, b9.x, b9.y, b9.z, 0, 1, 0, 0, 2, 1);

					ENTITY::SET_ENTITY_VISIBLE(Handle, true);	
					return true;
				}
				return false;
			}		
			return false;														
		}
		return false;
	}
	
	bool minigun2  = false;
    bool MINIGUNCAR2()
	{		
		uint Handle = PLAYER::PLAYER_PED_ID();
		Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		//hash2_EMP
		Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
		Vector3 a; a.x = 0.0, a.y = 1.61, a.z = -0.12;//X Coord - Y Coord - Z Coord
		Vector3 b; b.x = -12.0, b.y = 0.0, b.z = 0.0;//Pitch - Roll - Yaw
		//hash3_MiniGun
		Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
		Vector3 a1; a1.x = -0.60, a1.y = 1.60, a1.z = 0.20;
		Vector3 b1; b1.x = 0.0, b1.y = 0.0, b1.z = 88.0;
		//hash3_MiniGun2
		Vector3 null0; null0.x = 0.0, null0.y = 0.0; null0.z = 0.0;
		Vector3 a0; a0.x = 0.60, a0.y = 1.60, a0.z = 0.20;
		Vector3 b0; b0.x = 0.0, b0.y = 0.0, b0.z = 88.0;
		//hash4_FLWheel1
		Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
		Vector3 a2; a2.x = -0.94, a2.y = 1.32, a2.z = -0.25;
		Vector3 b2; b2.x = 9.0, b2.y = -28.0, b2.z = 87.0;
		//hash4_RLWheel1
		Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
		Vector3 a3; a3.x = -0.95, a3.y = -1.34, a3.z = -0.25f;
		Vector3 b3; b3.x = 9.0, b3.y = 38.0, b3.z = 87.0;
		//hash4_RFWheel1
		Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
		Vector3 a4; a4.x = 0.95, a4.y = 1.33, a4.z = -0.23;
		Vector3 b4; b4.x = 11.0, b4.y = 26.0, b4.z = -89.0;
		//hash4_RRWheel1
		Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
		Vector3 a5; a5.x = 0.96, a5.y = -1.31, a5.z = -0.23;
		Vector3 b5; b5.x = 10.0, b5.y = 20.0, b5.z = -92.0;

		int hash_T20 = GAMEPLAY::GET_HASH_KEY("t20");
		int hash2_EMP = GAMEPLAY::GET_HASH_KEY("hei_prop_heist_emp");
		int hash3_MiniGun = GAMEPLAY::GET_HASH_KEY("prop_minigun_01");
		int hash4_Wheel = GAMEPLAY::GET_HASH_KEY("prop_wheel_01");

		STREAMING::REQUEST_MODEL(hash_T20);
		STREAMING::REQUEST_MODEL(hash2_EMP);
        STREAMING::REQUEST_MODEL(hash3_MiniGun);
		STREAMING::REQUEST_MODEL(hash4_Wheel);

		if (STREAMING::HAS_MODEL_LOADED(hash_T20) && STREAMING::HAS_MODEL_LOADED(hash2_EMP) && STREAMING::HAS_MODEL_LOADED(hash3_MiniGun) && STREAMING::HAS_MODEL_LOADED(hash4_Wheel))
		{
			int EMP = OBJECT::CREATE_OBJECT(hash2_EMP, null.x, null.y, null.z, 1, 0, 1);
			int MiniGun = OBJECT::CREATE_OBJECT(hash3_MiniGun, null1.x, null1.y, null1.z, 1, 0, 1);
			int MiniGun2 = OBJECT::CREATE_OBJECT(hash3_MiniGun, null0.x, null0.y, null0.z, 1, 0, 1);
			int FLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null2.x, null2.y, null2.z, 1, 0, 1);
			int RLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null3.x, null3.y, null3.z, 1, 0, 1);
			int RFWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null4.x, null4.y, null4.z, 1, 0, 1);
			int RRWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null5.x, null5.y, null5.z, 1, 0, 1);

			if (ENTITY::DOES_ENTITY_EXIST(EMP) && ENTITY::DOES_ENTITY_EXIST(MiniGun) && ENTITY::DOES_ENTITY_EXIST(MiniGun2) && ENTITY::DOES_ENTITY_EXIST(FLWheel1)  && ENTITY::DOES_ENTITY_EXIST(RLWheel1) && ENTITY::DOES_ENTITY_EXIST(RFWheel1) && ENTITY::DOES_ENTITY_EXIST(RRWheel1))
			{
				//int Vehicle = CREATE_VEHICLE(hash_T20, get_entity_coords_float(PLAYER_PED_ID()), 0, 1, 0);
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash_T20, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);

				if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
				{
					PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash_T20);
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, true);
					ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true);

					ENTITY::ATTACH_ENTITY_TO_ENTITY(EMP, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(MiniGun, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(MiniGun2, Vehicle, 0, a0.x, a0.y, a0.z, b0.x, b0.y, b0.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(FLWheel1, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(RLWheel1, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(RFWheel1, Vehicle, 0, a4.x, a4.y, a4.z, b4.x, b4.y, b4.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(RRWheel1, Vehicle, 0, a5.x, a5.y, a5.z, b5.x, b5.y, b5.z, 0, 1, 0, 0, 2, 1);

					ENTITY::SET_ENTITY_VISIBLE(Handle, true);	
					return true;
				}
				return false;
			}		
			return false;														
		}
		return false;
	}


	bool buggy  = false;
    bool BumperBuggy()
	{		
		uint Handle = PLAYER::PLAYER_PED_ID();
		Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		//hash1_bumpercar
		Vector3 null0; null0.x = 0, null0.y = 0; null0.z = 0;
		Vector3 a0; a0.x = -0.34, a0.y = 0.32, a0.z = -0.25;
		Vector3 b0; b0.x = 0, b0.y = 0, b0.z = 180;
		//hash2_EMP
		Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
		Vector3 a; a.x = -0.3600, a.y = 1.2100, a.z = -0.4000;//X Coord - Y Coord - Z Coord
		Vector3 b; b.x = -17.5000, b.y = 0.0, b.z = 0.0;//Pitch - Roll - Yaw
		//hash3_engine
		Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
		Vector3 a1; a1.x = -0.3700, a1.y = -1.2100, a1.z = -0.5600;
		Vector3 b1; b1.x = 0.0, b1.y = 0.0, b1.z = -178.7874;
        //hash4_FLWheel1
		Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
		Vector3 a2; a2.x = -1.2000, a2.y = 1.1000, a2.z = -0.5000;
		Vector3 b2; b2.x = 0.0, b2.y = 0.0, b2.z = 91.0000;
		//hash4_FLWheel2
		Vector3 null10; null10.x = 0.0, null10.y = 0.0; null10.z = 0.0;
		Vector3 a10; a10.x = -1.0000, a10.y = 1.1000, a10.z = -0.5000;
		Vector3 b10; b10.x = 0.0, b10.y = 0.0, b10.z = 91.0000;
		//hash4_FRWheel1
		Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
		Vector3 a3; a3.x = 0.5000, a3.y = 1.1000, a3.z = -0.5000;
		Vector3 b3; b3.x = 0.0, b3.y = 0.0, b3.z = -91.0000;
		//hash4_FRWheel2
		Vector3 null11; null11.x = 0.0, null11.y = 0.0; null11.z = 0.0;
		Vector3 a11; a11.x = 0.3000, a11.y = 1.1000, a11.z = -0.5000;
		Vector3 b11; b11.x = 0.0, b11.y = 0.0, b11.z = -91.0000;
		//hash4_RLWheel1
		Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
		Vector3 a4; a4.x = -0.8000, a4.y = -1.4000, a4.z = -0.5000;
		Vector3 b4; b4.x = 0.0, b4.y = 0.0, b4.z = 91.0000;
		//hash4_RLWheel2
		Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
		Vector3 a5; a5.x = -1.0000, a5.y = -1.4000, a5.z = -0.5000;
		Vector3 b5; b5.x = 0.0, b5.y = 0.0, b5.z = 91.0000;
		//hash4_RLWheel3
		Vector3 null6; null6.x = 0.0, null6.y = 0.0; null6.z = 0.0;
		Vector3 a6; a6.x = -1.2000, a6.y = -1.4000, a6.z = -0.5000;
		Vector3 b6; b6.x = 0.0, b6.y = 0.0, b6.z = 91.0000;
		//hash4_RRWheel1
		Vector3 null7; null7.x = 0.0, null7.y = 0.0; null7.z = 0.0;
		Vector3 a7; a7.x = 0.1100, a7.y = -1.4000, a7.z = -0.5000;
		Vector3 b7; b7.x = 0.0, b7.y = 0.0, b7.z = -91.0000;
		//hash4_RRWheel2
		Vector3 null8; null8.x = 0.0, null8.y = 0.0; null8.z = 0.0;
		Vector3 a8; a8.x = 0.3000, a8.y = -1.4000, a8.z = -0.5000;
		Vector3 b8; b8.x = 0.0, b8.y = 0.0, b8.z = -91.0000;
		//hash4_RRWheel3
		Vector3 null9; null9.x = 0.0, null9.y = 0.0; null9.z = 0.0;
		Vector3 a9; a9.x = 0.5000, a9.y = -1.4000, a9.z = -0.5000;
		Vector3 b9; b9.x = 0.0, b9.y = 0.0, b9.z = -91.0000;
		//hash5_exhaust1
		Vector3 null12; null12.x = 0.0, null12.y = 0.0; null12.z = 0.0;
		Vector3 a12; a12.x = -0.5000, a12.y = -1.5000, a12.z = -0.5000;
		Vector3 b12; b12.x = 0.0, b12.y = 179.0000, b12.z = 0.0;
		//hash5_exhaust2
		Vector3 null13; null13.x = 0.0, null13.y = 0.0; null13.z = 0.0;
		Vector3 a13; a13.x = -0.1600, a13.y = -1.5000, a13.z = -0.6900;
		Vector3 b13; b13.x = 0.0, b13.y = 0.0, b13.z = 0.0;

		int hash_blista = GAMEPLAY::GET_HASH_KEY("blista");
		int hash1_bumpercar = GAMEPLAY::GET_HASH_KEY("prop_bumper_car_01");
		int hash2_EMP = GAMEPLAY::GET_HASH_KEY("hei_prop_heist_emp");
		int hash3_engine = GAMEPLAY::GET_HASH_KEY("prop_car_engine_01");
		int hash4_Wheel = GAMEPLAY::GET_HASH_KEY("prop_wheel_01");
		int hash5_exhaust = GAMEPLAY::GET_HASH_KEY("prop_car_exhaust_01");

		STREAMING::REQUEST_MODEL(hash_blista);
		STREAMING::REQUEST_MODEL(hash1_bumpercar);
		STREAMING::REQUEST_MODEL(hash2_EMP);
        STREAMING::REQUEST_MODEL(hash3_engine);
		STREAMING::REQUEST_MODEL(hash4_Wheel);
		STREAMING::REQUEST_MODEL(hash5_exhaust);

		if (STREAMING::HAS_MODEL_LOADED(hash_blista) && STREAMING::HAS_MODEL_LOADED(hash1_bumpercar) &&STREAMING::HAS_MODEL_LOADED(hash2_EMP) && STREAMING::HAS_MODEL_LOADED(hash3_engine) && STREAMING::HAS_MODEL_LOADED(hash4_Wheel) && STREAMING::HAS_MODEL_LOADED(hash5_exhaust))
		{
			int bumpercar = OBJECT::CREATE_OBJECT(hash1_bumpercar, null0.x, null0.y, null0.z, 1, 0, 1);
			int EMP = OBJECT::CREATE_OBJECT(hash2_EMP, null.x, null.y, null.z, 1, 0, 1);
			int engine = OBJECT::CREATE_OBJECT(hash3_engine, null1.x, null1.y, null1.z, 1, 0, 1);
			int FLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null2.x, null2.y, null2.z, 1, 0, 1);
			int FLWheel2 = OBJECT::CREATE_OBJECT(hash4_Wheel, null10.x, null10.y, null10.z, 1, 0, 1);
			int FRWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null3.x, null3.y, null3.z, 1, 0, 1);
			int FRWheel2 = OBJECT::CREATE_OBJECT(hash4_Wheel, null11.x, null11.y, null11.z, 1, 0, 1);
			int RLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null4.x, null4.y, null4.z, 1, 0, 1);
			int RLWheel2 = OBJECT::CREATE_OBJECT(hash4_Wheel, null5.x, null5.y, null5.z, 1, 0, 1);
			int RLWheel3 = OBJECT::CREATE_OBJECT(hash4_Wheel, null6.x, null6.y, null6.z, 1, 0, 1);
			int RRWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null7.x, null7.y, null7.z, 1, 0, 1);
			int RRWheel2 = OBJECT::CREATE_OBJECT(hash4_Wheel, null8.x, null8.y, null8.z, 1, 0, 1);
			int RRWheel3 = OBJECT::CREATE_OBJECT(hash4_Wheel, null9.x, null9.y, null9.z, 1, 0, 1);
			int exhaust1 = OBJECT::CREATE_OBJECT(hash5_exhaust, null12.x, null12.y, null12.z, 1, 0, 1);
			int exhaust2 = OBJECT::CREATE_OBJECT(hash5_exhaust, null13.x, null13.y, null13.z, 1, 0, 1);

			if (ENTITY::DOES_ENTITY_EXIST(bumpercar) && ENTITY::DOES_ENTITY_EXIST(EMP) && ENTITY::DOES_ENTITY_EXIST(engine) && ENTITY::DOES_ENTITY_EXIST(FLWheel1) && ENTITY::DOES_ENTITY_EXIST(FLWheel2) && ENTITY::DOES_ENTITY_EXIST(FRWheel1) && ENTITY::DOES_ENTITY_EXIST(FRWheel2) && ENTITY::DOES_ENTITY_EXIST(RLWheel1) && ENTITY::DOES_ENTITY_EXIST(RLWheel2) && ENTITY::DOES_ENTITY_EXIST(RLWheel3) && ENTITY::DOES_ENTITY_EXIST(RRWheel1) && ENTITY::DOES_ENTITY_EXIST(RRWheel2) && ENTITY::DOES_ENTITY_EXIST(RRWheel3) && ENTITY::DOES_ENTITY_EXIST(exhaust1) && ENTITY::DOES_ENTITY_EXIST(exhaust2))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash_blista, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);

				if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
				{
					PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash_blista);
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, false);
					ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true);

					ENTITY::ATTACH_ENTITY_TO_ENTITY(bumpercar, Vehicle, 0, a0.x, a0.y, a0.z, b0.x, b0.y, b0.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(EMP, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(engine, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(FLWheel1, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(FLWheel2, Vehicle, 0, a10.x, a10.y, a10.z, b10.x, b10.y, b10.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(FRWheel1, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(FRWheel2, Vehicle, 0, a11.x, a11.y, a11.z, b11.x, b11.y, b11.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(RLWheel1, Vehicle, 0, a4.x, a4.y, a4.z, b4.x, b4.y, b4.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(RLWheel2, Vehicle, 0, a5.x, a5.y, a5.z, b5.x, b5.y, b5.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(RLWheel3, Vehicle, 0, a6.x, a6.y, a6.z, b6.x, b6.y, b6.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(RRWheel1, Vehicle, 0, a7.x, a7.y, a7.z, b7.x, b7.y, b7.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(RRWheel2, Vehicle, 0, a8.x, a8.y, a8.z, b8.x, b8.y, b8.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(RRWheel3, Vehicle, 0, a9.x, a9.y, a9.z, b9.x, b9.y, b9.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(exhaust1, Vehicle, 0, a12.x, a12.y, a12.z, b12.x, b12.y, b12.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(exhaust2, Vehicle, 0, a13.x, a13.y, a13.z, b13.x, b13.y, b13.z, 0, 1, 0, 0, 2, 1);

					ENTITY::SET_ENTITY_VISIBLE(Handle, true);	
					return true;
				}
				return false;
			}		
			return false;														
		}
		return false;
	}

	
	bool kart  = false;
    bool GoKart()
	{		
		uint Handle = PLAYER::PLAYER_PED_ID();
		Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		//hash1_carcreeper
		Vector3 null0; null0.x = 0, null0.y = 0; null0.z = 0;
		Vector3 a0; a0.x = -0.3000, a0.y = -0.3000, a0.z = -0.4200;
		Vector3 b0; b0.x = 0, b0.y = 0, b0.z = -180.0000;
		//hash2_compressor
		Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
		Vector3 a; a.x = 0.2300, a.y = -1.1000, a.z = -0.9000;//X Coord - Y Coord - Z Coord
		Vector3 b; b.x = 0.0, b.y = 0.0, b.z = 0.0;//Pitch - Roll - Yaw
		//hash2_compressor2
		Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
		Vector3 a1; a.x = 0.2300, a1.y = -0.7800, a1.z = -0.9700;//X Coord - Y Coord - Z Coord
		Vector3 b1; b.x = 0.0, b1.y = 0.0, b1.z = 180.0000;//Pitch - Roll - Yaw
		//hash3_bumper
		Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
		Vector3 a2; a2.x = -0.3000, a2.y = -1.1500, a2.z = -1.5800;
		Vector3 b2; b2.x = 0.0, b2.y = 0.0, b2.z = -1.0000;
		//hash3_bumper2
		Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
		Vector3 a3; a3.x = -0.3000, a3.y = 0.4500, a3.z = -1.5800;
		Vector3 b3; b3.x = 0.0, b3.y = 0.0, b3.z = -180.0000;
        //hash4_FLWheel1
		Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
		Vector3 a4; a4.x = 0.5760, a4.y = 0.7000, a4.z = -0.1800;
		Vector3 b4; b4.x = 0.0, b4.y = 0.0, b4.z = -89.0000;
		//hash4_FLWheel2
		Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
		Vector3 a5; a5.x = 0.5760, a5.y = -1.5500, a5.z = -0.1800;
		Vector3 b5; b5.x = 0.0, b5.y = 0.0, b5.z = -89.0000;
		//hash4_FRWheel1
		Vector3 null6; null6.x = 0.0, null6.y = 0.0; null6.z = 0.0;
		Vector3 a6; a6.x = 0.6760, a6.y = -1.5500, a6.z = -0.1800;
		Vector3 b6; b6.x = 0.0, b6.y = 0.0, b6.z = -89.0000;
		//hash4_FRWheel2
		Vector3 null7; null7.x = 0.0, null7.y = 0.0; null7.z = 0.0;
		Vector3 a7; a7.x = 0.6360, a7.y = 0.7000, a7.z = -0.1800;
		Vector3 b7; b7.x = 0.0, b7.y = 0.0, b7.z = -89.0000;
		//hash4_RLWheel1
		Vector3 null8; null8.x = 0.0, null8.y = 0.0; null8.z = 0.0;
		Vector3 a8; a8.x = -1.1840, a8.y = 0.7000, a8.z = -0.1800;
		Vector3 b8; b8.x = 0.0, b8.y = 0.0, b8.z = 89.0000;
		//hash4_RLWheel2
		Vector3 null9; null9.x = 0.0, null9.y = 0.0; null9.z = 0.0;
		Vector3 a9; a9.x = -1.1840, a9.y = -1.5500, a9.z = -0.1800;
		Vector3 b9; b9.x = 0.0, b9.y = 0.0, b9.z = 90.9004;
		//hash4_RRWheel1
		Vector3 null10; null10.x = 0.0, null10.y = 0.0; null10.z = 0.0;
		Vector3 a10; a10.x = -1.2740, a10.y = -1.5500, a10.z = -0.1800;
		Vector3 b10; b10.x = 0.0, b10.y = 0.0, b10.z = 90.9004;
        //hash4_RRWheel2
		Vector3 null11; null11.x = 0.0, null11.y = 0.0; null11.z = 0.0;
		Vector3 a11; a11.x = -1.2140, a11.y = 0.7000, a11.z = -0.1800;
		Vector3 b11; b11.x = 0.0, b11.y = 0.0, b11.z = 90.9004;
        //hash5_carjack
		Vector3 null12; null12.x = 0.0, null12.y = 0.0; null12.z = 0.0;
		Vector3 a12; a12.x = -0.3000, a12.y = 0.2000, a12.z = 0.3300;
		Vector3 b12; b12.x = 137.1005, b12.y = 0.0, b12.z = 0.0;
		//hash6_laptop
		Vector3 null13; null13.x = 0.0, null13.y = 0.0; null13.z = 0.0;
		Vector3 a13; a13.x = 0.2300, a13.y = -0.4200, a13.z = -0.1300;
		Vector3 b13; b13.x = -66.0999, b13.y = -7.0000, b13.z = -3.0000;
		//hash7_seat
		Vector3 null14; null14.x = 0.0, null14.y = 0.0; null14.z = 0.0;
		Vector3 a14; a14.x = -0.3000, a14.y = -0.9000, a14.z = -0.2000;
		Vector3 b14; b14.x = 0.0, b14.y = 0.0, b14.z = -179.0000;
		//hash5_carjack2
		Vector3 null15; null15.x = 0.0, null15.y = 0.0; null15.z = 0.0;
		Vector3 a15; a15.x = 0.1000, a15.y = 0.3000, a15.z = -0.8700;
		Vector3 b15; b15.x = 65.8006, b15.y = 0.0, b15.z = 0.0;
		//hash8_minigun
		Vector3 null16; null16.x = 0.0, null16.y = 0.0; null16.z = 0.0;
		Vector3 a16; a16.x = 0.1000, a16.y = -1.5400, a16.z = -0.1500;
		Vector3 b16; b16.x = 0.0, b16.y = 0.0, b16.z = 0.0;
		//hash8_minigun2
		Vector3 null17; null17.x = 0.0, null17.y = 0.0; null17.z = 0.0;
		Vector3 a17; a17.x = -0.6900, a17.y = -1.5400, a17.z = -0.1500;
		Vector3 b17; b17.x = 0.0, b17.y = 0.0, b17.z = -180.0000;
		//hash9_controller
		Vector3 null18; null18.x = 0.0, null18.y = 0.0; null18.z = 0.0;
		Vector3 a18; a18.x = -0.3600, a18.y = -0.2400, a18.z = 0.5000;
		Vector3 b18; b18.x = -11.0000, b18.y = -87.0000, b18.z = 0.0;
		//hash9_controller2
		Vector3 null19; null19.x = 0.0, null19.y = 0.0; null19.z = 0.0;
		Vector3 a19; a19.x = -0.2400, a19.y = -0.2400, a19.z = 0.5000;
		Vector3 b19; b19.x = -11.0000, b19.y = 83.0000, b19.z = 0.0;

		int hash_adder = GAMEPLAY::GET_HASH_KEY("adder");
		int hash1_carcreeper = GAMEPLAY::GET_HASH_KEY("prop_carcreeper");
		int hash2_compressor = GAMEPLAY::GET_HASH_KEY("prop_compressor_03");
		int hash3_bumper = GAMEPLAY::GET_HASH_KEY("prop_bumper_03");
		int hash4_Wheel = GAMEPLAY::GET_HASH_KEY("prop_wheel_03");
		int hash5_carjack = GAMEPLAY::GET_HASH_KEY("prop_carjack");
		int hash6_laptop = GAMEPLAY::GET_HASH_KEY("prop_laptop_jimmy");
		int hash7_seat = GAMEPLAY::GET_HASH_KEY("prop_car_seat");
        int hash8_minigun = GAMEPLAY::GET_HASH_KEY("prop_minigun_01");
		int hash9_controller = GAMEPLAY::GET_HASH_KEY("prop_controller_01");
		//int hash8_exhaust = GAMEPLAY::GET_HASH_KEY("prop_car_exhaust_01");
		//int hash6_minigun = GAMEPLAY::GET_HASH_KEY("prop_minigun_01");
		//int hash10_lampa = GAMEPLAY::GET_HASH_KEY("v_ilev_fh_lampa_on");
		//int hash11_alarm = GAMEPLAY::GET_HASH_KEY("hei_prop_wall_alarm_off");
		//int hash12_controller = GAMEPLAY::GET_HASH_KEY("prop_controller-01");

		STREAMING::REQUEST_MODEL(hash_adder);
		STREAMING::REQUEST_MODEL(hash1_carcreeper);
		STREAMING::REQUEST_MODEL(hash2_compressor);
        STREAMING::REQUEST_MODEL(hash3_bumper);
		STREAMING::REQUEST_MODEL(hash4_Wheel);
		STREAMING::REQUEST_MODEL(hash5_carjack);
		STREAMING::REQUEST_MODEL(hash6_laptop);
		STREAMING::REQUEST_MODEL(hash7_seat);
		STREAMING::REQUEST_MODEL(hash8_minigun);
		STREAMING::REQUEST_MODEL(hash9_controller);
		//STREAMING::REQUEST_MODEL(hash8_exhaust);
		//STREAMING::REQUEST_MODEL(hash6_minigun);
		//STREAMING::REQUEST_MODEL(hash10_lampa);
		//STREAMING::REQUEST_MODEL(hash11_alarm);
		//STREAMING::REQUEST_MODEL(hash12_controller);

		if (STREAMING::HAS_MODEL_LOADED(hash_adder) && STREAMING::HAS_MODEL_LOADED(hash1_carcreeper) &&STREAMING::HAS_MODEL_LOADED(hash2_compressor) && STREAMING::HAS_MODEL_LOADED(hash3_bumper) && STREAMING::HAS_MODEL_LOADED(hash4_Wheel) && STREAMING::HAS_MODEL_LOADED(hash5_carjack) && STREAMING::HAS_MODEL_LOADED(hash6_laptop) && STREAMING::HAS_MODEL_LOADED(hash7_seat) && STREAMING::HAS_MODEL_LOADED(hash8_minigun) && STREAMING::HAS_MODEL_LOADED(hash9_controller)) //&& STREAMING::HAS_MODEL_LOADED(hash8_exhaust) && STREAMING::HAS_MODEL_LOADED(hash9_seat) && STREAMING::HAS_MODEL_LOADED(hash10_lampa) && STREAMING::HAS_MODEL_LOADED(hash11_alarm) && STREAMING::HAS_MODEL_LOADED(hash12_controller))
		{
			int carcreeper = OBJECT::CREATE_OBJECT(hash1_carcreeper, null0.x, null0.y, null0.z, 1, 0, 1);
			int compressor = OBJECT::CREATE_OBJECT(hash2_compressor, null.x, null.y, null.z, 1, 0, 1);
			int compressor2 = OBJECT::CREATE_OBJECT(hash2_compressor, null1.x, null1.y, null1.z, 1, 0, 1);
			int bumper = OBJECT::CREATE_OBJECT(hash3_bumper, null2.x, null2.y, null2.z, 1, 0, 1);
			int bumper2 = OBJECT::CREATE_OBJECT(hash3_bumper, null3.x, null3.y, null3.z, 1, 0, 1);
			int FLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null4.x, null4.y, null4.z, 1, 0, 1);
			int FLWheel2 = OBJECT::CREATE_OBJECT(hash4_Wheel, null5.x, null5.y, null5.z, 1, 0, 1);
			int FRWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null6.x, null6.y, null6.z, 1, 0, 1);
			int FRWheel2 = OBJECT::CREATE_OBJECT(hash4_Wheel, null7.x, null7.y, null7.z, 1, 0, 1);
			int RLWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null8.x, null8.y, null8.z, 1, 0, 1);
			int RLWheel2 = OBJECT::CREATE_OBJECT(hash4_Wheel, null9.x, null9.y, null9.z, 1, 0, 1);
			int RRWheel1 = OBJECT::CREATE_OBJECT(hash4_Wheel, null10.x, null10.y, null10.z, 1, 0, 1);
			int RRWheel2 = OBJECT::CREATE_OBJECT(hash4_Wheel, null11.x, null11.y, null11.z, 1, 0, 1);
            int carjack = OBJECT::CREATE_OBJECT(hash5_carjack, null12.x, null12.y, null12.z, 1, 0, 1);
			int laptop = OBJECT::CREATE_OBJECT(hash6_laptop, null13.x, null13.y, null13.z, 1, 0, 1);
			//int exhaust = OBJECT::CREATE_OBJECT(hash8_exhaust, null13.x, null13.y, null13.z, 1, 0, 1);
			int seat = OBJECT::CREATE_OBJECT(hash7_seat, null14.x, null14.y, null14.z, 1, 0, 1);
			int carjack2 = OBJECT::CREATE_OBJECT(hash5_carjack, null15.x, null15.y, null15.z, 1, 0, 1);
			int minigun = OBJECT::CREATE_OBJECT(hash8_minigun, null16.x, null16.y, null16.z, 1, 0, 1);
			int minigun2 = OBJECT::CREATE_OBJECT(hash8_minigun, null17.x, null17.y, null17.z, 1, 0, 1);
			int controller = OBJECT::CREATE_OBJECT(hash9_controller, null18.x, null18.y, null18.z, 1, 0, 1);
			int controller2 = OBJECT::CREATE_OBJECT(hash9_controller, null19.x, null19.y, null19.z, 1, 0, 1);

			if (ENTITY::DOES_ENTITY_EXIST(carcreeper) && ENTITY::DOES_ENTITY_EXIST(compressor) && ENTITY::DOES_ENTITY_EXIST(compressor2) && ENTITY::DOES_ENTITY_EXIST(bumper) && ENTITY::DOES_ENTITY_EXIST(bumper2) && ENTITY::DOES_ENTITY_EXIST(FLWheel1) && ENTITY::DOES_ENTITY_EXIST(FLWheel2) && ENTITY::DOES_ENTITY_EXIST(FRWheel1) && ENTITY::DOES_ENTITY_EXIST(FRWheel2) && ENTITY::DOES_ENTITY_EXIST(RLWheel1) && ENTITY::DOES_ENTITY_EXIST(RLWheel2) && ENTITY::DOES_ENTITY_EXIST(RRWheel1) && ENTITY::DOES_ENTITY_EXIST(RRWheel2) && ENTITY::DOES_ENTITY_EXIST(carjack) && ENTITY::DOES_ENTITY_EXIST(carjack2) && ENTITY::DOES_ENTITY_EXIST(laptop) && ENTITY::DOES_ENTITY_EXIST(minigun) && ENTITY::DOES_ENTITY_EXIST(seat) && ENTITY::DOES_ENTITY_EXIST(minigun2) && ENTITY::DOES_ENTITY_EXIST(controller) && ENTITY::DOES_ENTITY_EXIST(controller2))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash_adder, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);

				if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
				{
					PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash_adder);
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, false);
					ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true);

					ENTITY::ATTACH_ENTITY_TO_ENTITY(carcreeper, Vehicle, 0, a0.x, a0.y, a0.z, b0.x, b0.y, b0.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(compressor, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(compressor2, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(bumper, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(bumper2, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(FLWheel1, Vehicle, 0, a4.x, a4.y, a4.z, b4.x, b4.y, b4.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(FLWheel2, Vehicle, 0, a5.x, a5.y, a5.z, b5.x, b5.y, b5.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(FRWheel1, Vehicle, 0, a6.x, a6.y, a6.z, b6.x, b6.y, b6.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(FRWheel2, Vehicle, 0, a7.x, a7.y, a7.z, b7.x, b7.y, b7.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(RLWheel1, Vehicle, 0, a8.x, a8.y, a8.z, b8.x, b8.y, b8.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(RLWheel2, Vehicle, 0, a9.x, a9.y, a9.z, b9.x, b9.y, b9.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(RRWheel1, Vehicle, 0, a10.x, a10.y, a10.z, b10.x, b10.y, b10.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(RRWheel2, Vehicle, 0, a11.x, a11.y, a11.z, b11.x, b11.y, b11.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(carjack, Vehicle, 0, a12.x, a12.y, a12.z, b12.x, b12.y, b12.z, 0, 1, 0, 0, 2, 1);
                    ENTITY::ATTACH_ENTITY_TO_ENTITY(laptop, Vehicle, 0, a13.x, a13.y, a13.z, b13.x, b13.y, b13.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(seat, Vehicle, 0, a14.x, a14.y, a14.z, b14.x, b14.y, b14.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(carjack2, Vehicle, 0, a15.x, a15.y, a15.z, b15.x, b15.y, b15.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(minigun, Vehicle, 0, a16.x, a16.y, a16.z, b16.x, b16.y, b16.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(minigun2, Vehicle, 0, a17.x, a17.y, a17.z, b17.x, b17.y, b17.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(controller, Vehicle, 0, a18.x, a18.y, a18.z, b18.x, b18.y, b18.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(controller2, Vehicle, 0, a19.x, a19.y, a19.z, b19.x, b19.y, b19.z, 0, 1, 0, 0, 2, 1);

					ENTITY::SET_ENTITY_VISIBLE(Handle, true);	
					return true;
				}
				return false;
			}		
			return false;														
		}
		return false;
	}
		
	
	bool starwars  = false;
    bool spawnstarwars()
	{		
		uint Handle = PLAYER::PLAYER_PED_ID();
		Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		//hash1_carcreeper
		Vector3 null0; null0.x = 0, null0.y = 0; null0.z = 0;
		Vector3 a0; a0.x = -0.4000, a0.y = -0.4000, a0.z = 1.0000;
		Vector3 b0; b0.x = 19.0000, b0.y = 0, b0.z = 0.0;
		//hash1_carcreeper2
		Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
		Vector3 a; a.x = -0.4000, a.y = 1.5000, a.z = 0.8000;//X Coord - Y Coord - Z Coord
		Vector3 b; b.x = 30.7000, b.y = 0.0, b.z = 178.000;//Pitch - Roll - Yaw
		//hash1_carcreeper3
		Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
		Vector3 a1; a.x = -0.4000, a1.y = 1.5000, a1.z = -0.1000;//X Coord - Y Coord - Z Coord
		Vector3 b1; b.x = -16.3000, b1.y = 0.0, b1.z = 178.0000;//Pitch - Roll - Yaw
		//hash1_carcreeper4
		Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
		Vector3 a2; a2.x = -0.4000, a2.y = -0.3000, a2.z = 0.2000;
		Vector3 b2; b2.x = 35.9001, b2.y = 0.0, b2.z = 178.0000;
		//hash1_carcreeper5
		Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
		Vector3 a3; a3.x = -0.7000, a3.y = 1.3000, a3.z = 0.7000;
		Vector3 b3; b3.x = 35.9001, b3.y = 64.6000, b3.z = 175.7999;
        //hash1_carcreeper6
		Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
		Vector3 a4; a4.x = -0.1000, a4.y = 1.3000, a4.z = 0.7000;
		Vector3 b4; b4.x = 35.9001, b4.y = -67.8000, b4.z = -176.6998;
		//hash1_carcreeper7
		Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
		Vector3 a5; a5.x = -0.4500, a5.y = -1.9100, a5.z = 0.7000;
		Vector3 b5; b5.x = 3.9001, b5.y = -0.8000, b5.z = 179.0000;
		//hash1_carcreeper8
		Vector3 null6; null6.x = 0.0, null6.y = 0.0; null6.z = 0.0;
		Vector3 a6; a6.x = 0.2500, a6.y = -2.4100, a6.z = 0.7000;
		Vector3 b6; b6.x = 1.9001, b6.y = -0.8000, b6.z = 89.4000;
		//hash1_carcreeper9
		Vector3 null7; null7.x = 0.0, null7.y = 0.0; null7.z = 0.0;
		Vector3 a7; a7.x = -1.2500, a7.y = -2.4100, a7.z = 0.7000;
		Vector3 b7; b7.x = 1.9001, b7.y = -0.8000, b7.z = -91.6000;
		//hash1_carcreeper10
		Vector3 null8; null8.x = 0.0, null8.y = 0.0; null8.z = 0.0;
		Vector3 a8; a8.x = -1.1500, a8.y = -2.4100, a8.z = 1.0000;
		Vector3 b8; b8.x = -47.0999, b8.y = -0.8000, b8.z = -91.6000;
		//hash1_carcreeper11
		Vector3 null9; null9.x = 0.0, null9.y = 0.0; null9.z = 0.0;
		Vector3 a9; a9.x = 0.3300, a9.y = -2.4100, a9.z = 1.0000;
		Vector3 b9; b9.x = -47.0999, b9.y = -0.8000, b9.z = 92.0000;
		//hash1_carcreeper12
		Vector3 null10; null10.x = 0.0, null10.y = 0.0; null10.z = 0.0;
		Vector3 a10; a10.x = 0.8300, a10.y = 0.6900, a10.z = 0.2000;
		Vector3 b10; b10.x = -19.0999, b10.y = -0.8000, b10.z = 89.9000;
        //hash1_carcreeper13
		Vector3 null11; null11.x = 0.0, null11.y = 0.0; null11.z = 0.0;
		Vector3 a11; a11.x = -1.7100, a11.y = 0.7100, a11.z = 0.2100;
		Vector3 b11; b11.x = -19.0999, b11.y = -0.8000, b11.z = -91.2000;
        //hash1_carcreeper14
		Vector3 null12; null12.x = 0.0, null12.y = 0.0; null12.z = 0.0;
		Vector3 a12; a12.x = -2.5200, a12.y = 0.7100, a12.z = 0.6100;
		Vector3 b12; b12.x = 48.9001, b12.y = -0.8000, b12.z = -91.2000;
		//hash1_carcreeper15
		Vector3 null13; null13.x = 0.0, null13.y = 0.0; null13.z = 0.0;
		Vector3 a13; a13.x = 1.6800, a13.y = 0.7100, a13.z = 0.6100;
		Vector3 b13; b13.x = 48.9001, b13.y = -0.8000, b13.z = 91.0000;
		//hash2_engine
		Vector3 null14; null14.x = 0.0, null14.y = 0.0; null14.z = 0.0;
		Vector3 a14; a14.x = -0.5000, a14.y = -0.7000, a14.z = 1.0000;
		Vector3 b14; b14.x = 0.0, b14.y = 0.0, b14.z = 0.0;
		//hash3_minigun
		Vector3 null15; null15.x = 0.0, null15.y = 0.0; null15.z = 0.0;
		Vector3 a15; a15.x = -0.1000, a15.y = 2.7000, a15.z = 0.2000;
		Vector3 b15; b15.x = 0.0, b15.y = 0.0, b15.z = 88.0000;
		//hash3_minigun2
		Vector3 null16; null16.x = 0.0, null16.y = 0.0; null16.z = 0.0;
		Vector3 a16; a16.x = -0.6000, a16.y = 2.7000, a16.z = 0.2000;
		Vector3 b16; b16.x = 0.0, b16.y = 0.0, b16.z = 88.0000;
		//hash3_minigun3
		Vector3 null17; null17.x = 0.0, null17.y = 0.0; null17.z = 0.0;
		Vector3 a17; a17.x = -3.4000, a17.y = 1.3000, a17.z = 0.0;
		Vector3 b17; b17.x = 0.0, b17.y = 0.0, b17.z = 88.0000;
		//hash3_minigun4
		Vector3 null18; null18.x = 0.0, null18.y = 0.0; null18.z = 0.0;
		Vector3 a18; a18.x = 2.6000, a18.y = 1.3000, a18.z = 0.0;
		Vector3 b18; b18.x = 0.0, b18.y = 0.0, b18.z = 88.0000;
		//hash4_seat
		Vector3 null19; null19.x = 0.0, null19.y = 0.0; null19.z = 0.0;
		Vector3 a19; a19.x = -0.3000, a19.y = 0.6000, a19.z = 0.0;
		Vector3 b19; b19.x = 0.0, b19.y = 0.0, b19.z = 180.0000;
		//hash5_emp
		Vector3 null20; null20.x = 0.0, null20.y = 0.0; null20.z = 0.0;
		Vector3 a20; a20.x = -0.3900, a20.y = -0.6000, a20.z = 0.6200;
		Vector3 b20; b20.x = 0.0, b20.y = 0.0, b20.z = 0.0;

		int hash_buzzard = GAMEPLAY::GET_HASH_KEY("buzzard");
		int hash1_carcreeper = GAMEPLAY::GET_HASH_KEY("prop_carcreeper");
		int hash2_engine = GAMEPLAY::GET_HASH_KEY("prop_car_engine_01");
		int hash3_minigun = GAMEPLAY::GET_HASH_KEY("prop_minigun_01");
		int hash4_seat = GAMEPLAY::GET_HASH_KEY("prop_car_seat");
		int hash5_emp = GAMEPLAY::GET_HASH_KEY("hei_prop_heist_emp");


		STREAMING::REQUEST_MODEL(hash_buzzard);
		STREAMING::REQUEST_MODEL(hash1_carcreeper);
		STREAMING::REQUEST_MODEL(hash2_engine);
        STREAMING::REQUEST_MODEL(hash3_minigun);
		STREAMING::REQUEST_MODEL(hash4_seat);
		STREAMING::REQUEST_MODEL(hash5_emp);

		if (STREAMING::HAS_MODEL_LOADED(hash_buzzard) && STREAMING::HAS_MODEL_LOADED(hash1_carcreeper) &&STREAMING::HAS_MODEL_LOADED(hash2_engine) && STREAMING::HAS_MODEL_LOADED(hash3_minigun) && STREAMING::HAS_MODEL_LOADED(hash4_seat) && STREAMING::HAS_MODEL_LOADED(hash5_emp)) 
		{
			int carcreeper = OBJECT::CREATE_OBJECT(hash1_carcreeper, null0.x, null0.y, null0.z, 1, 0, 1);
            int carcreeper2 = OBJECT::CREATE_OBJECT(hash1_carcreeper, null.x, null.y, null.z, 1, 0, 1);
			int carcreeper3 = OBJECT::CREATE_OBJECT(hash1_carcreeper, null1.x, null1.y, null1.z, 1, 0, 1);
			int carcreeper4 = OBJECT::CREATE_OBJECT(hash1_carcreeper, null2.x, null2.y, null2.z, 1, 0, 1);
			int carcreeper5 = OBJECT::CREATE_OBJECT(hash1_carcreeper, null3.x, null3.y, null3.z, 1, 0, 1);
			int carcreeper6 = OBJECT::CREATE_OBJECT(hash1_carcreeper, null4.x, null4.y, null4.z, 1, 0, 1);
			int carcreeper7 = OBJECT::CREATE_OBJECT(hash1_carcreeper, null5.x, null5.y, null5.z, 1, 0, 1);
			int carcreeper8 = OBJECT::CREATE_OBJECT(hash1_carcreeper, null6.x, null6.y, null6.z, 1, 0, 1);
			int carcreeper9 = OBJECT::CREATE_OBJECT(hash1_carcreeper, null7.x, null7.y, null7.z, 1, 0, 1);
			int carcreeper10 = OBJECT::CREATE_OBJECT(hash1_carcreeper, null8.x, null8.y, null8.z, 1, 0, 1);
			int carcreeper11 = OBJECT::CREATE_OBJECT(hash1_carcreeper, null9.x, null9.y, null9.z, 1, 0, 1);
			int carcreeper12 = OBJECT::CREATE_OBJECT(hash1_carcreeper, null10.x, null10.y, null10.z, 1, 0, 1);
			int carcreeper13 = OBJECT::CREATE_OBJECT(hash1_carcreeper, null11.x, null11.y, null11.z, 1, 0, 1);
			int carcreeper14 = OBJECT::CREATE_OBJECT(hash1_carcreeper, null12.x, null12.y, null12.z, 1, 0, 1);
			int carcreeper15 = OBJECT::CREATE_OBJECT(hash1_carcreeper, null13.x, null13.y, null13.z, 1, 0, 1);
			int engine = OBJECT::CREATE_OBJECT(hash2_engine, null14.x, null14.y, null14.z, 1, 0, 1);
			int minigun = OBJECT::CREATE_OBJECT(hash3_minigun, null15.x, null15.y, null15.z, 1, 0, 1);
			int minigun2 = OBJECT::CREATE_OBJECT(hash3_minigun, null16.x, null16.y, null16.z, 1, 0, 1);
			int minigun3 = OBJECT::CREATE_OBJECT(hash3_minigun, null17.x, null17.y, null17.z, 1, 0, 1);
			int minigun4 = OBJECT::CREATE_OBJECT(hash3_minigun, null18.x, null18.y, null18.z, 1, 0, 1);
			int seat = OBJECT::CREATE_OBJECT(hash4_seat, null19.x, null19.y, null19.z, 1, 0, 1);
			int emp = OBJECT::CREATE_OBJECT(hash5_emp, null20.x, null20.y, null20.z, 1, 0, 1);

			if (ENTITY::DOES_ENTITY_EXIST(carcreeper) && ENTITY::DOES_ENTITY_EXIST(carcreeper2) && ENTITY::DOES_ENTITY_EXIST(carcreeper3) && ENTITY::DOES_ENTITY_EXIST(carcreeper4) && ENTITY::DOES_ENTITY_EXIST(carcreeper5) && ENTITY::DOES_ENTITY_EXIST(carcreeper6) && ENTITY::DOES_ENTITY_EXIST(carcreeper7) && ENTITY::DOES_ENTITY_EXIST(carcreeper8) && ENTITY::DOES_ENTITY_EXIST(carcreeper9) && ENTITY::DOES_ENTITY_EXIST(carcreeper11) && ENTITY::DOES_ENTITY_EXIST(carcreeper12) && ENTITY::DOES_ENTITY_EXIST(carcreeper13) && ENTITY::DOES_ENTITY_EXIST(carcreeper14) && ENTITY::DOES_ENTITY_EXIST(carcreeper15) && ENTITY::DOES_ENTITY_EXIST(engine) && ENTITY::DOES_ENTITY_EXIST(minigun) && ENTITY::DOES_ENTITY_EXIST(minigun) && ENTITY::DOES_ENTITY_EXIST(minigun2) && ENTITY::DOES_ENTITY_EXIST(minigun3) && ENTITY::DOES_ENTITY_EXIST(minigun4) && ENTITY::DOES_ENTITY_EXIST(seat) && ENTITY::DOES_ENTITY_EXIST(emp))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash_buzzard, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);

				if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
				{
					PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash_buzzard);
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, false);
					ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true);

					ENTITY::ATTACH_ENTITY_TO_ENTITY(carcreeper, Vehicle, 0, a0.x, a0.y, a0.z, b0.x, b0.y, b0.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(carcreeper2, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(carcreeper3, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(carcreeper4, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(carcreeper5, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(carcreeper6, Vehicle, 0, a4.x, a4.y, a4.z, b4.x, b4.y, b4.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(carcreeper7, Vehicle, 0, a5.x, a5.y, a5.z, b5.x, b5.y, b5.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(carcreeper8, Vehicle, 0, a6.x, a6.y, a6.z, b6.x, b6.y, b6.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(carcreeper9, Vehicle, 0, a7.x, a7.y, a7.z, b7.x, b7.y, b7.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(carcreeper10, Vehicle, 0, a8.x, a8.y, a8.z, b8.x, b8.y, b8.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(carcreeper11, Vehicle, 0, a9.x, a9.y, a9.z, b9.x, b9.y, b9.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(carcreeper12, Vehicle, 0, a10.x, a10.y, a10.z, b10.x, b10.y, b10.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(carcreeper13, Vehicle, 0, a11.x, a11.y, a11.z, b11.x, b11.y, b11.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(carcreeper14, Vehicle, 0, a12.x, a12.y, a12.z, b12.x, b12.y, b12.z, 0, 1, 0, 0, 2, 1);
                    ENTITY::ATTACH_ENTITY_TO_ENTITY(carcreeper15, Vehicle, 0, a13.x, a13.y, a13.z, b13.x, b13.y, b13.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(engine, Vehicle, 0, a14.x, a14.y, a14.z, b14.x, b14.y, b14.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(minigun, Vehicle, 0, a15.x, a15.y, a15.z, b15.x, b15.y, b15.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(minigun2, Vehicle, 0, a16.x, a16.y, a16.z, b16.x, b16.y, b16.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(minigun3, Vehicle, 0, a17.x, a17.y, a17.z, b17.x, b17.y, b17.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(minigun4, Vehicle, 0, a18.x, a18.y, a18.z, b18.x, b18.y, b18.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(seat, Vehicle, 0, a19.x, a19.y, a19.z, b19.x, b19.y, b19.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(emp, Vehicle, 0, a20.x, a20.y, a20.z, b20.x, b20.y, b20.z, 0, 1, 0, 0, 2, 1);

					ENTITY::SET_ENTITY_VISIBLE(Handle, true);	
					return true;
				}
				return false;
			}		
			return false;														
		}
		return false;
	}

	bool starwars2  = false;
    bool spawnstarwars2()
	{		
		uint Handle = PLAYER::PLAYER_PED_ID();
		Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		//hash1_cell
		Vector3 null0; null0.x = 0, null0.y = 0; null0.z = 0;
		Vector3 a0; a0.x = 0.0, a0.y = -0.1000, a0.z = 0.4000;
		Vector3 b0; b0.x = 0.0, b0.y = 0, b0.z = 0.0;
		//hash1_cell2
		Vector3 null; null.x = 0.0, null.y = 0.0; null.z = 0.0;
		Vector3 a; a.x = 0.0, a.y = 0.2000, a.z = 0.4000;//X Coord - Y Coord - Z Coord
		Vector3 b; b.x = 0.0, b.y = 0.0, b.z = 0.0;//Pitch - Roll - Yaw
		//hash1_cell3
		Vector3 null1; null1.x = 0.0, null1.y = 0.0; null1.z = 0.0;
		Vector3 a1; a.x = 0.0, a1.y = 0.4200, a1.z = 0.4500;//X Coord - Y Coord - Z Coord
		Vector3 b1; b.x = 23.0000, b1.y = 0.0, b1.z = 0.0;//Pitch - Roll - Yaw
		//hash1_cell4
		Vector3 null2; null2.x = 0.0, null2.y = 0.0; null2.z = 0.0;
		Vector3 a2; a2.x = 0.0, a2.y = 0.7300, a2.z = 0.5000;
		Vector3 b2; b2.x = -47.0001, b2.y = 0.0, b2.z = 0.0;
		//hash1_cell5
		Vector3 null3; null3.x = 0.0, null3.y = 0.0; null3.z = 0.0;
		Vector3 a3; a3.x = 0.0, a3.y = 0.8300, a3.z = 0.4000;
		Vector3 b3; b3.x = -47.0001, b3.y = 0.0, b3.z = 0.0;
        //hash1_cell6
		Vector3 null4; null4.x = 0.0, null4.y = 0.0; null4.z = 0.0;
		Vector3 a4; a4.x = 0.0, a4.y = 0.3300, a4.z = 0.4000;
		Vector3 b4; b4.x = -47.0001, b4.y = 0.0, b4.z = 0.0;
		//hash1_cell7
		Vector3 null5; null5.x = 0.0, null5.y = 0.0; null5.z = 0.0;
		Vector3 a5; a5.x = 0.0, a5.y = -0.3200, a5.z = 0.2500;
		Vector3 b5; b5.x = -149.0000, b5.y = 0.0, b5.z = 0.0;
		//hash1_cell8
		Vector3 null6; null6.x = 0.0, null6.y = 0.0; null6.z = 0.0;
		Vector3 a6; a6.x = 0.0, a6.y = -0.3200, a6.z = 0.1000;
		Vector3 b6; b6.x = 179.0000, b6.y = 0.0, b6.z = 0.0;
		//hash2_wheel
		Vector3 null7; null7.x = 0.0, null7.y = 0.0; null7.z = 0.0;
		Vector3 a7; a7.x = 0.0100, a7.y = 1.2400, a7.z = 0.0;
		Vector3 b7; b7.x = 0.0, b7.y = 0.0, b7.z = -91.0000;
		//hash2_wheel2
		Vector3 null8; null8.x = 0.0, null8.y = 0.0; null8.z = 0.0;
		Vector3 a8; a8.x = 0.0100, a8.y = -0.8600, a8.z = 0.0;
		Vector3 b8; b8.x = 0.0, b8.y = -0.0, b8.z = -91.0000;
		//hash2_wheel3
		Vector3 null9; null9.x = 0.0, null9.y = 0.0; null9.z = 0.0;
		Vector3 a9; a9.x = 0.0100, a9.y = -0.8600, a9.z = 0.0;
		Vector3 b9; b9.x = 0.0, b9.y = 0.0, b9.z = 89.0000;
		//hash2_wheel4
		Vector3 null10; null10.x = 0.0, null10.y = 0.0; null10.z = 0.0;
		Vector3 a10; a10.x = 0.0100, a10.y = 1.2400, a10.z = 0.0;
		Vector3 b10; b10.x = 0.0, b10.y = 0.0, b10.z = 89.0000;
        //hash3_minigun
		Vector3 null11; null11.x = 0.0, null11.y = 0.0; null11.z = 0.0;
		Vector3 a11; a11.x = 0.0, a11.y = -0.0300, a11.z = 0.0500;
		Vector3 b11; b11.x = 0.0, b11.y = 0.0, b11.z = -91.0000;
        //hash3_minigun2
		Vector3 null12; null12.x = 0.0, null12.y = 0.0; null12.z = 0.0;
		Vector3 a12; a12.x = 0.0, a12.y = -0.0200, a12.z = 0.2200;
		Vector3 b12; b12.x = 0.0, b12.y = 0.0, b12.z = -91.0000;
		//hash3_minigun3
		Vector3 null13; null13.x = 0.0, null13.y = 0.0; null13.z = 0.0;
		Vector3 a13; a13.x = 0.0, a13.y = 0.8500, a13.z = 0.3400;
		Vector3 b13; b13.x = -1.2400, b13.y = 136.0597, b13.z = 91.0000;
		//hash4_alarm
		Vector3 null14; null14.x = 0.0, null14.y = 0.0; null14.z = 0.0;
		Vector3 a14; a14.x = 0.0, a14.y = -0.2900, a14.z = 0.3000;
		Vector3 b14; b14.x = 0.0, b14.y = 0.0, b14.z = 0.0;
		//hash4_alarm2
		Vector3 null15; null15.x = 0.0, null15.y = 0.0; null15.z = 0.0;
		Vector3 a15; a15.x = 0.0, a15.y = 0.8700, a15.z = 0.6000;
		Vector3 b15; b15.x = 0.0, b15.y = 0.0, b15.z = 0.0;
		//hash5_light
		Vector3 null16; null16.x = 0.0, null16.y = 0.0; null16.z = 0.0;
		Vector3 a16; a16.x = 0.0, a16.y = 0.3600, a16.z = 0.4700;
		Vector3 b16; b16.x = -90.0000, b16.y = 0.0, b16.z = 0.0;
		//hash5_light2
		Vector3 null17; null17.x = 0.0, null17.y = 0.0; null17.z = 0.0;
		Vector3 a17; a17.x = 0.0, a17.y = 0.2700, a17.z = 0.4700;
		Vector3 b17; b17.x = 99.7998, b17.y = 0.0, b17.z = 0.0;
		//hash6_controller
		Vector3 null18; null18.x = 0.0, null18.y = 0.0; null18.z = 0.0;
		Vector3 a18; a18.x = -0.1700, a18.y = 0.5600, a18.z = 0.6000;
		Vector3 b18; b18.x = -53.0000, b18.y = -29.5500, b18.z = 0.0;
		//hash6_controller2
		Vector3 null19; null19.x = 0.0, null19.y = 0.0; null19.z = 0.0;
		Vector3 a19; a19.x = 0.1800, a19.y = 0.5600, a19.z = 0.6000;
		Vector3 b19; b19.x = -53.0000, b19.y = 37.0900, b19.z = 0.0;
		//hash7_overlay
		Vector3 null20; null20.x = 0.0, null20.y = 0.0; null20.z = 0.0;
		Vector3 a20; a20.x = 0.0100, a20.y = 0.7200, a20.z = 0.7000;
		Vector3 b20; b20.x = -42.0000, b20.y = 0.0, b20.z = 0.0;

		int hash_bati2 = GAMEPLAY::GET_HASH_KEY("bati2");
		int hash1_cell = GAMEPLAY::GET_HASH_KEY("prop_power_cell");
		int hash2_wheel = GAMEPLAY::GET_HASH_KEY("prop_wheel_01");
		int hash3_minigun = GAMEPLAY::GET_HASH_KEY("prop_minigun_01");
		int hash4_alarm = GAMEPLAY::GET_HASH_KEY("hei_prop_wall_alarm_on");
		int hash5_light = GAMEPLAY::GET_HASH_KEY("hei_prop_wall_light_10a_cr");
		int hash6_controller = GAMEPLAY::GET_HASH_KEY("prop_controller_01");
		int hash7_overlay = GAMEPLAY::GET_HASH_KEY("prop_lift_overlay_01");


		STREAMING::REQUEST_MODEL(hash_bati2);
		STREAMING::REQUEST_MODEL(hash1_cell);
		STREAMING::REQUEST_MODEL(hash2_wheel);
        STREAMING::REQUEST_MODEL(hash3_minigun);
		STREAMING::REQUEST_MODEL(hash4_alarm);
		STREAMING::REQUEST_MODEL(hash5_light);
		STREAMING::REQUEST_MODEL(hash6_controller);
		STREAMING::REQUEST_MODEL(hash7_overlay);

		if (STREAMING::HAS_MODEL_LOADED(hash_bati2) && STREAMING::HAS_MODEL_LOADED(hash1_cell) && STREAMING::HAS_MODEL_LOADED(hash2_wheel) && STREAMING::HAS_MODEL_LOADED(hash3_minigun) && STREAMING::HAS_MODEL_LOADED(hash4_alarm) && STREAMING::HAS_MODEL_LOADED(hash5_light) && STREAMING::HAS_MODEL_LOADED(hash6_controller) && STREAMING::HAS_MODEL_LOADED(hash7_overlay)) 
		{
			int cell = OBJECT::CREATE_OBJECT(hash1_cell, null0.x, null0.y, null0.z, 1, 0, 1);
            int cell2 = OBJECT::CREATE_OBJECT(hash1_cell, null.x, null.y, null.z, 1, 0, 1);
			int cell3 = OBJECT::CREATE_OBJECT(hash1_cell, null1.x, null1.y, null1.z, 1, 0, 1);
			int cell4 = OBJECT::CREATE_OBJECT(hash1_cell, null2.x, null2.y, null2.z, 1, 0, 1);
			int cell5 = OBJECT::CREATE_OBJECT(hash1_cell, null3.x, null3.y, null3.z, 1, 0, 1);
			int cell6 = OBJECT::CREATE_OBJECT(hash1_cell, null4.x, null4.y, null4.z, 1, 0, 1);
			int cell7 = OBJECT::CREATE_OBJECT(hash1_cell, null5.x, null5.y, null5.z, 1, 0, 1);
			int cell8 = OBJECT::CREATE_OBJECT(hash1_cell, null6.x, null6.y, null6.z, 1, 0, 1);
			int wheel = OBJECT::CREATE_OBJECT(hash2_wheel, null7.x, null7.y, null7.z, 1, 0, 1);
			int wheel2 = OBJECT::CREATE_OBJECT(hash2_wheel, null8.x, null8.y, null8.z, 1, 0, 1);
			int wheel3 = OBJECT::CREATE_OBJECT(hash2_wheel, null9.x, null9.y, null9.z, 1, 0, 1);
			int wheel4 = OBJECT::CREATE_OBJECT(hash2_wheel, null10.x, null10.y, null10.z, 1, 0, 1);
			int minigun = OBJECT::CREATE_OBJECT(hash3_minigun, null11.x, null11.y, null11.z, 1, 0, 1);
			int minigun2 = OBJECT::CREATE_OBJECT(hash3_minigun, null12.x, null12.y, null12.z, 1, 0, 1);
			int minigun3 = OBJECT::CREATE_OBJECT(hash3_minigun, null13.x, null13.y, null13.z, 1, 0, 1);
			int alarm = OBJECT::CREATE_OBJECT(hash4_alarm, null14.x, null14.y, null14.z, 1, 0, 1);
			int alarm2 = OBJECT::CREATE_OBJECT(hash4_alarm, null15.x, null15.y, null15.z, 1, 0, 1);
			int light = OBJECT::CREATE_OBJECT(hash5_light, null16.x, null16.y, null16.z, 1, 0, 1);
			int light2 = OBJECT::CREATE_OBJECT(hash5_light, null17.x, null17.y, null17.z, 1, 0, 1);
			int controller = OBJECT::CREATE_OBJECT(hash6_controller, null18.x, null18.y, null18.z, 1, 0, 1);
			int controller2 = OBJECT::CREATE_OBJECT(hash6_controller, null19.x, null19.y, null19.z, 1, 0, 1);
			int overlay = OBJECT::CREATE_OBJECT(hash7_overlay, null20.x, null20.y, null20.z, 1, 0, 1);

			if (ENTITY::DOES_ENTITY_EXIST(cell) && ENTITY::DOES_ENTITY_EXIST(cell2) && ENTITY::DOES_ENTITY_EXIST(cell3) && ENTITY::DOES_ENTITY_EXIST(cell4) && ENTITY::DOES_ENTITY_EXIST(cell5) && ENTITY::DOES_ENTITY_EXIST(cell6) && ENTITY::DOES_ENTITY_EXIST(cell7) && ENTITY::DOES_ENTITY_EXIST(cell8) && ENTITY::DOES_ENTITY_EXIST(wheel) && ENTITY::DOES_ENTITY_EXIST(wheel2) && ENTITY::DOES_ENTITY_EXIST(wheel3) && ENTITY::DOES_ENTITY_EXIST(wheel4) && ENTITY::DOES_ENTITY_EXIST(minigun) && ENTITY::DOES_ENTITY_EXIST(minigun2) && ENTITY::DOES_ENTITY_EXIST(minigun3) && ENTITY::DOES_ENTITY_EXIST(alarm) && ENTITY::DOES_ENTITY_EXIST(alarm2) && ENTITY::DOES_ENTITY_EXIST(light) && ENTITY::DOES_ENTITY_EXIST(light2) && ENTITY::DOES_ENTITY_EXIST(controller) && ENTITY::DOES_ENTITY_EXIST(controller2) && ENTITY::DOES_ENTITY_EXIST(overlay))
			{
				int Vehicle = VEHICLE::CREATE_VEHICLE(hash_bati2, MyCoords.x, MyCoords.y, MyCoords.z, ENTITY::GET_ENTITY_HEADING(Handle), 1, 0);

				if (ENTITY::DOES_ENTITY_EXIST(Vehicle))
				{
					PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Vehicle, -1);
					STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash_bati2);
					ENTITY::SET_ENTITY_VISIBLE(Vehicle, false);
					ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), true);

					ENTITY::ATTACH_ENTITY_TO_ENTITY(cell, Vehicle, 0, a0.x, a0.y, a0.z, b0.x, b0.y, b0.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(cell2, Vehicle, 0, a.x, a.y, a.z, b.x, b.y, b.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(cell3, Vehicle, 0, a1.x, a1.y, a1.z, b1.x, b1.y, b1.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(cell4, Vehicle, 0, a2.x, a2.y, a2.z, b2.x, b2.y, b2.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(cell5, Vehicle, 0, a3.x, a3.y, a3.z, b3.x, b3.y, b3.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(cell6, Vehicle, 0, a4.x, a4.y, a4.z, b4.x, b4.y, b4.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(cell7, Vehicle, 0, a5.x, a5.y, a5.z, b5.x, b5.y, b5.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(cell8, Vehicle, 0, a6.x, a6.y, a6.z, b6.x, b6.y, b6.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(wheel, Vehicle, 0, a7.x, a7.y, a7.z, b7.x, b7.y, b7.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(wheel2, Vehicle, 0, a8.x, a8.y, a8.z, b8.x, b8.y, b8.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(wheel3, Vehicle, 0, a9.x, a9.y, a9.z, b9.x, b9.y, b9.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(wheel4, Vehicle, 0, a10.x, a10.y, a10.z, b10.x, b10.y, b10.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(minigun, Vehicle, 0, a11.x, a11.y, a11.z, b11.x, b11.y, b11.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(minigun2, Vehicle, 0, a12.x, a12.y, a12.z, b12.x, b12.y, b12.z, 0, 1, 0, 0, 2, 1);
                    ENTITY::ATTACH_ENTITY_TO_ENTITY(minigun3, Vehicle, 0, a13.x, a13.y, a13.z, b13.x, b13.y, b13.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(alarm, Vehicle, 0, a14.x, a14.y, a14.z, b14.x, b14.y, b14.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(alarm2, Vehicle, 0, a15.x, a15.y, a15.z, b15.x, b15.y, b15.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(light, Vehicle, 0, a16.x, a16.y, a16.z, b16.x, b16.y, b16.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(light2, Vehicle, 0, a17.x, a17.y, a17.z, b17.x, b17.y, b17.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(controller, Vehicle, 0, a18.x, a18.y, a18.z, b18.x, b18.y, b18.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(controller2, Vehicle, 0, a19.x, a19.y, a19.z, b19.x, b19.y, b19.z, 0, 1, 0, 0, 2, 1);
					ENTITY::ATTACH_ENTITY_TO_ENTITY(overlay, Vehicle, 0, a20.x, a20.y, a20.z, b20.x, b20.y, b20.z, 0, 1, 0, 0, 2, 1);

					ENTITY::SET_ENTITY_VISIBLE(Handle, true);	
					return true;
				}
				return false;
			}		
			return false;														
		}
		return false;
	}



char* featureWeaponAsset = "VEHICLE_WEAPON_PLAYER_HUNTER";
void VehicleWeaponsFunction()
{
	int launchDistance = 250;
	int weaponHash = GAMEPLAY::GET_HASH_KEY(featureWeaponAsset);
	float launchSpeed = 1500.0f;
	int vehid = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());

	Vector3 idk1 = { 0.6f, 0.6707f, 0.37f };
	Vector3 idk2 = { -0.6f, 0.6707f, 0.3f };
	Vector3 idk3 = { 0.6f, 5.0707f, 0.3f };
	Vector3 idk4 = { -0.6f, 5.0707f, 0.3f };

	Vector3 getcoords1 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(vehid, idk1.x, idk1.y, idk1.z);
	Vector3 getcoords2 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(vehid, idk2.x, idk2.y, idk2.z);
	Vector3 getcoords3 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(vehid, idk3.x, idk3.y, idk3.z);
	Vector3 getcoords4 = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(vehid, idk4.x, idk4.y, idk4.z);
	GRAPHICS::DRAW_LINE(getcoords1.x, getcoords1.y, getcoords1.z, getcoords3.x, getcoords3.y, getcoords3.z, 255, 0, 0, 255);
	GRAPHICS::DRAW_LINE(getcoords2.x, getcoords2.y, getcoords2.z, getcoords4.x, getcoords4.y, getcoords4.z, 255, 0, 0, 255);
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), true) &&  CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_L3))
		
	{
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(getcoords1.x, getcoords1.y, getcoords1.z, getcoords3.x, getcoords3.y, getcoords3.z, launchDistance, 0, weaponHash, PLAYER::PLAYER_PED_ID(), 1, 0, launchSpeed);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(getcoords2.x, getcoords2.y, getcoords2.z, getcoords4.x, getcoords4.y, getcoords4.z, launchDistance, 0, weaponHash, PLAYER::PLAYER_PED_ID(), 1, 0, launchSpeed);
	}
}



void VehicleWeaponsFunctionold()
{
	uint player = PLAYER::PLAYER_ID();
	uint playerPed = PLAYER::PLAYER_PED_ID();

	bool bSelect = CONTROLS::IS_CONTROL_PRESSED(2, Button_L3);

	if (bSelect && PLAYER::IS_PLAYER_CONTROL_ON(player) && PED::IS_PED_IN_ANY_VEHICLE(playerPed, 0))
	{
		Vector3 v0, v1;
		uint veh = PED::GET_VEHICLE_PED_IS_USING(playerPed);
		int weaponAsset = GAMEPLAY::GET_HASH_KEY("");
		if (!WEAPON::HAS_WEAPON_ASSET_LOADED(weaponAsset))
		{
			WEAPON::REQUEST_WEAPON_ASSET(weaponAsset, 31, 0);
		}

		Vector3 coords0from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -(v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords1from = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, (v1.x + 0.25f), v1.y + 1.25f, 0.1);
		Vector3 coords0to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, -v1.x, v1.y + 100.0f, 0.1f);
		Vector3 coords1to = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(veh, v1.x, v1.y + 100.0f, 0.1f);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords0from.x, coords0from.y, coords0from.z, coords0to.x, coords0to.y, coords0to.z, 250, 1, weaponAsset, playerPed, 1, 0, -1.0);
		GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(coords1from.x, coords1from.y, coords1from.z, coords1to.x, coords1to.y, coords1to.z, 250, 1, weaponAsset, playerPed, 1, 0, -1.0);
	}
}
void DrawSprite(char * Streamedtexture, char * textureName, float x, float y, float width, float height, float rotation, int r, int g, int b, int a)
{
	GRAPHICS::REQUEST_STREAMED_TEXTURE_DICT(Streamedtexture, false);
	GRAPHICS::HAS_STREAMED_TEXTURE_DICT_LOADED(Streamedtexture);
	GRAPHICS::DRAW_SPRITE(Streamedtexture, textureName, x, y, width, height, rotation, r, g, b, a);
}

bool pimpin;
void LowRider()
	{
		int LeftRight = CONTROLS::GET_CONTROL_VALUE(0, 188);
		int UpDown = CONTROLS::GET_CONTROL_VALUE(0, 189);
		int VehicleHandle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		if (VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(VehicleHandle))
		{
			if (UpDown == 254)
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(VehicleHandle, 1, 0, 0, 0.078, 0, 3.05, 0, 1, 1, 1, 1, 0, 1);
			}
			if (UpDown == 0)
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(VehicleHandle, 1, 0, 0, 0.078, 0, -3.05, 0, 1, 1, 1, 1, 0, 1);
			}
			if (LeftRight == 254)
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(VehicleHandle, 1, 0, 0, 0.23, 0.98, 0, 0, 1, 1, 1, 1, 0, 1);
			}
			if (LeftRight == 0)
			{
				ENTITY::APPLY_FORCE_TO_ENTITY(VehicleHandle, 1, 0, 0, 0.23, -0.98, 0, 0, 1, 1, 1, 1, 0, 1);
			}
		}
	}



bool WheelieCar = false;
float EINS = 0.05;
float ZWEI = 1.3;
bool Wiiili;
void WWiiiliCar()
{
	if (!Wiiili){
		Wiiili = true;
	}
	else{
		Wiiili = false;
	}
}
bool LowerWhip;
void LowerCar()
{
	int VehicleHandle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) 
	ENTITY::APPLY_FORCE_TO_ENTITY(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 1, 0, 0, -0.1, 0, 0, 0, 0, 1, 1, 1, 0, 1);
}
bool RequestControlOfEnt(Entity ent)
{
	if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(ent))
	{
		while (!NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY)
		{
		}
		return true;
	}
	return false;
}

bool ForceTest;
bool Bunnycars;
bool BoostAreaCar = false;
bool TuneArea2 = false;
//Setup the array
const int numElements = 200;
const int arrSize = numElements * 2 + 2;
int veh[arrSize];
//0 index is the size of the array
void ForceVehicle2s(int Player,bool jum, bool Bunny = false)
{
	veh[0] = numElements;

	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);

	if (veh != NULL)
	{
		//Simple loop to go through results
		for (int i = 0; i < count; i++)
		{
			int offsettedID = i * 2 + 2;
			//Make sure it exists
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				RequestControlOfEnt(veh[offsettedID]);

				if (Bunny)
				{
					if (VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(veh[offsettedID]))
					{
						ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 0, 0, -0.1, 0, 0, 0, 1, 1, 1, 1, 0, 1);//Do something
					}
				}
			}
		}
	}
}
void ForceVehicles(int Player, bool jum, bool Bunny = false)
{
	veh[0] = numElements;

	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);

	if (veh != NULL)
	{
		//Simple loop to go through results
		for (int i = 0; i < count; i++)
		{
			int offsettedID = i * 2 + 2;
			//Make sure it exists
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				RequestControlOfEnt(veh[offsettedID]);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 0, 0, 0.1, 0, 0, 0, 1, 1, 1, 1, 0, 1);//Do something
			}
		}
	}
}

void MaxEng(int VehicleHandle)
{
	VEHICLE::SET_VEHICLE_MOD_KIT(VehicleHandle, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 11, 3, 0);//Motor
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 12, 2, 0);//Bremsen
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 13, 2, 0);//Getriebe
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 15, 2, 0);//Federung
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 16, 4, 0);//Panzerung
	VEHICLE::TOGGLE_VEHICLE_MOD(VehicleHandle, 18, 1);//Turbo
	VEHICLE::TOGGLE_VEHICLE_MOD(VehicleHandle, 22, 1);//Xenon 
	VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehicleHandle, 7);//Reifen Typ
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 23, 17, 0);//Reifen
	VEHICLE::SET_VEHICLE_WINDOW_TINT(VehicleHandle, 5);
}
void MaxStyle(int VehicleHandle)
{
	VEHICLE::SET_VEHICLE_MOD_KIT(VehicleHandle, 0);
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 0, 1, 0);//Soiler
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 1, 1, 0);//Frontstoßstange
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 2, 1, 0);//Heckstoßstange
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 3, 1, 0);//Body
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 14, 24, 0);//Hupe
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 4, 2, 0);//Auspuff
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 5, 1, 0);//Ueberrollkaeffig
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 6, 1, 0);//Grill
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 7, 1, 0);//Motorhaube
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 8, 2, 0);//Schhuerze
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 9, 2, 0);//Rechte Schuerze
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 10, 1, 0);//Dach
	VEHICLE::TOGGLE_VEHICLE_MOD(VehicleHandle, 22, 1);//Xenon 
	VEHICLE::SET_VEHICLE_WHEEL_TYPE(VehicleHandle, 7);//Reifen Typ
	VEHICLE::SET_VEHICLE_MOD(VehicleHandle, 23, 17, 0);//Reifen
	VEHICLE::SET_VEHICLE_WINDOW_TINT(VehicleHandle, 5);
}
void Maxtune(int VehicleHandle)
{
	MaxStyle(VehicleHandle);
	MaxEng(VehicleHandle);
}

void AreaTune2(int Player, int Radius)
{
	veh[0] = numElements;

	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);

	if (veh != NULL)
	{
		//Simple loop to go through results
		for (int i = 0; i < count; i++)
		{
			int offsettedID = i * 2 + 2;
			//Make sure it exists
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				RequestControlOfEnt(veh[offsettedID]);
	            Maxtune(veh[offsettedID]);
				VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh[offsettedID], 0, 255, 0);
				VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(veh[offsettedID]);
				VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(veh[offsettedID]);
				VEHICLE::SET_VEHICLE_MOD_KIT(veh[offsettedID], 0);
				VEHICLE::SET_VEHICLE_COLOURS(veh[offsettedID], 148, 148);
				VEHICLE::SET_VEHICLE_EXTRA_COLOURS(veh[offsettedID], 140, 0);
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(veh[offsettedID], "WILDEMODZ");
			}
		}
	}
}


void AreaBoost(int Player, int Radius)
{
	veh[0] = numElements;

	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);

	if (veh != NULL)
	{
		//Simple loop to go through results
		for (int i = 0; i < count; i++)
		{
			int offsettedID = i * 2 + 2;
			//Make sure it exists
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				RequestControlOfEnt(veh[offsettedID]);
				ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 0, 5, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1);//Do something
				
			}
		}
	}
}
bool Buny = false;//SET_VEHICLE_GRAVITY
void AreaBunny(int Player, int Radius)
{
	veh[0] = numElements;

	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);

	if (veh != NULL)
	{
		//Simple loop to go through results
		for (int i = 0; i < count; i++)
		{
			int offsettedID = i * 2 + 2;
			//Make sure it exists
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				RequestControlOfEnt(veh[offsettedID]);
				if (VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(veh[offsettedID])){
					ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 0, 0, 0.8, 0, 1.5, 0, 1, 1, 1, 1, 0, 1);
				}
			}
		}
	}
}
bool Graviiii = false;//SET_VEHICLE_GRAVITY
void AreaGravi()
{
	veh[0] = numElements;

	int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);

	if (veh != NULL)
	{
		//Simple loop to go through results
		for (int i = 0; i < count; i++)
		{
			int offsettedID = i * 2 + 2;
			//Make sure it exists
			if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
			{
				RequestControlOfEnt(veh[offsettedID]);
				VEHICLE::SET_VEHICLE_GRAVITY(veh[offsettedID], true);
				if (Graviiii){
					VEHICLE::SET_VEHICLE_GRAVITY(veh[offsettedID], false);
				}
			}
		}
	}
}