void CreateObject(const char* hash)
{
	 Vector3 mycoords;
	 mycoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	 int obj = GAMEPLAY::GET_HASH_KEY(hash);
	 OBJECT::CREATE_OBJECT(obj, mycoords.x,mycoords.y,mycoords.z, 1, 1, 0);
}

void clearArea()
{
	Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
	GAMEPLAY::CLEAR_AREA(Pos.x, Pos.y, Pos.z, 250, true);
	GAMEPLAY::CLEAR_AREA_OF_COPS(Pos.x, Pos.y, Pos.z, 250);
	GAMEPLAY::CLEAR_AREA_OF_OBJECTS(Pos.x, Pos.y, Pos.z, 250);
	GAMEPLAY::CLEAR_AREA_OF_VEHICLES(Pos.x, Pos.y, Pos.z, 250);
	GAMEPLAY::CLEAR_AREA_OF_PEDS(Pos.x, Pos.y, Pos.z, 250);
	GAMEPLAY::CLEAR_AREA_OF_PROJECTILES(Pos.x, Pos.y, Pos.z, 250);
}

void dropPickup(Vector3 Location, const char* PickupModel, const char* PickupBehavior, int PickupAmount, char* DisplayName, int Client)
{
	int Model = GAMEPLAY::GET_HASH_KEY(PickupModel);
	int Behavior = GAMEPLAY::GET_HASH_KEY(PickupBehavior); //"PICKUP_MONEY_CASE"
	STREAMING::REQUEST_MODEL(Model);
	if (STREAMING::HAS_MODEL_LOADED(Model))
	{
		OBJECT::CREATE_AMBIENT_PICKUP(Behavior, Location.x, Location.y, Location.z, 0, PickupAmount, Model, 0, 2);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Model);
	}
}

bool cstrcmp(const char* s1, const char* s2)
{
	while(*s1 && (*s1==*s2))
		s1++,s2++;
	if(*(const unsigned char*)s1-*(const unsigned char*)s2 == 0)
		return true;
	else
		return false;
}
bool PlayerAttached;
void toggleAttach(int Player)
{
	if(!(cstrcmp(PLAYER::GET_PLAYER_NAME(Player), PLAYER::GET_PLAYER_NAME(PLAYER::PLAYER_ID()))))
	{
		if (!PlayerAttached)
		{
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
			{
				int att = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				int player = PLAYER::GET_PLAYER_PED(Player);
				Vector3 One, Two;
				One.x = 0;
				One.y = 0;
				One.z = 0; 
				Two.x = 0;
				Two.y = 0;
				Two.z = 0; 
				ENTITY::ATTACH_ENTITY_TO_ENTITY(att, player, 0, One.x, One.y, One.z, Two.x, Two.y, Two.z, 0, 1, 0, 0, 2, 1);	
				ENTITY::SET_ENTITY_COLLISION(att, 0, 0);
			}
			else
			{
				int att = PLAYER::PLAYER_PED_ID();
				int player = PLAYER::GET_PLAYER_PED(Player);
				Vector3 One, Two;
				One.x = 0;
				One.y = -0.20;
				One.z = 0; 
				Two.x = 0;
				Two.y = 0;
				Two.z = 0; 
				ENTITY::ATTACH_ENTITY_TO_ENTITY(att, player, 0, One.x, One.y, One.z, Two.x, Two.y, Two.z, 0, 1, 0, 0, 2, 1);	
				ENTITY::SET_ENTITY_COLLISION(att, 0, 0);
			}
			PlayerAttached = true;
		}
		else
		{
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
			{
				int att = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
				int player = PLAYER::GET_PLAYER_PED(Player);
				ENTITY::DETACH_ENTITY(att, player, 1);
				ENTITY::SET_ENTITY_COLLISION(att, 1, 1);
			}
			else
			{
				int att = PLAYER::PLAYER_PED_ID();
				int player = PLAYER::GET_PLAYER_PED(Player);
				ENTITY::DETACH_ENTITY(att, player, 1);	
				ENTITY::SET_ENTITY_COLLISION(att, 1, 1);				
			}				
			PlayerAttached = false;
		}
	}
}
void DeleteEntity(int Handle)
{
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(Handle);
	ENTITY::SET_ENTITY_AS_MISSION_ENTITY(Handle, 1, 1);
	ENTITY::DELETE_ENTITY(&Handle);
}




