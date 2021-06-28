void SetTunable(int index, int value)
{
	int TunablesAddress = (*(int*)0x1E70374) + 4; //0x1E60274
	{
		if (TunablesAddress != 0)
		{
			int temp = TunablesAddress;
			temp += (index * 4);
			*(int*)temp = value;
		}
	}
}

void CleanPed(int PedHandle)
{
	PED::CLEAR_PED_BLOOD_DAMAGE(PedHandle);
	PED::RESET_PED_VISIBLE_DAMAGE(PedHandle);
	PED::SET_PED_ARMOUR(PLAYER::GET_PLAYER_PED(PedHandle), 9999999);
}

void Armour(int PedHandle)
{
	PED::SET_PED_ARMOUR(PLAYER::GET_PLAYER_PED(PedHandle), 9999999);
}


int ClonePed(int PedHandle)
{
	return PED::CLONE_PED(PedHandle, ENTITY::GET_ENTITY_HEADING(PedHandle), 1, 1);

}

void spawnMoneyModel(const char* Model, Vector3 Position, const char* Pickup = "Bags")
{
	int ModelHash = GAMEPLAY::GET_HASH_KEY(Model);
	int PickupHash = GAMEPLAY::GET_HASH_KEY(Pickup);
	STREAMING::REQUEST_MODEL(ModelHash);
	if (STREAMING::HAS_MODEL_LOADED(ModelHash))
	{
		OBJECT::CREATE_AMBIENT_PICKUP(PickupHash, Position.x, Position.y, Position.z,  0, 2000, ModelHash, 0, 1);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(ModelHash);
	}
}

void changeModel(const char* Model)
{
	int ModelHash = GAMEPLAY::GET_HASH_KEY(Model);
	if (STREAMING::IS_MODEL_IN_CDIMAGE(ModelHash))
	{
		if (STREAMING::IS_MODEL_VALID(ModelHash))
			{
			STREAMING::REQUEST_MODEL(ModelHash);
			if (STREAMING::HAS_MODEL_LOADED(ModelHash))
			{
				PLAYER::SET_PLAYER_MODEL(PLAYER::PLAYER_ID(), ModelHash);
				STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(ModelHash);
			}
		}
	}
}


bool mobileRadio;
void toggleMobileRadio()
{
	int station = AUDIO::GET_PLAYER_RADIO_STATION_INDEX();		
	if (mobileRadio)
	{
		AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(false);
		AUDIO::SET_MOBILE_PHONE_RADIO_STATE(0);		
		mobileRadio = false;
	}
	else
	{
		AUDIO::SET_MOBILE_RADIO_ENABLED_DURING_GAMEPLAY(true);
		AUDIO::SET_MOBILE_PHONE_RADIO_STATE(1);
		AUDIO::SET_RADIO_TO_STATION_INDEX(station);
		mobileRadio = true;
	}
}

void ExplodePlayer(int PedHandle)
{
	Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PedHandle), true);
	FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, 29, 0.5f, true, false, 5.0f);
}



void bossMode()
{
	bool Explode = false;
	for(int i = 0; i < 18; i++)
	{
		if(PLAYER::IS_PLAYER_TARGETTING_ENTITY(i, PLAYER::PLAYER_PED_ID()) && !Explode)
		{
			Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(i), true);
			FIRE::ADD_OWNED_EXPLOSION(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_ID()), Pos.x,Pos.y,Pos.z, 29, 0.5f, true, false, 0.0f);
			Explode = true;
		}
	}
}

void stopTasks(int Client)
{
	AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED(Client));
}
void StopAnim()
{
	AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID());
}

 void rambus(int model,int selectedPlayer)
{
	float Headingx;
	int MYCAR;
	int NET1;
	Headingx = ENTITY::GET_ENTITY_HEADING(PLAYER::GET_PLAYER_PED(selectedPlayer));

	STREAMING::REQUEST_MODEL(model);
	if(STREAMING::HAS_MODEL_LOADED(model));
	MYCAR = VEHICLE::CREATE_VEHICLE(model,Vector3 (ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer),0,67,0)),0,1,0);
	STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(model);
	VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(MYCAR);
	NET1 = NETWORK::NETWORK_GET_NETWORK_ID_FROM_ENTITY(MYCAR);
	NETWORK::SET_NETWORK_ID_CAN_MIGRATE(NET1, true);
	if(Headingx > 190.0) Headingx -= 190.0;
	else Headingx += 190.0;
	ENTITY::SET_ENTITY_HEADING(MYCAR, Headingx);
	ENTITY::SET_ENTITY_PROOFS(MYCAR, true, true, true, true, true,true,true,true);
	VEHICLE::SET_VEHICLE_FORWARD_SPEED(MYCAR,150);
	//PRINT("Sent a Ram Car",1000);
	}
 #define FLT_MAX (3.40282347E+38F)
void doForceField(int client)
{
	Vector3 Pos = ENTITY::GET_ENTITY_COORDS(client, true);
	FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, 29, FLT_MAX, false, true, 0.0f);
	FIRE::ADD_EXPLOSION(Pos.x, Pos.y, Pos.z, 26, FLT_MAX, false, true, 0.0f);
}





bool doForceField_;
void Dofroce()
{
	doForceField_ = !doForceField_;
}


bool MoneyBagToggle = false;
void dropPickup(Vector3 Location, char* PickupModel, char* PickupBehavior, int PickupAmount)
{
	int Model = GAMEPLAY::GET_HASH_KEY(PickupModel);
	int Behavior = GAMEPLAY::GET_HASH_KEY(PickupBehavior); //"PICKUP_MONEY_CASE"
	STREAMING::REQUEST_MODEL(Model);
	if (STREAMING::HAS_MODEL_LOADED(Model))
	{
		Location.z += 1;
		OBJECT::CREATE_AMBIENT_PICKUP(Behavior, Location.x, Location.y, Location.z, 0, PickupAmount, Model, 0, 2);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(Model);
	}
}
void shootAtPed(Ped selectedPed)
{
	Vector3 Mouth = PED::GET_PED_BONE_COORDS(selectedPed, 0x796e, 0.08f, 0.0f, 0.0f);
	PED::SET_PED_SHOOTS_AT_COORD(PLAYER::PLAYER_PED_ID(), Mouth.x, Mouth.y, Mouth.z, true);
}