#pragma region Entity XYZ

bool RequestNetworkControl(uint vehID)
{
	int Tries = 0;
	bool
		hasControl = false,
		giveUp = false;
	do
	{
		hasControl = NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(vehID);
		Tries++;
		if (Tries > 300)
			giveUp = true;
	} while (!hasControl && !giveUp);

	if (giveUp)
		return false;
	else return true;
}

void moveEntityX_Plus(uint Handle)
{
	if (ENTITY::DOES_ENTITY_EXIST(Handle))
	{
		RequestNetworkControl(Handle);
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(Handle, 1);
		Pos.x += 0.25f;
		RequestNetworkControl(Handle);
		ENTITY::SET_ENTITY_COORDS(Handle, Pos.x, Pos.y, Pos.z, 0, 0, 0, 1);
	}
}
void moveEntityX_Min(uint Handle)
{
	if (ENTITY::DOES_ENTITY_EXIST(Handle))
	{
		RequestNetworkControl(Handle);
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(Handle, 1);
		Pos.x -= 0.25f;
		RequestNetworkControl(Handle);
		ENTITY::SET_ENTITY_COORDS(Handle, Pos.x, Pos.y, Pos.z, 0, 0, 0, 1);
	}
}
void moveEntityY_Plus(uint Handle)
{
	if (ENTITY::DOES_ENTITY_EXIST(Handle))
	{
		RequestNetworkControl(Handle);
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(Handle, 1);
		Pos.y += 0.25f;
		RequestNetworkControl(Handle);
		ENTITY::SET_ENTITY_COORDS(Handle, Pos.x, Pos.y, Pos.z, 0, 0, 0, 1);
	}
}
void moveEntityY_Min(uint Handle)
{
	if (ENTITY::DOES_ENTITY_EXIST(Handle))
	{
		RequestNetworkControl(Handle);
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(Handle, 1);
		Pos.y -= 0.25f;
		RequestNetworkControl(Handle);
		ENTITY::SET_ENTITY_COORDS(Handle, Pos.x, Pos.y, Pos.z, 0, 0, 0, 1);
	}
}
void moveEntityZ_Plus(uint Handle)
{
	if (ENTITY::DOES_ENTITY_EXIST(Handle))
	{
		RequestNetworkControl(Handle);
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(Handle, 1);
		Pos.z += 0.25f;
		RequestNetworkControl(Handle);
		ENTITY::SET_ENTITY_COORDS(Handle, Pos.x, Pos.y, Pos.z, 0, 0, 0, 1);
	}
}
void moveEntityZ_Min(uint Handle)
{
	if (ENTITY::DOES_ENTITY_EXIST(Handle))
	{
		RequestNetworkControl(Handle);
		Vector3 Pos = ENTITY::GET_ENTITY_COORDS(Handle, 1);
		Pos.z -= 0.25f;
		RequestNetworkControl(Handle);
		ENTITY::SET_ENTITY_COORDS(Handle, Pos.x, Pos.y, Pos.z, 0, 0, 0, 1);
	}
}

#pragma endregion
#pragma region Entity Pitch Roll Yaw

void changeEntityRoll_Plus(uint Handle)
{
	if (ENTITY::DOES_ENTITY_EXIST(Handle))
	{
		RequestNetworkControl(Handle);
		float Yaw = ENTITY::GET_ENTITY_HEADING(Handle);
		float Pitch = ENTITY::GET_ENTITY_PITCH(Handle);
		float Roll = ENTITY::GET_ENTITY_ROLL(Handle);
		Roll += 2.5;
		Vector3 Rot;
		Rot.x = Pitch; Rot.y = Roll, Rot.z = Yaw;
		RequestNetworkControl(Handle);
		ENTITY::SET_ENTITY_ROTATION(Handle, Rot.x, Rot.y, Rot.z, 2, 1);
	}
}
void changeEntityRoll_Min(uint Handle)
{
	if (ENTITY::DOES_ENTITY_EXIST(Handle))
	{
		RequestNetworkControl(Handle);
		float Yaw = ENTITY::GET_ENTITY_HEADING(Handle);
		float Pitch = ENTITY::GET_ENTITY_PITCH(Handle);
		float Roll = ENTITY::GET_ENTITY_ROLL(Handle);
		Roll -= 2.5;
		Vector3 Rot;
		Rot.x = Pitch; Rot.y = Roll, Rot.z = Yaw;
		RequestNetworkControl(Handle);
		ENTITY::SET_ENTITY_ROTATION(Handle, Rot.x, Rot.y, Rot.z, 2, 1);
	}
}
void changeEntityPitch_Plus(uint Handle)
{
	if (ENTITY::DOES_ENTITY_EXIST(Handle))
	{
		RequestNetworkControl(Handle);
		float Yaw = ENTITY::GET_ENTITY_HEADING(Handle);
		float Pitch = ENTITY::GET_ENTITY_PITCH(Handle);
		float Roll = ENTITY::GET_ENTITY_ROLL(Handle);
		Pitch += 1.0;
		Vector3 Rot;
		Rot.x = Pitch; Rot.y = Roll, Rot.z = Yaw;
		RequestNetworkControl(Handle);
		ENTITY::SET_ENTITY_ROTATION(Handle, Rot.x, Rot.y, Rot.z, 2, 1);
	}
}
void changeEntityPitch_Min(uint Handle)
{
	if (ENTITY::DOES_ENTITY_EXIST(Handle))
	{
		RequestNetworkControl(Handle);
		float Yaw = ENTITY::GET_ENTITY_HEADING(Handle);
		float Pitch = ENTITY::GET_ENTITY_PITCH(Handle);
		float Roll = ENTITY::GET_ENTITY_ROLL(Handle);
		Pitch -= 10;
		Vector3 Rot;
		Rot.x = Pitch; Rot.y = Roll, Rot.z = Yaw;
		RequestNetworkControl(Handle);
		ENTITY::SET_ENTITY_ROTATION(Handle, Rot.x, Rot.y, Rot.z, 2, 1);
	}
}
void changeEntityYaw_Plus(uint Handle)
{
	if (ENTITY::DOES_ENTITY_EXIST(Handle))
	{
		RequestNetworkControl(Handle);
		float Yaw = ENTITY::GET_ENTITY_HEADING(Handle);
		float Pitch = ENTITY::GET_ENTITY_PITCH(Handle);
		float Roll = ENTITY::GET_ENTITY_ROLL(Handle);
		Yaw += 2.5;
		Vector3 Rot;
		Rot.x = Pitch; Rot.y = Roll, Rot.z = Yaw;
		RequestNetworkControl(Handle);
		ENTITY::SET_ENTITY_ROTATION(Handle, Rot.x, Rot.y, Rot.z, 2, 1);
	}
}
void changeEntityYaw_Min(uint Handle)
{
	if (ENTITY::DOES_ENTITY_EXIST(Handle))
	{
		RequestNetworkControl(Handle);
		float Yaw = ENTITY::GET_ENTITY_HEADING(Handle);
		float Pitch = ENTITY::GET_ENTITY_PITCH(Handle);
		float Roll = ENTITY::GET_ENTITY_ROLL(Handle);
		Yaw -= 2.5;
		Vector3 Rot;
		Rot.x = Pitch; Rot.y = Roll, Rot.z = Yaw;
		RequestNetworkControl(Handle);
		ENTITY::SET_ENTITY_ROTATION(Handle, Rot.x, Rot.y, Rot.z, 2, 1);
	}
}

#pragma endregion

void freezeEntity(uint Handle)
{
	if (ENTITY::DOES_ENTITY_EXIST(Handle))
	{
		RequestNetworkControl(Handle);
		ENTITY::FREEZE_ENTITY_POSITION(Handle, true);
	}
}

void unfreezeEntity(uint Handle)
{
	if (ENTITY::DOES_ENTITY_EXIST(Handle))
	{
		RequestNetworkControl(Handle);
		ENTITY::FREEZE_ENTITY_POSITION(Handle, false);
	}
}
bool FrezzeandUnfrezze_;
void FrezzeandUnfrezze(uint ha)
{
	if (FrezzeandUnfrezze_ == false)
	{
		freezeEntity(ha);
		//drawNotification("Objected Frozen");
		FrezzeandUnfrezze_ = true;
	}
	else if (FrezzeandUnfrezze_ == true)
	{
		unfreezeEntity(ha);
		//drawNotification("Objected UnFrozen");
		FrezzeandUnfrezze_ = false;
	}
}

void setStraight(uint Handle)
{
	if (ENTITY::DOES_ENTITY_EXIST(Handle))
	{
		RequestNetworkControl(Handle);
		float Yaw = ENTITY::GET_ENTITY_HEADING(Handle);
		float Pitch = 0;
		float Roll = 0;
		RequestNetworkControl(Handle);
		ENTITY::SET_ENTITY_HEADING(Handle, Yaw + 0.1f);
	}
}



opd_s SET_ENTITY_ROTATION_t = { Addresses::SET_ENTITY_ROTATION, TOC };
void(*SET_ENTITY_ROTATION)(int station,float* h ,int d,int e) = (void(*)(int,float*,int,int))&SET_ENTITY_ROTATION_t;//0x3B3A6C
void SET_ROTATION(int entity,float b,float a,float z)
{
	float xyzz[3] = { b, a, z };
	SET_ENTITY_ROTATION(entity,xyzz,2,1);

}


	opd_s SET_ENTITY_COORDSzz_t = { Addresses::SET_ENTITY_COORDS, TOC };
int(*SET_ENTITY_COORDSzz)(int PedID, float* numArray, int r0, int r1, int r2, int r3) = (int(*)(int, float*, int, int, int, int))&SET_ENTITY_COORDSzz_t;
int OBJ;
void object_x_y_z_pitch_roll_yaw(int modelx,float x,float y ,float z,float pitch,float roll,float yaw)
{
		
    OBJ = OBJECT::CREATE_OBJECT(modelx, 0.0f, 1.0f, 2.0f, 0, 0, 0);
	float numArray[3] = { x,y,z, };
	SET_ENTITY_COORDSzz(OBJ, numArray, 1, 0, 0, 1);
    SET_ROTATION(OBJ,pitch,roll,yaw);
    ENTITY::SET_ENTITY_INVINCIBLE(OBJ, 1);
	ENTITY::SET_ENTITY_CAN_BE_DAMAGED(OBJ,false);
	ENTITY::FREEZE_ENTITY_POSITION(OBJ,true);
	OBJECT::SET_OBJECT_TARGETTABLE(OBJ, true);
	ENTITY::SET_ENTITY_ONLY_DAMAGED_BY_PLAYER(OBJ,false);
	ENTITY::RESET_ENTITY_ALPHA(OBJ);
	ENTITY::SET_ENTITY_PROOFS(OBJ,true,true,true,true,true,true,true,true);
	OBJECT::SET_ACTIVATE_OBJECT_PHYSICS_AS_SOON_AS_IT_IS_UNFROZEN(OBJ,false);
		
}




