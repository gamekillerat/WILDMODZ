//Menu base created by 2much4u

#include <cellstatus.h>
#include <sys/prx.h>
#include <sys/ppu_thread.h>
#include <string.h>
#include <sys/memory.h>
#include <sys/timer.h>
#include <sys/process.h>
#include <ppu_intrinsics.h>
#include <stdarg.h>
#include <stdio.h>
#include <cstdlib>
#include "Enums.h"
#include "Addresses.h"
#include "Natives.h"
#include "Vehicle.h"
#include "Recovery.h"
#include "Weapons.h"
#include "Teleport.h"
#include "PED.h"
#include "Objects.h"

SYS_MODULE_INFO("GTAV_Native_Invoker", 0, 1, 1);
SYS_MODULE_START(PRX_ENTRY);

Vector3 GET_COORDS_INFRONT(float Distance)
{
	float Tan = Distance * myTan(ADDR::__GET_GAMEPLAY_CAM_ROT(2).y, 20);
	Vector3 init = { 0, Distance, Distance * Tan };
	float Set[] = { init.x, init.y, init.z };
	Vector3 Coords = ADDR::__GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS(PLAYER::PLAYER_PED_ID(), Set);
	return Coords;
}

Vector3 get_coords_from_cam(float distance)
{
	Vector3 Rot = CAM::GET_GAMEPLAY_CAM_ROT(2);
	Vector3 Coord = CAM::GET_GAMEPLAY_CAM_COORD();

	Rot.y = distance * SYSTEM::COS(Rot.x);
	Coord.x = Coord.x + Rot.y * SYSTEM::SIN(Rot.z * -1.0f);
	Coord.y = Coord.y + Rot.y * SYSTEM::COS(Rot.z * -1.0f);
	Coord.z = Coord.z + distance * SYSTEM::SIN(Rot.x);

	return Coord;
}


#pragma region Variables
Native_s** g_Natives;
int submenu = 0;
int submenuLevel;
int lastSubmenu[20];
int lastOption[20];
int currentOption;
int optionCount;
bool optionPress = false;
bool rightPress = false;
bool leftPress = false;
bool fastRightPress = false;
bool fastLeftPress = false;
bool squarePress = false;
int selectedPlayer;
bool menuSounds = true;
bool keyboardActive = false;
int keyboardAction;
int *keyboardVar = 0;
char *infoText;
//char TLK[100];
//char HST[100];
//char NUM[100];
int InfoFont = 1;
char X[100];
char Y[100];
char Z[100];
char YAW[100];
char PTH[100];
char RLL[100];
char bufferO[100];
char NUM[100];
char VEH[100];
char PEDOO[100];
char HST[100];
char TLK[100];

bool newTimerTick = true;
int maxTimerCount;
bool newTimerTick2 = true;
int maxTimerCount2;

bool Rectz=false;
bool instructions = true;
int instructCount;
int mov;
bool instructionsSetupThisFrame;
bool xInstruction;
bool squareInstruction;
bool lrInstruction;

int platetype = 0;
int hours = 0;
int vehwindow = 0;
int vehdoor = 0;
int redcolor = 0;
int greencolor = 0;
int bluecolor = 0;
int Pearlescant = 0;
int RimColor = 0;

int bannerTextRed = 255;
int bannerTextGreen = 255;
int bannerTextBlue = 255;
int bannerTextRed1 = 255;
int bannerTextGreen1 = 255;
int bannerTextBlue1 = 255;
int bannerTextOpacity = 255;
int bannerTextFont = 1;
int bannerRectRed = 0;
int bannerRectGreen = 255;
int bannerRectBlue = 255;
int bannerRectOpacity = 255;
int backgroundRed = 16;
int backgroundGreen = 16;
int backgroundBlue = 16;
int backgroundOpacity = 70;
int optionsRed = 255;
int optionsGreen = 255;
int optionsBlue = 255;
int optionsOpacity = 255;
int optionsFont = 0;
int scrollerRed = 255;
int scrollerGreen = 255;
int scrollerBlue = 255;
int scrollerOpacity = 50;
int indicatorRed = 255;
int indicatorGreen = 255;
int indicatorBlue = 255;
int indicatorOpacity = 255;
int newsR = 0;
int newsG = 0;
int newsB = 0;
int newsA = 40;
float NewsbarX;
float menuXCoord = 0.845f;
float textXCoord = 0.76f;

int maxOptions = 18;
int NeonR = 0;
int NeonG = 0;
int NeonB = 0;


//bool LowerWhip = false;
bool SuperJump = false;
bool InfinArmour = false;
bool ExplosiveBullets = false;
bool FireAmmo = false;
bool SuperPunch = false;
bool TurnSignalLeft = false;
bool TurnSignalRight = false;
bool InvisibleVehicle = false;
//bool InvisiblePlayer = false;
bool NoCops = false;
//bool GodMode = false;

bool GodModeVehicle = false;
bool ShowTalking = false;
bool ShowCoords = false;
bool ShowInfos = false;
bool DriftCar = false;
bool HeadLights = false;
bool NoTarget = false;
//bool hasBossMode = false; 
bool hasBossMode;
bool InteriorLights = false;
bool LoopNeons_ = false;
bool Neons_ = false;
bool Newsbar = false;
bool newsbar = false;
bool Loopl = false;
int LoopCase = 0;
bool cars;
bool loop40K_;
int SpawnedVeh;
float SetVat = 5;
uint32_t hash_veh;
bool SpawnVehicle;
bool VehEap;
bool alplayerscash;
bool frezzeall;
int SelectedPed;
bool r3boost;
bool l3break;
bool leftfix;
bool SlingShot;
bool Maxup;
bool toogleesp_;
bool frezzeplayer;
bool pedstopanim;
bool pedsexr;
bool spawnsetswat;
bool spawnsetchop;
bool spawnsetmtlion;
int spawnedped;
bool explosionloop;
bool SpeedOMeter;
char buffer[100];
bool ExplodeAllPlayers;
bool hasNoCollision;
bool expl;
bool forcefield;
bool vinval_ = true;
bool carinvstext;
bool gmode = false;
bool Superman = false;
bool _test;
bool ghook;
bool shhotcars_;
bool firegun;
bool BulletBags;
bool weedgun1;
bool applyforceg;
bool Explosions;
bool Car;
int ExplosionType;
bool grenadegun;
bool grenadeLaunchgun;
bool allf;
bool alll;
bool FlyCar = false;
bool Zusatz = false;
bool MeinCode;
bool Spanlllll = false;
bool MeinCodewat;
int AirHeigt;
int FerrisWheele;
bool showCoords = false;
bool AirStikeAll[16];
bool AirStikePL = false;
bool MoneyRain = false;
bool WaepLOOP = false;
bool GrapGun = false;
bool CarGun = false;
bool RocketGun = false;
int MarkerRed=0;
int markergreen = 255;
int markerblue = 255;
bool SpawnGuitar=false;
int MarkerVar;
int MarkerVar1;
int llvar;
int BIndex=0x0;
char *Carsall[] = { "adder", "t20", "zentorno", "elegy2", "entityxf", "cheetah", "osiris", "khamelion", "massacro2", "kuruma2", "coquette2", "ztype", "hotknife", "insurgent", "insurgent2", "technical", "monster", "slamvan2", "fbi2", "carbonrs", "blimp", "hydra" };
char* Marker[] = { "Line", "Marker", "Box", "Head Marker" };
char *WeaponsMenu[] = { "Tank", "Space Rockets","Plane Rockets", "Green Laser", "Red Laser", "Buzzard"};
int WeapVar;
char *Weapshsh[] = { "VEHICLE_WEAPON_TANK", "VEHICLE_WEAPON_SPACE_ROCKET", "VEHICLE_WEAPON_PLANE_ROCKET", "VEHICLE_WEAPON_PLAYER_LASER", "VEHICLE_WEAPON_ENEMY_LASER", "VEHICLE_WEAPON_PLAYER_BUZZARD" };
char *WeaponSHoot;
int BoneVar;
char *BONSCH[] = { "Head", "Neck", "Tongue","Spine","Left Clavicle","Right Clavicle", "Left Hand", "Right Hand", "Left Upperarm", "Riight Upperarm", "Left Knee","Right Knee","Left Foot", "Right Foot" };
int BONES[] = { 0x796e, 0x9995, 0xb987, 0x60f0, 0xfcd9, 0x29d2, 0x49d9, 0xe5f2, 0xb1c5, 0x9d4d, 0xb3fe, 0x3fcf, 0x3779, 0xcc4d };
int AttVAR;
int AttvarALL;
char *AttProps[] = { "prop_alien_egg_01", "prop_weed_01", "prop_roadcone01a", "prop_beach_fire" ,"prop_cs_katana_01"};
char *AttPropSub[] = { "Alien Egg", "Weed", "Cone", "Beach Fire" , "Katana"};
char* AllPROPS[] = { "prop_a4_pile_01", "prop_a4_sheet_01", "prop_a4_sheet_02", "prop_a4_sheet_03", "prop_a4_sheet_04", "prop_a4_sheet_05", "prop_abat_roller_static", "prop_abat_slide", "prop_acc_guitar_01", "prop_acc_guitar_01_d1", "prop_aerial_01a", "prop_aerial_01b", "prop_aerial_01d", "prop_afsign_amun", "prop_agave_01", "prop_agave_02", "prop_aiprort_sign_01", "prop_aiprort_sign_02", "prop_aircon_l_01", "prop_aircon_l_02", "prop_aircon_l_03", "prop_aircon_l_04", "prop_aircon_m_09", "prop_aircon_s_01a", "prop_aircon_s_02a", "prop_aircon_s_02b", "prop_aircon_s_03a", "prop_aircon_s_03b", "prop_aircon_s_04a", "rop_aircon_s_05a", "prop_aircon_s_06a", "prop_aircon_s_07a", "rop_aircon_s_07b", "prop_airhockey_01", "prop_air_bagloader", "prop_air_bagloader2", "rop_air_barrier", "prop_air_bench_01", "prop_air_bench_02", "rop_air_bigradar_l1", "prop_air_bigradar_l2", "prop_air_bigradar_slod", "prop_air_blastfence_01", "prop_air_blastfence_02", "prop_air_bridge01", "prop_air_bridge02", "prop_air_cargoloader_01", "prop_air_cargo_01a", "prop_air_cargo_01b", "prop_air_cargo_01c", "prop_air_cargo_02a", "prop_air_cargo_02b", "prop_air_cargo_03a", "prop_air_cargo_04a", "prop_air_cargo_04b", "prop_air_cargo_04c", "prop_air_chock_01", "prop_air_chock_03", "prop_air_chock_04", "prop_air_fueltrail1", "prop_air_fueltrail2", "prop_air_gasbogey_01", "prop_air_generator_01", "prop_air_generator_03", "prop_air_hoc_paddle_01", "prop_air_hoc_paddle_02", "prop_air_lights_01a", "prop_air_lights_01b", "prop_air_lights_03a", "prop_air_luggtrolley", "prop_air_mast_01", "prop_air_mast_02", "prop_air_monhut_01", "prop_air_monhut_02", "prop_air_monhut_03", "prop_air_propeller01", "rop_air_radar_01", "prop_air_stair_01", "prop_air_stair_02", "rop_air_stair_03", "prop_air_stair_04a", "prop_air_stair_04b", "prop_air_towbar_01", "prop_air_towbar_02", "prop_air_towbar_03", "prop_air_trailer_4a", "prop_air_trailer_4b", "prop_air_trailer_4c", "prop_air_watertank1", "prop_air_watertank2", "prop_air_windsock_base", "prop_air_woodsteps", "prop_alarm_01", "prop_alarm_02", "prop_alien_egg_01", "prop_aloevera_01", "prop_amanda_note_01", "prop_amanda_note_01b", "prop_amb_40oz_02", "prop_amb_40oz_03", "prop_amb_beer_bottle", "prop_amb_ciggy_01", "prop_amb_donut", "prop_amb_handbag_01", "prop_amb_phone", "prop_amp_01", "prop_am_box_wood_01", "prop_anim_cash_note", "prop_anim_cash_note_b", "prop_anim_cash_pile_01", "prop_anim_cash_pile_02", "prop_apple_box_01", "prop_apple_box_02", "prop_arcade_01", "prop_arcade_02", "rop_arc_blueprints_01", "prop_armchair_01", "prop_armenian_gate", "prop_armour_pickup", "prop_arm_gate_l", "prop_arm_wrestle_01", "prop_artgallery_02_dl", "prop_artgallery_02_dr", "prop_artgallery_dl", "prop_artgallery_dr", "rop_artifact_01", "prop_ashtray_01", "prop_asteroid_01", "rop_atm_02", "prop_atm_03", "prop_attache_case_01", "prop_aviators_01", "prop_a_base_bars_01", "prop_a_trailer_door_01", "prop_bahammenu", "prop_ballistic_shield", "prop_ballistic_shield_lod1", "prop_bandsaw_01", "prop_bank_shutter", "prop_bank_vaultdoor", "prop_barbell_01", "prop_barbell_02", "prop_barbell_100kg", "prop_barbell_10kg", "prop_barbell_20kg", "prop_barbell_30kg", "prop_barbell_40kg", "prop_barbell_50kg", "prop_barbell_60kg", "prop_barbell_80kg", "prop_barier_conc_01b", "prop_barier_conc_01c", "prop_barier_conc_02b", "prop_barier_conc_02c", "prop_barier_conc_03a", "prop_barier_conc_04a", "prop_barier_conc_05a", "prop_barier_conc_05b", "prop_barn_door_l", "prop_barn_door_r", "prop_barrachneon", "prop_barrel_01a", "prop_barrel_02a", "prop_barrel_02b", "prop_barrel_03a", "prop_barrel_03d", "prop_barrel_float_1", "prop_barrel_float_2", "prop_barriercrash_03", "prop_barriercrash_04", "prop_barrier_wat_01a", "prop_barrier_wat_03b", "prop_barrier_work01c", "prop_barry_table_detail", "prop_bar_coastbarr", "prop_bar_coastchamp", "prop_bar_coastdusc", "prop_bar_coastmount", "prop_bar_cooler_01", "prop_bar_cooler_03", "prop_bar_fridge_01", "prop_bar_fridge_02", "prop_bar_fridge_03", "prop_bar_fridge_04", "prop_bar_ice_01", "prop_bar_napkindisp", "prop_bar_pump_01", "prop_bar_pump_04", "prop_bar_pump_05", "prop_bar_pump_06", "prop_bar_pump_07", "prop_bar_pump_08", "prop_bar_pump_09", "prop_bar_pump_10", "prop_bar_sink_01", "prop_bar_stool_01", "prop_basejump_target_01", "prop_basketball_net", "prop_bath_dirt_01", "prop_battery_01", "prop_battery_02", "prop_bball_arcade_01", "prop_bbq_2", "prop_bbq_3", "prop_beachbag_01", "prop_beachbag_02", "prop_beachbag_03", "prop_beachbag_04", "prop_beachbag_05", "prop_beachbag_06", "prop_beachbag_combo_01", "prop_beachbag_combo_02", "prop_beachball_02", "prop_beachflag_le", "prop_beach_bars_01", "prop_beach_bars_02", "prop_beach_bbq", "rop_beach_dip_bars_01", "prop_beach_dip_bars_02", "prop_beach_fire", "prop_beach_lg_float", "prop_beach_lg_stretch", "prop_beach_lg_surf", "prop_beach_lotion_01", "rop_beach_lotion_02", "prop_beach_lotion_03", "prop_beach_punchbag", "prop_beach_rings_01", "prop_beach_sculp_01", "prop_beach_towel_02", "prop_beach_volball01", "prop_beach_volball02", "rop_beerneon", "prop_beer_bison", "prop_beer_box_01", "prop_beer_neon_01", "prop_beer_neon_02", "prop_beer_neon_03", "rop_beer_neon_04", "prop_beggers_sign_01", "prop_beggers_sign_02", "prop_beggers_sign_03", "prop_beggers_sign_04", "prop_bench_01b", "prop_bench_01c", "rop_bench_04", "prop_bench_05", "prop_bench_09", "prop_beta_tape", "prop_beware_dog_sign", "prop_bh1_03_gate_l", "prop_bh1_03_gate_r", "prop_bh1_08_mp_gar", "rop_bh1_09_mp_gar", "prop_bh1_09_mp_l", "prop_bh1_09_mp_r", "prop_bh1_16_display", "prop_bh1_44_door_01l", "prop_bh1_44_door_01r", "prop_bh1_48_backdoor_l", "prop_bh1_48_backdoor_r", "prop_bh1_48_gate_1", "prop_bhhotel_door_l", "prop_bhhotel_door_r", "prop_big_bag_01", "prop_big_clock_01", "rop_big_shit_01", "rop_big_shit_02", "prop_bikerack_2", "prop_bikini_disp_01", "prop_bikini_disp_02", "prop_bikini_disp_03", "prop_bikini_disp_04", "prop_bikini_disp_05", "prop_bikini_disp_06", "prop_billboard_01", "prop_billboard_02", "prop_billboard_03", "prop_billboard_04", "prop_billboard_05", "prop_billboard_06", "prop_billboard_07", "prop_billboard_08", "prop_billboard_09", "prop_billboard_09wall", "rop_billboard_10", "prop_billboard_11", "prop_billboard_12", "prop_billboard_13", "prop_billboard_14", "prop_billboard_15", "prop_billboard_16", "prop_billb_frame01a", "prop_billb_frame01b", "prop_billb_frame02a", "prop_billb_frame02b", "prop_billb_frame03a", "prop_billb_frame03b", "prop_billb_frame03c", "prop_billb_frame04a", "prop_billb_frame04b", "prop_binoc_01", "prop_bin_04a", "prop_bin_10a", "prop_bin_10b", "prop_bin_11a", "prop_bin_11b", "prop_bin_12a", "prop_bin_13a", "prop_bin_14a", "prop_bin_14b", "prop_bin_beach_01d", "prop_bin_delpiero", "prop_bin_delpiero_b", "prop_biolab_g_door", "prop_biotech_store", "prop_bison_winch", "prop_blackjack_01", "prop_bleachers_01", "prop_bleachers_02", "prop_bleachers_03", "prop_bleachers_04", "prop_bleachers_05", "prop_blox_spray", "prop_bmu_01", "prop_bmu_01_b", "prop_bmu_02", "prop_bmu_02_ld", "prop_bmu_02_ld_cab", "prop_bmu_02_ld_sup", "prop_bmu_track01", "prop_bmu_track02", "rop_bmu_track03", "prop_bodyarmour_02", "prop_bodyarmour_03", "prop_bodyarmour_04", "rop_bodyarmour_05", "prop_bodyarmour_06", "prop_bollard_01a", "rop_bollard_01b", "prop_bollard_01c", "prop_bollard_03a", "prop_bomb_01", "prop_bomb_01_s", "prop_bonesaw", "prop_bongos_01", "prop_bong_01", "prop_boogbd_stack_01", "prop_boogbd_stack_02", "prop_boogieboard_01", "prop_boogieboard_02", "prop_boogieboard_03", "prop_boogieboard_04", "prop_boogieboard_05", "prop_boogieboard_06", "prop_boogieboard_07", "prop_boogieboard_08", "prop_boogieboard_09", "prop_boogieboard_10", "prop_boombox_01", "prop_bottle_cap_01", "prop_bowling_ball", "prop_bowling_pin", "prop_bowl_crisps", "prop_boxcar5_handle", "prop_boxing_glove_01", "prop_boxpile_10a", "prop_boxpile_10b", "rop_box_ammo01a", "rop_box_ammo02a", "prop_box_ammo03a_set", "prop_box_ammo03a_set2", "prop_box_ammo04a", "prop_box_ammo05b", "prop_box_ammo07a", "prop_box_ammo07b", "prop_box_guncase_01a", "prop_box_guncase_02a", "prop_box_guncase_03a", "prop_box_tea01a", "prop_box_wood05a", "prop_box_wood05b", "prop_box_wood08a", "prop_breadbin_01", "prop_bread_rack_01", "rop_bread_rack_02", "prop_broken_cboard_p1", "rop_broken_cboard_p2", "prop_broken_cell_gate_01", "prop_broom_unit_01", "prop_bskball_01", "prop_bs_map_door_01", "prop_buckets_02", "prop_bucket_01a", "prop_bucket_01b", "prop_bucket_02a", "prop_buck_spade_01", "prop_buck_spade_02", "prop_buck_spade_03", "prop_buck_spade_04", "prop_buck_spade_05", "prop_buck_spade_06", "prop_buck_spade_07", "prop_buck_spade_08", "prop_buck_spade_09", "prop_buck_spade_10", "prop_bumper_01", "prop_bumper_02", "prop_bumper_03", "prop_bumper_04", "rop_bumper_05", "prop_bumper_06", "prop_bumper_car_01", "prop_burto_gate_01", "prop_bush_dead_02", "prop_bush_grape_01", "prop_bush_ivy_01_1m", "prop_bush_ivy_01_2m", "rop_bush_ivy_01_bk", "prop_bush_ivy_01_l", "rop_bush_ivy_01_pot", "prop_bush_ivy_01_r", "prop_bush_ivy_01_top", "rop_bush_ivy_02_1m", "rop_bush_ivy_02_2m", "prop_bush_ivy_02_l", "prop_bush_ivy_02_pot", "rop_bush_ivy_02_r", "prop_bush_ivy_02_top", "prop_bush_lrg_01", "prop_bush_lrg_01b", "prop_bush_lrg_01c", "prop_bush_lrg_01d", "rop_bush_lrg_01e", "prop_bush_lrg_02", "prop_bush_lrg_02b", "prop_bush_lrg_03", "prop_bush_lrg_03b", "prop_bush_lrg_04b", "prop_bush_lrg_04c", "prop_bush_lrg_04d", "prop_bush_med_01", "prop_bush_med_02", "prop_bush_med_03", "prop_bush_med_05", "prop_bush_med_06", "prop_bush_med_07", "prop_bush_neat_01", "prop_bush_neat_02", "prop_bush_neat_03", "prop_bush_neat_04", "rop_bush_neat_05", "prop_bush_neat_06", "prop_bush_neat_07", "prop_bush_neat_08", "prop_bush_ornament_01", "prop_bush_ornament_02", "prop_bush_ornament_03", "prop_bush_ornament_04", "prop_busker_hat_01", "prop_byard_bench01", "prop_byard_bench02", "prop_byard_block_01", "prop_byard_boat01", "prop_byard_boat02", "prop_byard_chains01", "prop_byard_dingy", "prop_byard_elecbox01", "rop_byard_elecbox02", "prop_byard_elecbox03", "prop_byard_elecbox04", "prop_byard_floatpile", "prop_byard_float_01", "prop_byard_float_01b", "prop_byard_float_02", "prop_byard_float_02b", "prop_byard_hoist", "prop_byard_hoist_2", "prop_byard_hoses01", "prop_byard_hoses02", "prop_byard_ladder01", "prop_byard_machine01", "prop_byard_machine02", "prop_byard_machine03", "prop_byard_motor_01", "prop_byard_motor_02", "prop_byard_motor_03", "prop_byard_net02", "prop_byard_phone", "prop_byard_pipes01", "prop_byard_pipe_01", "prop_byard_planks01", "prop_byard_pulley01", "prop_byard_rack", "prop_byard_ramp", "prop_byard_rampold", "prop_byard_rowboat1", "prop_byard_rowboat2", "prop_byard_rowboat3", "prop_byard_rowboat4", "prop_byard_rowboat5", "prop_byard_scfhold01", "prop_byard_sleeper01", "prop_byard_sleeper02", "prop_byard_steps_01", "prop_byard_tank_01", "prop_byard_trailer01", "prop_byard_trailer02", "prop_b_board_blank", "prop_c4_final", "prop_c4_final_green", "prop_cabinet_01", "prop_cabinet_01b", "prop_cabinet_02b", "prop_cablespool_01a", "prop_cablespool_01b", "prop_cablespool_02", "prop_cablespool_03", "prop_cablespool_04", "prop_cablespool_05", "prop_cablespool_06", "prop_cable_hook_01", "prop_camera_strap", "prop_candy_pqs", "prop_can_canoe", "prop_cap_01", "prop_cap_01b", "prop_cap_row_01", "prop_cap_row_01b", "prop_cap_row_02", "prop_cap_row_02b", "prop_carcreeper", "prop_cargo_int", "prop_carjack", "prop_carjack_l2", "prop_carrier_bag_01", "prop_carrier_bag_01_lod", "prop_cartwheel_01", "prop_carwash_roller_horz", "prop_carwash_roller_vert", "prop_car_battery_01", "prop_car_bonnet_01", "prop_car_bonnet_02", "prop_car_door_01", "prop_car_door_02", "prop_car_door_03", "prop_car_door_04", "rop_car_engine_01", "prop_car_exhaust_01", "prop_car_ignition", "rop_car_seat", "prop_casey_sec_id", "rop_cash_case_01", "prop_cash_case_02", "prop_cash_crate_01", "prop_cash_dep_bag_01", "prop_cash_envelope_01", "prop_cash_note_01", "prop_cash_pile_01", "prop_cash_pile_02", "prop_cash_trolly", "prop_casino_door_01l", "prop_casino_door_01r", "prop_cattlecrush", "prop_cat_tail_01", "prop_cctv_02_sm=", "prop_cctv_cont_01", "prop_cctv_cont_03", "prop_cctv_cont_04", "prop_cctv_cont_05", "prop_cctv_cont_06", "rop_cctv_unit_01", "prop_cctv_unit_02", "prop_cctv_unit_05", "prop_cementmixer_01a", "prop_cementmixer_02a", "prop_ceramic_jug_01", "prop_ceramic_jug_cork", "rop_ch1_07_door_01l", "prop_ch1_07_door_01r", "prop_ch1_07_door_02l", "prop_ch1_07_door_02r", "prop_ch2_05d_g_door", "prop_ch2_07b_20_g_door", "prop_ch2_09b_door", "prop_ch2_09c_garage_door", "prop_ch3_01_trlrdoor_l", "prop_ch3_01_trlrdoor_r", "prop_ch3_04_door_01l", "prop_ch3_04_door_01r", "prop_ch3_04_door_02", "prop_chair_01a", "prop_chair_01b", "prop_chair_02", "prop_chair_03", "prop_chair_04a", "prop_chair_04b", "prop_chair_05", "prop_chair_06", "prop_chair_07", "prop_chair_08", "prop_chair_09", "prop_chair_10", "prop_chair_pile_01", "prop_chall_lamp_01", "prop_chall_lamp_01n", "prop_chall_lamp_02", "prop_chateau_chair_01", "prop_cheetah_covered", "prop_chem_grill", "prop_chem_grill_bit", "prop_chem_vial_02", "prop_chem_vial_02b", "prop_cherenneon", "prop_chickencoop_a", "prop_chip_fryer", "prop_choc_ego", "prop_choc_meto", "prop_choc_pq", "prop_ch_025c_g_door_01", "prop_cigar_01", "prop_cigar_02", "prop_cigar_03", "prop_cigar_pack_01", "prop_cigar_pack_02", "prop_clapper_brd_01", "prop_cleaver", "prop_cliff_paper", "prop_clippers_01", "prop_clothes_rail_02", "prop_clothes_rail_03", "prop_clothes_rail_2b", "prop_clothes_tub_01", "prop_clown_chair", "prop_cntrdoor_ld_l", "prop_cntrdoor_ld_r", "prop_coathook_01", "prop_cockneon", "prop_coffee_cup_trailer", "prop_coffee_mac_02", "prop_coffin_02", "prop_coffin_02b", "prop_coke_block_01", "prop_coke_block_half_a", "prop_coke_block_half_b", "prop_compressor_01", "prop_compressor_02", "prop_compressor_03", "prop_com_gar_door_01", "prop_com_ls_door_01", "prop_conc_sacks_02a", "prop_cone_float_1", "prop_conschute", "prop_consign_01c", "prop_consign_02a", "prop_conslift_base", "prop_conslift_brace", "prop_conslift_cage", "prop_conslift_door", "prop_conslift_lift", "prop_conslift_rail", "prop_conslift_rail2", "prop_conslift_steps", "prop_console_01", "prop_construcionlamp_01", "prop_const_fence01a", "prop_const_fence01b", "prop_const_fence02a", "prop_const_fence02b", "prop_const_fence03b", "prop_cons_crate", "prop_cons_plank", "prop_cons_ply01", "prop_cons_ply02", "prop_container_01a", "prop_container_01b", "prop_container_01c", "prop_container_01d", "prop_container_01e", "prop_container_01f", "prop_container_01g", "prop_container_01h", "prop_container_01mb", "prop_container_02a", "prop_container_03a", "prop_container_03b", "prop_container_03mb", "prop_container_03_ld", "prop_container_04a", "prop_container_04mb", "prop_container_05mb", "prop_container_door_mb_l", "prop_container_door_mb_r", "prop_container_hole", "prop_container_ld", "prop_container_ld2", "prop_container_old1", "prop_contnr_pile_01a", "prop_controller_01", "prop_control_rm_door_01", "prop_cont_chiller_01", "prop_cooker_03", "prop_copier_01", "prop_copper_pan", "prop_coral_bush_01", "prop_coral_flat_01", "prop_coral_flat_01_l1", "prop_coral_flat_02", "prop_coral_flat_brainy", "prop_coral_flat_clam", "prop_coral_grass_01", "prop_coral_grass_02", "prop_coral_kelp_01", "prop_coral_kelp_01_l1", "prop_coral_kelp_02", "prop_coral_kelp_02_l1", "prop_coral_kelp_03", "prop_coral_kelp_03a", "prop_coral_kelp_03b", "prop_coral_kelp_03c", "prop_coral_kelp_03d", "prop_coral_kelp_03_l1", "prop_coral_kelp_04", "prop_coral_kelp_04_l1", "prop_coral_pillar_01", "prop_coral_pillar_02", "prop_coral_spikey_01", "prop_coral_stone_03", "prop_coral_stone_04", "prop_coral_sweed_01", "prop_coral_sweed_02", "prop_coral_sweed_03", "prop_coral_sweed_04", "prop_cora_clam_01", "prop_cork_board", "prop_couch_01", "prop_couch_03", "prop_couch_04", "prop_couch_lg_02", "prop_couch_lg_05", "prop_couch_lg_06", "prop_couch_lg_07", "prop_couch_lg_08", "prop_couch_sm1_07", "prop_couch_sm2_07", "prop_couch_sm_02", "prop_couch_sm_05", "prop_couch_sm_06", "prop_couch_sm_07", "prop_crane_01_truck1", "prop_crane_01_truck2", "prop_cranial_saw", "prop_crashed_heli", "prop_cratepile_07a_l1", "prop_crate_01a", "prop_crate_02a", "prop_crate_08a", "prop_crate_09a", "prop_crate_10a", "prop_crate_11a", "prop_crate_11b", "prop_crate_11c", "prop_crate_11d", "prop_crate_float_1", "prop_creosote_b_01", "prop_crispvprop_crisp_small", "prop_crosssaw_01", "prop_cs1_14b_traind", "prop_cs1_14b_traind_dam", "prop_cs4_05_tdoor", "prop_cs4_10_tr_gd_01", "prop_cs4_11_door", "prop_cs6_03_door_l", "prop_cs6_03_door_r", "rop_cs_20m_rope", "prop_cs_30m_rope", "prop_cs_abattoir_switch", "prop_cs_aircon_01", "prop_cs_aircon_fan", "prop_cs_amanda_shoe", "prop_cs_ashtray", "prop_cs_bandana", "prop_cs_bar", "prop_cs_beachtowel_01", "prop_cs_beer_bot_01", "prop_cs_beer_bot_01b", "prop_cs_beer_bot_01lod", "prop_cs_beer_bot_02", "prop_cs_beer_bot_03", "prop_cs_beer_bot_40oz", "prop_cs_beer_bot_40oz_02", "prop_cs_beer_bot_40oz_03", "prop_cs_beer_bot_test", "prop_cs_binder_01", "prop_cs_bin_01", "prop_cs_bin_01_lid", "prop_cs_bin_01_skinned", "prop_cs_bin_02", "prop_cs_bin_03", "prop_cs_book_01", "prop_cs_bottle_opener", "prop_cs_bowie_knife", "prop_cs_bowl_01", "prop_cs_bowl_01b", "prop_cs_box_clothes", "prop_cs_box_step", "prop_cs_brain_chunk", "prop_cs_bs_cup", "prop_cs_bucket_s", "prop_cs_bucket_s_lod", "prop_cs_burger_01", "prop_cs_business_card", "prop_cs_cardbox_01", "prop_cs_cash_note_01", "prop_cs_cctv", "prop_cs_champ_flute", "prop_cs_ciggy_01", "prop_cs_ciggy_01b", "prop_cs_clothes_box", "prop_cs_coke_line", "prop_cs_cont_latch", "prop_cs_crackpipe", "prop_cs_credit_card", "prop_cs_creeper_01", "prop_cs_crisps_01", "prop_cs_cuffs_01", "prop_cs_diaphram", "prop_cs_dildo_01", "prop_cs_documents_01", "prop_cs_dog_lead_2a", "prop_cs_dog_lead_2b", "prop_cs_dog_lead_2c", "prop_cs_dog_lead_3a", "prop_cs_dog_lead_3b", "prop_cs_dog_lead_a", "prop_cs_dog_lead_b", "prop_cs_dog_lead_c", "prop_cs_duffel_01", "prop_cs_duffel_01b", "prop_cs_dumpster_01a", "prop_cs_dumpster_lidl", "prop_cs_dumpster_lidr", "prop_cs_dvd", "prop_cs_dvd_case", "prop_cs_dvd_player", "prop_cs_envolope_01", "prop_cs_fertilizer", "prop_cs_film_reel_01", "prop_cs_folding_chair_01", "prop_cs_fork", "prop_cs_frank_photo", "prop_cs_freightdoor_l1", "prop_cs_freightdoor_r1", "prop_cs_fridge", "prop_cs_fridge_door", "prop_cs_fuel_hose", "prop_cs_fuel_nozle", "prop_cs_gascutter_1", "prop_cs_gascutter_2", "prop_cs_glass_scrap", "prop_cs_gravyard_gate_l", "prop_cs_gravyard_gate_r", "prop_cs_gunrack", "prop_cs_hand_radio", "prop_cs_heist_bag_01", "prop_cs_heist_bag_02", "prop_cs_heist_bag_strap_01", "prop_cs_heist_rope", "prop_cs_heist_rope_b", "prop_cs_hotdog_01", "prop_cs_hotdog_02", "prop_cs_h_bag_strap_01", "prop_cs_ice_locker", "prop_cs_ice_locker_door_l", "prop_cs_ice_locker_door_r", "prop_cs_ilev_blind_01", "prop_cs_ironing_board", "prop_cs_katana_01", "prop_cs_kettle_01", "prop_cs_keyboard_01", "prop_cs_keys_01", "prop_cs_kitchen_cab_l2", "prop_cs_kitchen_cab_ld", "prop_cs_kitchen_cab_rd", "prop_cs_lazlow_ponytail", "prop_cs_lazlow_shirt_01", "prop_cs_lazlow_shirt_01b", "prop_cs_leaf", "prop_cs_leg_chain_01", "prop_cs_lester_crate", "prop_cs_lipstick", "prop_cs_magazine", "prop_cs_marker_01", "prop_cs_meth_pipe", "prop_cs_milk_01", "prop_cs_mini_tv", "prop_cs_mopbucket_01", "prop_cs_mop_s", "prop_cs_mouse_01", "prop_cs_nail_file", "prop_cs_newspaper", "prop_cs_office_chair", "prop_cs_overalls_01", "prop_cs_package_01", "prop_cs_padlock", "prop_cs_pamphlet_01", "prop_cs_panel_01", "prop_cs_panties", "prop_cs_panties_02", "prop_cs_panties_03", "prop_cs_paper_cup", "prop_cs_para_ropebit", "prop_cs_para_ropes", "prop_cs_pebble", "prop_cs_pebble_02", "prop_cs_petrol_can", "prop_cs_phone_01", "prop_cs_photoframe_01", "prop_cs_pills", "prop_cs_plane_int_01", "prop_cs_planning_photo", "prop_cs_plant_01", "prop_cs_plate_01", "prop_cs_polaroid", "prop_cs_police_torch", "prop_cs_pour_tube", "prop_cs_power_cell", "prop_cs_power_cord", "prop_cs_protest_sign_01", "prop_cs_protest_sign_02", "prop_cs_protest_sign_02b", "prop_cs_protest_sign_03", "prop_cs_protest_sign_04a", "prop_cs_protest_sign_04b", "prop_cs_rage_statue_p1", "prop_cs_rage_statue_p2", "prop_cs_remote_01", "prop_cs_rolled_paper", "prop_cs_rope_tie_01", "prop_cs_rub_binbag_01", "prop_cs_rub_box_01", "prop_cs_rub_box_02", "prop_cs_r_business_card", "prop_cs_sack_01", "prop_cs_saucer_01", "prop_cs_sc1_11_gate", "prop_cs_scissors", "prop_cs_script_bottle", "prop_cs_script_bottle_01", "prop_cs_server_drive", "prop_cs_sheers", "prop_cs_shirt_01", "prop_cs_shopping_bag", "prop_cs_shot_glass", "prop_cs_silver_tray", "prop_cs_sink_filler", "prop_cs_sink_filler_02", "prop_cs_sink_filler_03", "prop_cs_sm_27_gate", "prop_cs_sol_glasses", "prop_cs_spray_can", "prop_cs_steak", "prop_cs_stock_book", "prop_cs_street_binbag_01", "prop_cs_street_card_01", "prop_cs_street_card_02", "prop_cs_sub_hook_01", "prop_cs_sub_rope_01", "prop_cs_swipe_card", "prop_cs_tablet", "prop_cs_tablet_02", "prop_cs_toaster", "prop_cs_trolley_01", "prop_cs_trowel", "prop_cs_truck_ladder", "prop_cs_tshirt_ball_01", "prop_cs_tv_stand", "prop_cs_t_shirt_pile", "prop_cs_valve", "prop_cs_vent_cover", "prop_cs_vial_01", "prop_cs_walkie_talkie", "prop_cs_walking_stick", "prop_cs_whiskey_bottle", "prop_cs_whiskey_bot_stop", "prop_cs_wrench", "rop_cub_door_lifeblurb", "prop_cub_lifeblurb", "prop_cuff_keys_01", "prop_cup_saucer_01", "prop_curl_bar_01", "prop_damdoor_01", "prop_dart_1", "prop_dart_2", "prop_dart_bd_01", "prop_dart_bd_cab_01", "prop_defilied_ragdoll_01", "prop_desert_iron_01", "prop_tea_trolly", "prop_tea_urn", "prop_telegraph_01a", "prop_telegraph_01b", "prop_telegraph_01c", "prop_telegraph_01d", "prop_telegraph_01e", "prop_telegraph_01f", "prop_telegraph_01g", "prop_telegraph_02a", "prop_telegraph_02b", "prop_telegraph_03", "prop_telegraph_04a", "prop_telegraph_04b", "prop_telegraph_05a", "prop_telegraph_05b", "prop_telegraph_05c", "prop_telegraph_06a", "prop_telegraph_06b", "prop_telegraph_06c", "prop_telegwall_01a", "prop_telegwall_01b", "prop_telegwall_02a", "prop_telegwall_03a", "prop_telegwall_03b", "prop_telegwall_04a", "prop_telescope", "prop_telescope_01", "prop_temp_block_blocker", "prop_tennis_bag_01", "prop_tennis_ball", "prop_tennis_ball_lobber", "prop_tennis_rack_01", "prop_tennis_rack_01b", "prop_test_boulder_01", "prop_test_boulder_02", "prop_test_boulder_03", "prop_test_boulder_04", "prop_test_elevator", "prop_test_elevator_dl", "prop_test_elevator_dr", "prop_tick", "prop_tick_02", "prop_till_01_dam", "prop_till_02", "prop_till_03", "prop_time_capsule_01", "prop_tint_towel", "prop_tint_towels_01", "prop_tint_towels_01b", "prop_toaster_01", "prop_toaster_02", "prop_toiletfoot_static", "prop_toilet_01", "prop_toilet_02", "prop_toilet_03", "prop_toilet_brush_01", "prop_toilet_cube_01", "prop_toilet_cube_02", "prop_toilet_roll_01", "prop_toilet_roll_02", "prop_toilet_roll_03", "prop_toilet_roll_04", "prop_toilet_roll_05", "prop_toilet_shamp_01", "prop_toilet_shamp_02", "prop_toilet_soap_01", "prop_toilet_soap_02", "prop_toilet_soap_03", "prop_toilet_soap_04", "prop_toolchest_01", "prop_toolchest_02", "prop_toolchest_03", "prop_toolchest_04", "prop_toolchest_05", "prop_tool_adjspanner", "prop_tool_bench01", "prop_tool_bluepnt", "prop_tool_box_01", "prop_tool_box_02", "prop_tool_box_03", "prop_tool_box_04", "prop_tool_box_05", "prop_tool_box_06", "prop_tool_box_07", "prop_tool_broom", "prop_tool_broom2", "prop_tool_broom2_l1", "prop_tool_cable01", "prop_tool_cable02", "prop_tool_consaw", "prop_tool_drill", "prop_tool_fireaxe", "prop_tool_hammer", "prop_tool_hardhat", "prop_tool_jackham", "prop_tool_mallet", "prop_tool_mopbucket", "prop_tool_nailgun", "prop_tool_pickaxe", "prop_tool_pliers", "prop_tool_rake", "prop_tool_rake_l1", "prop_tool_sawhorse", "prop_tool_screwdvr01", "prop_tool_screwdvr02", "prop_tool_screwdvr03", "prop_tool_shovel", "prop_tool_shovel006", "rop_tool_shovel2", "prop_tool_shovel3", "prop_tool_shovel4", "prop_tool_shovel5", "prop_tool_sledgeham", "prop_tool_spanner01", "prop_tool_spanner02", "prop_tool_spanner03", "prop_tool_torch", "prop_tool_wrench", "prop_toothbrush_01", "prop_toothb_cup_01", "prop_toothpaste_01", "prop_tornado_wheel", "prop_torture_01", "prop_torture_ch_01", "prop_tourist_map_01", "prop_towel2_01", "prop_towel2_02", "prop_towel_01", "prop_towel_rail_01", "prop_towel_rail_02", "prop_towel_shelf_01", "prop_towel_small_01", "prop_towercrane_01a", "prop_towercrane_02a", "prop_towercrane_02b", "prop_towercrane_02c", "prop_towercrane_02d", "prop_towercrane_02e", "prop_towercrane_02el", "prop_towercrane_02el2", "prop_traffic_rail_1c", "prop_traffic_rail_2", "prop_trailer01", "prop_trailer01_up", "prop_trailer_01_new", "prop_trailer_door_closed", "prop_trailer_door_open", "prop_trailer_monitor_01", "prop_trailr_base", "prop_trailr_base_static", "prop_train_ticket_02", "prop_tram_pole_double01", "prop_tram_pole_double02", "prop_tram_pole_double03", "prop_tram_pole_roadside", "prop_tram_pole_single01", "prop_tram_pole_single02", "prop_tram_pole_wide01", "prop_tree_birch_01", "prop_tree_birch_02", "prop_tree_birch_03", "prop_tree_birch_03b", "prop_tree_birch_04", "prop_tree_birch_05", "prop_tree_cedar_02", "prop_tree_cedar_03", "prop_tree_cedar_04", "prop_tree_cedar_s_01", "prop_tree_cedar_s_02", "prop_tree_cedar_s_04", "prop_tree_cedar_s_05", "prop_tree_cedar_s_06", "prop_tree_cypress_01", "prop_tree_eng_oak_01", "prop_tree_eucalip_01", "prop_tree_fallen_01", "prop_tree_fallen_02", "prop_tree_fallen_pine_01", "prop_tree_jacada_01", "prop_tree_jacada_02", "prop_tree_lficus_02", "prop_tree_lficus_03", "prop_tree_lficus_05", "prop_tree_lficus_06", "prop_tree_log_01", "prop_tree_log_02", "prop_tree_maple_02", "prop_tree_maple_03", "prop_tree_mquite_01", "prop_tree_oak_01", "prop_tree_olive_01", "prop_tree_pine_01", "prop_tree_pine_02", "prop_tree_stump_01", "prop_trevor_rope_01", "prop_trev_sec_id", "prop_trev_tv_01", "prop_triple_grid_line", "prop_tri_finish_banner", "prop_tri_pod", "prop_tri_pod_lod", "prop_tri_start_banner", "prop_tri_table_01", "prop_trough1", "prop_truktrailer_01a", "rop_tshirt_box_02", "prop_tshirt_shelf_1", "rop_tshirt_shelf_2", "prop_tshirt_shelf_2a", "prop_tshirt_shelf_2b", "prop_tshirt_shelf_2c", "prop_tshirt_stand_01", "prop_tshirt_stand_01b", "prop_tshirt_stand_02", "prop_tshirt_stand_04", "prop_tt_screenstatic", "prop_tumbler_01", "prop_tumbler_01b", "prop_tumbler_01_empty", "prop_tunnel_liner01", "prop_tunnel_liner02", "prop_tunnel_liner03", "prop_turkey_leg_01", "prop_turnstyle_01", "prop_tv_02", "prop_tv_03_overlay", "prop_tv_04", "prop_tv_05", "prop_tv_06", "prop_tv_07", "prop_tv_cabinet_03", "prop_tv_cabinet_04", "prop_tv_cabinet_05", "prop_tv_cam_02", "prop_tv_flat_01", "prop_tv_flat_01_screen", "prop_tv_flat_02b", "prop_tv_flat_03", "prop_tv_flat_03b", "prop_tv_flat_michael", "prop_tv_test", "rop_tyre_rack_01", "prop_tyre_spike_01", "prop_t_coffe_table", "prop_t_shirt_ironing", "prop_t_shirt_row_01", "prop_t_shirt_row_02", "prop_t_shirt_row_02b", "prop_t_shirt_row_03", "prop_t_shirt_row_04", "prop_t_shirt_row_05l", "prop_t_shirt_row_05r", "prop_t_sofa", "prop_t_sofa_02", "prop_t_telescope_01b", "prop_umpire_01", "prop_utensil", "prop_valet_03", "prop_vault_shutter", "prop_vb_34_tencrt_lighting", "prop_vcr_01", "prop_veg_corn_01", "rop_veg_crop_01", "prop_veg_crop_02", "prop_veg_crop_04", "prop_veg_crop_04_leaf", "prop_veg_crop_05", "prop_veg_crop_06", "prop_veg_crop_orange", "rop_veg_crop_tr_01", "prop_veg_crop_tr_02", "prop_veg_grass_01_a", "prop_veg_grass_01_b", "prop_veg_grass_01_c", "prop_veg_grass_01_d", "prop_veg_grass_02_a", "prop_vehicle_hook", "prop_vend_coffe_01", "prop_vend_condom_01", "prop_vend_fags_01", "prop_vend_fridge01", "rop_vend_snak_01", "prop_venice_board_01", "prop_venice_board_02", "prop_venice_board_03", "rop_venice_counter_01", "prop_venice_counter_02", "prop_venice_counter_03", "prop_venice_counter_04", "prop_venice_shop_front_01", "prop_venice_sign_09", "prop_venice_sign_10", "prop_venice_sign_11", "prop_venice_sign_12", "prop_venice_sign_14", "prop_venice_sign_15", "prop_venice_sign_16", "prop_venice_sign_17", "prop_venice_sign_18", "prop_ventsystem_01", "prop_ventsystem_02", "prop_ventsystem_03", "prop_ventsystem_04", "prop_ven_market_stool", "prop_ven_market_table1", "prop_ven_shop_1_counter", "prop_vertdrill_01", "prop_voltmeter_01", "prop_v_15_cars_clock", "prop_v_5_bclock", "prop_v_bmike_01", "prop_v_cam_01", "prop_v_door_44", "prop_v_hook_s", "prop_v_m_phone_01", "prop_v_m_phone_o1s", "prop_v_parachute", "prop_waiting_seat_01", "prop_wait_bench_01", "prop_walllight_ld_01b", "prop_wall_light_08a", "prop_wall_light_10a", "rop_wall_light_10b", "prop_wall_light_10c", "prop_wall_light_11", "prop_wall_light_12", "prop_wall_light_17b", "prop_wall_light_18a", "prop_wall_vent_01", "prop_wall_vent_02", "prop_wall_vent_03", "prop_wall_vent_04", "prop_wall_vent_05", "prop_wall_vent_06", "prop_wardrobe_door_01", "prop_warehseshelf01", "prop_warehseshelf02", "prop_warehseshelf03", "prop_warninglight_01", "prop_washer_01", "prop_washer_02", "prop_washer_03", "prop_washing_basket_01", "prop_watercrate_01", "prop_wateringcan", "prop_watertower01", "prop_watertower02", "prop_watertower03", "prop_watertower04", "prop_waterwheela", "prop_waterwheelb", "prop_water_bottle", "prop_water_bottle_dark", "prop_water_corpse_01", "prop_water_corpse_02", "prop_water_ramp_01", "prop_water_ramp_02", "prop_water_ramp_03", "prop_weed_01", "rop_weed_02", "prop_weed_block_01", "prop_weed_bottle", "prop_weed_pallet", "prop_weed_tub_01", "prop_weed_tub_01b", "prop_weight_10k", "prop_weight_15k", "prop_weight_1_5k", "prop_weight_20k", "prop_weight_2_5k", "prop_weight_5k", "prop_weight_rack_01", "prop_weight_rack_02", "prop_welding_mask_01", "prop_weld_torch", "prop_wheat_grass_empty", "prop_wheat_grass_glass", "prop_wheelbarrow01a", "prop_wheelbarrow02a", "prop_wheelchair_01", "prop_wheel_01", "prop_wheel_02", "prop_wheel_03", "prop_wheel_04", "prop_wheel_05", "prop_wheel_06", "prop_wheel_hub_01", "prop_wheel_hub_02_lod_02", "prop_wheel_rim_01", "prop_wheel_rim_02", "prop_wheel_rim_03", "prop_wheel_rim_04", "prop_wheel_rim_05", "prop_wheel_tyre", "prop_whisk", "prop_white_keyboard", "prop_winch_hook_long", "prop_winch_hook_short", "prop_windmill2", "prop_windmill_01_l1", "prop_windmill_01_slod", "prop_windmill_01_slod2", "prop_windowbox_a", "prop_windowbox_b", "prop_windowbox_broken", "prop_windowbox_small", "rop_win_plug_01", "prop_win_plug_01_dam", "prop_win_trailer_ld", "prop_wok", "prop_woodpile_02a", "prop_worklight_01a_l1", "prop_worklight_03a_l1", "prop_worklight_03b_l1", "prop_worklight_04a", "prop_worklight_04b_l1", "prop_worklight_04c_l1", "prop_worklight_04d_l1", "prop_workwall_01", "prop_workwall_02", "prop_wreckedcart", "prop_wrecked_buzzard", "prop_w_board_blank", "prop_w_board_blank_2", "prop_w_fountain_01", "prop_w_r_cedar_01", "prop_w_r_cedar_dead", "prop_yacht_lounger", "prop_yacht_seat_01", "prop_yacht_seat_02", "prop_yacht_seat_03", "prop_yacht_table_01", "prop_yacht_table_02", "prop_yacht_table_03", "prop_yaught_chair_01", "prop_yaught_sofa_01", "prop_yell_plastic_target", "prop_yoga_mat_01", "prop_yoga_mat_02", "prop_yoga_mat_03", "prop_ztype_covered", "p_ing_skiprope_01", "p_ing_skiprope_01_s", "p_skiprope_r_s", "test_prop_gravestones_04a", "test_prop_gravestones_05a", "test_prop_gravestones_07a", "test_prop_gravestones_08a", "test_prop_gravestones_09a", "test_prop_gravetomb_01a", "test_prop_gravetomb_02a", "v_prop_floatcandle", "prop_detergent_01a", "prop_detergent_01b", "prop_devin_box_01", "prop_devin_rope_01", "prop_diggerbkt_01", "prop_direct_chair_01", "prop_direct_chair_02", "prop_display_unit_01", "prop_display_unit_02", "prop_disp_cabinet_002", "prop_disp_cabinet_01", "prop_disp_razor_01", "prop_distantcar_day", "prop_distantcar_night", "prop_distantcar_truck", "prop_dj_deck_01", "prop_dj_deck_02", "prop_dock_bouy_1", "prop_dock_bouy_2", "prop_dock_bouy_3", "prop_dock_bouy_5", "prop_dock_crane_01", "prop_dock_crane_02", "prop_dock_crane_02_cab", "prop_dock_crane_02_hook", "prop_dock_crane_02_ld", "prop_dock_crane_04", "prop_dock_crane_lift", "prop_dock_float_1", "prop_dock_float_1b", "prop_dock_moor_01", "prop_dock_moor_04", "prop_dock_moor_05", "prop_dock_moor_06", "prop_dock_moor_07", "prop_dock_ropefloat", "prop_dock_ropetyre1", "prop_dock_ropetyre2", "prop_dock_ropetyre3", "prop_dock_rtg_01", "prop_dock_rtg_ld", "prop_dock_shippad", "prop_dock_sign_01", "prop_dock_woodpole1", "prop_dock_woodpole2", "prop_dock_woodpole3", "prop_dock_woodpole4", "prop_dock_woodpole5", "prop_dog_cage_01", "prop_dog_cage_02", "prop_dolly_01", "prop_dolly_02", "prop_donut_01", "prop_donut_02", "prop_donut_02b", "prop_door_01", "prop_door_balcony_frame", "prop_door_balcony_left", "prop_door_balcony_right", "prop_door_bell_01", "prop_double_grid_line", "prop_dress_disp_01", "prop_dress_disp_02", "prop_dress_disp_03", "prop_dress_disp_04", "prop_drop_armscrate_01", "prop_drop_armscrate_01b", "prop_drop_crate_01", "prop_drop_crate_01_set", "prop_drop_crate_01_set2", "prop_drug_burner", "prop_drug_package", "prop_drug_package_02", "prop_drywallpile_01", "prop_drywallpile_02", "prop_dt1_13_groundlight", "5prop_dt1_13_walllightsource", "prop_dt1_20_mp_door_l", "prop_dt1_20_mp_door_r", "prop_dt1_20_mp_gar", "prop_ducktape_01", "prop_dummy_01", "prop_dummy_car", "prop_dummy_light", "prop_dummy_plane", "prop_dumpster_3a", "prop_dumpster_3step", "prop_dumpster_4a", "prop_dumpster_4b", "prop_d_balcony_l_ligh", "prop_d_balcony_r_light", "prop_ear_defenders_01", "prop_ecg_01", "prop_ecg_01_cable_01", "prop_ecg_01_cable_02", "prop_ecola_can", "prop_egg_clock_01", "prop_ejector_seat_01", "prop_elecbox_03a", "prop_elecbox_10", "prop_elecbox_12", "prop_elecbox_13", "prop_elecbox_14", "prop_elecbox_15", "prop_elecbox_16", "prop_elecbox_17", "prop_elecbox_18", "prop_elecbox_19", "prop_elecbox_20", "prop_elecbox_21", "prop_elecbox_22", "prop_elecbox_23", "prop_elecbox_24", "prop_elecbox_24b", "prop_elecbox_25", "prop_el_guitar_01", "prop_el_guitar_02", "rop_el_guitar_03", "prop_employee_month_01", "prop_employee_month_02", "prop_energy_drink", "prop_entityxf_covered", "prop_epsilon_door_l", "prop_epsilon_door_r", "prop_etricmotor_01", "prop_exer_bike_01", "prop_faceoffice_door_l", "prop_faceoffice_door_r", "prop_face_rag_01", "prop_facgate_01", "prop_facgate_01b", "prop_facgate_02pol", "prop_facgate_02_l", "prop_facgate_03post", "prop_facgate_03_l", "prop_facgate_03_ld_l", "prop_facgate_03_ld_r", "prop_facgate_03_r", "prop_facgate_04_l", "rop_facgate_04_r", "prop_facgate_05_r", "prop_facgate_05_r_dam_l1", "prop_facgate_05_r_l1", "prop_facgate_06_l", "prop_facgate_06_r", "prop_facgate_07", "prop_facgate_07b", "prop_facgate_08", "prop_facgate_08_frame", "prop_facgate_08_ld2", "prop_facgate_id1_27", "prop_fac_machine_02", "prop_fag_packet_01", "prop_fan_01", "prop_fan_palm_01a", "prop_fax_01", "prop_fbi3_coffee_table", "prop_fbibombbin", "prop_fbibombcupbrd", "prop_fbibombfile", "prop_fbibombplant", "prop_feeder1", "prop_feed_sack_01", "prop_feed_sack_02", "prop_fence_log_01", "prop_fence_log_02", "prop_ferris_car_01", "prop_ferris_car_01_lod1", "prop_ff_counter_01", "prop_ff_counter_02", "rop_ff_counter_03", "prop_ff_noodle_01", "prop_ff_noodle_02", "prop_ff_shelves_01", "prop_ff_sink_01", "prop_ff_sink_02", "prop_fib_badge", "prop_fib_broken_window", "prop_fib_skylight_piece", "prop_film_cam_01", "prop_fireescape_01a", "prop_fireescape_01b", "prop_fireescape_02a", "prop_fireescape_02b", "prop_fire_driser_1a", "prop_fire_driser_1b", "prop_fire_driser_2b", "prop_fire_driser_3b", "prop_fire_driser_4a", "prop_fire_driser_4b", "rop_fire_hosereel", "prop_fishing_rod_01", "prop_fishing_rod_02", "prop_fish_slice_01", "prop_flagpole_1a", "prop_flagpole_2a", "prop_flagpole_3a", "prop_flare_01", "prop_flare_01b", "prop_flash_unit", "prop_flatbed_strap", "prop_flatbed_strap_b", "prop_flatscreen_overlay", "prop_flattrailer_01a", "rop_flattruck_01a", "prop_fleeca_atm", "prop_flight_box_01", "prop_flight_box_insert", "prop_flight_box_insert2", "rop_flipchair_01", "prop_floor_duster_01", "prop_fncconstruc_02a", "rop_fnccorgm_05a", "prop_fnccorgm_05b", "prop_fnccorgm_06a", "prop_fnccorgm_06b", "prop_fnclink_01gate1", "prop_fnclink_02gate1", "prop_fnclink_02gate2", "prop_fnclink_02gate5", "prop_fnclink_02gate6_l", "prop_fnclink_02gate6_r", "prop_fnclink_02gate7", "prop_fnclink_03gate1", "prop_fnclink_03gate2", "prop_fnclink_03gate4", "prop_fnclink_03gate5", "prop_fnclink_04gate1", "prop_fnclink_04h_l2", "prop_fnclink_06gate2", "prop_fnclink_06gate3", "prop_fnclink_06gatepost", "prop_fnclink_07gate1", "prop_fnclink_07gate2", "prop_fnclink_07gate3", "prop_fnclink_09gate1", "prop_fnclink_10a", "prop_fnclink_10b", "rop_fnclink_10c", "prop_fnclink_10d", "prop_fnclink_10e", "prop_fnclog_01a", "prop_fnclog_01b", "prop_fncpeir_03a", "prop_fncres_02a", "prop_fncres_02b", "prop_fncres_02c", "prop_fncres_02d", "prop_fncres_02_gate1", "prop_fncres_03gate1", "prop_fncres_05c_l1", "prop_fncsec_01a", "prop_fncsec_01b", "prop_fncsec_01crnr", "prop_fncsec_01gate", "prop_fncsec_01pole", "prop_fncsec_02a", "prop_fncsec_02pole", "prop_fncsec_04a", "prop_fncwood_07gate1", "prop_fncwood_11a_l1", "prop_fncwood_16a", "prop_fncwood_16b", "prop_fncwood_16", "prop_fncwood_18a", "prop_folded_polo_shirt", "prop_folder_01", "prop_folder_02", "prop_food_bin_01", "rop_food_bin_02", "prop_food_bs_bshelf", "prop_food_bs_cups01", "prop_food_bs_cups03", "prop_food_bs_soda_01", "prop_food_bs_soda_02", "prop_food_bs_tray_01", "prop_food_bs_tray_06", "prop_food_burg1", "prop_food_burg2", "prop_food_cb_bshelf", "prop_food_cb_burg01", "prop_food_cb_cups01", "prop_food_cb_donuts", "prop_food_cb_nugets", "prop_food_cb_soda_01", "prop_food_cb_soda_02", "prop_food_cb_tray_01", "prop_food_cups1", "prop_food_napkin_01", "prop_food_napkin_02", "prop_food_tray_01", "prop_food_van_01", "prop_food_van_02", "prop_forsalejr2", "prop_forsalejr3", "prop_forsalejr4", "prop_foundation_sponge", "prop_fountain1", "prop_fountain2", "prop_franklin_dl", "prop_freeweight_01", "prop_freeweight_02", "prop_fridge_01", "prop_fridge_03", "prop_front_seat_01", "rop_front_seat_02", "prop_front_seat_03", "prop_front_seat_04", "prop_front_seat_05", "prop_front_seat_06", "prop_front_seat_07", "prop_front_seat_row_01", "prop_fruitstand_b_nite", "prop_fruit_basket", "prop_ftowel_01", "rop_ftowel_07", "prop_ftowel_08", "prop_ftowel_10", "prop_f_b_insert_broken", "prop_f_duster_01_s", "prop_f_duster_02", "prop_gaffer_arm_bind", "prop_gaffer_arm_bind_cut", "prop_gaffer_leg_bind", "prop_gaffer_leg_bind_cut", "prop_gaffer_tape", "prop_gaffer_tape_strip", "prop_game_clock_01", "prop_game_clock_02", "prop_garden_dreamcatch_01", "rop_garden_edging_01", "prop_garden_edging_02", "prop_garden_zapper_01", "rop_gardnght_01", "prop_gar_door_01", "prop_gar_door_02", "prop_gar_door_03", "prop_gar_door_03_ld", "prop_gar_door_04", "prop_gar_door_05", "prop_gar_door_05_l", "prop_gar_door_05_r", "prop_gar_door_a_01", "prop_gar_door_plug", "rop_gascage01", "rop_gascyl_ramp_01", "prop_gascyl_ramp_door_01", "prop_gas_01", "prop_gas_02", "rop_gas_03", "prop_gas_04", "prop_gas_05", "rop_gas_grenade", "prop_gas_mask_hang_01", "prop_gatecom_02", "prop_gate_airport_01", "prop_gate_bridge_ld", "prop_gate_cult_01_l", "prop_gate_cult_01_r", "rop_gate_docks_ld", "prop_gate_farm_01a", "prop_gate_farm_post", "prop_gate_frame_01", "prop_gate_frame_02", "prop_gate_frame_04", "prop_gate_frame_05", "prop_gate_frame_06", "rop_gate_military_01", "prop_gate_prison_01", "prop_gate_tep_01_l", "rop_gate_tep_01_r", "rop_gazebo_03", "prop_gd_ch2_08", "prop_generator_02a", "rop_generator_03a", "prop_generator_04", "rop_ghettoblast_02", "prop_girder_01a", "rop_glasscutter_01", "prop_glass_suck_holder", "prop_glf_roller", "prop_glf_spreader", "prop_gold_bar", "prop_gold_cont_01", "prop_gold_cont_01b", "prop_gold_trolly", "prop_gold_trolly_full", "prop_gold_trolly_strap_01", "prop_golf_bag_01", "prop_golf_bag_01b", "prop_golf_bag_01c", "prop_golf_ball", "prop_golf_ball_p2", "prop_golf_ball_p3", "prop_golf_ball_p4", "prop_golf_ball_tee", "prop_golf_driver", "prop_golf_iron_01", "prop_golf_marker_01", "prop_golf_pitcher_01", "prop_golf_putter_01", "prop_golf_tee", "prop_golf_wood_01", "prop_grain_hopper", "rop_grapes_01", "prop_grapes_02", "prop_grass_dry_02", "prop_grass_dry_03", "rop_gravestones_01a", "prop_gravestones_02a", "prop_gravestones_03a", "prop_gravestones_04a", "prop_gravestones_05a", "prop_gravestones_06a", "prop_gravestones_07a", "prop_gravestones_08a", "prop_gravestones_09a", "prop_gravestones_10a", "prop_gravetomb_01a", "prop_gravetomb_02a", "prop_griddle_01", "prop_griddle_02", "prop_grumandoor_l", "prop_grumandoor_r", "rop_gshotsensor_01", "prop_gun_case_01", "rop_gun_case_02", "rop_gun_frame", "prop_hacky_sack_01", "prop_handdry_01", "prop_handdry_02", "prop_handrake", "prop_handtowels", "prop_hand_toilet", "prop_hanger_door_1", "prop_hard_hat_01", "prop_hat_box_01", "prop_hat_box_02", "prop_hat_box_03", "prop_hat_box_04", "prop_hat_box_05", "prop_hat_box_06", "prop_haybailer_01", "prop_haybale_01", "prop_haybale_02", "prop_haybale_stack_01", "prop_hd_seats_01", "prop_headphones_01", "prop_headset_01", "prop_hedge_trimmer_01", "prop_helipad_01", "prop_helipad_02", "prop_henna_disp_01", "prop_henna_disp_02", "prop_henna_disp_03", "prop_hifi_01", "prop_hobo_stove_01", "prop_hockey_bag_01", "prop_hole_plug_01", "prop_holster_01", "prop_homeless_matress_01", "prop_homeless_matress_02", "prop_hose_1", "prop_hose_2", "prop_hose_3", "prop_hose_nozzle", "rop_hospitaldoors_start", "prop_hospital_door_l", "prop_hospital_door_r", "prop_hotel_clock_01", "prop_hotel_trolley", "prop_hottub2", "prop_huf_rag_01", "prop_huge_display_01", "prop_huge_display_02", "prop_hunterhide", "prop_hw1_03_gardoor_01", "prop_hw1_04_door_l1", "rop_hw1_04_door_r1", "prop_hw1_23_door=", "prop_hwbowl_pseat_6x1", "prop_hwbowl_seat_01", "prop_hwbowl_seat_02", "prop_hwbowl_seat_03", "prop_hwbowl_seat_03b", "prop_hwbowl_seat_6x6", "prop_hydro_platform_01", "prop_ice_box_01", "prop_ice_box_01_l1", "prop_ice_cube_01", "prop_ice_cube_02", "prop_ice_cube_03", "prop_id2_11_gdoor", "prop_id2_20_clock", "prop_idol_01", "prop_idol_01_error", "prop_idol_case", "prop_idol_case_01", "prop_idol_case_02", "prop_id_21_gardoor_01", "rop_id_21_gardoor_02", "prop_indus_meet_door_l", "prop_indus_meet_door_r", "prop_ind_barge_01", "prop_ind_barge_02", "prop_ind_coalcar_01", "prop_ind_coalcar_02", "prop_ind_coalcar_03", "prop_ind_conveyor_01", "prop_ind_conveyor_02", "prop_ind_conveyor_04", "prop_ind_crusher", "prop_ind_deiseltank", "prop_ind_light_01a", "prop_ind_light_01b", "prop_ind_light_01c", "prop_ind_mech_01c", "prop_ind_mech_02a", "prop_ind_mech_02b", "prop_ind_mech_03a", "prop_ind_mech_04a", "prop_ind_oldcrane", "prop_ind_washer_02", "prop_inflatearch_01", "prop_inflategate_01", "prop_ing_camera_01", "prop_ing_crowbar", "prop_inhaler_01", "prop_int_gate01", "rop_in_tray_01", "prop_irish_sign_01", "prop_irish_sign_02", "prop_irish_sign_03", "prop_irish_sign_04", "rop_irish_sign_05", "prop_irish_sign_06", "rop_irish_sign_07", "prop_irish_sign_08", "prop_irish_sign_09", "prop_irish_sign_10", "prop_irish_sign_11", "prop_irish_sign_12", "prop_irish_sign_13", "prop_iron_01", "prop_jb700_covered", "prop_jeans_01", "prop_jetski_ramp_01", "prop_jet_bloodsplat_01", "prop_jewel_02a", "prop_jewel_02b", "prop_jewel_02c", "prop_jewel_03a", "prop_jewel_03b", "prop_jewel_04a", "prop_jewel_04b", "prop_jewel_pickup_new_01", "prop_juice_dispenser", "prop_juice_pool_01", "prop_jukebox_01", "prop_jukebox_02", "prop_jyard_block_01a", "prop_j_disptray_01", "prop_j_disptray_01b", "prop_j_disptray_01_dam", "prop_j_disptray_02", "prop_j_disptray_02_dam", "prop_j_disptray_03", "prop_j_disptray_03_dam", "prop_j_disptray_04", "prop_j_disptray_04b", "prop_j_disptray_05", "prop_j_disptray_05b", "prop_j_heist_pic_01", "prop_j_heist_pic_02", "prop_j_heist_pic_03", "prop_j_heist_pic_04", "prop_j_neck_disp_01", "prop_j_neck_disp_02", "prop_j_neck_disp_03", "prop_kayak_01", "prop_kayak_01b", "prop_kebab_grill", "rop_keg_01", "prop_kettle", "prop_kettle_01", "prop_keyboard_01a", "rop_keyboard_01b", "prop_kino_light_01", "prop_kino_light_03", "prop_kitch_juicer", "prop_kitch_pot_fry", "prop_kitch_pot_huge", "prop_kitch_pot_lrg", "prop_kitch_pot_lrg2", "prop_kitch_pot_med", "prop_kitch_pot_sm", "prop_knife=436978267prop_knife_stand", "prop_kt1_06_door_l", "rop_kt1_06_door_r", "rop_kt1_10_mpdoor_l", "prop_kt1_10_mpdoor_r", "prop_ladel", "prop_laptop_02_closed", "rop_laptop_jimmy", "rop_laptop_lester", "prop_laptop_lester2", "prop_large_gold", "prop_large_gold_alt_a", "prop_large_gold_alt_b", "prop_large_gold_alt_c", "prop_large_gold_empty", "prop_lawnmower_01", "prop_ld_alarm_01", "4prop_ld_alarm_01_dam", "prop_ld_alarm_alert", "prop_ld_ammo_pack_01", "prop_ld_ammo_pack_02", "prop_ld_ammo_pack_03", "prop_ld_armour", "prop_ld_balcfnc_01a", "prop_ld_balcfnc_02a", "prop_ld_balcfnc_02c", "prop_ld_bankdoors_02", "rop_ld_barrier_01", "prop_ld_binbag_01", "prop_ld_bomb", "prop_ld_bomb_01", "prop_ld_bomb_01_open", "prop_ld_bomb_anim", "prop_ld_cable", "prop_ld_cable_tie_01", "prop_ld_can_01", "prop_ld_case_01", "prop_ld_case_01_lod", "prop_ld_case_01_s", "prop_ld_contact_card", "prop_ld_container", "prop_ld_contain_dl", "prop_ld_contain_dl2", "rop_ld_contain_dr", "prop_ld_contain_dr2", "prop_ld_crate_01", "prop_ld_crate_lid_01", "prop_ld_crocclips01", "prop_ld_crocclips02", "prop_ld_dummy_rope", "prop_ld_fags_01", "prop_ld_fags_02", "prop_ld_fan_01", "prop_ld_fan_01_old", "prop_ld_faucet", "prop_ld_ferris_wheel", "prop_ld_fireaxe", "prop_ld_flow_bottle", "prop_ld_fragwall_01a", "rop_ld_garaged_01", "prop_ld_gold_tooth", "prop_ld_greenscreen_01", "prop_ld_handbag", "prop_ld_handbag_s", "prop_ld_hat_01", "prop_ld_haybail", "prop_ld_hdd_01", "prop_ld_health_pack", "prop_ld_hook", "prop_ld_int_safe_01", "prop_ld_jail_door", "prop_ld_jeans_01", "prop_ld_jeans_02", "prop_ld_jerrycan_01", "prop_ld_keypad_01", "prop_ld_keypad_01b", "prop_ld_keypad_01b_lod", "prop_ld_lap_top", "rop_ld_monitor_01", "prop_ld_peep_slider", "prop_ld_pipe_single_01", "prop_ld_planning_pin_01", "prop_ld_planning_pin_02", "prop_ld_planning_pin_03", "prop_ld_purse_01", "prop_ld_purse_01_lod", "prop_ld_rail_01", "prop_ld_rail_02", "prop_ld_rope_t", "prop_ld_rubble_01", "prop_ld_rubble_02", "prop_ld_rubble_03", "prop_ld_rubble_04", "prop_ld_rub_binbag_01", "prop_ld_scrap", "prop_ld_shirt_01", "prop_ld_shoe_01", "prop_ld_shoe_02", "prop_ld_shovel", "prop_ld_shovel_dirt", "prop_ld_snack_01", "prop_ld_suitcase_01", "prop_ld_suitcase_02", "prop_ld_test_01", "prop_ld_toilet_01", "prop_ld_tooth", "prop_ld_tshirt_01", "prop_ld_tshirt_02", "prop_ld_vault_door", "prop_ld_wallet_01", "prop_ld_wallet_01_s", "prop_ld_wallet_02", "prop_ld_wallet_pickup", "prop_ld_w_me_machette", "prop_leaf_blower_01", "prop_lectern_01", "prop_letterbox_04", "prop_lev_crate_01", "prop_lev_des_barge_01", "prop_lev_des_barge_02", "prop_lifeblurb_01", "prop_lifeblurb_01", "prop_lifeblurb_02", "prop_lifeblurb_02b", "prop_life_ring_02", "prop_lift_overlay_01", "prop_lift_overlay_02", "prop_litter_picker", "prop_loggneon", "prop_logpile_05", "rop_logpile_06", "prop_logpile_06b", "prop_logpile_07", "prop_logpile_07b", "prop_log_01", "prop_log_02", "prop_log_03", "rop_loose_rag_01", "prop_lrggate_01c_l", "prop_lrggate_01c_r", "prop_lrggate_01_l", "prop_lrggate_01_pst", "prop_lrggate_01_r", "prop_lrggate_02_ld", "prop_lrggate_03a", "prop_lrggate_03b", "prop_lrggate_03b_ld", "prop_lrggate_04a", "prop_lrggate_05a", "prop_lrggate_06a", "prop_luggage_01a", "prop_luggage_02a", "prop_luggage_03a", "prop_luggage_04a", "prop_luggage_05a", "prop_luggage_06a", "prop_luggage_07a", "prop_luggage_08a", "prop_luggage_09a", "prop_magenta_door", "prop_makeup_trail_01", "prop_makeup_trail_02", "prop_map_door_01", "prop_mast_01", "prop_mat_box", "prop_mb_cargo_01a", "prop_mb_cargo_02a", "prop_mb_cargo_03", "prop_mb_cargo_04a", "prop_mb_cargo_04b", "prop_mb_crate_01a", "prop_mb_crate_01a_set", "prop_mb_crate_01b", "prop_mb_hesco_06", "prop_mb_ordnance_01", "prop_mb_ordnance_03", "prop_mb_sandblock_01", "prop_mb_sandblock_02", "prop_mb_sandblock_03", "prop_mb_sandblock_04", "prop_mb_sandblock_05", "prop_medal_01", "prop_medstation_02", "prop_medstation_03", "prop_medstation_04", "prop_med_bag_01", "prop_med_bag_01b", "prop_med_jet_01", "prop_megaphone_01", "prop_mem_candle_04", "prop_mem_candle_05", "prop_mem_candle_06", "prop_mem_reef_01", "prop_mem_reef_02", "prop_mem_reef_03", "prop_mem_teddy_01", "prop_mem_teddy_02", "prop_metalfoodjar_01", "prop_metal_plates01", "prop_metal_plates02", "prop_meth_bag_01", "prop_michaels_credit_tv", "prop_michael_backpack", "prop_michael_balaclava", "prop_michael_door", "prop_michael_sec_id", "prop_microphone_02", "prop_microwave_1", "prop_micro_01", "prop_micro_02", "prop_micro_cs_01", "prop_micro_cs_01_door", "prop_military_pickup_01", "prop_mil_crate_01", "prop_mil_crate_02", "prop_minigun_01", "prop_mobile_mast_1", "prop_mobile_mast_2", "prop_money_bag_01", "prop_monitor_01c", "prop_monitor_01d", "prop_monitor_02", "prop_monitor_03b", "prop_motel_door_09", "prop_mouse_01", "prop_mouse_01a", "prop_mouse_01b", "prop_mouse_02", "prop_movie_rack", "prop_mp3_dock", "prop_mp_arrow_barrier_01", "prop_mp_barrier_01", "prop_mp_barrier_01b", "prop_mp_barrier_02", "prop_mp_barrier_02b", "prop_mp_base_marker", "prop_mp_boost_01", "prop_mp_cant_place_lrg", "prop_mp_cant_place_med", "prop_mp_cant_place_sm", "rop_mp_cone_01", "prop_mp_cone_02", "prop_mp_cone_03", "rop_mp_cone_04", "prop_mp_drug_package", "prop_mp_drug_pack_blue", "rop_mp_drug_pack_red", "prop_mp_icon_shad_lrg", "prop_mp_icon_shad_med", "prop_mp_icon_shad_sm", "prop_mp_max_out_lrg", "prop_mp_max_out_med", "prop_mp_max_out_sm", "prop_mp_num_0", "prop_mp_num_1", "prop_mp_num_2", "prop_mp_num_3", "prop_mp_num_4", "prop_mp_num_5", "prop_mp_num_6", "prop_mp_num_7", "prop_mp_num_8", "prop_mp_num_9", "prop_mp_placement", "prop_mp_placement_lrg", "prop_mp_placement_maxd", "prop_mp_placement_med", "prop_mp_placement_red", "prop_mp_placement_sm", "prop_mp_ramp_01", "prop_mp_ramp_02", "prop_mp_ramp_03", "prop_mp_repair", "prop_mp_repair_01", "prop_mp_respawn_02", "prop_mp_rocket_01", "prop_mp_spike_01", "prop_mr_rasberryclean", "prop_mr_raspberry_01", "prop_muscle_bench_01", "prop_muscle_bench_02", "prop_muscle_bench_03", "prop_muscle_bench_04", "prop_muscle_bench_05", "prop_muscle_bench_06", "prop_muster_wboard_01", "prop_muster_wboard_02", "prop_m_pack_int_01", "prop_necklace_board", "prop_news_disp_02a_s", "prop_new_drug_pack_01", "prop_nigel_bag_pickup", "prop_night_safe_01", "prop_notepad_01", "prop_notepad_02", "prop_novel_01", "prop_npc_phone", "prop_npc_phone_02", "prop_office_alarm_01", "prop_office_desk_01", "prop_offroad_bale01", "prop_offroad_bale02_l1_frag_", "prop_offroad_barrel01", "prop_offroad_tyres01", "prop_off_chair_01", "prop_off_chair_03", "prop_off_chair_04", "prop_off_chair_04b", "prop_off_chair_04_s", "prop_off_chair_05", "prop_off_phone_01", "prop_oiltub_01", "prop_oiltub_02", "prop_oiltub_03", "prop_oiltub_05", "prop_oiltub_06", "prop_oil_derrick_01", "prop_oil_guage_01", "prop_oil_spool_02", "prop_oil_valve_01", "prop_oil_valve_02", "prop_oil_wellhead_01", "prop_oil_wellhead_03", "prop_oil_wellhead_04", "prop_oil_wellhead_05", "prop_oil_wellhead_06", "prop_oldplough1", "prop_old_boot", "prop_old_churn_01", "prop_old_churn_02", "prop_old_deck_chair", "prop_old_deck_chair_02", "prop_old_farm_01", "prop_old_farm_02", "prop_old_wood_chair", "prop_old_wood_chair_lod", "prop_orang_can_01", "prop_outdoor_fan_01", "prop_out_door_speaker", "prop_overalls_01", "prop_owl_totem_01", "prop_paints_can01", "prop_paints_can02", "prop_paints_can03", "prop_paints_can04", "prop_paints_can05", "prop_paints_can06", "prop_paints_can07", "prop_paint_brush01", "prop_paint_brush02", "prop_paint_brush03", "prop_paint_brush04", "prop_paint_brush05", "prop_paint_roller", "prop_paint_spray01a", "prop_paint_spray01b", "prop_paint_stepl01", "prop_paint_stepl01b", "prop_paint_stepl02", "prop_paint_tray", "prop_paint_wpaper01", "prop_pallettruck_01", "prop_palm_fan_02_a", "prop_palm_fan_02_b", "prop_palm_fan_03_a", "prop_palm_fan_03_b", "prop_palm_fan_03_c", "prop_palm_fan_03_d", "prop_palm_fan_04_a", "prop_palm_fan_04_b", "prop_palm_fan_04_c", "prop_palm_fan_04_d", "prop_palm_huge_01a", "prop_palm_huge_01b", "prop_palm_med_01a", "prop_palm_med_01b", "prop_palm_med_01c", "prop_palm_med_01d", "prop_palm_sm_01a", "prop_palm_sm_01d", "prop_palm_sm_01e", "prop_palm_sm_01f", "prop_paper_bag_01", "prop_paper_bag_small", "prop_paper_ball", "prop_paper_box_01", "prop_paper_box_02", "prop_paper_box_03", "prop_paper_box_04", "prop_paper_box_05", "prop_pap_camera_01", "prop_parachute", "prop_parapack_01", "prop_parasol_01", "prop_parasol_01_b", "prop_parasol_01_c", "prop_parasol_01_down", "prop_parasol_02", "prop_parasol_02_b", "prop_parasol_02_c", "prop_parasol_03", "prop_parasol_03_b", "prop_parasol_03_c", "prop_parasol_04e", "prop_parasol_04e_lod1", "prop_parasol_bh_48", "prop_parking_sign_06", "prop_parking_sign_07", "prop_parking_sign_1", "prop_parking_sign_2", "prop_parking_wand_01", "prop_park_ticket_01", "prop_partsbox_01", "prop_passport_01", "prop_patio_heater_01", "prop_patio_lounger1", "prop_patio_lounger1b", "prop_patio_lounger1_table", "prop_patio_lounger_2", "prop_patio_lounger_3", "prop_patriotneon", "prop_paynspray_door_l", "prop_paynspray_door_r", "prop_pc_01a", "prop_pc_02a", "prop_peanut_bowl_01", "prop_ped_pic_01", "prop_ped_pic_01_sm", "prop_ped_pic_02", "prop_ped_pic_02_sm", "prop_ped_pic_03", "prop_ped_pic_03_sm", "prop_ped_pic_04", "prop_ped_pic_04_sm", "prop_ped_pic_05", "prop_ped_pic_05_sm", "prop_ped_pic_06", "prop_ped_pic_06_sm", "prop_ped_pic_07", "prop_ped_pic_07_sm", "prop_ped_pic_08", "prop_ped_pic_08_sm", "prop_pencil_01", "prop_pharm_sign_01", "prop_phonebox_05a", "prop_phone_ing", "prop_phone_ing_02", "prop_phone_ing_03", "prop_phone_overlay_01", "prop_phone_overlay_02", "prop_phone_overlay_anim", "prop_phone_proto", "prop_phone_proto_back", "prop_phone_proto_battery", "prop_picnictable_02", "prop_piercing_gun", "prop_pier_kiosk_01", "prop_pier_kiosk_02", "prop_pier_kiosk_03", "prop_pile_dirt_01", "prop_pile_dirt_02", "prop_pile_dirt_03", "prop_pile_dirt_04", "prop_pile_dirt_06", "prop_pile_dirt_07", "prop_ping_pong", "prop_pipes_01a", "prop_pipes_01b", "prop_pipes_03b", "prop_pipes_04a", "prop_pipes_05a", "prop_pipes_conc_01", "prop_pipes_conc_02", "prop_pipe_single_01", "prop_pistol_holster", "prop_pitcher_01_cs", "prop_pizza_box_01", "prop_pizza_box_02", "prop_pizza_oven_01", "prop_planer_01", "prop_plant_01a", "prop_plant_01b", "prop_plant_base_01", "prop_plant_base_02", "prop_plant_base_03", "prop_plant_cane_01a", "prop_plant_cane_01b", "prop_plant_cane_02a", "prop_plant_cane_02b", "prop_plant_clover_01", "prop_plant_clover_02", "prop_plant_fern_01a", "prop_plant_fern_01b", "prop_plant_fern_02a", "prop_plant_fern_02b", "prop_plant_fern_02c", "prop_plant_flower_01", "prop_plant_flower_02", "prop_plant_flower_03", "prop_plant_flower_04", "prop_plant_group_01", "prop_plant_group_02", "prop_plant_group_03", "prop_plant_group_04", "prop_plant_group_05", "prop_plant_group_05b", "prop_plant_group_05c", "prop_plant_group_05d", "prop_plant_group_06a", "prop_plant_group_06b", "prop_plant_group_06c", "prop_plant_int_02a", "rop_plant_int_02b", "prop_plant_int_05a", "prop_plant_int_05b", "prop_plant_int_06a", "prop_plant_int_06b", "prop_plant_int_06c", "prop_plant_paradise", "prop_plant_paradise_b", "prop_plastic_cup_02", "prop_plas_barier_01a", "prop_plate_04", "prop_plate_stand_01", "prop_plate_warmer", "prop_player_gasmask", "prop_player_phone_01", "prop_player_phone_02", "prop_pliers_01", "prop_plywoodpile_01a", "prop_plywoodpile_01b", "prop_podium_mic", "prop_police_door_l", "prop_police_door_l_dam", "prop_police_door_r", "prop_police_door_r_dam", "prop_police_door_surround", "prop_police_phone", "prop_police_radio_handset", "prop_police_radio_main", "prop_poly_bag_01", "prop_poly_bag_money", "prop_poolball_1", "prop_poolball_10", "prop_poolball_11", "prop_poolball_12", "prop_poolball_13", "prop_poolball_14", "prop_poolball_15", "prop_poolball_2", "prop_poolball_3", "rop_poolball_4", "rop_poolball_5", "prop_poolball_6", "prop_poolball_7", "prop_poolball_8", "prop_poolball_9", "prop_poolball_cue", "prop_poolskimmer", "prop_pooltable_02", "prop_pooltable_3b", "prop_pool_ball_01", "prop_pool_cue", "prop_pool_rack_01", "prop_pool_rack_02", "prop_pool_tri", "prop_porn_mag_01", "prop_porn_mag_02", "prop_porn_mag_03", "prop_porn_mag_04", "prop_portable_hifi_01", "prop_portacabin01", "prop_portasteps_01", "prop_portasteps_02", "prop_postcard_rack", "prop_poster_tube_01", "prop_poster_tube_02", "prop_postit_drive", "prop_postit_gun", "prop_postit_it", "prop_postit_lock", "prop_potatodigger", "prop_pot_01", "prop_pot_02", "prop_pot_03", "prop_pot_04", "prop_pot_05", "prop_pot_06", "prop_pot_plant_02a", "prop_pot_plant_02b", "prop_pot_plant_02c", "prop_pot_plant_02d", "prop_pot_plant_03a", "prop_pot_plant_04a", "prop_pot_plant_05d_l1", "prop_pot_plant_bh1", "prop_pot_rack", "prop_power_cell", "prop_power_cord_01", "prop_premier_fence_01", "prop_premier_fence_02", "prop_printer_01", "prop_printer_02", "prop_pris_bars_01", "prop_pris_bench_01", "prop_pris_door_01_l", "prop_pris_door_01_r", "prop_pris_door_02", "prop_pris_door_03", "prop_prlg_gravestone_05a_l1", "prop_prlg_gravestone_06a", "prop_projector_overlay", "prop_prologue_phone", "prop_prop_tree_01", "prop_prop_tree_02", "prop_protest_sign_01", "prop_protest_table_01", "prop_prototype_minibomb", "prop_proxy_chateau_table", "prop_punch_bag_l", "prop_pylon_01", "prop_pylon_02", "prop_pylon_03", "prop_pylon_04", "prop_p_jack_03_col", "prop_p_spider_01a", "prop_p_spider_01c", "prop_p_spider_01d", "prop_ql_revolving_door", "prop_quad_grid_line", "prop_radiomast01", "prop_radiomast02", "prop_rad_waste_barrel_01", "prop_ragganeon", "prop_rag_01", "prop_railsleepers01", "prop_railsleepers02", "prop_railstack01", "prop_railstack02", "prop_railstack03", "prop_railstack04", "prop_railstack05", "prop_rail_boxcar", "prop_rail_boxcar2", "prop_rail_boxcar3", "prop_rail_boxcar4", "prop_rail_boxcar5", "prop_rail_boxcar5_d", "prop_rail_buffer_01", "prop_rail_buffer_02", "prop_rail_controller", "prop_rail_crane_01", "prop_rail_points01", "prop_rail_points02", "prop_rail_sigbox01", "prop_rail_sigbox02", "prop_rail_signals02", "rop_rail_tankcar", "prop_rail_tankcar2", "prop_rail_tankcar3", "prop_rail_wellcar", "prop_rail_wellcar2", "prop_range_target_01", "prop_range_target_02", "prop_range_target_03", "prop_rebar_pile01", "prop_recyclebin_02a", "prop_recyclebin_02b", "prop_recyclebin_02_c", "prop_recyclebin_02_d", "prop_recyclebin_03_a", "prop_recyclebin_04_a", "prop_recyclebin_04_b", "prop_recyclebin_05_a", "prop_ret_door", "prop_ret_door_02", "prop_ret_door_03", "prop_ret_door_04", "prop_rf_conc_pillar", "prop_riding_crop_01", "prop_riot_shield", "prop_rio_del_01", "prop_roadcone01a", "prop_roadcone01b", "prop_roadcone01c", "prop_roadcone02a", "prop_roadcone02b", "prop_roadcone02c", "prop_roadheader_01", "prop_rock_1_a", "prop_rock_1_b", "prop_rock_1_c", "prop_rock_1_d", "prop_rock_1_e", "prop_rock_1_f", "prop_rock_1_g", "prop_rock_1_h", "prop_rock_1_i", "prop_rock_2_a", "prop_rock_2_c", "prop_rock_2_d", "prop_rock_2_f", "prop_rock_2_g", "prop_rock_3_a", "prop_rock_3_b", "prop_rock_3_c", "prop_rock_3_d", "prop_rock_3_e", "prop_rock_3_f", "rop_rock_3_g", "prop_rock_3_h", "prop_rock_3_i", "prop_rock_3_j", "prop_rock_4_c", "prop_rock_4_d", "prop_rock_chair_01", "prop_rolled_sock_01", "prop_rolled_sock_02", "prop_rolled_yoga_mat", "prop_roller_car_01", "prop_roller_car_02", "prop_ron_door_01", "prop_roofpipe_01", "prop_roofpipe_02", "prop_roofpipe_03", "prop_roofpipe_04", "prop_roofpipe_05", "prop_roofpipe_06", "prop_roofvent_011a", "prop_roofvent_01a", "prop_roofvent_01b", "prop_roofvent_02a", "prop_roofvent_02b", "prop_roofvent_03a", "prop_roofvent_04a", "prop_roofvent_05a", "prop_roofvent_05b", "prop_roofvent_07a", "rop_roofvent_08a", "rop_roofvent_09a", "prop_roofvent_10a", "prop_roofvent_10b", "prop_roofvent_11b", "prop_roofvent_11c", "prop_roofvent_12a", "prop_roofvent_13a", "prop_roofvent_15a", "prop_roofvent_16a", "prop_rope_family_3", "prop_rope_hook_01", "prop_roundbailer01", "prop_roundbailer02", "prop_rub_bike_01", "prop_rub_bike_02", "prop_rub_bike_03", "prop_rub_binbag_sd_01", "prop_rub_binbag_sd_02", "prop_rub_busdoor_01", "prop_rub_busdoor_02", "prop_rub_buswreck_01", "prop_rub_buswreck_03", "prop_rub_buswreck_06", "prop_rub_cabinet", "prop_rub_cabinet01", "prop_rub_cabinet02", "prop_rub_cabinet03", "prop_rub_cage01a", "prop_rub_carpart_02", "prop_rub_carpart_03", "prop_rub_carpart_04", "prop_rub_chassis_01", "prop_rub_chassis_02", "prop_rub_chassis_03", "prop_rub_cont_01a", "prop_rub_cont_01b", "prop_rub_cont_01c", "prop_rub_flotsam_01", "prop_rub_flotsam_02", "prop_rub_flotsam_03", "prop_rub_frklft", "prop_rub_litter_01", "prop_rub_litter_02", "prop_rub_litter_03", "rop_rub_litter_03b", "prop_rub_litter_03c", "prop_rub_litter_04", "prop_rub_litter_04b", "prop_rub_litter_05", "prop_rub_litter_06", "prop_rub_litter_07", "prop_rub_litter_09", "prop_rub_litter_8", "prop_rub_matress_01", "prop_rub_matress_02", "prop_rub_matress_03", "prop_rub_matress_04", "prop_rub_monitor", "prop_rub_pile_01", "prop_rub_pile_02", "prop_rub_planks_01", "prop_rub_planks_02", "prop_rub_planks_03", "prop_rub_planks_04", "prop_rub_railwreck_1", "prop_rub_railwreck_2", "prop_rub_railwreck_3", "prop_rub_scrap_02", "prop_rub_scrap_03", "prop_rub_scrap_04", "prop_rub_scrap_05", "prop_rub_scrap_06", "prop_rub_scrap_07", "prop_rub_stool", "prop_rub_sunktyre", "prop_rub_t34", "prop_rub_trainers_01", "prop_rub_trolley01a", "prop_rub_trolley02a", "prop_rub_trolley03a", "prop_rub_trukwreck_1", "prop_rub_trukwreck_2", "prop_rub_tyre_01", "prop_rub_tyre_02", "prop_rub_tyre_03", "prop_rub_tyre_dam1", "prop_rub_tyre_dam2", "prop_rub_tyre_dam3", "prop_rub_washer_01", "prop_rub_wheel_01", "prop_rub_wheel_02", "prop_rub_wreckage_3", "prop_rub_wreckage_4", "prop_rub_wreckage_5", "prop_rub_wreckage_6", "prop_rub_wreckage_7", "prop_rub_wreckage_8", "prop_rub_wreckage_9", "prop_rural_windmill_l1", "prop_rural_windmill_l2", "prop_rus_olive", "prop_rus_olive_wint", "prop_sacktruck_01", "prop_sacktruck_02a", "prop_safety_glasses", "prop_sam_01", "prop_sandwich_01", "prop_satdish_2_a", "prop_satdish_2_f", "prop_satdish_2_g", "prop_satdish_3_b", "prop_satdish_3_c", "prop_satdish_3_d", "prop_satdish_l_01", "prop_satdish_s_03", "prop_satdish_s_05a", "prop_satdish_s_05b", "prop_sc1_06_gate_l", "prop_sc1_06_gate_r", "prop_sc1_12_door", "prop_sc1_21_g_door_01", "prop_scaffold_pole", "prop_scafold_01a", "prop_scafold_01c", "prop_scafold_01f", "prop_scafold_02a", "prop_scafold_02c", "prop_scafold_03a", "prop_scafold_03b", "prop_scafold_03c", "prop_scafold_03f", "prop_scafold_04a", "prop_scafold_05a", "prop_scafold_06a", "prop_scafold_06b", "prop_scafold_06c", "prop_scafold_07a", "prop_scafold_08a", "prop_scafold_09a", "prop_scafold_frame1a", "prop_scafold_frame1b", "prop_scafold_frame1c", "prop_scafold_frame1f", "prop_scafold_frame2a", "prop_scafold_frame2b", "prop_scafold_frame2c", "prop_scafold_frame3a", "prop_scafold_frame3c", "prop_scafold_rail_01", "prop_scafold_rail_02", "prop_scafold_rail_03", "prop_scafold_xbrace", "prop_scalpel", "prop_scn_police_torch", "prop_scourer_01", "prop_scrap_2_crate", "prop_scrap_win_01", "prop_scrim_01", "prop_scythemower", "prop_section_garage_01", "prop_securityvan_lightrig", "prop_security_case_01", "prop_security_case_02", "prop_sec_gate_01b", "prop_sec_gate_01c", "prop_sec_gate_01d", "prop_set_generator_01", "prop_sewing_fabric", "prop_sewing_machine", "prop_sglasses_stand_01", "prop_sglasses_stand_02", "prop_sglasses_stand_02b", "prop_sglasses_stand_03", "prop_sglasss_1b_lod", "prop_sglasss_1_lod", "prop_shamal_crash", "prop_shelves_01", "prop_shelves_02", "prop_shelves_03", "prop_shopping_bags01", "prop_shopping_bags02", "prop_shop_front_door_l", "prop_shop_front_door_r", "prop_shots_glass_cs", "prop_shower_01", "prop_shower_rack_01", "prop_shower_towel", "prop_showroom_door_l", "prop_showroom_door_r", "prop_showroom_glass_1b", "prop_shredder_01", "prop_shrub_rake", "prop_shuttering01", "prop_shuttering02", "prop_shuttering03", "prop_shuttering04", "prop_sh_beer_pissh_01", "prop_sh_bong_01", "prop_sh_cigar_01", "prop_sh_joint_01", "prop_sh_mr_rasp_01", "prop_sh_shot_glass", "prop_sh_tall_glass", "prop_sh_tt_fridgedoor", "prop_sh_wine_glass", "prop_side_lights", "prop_side_spreader", "prop_sign_airp_01a", "prop_sign_airp_02a", "prop_sign_airp_02b", "prop_sign_big_01", "prop_sign_mallet", "prop_sign_road_04g_l1", "prop_single_grid_line", "prop_single_rose", "prop_sink_01", "prop_sink_02", "prop_sink_03", "prop_sink_04", "prop_sink_05", "prop_sink_06", "prop_skate_flatramp", "prop_skate_funbox", "prop_skate_halfpipe", "prop_skate_kickers", "prop_skate_quartpipe", "prop_skate_rail", "prop_skate_spiner", "prop_skid_chair_01", "prop_skid_chair_02", "prop_skid_chair_03", "prop_skid_sleepbag_1", "prop_skid_tent_01", "prop_skid_tent_01b", "prop_skid_tent_03", "prop_skip_01a", "prop_skip_02a", "prop_skip_03", "prop_skip_04", "prop_skip_05a", "prop_skip_05b", "prop_skip_06a", "prop_skip_08a", "prop_skip_08b", "prop_skip_10a", "prop_skip_rope_01", "prop_skunk_bush_01", "prop_skylight_01", "prop_skylight_02", "prop_skylight_03", "prop_skylight_04", "prop_skylight_05", "prop_skylight_06a", "prop_skylight_06b", "prop_skylight_06c", "prop_sky_cover_01", "prop_slacks_01", "prop_slacks_02", "prop_sluicegate", "prop_sluicegatel", "prop_sluicegater", "prop_slush_dispenser", "prop_sm1_11_doorl", "prop_sm1_11_doorr", "prop_sm1_11_garaged=", "prop_smg_holster_01", "prop_sm_10_mp_door", "prop_sm_14_mp_gar", "prop_sm_19_clock", "prop_sm_27_door", "prop_sm_27_gate", "prop_sm_27_gate_02", "prop_sm_27_gate_03", "prop_sm_27_gate_04", "prop_sm_locker_door", "prop_snow_bailer_01", "prop_snow_barrel_pile_03", "prop_snow_bench_01", "prop_snow_bin_01", "prop_snow_bin_02", "prop_snow_bush_01_a", "prop_snow_bush_02_a", "prop_snow_bush_02_b", "prop_snow_bush_03", "prop_snow_bush_04", "prop_snow_bush_04b", "prop_snow_cam_03", "prop_snow_cam_03a", "prop_snow_diggerbkt_01", "prop_snow_dumpster_01", "prop_snow_elecbox_16", "prop_snow_facgate_01", "prop_snow_field_01", "prop_snow_field_02", "prop_snow_field_03", "prop_snow_field_04", "prop_snow_flower_01", "prop_snow_flower_02", "prop_snow_fnclink_03crnr2", "prop_snow_fnclink_03h", "prop_snow_fnclink_03i", "prop_snow_fncwood_14a", "prop_snow_fncwood_14b", "prop_snow_fncwood_14c", "prop_snow_fncwood_14d", "prop_snow_fncwood_14e", "prop_snow_fnc_01", "prop_snow_gate_farm_03", "prop_snow_grain_01", "prop_snow_grass_01", "prop_snow_light_01", "prop_snow_oldlight_01b", "prop_snow_rail_signals02", "prop_snow_rub_trukwreck_2", "prop_snow_side_spreader_01", "prop_snow_streetlight01", "prop_snow_streetlight_01_frag_", "prop_snow_sub_frame_01a", "prop_snow_sub_frame_04b", "prop_snow_telegraph_01a", "prop_snow_telegraph_02a", "prop_snow_telegraph_03", "prop_snow_traffic_rail_1a", "prop_snow_traffic_rail_1b", "prop_snow_trailer01", "prop_snow_tree_03_e", "prop_snow_tree_03_h", "prop_snow_tree_03_i", "prop_snow_tree_04_d", "prop_snow_tree_04_f", "prop_snow_truktrailer_01a", "prop_snow_tyre_01", "prop_snow_t_ml_01", "prop_snow_t_ml_02", "prop_snow_t_ml_03", "prop_snow_wall_light_15a", "prop_snow_watertower01", "prop_snow_watertower01_l2", "prop_snow_watertower03", "prop_snow_woodpile_04a", "prop_soap_disp_01", "prop_soap_disp_02", "prop_solarpanel_01", "prop_solarpanel_02", "prop_solarpanel_03", "prop_sol_chair", "prop_space_pistol", "prop_space_rifle", "prop_speaker_01", "prop_speaker_02", "prop_speaker_03", "prop_speaker_05", "prop_speaker_06", "prop_speaker_07", "prop_speaker_08", "prop_speedball_01", "prop_sponge_01", "prop_sports_clock_01", "prop_spot_01", "prop_spot_clamp", "prop_spot_clamp_02", "prop_sprayer", "prop_spraygun_01", "prop_spray_backpack_01", "prop_spray_jackframe", "prop_spray_jackleg", "prop_sprink_crop_01", "prop_sprink_golf_01", "prop_sprink_park_01", "prop_spycam", "prop_squeegee", "prop_ss1_05_mp_door", "prop_ss1_08_mp_door_l", "prop_ss1_08_mp_door_r", "prop_ss1_10_door_l", "prop_ss1_10_door_r", "prop_ss1_14_garage_door", "prop_ss1_mpint_door_l", "prop_ss1_mpint_door_r", "prop_ss1_mpint_garage", "prop_ss1_mpint_garage_cl", "prop_stag_do_rope", "prop_start_finish_line_01", "prop_start_grid_01", "prop_staticmixer_01", "prop_stat_pack_0", "prop_steam_basket_01", "prop_steam_basket_02", "prop_steps_big_01", "prop_stickbfly", "prop_stickhbird", "prop_still", "prop_stockade_wheel", "prop_stockade_wheel_flat", "prop_stool_01", "prop_storagetank_01", "prop_storagetank_02", "prop_storagetank_03", "prop_storagetank_03a", "prop_storagetank_03b", "prop_storagetank_04", "prop_storagetank_05", "prop_storagetank_06", "prop_storagetank_07a", "prop_stripmenu", "prop_strip_door_01", "prop_strip_pole_01", "prop_studio_light_02", "prop_studio_light_03", "prop_sub_chunk_01", "prop_sub_cover_01", "prop_sub_crane_hook", "prop_sub_frame_01a", "prop_sub_frame_01b", "prop_sub_frame_01c", "prop_sub_frame_02a", "prop_sub_frame_03a", "prop_sub_frame_04a", "prop_sub_frame_04b", "prop_sub_gantry", "prop_sub_release", "prop_sub_trans_01a", "prop_sub_trans_02a", "prop_sub_trans_03a", "prop_sub_trans_04a", "prop_sub_trans_05b", "prop_sub_trans_06b", "prop_suitcase_01", "prop_suitcase_01b", "prop_suitcase_01c", "prop_suitcase_01d", "prop_suitcase_02", "prop_suitcase_03", "prop_suitcase_03b", "prop_surf_board_ldn_01", "prop_surf_board_ldn_02", "prop_surf_board_ldn_03", "prop_surf_board_ldn_04", "prop_syringe_01", "prop_s_pine_dead_01", "prop_tablesaw_01", "prop_tablesmall_01", "prop_table_02", "prop_table_03b_cs", "prop_table_04", "prop_table_04_chr", "prop_table_05", "prop_table_05_chr", "prop_table_06", "prop_table_06_chr", "prop_table_07", "prop_table_07_l1", "prop_table_08", "prop_table_08_chr", "prop_table_08_side", "prop_table_mic_01", "prop_table_para_comb_04", "prop_table_tennis", "prop_table_ten_bat", "prop_taco_01", "prop_taco_02", "prop_tail_gate_col", "prop_tapeplayer_01", "prop_target_arm", "prop_target_arm_b", "prop_target_arm_long", "prop_target_arm_sm", "prop_target_backboard", "prop_target_backboard_b", "prop_target_blue", "prop_target_blue_arrow", "prop_target_bull", "prop_target_bull_b", "prop_target_comp_metal", "prop_target_comp_wood", "prop_target_frame_01", "prop_target_inner1", "prop_target_inner2", "prop_target_inner2_b", "prop_target_inner3", "prop_target_inner3_b", "prop_target_inner_b", "prop_target_orange_arrow", "prop_target_oran_cross", "prop_target_ora_purp_01", "prop_target_purp_arrow", "prop_target_purp_cross", "prop_target_red", "prop_target_red_arrow", "prop_target_red_blue_01", "prop_target_red_cross", "prop_tarp_strap", "prop_taxi_meter_1", "prop_taxi_meter_2", "bink_3a_00", "bink_3a_01", "bink_3a_02", "bink_3a_03", "bink_3a_04", "bink_3a_05", "bink_3a_07", "bink_3a_08", "bink_3a_09", "bink_3a_10", "bink_3a_100", "bink_3a_11", "bink_3a_13", "bink_3a_14", "bink_3a_15", "bink_3a_16", "bink_3a_17", "bink_3a_18", "bink_3a_19", "bink_3a_20", "bink_3a_21", "bink_3a_22", "bink_3a_23", "bink_3a_24", "bink_3a_25", "bink_3a_26", "bink_3a_27", "bink_3a_28", "bink_3a_29", "bink_3a_30", "bink_3a_31", "bink_3a_32", "bink_3a_33", "bink_3a_34", "bink_3a_35", "bink_3a_36", "bink_3a_37", "bink_3a_38", "bink_3a_39", "bink_3a_40", "bink_3a_41", "bink_3a_42", "bink_3a_43", "bink_3a_44", "bink_3a_46", "bink_3a_47", "bink_3a_48", "bink_3a_49", "bink_3a_50", "bink_3a_52", "bink_3a_53", "bink_3a_54", "bink_3a_55", "bink_3a_56", "bink_3a_57", "bink_3a_58", "bink_3a_60", "bink_3a_62", "bink_3a_63", "bink_3a_64", "bink_3a_65", "bink_3a_67", "bink_3a_68", "bink_3a_69", "bink_3a_72", "bink_3a_73", "bink_3a_75", "bink_3a_77", "bink_3a_78", "bink_3a_79", "bink_3a_80", "bink_3a_81", "bink_3a_82", "bink_3a_83", "bink_3a_84", "bink_3a_85", "bink_3a_86", "bink_3a_87", "bink_3a_88", "bink_3a_89", "bink_3a_90", "bink_3a_91", "bink_3a_92", "bink_3a_93", "bink_3a_94", "bink_3a_95", "bink_3a_96", "bink_3a_97", "bink_3a_98", "bink_3a_99", "bink_3a_door", "bink_3b_00", "bink_3b_01", "bink_3b_02", "bink_3b_03", "bink_3b_04", "bink_3b_05", "bink_3b_06", "bink_3b_07", "bink_3b_08", "bink_3b_09", "bink_3b_10", "bink_3b_11", "bink_3b_12", "bink_3b_13", "bink_3b_14", "bink_3b_15", "bink_3b_16", "bink_3b_17", "bink_3b_18", "bink_3b_19", "bink_3b_20", "bink_3b_21", "bink_3b_22", "bink_3b_23", "bink_3b_24", "bink_3b_25", "bink_3b_26", "bink_3b_27", "bink_3b_28", "bink_3b_29", "bink_3b_30", "bink_3b_31", "bink_3b_32", "bink_3b_33", "bink_3b_34", "bink_3b_35", "bink_3b_36", "bink_3b_37", "bink_3b_38", "bink_3b_39", "bink_3b_40", "bink_3b_41", "bink_3b_42", "bink_3b_43", "bink_3b_44" };
int FXVar;
char *FX_Name[] = { "scr_mp_cig", "scr_fbi4", "scr_family4", "scr_rcbarry2", "scr_rcbarry1", "scr_rcbarry1", "scr_mp_house", "scr_mp_house", "scr_agencyheistb", "scr_agencyheist", "scr_agencyheist", "scr_agency3b_elec_box", "scr_fbi5a", "scr_fbi5a", "scr_finalec2", "scr_bigscore", "scr_mp_creator", "scr_fm_intro_cut_dev", "scr_minigamegolf", "scr_martin1", "core_snow", "scr_michael2", "scr_michael2", "scr_rcpaparazzo1", "scr_safehouse", "scr_safehouse", "scr_familyscenem", "scr_familyscenem", "scr_familyscenem", "scr_familyscenem", "scr_familyscenem", "scr_reburials", "scr_recartheft", "scr_recartheft", "scr_rcpaparazzo1", "scr_recrash_rescue", "scr_trevor1", "scr_trevor1", "scr_trevor1", "scr_trevor1", "scr_trevor1", "scr_oddjobtowtruck", "scr_oddjobtaxi", "scr_oddjobtaxi", "scr_solomon3", "scr_solomon3", "scr_exile3", "scr_exile2", "scr_jewelheist", "scr_jewelheist", "scr_carsteal4", "scr_carsteal4", "scr_carsteal4", "scr_carsteal3" };
char *FX_Effect[] = { "ent_anim_cig_smoke_car", "scr_fbi4_trucks_crash", "scr_fam4_trailer_sparks", "scr_clown_appears", "scr_alien_teleport", "scr_alien_disintegrate", "scr_sh_lighter_sparks", "scr_sh_lighter_flame", "scr_agency3b_elec_box", "scr_fbi_mop_drips", "scr_fbi_mop_squeeze", "scr_fbi5_ped_water_splash", "water_splash_ped_bubbles", "scr_finale2_blood_entry", "scr_bigscore_tyre_spiked", "scr_mp_plane_landing_tyre_smoke", "scr_mp_plane_landing_tyre_smoke", "scr_golf_ball_trail", "scr_sol1_sniper_impact", "cs_mich1_spade_dirt_throw", "scr_abattoir_ped_sliced", "scr_mich2_blood_stab", "scr_rcpap1_camera", "scr_sh_lighter_sparks", "scr_sh_lighter_flame", "scr_meth_pipe_smoke", "scr_reconstructionaccident", "scr_reconstruct_pipefall_debris", "scr_reconstruct_pipe_impact", "scr_sparking_generator", "scr_burial_dirt", "scr_wheel_burnout", "scr_wheel_burnout", "scr_rcpap1_camera", "scr_recrash_rescue_fire", "scr_paleto_banknotes", "cs_paleto_blowtorch"  "scr_trev1_trailer_splash", "scr_trev1_trailer_boosh", "scr_trev1_trailer_wires", "scr_trev1_crash_dust", "scr_trev1_wheelspin_dirt", "scr_ojtt_train_sparks", "scr_ojtaxi_hotbox_trail", "scr_ojtaxi_hotbox_trail", "scr_trev4_747_blood_impact", "scr_trev4_747_engine_debris", "scr_ex3_water_dinghy_wash", "scr_ex2_car_impact", "scr_jew_biKe_burnout", "scr_jewel_cab_smash", "scr_carsteal4_wheel_burnout", "scr_carsteal5_car_muzzle_flash", "scr_carsteal5_tyre_spiked", "scr_carsteal4_tyre_spiked" };


bool hasESP = false;
bool AllESP = false;
bool HeadBox = false;
int PrimRed = 255;
int PrimGreen = 255;
int PrimBlue = 255;
int SekRed = 255;
int SekGreen = 255;
int SekBlue = 255;
bool Loading_Vehicle;
bool FX_CAR = true;
bool ChromeSpawn = false;
bool spawnGodmode = true;
bool SpawntoPlayer = false;
bool TeleAutomIncar = true;
bool TeleportInFront = false;
bool ShootCar = false;
char* Vehicle_String;
int Spawned_Vehicle;
int Spawned_Vehiclet[25];
char* Vehicle_NameArray[25];
bool Driftin = false;
bool setpedonplayer;
bool attachboxing;
#pragma endregion
	opd_s ADD_OWNED_EXPLOSION_t = { 0x3BD40C, TOC };
void(*__ADD_OWNED_EXPLOSION)(int entity, Vector3 *Coords, int a, float a1, bool b, bool c, float b1) = (void(*)(int, Vector3 *Coords, int, float, bool, bool, float))&ADD_OWNED_EXPLOSION_t;
#pragma region Internals
void HookNative(int native, int dest) {
	int FuncBytes[1];
	FuncBytes[0] = *(int*)dest;
	memcpy((void*)native, FuncBytes, 4);
}
int32_t _write_process(uint64_t ea, const void * data, uint32_t size)
{
	system_call_4(905, (uint64_t)sys_process_getpid(), ea, size, (uint64_t)data);
	return_to_user_prog(int32_t);
}
int write_process(void* destination, const void* source, size_t size)
{
	system_call_4(905, (uint64_t)sys_process_getpid(), (uint64_t)destination, size, (uint64_t)source);
	return_to_user_prog(int);
}
void PatchInJump(uint64_t Address, int Destination, bool Linked)
{
	int FuncBytes[4];													// Use this data to copy over the address.
	Destination = *(int*)Destination;									// Get the actual destination address (pointer to void).
	FuncBytes[0] = 0x3D600000 + ((Destination >> 16) & 0xFFFF);			// lis %r11, dest>>16
	if (Destination & 0x8000)											// if bit 16 is 1...
		FuncBytes[0] += 1;
	FuncBytes[1] = 0x396B0000 + (Destination & 0xFFFF);					// addi %r11, %r11, dest&OxFFFF
	FuncBytes[2] = 0x7D6903A6;											// mtctr %r11
	FuncBytes[3] = 0x4E800420;											// bctr
	if (Linked)
		FuncBytes[3] += 1;												// bctrl
	write_process((void*)Address, FuncBytes, 4 * 4);
	//memcpy((void*)Address, FuncBytes, 4 * 4);
}
unsigned int FindNativeTableAddress()
{
	unsigned int  l_uiNativeTableAddress = 0;
	unsigned int l_uiStartAddress = 0x390000;
	unsigned int l_uiAddress = 0;
	for (unsigned int i = 0; i < 0x10000; i++)
	{
		if (*(unsigned int*)(l_uiStartAddress + i) == 0x3C6072BD)
			if (*(unsigned int*)(l_uiStartAddress + i + 8) == 0x6063E002)
			{
				l_uiAddress = *(unsigned int*)(l_uiStartAddress + i + 0x10);
				l_uiAddress &= 0xFFFFFF;
				l_uiAddress += (l_uiStartAddress + i + 0x10) - 1;
				printf("address: 0x%08x\n", l_uiAddress);
				break;
			}
	}
	l_uiNativeTableAddress = (*(unsigned int*)(l_uiAddress + 0x24) << 16) + (*(unsigned int*)(l_uiAddress + 0x2C) & 0xFFFF);
	l_uiNativeTableAddress -= 0x10000;
	return l_uiNativeTableAddress;
}
int NativeAddress(int Native, bool PatchInJump = true)
{
	int Hash = Native & 0xFF;
	int Table = *(int*)(FindNativeTableAddress() + (Hash * 4));
	while (Table != 0)
	{
		int NativeCount = *(int*)(Table + 0x20);
		for (int i = 0; i < NativeCount; i++)
		{
			if (*(int*)((Table + 0x24) + (i * 4)) == Native)
			{
				if (PatchInJump)
				{
					int NativeLocation = *(int*)(*(int*)((Table + 4) + (i * 4)));
					for (int i = 0; i < 50; ++i)
					{
						short CurrentPlace = *(short*)(NativeLocation + (i * 4));
						if (CurrentPlace == 0x4AE6 || CurrentPlace == 0x4AA8 || CurrentPlace == 0x4AE4 || CurrentPlace == 0x4AE5)
						{
							return (((*(int*)(NativeLocation + (i * 4))) - 0x48000001) + (NativeLocation + (i * 4))) - 0x4000000;
						}
					}
				}
				else
				{
					return *(int*)((Table + 4) + (i * 4));
				}

			}
		}
		Table = *(int*)(Table);
	}
}
void sleep(usecond_t time)  //1 second = 1000
{
	sys_timer_usleep(time * 1000);
}
void set_text_component(char *text)
{
	GRAPHICS::_0x3AC9CB55("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	GRAPHICS::_0x386CE0B8();
}
void instructionsSetup()
{
	mov = GRAPHICS::REQUEST_SCALEFORM_MOVIE("instructional_buttons");
	GRAPHICS::_0x7B48E696(mov, 255, 255, 255, 0);
	GRAPHICS::_0x215ABBE8(mov, "CLEAR_ALL");
	GRAPHICS::_0x02DBF2D7();
	GRAPHICS::_0x215ABBE8(mov, "SET_CLEAR_SPACE");
	GRAPHICS::_0x716777CB(200);
	GRAPHICS::_0x02DBF2D7();
	instructCount = 0;
}
void addInstruction(int button, char *text)
{
	if (!instructionsSetupThisFrame)
	{
		instructionsSetup();
		instructionsSetupThisFrame = true;
	}
	GRAPHICS::_0x215ABBE8(mov, "SET_DATA_SLOT");
	GRAPHICS::_0x716777CB(instructCount);
	GRAPHICS::_0x716777CB(button);
	set_text_component(text);
	GRAPHICS::_0x02DBF2D7();
	instructCount++;
}
void instructionsClose()
{
	GRAPHICS::_0x215ABBE8(mov, "DRAW_INSTRUCTIONAL_BUTTONS");
	GRAPHICS::_0x02DBF2D7();
	GRAPHICS::_0x215ABBE8(mov, "SET_BACKGROUND_COLOUR");
	GRAPHICS::_0x716777CB(0);
	GRAPHICS::_0x716777CB(0);
	GRAPHICS::_0x716777CB(0);
	GRAPHICS::_0x716777CB(80);
	GRAPHICS::_0x02DBF2D7();
}
void drawText(char * text, int font, float x, float y, float scalex, float scaley, int r, int b, int g, int a, bool center)
{
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scalex, scaley);
	UI::SET_TEXT_COLOUR(r, g, b, a);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_CENTRE(center);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	UI::SET_TEXT_OUTLINE();
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::_DRAW_TEXT(x, y);
}
void drawNotification(char* msg)
{
	if (menuXCoord == 0.845f)
	{
		UI::_0x574EE85C("STRING");
		UI::_ADD_TEXT_COMPONENT_STRING(msg);
		UI::_SET_NOTIFICATION_MESSAGE_CLAN_TAG_2("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", 1, 7, "WILDEMODZ", "Information", 1, "___~g~420", 8);
		//UI::_SET_NOTIFICATION_MESSAGE("CHAR_SOCIAL_CLUB", "CHAR_SOCIAL_CLUB", true, 4, "WILDEMODZ SPRX", "");
		UI::_DRAW_NOTIFICATION(false, true);
	}
	else
	{
		UI::_0xF42C43C7("STRING");
		UI::_ADD_TEXT_COMPONENT_STRING(msg);
		UI::_0x38F82261(3000, 1);
	}
}
void CustomPRINT(bool a, char *Text)
{
	char buf[100];
	char buf2[100];
	snprintf(buf, sizeof(buf), "%s:\n ~b~Enabled~w~!", Text);
	snprintf(buf2, sizeof(buf), "%s:\n ~r~Disabled~w~!", Text);
	drawNotification(a ? buf : buf2);
}
void PRINT(char *text, int font)
{
	UI::SET_TEXT_FONT(font);
	UI::_0x574EE85C("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::_DRAW_NOTIFICATION(false, true);
}
void sendText(int player, char *text, int font)
{
	if (player == PLAYER::PLAYER_ID())
	{
	UI::SET_TEXT_FONT(font);
	UI::_0x574EE85C("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(text);
	UI::_DRAW_NOTIFICATION(false, true);
	}
	else
	{
	int NetHandleBuffer = 0x10070200;
	NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, NetHandleBuffer, 13);
	NETWORK::NETWORK_SEND_TEXT_MESSAGE(text, NetHandleBuffer);
	}
}
/*void sendText(int player, char *text, int font)
{
	int NetHandleBuffer = 0x10070200;
	NETWORK::NETWORK_HANDLE_FROM_PLAYER(player, NetHandleBuffer, 13);
	NETWORK::NETWORK_SEND_TEXT_MESSAGE(text, NetHandleBuffer);
	PRINT(text, font);
}*/
void drawTalker(char* Text, int Index)
{
	UI::SET_TEXT_FONT(4);
	UI::SET_TEXT_SCALE(0.500, 0.500);
	UI::SET_TEXT_COLOUR(255, 255, 255, 255);
	UI::SET_TEXT_OUTLINE();
	UI::SET_TEXT_WRAP(0, 1);
	UI::SET_TEXT_CENTRE(false);
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(Text);
	UI::_DRAW_TEXT(0.070, 0.220 + (Index * 0.028));
}
void DisplayText(char *Text, int font, float x, float y, float scaleX, float scaleY, int r, int g, int b, int a, bool centered)
{
	UI::SET_TEXT_FONT(font);
	UI::SET_TEXT_SCALE(scaleX, scaleY);
	UI::SET_TEXT_COLOUR(r, g, b, a);
	UI::SET_TEXT_WRAP(0.0f, 1.0f);
	UI::SET_TEXT_CENTRE(centered);
	UI::SET_TEXT_DROPSHADOW(0, 0, 0, 0, 0);
	UI::SET_TEXT_OUTLINE();
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(Text);
	UI::_DRAW_TEXT(x, y);
}
void drawCoords(char* X, char* Y, char* Z, char* Ya, char* Pi, char* Ro)
{
	DisplayText(X, InfoFont, 0.10, 0.93, 0.590, 0.590, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, false);
	DisplayText(Y, InfoFont, 0.26, 0.92, 0.590, 0.590, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, false);
	DisplayText(Z, InfoFont, 0.41, 0.91, 0.590, 0.590, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, false);
	DisplayText(Pi, InfoFont, 0.56, 0.91, 0.590, 0.590, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, false);
	DisplayText(Ro, InfoFont, 0.69, 0.92, 0.590, 0.590, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, false);
	DisplayText(Ya, InfoFont, 0.80, 0.93, 0.590, 0.590, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, false);
}
void DRAW_NEWSBAR(char* Text, float X, float Y, int R, int G, int B, int A)
{
	UI::SET_TEXT_FONT(4);
	UI::SET_TEXT_SCALE(0.600, 0.600);
	UI::SET_TEXT_COLOUR(R, G, B, A);
	UI::SET_TEXT_OUTLINE();
	UI::SET_TEXT_WRAP(0, 1);
	UI::SET_TEXT_CENTRE(1);
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(Text);
	UI::_DRAW_TEXT(X, Y);
}
void draw_news()
{
	DRAW_NEWSBAR("| This is ~p~WILDEMODZ ~g~SPRX V1.1 ~w~Developed By ~p~WILDEMODZ ~w~and ~r~MoDz4Gaming ~w~ |", NewsbarX, 0.9300, 255, 255, 255, 255);
	DRAW_NEWSBAR("| LEFT + R1 = ~b~Open ~w~| Dpad Up/Down = ~y~Scroll ~w~| X = ~b~Select ~w~| O = ~r~Back ~w~|", NewsbarX + 0.4965, 0.9300, 255, 255, 255, 255);
	GRAPHICS::DRAW_RECT(0.5000, 0.9500, 1.0000, 0.0500, newsR, newsG, newsB, newsA);
}
void drawSpeedo(char* Text)
{
	UI::SET_TEXT_FONT(4);
	UI::SET_TEXT_SCALE(0.780, 0.780);
	UI::SET_TEXT_COLOUR(255, 255, 255, 255);
	UI::SET_TEXT_OUTLINE();
	UI::SET_TEXT_WRAP(0, 1);
	UI::SET_TEXT_CENTRE(1);
	UI::_SET_TEXT_ENTRY("STRING");
	UI::_ADD_TEXT_COMPONENT_STRING(Text);
	UI::_DRAW_TEXT(0.140 + 0.138f, 0.930 - 0.055f);
}
void drawInfos(char* A, char* B, char* C)
{
	DisplayText(A, InfoFont, 0.22, 0.77, 0.45, 0.45, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, false);
	DisplayText(B, InfoFont, 0.22, 0.82, 0.45, 0.45, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, false);
	DisplayText(C, InfoFont, 0.22, 0.882, 0.45, 0.45, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, false);
}
/*void DrawInfos(char* A)
{               // L/R     UP          size
	drawText(A, 4, 0.24, 0.760, 0.190, 0.590, 255, 255, 255, 255, false);
}*/


char* str;
char* get_player_name(int id)
{
	char* Name = PLAYER::GET_PLAYER_NAME(id);
	if (cstrcmp(Name, "**Invalid**"))
		return "-";
	else
		return Name;
	return str;
}
int GetNumPlayers()
{
	int Amount = 0;
	for(int i = 0; i < 18; i++)
	{
		if (!(strcmp(PLAYER::GET_PLAYER_NAME(i), "-")))
			Amount++;
	}
	return Amount;
}
int GetFreeSpots()
{
	int amount = GetNumPlayers();
	return (18 - amount);
}
int GetHost()
{
	return NETWORK::NETWORK_GET_HOST_OF_SCRIPT("freemode", -1, 0);
}
char* GetHostName()
{
	return PLAYER::GET_PLAYER_NAME(GetHost());
}
void playSound(char* sound)
{
	if (menuSounds)
		AUDIO::PLAY_SOUND_FRONTEND(-1, sound, "HUD_FRONTEND_DEFAULT_SOUNDSET");
}
bool isNumericChar(char x)
{
	return (x >= '0' && x <= '9') ? true : false;
}
int StoI(char *str)
{
	if (*str == NULL)
		return 0;

	int res = 0,
		sign = 1,
		i = 0;

	if (str[0] == '-')
	{
		sign = -1;
		i++;
	}
	for (; str[i] != '\0'; ++i)
	{
		if (isNumericChar(str[i]) == false)
			return 0;
		res = res * 10 + str[i] - '0';
	}
	return sign*res;
}
char *ItoS(int num)
{
	char buf[30];
	snprintf(buf, sizeof(buf), "%i", num);
	return buf;
}
char* FtoS(float input)
{
	char returnvalue[64];
	int wholenumber = (int)input;
	input -= wholenumber;
	input *= 100;
	sprintf(returnvalue, "%d.%d", wholenumber, (int)input);
	return returnvalue;
}
void startKeyboard(int action, char *defaultText, int maxLength)
{
	GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "FMMC_KEY_TIP8", "", defaultText, "", "", "", maxLength);
	keyboardAction = action;
	keyboardActive = true;
}
void startKeyLoop(int action)
{
	LoopCase = action;
	Loopl = true;
}
void changeSubmenu(int newSubmenu)
{
	lastSubmenu[submenuLevel] = submenu;
	lastOption[submenuLevel] = currentOption;
	currentOption = 1;
	submenu = newSubmenu;
	submenuLevel++;
}
void SetupTimer(int tickTime)
{
	if (newTimerTick) {
		maxTimerCount = GAMEPLAY::GET_GAME_TIMER() + tickTime;
		newTimerTick = false;
	}
}
bool IsTimerReady()
{
	return GAMEPLAY::GET_GAME_TIMER() > maxTimerCount;
}
void ResetTimer()
{
	newTimerTick = true;
}
void SetupTimer2(int tickTime)
{
	if (newTimerTick2) {
		maxTimerCount2 = GAMEPLAY::GET_GAME_TIMER() + tickTime;
		newTimerTick2 = false;
	}
}
bool IsTimerReady2()
{
	return GAMEPLAY::GET_GAME_TIMER() > maxTimerCount2;
}
void ResetTimer2()
{
	newTimerTick2 = true;
}
void addTitle(char *title)
{
	drawText(title, bannerTextFont, menuXCoord, 0.1f, 0.75f, 0.75f, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, true);
	GRAPHICS::DRAW_RECT(menuXCoord, 0.1175f, 0.19f, 0.083f, bannerRectRed, bannerRectGreen, bannerRectBlue, bannerRectOpacity);
}
//void Signature(char *title)
//{
	//drawText(title, 1, menuXCoord, 0.13f, 0.75f, 0.35f, bannerTextRed1, bannerTextGreen1, bannerTextBlue1, bannerTextOpacity, true);
//}
#pragma region Option Helpers
void addOption(char *option, char *info = NULL)
{
	optionCount++;
	if (currentOption == optionCount)
		infoText = info;
	if (currentOption <= maxOptions && optionCount <= maxOptions)
		drawText(option, optionsFont, textXCoord, (optionCount * 0.035f + 0.125f), 0.4f, 0.4f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, false);
	else if ((optionCount > (currentOption - maxOptions)) && optionCount <= currentOption)
		drawText(option, optionsFont, textXCoord, ((optionCount - (currentOption - maxOptions)) * 0.035f + 0.125f), 0.4f, 0.4f, optionsRed, optionsGreen, optionsBlue, optionsOpacity, false);
}

void addSubmenuOption(char *option, int newSubmenu, char *info = NULL)
{
	addOption(option, info);
	if (currentOption == optionCount)
	{
		xInstruction = true;
		if (optionPress)
			changeSubmenu(newSubmenu);
	}
}
void addBoolOption(char *option, bool b00l, char *info = NULL)
{
	char buf[30];
	if (b00l)
	{
		snprintf(buf, sizeof(buf), "%s: ~b~On", option);
		addOption(buf, info);
	}
	else
	{
		snprintf(buf, sizeof(buf), "%s: Off", option);
		addOption(buf, info);
	}
}
void addBoolOption01(char *option, bool b00l, char *info = NULL)
{
	char buf[30];
	if (b00l)
	{
		snprintf(buf, sizeof(buf), "~w~Signal Flashing ~b~Left", option);
		addOption(buf, info);
	}
	else
	{
		snprintf(buf, sizeof(buf), "~w~Left Turn Signal", option);
		addOption(buf, info);
	}
}


void addBoolOption02(char *option, bool b00l, char *info = NULL)
{
	char buf[30];
	if (b00l)
	{
		snprintf(buf, sizeof(buf), "~w~Signal Flashing ~b~Right", option);
		addOption(buf, info);
	}
	else
	{
		snprintf(buf, sizeof(buf), "~w~Right Turn Signal", option);
		addOption(buf, info);
	}
}
void addBoolOption2(char *option, bool b00l, char *info = NULL)
{
	char buf[30];
	if (b00l)
	{
		snprintf(buf, sizeof(buf), "%s", option);
		addOption(buf, info);
	}
	else
	{
		snprintf(buf, sizeof(buf), "%s", option);
		addOption(buf, info);
	}
}
void spawnCarOption(char *Option, char *Vehicle)
{
	addOption(Option);
	if (currentOption == optionCount)
	{
		xInstruction = true;
		if (optionPress)
		{
			Vehicle_String = Vehicle;
			Loading_Vehicle = true;
		}
	}
}
void addVehOption(char *option,char *model, char *notification)
{
	addOption(option);
	if (currentOption == optionCount && optionPress)
	{
		//CREATE_VEHL(model);
		hash_veh = GAMEPLAY::GET_HASH_KEY(model); 
		SpawnVehicle = true;
		drawNotification(notification);
	}
}
char *Modchar;
bool doAttachCustom = false;
void AttachObject(char* object, int IndexBone)
{
	BIndex = IndexBone;
	Modchar = object;
	doAttachCustom = true;
}
void addAttachOption(char *option)
{
	//addCenterOption(option);
	if (currentOption == optionCount)
	{
		xInstruction = true;
		if (optionPress){
			BIndex = BONES[BoneVar];
			Modchar = option;
			doAttachCustom = true;
			char buf[50];
			snprintf(buf, sizeof(buf), "Attached:\n ~b~%s", option);
			PRINT(buf, 2000);
		}
	}
}
	


void addNeonsOption(char *option, int R, int G, int B)
{
	addOption(option);
	if (currentOption == optionCount && optionPress)
	{
		NeonR = R;
		NeonG = G;
		NeonB = B;
	}
}
void WechselBoolFunction(char *optionOFF, char *OptionOn, bool b00l, float *var, float min, float max,  float Movement = 0.010)
{
	char buf[50];

	if (b00l)
	{
		snprintf(buf, sizeof(buf), "%s: < %s >", OptionOn, FtoS(*var));
		addOption(buf);
		if (currentOption == optionCount)
		{
			lrInstruction = true;
			if (rightPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + Movement;
			}
			else if (leftPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - Movement;
			}
		}
	}
	else
	{
		snprintf(buf, sizeof(buf), "%s: Off", optionOFF);
		addOption(buf);
	}
}
template<typename TYPE>
void addCustomBoolOption(char *option, TYPE value, TYPE match, char *info = NULL)
{
	char buf[30];
	if (value == match)
	{
		snprintf(buf, sizeof(buf), "Switch Menu To Right Side", option);
		addOption(buf, info);
	}
	else
	{
		snprintf(buf, sizeof(buf), "Switch Menu To Left side", option);
		addOption(buf, info);
	}
}
void addIntOption(char *option, int *var, int min, int max, bool keyboard, char *info = NULL)
{
	char buf[30];
	snprintf(buf, sizeof(buf), "%s: < %i >", option, *var);
	addOption(buf, info);
	if (currentOption == optionCount)
	{
		lrInstruction = true;
		if (rightPress)
		{
			playSound("NAV_UP_DOWN");
			if (*var >= max)
				*var = min;
			else
				*var = *var + 1;
		}
		else if (leftPress)
		{
			playSound("NAV_UP_DOWN");
			if (*var <= min)
				*var = max;
			else
				*var = *var - 1;
		}
		if (keyboard)
		{
			squareInstruction = true;
			if (squarePress)
			{
				startKeyboard(0, "", (strlen(ItoS(max)) + 1));
				keyboardVar = var;
			}
		}
	}
}

void addFloatOption(char *option, float *var, float min, float max, bool holdPress, char *info = NULL)
{
	char buf[30];
	snprintf(buf, sizeof(buf), "%s: < %s >", option, FtoS(*var));
	addOption(buf, info);
	if (currentOption == optionCount)
	{
		lrInstruction = true;
		if (holdPress)
		{
			if (fastRightPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + 0.01f;
			}
			else if (fastLeftPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - 0.01f;
			}
		}
		else
		{
			if (rightPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + 0.01f;
			}
			else if (leftPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - 0.01f;
			}
		}
	}
}
void addCharSwap(char *option, char **From, int*var, int min, int max,  bool any = false)
{
	char buf[50];
	if (!any)
	{
		snprintf(buf, sizeof(buf), "%s: ~r~%s~w~ ", option, From[*var]);
		addOption(buf);
		if (currentOption == optionCount)
		{
			lrInstruction = true;
			if (rightPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + 1;
			}
			else if (leftPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - 1;
			}
		}
	}
	else
	{
		snprintf(buf, sizeof(buf), "%s: - ~b~%s~w~ +", option, From[*var]);
		addOption(buf);
		if (currentOption == optionCount)
		{
			lrInstruction = true;
			if (rightPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + 1;
			}
			else if (leftPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - 1;
			}
		}
	}

}

void addCharBOOLSwap(char *optionON, char *optionOFF,char **From, int*var, int min, int max, bool B)
{
	if (B)
	{
		char buf[50];
		snprintf(buf, sizeof(buf), "%s: - ~b~%s~w~ +", optionOFF, (From[*var]));
		addOption(buf);
		if (currentOption == optionCount)
		{
			lrInstruction = true;
			if (rightPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var >= max)
					*var = min;
				else
					*var = *var + 1;
			}
			else if (leftPress)
			{
				playSound("NAV_UP_DOWN");
				if (*var <= min)
					*var = max;
				else
					*var = *var - 1;
			}
		}
	}
	else
	{
		char buf[30];
		snprintf(buf, sizeof(buf), "%s: Off", optionON);
		addOption(buf);

	}

}


void addKeyboardOption(char *option, int action, char *defaultText, int maxLength, char *info = NULL)
{
	addOption(option, info);
	if (currentOption == optionCount)
	{
		xInstruction = true;
		if (optionPress)
			startKeyboard(action, defaultText, maxLength);
	}
}
#pragma endregion
int getOption()
{
	xInstruction = true;
	if (optionPress)
		return currentOption;
	else return 0;
}
void monitorButtons()
{
	SetupTimer(20);
	if (submenu == Closed)
	{
		if (IsTimerReady())
		{
			if (CONTROLS::IS_CONTROL_PRESSED(0, Button_R1) && CONTROLS::IS_CONTROL_PRESSED(0, Dpad_Left))
			{
				submenu = Main_Menu;
				submenuLevel = 0;
				currentOption = 1;
				playSound("YES");
			}
			ResetTimer();
		}
	}
	else {
		if (IsTimerReady())
		{
			if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_B))
			{
				if (submenu == Main_Menu)
				{
					submenu = Closed;
				}
				else {
					submenu = lastSubmenu[submenuLevel - 1];
					currentOption = lastOption[submenuLevel - 1];
					submenuLevel--;
				}
				playSound("Back");
			}
			else if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_A))
			{
				optionPress = true;
				playSound("SELECT");
			}
			else if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Dpad_Up))
			{
				currentOption--;
				if (currentOption < 1)
				{
					currentOption = optionCount;
				}
				playSound("NAV_UP_DOWN");
			}
			else if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Dpad_Down))
			{
				currentOption++;
				if (currentOption > optionCount)
				{
					currentOption = 1;
				}
				playSound("NAV_UP_DOWN");
			}
			else if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Dpad_Right))
			{
				rightPress = true;
			}
			else if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Dpad_Left))
			{
				leftPress = true;
			}
			else if (CONTROLS::IS_CONTROL_PRESSED(0, Dpad_Right))
			{
				fastRightPress = true;
			}
			else if (CONTROLS::IS_CONTROL_PRESSED(0, Dpad_Left))
			{
				fastLeftPress = true;
			}
			else if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_X))
			{
				squarePress = true;
			}
			ResetTimer();
		}
	}
}
void normalMenuActions()
{
	UI::HIDE_HELP_TEXT_THIS_FRAME();
	CAM::SET_CINEMATIC_BUTTON_ACTIVE(0);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(10);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(6);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(7);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(9);
	UI::HIDE_HUD_COMPONENT_THIS_FRAME(8);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 19);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 20);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 21);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 27);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 54);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 123);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 124);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 125);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 126);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 138);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 139);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 140);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 177);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 178);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 179);
	CONTROLS::DISABLE_CONTROL_ACTION(0, 207);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 166);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 167);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 177);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 178);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 193);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 194);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 195);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 202);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 203);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 204);
	CONTROLS::SET_INPUT_EXCLUSIVE(2, 205);
	if (optionCount > maxOptions)
	{
		GRAPHICS::DRAW_RECT(menuXCoord, (((maxOptions * 0.035f) / 2) + 0.159f), 0.19f, (maxOptions * 0.035f), backgroundRed, backgroundGreen, backgroundBlue, backgroundOpacity); //Background
		if (currentOption > maxOptions)
		{
			GRAPHICS::DRAW_RECT(menuXCoord, ((maxOptions * 0.035f) + 0.1415f), 0.19f, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity); //Scroller
			GRAPHICS::DRAW_RECT(menuXCoord, 0.156f, 0.19f, 0.005f, indicatorRed, indicatorGreen, indicatorBlue, indicatorOpacity); //Up Indicator
		}
		else
		{
			GRAPHICS::DRAW_RECT(menuXCoord, ((currentOption * 0.035f) + 0.1415f), 0.19f, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity); //Scroller
		}
		if (currentOption != optionCount)
		{
			GRAPHICS::DRAW_RECT(menuXCoord, ((maxOptions * 0.035f) + 0.161f), 0.19f, 0.005f, indicatorRed, indicatorGreen, indicatorBlue, indicatorOpacity); //Down Indicator
		}
	}
	else
	{
		GRAPHICS::DRAW_RECT(menuXCoord, (((optionCount * 0.035f) / 2) + 0.159f), 0.19f, (optionCount * 0.035f), backgroundRed, backgroundGreen, backgroundBlue, backgroundOpacity); //Background
		GRAPHICS::DRAW_RECT(menuXCoord, ((currentOption * 0.035f) + 0.1415f), 0.19f, 0.035f, scrollerRed, scrollerGreen, scrollerBlue, scrollerOpacity); //Scroller
	}
	if (!GAMEPLAY::IS_STRING_NULL_OR_EMPTY(infoText))
	{
		if (optionCount > maxOptions)
		{
			drawText(infoText, optionsFont, menuXCoord, ((maxOptions + 1) * 0.035f + 0.125f), 0.4f, 0.4f, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, true);
			GRAPHICS::DRAW_RECT(menuXCoord, (((maxOptions + 1) * 0.035f) + 0.1415f), 0.19f, 0.035f, bannerRectRed, bannerRectGreen, bannerRectBlue, bannerRectOpacity); //Info Box
		}
		else
		{
			drawText(infoText, optionsFont, menuXCoord, ((optionCount + 1) * 0.035f + 0.125f), 0.4f, 0.4f, bannerTextRed, bannerTextGreen, bannerTextBlue, bannerTextOpacity, true);
			GRAPHICS::DRAW_RECT(menuXCoord, (((optionCount + 1) * 0.035f) + 0.1415f), 0.19f, 0.035f, bannerRectRed, bannerRectGreen, bannerRectBlue, bannerRectOpacity); //Info Box
		}
	}
	SetupTimer2(20);
	if (instructions)
	{
		if (IsTimerReady2())
		{
			if (xInstruction)
				addInstruction(BUTTON_A, "Select");
			if (squareInstruction)
				addInstruction(BUTTON_X, "Keyboard");
			if (lrInstruction)
				addInstruction(BUTTON_DPAD_LEFT_RIGHT, "Scroll");
			addInstruction(BUTTON_DPAD_UP_DOWN, "Scroll");
			addInstruction(BUTTON_B, "Back");
			instructionsClose();
			ResetTimer2();
		}
	}
}
void resetVars()
{
	/*if (submenu != Closed)
		normalMenuActions();*/
    if (submenu != Closed && !UI::IS_PAUSE_MENU_ACTIVE())
        normalMenuActions();
	    optionPress = false;
	    rightPress = false;
	    leftPress = false;
	    fastRightPress = false;
	    fastLeftPress = false;
	    squarePress = false;
	    infoText = NULL;
	    instructionsSetupThisFrame = false;
	    squareInstruction = false;
	    xInstruction = false;
	    lrInstruction = false;
}

bool Partic = false;
char *EffectName;
char *fxName;
int FXObject;
void ParticleFX(char *fx, char *Effect, int Object)
{
	fxName = fx;
	EffectName = Effect;
	FXObject = Object;
	Partic = true;
}
bool slowmotion;
bool ToggleSlowMo = false;
void SlowMotion()
{
	if (!slowmotion)
	{
		char bytes[] = { 0x3F, 0x00, 0x00, 0x00 };
		GAMEPLAY::SET_TIME_SCALE(.4);
		slowmotion = true;
		_write_process(Addresses::RTMSlowMo, &bytes, sizeof(bytes));
	}
	else
	{
		char bytes[] = { 0x3F, 0x80, 0x00, 0x00 };
		GAMEPLAY::SET_TIME_SCALE(1);
		slowmotion = false;
		_write_process(Addresses::RTMSlowMo, &bytes, sizeof(bytes));
	}
}

void DriftMod()
{
	int VehicleHandle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());
	RequestNetworkControl(VehicleHandle);
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 1))
	{
		if (CONTROLS::IS_CONTROL_PRESSED(0, Button_L1) )
		{
			char bytes[] = { 0x3F, 0x00, 0x00, 0x00 };
			slowmotion = true;
			_write_process(Addresses::RTMSlowMo, &bytes, sizeof(bytes));
		}
		else
		{
			char bytes[] = { 0x3F, 0x80, 0x00, 0x00 };
			slowmotion = false;
			_write_process(Addresses::RTMSlowMo, &bytes, sizeof(bytes));
		}
		if (CONTROLS::IS_CONTROL_PRESSED(0, Button_X))
		{
			VEHICLE::SET_VEHICLE_REDUCE_GRIP(VehicleHandle, true);
		}
		else
		{
			VEHICLE::SET_VEHICLE_REDUCE_GRIP(VehicleHandle, false);
		}
	}
}

bool drift;
void Drif(uint vehicle)
{
	if (CONTROLS::IS_CONTROL_PRESSED(2, 44))
	{
	VEHICLE::SET_VEHICLE_REDUCE_GRIP(vehicle, 3);
	}
	if (CONTROLS::IS_CONTROL_JUST_RELEASED(2, 44))
	{
	VEHICLE::SET_VEHICLE_REDUCE_GRIP(vehicle, 100);
	}
}

bool Create_Vehicle(char* FahrzeugName, char* Name, Vector3 Pos)
{
	if (STREAMING::IS_MODEL_IN_CDIMAGE(GAMEPLAY::GET_HASH_KEY(FahrzeugName)))
	{
		if (STREAMING::IS_MODEL_VALID(GAMEPLAY::GET_HASH_KEY(FahrzeugName)))
		{
			STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY(FahrzeugName));
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			float CarYaw = ENTITY::GET_ENTITY_HEADING(Spawned_Vehiclet[Spawned_Vehicle]);
			if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY(FahrzeugName)))
			{
				if (TeleportInFront)
				{
					CarGun = false;
					ShootCar = false; 
					TeleAutomIncar = false;
					SpawntoPlayer = false;
					Vector3 CoordsFront = GET_COORDS_INFRONT(3);
					Spawned_Vehiclet[Spawned_Vehicle] = VEHICLE::CREATE_VEHICLE(GAMEPLAY::GET_HASH_KEY(FahrzeugName), CoordsFront.x, CoordsFront.y, CoordsFront.z, ENTITY::GET_ENTITY_HEADING(Spawned_Vehicle), 1, 0);
					ENTITY::SET_ENTITY_COORDS(Spawned_Vehiclet[Spawned_Vehicle], CoordsFront.x, CoordsFront.y, CoordsFront.z, 0, 0, CarYaw+90, 0);
				}
				if (TeleAutomIncar)
				{
					CarGun = false;
					ShootCar = false; 
					TeleportInFront = false;
					SpawntoPlayer = false;
					Spawned_Vehiclet[Spawned_Vehicle] = VEHICLE::CREATE_VEHICLE(GAMEPLAY::GET_HASH_KEY(FahrzeugName), coords.x, coords.y, coords.z, ENTITY::GET_ENTITY_HEADING(Spawned_Vehicle)+ 90 , 1, 0);
				}
				if (SpawntoPlayer)
				{
					CarGun = false;
					ShootCar = false; 
					TeleportInFront = false;
					TeleAutomIncar = false;
					Vector3 CoordsFronfft = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer),1);
					Spawned_Vehiclet[Spawned_Vehicle] = VEHICLE::CREATE_VEHICLE(GAMEPLAY::GET_HASH_KEY(FahrzeugName), CoordsFronfft.x+2, CoordsFronfft.y, CoordsFronfft.z, ENTITY::GET_ENTITY_HEADING(Spawned_Vehicle), 1, 0);
				}
				if (ShootCar)
				{
					TeleAutomIncar = false;
					TeleportInFront = false;
					SpawntoPlayer = false;
					Vector3 CoordsFronfft = get_coords_from_cam(5);
					Vector3 Pete = GAMEPLAY::_GET_GAMEPLAY_CAM_ROT(2);
						Spawned_Vehiclet[Spawned_Vehicle] = VEHICLE::CREATE_VEHICLE(GAMEPLAY::GET_HASH_KEY(FahrzeugName), CoordsFronfft.x, CoordsFronfft.y, CoordsFronfft.z, 0, 1, 0);
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(Spawned_Vehiclet[Spawned_Vehicle], 150);
					ENTITY::SET_ENTITY_ROTATION(Spawned_Vehiclet[Spawned_Vehicle], Pete.x, 0, Pete.z,2,1);
					//ENTITY::APPLY_FORCE_TO_ENTITY(Spawned_Vehiclet[Spawned_Vehicle], 1, 0.0f, 350.0f, 2.0f, 2.0f, 0.0f, 0.0f, 0, 1, 1, 1, 0, 1);

				}
				Vehicle_NameArray[Spawned_Vehicle] = FahrzeugName;
				if (ENTITY::DOES_ENTITY_EXIST(Spawned_Vehiclet[Spawned_Vehicle]))
				{
					VEHICLE::SET_VEHICLE_MOD_KIT(Spawned_Vehiclet[Spawned_Vehicle], 0);
					VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(Spawned_Vehiclet[Spawned_Vehicle], PrimRed, PrimGreen, PrimBlue);
					VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(Spawned_Vehiclet[Spawned_Vehicle], SekRed, SekGreen, SekBlue);
					if (TeleAutomIncar)
					{
						PED::SET_PED_INTO_VEHICLE(PLAYER::PLAYER_PED_ID(), Spawned_Vehiclet[Spawned_Vehicle], -1);
					}
					if (FX_CAR)
					{
						ParticleFX("scr_rcbarry2", "scr_clown_appears", Spawned_Vehiclet[Spawned_Vehicle]);
					}
					if (MaxUpgrades)
					{
						VEHICLE::SET_VEHICLE_FIXED(Spawned_Vehiclet[Spawned_Vehicle]);
						VEHICLE::SET_VEHICLE_DEFORMATION_FIXED(Spawned_Vehiclet[Spawned_Vehicle]);
						VEHICLE::SET_VEHICLE_DIRT_LEVEL(Spawned_Vehiclet[Spawned_Vehicle], 0);
						VEHICLE::SET_VEHICLE_MOD_KIT(Spawned_Vehiclet[Spawned_Vehicle], 0);
						VEHICLE::SET_VEHICLE_MOD(Spawned_Vehiclet[Spawned_Vehicle], 0, 1, 0);//Soiler
						VEHICLE::SET_VEHICLE_MOD(Spawned_Vehiclet[Spawned_Vehicle], 1, 1, 0);//Frontstoßstange
						VEHICLE::SET_VEHICLE_MOD(Spawned_Vehiclet[Spawned_Vehicle], 2, 1, 0);//Heckstoßstange
						VEHICLE::SET_VEHICLE_MOD(Spawned_Vehiclet[Spawned_Vehicle], 3, 1, 0);//Body
						VEHICLE::SET_VEHICLE_MOD(Spawned_Vehiclet[Spawned_Vehicle], 4, 2, 0);//Auspuff
						VEHICLE::SET_VEHICLE_MOD(Spawned_Vehiclet[Spawned_Vehicle], 5, 1, 0);//Ueberrollkaeffig
						VEHICLE::SET_VEHICLE_MOD(Spawned_Vehiclet[Spawned_Vehicle], 6, 1, 0);//Grill
						VEHICLE::SET_VEHICLE_MOD(Spawned_Vehiclet[Spawned_Vehicle], 7, 1, 0);//Motorhaube
						VEHICLE::SET_VEHICLE_MOD(Spawned_Vehiclet[Spawned_Vehicle], 8, 2, 0);//Schhuerze
						VEHICLE::SET_VEHICLE_MOD(Spawned_Vehiclet[Spawned_Vehicle], 9, 2, 0);//Rechte Schuerze
						VEHICLE::SET_VEHICLE_MOD(Spawned_Vehiclet[Spawned_Vehicle], 10, 1, 0);//Dach
						VEHICLE::SET_VEHICLE_MOD(Spawned_Vehiclet[Spawned_Vehicle], 11, 3, 0);//Motor9
						VEHICLE::SET_VEHICLE_MOD(Spawned_Vehiclet[Spawned_Vehicle], 12, 2, 0);//Bremsen
						VEHICLE::SET_VEHICLE_MOD(Spawned_Vehiclet[Spawned_Vehicle], 13, 2, 0);//Getriebe
						VEHICLE::SET_VEHICLE_MOD(Spawned_Vehiclet[Spawned_Vehicle], 14, 24, 0);//Hupe
						VEHICLE::SET_VEHICLE_MOD(Spawned_Vehiclet[Spawned_Vehicle], 15, 2, 0);//Federung
						VEHICLE::SET_VEHICLE_MOD(Spawned_Vehiclet[Spawned_Vehicle], 16, 4, 0);//Panzerung
						VEHICLE::TOGGLE_VEHICLE_MOD(Spawned_Vehiclet[Spawned_Vehicle], 18, 1);//Turbo
						VEHICLE::TOGGLE_VEHICLE_MOD(Spawned_Vehiclet[Spawned_Vehicle], 22, 1);//Xenon 
						VEHICLE::SET_VEHICLE_WHEEL_TYPE(Spawned_Vehiclet[Spawned_Vehicle], 7);//Reifen Typ
						VEHICLE::SET_VEHICLE_MOD(Spawned_Vehiclet[Spawned_Vehicle], 23, 18, 0);//Reifen
						VEHICLE::SET_VEHICLE_WINDOW_TINT(Spawned_Vehiclet[Spawned_Vehicle], 5);
						VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(Spawned_Vehiclet[Spawned_Vehicle], "WILDEMODZ");
						VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT_INDEX(Spawned_Vehiclet[Spawned_Vehicle], 3);
						VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(Spawned_Vehiclet[Spawned_Vehicle], false);
						char buf[100];
						snprintf(buf, sizeof(buf), "Upgraded: ~b~%s~w~!", FahrzeugName);
						drawNotification(buf);
					}
					if (ChromeSpawn)
						VEHICLE::SET_VEHICLE_COLOURS(Spawned_Vehiclet[Spawned_Vehicle], 120, 120);
					if (spawnGodmode)
						ENTITY::SET_ENTITY_INVINCIBLE(Spawned_Vehiclet[Spawned_Vehicle], true);
					Spawned_Vehicle++;
					char buf[100];
					snprintf(buf, sizeof(buf), "Spawned: ~b~%s~w~!", FahrzeugName);
					PRINT(buf, 2000);
					if (Spawned_Vehicle >= 25)
						Spawned_Vehicle = 0;
					return true;
				}
				else return false;
			}
			else return false;
		}
	}
}
int OBBN;
int attachtedObjects[50];
int AttobjVar;
int AttOBBB;
bool AttachCustom( char* Object)
{
	Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(ADDR::__GET_PLAYER_PED(selectedPlayer), true);
	int hash = GAMEPLAY::GET_HASH_KEY(Object);
	ADDR::__REQUEST_MODEL(hash);
	if (STREAMING::HAS_MODEL_LOADED(hash))
	{
		attachtedObjects[AttobjVar] = OBJECT::CREATE_OBJECT(hash, PlayerCoords.x, PlayerCoords.y, PlayerCoords.z, 1, 0, 1);
		if (ENTITY::DOES_ENTITY_EXIST(attachtedObjects[AttobjVar]))
		{
			AttOBBB = attachtedObjects[AttobjVar];
			Vector3 One, Two;
			Two.y = 90;
			ADDR::__ATTACH_ENTITY_TO_ENTITY(AttOBBB, ADDR::__GET_PLAYER_PED(selectedPlayer), BIndex, &One, &Two, 0, 1, 0, 0, 2, 1);
			ENTITY::SET_ENTITY_COLLISION(AttOBBB, 1, 0);
			char buf[100];
			snprintf(buf, sizeof(buf), "Attached: ~b~%s", Object);
			PRINT(buf, 100);
			AttobjVar++;

			if (AttobjVar >= 50)
				AttobjVar = 0;
			return true;
		}
		return false;
	}
	return false;
}


Vector3 get_blip_marker()
{
	static Vector3 zero;
	Vector3 coords;

	bool blipFound = false;
	// search for marker blip
	int blipIterator = UI::_GET_BLIP_INFO_ID_ITERATOR();
	for (Blip i = UI::GET_FIRST_BLIP_INFO_ID(blipIterator); UI::DOES_BLIP_EXIST(i) != 0; i = UI::GET_NEXT_BLIP_INFO_ID(blipIterator))
	{
		if (UI::GET_BLIP_INFO_ID_TYPE(i) == 4)
		{
			coords = UI::GET_BLIP_INFO_ID_COORD(i);
			blipFound = true;
			break;
		}
	}
	if (blipFound)
	{
		return coords;
	}
	return zero;
}
void drawESP(int client)
{
	Vector3 	playerPosition = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS2(PLAYER::GET_PLAYER_PED(client), 10.0, 10.0, 0.0);
	playerPosition.z += 1.5;
	GRAPHICS::DRAW_MARKER(21, playerPosition.x, playerPosition.y, playerPosition.z, 0.0f, 0.0f, 0.0f, 180.0f, 0.0f, 0.0f, 0.9f, 0.9f, 0.9f, MarkerRed, markergreen, markerblue, 255, true, false, 2, true, false, false, false);
}
void Linie(int Client)
{
	int PedID = PLAYER::GET_PLAYER_PED(Client);
	Vector3 LocalPed = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
	Vector3 TargetPed = ENTITY::GET_ENTITY_COORDS(PedID, 1);
	float start[] = { LocalPed.x, LocalPed.y, LocalPed.z };
	float end[] = { TargetPed.x, TargetPed.y, TargetPed.z };
	GRAPHICS::DRAW_LINE(start[0], start[1], start[2], end[0], end[1], end[2], MarkerRed, markergreen, markerblue, 255);
	GRAPHICS::_DRAW_RECT(start, end, MarkerRed, markergreen, markerblue, 255);
}


void RpgGun()
{
	Vector3 spawnPosition = get_coords_from_cam(5.0);
	Vector3 endPosition = get_coords_from_cam(50.0);
	if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID()))
	{
		float Start[] = { spawnPosition.x, spawnPosition.y, spawnPosition.z };
		float End[] = { endPosition.x, endPosition.y, endPosition.z };

		ADDR::__SHOOT_SINGLE_BULLET_BETWEEN_COORDS(Start, End, 250, 1, GAMEPLAY::GET_HASH_KEY(Weapshsh[WeapVar]), PLAYER::PLAYER_PED_ID(), 1, 0, 400);
	}
}
int SpawnedPed[20];
char* PedNameArray[20];
int SpawnedPed_;
bool LoadingPed;
bool Spawnped;
char *ped_moel;
bool Create_Ped1(char* ObjectName, char* Name, float Pos, float y, float z, char *meg, bool custom = false, int hash = 0)
{
	if (Spawnped)
	{
		if (custom)
		{
			if (STREAMING::IS_MODEL_IN_CDIMAGE(hash))
			{
				if (STREAMING::IS_MODEL_VALID(hash))
				{
					STREAMING::REQUEST_MODEL(hash);
					if (STREAMING::HAS_MODEL_LOADED(hash))
					{
						SpawnedPed[SpawnedPed_] = PED::CREATE_PED(21, GAMEPLAY::GET_HASH_KEY(ObjectName), Pos, y, z, 1, 1, 0);
						PedNameArray[SpawnedPed_] = Name;
						if (ENTITY::DOES_ENTITY_EXIST(SpawnedPed[SpawnedPed_]))
						{
							SpawnedPed_++;
							char buf[100];
							//__snprintf(buf, sizeof(buf), "Spawned: ~b~%s~HUD_COLOUR_WHITE~!", Name);
							//PRINT(buf, 2000);
							if (SpawnedPed_ >= 15)
								SpawnedPed_ = 0;
							drawNotification(meg);
							return true;
						}
						else return false;
					}
					else return false;
				}
			}
		}
		else
		{
			if (STREAMING::IS_MODEL_IN_CDIMAGE(GAMEPLAY::GET_HASH_KEY(ObjectName)))
			{
				if (STREAMING::IS_MODEL_VALID(GAMEPLAY::GET_HASH_KEY(ObjectName)))
				{
					STREAMING::REQUEST_MODEL(GAMEPLAY::GET_HASH_KEY(ObjectName));
					Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
					if (STREAMING::HAS_MODEL_LOADED(GAMEPLAY::GET_HASH_KEY(ObjectName)))
					{
						//	static Any CREATE_OBJECT(Hash ObjectHash, float XCoord, float YCoord, float ZCoord, int p4, BOOL p5, BOOL dynamic) { return invoke<Any>(0x2F7AA05C, ObjectHash, XCoord, YCoord, ZCoord, p4, p5, dynamic); } // 0x2F7AA05C
						SpawnedPed[SpawnedPed_] = PED::CREATE_PED(21, GAMEPLAY::GET_HASH_KEY(ObjectName), Pos, y, z, 1, 1, 0);
						PedNameArray[SpawnedPed_] = ObjectName;
						if (ENTITY::DOES_ENTITY_EXIST(SpawnedPed[SpawnedPed_]))
						{
							SpawnedPed_++;
							char buf[100];
							//__snprintf(buf, sizeof(buf), "Spawned: ~b~%s~HUD_COLOUR_WHITE~!", ObjectName);
							//PRINT(buf, 2000);
							if (SpawnedPed_ >= 15)
								SpawnedPed_ = 0;


							Spawnped = false;
							return true;
						}
						else return false;
					}
					else return false;
				}
			}
		}
	}
}

void Create_Ped(char* ObjectName, char* Name, float Pos, float y, float z, char *meg, bool custom = false, int hash = 0)
{
	drawNotification(meg);
	ped_moel = ObjectName;
	Spawnped = true;
}
	

bool PedG_;
bool SpawnedPedHasGodmode[20];
void SetGMod(int ped)
{
	if (PedG_ == false)
	{
		if (RequestNetworkControl(ped))
		{
				ENTITY::SET_ENTITY_CAN_BE_DAMAGED(ped, false);
				ENTITY::SET_ENTITY_INVINCIBLE(ped, true);
				PED::SET_PED_CAN_RAGDOLL(ped, 0);
		        PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(ped, 0);
		        PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(ped, false);
				drawNotification("God Mode On");
				PedG_ = true;
		}
	}
	else if (PedG_ == true)
	{
		ENTITY::SET_ENTITY_CAN_BE_DAMAGED(ped, true);
		ENTITY::SET_ENTITY_INVINCIBLE(ped, false);
		drawNotification("God Mode Off");
		PedG_ = false;
	}

}
bool Setped;
void SetPedonPlayer(int ped)
{
	if (ENTITY::DOES_ENTITY_EXIST(ped) && ENTITY::GET_ENTITY_HEALTH(ped) != 0)
	{
		int Ped = ped;
		Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 1);
		ENTITY::SET_ENTITY_COORDS(ped, coords.x, coords.y, coords.z, 1, 0, 0, 1);
		AI::TASK_COMBAT_PED(ped, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 0x10);
		PED::SET_PED_COMBAT_ABILITY(Ped, 100);
		PED::SET_PED_CAN_SWITCH_WEAPON(Ped, false);
		ENTITY::SET_ENTITY_CAN_BE_DAMAGED(ped, false);
		ENTITY::SET_ENTITY_INVINCIBLE(ped, true);
		PED::SET_PED_CAN_RAGDOLL(ped, 0);
		PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(ped, 0);
		PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(ped, false);
		setpedonplayer = false;
	}
}

void BodyGard(int ped)
{
	if (ENTITY::DOES_ENTITY_EXIST(ped) && ENTITY::GET_ENTITY_HEALTH(ped) != 0)
	{
		int Ped = ped;
		int my_group = PLAYER::GET_PLAYER_GROUP(PLAYER::PLAYER_ID());
		PED::SET_PED_AS_GROUP_LEADER(PLAYER::PLAYER_PED_ID(), my_group);
		PED::SET_PED_AS_GROUP_MEMBER(Ped, my_group);
		PED::SET_PED_COMBAT_ABILITY(Ped, 100);
		PED::SET_PED_CAN_SWITCH_WEAPON(Ped, false);
		drawNotification("Ped Is Now Bodyguard");
	}
	else
	{
		drawNotification("Ped Dosent Exists Anymore");
	}
}
void GiveWeaponPed(int Ped, int WeaponHash)
	{
		WEAPON::GIVE_DELAYED_WEAPON_TO_PED(Ped, WeaponHash, 9999, 1);

	}


bool AttachGuitar(int PlayerID)
{
 Vector3 PlayerCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(PlayerID), true); // been tryn to get this to work 2 lol
 int hash = GAMEPLAY::GET_HASH_KEY("prop_acc_guitar_01"); 
 STREAMING::REQUEST_MODEL(hash);
 int back = PED::GET_PED_BONE_INDEX(PLAYER::GET_PLAYER_PED(PlayerID), 23553);// SKEL_Spine0
 if (STREAMING::HAS_MODEL_LOADED(hash))
 {
  int attachobj = OBJECT::CREATE_OBJECT(hash, PlayerCoords.x,PlayerCoords.y,PlayerCoords.z, 1, 0, 1);// is correct
  if(ENTITY::DOES_ENTITY_EXIST(attachobj))
  {
   Vector3 One, Two;
   One.x = 0.5;// up & down
   One.y = -0.2;// Forward & Backward
   One.z = 0;// Left & Right
   Two.x = 0;
   Two.y = 75.0;
   Two.z = 0; 
   ENTITY::ATTACH_ENTITY_TO_ENTITY(attachobj, PLAYER::GET_PLAYER_PED(PlayerID), back, One.x,One.y,One.z, Two.y,Two.x,Two.z, 0, 1, 0, 0, 2, 1); 
   ENTITY::SET_ENTITY_COLLISION(attachobj,true, 0);// okay next ? ^^ do i have to run that in a loop//Yea
   return 1;
  }
  return 0;
 } 
 return 0;
}
bool doAnimationPed(int ped, char* anim, char* animid)
{
	int pPlayer = ped;
	NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(pPlayer);
	STREAMING::REQUEST_ANIM_DICT(anim);
	if (STREAMING::HAS_ANIM_DICT_LOADED((anim)))
	{
		AI::TASK_PLAY_ANIM(pPlayer, anim, animid, 8.0f, 0.0f, -1, 9, 0, 0, 0, 0);
		return true;
	}
	return false;
}
bool dorape;
void RapePed(int me, int p2)
{
	Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(p2, true);
	if (dorape == false)
	{

		ENTITY::ATTACH_ENTITY_TO_ENTITY(me, p2, 0, 0.0f, 0.2f, 0.0, 0, 0, 0, 1, 1, 0, 0, 2, 1);
		ENTITY::SET_ENTITY_COORDS(me, MyCoords.x, MyCoords.y, MyCoords.z, 1, 0, 0, 1);
		drawNotification("Rape Started");
		doAnimationPed(me, "rcmpaparazzo_2", "shag_loop_a");
		doAnimationPed(p2, "rcmpaparazzo_2", "shag_loop_poppy");
		doAnimationPed(me, "rcmpaparazzo_2", "shag_loop_a");
		doAnimationPed(p2, "rcmpaparazzo_2", "shag_loop_poppy");
		drawNotification("Rape Started");
		dorape = true;
	}
	else if (dorape == true) 
	{
		AI::CLEAR_PED_TASKS_IMMEDIATELY(me);
		AI::CLEAR_PED_TASKS_IMMEDIATELY(p2);
		ENTITY::DETACH_ENTITY(PLAYER::PLAYER_PED_ID(), true, true);
		drawNotification("Rape Stopped And Detched From Ped");
		dorape = false;
	}
}
bool doTeleportClient = false;
bool TeleportClientHook(int Client, float Coords, float y, float z)
{
	Ped handle = PLAYER::GET_PLAYER_PED(Client);
	if (PED::IS_PED_IN_ANY_VEHICLE(handle, 0))
	{
		handle = PED::GET_VEHICLE_PED_IS_IN(handle, 0);
		if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(handle))
		{
			ENTITY::SET_ENTITY_COORDS(handle, Coords, y, z, 0, 0, 0, 1);
			drawNotification("~g~Teleported!");
			return true;
		}
		return false;
	}
	else
	{
		drawNotification("~r~Player is not in a vehicle!");
		doTeleportClient = false;
		return false;
	}
}
void inner_force() 
{
        if (CONTROLS::IS_CONTROL_PRESSED(0, Button_X))
		{
			const int numElements = 50;
			const int arrSize = numElements * 2 + 2;
			Any veh[arrSize];
			veh[0] = numElements;
			int count = PED::GET_PED_NEARBY_VEHICLES(PLAYER::PLAYER_PED_ID(), veh);
			if (veh != NULL)
			{
				for (int i = 1; i <= count; i++)
				{
					int offsettedID = i;
					if (veh[offsettedID] != NULL && ENTITY::DOES_ENTITY_EXIST(veh[offsettedID]))
					{
						ENTITY::APPLY_FORCE_TO_ENTITY(veh[offsettedID], 1, 0, 0, 3, 0, 0, 0, 1, false, true, true, true, true);

					}
				}
			}
		}
}
void InnerFoce()
{
	Loopl = !Loopl;
}
void KickFlip(int veh)
{
	RequestNetworkControl(veh);
	if (VEHICLE::IS_VEHICLE_ON_ALL_WHEELS(veh))
		ENTITY::APPLY_FORCE_TO_ENTITY(veh, 1, 0.0, 0.0, 10.71, 5.0, 0.0, 0.0, 1, false, true, true, true, true);
	drawNotification("Kickflip");
}
bool doFlipCar = false;
bool FlipPlayersCar(int Client)
{
	int PedHandle = ADDR::__GET_PLAYER_PED(Client);
	if (ADDR::__IS_PED_IN_ANY_VEHICLE(PedHandle, 0))
	{
		int VehHandle = ADDR::__GET_VEHICLE_PED_IS_IN(PedHandle, 0);
		if (ADDR::__NETWORK_REQUEST_CONTROL_OF_ENTITY(VehHandle))
		{
			KickFlip(VehHandle);
			drawNotification("~b~Kickflip~w~!");
			return true;
		}
		else return false;
	}
	else
	{
		drawNotification("~r~Player is not  in a vehicle!");
		doFlipCar = false;
		return false;
	}
}
bool RunSpeed = false;
void playerMovementSpeed()
{
	if (!RunSpeed)
	{
		PLAYER::_SET_MOVE_SPEED_MULTIPLIER(PLAYER::PLAYER_ID(), 1.49f);
		drawNotification("Super Run: ~b~Enabled~w~!");
		RunSpeed = true;
	}
	else
	{
		PLAYER::_SET_MOVE_SPEED_MULTIPLIER(PLAYER::PLAYER_ID(), 1);
		drawNotification("Super Run: ~r~Disabled~w~!");
		RunSpeed = false;
	}
}
bool doMaxCar = false;
bool tunePlayersCar(int Client)
{
	//FixWashVehicleClient
	int PedHandle = ADDR::__GET_PLAYER_PED(Client);
	if (ADDR::__IS_PED_IN_ANY_VEHICLE(PedHandle, 0))
	{
		int VehHandle = ADDR::__GET_VEHICLE_PED_IS_IN(PedHandle, 0);
		if (ADDR::__NETWORK_REQUEST_CONTROL_OF_ENTITY(VehHandle))
		{
			MaxUpgrades(VehHandle);//Maxtune(VehHandle);
			PRINT("Vehicle ~b~Full Upgraded~w~!", 1000);

			return true;
		}
		else return false;
	}
	else
	{
		PRINT("~r~Player is not  in a vehicle!", 2000);
		doMaxCar = false;
		return false;
	}
}

int JetObject;
int Heiht;

bool Zusat2 = false;
bool SpawnFlieg()
{
	int ObjectName = GAMEPLAY::GET_HASH_KEY("prop_basejump_target_01");
	if (STREAMING::IS_MODEL_IN_CDIMAGE(ObjectName))
	{
		if (STREAMING::IS_MODEL_VALID(ObjectName))
		{
			STREAMING::REQUEST_MODEL(ObjectName);
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			if (STREAMING::HAS_MODEL_LOADED(ObjectName))
			{
				JetObject = OBJECT::CREATE_OBJECT(ObjectName, coords.x, coords.y, coords.z, 1, 0, 1);
				if (ENTITY::DOES_ENTITY_EXIST(JetObject))
				{
					ENTITY::SET_ENTITY_COLLISION(JetObject, 1, 0);
					ENTITY::SET_ENTITY_ALPHA(JetObject, 0, 0);
					ENTITY::SET_ENTITY_VISIBLE(JetObject, false);
					
					Zusat2 = true;
					return true;
				}
				else return false;
			}
			else return false;
		}
	}
}

bool jP;
bool sJP=false;
void JETPACK()
{
	if (!jP)
	{
		jP = true;
		sJP = true;
		Vector3 uhu = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
		Heiht  = uhu.z;
	}
	else
	{
		jP = false;
		Zusat2 = false;
		DeleteEntity(JetObject);
		StopAnim();
		ENTITY::DETACH_ENTITY(PLAYER::PLAYER_PED_ID(), 0, 0);
	}
}
Vector3 TelePLCoords;
bool TeleportPlayer = false;
bool TeleportPLFunc(int Player, Vector3 Coords)
{
 int handle = PLAYER::GET_PLAYER_PED(Player);
 if (PED::IS_PED_IN_ANY_VEHICLE(handle, 0)){
  handle = PED::GET_VEHICLE_PED_IS_IN(handle, 0);
  if (NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(handle))  {
   ENTITY::SET_ENTITY_COORDS(handle, Coords.x, Coords.y, Coords.z, 0, 0, 0, 1);
   PRINT("~b~Teleported!", 200);
   ParticleFX("scr_trevor1", "scr_trev1_trailer_boosh", PLAYER::PLAYER_PED_ID());
   return true;
  }
  return false;
 }
 else{
  PRINT("~r~Player is not in a vehicle!", 2000);
  TeleportPlayer = false;
  return false;
 }
}

void DriveAir()
{
	if (!MeinCode)
	{
		AirHeigt = 360;
		MeinCode = true;
		Spanlllll = true;
		MeinCodewat = false;
	}
	else
	{
		MeinCode = false;
		Zusatz = false;
		DeleteEntity(FerrisWheele);
	}
}
bool SpawnWheel()
{
	int ObjectName = GAMEPLAY::GET_HASH_KEY("prop_ld_ferris_wheel");
	if (STREAMING::IS_MODEL_IN_CDIMAGE(ObjectName))
	{
		if (STREAMING::IS_MODEL_VALID(ObjectName))
		{
			STREAMING::REQUEST_MODEL(ObjectName);
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			if (STREAMING::HAS_MODEL_LOADED(ObjectName))
			{
				FerrisWheele = OBJECT::CREATE_OBJECT(ObjectName, coords.x, coords.y, coords.z, 1, 0, 1);
				if (ENTITY::DOES_ENTITY_EXIST(FerrisWheele))
				{
					Vector3 Me = ENTITY::GET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0),1);
					ENTITY::SET_ENTITY_COORDS(FerrisWheele, Me.x, Me.y, AirHeigt, 1, 0, 0, 1);
					ENTITY::SET_ENTITY_ROTATION(FerrisWheele, 180, 90, 180, 2, 1);
					ENTITY::SET_ENTITY_VISIBLE(FerrisWheele, false);
					ENTITY::SET_ENTITY_ALPHA(FerrisWheele, 0,0);
					ENTITY::FREEZE_ENTITY_POSITION(FerrisWheele, true);
					if (!MeinCodewat)
						ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), Me.x, Me.y, AirHeigt + 2, 1, 0, 0, 1);
					Zusatz = true;
					return true;
				}
				else return false;
			}
			else return false;
		}
	}
}
void DriveWater()
{
	if (!MeinCodewat)
	{
		MeinCodewat = true;
		AirHeigt = -1.6;
		Spanlllll = true;
		MeinCode = false;
	}
	else
	{
		MeinCodewat = false;
		Zusatz = false;
		DeleteEntity(FerrisWheele);
	}
}
int fam;
void Modelo(char* family, int model, int texture)
{
	if (cstrcmp(family, "HATS") || cstrcmp(family, "GLASSES") || cstrcmp(family, "EARS"))
	{
		if (cstrcmp(family, "HATS"))
			fam = 0;
		else if (cstrcmp(family, "GLASSES"))
			fam = 1;
		else if (cstrcmp(family, "EARS"))
			fam = 2;
		ADDR::__SET_PED_PROP_INDEX(ADDR::__PLAYER_PED_ID(), fam, model - 1, texture);
	}
	else
	{
		if (cstrcmp(family, "FACE"))
			fam = 0;
		else if (cstrcmp(family, "MASK"))
			fam = 1;
		else if (cstrcmp(family, "HAIR"))
			fam = 2;
		else if (cstrcmp(family, "TORSO"))
			fam = 3;
		else if (cstrcmp(family, "LEGS"))
			fam = 4;
		else if (cstrcmp(family, "HANDS"))
			fam = 5;
		else if (cstrcmp(family, "SHOES"))
			fam = 6;
		else if (cstrcmp(family, "SPECIAL1"))
			fam = 7;
		else if (cstrcmp(family, "SPECIAL2"))
			fam = 8;
		else if (cstrcmp(family, "SPECIAL3"))
			fam = 9;
		else if (cstrcmp(family, "TEXTURE"))
			fam = 10;
		else if (cstrcmp(family, "TORSO2"))
			fam = 11;
		ADDR::__SET_PED_COMPONENT_VARIATION(ADDR::__PLAYER_PED_ID(), fam, model, texture);
	}
}
void MoneyLoop()
{
	if (!loop40K_)
	{
		loop40K_ = true;
	}
	else
	{
		loop40K_ = false;
	}
}
int MaxRadius = 8;
void RainMoney()
{

	STREAMING::REQUEST_MODEL(0x113FD533);
	Vector3 Player = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS2(PLAYER::GET_PLAYER_PED(selectedPlayer), 0.0, 0.0, 0);
	int offsetX = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-MaxRadius, MaxRadius);
	int offsetyY = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-MaxRadius, MaxRadius);
	int offsetX1 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-MaxRadius, MaxRadius);
	int offsetyY1 = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(-MaxRadius, MaxRadius);
	int offsetZ = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(8, 25);

	if (STREAMING::HAS_MODEL_LOADED(0x113FD533))
	{
		int PICKUP_MONEY_CASE = GAMEPLAY::GET_HASH_KEY("PICKUP_MONEY_CASE");
		int AMOUNT = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(20000, 40000);
		Vector3 Cord1 = { Player.x + offsetX, Player.y + offsetyY, Player.z + offsetZ };
		Vector3 Cord2 = { Player.x + offsetX1, Player.y + offsetyY1, Player.z + offsetZ };
		ADDR::__CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, &Cord1, 0, AMOUNT, 0x113FD533, 0, 1);
		ADDR::__CREATE_AMBIENT_PICKUP(PICKUP_MONEY_CASE, &Cord2, 0, AMOUNT, 0x113FD533, 0, 1);
		STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(0x113FD533);

	}
}

void changenae(char *newname = "")
	{
		strncpy((char*)0x41143344, newname, strlen(newname));
		*(char*)(0x41143344 + strlen(newname)) = 0;
		strncpy((char*)0x200255C, newname, strlen(newname));
		*(char*)(0x200255C + strlen(newname)) = 0;
	}
/*opd_s PRINT_TEXT_TYPE_t = { 0x3C80A0,};
int(*PRINT_TEXT_TYPE)(const char* p1) = (int(*)(const char *))&PRINT_TEXT_TYPE_t;
opd_s _add_text_component_string = { 0x3C8460, };
void(*PRINT_TEXT_TEXT)(const char *text) = (void(*)(const char *))&_add_text_component_string;
opd_s PRINT_TEXT_TIME_t = { 0x3C80C0, };
int(*PRINT_TEXT_TIME)(int p1) = (int(*)(int))&PRINT_TEXT_TIME_t;*/

//void PRINT(const char* Text, int MillisecondsToDisplay);
/*void PRINT(const char* Text, int MillisecondsToDisplay = 2000)
{
	ADDR::__PRINT_TEXT_TYPE("STRING");
	ADDR::__PRINT_TEXT_TEXT(Text);
	ADDR::__PRINT_TEXT_TIME(MillisecondsToDisplay);
}*/

	void PRINT(const char* Text, int MillisecondsToDisplay= 2000)
	{
		ADDR::__PRINT_TEXT_TYPE("STRING");
		ADDR::__PRINT_TEXT_TEXT(Text);
		ADDR::__PRINT_TEXT_TIME(MillisecondsToDisplay);
	}

	bool KEYBOARD_PROMPT = false;
	int KeyboardIndex = 0; 
	void doKeyboardFunc(char* Result, int KBIndex, int Client)
	{
		char buf[100];
		switch(KBIndex)
		{
		case 0: PRINT(Result, 2000); break;// looks right idk whats wrong maybe your functio.
		case 1: sendText(PLAYER::GET_PLAYER_PED(selectedPlayer), Result, 0);break;
		case 2:	changenae(Result);break;
		}
		KeyboardIndex = 0;// y
	}
	void Kiste(Vector3 Cords,float XXX, float ZZZ)
{
	GRAPHICS::DRAW_LINE(Cords.x + XXX, Cords.y + XXX, Cords.z + ZZZ, Cords.x + XXX, Cords.y - XXX, Cords.z + ZZZ, MarkerRed, markergreen, markerblue, 255);
	GRAPHICS::DRAW_LINE(Cords.x + XXX, Cords.y - XXX, Cords.z + ZZZ, Cords.x - XXX, Cords.y - XXX, Cords.z + ZZZ, MarkerRed, markergreen, markerblue, 255);
	GRAPHICS::DRAW_LINE(Cords.x - XXX, Cords.y - XXX, Cords.z + ZZZ, Cords.x - XXX, Cords.y + XXX, Cords.z + ZZZ, MarkerRed, markergreen, markerblue, 255);
	GRAPHICS::DRAW_LINE(Cords.x - XXX, Cords.y + XXX, Cords.z + ZZZ, Cords.x + XXX, Cords.y + XXX, Cords.z + ZZZ, MarkerRed, markergreen, markerblue, 255);
	GRAPHICS::DRAW_LINE(Cords.x + XXX, Cords.y + XXX, Cords.z - ZZZ, Cords.x + XXX, Cords.y - XXX, Cords.z - ZZZ, MarkerRed, markergreen, markerblue, 255); 
	GRAPHICS::DRAW_LINE(Cords.x + XXX, Cords.y - XXX, Cords.z - ZZZ, Cords.x - XXX, Cords.y - XXX, Cords.z - ZZZ, MarkerRed, markergreen, markerblue, 255);
	GRAPHICS::DRAW_LINE(Cords.x - XXX, Cords.y - XXX, Cords.z - ZZZ, Cords.x - XXX, Cords.y + XXX, Cords.z - ZZZ, MarkerRed, markergreen, markerblue, 255);
	GRAPHICS::DRAW_LINE(Cords.x - XXX, Cords.y + XXX, Cords.z - ZZZ, Cords.x + XXX, Cords.y + XXX, Cords.z - ZZZ, MarkerRed, markergreen, markerblue, 255);
	GRAPHICS::DRAW_LINE(Cords.x + XXX, Cords.y + XXX, Cords.z - ZZZ, Cords.x + XXX, Cords.y + XXX, Cords.z + ZZZ, MarkerRed, markergreen, markerblue, 255);
	GRAPHICS::DRAW_LINE(Cords.x + XXX, Cords.y - XXX, Cords.z - ZZZ, Cords.x + XXX, Cords.y - XXX, Cords.z + ZZZ, MarkerRed, markergreen, markerblue, 255);
	GRAPHICS::DRAW_LINE(Cords.x - XXX, Cords.y - XXX, Cords.z - ZZZ, Cords.x - XXX, Cords.y - XXX, Cords.z + ZZZ, MarkerRed, markergreen, markerblue, 255);
	GRAPHICS::DRAW_LINE(Cords.x - XXX, Cords.y + XXX, Cords.z - ZZZ, Cords.x - XXX, Cords.y + XXX, Cords.z + ZZZ, MarkerRed, markergreen, markerblue, 255);
}

#pragma endregion

#pragma region Other Loop
void otherLoop()
{	
	if(drift){Drif(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));} else {drift = false;}
	if(ToggleSlowMo) { SlowMotion();}
	if(doAttachCustom){
	if(AttachCustom(Modchar) == true)	{ Vector3 One, Two; doAttachCustom = false;}}
	if(Loading_Vehicle) {Vector3 Pos; if (Create_Vehicle(Vehicle_String, "", Pos) == true) { Loading_Vehicle = false; Vehicle_String = ""; }}
	if(shhotcars_) { ShhotCars(); }
	if(doTrolley){if(spawnTrolley()){doTrolley = false;}} 
	if(doToilet){if(spawnToilet()){doToilet = false;}} 
	if(doCouch){if(spawnCouch()){doCouch = false;}} 
	if(doWheelchair){if(spawnWheelchair()){doWheelchair = false;}} 
	if(doBumpercar){if(spawnBumpercar()){doBumpercar = false;}} 
	if(doWheelbarrow){if(spawnWheelbarrow()){doWheelbarrow = false;}} 
	if(doTeddycar){if(spawnTeddycar()){doTeddycar = false;}} 
	if(minigun){if(spawnMiniguncar()){minigun = false;}} 
	if(minigun2){if(MINIGUNCAR2()){minigun2 = false;}}
	if(batbike){if(spawnBatBike()){batbike = false;}}
	if(buggy){if(BumperBuggy()){buggy = false;}}
	if(kart){if(GoKart()){kart = false;}}
	if(starwars){if(spawnstarwars()){starwars = false;}}
	if(starwars2){if(spawnstarwars2()){starwars2 = false;}}
	if(pimpin == true) { LowRider(); }
	if(Driftin) { if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) DriftMod(); else { Driftin = false; PRINT("Slow Motion Drift ~r~Disabled~w~!\nYou need a Vehicle", 2000); } }
	if ( SpawnGuitar) { if(AttachGuitar(selectedPlayer)==true) { SpawnGuitar=false; } }
	if (sJP) { if (SpawnFlieg() == true){sJP = false;}}
    if (Spanlllll) { if (SpawnWheel() == true) { Spanlllll = false;}}
	if (ForceTest) { if (CONTROLS::IS_CONTROL_PRESSED(0, Button_X)) { ForceVehicles(PLAYER::PLAYER_PED_ID(), true);}}
	if (Bunnycars) { ForceVehicle2s(PLAYER::PLAYER_PED_ID(), false, true);}
	if (TuneArea2) { AreaTune2(PLAYER::PLAYER_PED_ID(), 100);}
	if (Buny) { AreaBunny(PLAYER::PLAYER_PED_ID(), 100); }
	if (BoostAreaCar) { if (CONTROLS::IS_CONTROL_PRESSED(0, Button_R1)) { AreaBoost(PLAYER::PLAYER_PED_ID(), 100); }}
	if (doFlipCar) { if (FlipPlayersCar(selectedPlayer)) { doFlipCar = false; } }
	if (WaepLOOP) { DropWeapons(ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 1)); }	
	if(SpeedOMeter) { if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0)) { memset(buffer, 0, sizeof(buffer)); float speed = (ENTITY::GET_ENTITY_SPEED(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0)) * 3.3) * 1.609344; _sprintf(buffer, 100, "%.2f%s", speed, " ~b~KMH\n\0"); drawSpeedo(buffer); } }
	if(pedstopanim) { AI::CLEAR_PED_TASKS_IMMEDIATELY(SpawnedPed[SelectedPed]); pedstopanim = false; }
	if(pedsexr) { STREAMING::REQUEST_ANIM_DICT("rcmpaparazzo_2"); if (STREAMING::HAS_ANIM_DICT_LOADED("rcmpaparazzo_2") == 1) { AI::TASK_PLAY_ANIM(SpawnedPed[SelectedPed], "rcmpaparazzo_2", "shag_loop_poppy", 8, 0, -1, 9, 0, 0, 0, 0); } pedsexr = false; }
	if(hasBossMode == true){ BoosMode(); }
	if(frezzeplayer) { AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::GET_PLAYER_PED(selectedPlayer)); }
	if(Maxup) { MaxUpgrades(selectedPlayer);} else {Maxup = false;}
	//if(Maxup){NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(selectedPlayer), true)); if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(selectedPlayer), true)));{MaxUpgrades(selectedPlayer);} Maxup = false;}
	if(SlingShot){NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(selectedPlayer), true)); if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(selectedPlayer), true)));{ENTITY::APPLY_FORCE_TO_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(selectedPlayer), true), 1, 0, 0, 20, 0, 0, 0, 1, false, true, true, true, true);} SlingShot = false;}
	if(r3boost) { if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_R3)) VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 100);}
	if(l3break) { if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_L3)) VEHICLE::SET_VEHICLE_FORWARD_SPEED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0);}
	if(leftfix) { if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Dpad_Left)) VEHICLE::SET_VEHICLE_FIXED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()));}
	if(frezzeall) {for (int i = 0; i < 16; i++) {int id = PLAYER::GET_PLAYER_PED(i); if (id > 0 && id != PLAYER::PLAYER_PED_ID()) {AI::CLEAR_PED_TASKS_IMMEDIATELY(id);}}}
	if(VehEap){VehicleWeaponsFunction();}
	if(Loopl){inner_force();}
	if(rainbow) { RainbowGun(); }
	if(loop40K_) { Vector3 mycoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true); STREAMING::REQUEST_MODEL(0x113FD533); if(STREAMING::HAS_MODEL_LOADED(0x113FD533) == 1) { OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, mycoords.x, mycoords.y, mycoords.z, 0, 40000, 0x113FD533, 0, 1);  STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(0x113FD533); }}
	if(LowerWhip) { LowerCar(); } 
	if(SuperJump){GAMEPLAY::SET_SUPER_JUMP_THIS_FRAME(PLAYER::PLAYER_ID());}
	if(ExplosiveBullets){GAMEPLAY::SET_EXPLOSIVE_AMMO_THIS_FRAME(PLAYER::PLAYER_ID());}
	if(predator) {PredoGun();} else {predator = false;}
	if(SuperPunch){GAMEPLAY::SET_EXPLOSIVE_MELEE_THIS_FRAME(PLAYER::PLAYER_ID());}
	if(TurnSignalLeft){int VehHandle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());PED::IS_PED_IN_ANY_VEHICLE(VehHandle, 0);VEHICLE::SET_VEHICLE_INDICATOR_LIGHTS(VehHandle, 1, 1);} else {int VehHandle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());PED::IS_PED_IN_ANY_VEHICLE(VehHandle, 0);VEHICLE::SET_VEHICLE_INDICATOR_LIGHTS(VehHandle, 1, 0);}
	if(TurnSignalRight){int VehHandle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());PED::IS_PED_IN_ANY_VEHICLE(VehHandle, 0);VEHICLE::SET_VEHICLE_INDICATOR_LIGHTS(VehHandle, 0, 1);} else {int VehHandle = PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID());PED::IS_PED_IN_ANY_VEHICLE(VehHandle, 0);VEHICLE::SET_VEHICLE_INDICATOR_LIGHTS(VehHandle, 0, 0);}
	if(NoCops){PLAYER::CLEAR_PLAYER_WANTED_LEVEL(PLAYER::PLAYER_ID());} else {NoCops = false;}
	if(GodModeVehicle){ENTITY::SET_ENTITY_INVINCIBLE(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), true);} else {GodModeVehicle = false;}
	if(DriftCar){VEHICLE::SET_VEHICLE_REDUCE_GRIP(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()),true);} else {VEHICLE::SET_VEHICLE_REDUCE_GRIP(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()),false);}
	if(NoTarget){PED::SET_PED_CAN_BE_TARGETTED(PLAYER::PLAYER_PED_ID(),false);} else {PED::SET_PED_CAN_BE_TARGETTED(PLAYER::PLAYER_PED_ID(),true);}
	if(InteriorLights)VEHICLE::SET_VEHICLE_INTERIORLIGHT(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), true); else VEHICLE::SET_VEHICLE_INTERIORLIGHT(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), false);
	if(doForceField_){ doForceField(PLAYER::PLAYER_PED_ID()); }
	if (forcefield) { Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true); FIRE::ADD_EXPLOSION(coords.x, coords.y, coords.z, 0x08, 640.00, 0, 1, 0); }
	if(Neons_){drawneons(NeonR, NeonG, NeonB);}
	if(LoopNeons_) { NeonR = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255); NeonG = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 150); NeonB = GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 100); }
	if (_test) { TeleportGun1(); }
    if (firegun) { ShootFire(); }
    if (BulletBags) { MoneyBagGun(); }
    if (weedgun1) { Weedgun(); }
    if (applyforceg) { AimedEnit(); }
	if(Newsbar){draw_news(); }
	if (Partic) { STREAMING::REQUEST_NAMED_PTFX_ASSET(fxName); GRAPHICS::_SET_PTFX_ASSET_NEXT_CALL(fxName); GRAPHICS::START_PARTICLE_FX_NON_LOOPED_ON_ENTITY(EffectName, FXObject, 0.0, 0.0, -0.5, 0.0, 0.0, 0.0, 1.0, false, false, false);Partic = false;}
    //if (CarGun)	{ if (PED::IS_PED_SHOOTING(PLAYER::PLAYER_PED_ID())){ Vehicle_String = Carsall[GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 21)]; Loading_Vehicle = true; }}
	if (RocketGun) { RpgGun(); }
	if (attachboxing)
	{
		int hash = GAMEPLAY::GET_HASH_KEY("prop_gold_cont_01");
		Vector3 coords;
		coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 1);
		OBJECT::CREATE_OBJECT(hash, coords.x, coords.y, coords.z, 1, 1, 0);
		Vector3 One, Two;
		Two.y = 90;
		ADDR::__ATTACH_ENTITY_TO_ENTITY(AttOBBB, ADDR::__GET_PLAYER_PED(selectedPlayer), BIndex, &One, &Two, 0, 1, 0, 0, 2, 1);
		ENTITY::SET_ENTITY_COLLISION(AttOBBB, 1, 0);
		attachboxing = false;
	}
	if (SpawnVehicle)
	{
		Ped pedHandle = PLAYER::PLAYER_PED_ID();
		Vehicle vehHandle = PED::GET_VEHICLE_PED_IS_USING(pedHandle);

		if (!STREAMING::HAS_MODEL_LOADED(hash_veh))
			STREAMING::REQUEST_MODEL(hash_veh);
		else
		{
			if (PED::IS_PED_IN_ANY_VEHICLE(pedHandle, true))
			{
				VEHICLE::DELETE_VEHICLE(&vehHandle);
			}
			Vector3 coords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
			SpawnedVeh = VEHICLE::CREATE_VEHICLE(hash_veh, coords.x, coords.y, coords.z, 0, 1, 0);
			if (ENTITY::DOES_ENTITY_EXIST(SpawnedVeh))
			{
				ENTITY::SET_ENTITY_HEADING(SpawnedVeh, ENTITY::GET_ENTITY_HEADING(pedHandle));
				PED::SET_PED_INTO_VEHICLE(pedHandle, SpawnedVeh, -1);
				ENTITY::SET_ENTITY_INVINCIBLE(SpawnedVeh, true);
                ENTITY::SET_ENTITY_PROOFS(SpawnedVeh, 1, 1, 1, 1, 1, 1, 1, 1);
				VEHICLE::SET_VEHICLE_CAN_BE_VISIBLY_DAMAGED(SpawnedVeh, false);
				VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(SpawnedVeh, false);
				VEHICLE::SET_VEHICLE_NUMBER_PLATE_TEXT(SpawnedVeh, "WILDEMODZ");
				VEHICLE::SET_VEHICLE_MOD_KIT(SpawnedVeh, 0);
		        //VEHICLE::SET_VEHICLE_COLOURS(SpawnedVeh, 120, 120);
		        VEHICLE::TOGGLE_VEHICLE_MOD(SpawnedVeh, 18, 1);
		        VEHICLE::TOGGLE_VEHICLE_MOD(SpawnedVeh, 22, 1);
		        VEHICLE::SET_VEHICLE_MOD(SpawnedVeh, 16, 5, 0);
		        VEHICLE::SET_VEHICLE_MOD(SpawnedVeh, 12, 2, 0);
		        VEHICLE::SET_VEHICLE_MOD(SpawnedVeh, 11, 3, 0);
		        VEHICLE::SET_VEHICLE_MOD(SpawnedVeh, 14, 14, 0);
		        VEHICLE::SET_VEHICLE_MOD(SpawnedVeh, 15, 3, 0);
		        VEHICLE::SET_VEHICLE_MOD(SpawnedVeh, 13, 2, 0);
		        VEHICLE::SET_VEHICLE_WHEEL_TYPE(SpawnedVeh, 6);
		        VEHICLE::SET_VEHICLE_WINDOW_TINT(SpawnedVeh, 5);
		        VEHICLE::SET_VEHICLE_MOD(SpawnedVeh, 23, 19, 1);
		        VEHICLE::SET_VEHICLE_MOD(SpawnedVeh, 0, 1, 0);
		        VEHICLE::SET_VEHICLE_MOD(SpawnedVeh, 1, 1, 0);
		        VEHICLE::SET_VEHICLE_MOD(SpawnedVeh, 2, 1, 0);
		        VEHICLE::SET_VEHICLE_MOD(SpawnedVeh, 3, 1, 0);
		        VEHICLE::SET_VEHICLE_MOD(SpawnedVeh, 4, 1, 0);
		        VEHICLE::SET_VEHICLE_MOD(SpawnedVeh, 5, 1, 0);
		        VEHICLE::SET_VEHICLE_MOD(SpawnedVeh, 6, 1, 0);
		        VEHICLE::SET_VEHICLE_MOD(SpawnedVeh, 7, 1, 0);
		        VEHICLE::SET_VEHICLE_MOD(SpawnedVeh, 8, 1, 0);
		        VEHICLE::SET_VEHICLE_MOD(SpawnedVeh, 9, 1, 0);
		        VEHICLE::SET_VEHICLE_MOD(SpawnedVeh, 10, 1, 0);
				VEHICLE::TOGGLE_VEHICLE_MOD(SpawnedVeh, 20, 1);
				VEHICLE::SET_VEHICLE_MOD_KIT(SpawnedVeh, 0);
				VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(SpawnedVeh, 0, 0, 0);
				SpawnVehicle = false;
			    }
		    }
		}
        Vector3 CreatePedCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
		Create_Ped1(ped_moel, ped_moel, CreatePedCoords.x, CreatePedCoords.y, CreatePedCoords.z, "");
		if (doMaxCar)
	    {
		if (tunePlayersCar(selectedPlayer))
		{
			doMaxCar = false;
		}
	    }
        if (spawnsetswat)
	    {
		int hash = GAMEPLAY::GET_HASH_KEY("s_m_y_swat_01");
		Vector3 mycoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true);
		STREAMING::REQUEST_MODEL(hash);
		if (STREAMING::HAS_MODEL_LOADED(hash))
		{
			spawnedped = PED::CREATE_PED(21, hash, mycoords.x, mycoords.y, mycoords.z, 29, 0.5f, true);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			PED::SET_PED_COMBAT_ABILITY(spawnedped, 100);
			AI::TASK_COMBAT_PED(spawnedped, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 16);
			PED::SET_PED_CAN_SWITCH_WEAPON(spawnedped, false);
			ENTITY::SET_ENTITY_CAN_BE_DAMAGED(spawnedped, 0);
			ENTITY::SET_ENTITY_INVINCIBLE(spawnedped, true);
			PED::SET_PED_CAN_RAGDOLL(spawnedped, 0);
		    PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(spawnedped, 0);
		    PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(spawnedped, false);
			WEAPON::GIVE_DELAYED_WEAPON_TO_PED(spawnedped, 0xB1CA77B1, 9999, 1);
		}
		spawnsetswat = false;
	}
	if (spawnsetchop)
	{
		int hash = GAMEPLAY::GET_HASH_KEY("A_C_Chop");
		Vector3 Pos1 = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true);
		STREAMING::REQUEST_MODEL(hash);
		if (STREAMING::HAS_MODEL_LOADED(hash))
		{
			spawnedped = PED::CREATE_PED(21, hash, Pos1.x, Pos1.y, Pos1.z, 29, 0.5f, true);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
		    PED::SET_PED_COMBAT_ABILITY(spawnedped, 100);
			AI::TASK_COMBAT_PED(spawnedped, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 16);
			PED::SET_PED_CAN_SWITCH_WEAPON(spawnedped, false);
			ENTITY::SET_ENTITY_CAN_BE_DAMAGED(spawnedped, 0);
			ENTITY::SET_ENTITY_INVINCIBLE(spawnedped, true);
			PED::SET_PED_CAN_RAGDOLL(spawnedped, 0);
		    PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(spawnedped, 0);
		    PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(spawnedped, false);
		}
		spawnsetchop = false;
	}
	if (spawnsetmtlion)
	{
		int hash = GAMEPLAY::GET_HASH_KEY("A_C_MtLion");
		Vector3 mycoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true);
		STREAMING::REQUEST_MODEL(hash);
		if (STREAMING::HAS_MODEL_LOADED(hash))
		{
			spawnedped = PED::CREATE_PED(21, hash, mycoords.x, mycoords.y, mycoords.z, 29, 0.5f, true);
			STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(hash);
			AI::TASK_COMBAT_PED(spawnedped, PLAYER::GET_PLAYER_PED(selectedPlayer), 0, 16);
			PED::SET_PED_CAN_SWITCH_WEAPON(spawnedped, true);
			ENTITY::SET_ENTITY_CAN_BE_DAMAGED(spawnedped, 0);
			ENTITY::SET_ENTITY_INVINCIBLE(spawnedped, true);
			PED::SET_PED_CAN_RAGDOLL(spawnedped, 0);
		    PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(spawnedped, 0);
		    PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(spawnedped, false);
		}
		spawnsetmtlion = false;
	 }
	 if(KEYBOARD_PROMPT)
	 {
		 if (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 1)
		{
			KEYBOARD_PROMPT = false;
			doKeyboardFunc(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT(), KeyboardIndex, selectedPlayer);
		}
		else if (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 2)
		{
			KEYBOARD_PROMPT = false;
		}
		else if (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 3)
		{
			KEYBOARD_PROMPT = false;
			PRINT("~r~ERROR: Keyboard not found?", 2000);
		}
	 }
	 if (keyboardActive)
	 {
		if (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 1)
		{
			keyboardActive = false;
			switch (keyboardAction)
			{
			case 0: //addIntOption
				*keyboardVar = StoI(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
				break;
			case 1:
				Vector3 CreatePedCoords1 = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
				drawNotification(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT());
				Create_Ped(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT(), "Custom", CreatePedCoords1.x, CreatePedCoords1.y, CreatePedCoords1.z, "Spawned: Cunstom");
				break;
			case 2:
				strncpy((char*)0x41143344, GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT(), strlen(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()));
				*(char*)(0x41143344 + strlen(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT())) = 0;
				strncpy((char*)0x01FF248C, GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT(), strlen(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT()));
				*(char*)(0x01FF248C + strlen(GAMEPLAY::GET_ONSCREEN_KEYBOARD_RESULT())) = 0;
				break;
			}
		}
		else if (GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 2 || GAMEPLAY::UPDATE_ONSCREEN_KEYBOARD() == 3)
		{
			keyboardActive = false;
		}
	 }
	 if (GrapGun)
	 {
		bool L;
		Entity Enti;
		Hash WeapHash;
		int R, G, B;
		R = 0, G = 255, B = 0;
		WEAPON::GET_CURRENT_PED_WEAPON(PLAYER::PLAYER_PED_ID(), &WeapHash, false);
		if (CONTROLS::IS_CONTROL_PRESSED(0, Button_L2)){
			Vector3 Hand = ENTITY::GET_PED_BONE_COORDS(PLAYER::PLAYER_PED_ID(), 0x49d9, 0, 0, .1);
			Vector3 Front = get_coords_from_cam(1000);
			float Start[] = { Hand.x, Hand.y, Hand.z };
			float End[] = { Front.x, Front.y, Front.z };
			ADDR::__DRAW_LINE(Start, End, R, G, B, 255);
			for (int i = 0; i < 18; i++){
				if (i != PLAYER::PLAYER_ID())
					Kiste(ENTITY::GET_PED_BONE_COORDS(PLAYER::GET_PLAYER_PED(i), 0x796e, 0.06, 0, 0), 0.12, 0.12);
			}
			if (PLAYER::_GET_AIMED_ENTITY(PLAYER::PLAYER_PED_ID(), &Enti))	{
				L = true;
				R = 255, G = 0, B = 0;
				shootAtPed(Enti);
			}
			else{
				R = 0, G = 255, B = 0;
				L = false;
			}
		}
	}
	if (hasESP)
	{
	if (cstrcmp(Marker[MarkerVar1], "Box"))
	{
	   Player playerHandle = PLAYER::GET_PLAYER_PED(selectedPlayer);
	   Vector3 handleCoords = ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS2(playerHandle, 0, 0, 0);
	   Kiste(ENTITY::GET_OFFSET_FROM_ENTITY_IN_WORLD_COORDS2(playerHandle, 0, 0, 0), 0.5, 0.85);
	}
	if (cstrcmp(Marker[MarkerVar1], "Marker"))
	{
	   drawESP(selectedPlayer);
	}
	   if (cstrcmp(Marker[MarkerVar1], "Line"))
	{
	   Linie(selectedPlayer);
	}
	   if (cstrcmp(Marker[MarkerVar1], "Head Marker"))
	{
	   Player playerHandle = PLAYER::GET_PLAYER_PED(selectedPlayer);
	   Kiste(ENTITY::GET_PED_BONE_COORDS(playerHandle, 0x796e, 0.06, 0, 0), 0.12, 0.12);
	}
	}
    if (TeleportPlayer) { if (TeleportPLFunc(selectedPlayer, TelePLCoords)) { TeleportPlayer = false; }}	
	for (int i = 0; i < 16; i++) if (!(cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")) && i != PLAYER::PLAYER_ID()){if (AllESP){if ((cstrcmp(Marker[MarkerVar], "Line"))){Linie(i);}if ((cstrcmp(Marker[MarkerVar], "Box"))){Kiste(ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(i), 1), 0.35, .8);}if ((cstrcmp(Marker[MarkerVar], "Head Marker"))){Kiste(ENTITY::GET_PED_BONE_COORDS(PLAYER::GET_PLAYER_PED(i), 0x796e, 0.06, 0, 0), 0.12, 0.12);}if ((cstrcmp(Marker[MarkerVar], "Marker"))){drawESP(i);}}
	if (AirStikeAll[i])
	{
	Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(i), 1);
	float Start[] = { Coords.x, Coords.y, Coords.z + 70 };
	float Start1[] = { Coords.x + 100, Coords.y, Coords.z + 50 };
	float End[] = { Coords.x, Coords.y, Coords.z };
	ADDR::__SHOOT_SINGLE_BULLET_BETWEEN_COORDS(Start, End, 250, 0, GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_SPACE_ROCKET"), ADDR::__GET_PLAYER_PED(i), 1, 1, 800);
	AirStikeAll[i] = false;}}
	/*if (AirStikePL)
	{
	Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 1);
	float Start[] = { Coords.x, Coords.y, Coords.z + 100 };
	float End[] = { Coords.x, Coords.y, Coords.z };
	ADDR::__SHOOT_SINGLE_BULLET_BETWEEN_COORDS(Start, End, 250, 0, GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_SPACE_ROCKET"), ADDR::__GET_PLAYER_PED(selectedPlayer), 1, 1, 500);
	AirStikePL = false;
	}*/
	if (AirStikePL)
	{
    Vector3 Coords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 1);
    Coords.z += 25;
    float Start[] = { Coords.x, Coords.y, Coords.z + 30 };
    float End[] = { Coords.x, Coords.y, Coords.z };
    float Start12[] = { Coords.x, Coords.y, Coords.z + 35 };
    float End12[] = { Coords.x, Coords.y, Coords.z };
    ADDR::__SHOOT_SINGLE_BULLET_BETWEEN_COORDS(Start12, End12, 250, 1, GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_SPACE_ROCKET"), ADDR::__GET_PLAYER_PED(selectedPlayer), 1, 1, 500);
    ADDR::__SHOOT_SINGLE_BULLET_BETWEEN_COORDS(Start, End, 250, 0, GAMEPLAY::GET_HASH_KEY("VEHICLE_WEAPON_SPACE_ROCKET"), 0, 1, 1, 500);
    GAMEPLAY::SHOOT_SINGLE_BULLET_BETWEEN_COORDS(Coords.x, Coords.y, Coords.z + 55, Coords.x, Coords.y, Coords.z, 100, false, 0xF8A3939F, ADDR::__GET_PLAYER_PED(selectedPlayer), true, true, 600);
    AirStikePL = false;
    }
    if (Zusatz)
	{
		if (ENTITY::DOES_ENTITY_EXIST(FerrisWheele)){
			Vector3 po;
			if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
				po = ENTITY::GET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0), 1);
			else
				po = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1);
			if (MeinCodewat)
			{
				AirHeigt = -1, 2;
				ENTITY::SET_ENTITY_COORDS(FerrisWheele, po.x, po.y, AirHeigt, 1, 0, 0, 1);
			}
			else{
				AirHeigt = 360;
				ENTITY::SET_ENTITY_COORDS(FerrisWheele, po.x, po.y, AirHeigt, 1, 0, 0, 1);
			}
			ENTITY::SET_ENTITY_ROTATION(FerrisWheele, 180, 90, 180, 2, 1);
			ENTITY::SET_ENTITY_VISIBLE(FerrisWheele, false);
			ENTITY::SET_ENTITY_ALPHA(FerrisWheele, 0, 0);
		}
	}
	if (FlyCar)
	{
		int VehicleHandle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		float Speed = ENTITY::GET_ENTITY_SPEED(VehicleHandle);
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
		{
			NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(PLAYER::PLAYER_PED_ID()), true));
			if (!ENTITY::IS_ENTITY_IN_AIR(VehicleHandle))
			{
				if (Speed > 15)
				{
					PRINT("Start with Square", 1);
					if (CONTROLS::IS_CONTROL_PRESSED(0, Button_X))
					{
						ENTITY::APPLY_FORCE_TO_ENTITY(VehicleHandle, 1, 0, 3, 0.2, 0, 1, 0, 1, 1, 1, 1, 0, 1);
						PRINT("Control the Vehicle With \n~b~L1 ~w~and~b~ R1", 2000);
					}
				}
			}
			else if (ENTITY::IS_ENTITY_IN_AIR(VehicleHandle))
			{
				CONTROLS::SET_INPUT_EXCLUSIVE(2, 196);// Aiming // Zielen
				if (CONTROLS::IS_CONTROL_PRESSED(0, Button_R2))
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(VehicleHandle, 65);
				if (CONTROLS::IS_CONTROL_PRESSED(0, Button_L2))
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(VehicleHandle, -65);
				if (CONTROLS::IS_CONTROL_PRESSED(0, Button_L1))
					ENTITY::APPLY_FORCE_TO_ENTITY(VehicleHandle, 1, -0.050, 0, 0, 0, 2, 0, 1, 1, 1, 1, 0, 1);
				if (CONTROLS::IS_CONTROL_PRESSED(0, Button_R1))
					ENTITY::APPLY_FORCE_TO_ENTITY(VehicleHandle, 1, 0.050, 0, 0, 0, 2, 0, 1, 1, 1, 1, 0, 1);
				if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_L1))
					VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(VehicleHandle);
				if (CONTROLS::IS_CONTROL_JUST_PRESSED(0, Button_R1))
					VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(VehicleHandle);
				if (CONTROLS::IS_CONTROL_PRESSED(0, Button_L2) && CONTROLS::IS_CONTROL_PRESSED(0, Button_R2))
					VEHICLE::SET_VEHICLE_FORWARD_SPEED(VehicleHandle, 0);
			}
		}
	}
	if (Wiiili){
	int UpDown = CONTROLS::GET_CONTROL_VALUE(0, 189);
	int VehicleHandle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), 0))
	{
	if (UpDown == 254)
	ENTITY::APPLY_FORCE_TO_ENTITY(VehicleHandle, 1, 0, 0, EINS, 0, ZWEI, 0, 1, 1, 1, 1, 0, 1);
    }
	else
	{
	Wiiili = false;
	}
	}
	if (Superman)
	{
		int LeftRight = CONTROLS::GET_CONTROL_VALUE(0, 188);
		int UpDown = CONTROLS::GET_CONTROL_VALUE(0, 189);
		int Me = PLAYER::PLAYER_PED_ID();
		if (!ENTITY::IS_ENTITY_IN_AIR(Me))
		{
			if (CONTROLS::IS_CONTROL_PRESSED(0, Button_L3) && CONTROLS::IS_CONTROL_PRESSED(0, Button_R1))
			{
				Vector3 MyCoords = ENTITY::GET_ENTITY_COORDS(Me, 1);
				ENTITY::SET_ENTITY_COORDS(Me, MyCoords.x, MyCoords.y, MyCoords.z + 20, 0, 0, 0, 1);
			}
			PRINT("Start: ~b~L3~w~+~b~R1 \nControl: ~b~Left Stick \n~w~Forward: ~b~R2");
		}
		else
		{
			if (UpDown == 254)//L3 Hinten
				ENTITY::APPLY_FORCE_TO_ENTITY(Me, 1, 0, +3, 10, 0, 0, 0, 1, 1, 1, 1, 0, 1);
			if (UpDown == 0)//L3 Vorn
				ENTITY::APPLY_FORCE_TO_ENTITY(Me, 1, 0, +3, 0, 0, 0, 0, 1, 1, 1, 1, 0, 1);
			if (CONTROLS::IS_CONTROL_PRESSED(0, Button_R2))
				ENTITY::APPLY_FORCE_TO_ENTITY(Me, 1, 0, +15, .3, 0, 0, 0, 1, 1, 1, 1, 0, 1);
			if (LeftRight == 254)//L3 Vorn
				ENTITY::APPLY_FORCE_TO_ENTITY(Me, 1, 2.20, 0, 0, 0, 0.50, 0, 1, 1, 1, 1, 0, 1);
			if (LeftRight == 0)//L3 Vorn
				ENTITY::APPLY_FORCE_TO_ENTITY(Me, 1, -2.20, 0, 0, 0, 0.50, 0, 1, 1, 1, 1, 0, 1);
		}
	}
	if (explosionloop){Vector3 Pos1 = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true);FIRE::ADD_EXPLOSION(Pos1.x, Pos1.y, Pos1.z, 29, 0.5f, true, false, 5.0f);{STREAMING::REQUEST_MODEL(0x113FD533);if (STREAMING::HAS_MODEL_LOADED(0x113FD533) == 1){ Vector3 mycoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true);OBJECT::CREATE_AMBIENT_PICKUP(0xCE6FDD6B, mycoords.x, mycoords.y, mycoords.z, 0, 40000, 0x113FD533, 0, 1); STREAMING::SET_MODEL_AS_NO_LONGER_NEEDED(0x113FD533);}}}
    if (alplayerscash){
    for (int i = 0; i < 16; i++) {
    if (!(cstrcmp(PLAYER::GET_PLAYER_NAME(i), "-")) && i != PLAYER::PLAYER_ID()){
    if (ENTITY::DOES_ENTITY_EXIST(PLAYER::GET_PLAYER_PED(i)))
    dropPickup(ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(i), 1), "prop_money_bag_01", "PICKUP_MONEY_CASE", 40000); }}}
    if (MoneyRain) { RainMoney(); }
    if(expl){ for(int i = 0; i < 18; i++){
	if (i != PLAYER::PLAYER_PED_ID()){
	Vector3 mycoords = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(i), true);
	FIRE::ADD_OWNED_EXPLOSION(PLAYER::GET_PLAYER_PED(i), mycoords.x, mycoords.y, mycoords.z, 29, 0.5f, true, false, 5.0f);}}} expl = false;
    if(PredGun) { PredToPlayer(PLAYER::GET_PLAYER_PED(selectedPlayer)); }
    if (newsbar){draw_news();}
	if (ShowTalking) { memset(TLK, 0, sizeof(TLK)); char* Talker; for(int i = 0; i < 18; i++) { if(NETWORK::NETWORK_IS_PLAYER_TALKING(i)) { Talker = PLAYER::GET_PLAYER_NAME(i); snprintf(TLK, 100, "Talking: ~b~%s", Talker); drawTalker(TLK, i); } } }
	//if(ShowInfos) { memset(HST, 0, sizeof(HST)); char* Host = GetHostName(); if (strcmp(Host, "-")) Host = "~r~Singleplayer"; snprintf(HST, 100, "Host: ~b~%s", GetHostName()); DrawInfos(HST); }
	if (ShowInfos)
	{
		memset(VEH, 0, sizeof(VEH));
		memset(PEDOO, 0, sizeof(PEDOO));
		memset(HST, 0, sizeof(HST));
		memset(NUM, 0, sizeof(NUM));
		char* Host = GetHostName();
		if (cstrcmp(Host, "~r~Not Online"))
			Host = "";
		ADDR::__snprintf(HST, 100, "~HUD_COLOUR_WHIT~Server Host: ~HUD_COLOUR_BLUE~%s", GetHostName());
		//ADDR::__snprintf(NUM, 100, "~HUD_COLOUR_WHIT~Free Spots: ~HUD_COLOUR_BLUE~%i", GetHostName());
		ADDR::__snprintf(PEDOO, 100, "~HUD_COLOUR_WHIT~Time Since Last Death: ~b~%.2f Sec.", ((float)ADDR::__GET_TIME_SINCE_LAST_DEATH()) / 1000);
		drawInfos(HST, PEDOO, NUM);
	}
	if (showCoords)
	{
		int Handle = ADDR::__PLAYER_PED_ID();
		memset(X, 0, sizeof(X));
		memset(Y, 0, sizeof(Y));
		memset(Z, 0, sizeof(Z));
		memset(YAW, 0, sizeof(YAW));
		memset(PTH, 0, sizeof(PTH));
		memset(RLL, 0, sizeof(RLL));
		Vector3 Coords = ADDR::__GET_ENTITY_COORDS(Handle, true);
		ADDR::__snprintf(X, 100, "~HUD_COLOUR_WHIT~X Coordinate: ~HUD_COLOUR_BLUE~%.2f", Coords.x);
		ADDR::__snprintf(Y, 100, "~HUD_COLOUR_WHIT~Y Coordinate: ~HUD_COLOUR_BLUE~%.2f", Coords.y);
		ADDR::__snprintf(Z, 100, "~HUD_COLOUR_WHIT~Z Coordinate: ~HUD_COLOUR_BLUE~%.2f", Coords.z);
		ADDR::__snprintf(YAW, 100, "~HUD_COLOUR_WHIT~Yaw: ~HUD_COLOUR_BLUE~%.2f f", ADDR::__GET_ENTITY_HEADING(Handle));
		ADDR::__snprintf(PTH, 100, "~HUD_COLOUR_WHIT~Pitch: ~HUD_COLOUR_BLUE~%.2f f", ADDR::__GET_ENTITY_PITCH(Handle));
		ADDR::__snprintf(RLL, 100, "~HUD_COLOUR_WHIT~Roll: ~HUD_COLOUR_BLUE~%.2f f", ADDR::__GET_ENTITY_ROLL(Handle));
		drawCoords(X, Y, Z, YAW, PTH, RLL);
	}

	if(gmode)
	{
		ENTITY::SET_ENTITY_HEALTH(PLAYER::PLAYER_PED_ID(), PED::GET_PED_MAX_HEALTH(PLAYER::PLAYER_PED_ID()));
		PED::SET_PED_ARMOUR(PLAYER::PLAYER_PED_ID(), PLAYER::GET_PLAYER_MAX_ARMOUR(PLAYER::PLAYER_ID()));
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), 1);
		ENTITY::SET_ENTITY_CAN_BE_DAMAGED(PLAYER::PLAYER_PED_ID(), 0);
		ENTITY::SET_ENTITY_PROOFS(PLAYER::PLAYER_PED_ID(), 1, 1, 1, 1, 1, 1, 1, 1);
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), true);
		PED::SET_PED_CAN_RAGDOLL(PLAYER::PLAYER_PED_ID(), 0);
		PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER::PLAYER_PED_ID(), 0);
		PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER::PLAYER_PED_ID(), false);
	}
	else
	{
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), 0);
		ENTITY::SET_ENTITY_CAN_BE_DAMAGED(PLAYER::PLAYER_PED_ID(), 1);
		ENTITY::SET_ENTITY_PROOFS(PLAYER::PLAYER_PED_ID(), 0, 0, 0, 0, 0, 0, 0, 0);
		ENTITY::SET_ENTITY_INVINCIBLE(PLAYER::PLAYER_PED_ID(), false);
		PED::SET_PED_CAN_RAGDOLL(PLAYER::PLAYER_PED_ID(), 1);
		PED::SET_PED_CAN_RAGDOLL_FROM_PLAYER_IMPACT(PLAYER::PLAYER_PED_ID(), 1);
		PED::SET_PED_CAN_BE_KNOCKED_OFF_VEHICLE(PLAYER::PLAYER_PED_ID(), true);
	}
}
	 
#pragma endregion
int Hook()
{
	monitorButtons();
	otherLoop();
	optionCount = 0;
	switch (submenu)
	{
#pragma region Main Menu
   case Main_Menu:
		addTitle("WILDEMODZ SPRX");
		//Signature("Created by Wildemodz");
		addSubmenuOption("Recovery", Recovery);
		addSubmenuOption("Self Options", Self_Options);
		addSubmenuOption("Spawn Vehicle", Spawn_Vehicle);
		       addOption("Vehicle Options");
		addSubmenuOption("Traffic Options", traffic_options);
        addSubmenuOption("Weapon Editor", Weapon_Editor);
		addSubmenuOption("Vehicle Weapons", Vehicle_Weapons);
		addSubmenuOption("Teleport Options", Teleport);
		addSubmenuOption("Custom Map Options", Custom_Map_Options);
		addSubmenuOption("Spawn Peds", Spawn_Peds);
		addSubmenuOption("Spawn Objects", Spawn_Objects);
		addSubmenuOption("Change Models", Change_Model);
		addSubmenuOption("Weather Options", Weather_Options);
        addSubmenuOption("Animations", Animations);
		addSubmenuOption("Send Message", Players_List2);
		addSubmenuOption("Players List", Players_List);
		addSubmenuOption("All Players", All_Players);
		addSubmenuOption("Settings", Settings, "1.26");
	    switch (getOption())
	    {
	    case 4:
		if (PED::IS_PED_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID(), true)) { changeSubmenu(Vehicle_Options); } else { drawNotification("Must Be In Vehicle To Open Vehicle Options Menu"); }
		break;
		}
	    break;
#pragma endregion
#pragma region Players List
	case Players_List:
		addTitle("Players List");
		for (int i = 0; i < 16; i++)
		{
			addOption(PLAYER::GET_PLAYER_NAME(i));
		}
		if (optionPress && PLAYER::IS_PLAYER_PLAYING(currentOption - 1))
		{
			selectedPlayer = currentOption - 1;
			changeSubmenu(Player_Options);
		}
		break;
#pragma endregion
#pragma region Player Options
   case Player_Options:
	    addTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
	    addSubmenuOption("Teleport Menu",Player_Teleport);
	    addSubmenuOption("Good Things Menu", Player_Good_Things);
	    addSubmenuOption("Bad Things Menu", Player_Bad_Things);
	    addSubmenuOption("Vehicle Menu", Player_Vehicle);
	    break;
		#pragma endregion
#pragma region Player_Teleport
   case Player_Teleport:
		Ped lel = selectedPlayer;
	    addTitle("Player Teleport");
	    addOption("Teleport To Them", "Teleported To Them");
	    addOption("Teleport Into There Car", "");
	    addOption("Teleport To Me (Car)", "");
		addOption("Teleport To Cage (Car)", "");
		addOption("Teleport To Cage1 (Car)", "");	
	    addOption("Teleport Them To Prison (Car)", "");
	    normalMenuActions();
	    switch ( getOption())
	    {
	    case 1: TeleportToPed(selectedPlayer); break;
	    case 2: TpIntoPlayerVehicle(selectedPlayer); break;
	    case 3: TelePLCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1); TeleportPlayer = true; break; 
		case 4: TeleportToCage(selectedPlayer); break;
		case 5: TeleportToCage1(selectedPlayer); break;
	    case 6: TeleportClientHook(lel, 1640.7910, 1640.7910, 1640.7910); break;
	    }
        break;
		#pragma endregion
#pragma region Player_Good_Things
   case Player_Good_Things:
		addTitle("Good Things Menu");
		addBoolOption("LOOP 40K",loop40K_);
		addBoolOption("Rain Money",MoneyRain);
        addBoolOption("Drop Weapon", WaepLOOP);
		addOption("Drop Ammo");
		addOption("Drop Armour");
		addOption("Drop Health");
		addOption("Drop Snacks");
		addOption("Drop Parachute");
		addOption("Give Armour");
		addOption("Give Stun Gun");
		addOption("Give All Weapons");
		//addOption("Give Predator Gun");
		switch (getOption())
		{
		case 1: loop40K_ = !loop40K_; break; 
		case 2: MoneyRain = !MoneyRain; break;
        case 3: WaepLOOP = !WaepLOOP; break;
        case 4: dropPickup(ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 1),"prop_ld_ammo_pack_01", "PICKUP_AMMO_BULLET_MP", 10, "Ammo", selectedPlayer); break;
		case 5: dropPickup(ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 1),"prop_armour_pickup", "PICKUP_ARMOUR_STANDARD", 100, "Armor", selectedPlayer); break;
		case 6: dropPickup(ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 1),"prop_ld_health_pack", "PICKUP_HEALTH_STANDARD", 100, "Health", selectedPlayer); break;
		case 7: dropPickup(ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 1),"prop_ld_snack_01", "PICKUP_HEALTH_SNACK", 10, "Snacks", selectedPlayer); break;
		case 8: dropPickup(ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), 1),"prop_parachute", "PICKUP_PARACHUTE", 1, "Parachute", selectedPlayer); break;
		case 9:	Armour(selectedPlayer); break;
		case 10: WEAPON::GIVE_WEAPON_TO_PED(PLAYER::GET_PLAYER_PED(selectedPlayer), 911657153, -1, true, true); break;
		case 11: GiveAllWeapons(selectedPlayer); break;
		//case 10:PredGun=!PredGun;break;
		}
        break;
		#pragma endregion
#pragma region Player_Bad_Things
   case Player_Bad_Things:
		addTitle("Bad Things Menu");
		addOption("SWAT Player");
		addOption("Set Chop On Player");
		addOption("Set Mt Lion On Player");
		addOption("Kick Player");
		addOption("Clone Player");
		addOption("Explode Player");
		//addOption("Set Player On Fire ~r~FIXING");
		addOption("Remove All Weapons");
		addOption("Clear Player Actions");
		addBoolOption("Forcefield", forcefield);
		addBoolOption("Frezze Player", frezzeplayer);
		addBoolOption2("Attach/Detach Player", PlayerAttached);
		addBoolOption("Explosion loop", explosionloop);
		    addOption("Airstrike Player");
			addOption("Attach Objects Menu");
		addOption("Blame Explosion");
		addCharBOOLSwap("ESP", "Set", Marker, &MarkerVar1, 0, 3,  hasESP);
		//addOption("Ram With Bus");
		switch (getOption())
		{
        case 1: spawnsetswat = true; break; 
		case 2: spawnsetchop = true; break;
		case 3: spawnsetmtlion = true; break;
		case 4: NETWORK::NETWORK_SESSION_KICK_PLAYER(selectedPlayer); break;
        case 5: ClonePed(PLAYER::GET_PLAYER_PED(selectedPlayer)); break;
		case 6: ExplodePlayer(selectedPlayer); break;
		//case 7: Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(selectedPlayer), true); FIRE::ADD_OWNED_EXPLOSION(PLAYER::PLAYER_PED_ID(), Pos.x, Pos.y, Pos.z, 0x1F6C9D25, 1, true, true, 1); break;
        case 7: WEAPON::REMOVE_ALL_PED_WEAPONS(PLAYER::GET_PLAYER_PED(selectedPlayer), 1); break;
        case 8: stopTasks(selectedPlayer); break;
		case 9: forcefield = !forcefield; break;
		case 10: frezzeplayer = !frezzeplayer; break;
		case 11: toggleAttach(selectedPlayer); break;
		case 12: if (explosionloop == false) { drawNotification("Explosion Loop~g~ On"); explosionloop = true; } else if (explosionloop == true) { drawNotification("Explosion Loop~r~ Off"); explosionloop = false; } break;
		case 13: AirStikePL = true;  break;
		case 14: changeSubmenu(FullObj); break;
		case 15:for (int i = 0; i < 18; i++)
			{
				if (i != PLAYER::PLAYER_ID() && i != selectedPlayer)
				{
					Vector3 Pos = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(i), true);
			ADDR::__ADD_OWNED_EXPLOSION(PLAYER::GET_PLAYER_PED(selectedPlayer), &Pos, 29, 0.5f, true, false, 2.0f);
				}
			}
			char buf[100];
			snprintf(buf, sizeof(buf), "%s ~r~Exploded the Lobby!", get_player_name(selectedPlayer));
			PRINT(buf, 2000);
			break;
		case 16: hasESP = !hasESP;	break;
		//case 15: rambus(0xD577C962,selectedPlayer); break;*/

			}
        break;
		#pragma endregion
#pragma region FullObj
		case FullObj:
			addTitle("Attach Objects");
			addCharSwap("Attach to", BONSCH, &BoneVar, 0, 13,  true);
			addCharSwap("Attach", AttPropSub, &AttVAR, 0, 4);
			addOption("Attach Boxing Glove");
			addOption("Full Object List");
			addOption("~b~Custom Input");
			addOption("Delete Objects");
			switch (getOption())
			{
			case 1: BIndex = PED::GET_PED_BONE_INDEX(ADDR::__GET_PLAYER_PED(selectedPlayer), BONES[BoneVar]); break;

			case 2:
				BIndex = PED::GET_PED_BONE_INDEX(ADDR::__GET_PLAYER_PED(selectedPlayer), BONES[BoneVar]);
				Modchar = AttProps[AttVAR];
				doAttachCustom = true;
				break;
			case 3: attachboxing = true; break;

			case 4: changeSubmenu(FullAttacList); break;

			case 5:
				KeyboardIndex = 8;
				ADDR::__DISPLAY_ONSCREEN_KEYBOARD(0, "PM_NAME_CHALL", "", "", "", "", "", 40);
				KEYBOARD_PROMPT = true;
				break;

			case 6:
				for (int i = 0; i < 50; i++)
				{
					if (ENTITY::DOES_ENTITY_EXIST(attachtedObjects[i]))
					{
						DeleteEntity(attachtedObjects[i]);
						PRINT("All Objects Deleted", 2000);
					}
				}
				break;
			}
			break;
		#pragma endregion
#pragma region FullAttacList
   case FullAttacList:
			addTitle("Object List");
			for (AttvarALL = 0; AttvarALL < 3415; AttvarALL++)
			{
				addAttachOption(AllPROPS[AttvarALL]);
			}
			break;
			
		#pragma endregion
#pragma region Player_Vehicle
   case Player_Vehicle:
		Vehicle VehicleHandle = PED::GET_VEHICLE_PED_IS_IN(PLAYER::GET_PLAYER_PED(selectedPlayer), true);
        addTitle("Players Vehicle Menu");
		addOption("Fix Vehicle");
		addOption("Max Upgrades");
        addOption("Delete Vehicle");
		addOption("Kick From Vehicle");
		addOption("Sling Shot Vehicle");
		addOption("Panted Random Color");
		addBoolOption2("Lock Vehicle", doLockCar);
		addBoolOption2("Un-Lock Vehicle", doUnlockCar);
		addBoolOption2("Breakdown Vehicle", doUndriveableCar);
		addBoolOption2("Freeze Vehicle", doFreezeCar);
		addBoolOption2("Un-Freeze Vehicle", doUnfreezeCar);
		     addOption("Kickflip Vehicle");
        addCharSwap("Spawn", Carsall, &llvar, 0, 21 ,1);
		switch (getOption())
		{
        case 1: NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehicleHandle); if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(VehicleHandle)) { VEHICLE::SET_VEHICLE_FIXED(VehicleHandle); } break;
	    case 2: Maxup = !Maxup; break;
			//NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehicleHandle); if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(VehicleHandle)) { MaxUpgrades(selectedPlayer); } break;
		case 3: DeleteVehicle(selectedPlayer); break;
		case 4: KickFromCar(selectedPlayer); break;
		case 5: SlingShot = !SlingShot; break;
        case 6: NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehicleHandle); if (NETWORK::NETWORK_HAS_CONTROL_OF_ENTITY(VehicleHandle)) { VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(VehicleHandle, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255)); VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(VehicleHandle, GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255), GAMEPLAY::GET_RANDOM_INT_IN_RANGE(0, 255)); } break;
		case 7: lockPlayersCar(selectedPlayer); break;
		case 8: unlockPlayersCar(selectedPlayer); break;
		case 9: undriveablePlayersCar(selectedPlayer); break;
		case 10: freezePlayersCar(selectedPlayer); break;
		case 11: unfreezePlayersCar(selectedPlayer); break;
		case 12: doFlipCar = true; break;
        case 13: SpawntoPlayer = true;
			     TeleportInFront = false;
			     TeleAutomIncar = false;
			     Vehicle_String = Carsall[llvar];
			     Loading_Vehicle = true;
			     break;
			
		}
		break;
#pragma endregion
#pragma region Players List
   case Players_List2:
		addTitle("Send Message");
		for (int i = 0; i < 16; i++)
		{
			addOption(PLAYER::GET_PLAYER_NAME(i));
		}
		if (optionPress && PLAYER::IS_PLAYER_PLAYING(currentOption - 1))
		{
			selectedPlayer = currentOption - 1;
			changeSubmenu(Player_Options2);
		}
		break;
#pragma endregion
#pragma region Player Options2
   case Player_Options2:
		addTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
		addOption("Custom MSG");
		addOption("Ban Message");
		addOption("Rockstar are Watching");
		addOption("Troll");
		addOption("Gotcha");
		addOption("Yes");
		addOption("No");
		addOption("Maybe");
		addOption("Can't");
		addOption("Whats Up!");
		addOption("Here Comes The BOOM!");
		addOption("Bring It On BITCH");
		addOption("Stop Asking 4 Money");
		addOption("Stop Asking 2 Mod Ya Car");
		addOption("Last Chance");
		addOption("Before I FUCK YOU UP");
		addOption("WILDEMODZ");
		addOption("Sweet as");
		addOption("All Good Buddy");
		switch (getOption())
		{
        case 1: KeyboardIndex=1; GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "PM_NAME_CHALL", "", "", "", "", "", 150); KEYBOARD_PROMPT=true; break;
		case 2: sendText(selectedPlayer, "~y~WARNING:\n~w~You will be banned from Grand Theft Auto Online", 7); break;
		case 3: sendText(selectedPlayer, "~r~WARNING:\n~y~Rockstar ~w~Are Watching You", 7); break;
		case 4: sendText(selectedPlayer, "~y~Trolla la la la", 7); break;
		case 5: sendText(selectedPlayer, "~b~Gotcha ~w~LOL ~y~:P", 7); break;
		case 6: sendText(selectedPlayer, "~g~Yes", 7); break;
		case 7: sendText(selectedPlayer, "~r~No", 7); break;
		case 8: sendText(selectedPlayer, "~o~Maybe", 7); break;
		case 9: sendText(selectedPlayer, "~y~Can't", 7); break;
		case 10: sendText(selectedPlayer, "WHATS ~g~UUUUUUUUUUP!", 7); break;
        case 11: sendText(selectedPlayer, "Here Comes The ~r~BOOM!", 7); break;
		case 12: sendText(selectedPlayer, "BRING IT ON ~r~BITCH", 7); break;
        case 13: sendText(selectedPlayer, "~r~STOP ~w~ASKING FOR ~g~MONEY", 7); break;
		case 14: sendText(selectedPlayer, "~r~STOP ~w~ASKING ME 2 MOD YOUR ~g~CAR", 7); break;
        case 15: sendText(selectedPlayer, "Last ~g~Chance ~w~To ~r~stop ~w~Being a ~r~DICK", 7); break;
		case 16: sendText(selectedPlayer, "Before I ~r~FUCK YOU UP", 7); break;
        case 17: sendText(selectedPlayer, "This MSG Was Sent By ~p~WILDEMODZ ~g~SPRX", 7); break;
		case 18: sendText(selectedPlayer, "~g~SWEET ~w~AS", 7); break;
		case 19: sendText(selectedPlayer, "~g~All Good ~w~Buddy", 7); break;
        }
		break;
#pragma endregion
#pragma region All Players
   case All_Players:
        addTitle("All Players");
	    addBoolOption("Cash Drop All", alplayerscash);
		addBoolOption("Show Host", ShowInfos);
		addBoolOption("Show Coords", showCoords);
	    addBoolOption("Show Talking Players", ShowTalking);
		addOption("Expload All");
	    addBoolOption("Frezze All", frezzeall);
		addOption("Set On ~r~Fire");
		addOption("Launch All");
		addOption("Airstrike All");
		addCharBOOLSwap("ESP", "Set", Marker, &MarkerVar, 0, 3, AllESP);
	    switch (getOption())
	    {
	case 1: alplayerscash = !alplayerscash; break;
	case 2: ShowInfos = !ShowInfos; break;
	case 3: showCoords = !showCoords; break;
	case 4: ShowTalking = !ShowTalking; break;
	case 5: for (int i = 0; i < 16; i++)
		    {
			int id = PLAYER::GET_PLAYER_PED(i);
			if (id > 0 && id != PLAYER::PLAYER_PED_ID())
			{
				Vector3 Pos1 = ENTITY::GET_ENTITY_COORDS(id, true);
				FIRE::ADD_EXPLOSION(Pos1.x, Pos1.y, Pos1.z, 29, 0.5f, true, false, 5.0f);
			}
		}
		break;
	case 6: frezzeall = !frezzeall; break;
	case 7: for(int i = 0; i<18; i++){
		    if(i != PLAYER::PLAYER_ID()){
		    Vector3 Pos1 = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(i), true);
		    FIRE::ADD_EXPLOSION(Pos1.x, Pos1.y, Pos1.z, 12, 1, false, true, 1); //P = "~g~All Set On Fire!";
			drawNotification("All Set On ~r~Fire!"); 
		    }
	    }
        break;
	case 8: for(int i = 0; i<18; i++){
		    if(i != PLAYER::PLAYER_ID()){
		    Vector3 Pos1 = ENTITY::GET_ENTITY_COORDS(PLAYER::GET_PLAYER_PED(i), true);
		    FIRE::ADD_EXPLOSION(Pos1.x, Pos1.y, Pos1.z, 13, 5.0, 1, 0, 0); // P = "All ~g~Launched!";
			drawNotification("All ~g~Launched"); 
		    }
	    }
	    break;
	case 9: for (int i = 0; i < 16; i++)
			{
				PRINT("~r~Airstrike ~w~to all PLayers", 2000);
				AirStikeAll[i] = true;
			}
			break;
	case 10: AllESP = !AllESP; break;
	    }
		break;
#pragma endregion
#pragma region Self Options
   case Self_Options:
		addTitle("Self Options");
		addBoolOption("God Mode", gmode);
		addBoolOption("Boss Mode", hasBossMode);
		addBoolOption("The Force", Loopl);
		WechselBoolFunction("Jet Pack", "Value", Zusat2, &SetVat, 2,10,1);
		addBoolOption("Superman", Superman);
		addBoolOption("Faster Run", RunSpeed);
		addBoolOption("Super Jump", SuperJump);
		addBoolOption("Super Punch", SuperPunch);
		addBoolOption("Force Field", doForceField_);
		addBoolOption("Not Targeted", NoTarget);
		addBoolOption("Mobile Radio", mobileRadio);
		addBoolOption("Invisibility", !ENTITY::IS_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID()));//); 
	    addBoolOption("Never Wanted", NoCops);
		addBoolOption("Infinite Ammo", Ammo);
		    addOption("Give Self Weapons");
		    addOption("Clean Player");
		    addOption("Disable Idle Kick");
		    addOption("Change Name");
		    addOption("Clothing Sub~r~ ->>");
		switch (getOption())
		{
		case 1: gmode = !gmode; break;
		case 2: hasBossMode = !hasBossMode; break;
        case 3: InnerFoce(); drawNotification("PRESS: ~g~SQUARE ~g~TO SHOW YOUR POWER"); break;
		case 4: JETPACK(); break;
		case 5: dropPickup(ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), 1), "prop_parachute", "PICKUP_PARACHUTE", 2);
			    Superman = !Superman; PRINT(Superman ? "Superman: ~b~Enabled~w~! \nStart the fly with ~b~L3 ~w~and ~b~R1\nControl with ~b~right stick\nR2 Up" : "Superman: ~r~Disabled~w~!", 2000); break;
		case 6: playerMovementSpeed(); break;
		case 7: SuperJump = !SuperJump; break;
		case 8: SuperPunch = !SuperPunch; break;
		case 9: Dofroce(); break;
		case 10: NoTarget = !NoTarget; break;
        case 11: toggleMobileRadio(); break;
		case 12: ENTITY::SET_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID(), !ENTITY::IS_ENTITY_VISIBLE(PLAYER::PLAYER_PED_ID())); break;
		case 13: NoCops = !NoCops; break;
		case 14: AmmoOn(); break;
	    case 15: GiveWeapons(); drawNotification("All Weapons ~g~GIVEN"); break;
		case 16: CleanPed(PLAYER::PLAYER_PED_ID()); break;
		case 17: SetTunable(73, 1); SetTunable(74, 1); SetTunable(75, 1); SetTunable(76, 0x3B9AC9FF); break;
		case 18: startKeyboard(2, "WILDEMODZ", 15); GAMEPLAY::DISPLAY_ONSCREEN_KEYBOARD(0, "PM_NAME_CHALL", "", "", "", "", "", 40); keyboardActive = true; break;
		case 19: changeSubmenu(Outfts); break;
		}
	    break;
#pragma endregion
#pragma region Outfts
   case Outfts:
		addTitle("Outfts");
		addOption("Outfts Men");
		addOption("Outfts Women");
		addOption(" ");
		addOption(" ");
		addOption(" ");
		addOption(" ");
		addOption(" ");
		addOption(" ");
		addOption(" ");
		addOption(" ");
		switch (getOption())
		{
		case 1: changeSubmenu(OutftsMen); break;
		case 2: changeSubmenu(OutftsWomen); break;
		}
		break;
#pragma endregion
#pragma region Outfts Men
   case OutftsMen:
		addTitle("Clothing Men");
		addOption("Pilot");
		addOption("Strength");
		addOption("Security");
		addOption("Families");
		addOption("Ballas");
		addOption("Thug");
		addOption("Santa");
		addOption("Elf");
		addOption("Snowman");
		addOption("Police");
		switch (getOption())
		{
		case 1: // The Pilot
			ResetAppearance();
			Modelo("HATS", 20, 0);
			Modelo("GLASSES", 6, 0);
			Modelo("TORSO", 16, 0);
			Modelo("LEGS", 30, 0);
			Modelo("HANDS", 39, 4);
			Modelo("SHOES", 24, 0);
			Modelo("SPECIAL2", 15, 0);
			Modelo("TORSO2", 48, 0);
			break;
		case 2: // The Strength
			ResetAppearance();
			Modelo("HATS", 40, 0);
			Modelo("MASK", 28, 0);
			Modelo("TORSO", 44, 0);
			Modelo("LEGS", 34, 0);
			Modelo("HANDS", 45, 0);
			Modelo("SHOES", 25, 0);
			Modelo("SPECIAL2", 56, 1);
			Modelo("TORSO2", 53, 0);
			break;
		case 3: // The Security
			ResetAppearance();
			Modelo("HATS", 7, 1);
			Modelo("GLASSES", 9, 6);
			Modelo("EARS", 1, 0);
			Modelo("TORSO", 4, 0);
			Modelo("LEGS", 26, 0);
			Modelo("SHOES", 24, 0);
			Modelo("SPECIAL2", 58, 0);
			Modelo("TORSO2", 53, 0);
			break;
		case 4: // The Families
			ResetAppearance();
			Modelo("HATS", 10, 5);
			Modelo("GLASSES", 17, 5);
			Modelo("MASK", 51, 5);
			Modelo("TORSO", 14, 0);
			Modelo("LEGS", 5, 6);
			Modelo("SHOES", 9, 10);
			Modelo("SPECIAL2", 23, 0);
			Modelo("TORSO2", 7, 6);
			break;
		case 5: // The Ballas
			ResetAppearance();
			Modelo("HATS", 10, 7);
			Modelo("GLASSES", 17, 6);
			Modelo("MASK", 51, 6);
			Modelo("TORSO", 14, 0);
			Modelo("LEGS", 5, 9);
			Modelo("SHOES", 9, 5);
			Modelo("SPECIAL2", 23, 0);
			Modelo("TORSO2", 7, 9);
			break;
		case 6: // The Thug
			ResetAppearance();
			Modelo("HATS", 46, 1);
			Modelo("GLASSES", 17, 6);
			Modelo("MASK", 51, 7);
			Modelo("TORSO", 22, 0);
			Modelo("LEGS", 7, 0);
			Modelo("HANDS", 44, 0);
			Modelo("SHOES", 12, 6);
			Modelo("SPECIAL2", 15, 0);
			Modelo("TORSO2", 14, 7);
			break;
		case 7: // The Santa
			ResetAppearance();
			Modelo("MASK", 8, 0);
			Modelo("TORSO", 12, 0);
			Modelo("LEGS", 19, 0);
			Modelo("SHOES", 4, 4);
			Modelo("SPECIAL1", 10, 0);
			Modelo("SPECIAL2", 21, 2);
			Modelo("TORSO2", 19, 0);
			break;
		case 8: // The Elf
			ResetAppearance();
			Modelo("MASK", 34, 0);
			Modelo("TORSO", 4, 0);
			Modelo("LEGS", 19, 1);
			Modelo("SHOES", 22, 1);
			Modelo("SPECIAL1", 18, 0);
			Modelo("SPECIAL2", 28, 8);
			Modelo("TORSO2", 19, 1);
			break;
		case 9: // The Snowman
			ResetAppearance();
			Modelo("MASK", 10, 0);
			Modelo("TORSO", 12, 0);
			Modelo("LEGS", 20, 0);
			Modelo("SHOES", 18, 1);
			Modelo("SPECIAL1", 24, 2);
			Modelo("SPECIAL2", 22, 4);
			Modelo("TORSO2", 25, 7);
			break;
		case 10: // The Cop
			ResetAppearance();
			Modelo("TORSO", 0, 0);
			Modelo("GLASSES", 6, 1);
			Modelo("LEGS", 35, 0);
			Modelo("SHOES", 25, 0);
			Modelo("SPECIAL2", 58, 0);
			Modelo("TORSO2", 55, 0);
			break;
		}
		break;
#pragma endregion
#pragma region Outfts Women
   case OutftsWomen:
		addTitle("Clothing Women");
		addOption("Pilot");
		addOption("Strength");
		addOption("Security");
		addOption("Biker");
		addOption("Business");
		addOption("Cop");
		addOption("Whore");
		switch (getOption())
		{
		case 1: // The Pilot
			ResetAppearance();
			Modelo("HATS", 20, 0);
			Modelo("GLASSES", 12, 1);
			Modelo("TORSO", 17, 0);
			Modelo("LEGS", 29, 0);
			Modelo("HANDS", 39, 4);
			Modelo("SHOES", 24, 0);
			Modelo("SPECIAL2", 2, 0);
			Modelo("TORSO2", 41, 0);
			break;
		case 2: // The Strength
			ResetAppearance();
			Modelo("HATS", 39, 0);
			Modelo("MASK", 28, 0);
			Modelo("TORSO", 36, 0);
			Modelo("LEGS", 33, 0);
			Modelo("HANDS", 45, 0);
			Modelo("SHOES", 25, 0);
			Modelo("SPECIAL2", 33, 1);
			Modelo("TORSO2", 46, 0);
			break;
		case 3: // The Security
			ResetAppearance();
			Modelo("HATS", 15, 0);
			Modelo("GLASSES", 12, 3);
			Modelo("EARS", 1, 0);
			Modelo("TORSO", 36, 0);
			Modelo("LEGS", 30, 0);
			Modelo("SHOES", 24, 0);
			Modelo("SPECIAL2", 35, 0);
			Modelo("TORSO2", 46, 0);
			break;
		case 4: // The Biker
			ResetAppearance();
			Modelo("HATS", 7, 0);
			Modelo("GLASSES", 12, 1);
			Modelo("TORSO", 23, 0);
			Modelo("LEGS", 27, 0);
			Modelo("SHOES", 7, 0);
			Modelo("SPECIAL2", 14, 0);
			Modelo("TORSO2", 55, 0);
			break;
		case 5: // The Business
			ResetAppearance();
			Modelo("GLASSES", 8, 5);
			Modelo("TORSO", 5, 0);
			Modelo("LEGS", 23, 0);
			Modelo("SHOES", 7, 3);
			Modelo("SPECIAL1", 6, 1);
			Modelo("SPECIAL2", 3, 0);
			Modelo("TORSO2", 57, 7);
			break;
		case 6: // The Cop
			ResetAppearance();
			Modelo("TORSO", 14, 0);
			Modelo("GLASSES", 12, 1);
			Modelo("LEGS", 34, 0);
			Modelo("SHOES", 25, 0);
			Modelo("SPECIAL2", 35, 0);
			Modelo("TORSO2", 48, 0);
			break;
		case 7: // The Whore
			ResetAppearance();
			Modelo("TORSO", 15, 0);
			Modelo("LEGS", 22, 2);
			Modelo("HAIRS", 4, 0);
			Modelo("SHOES", 14, 0);
			Modelo("SPECIAL1", 2, 0);
			Modelo("SPECIAL2", 2, 0);
			Modelo("TORSO2", 0, 16);
			break;
		}
		break;
#pragma endregion
#pragma region Weapon Editor
   case Weapon_Editor:
		addTitle("Weapon Editor");
		addBoolOption("Fire Gun", firegun);
	    addBoolOption("Shoot Cars", shhotcars_);
	    addBoolOption("Teleport Gun", _test);
	    addBoolOption("MoneyBag Gun", BulletBags);
	    addBoolOption("Predator Gun", predator);
	    addCharBOOLSwap("Rocket Gun", "Bullets", WeaponsMenu, &WeapVar, 0, 5, RocketGun);
		//addBoolOption("Aiming Laser", GrapGun);
		addBoolOption("Rainbow Cammo", rainbow);
		addBoolOption("Explosive Bullets", ExplosiveBullets);
	    switch (getOption())
	    {
        case 1: firegun = !firegun; break;
        case 2: shhotcars_ = !shhotcars_; break;
	    case 3: _test = !_test; break;
        case 4: BulletBags = !BulletBags; break;
	    case 5: predator = !predator; break;
		case 6:  RocketGun = !RocketGun; WeaponSHoot = "VEHICLE_WEAPON_PLAYER_LASER"; break;
		//case 8: GrapGun = !GrapGun; break; //CustomPRINT(GrapGun , "Aiming Laser"); break;
		case 7: rainbow = !rainbow;  break;
		case 8: ExplosiveBullets = !ExplosiveBullets; break;
		}
		break;
#pragma endregion
#pragma region Vehicle Options
   case Vehicle_Options:
		addTitle("Vehicle Options");
		addBoolOption("God Mode", GodModeVehicle);
		addBoolOption("Lower Ride", LowerWhip);
		addBoolOption("Hydraulics", pimpin);
		addBoolOption("Wheele Car", Wiiili);
		addBoolOption("Flying Car", FlyCar);
		addBoolOption("SpeedOMeter", SpeedOMeter);
		addBoolOption("No Collision;", hasNoCollision);
		addBoolOption("Drive on Air", MeinCode);
		addBoolOption("Drive on Water", MeinCodewat);
		addBoolOption("Invisible Vehicle", carinvstext);
		    addOption("Fix+Clean Vehicle");
		    addOption("Set Vehicle Upright");
			addOption("Max Upgrade Vehicle ");
	 addSubmenuOption("Los Santos Customs", Los_Santos_Customs);
	 addSubmenuOption("Vehicle Neons Menu", Neons);
	 addSubmenuOption("Vehicle Binds Menu", Vehicle_Binds);
	 addSubmenuOption("Vehicle Door Options", OpenShut_Doors);
	 addSubmenuOption("Other Vehicle Options", Other_Vehicle_Options);
		switch (getOption())
		{
		case 1:  GodModeVehicle = !GodModeVehicle; break;
		case 2: LowerWhip = !LowerWhip; break;
		case 3: pimpin = !pimpin; if (pimpin == true) { drawNotification("L3 TO USE ~b~HYDRAULICS"); } break;
		case 4: WWiiiliCar();
			    PRINT(Wiiili ? "Wheelie Car: ~b~Enabled~w~! \n~w~Do Wheelie with Left Stick" : "Wheelie Car: ~r~Disabled~w~!", 2000);
			    break;
		case 5: FlyCar = !FlyCar;
			    CustomPRINT(FlyCar, "Fly Car");
			    break;
		case 6: if(SpeedOMeter) { SpeedOMeter = false; drawNotification("Speed-o-Meter: ~r~Disabled"); } else { SpeedOMeter = true; drawNotification("Speed-o-Meter: ~g~Enabled"); } break;
		case 7: if(hasNoCollision)
				 {
					NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
					ENTITY::SET_ENTITY_COLLISION(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), true, true);
					drawNotification("Collision: ~r~Disabled");
					hasNoCollision = false;
				}
				else
				{
					NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
					ENTITY::SET_ENTITY_COLLISION(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), false, false);
					drawNotification("Collision: ~g~Enabled");
					hasNoCollision = true;
				}
		        break;
		case 8: DriveAir(); CustomPRINT(MeinCode, "Drive on Air"); break;
		case 9: DriveWater(); CustomPRINT(MeinCodewat, "Drive on Water"); break;
        case 10: if (carinvstext = !carinvstext)
				{
                NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
			    ENTITY::SET_ENTITY_VISIBLE(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), false);
				}
				else
				{
			    NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0));
			    ENTITY::SET_ENTITY_VISIBLE(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), true);
				}
		        break;
        case 11: VEHICLE::SET_VEHICLE_DIRT_LEVEL(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), 0), VEHICLE::SET_VEHICLE_FIXED(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID())); break;
        case 12: VEHICLE::SET_VEHICLE_ON_GROUND_PROPERLY(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID())); break;
		case 13: Maxupgrade(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()));break;
		}
		break;
#pragma endregion
#pragma region Los Santos Customs
   case Los_Santos_Customs:
		addTitle("Los Santos Customs");
	addSubmenuOption("Armor", Armor);
	addSubmenuOption("Engine", Engine);
	addSubmenuOption("Brakes", Armor);
	addSubmenuOption("Spoilers", Spoiler);
	addSubmenuOption("Side Skirt", Skirt);
	addSubmenuOption("Suspension", Suspension);
	addSubmenuOption("Transmission", Transmission);
    addSubmenuOption("Change Color", Paint_Vehicle);
		addIntOption("Change Plate Type", &platetype, 0, 5,true);
    addSubmenuOption("Tire Smoke Menu", Tire_Smoke);
		switch (getOption())
		{
        case 9: changeplate(platetype); break;
		}
		break;
#pragma endregion
#pragma region Armor
   case Armor:
		addTitle("Armor");
	    addOption("Level 1");
        addOption("Level 2");
		addOption("Level 3");
        addOption("Level 4");
		addOption("Level 5");
		int Armor = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
        switch (getOption())
		{
        case 1: VEHICLE::SET_VEHICLE_MOD_KIT(Armor, 0); VEHICLE::SET_VEHICLE_MOD(Armor, 16, 0, 0); drawNotification("Armor: ~b~Level 1"); break;
        case 2: VEHICLE::SET_VEHICLE_MOD_KIT(Armor, 0); VEHICLE::SET_VEHICLE_MOD(Armor, 16, 1, 0); drawNotification("Armor: ~b~Level 2");  break;
		case 3: VEHICLE::SET_VEHICLE_MOD_KIT(Armor, 0); VEHICLE::SET_VEHICLE_MOD(Armor, 16, 2, 0); drawNotification("Armor: ~b~Level 3"); break;
		case 4: VEHICLE::SET_VEHICLE_MOD_KIT(Armor, 0); VEHICLE::SET_VEHICLE_MOD(Armor, 16, 3, 0); drawNotification("Armor: ~b~Level 4"); break;
		case 5: VEHICLE::SET_VEHICLE_MOD_KIT(Armor, 0); VEHICLE::SET_VEHICLE_MOD(Armor, 16, 4, 0); drawNotification("Armor: ~b~Level 5");
		break;
		}
		break;
#pragma endregion
#pragma region Brakes
   case Brakes:
		addTitle("Brakes");
	    addOption("Stock");
        addOption("Street");
        addOption("Sports");
		addOption("Race");
		int Brakes = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
        switch (getOption())
		{
        case 1: VEHICLE::SET_VEHICLE_MOD_KIT(Brakes, 0); VEHICLE::REMOVE_VEHICLE_MOD(Brakes, 12); drawNotification("Brakes: ~b~Stock"); break;
        case 2: VEHICLE::SET_VEHICLE_MOD_KIT(Brakes, 0); VEHICLE::SET_VEHICLE_MOD(Brakes, 12, 0, 0); drawNotification("Brakes: ~b~Street"); break;
		case 3: VEHICLE::SET_VEHICLE_MOD_KIT(Brakes, 0); VEHICLE::SET_VEHICLE_MOD(Brakes, 12, 1, 0); drawNotification("Brakes: ~b~Sports"); break;
		case 4: VEHICLE::SET_VEHICLE_MOD_KIT(Brakes, 0); VEHICLE::SET_VEHICLE_MOD(Brakes, 12, 2, 0); drawNotification("Brakes: ~b~Race");
	    break;
		}
		break;
		#pragma endregion
#pragma region Spoiler
   case Spoiler:
		addTitle("Spoilers");
	    addOption("Stock");
        addOption("Street");
        addOption("Sports");
		addOption("Race");
		int Spoiler = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
        switch (getOption())
		{
		case 1: VEHICLE::SET_VEHICLE_MOD_KIT(Spoiler, 0); VEHICLE::SET_VEHICLE_MOD(Spoiler, 0, 0, 0); drawNotification("Spoiler: ~b~Spoiler 1"); break;
		case 2: VEHICLE::SET_VEHICLE_MOD_KIT(Spoiler, 0); VEHICLE::SET_VEHICLE_MOD(Spoiler, 0, 1, 0); drawNotification("Spoiler: ~b~Spoiler 2"); break;
		case 3: VEHICLE::SET_VEHICLE_MOD_KIT(Spoiler, 0); VEHICLE::SET_VEHICLE_MOD(Spoiler, 0, 2, 0); drawNotification("Spoiler: ~b~Spoiler 3"); break;
		case 4: VEHICLE::SET_VEHICLE_MOD_KIT(Spoiler, 0); VEHICLE::SET_VEHICLE_MOD(Spoiler, 0, 3, 0); drawNotification("Spoiler: ~b~Spoiler 4"); break;
		case 5: VEHICLE::SET_VEHICLE_MOD_KIT(Spoiler, 0); VEHICLE::SET_VEHICLE_MOD(Spoiler, 0, 4, 0); drawNotification("Spoiler: ~b~Spoiler 5"); break;
		case 6: VEHICLE::SET_VEHICLE_MOD_KIT(Spoiler, 0); VEHICLE::SET_VEHICLE_MOD(Spoiler, 0, 5, 0); drawNotification("Spoiler: ~b~Spoiler 6");
		break;
		}
		break;
		#pragma endregion
#pragma region Skirt
   case Skirt:
		addTitle("Side Skirts");
	    addOption("Skirts 1");
        addOption("Skirts 2");
        addOption("Skirts 3");
		addOption("Skirts 4");
		addOption("Skirts 5");
		addOption("Skirts 6");
		int Skirt = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
        switch (getOption())
		{
		case 1: VEHICLE::SET_VEHICLE_MOD_KIT(Skirt, 0); VEHICLE::SET_VEHICLE_MOD(Skirt, 3, 0, 0); drawNotification("Side Skirts: ~g~Skirts 1"); break;
		case 2: VEHICLE::SET_VEHICLE_MOD_KIT(Skirt, 0); VEHICLE::SET_VEHICLE_MOD(Skirt, 3, 1, 0); drawNotification("Side Skirts: ~g~Skirts 2"); break;
		case 3: VEHICLE::SET_VEHICLE_MOD_KIT(Skirt, 0); VEHICLE::SET_VEHICLE_MOD(Skirt, 3, 2, 0); drawNotification("Side Skirts: ~g~Skirts 3"); break;
		case 4: VEHICLE::SET_VEHICLE_MOD_KIT(Skirt, 0); VEHICLE::SET_VEHICLE_MOD(Skirt, 3, 3, 0); drawNotification("Side Skirts: ~g~Skirts 4"); break;
		case 5:	VEHICLE::SET_VEHICLE_MOD_KIT(Skirt, 0); VEHICLE::SET_VEHICLE_MOD(Skirt, 3, 4, 0); drawNotification("Side Skirts: ~g~Skirts 5"); break;
		case 6: VEHICLE::SET_VEHICLE_MOD_KIT(Skirt, 0); VEHICLE::SET_VEHICLE_MOD(Skirt, 3, 5, 0); drawNotification("Side Skirts: ~g~Skirts 6");
	    break;
		}
		break;
#pragma endregion
#pragma region Engine
   case Engine:
		addTitle("Engine");
	    addOption("Level 1");
        addOption("Level 2");
		addOption("Level 3");
        addOption("Level 4");
		int vehicleID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
        switch (getOption())
		{
        case 1: VEHICLE::SET_VEHICLE_MOD_KIT(vehicleID, 0); VEHICLE::SET_VEHICLE_MOD(vehicleID, 11, 0, 0); drawNotification("Engine: ~b~Level 1"); break;
        case 2: VEHICLE::SET_VEHICLE_MOD_KIT(vehicleID, 0); VEHICLE::SET_VEHICLE_MOD(vehicleID, 11, 1, 0); drawNotification("Engine: ~b~Level 2");  break;
		case 3: VEHICLE::SET_VEHICLE_MOD_KIT(vehicleID, 0); VEHICLE::SET_VEHICLE_MOD(vehicleID, 11, 2, 0); drawNotification("Engine: ~b~Level 3"); break;
		case 4: VEHICLE::SET_VEHICLE_MOD_KIT(vehicleID, 0); VEHICLE::SET_VEHICLE_MOD(vehicleID, 11, 3, 0); drawNotification("Engine: ~b~Level 4");
		break;
		}
		break;
#pragma endregion
#pragma region Suspension
   case Suspension:
		addTitle("Suspension");
	    addOption("Stock");
        addOption("Lowered");
		addOption("Street");
        addOption("Sports");
		addOption("Competition");
		int Suspen = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
        switch (getOption())
		{
		case 1: VEHICLE::SET_VEHICLE_MOD_KIT(Suspen, 0); VEHICLE::REMOVE_VEHICLE_MOD(Suspen, 15); drawNotification("Suspension: ~b~Stock"); break;
		case 2: VEHICLE::SET_VEHICLE_MOD_KIT(Suspen, 0); VEHICLE::SET_VEHICLE_MOD(Suspen, 15, 0, 0); drawNotification("Suspension: ~b~Lowered"); break;
		case 3: VEHICLE::SET_VEHICLE_MOD_KIT(Suspen, 0); VEHICLE::SET_VEHICLE_MOD(Suspen, 15, 1, 0); drawNotification("Suspension: ~b~Street"); break;
		case 4: VEHICLE::SET_VEHICLE_MOD_KIT(Suspen, 0); VEHICLE::SET_VEHICLE_MOD(Suspen, 15, 2, 0); drawNotification("Suspension: ~b~Sports"); break;
		case 5: VEHICLE::SET_VEHICLE_MOD_KIT(Suspen, 0); VEHICLE::SET_VEHICLE_MOD(Suspen, 15, 3, 0); drawNotification("Suspension: ~b~Competition");
		break;
		}
		break;
#pragma endregion
#pragma region Transmission
   case Transmission:
		addTitle("Transmission");
	    addOption("Stock");
        addOption("Street");
        addOption("Sports");
		addOption("Race");
		int Trans = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
        switch (getOption())
		{
        case 1: VEHICLE::SET_VEHICLE_MOD_KIT(Trans, 0); VEHICLE::REMOVE_VEHICLE_MOD(Trans, 13); drawNotification("Transmission: ~b~Stock"); break;
        case 2: VEHICLE::SET_VEHICLE_MOD_KIT(Trans, 0); VEHICLE::SET_VEHICLE_MOD(Trans, 13, 0, 0); drawNotification("Transmission: ~b~Street");  break;
		case 3: VEHICLE::SET_VEHICLE_MOD_KIT(Trans, 0); VEHICLE::SET_VEHICLE_MOD(Trans, 13, 1, 0); drawNotification("Transmission: ~b~Sports"); break;
		case 4: VEHICLE::SET_VEHICLE_MOD_KIT(Trans, 0); VEHICLE::SET_VEHICLE_MOD(Trans, 13, 2, 0); drawNotification("Transmission: ~b~Race");
		break;
		}
		break;
#pragma endregion
#pragma region Paint Vehicle
   case Paint_Vehicle:
		addTitle("Change Color");
		addIntOption("Change Color Red", &redcolor, 0, 255, true);
		addIntOption("Change Color Green", &greencolor, 0, 255, true);
		addIntOption("Change Color Blue", &bluecolor, 0, 255, true);
		addIntOption("Change Pearl color", &Pearlescant, 0, 255, true);
		addOption("Apply Primary Color");
		addOption("Apply Secondary Color");
		addOption("Apply Pearl Color");
		addOption("Apply Chrome");
		addOption("Apply Gold");
		addOption("Apply Aluminum");
		addOption("Apply Black Steel");
		addOption("Apply Epsilon Blue"); //157
		addOption("Matte Purple Blue Pearl");
		int VEHICLE = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
		switch (getOption())
		{
		case 5: VEHICLE::SET_VEHICLE_CUSTOM_PRIMARY_COLOUR(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), redcolor, greencolor, bluecolor); break;
		case 6: VEHICLE::SET_VEHICLE_CUSTOM_SECONDARY_COLOUR(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), redcolor, greencolor, bluecolor); break;
		case 7: VEHICLE::SET_VEHICLE_EXTRA_COLOURS(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), Pearlescant, RimColor); break; //RimColor
		case 8: VEHICLE::SET_VEHICLE_MOD_KIT(VEHICLE, 0); VEHICLE::SET_VEHICLE_COLOURS(VEHICLE, 120, 120); drawNotification("Color: ~b~Chrome"); break;
		case 9: VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(VEHICLE); VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(VEHICLE); VEHICLE::SET_VEHICLE_MOD_KIT(VEHICLE, 0); VEHICLE::SET_VEHICLE_COLOURS(VEHICLE, 37, 37); drawNotification("Color: ~b~Gold"); break;
		case 10: VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(VEHICLE); VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(VEHICLE); VEHICLE::SET_VEHICLE_MOD_KIT(VEHICLE, 0); VEHICLE::SET_VEHICLE_COLOURS(VEHICLE, 119, 119); drawNotification("Color: ~b~Aluminum"); break;
		case 11: VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(VEHICLE); VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(VEHICLE); VEHICLE::SET_VEHICLE_MOD_KIT(VEHICLE, 0); VEHICLE::SET_VEHICLE_COLOURS(VEHICLE, 118, 118); drawNotification("Color: ~b~Black Steel"); break;
		case 12: VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(VEHICLE); VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(VEHICLE); VEHICLE::SET_VEHICLE_MOD_KIT(VEHICLE, 0); VEHICLE::SET_VEHICLE_COLOURS(VEHICLE, 157, 157 ); drawNotification("Color: ~b~Epsilon Blue"); break;
		case 13: VEHICLE::CLEAR_VEHICLE_CUSTOM_PRIMARY_COLOUR(VEHICLE); 
			    VEHICLE::CLEAR_VEHICLE_CUSTOM_SECONDARY_COLOUR(VEHICLE); 
				VEHICLE::SET_VEHICLE_MOD_KIT(VEHICLE, 0); 
				VEHICLE::SET_VEHICLE_COLOURS(VEHICLE, 148, 148);
				VEHICLE::SET_VEHICLE_EXTRA_COLOURS(VEHICLE, 140, 0); //Flourescent Blue 
				//VEHICLE::SET_VEHICLE_EXTRA_COLOURS(VEHICLE, 80, 0);//Matte Purple Blue Pearl
				//drawNotification("Color: ~b~Gold"); break;
		}
		break;
#pragma endregion
#pragma region Other Vehicle Options
   case Other_Vehicle_Options:
		addTitle("Other Vehicle Options");
	    addBoolOption("High Beams", HeadLights);
		addBoolOption("Interior Light", InteriorLights);
		addBoolOption01("", TurnSignalLeft);
		addBoolOption02("", TurnSignalRight);
		switch (getOption())
		{
		case 1:  HeadLights = !HeadLights; break;
		case 2:  InteriorLights = !InteriorLights; break;
		case 3:  TurnSignalLeft = !TurnSignalLeft; break;
		case 4:  TurnSignalRight = !TurnSignalRight; break;		
		}
		break;
#pragma endregion
#pragma region Open/Shut Doors
   case OpenShut_Doors:
		addTitle("Door Options");
		addIntOption("Power Window Down", &vehwindow, 0, 6, true);
		addIntOption("Power Window Up", &vehwindow, 0, 6, true);
		addIntOption("Open Vehicle Door", &vehdoor, 0, 6, true);
		addOption("Shut Vehicle Doors");
		switch (getOption())
		{
		case 1: VEHICLE::ROLL_DOWN_WINDOW(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), vehwindow); break;
		case 2: VEHICLE::ROLL_UP_WINDOW(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), vehwindow); break;
		case 3: VEHICLE::SET_VEHICLE_DOOR_OPEN(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), vehdoor, 0, 1); break;
		case 4: VEHICLE::SET_VEHICLE_DOORS_SHUT(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), vehdoor); break;		
		}
        break;
#pragma endregion
#pragma region Vehicle_Weapons
   case Vehicle_Weapons:
		addTitle("Vehicle Weapons");
		addBoolOption("Vehicle Weapons", VehEap);
	    addOption("Change To RPG");
	    addOption("Change To TANK");
	    addOption("Change To HUNTER");
	    addOption("Change To FIREWORKS");
	    addOption("Change To RED LAZER");
	    addOption("Change To GREEN LAZER");
	    switch (getOption())
	    {
	    case 1: VehEap = !VehEap; if (VehEap) { drawNotification("Vehicles Weapons On\n L3 To Shoot"); } break;
        case 2: featureWeaponAsset = "WEAPON_RPG"; break;
	    case 3: featureWeaponAsset = "VEHICLE_WEAPON_TANK"; break;
	    case 4: featureWeaponAsset = "VEHICLE_WEAPON_PLAYER_HUNTER"; break;
        case 5: featureWeaponAsset = "WEAPON_FIREWORK"; break;
	    case 6: featureWeaponAsset = "VEHICLE_WEAPON_ENEMY_LASER"; break;
	    case 7: featureWeaponAsset = "VEHICLE_WEAPON_PLAYER_LASER"; break;
	    }
		break;
#pragma endregion
#pragma region traffic options 
   case traffic_options:
		addTitle("Traffic");
		addBoolOption("Force Traffic", ForceTest);
		addBoolOption("Tuned Traffic", TuneArea2);
		addBoolOption("Boost Traffic", BoostAreaCar);
		addBoolOption("Lowrider Traffic", Buny);
		addBoolOption("Gravity", Graviiii);
		addBoolOption("Jumping Cars", Bunnycars);
		//addBoolOption("Weird Car", KAAAA);
		switch (getOption())
		{
		case 1: ForceTest = !ForceTest; PRINT(ForceTest ? "Force Traffic: ~b~Enabled~w~!\nActivate the Froce with Square!" : "Force Traffic:~r~ Disabled~w~!", 2000); break;
		case 2: TuneArea2 = !TuneArea2; PRINT(TuneArea2 ? "Tuned Traffic: ~b~Enabled~w~!" : "Tuned Traffic: ~r~Disabled~w~!", 2000); break;
		case 3: BoostAreaCar = !BoostAreaCar; PRINT(BoostAreaCar ? "Boost Traffic: ~b~Enabled~w~!\nBoost with R1" : "Boost Traffic: ~r~Disabled~w~!", 2000); break;
		case 4: Buny = !Buny; PRINT(Buny ? "Lowrider Traffic: ~b~Enabled~w~!" : "Lowrider Traffic: ~r~Disabled~w~!", 2000); break;
		case 5: Graviiii = !Graviiii; PRINT(Graviiii ? "Traffic have no Gravity!" : "Gravity Restored!", 2000); break;
		case 6:	Bunnycars = !Bunnycars; break;
		//case 7: CarForceMod(); break;
		}
		break;
#pragma endregion
#pragma region Spawn_Vehicle 
   case Spawn_Vehicle:
		addTitle("Spawn Vehicle");
		addSubmenuOption("Super Cars", Super_Cars);
		addSubmenuOption("Sports Cars", Sports_Cars);
		addSubmenuOption("Heist Cars", Heist_);
		addSubmenuOption("Motorcycles", MotorcyclesBicycles_);
		addSubmenuOption("Helicopters/Planes", HelicoptersPlanes_);
		addSubmenuOption("Boats", Boats_);
		addSubmenuOption("All Vehicle",All_Vehicle);
		addSubmenuOption("Modded Vehicles", Modded_Vehicles);
        break;
#pragma endregion
#pragma region Super Cars
   case Super_Cars:
		addTitle("Super Cars");
		addVehOption("Adder", "adder", "Spawned: Adder");
		addVehOption("Zentorno", "zentorno", "Spawned: Zentorno");
		addVehOption("Bullet", "bullet", "Spawned: Bullet");
		addVehOption("Obey 9F", "ninef", "Spawned: Obey 9F");
		addVehOption("T20", "t20", "Spawned: T20");
		addVehOption("Cheetah", "cheetah", "Spawned: Cheetah");
		addVehOption("Entity XF", "ENTITYXF", "Spawned: Entity XF");
		addVehOption("Infernus", "infernus", "Spawned: Infernus");
		addVehOption("Osiris", "osiris", "Spawned: Osiris");
		addVehOption("Turismo", "turismor", "Spawned: Turismo");
		addVehOption("Vacca", "vacca", "Spawned: Vacca");
		addVehOption("faggio", "faggio2", "Spawned: faggio");
        break;
#pragma endregion
#pragma region Sports_Cars
   case Sports_Cars:
		addTitle("Sports Cars");
		addVehOption("Obey 9F", "ninef", "Obey 9F");
        addVehOption("Rapid GT", "rapidgt", "Spawned: Rapid GT");
		addVehOption("Furore GT", "furoregt", "Spawned: Furore GT");
		addVehOption("Massacro", "massacro", "Spawned: Massacro");
		addVehOption("Elegy RH8", "elegy2", "Spawned: Elegy RH8");
		addVehOption("Alpha", "alpha", "Spawned: Alpha");
		addVehOption("Carbonizzare", "carbonizzare", "Spawned: Carbonizzare");
		addVehOption("Coquette", "coquette", "Spawned: Coquette");
		addVehOption("Jester", "jester", "Spawned: Jester");
		addVehOption("Comet", "comet2", "Spawned: Comet");
		addVehOption("Feltzer", "feltzer2", "Spawned: Feltzer");
		addVehOption("Khamelion", "khamelion", "Spawned: Khamelion");
		addVehOption("Sultan RS", "SULTAN", "Spawned: Sultan RS");
        break;
#pragma endregion
#pragma region Heist_
   case Heist_:
		addTitle("Heist Cars");
		addVehOption("Enduro", "enduro", "Spawned: Enduro");
		addVehOption("Guardian", "guardian", "Spawned: Guardian");
		addVehOption("Kuruma", "kuruma", "Spawned: Kuruma");
		addVehOption("Armored Kuruma", "kuruma2", "Spawned: Armored Kuruma");
		addVehOption("Casco", "casco", "Spawned: Casco");
		addVehOption("Seater Velum", "velum2", "Spawned: Seater Velum");
		addVehOption("Hydra", "hydra", "Spawned: Hydra");
		addVehOption("Insurgent", "insurgent", "Spawned: Insurgent");
		addVehOption("Insurgent Pick-Up", "insurgent2", "Spawned: Insurgent Pick-Up");
		addVehOption("Valkyrie", "valkyrie", "Spawned: Valkyrie");
		addVehOption("Technical", "technical", "Spawned: Technical");
		addVehOption("Savage", "savage", "Spawned: Savage");
		addVehOption("Lectro", "lectro", "Spawned: Lectro");
		addVehOption("Lost Slamvan", "slamvan2", "Spawned: Lost Slamvan");
		addVehOption("Brawler", "brawler", "Spawned: Brawler");
        break;
#pragma endregion
#pragma region MotorcyclesBicycles_
   case MotorcyclesBicycles_:
		addTitle("Motorcycles");
		addVehOption("Akuma", "akuma", "Spawned: Akuma");
		addVehOption("Bati 801RR", "bati2", "Spawned: Bati 801RR");
		addVehOption("Carbon RS", "carbonrs", "Spawned: Carbon RS");
		addVehOption("Daemon", "daemon", "Spawned: Daemon");
		addVehOption("Faggio", "faggio2", "Spawned: Faggio");
		addVehOption("Hakuchou", "hakuchou", "Spawned: Hakuchou");
		addVehOption("Sanchez", "sanchez", "Spawned: Sanchez");
		addVehOption("Double T", "double", "Spawned: Double T");
		addVehOption("Innovation", "innovation", "Spawned: Innovation");
		addVehOption("Thrust", "thrust", "Spawned: Thrust");
		addVehOption("Sovereign", "sovereign", "Spawned: Sovereign");
		addVehOption("Nemesis", "nemesis", "Spawned: Nemesis");
        break;
#pragma endregion
#pragma region HelicoptersPlanes_
   case HelicoptersPlanes_:
		addTitle("Helis/Planes");
		addVehOption("Annihilator", "annihilator", "Spawned: Annihilator");
		addVehOption("Buzzard", "buzzard", "Spawned: Buzzard");
		addVehOption("Buzzard2", "Buzzard2", "Spawned: Buzzard2");
		addVehOption("Blimp", "Blimp", "Spawned: Blimp");
		addVehOption("Cargobob", "cargobob", "Spawned: Cargobob");
		addVehOption("Cargobob2", "Cargobob2", "Spawned: Cargobob2");
		addVehOption("Cargobob3", "Cargobob3", "Spawned: Cargobob3");
		addVehOption("Maverick", "maverick", "Spawned: Maverick");
		addVehOption("Skylift", "skylift", "Spawned: Skylift");
		addVehOption("Trevor's Cargobob", "cargobob3", "Spawned: Trevor's Cargobob");
		addVehOption("Mammatus", "mammatus", "Spawned: Mammatus");
		addVehOption("Luxor", "luxor", "Spawned: Luxor");
		addVehOption("Lazer", "lazer", "Spawned: Lazer");
		addVehOption("Miljet", "miljet", "Spawned: Miljet");
		addVehOption("Titan", "titan", "Spawned: Titan");
		addVehOption("Vestra", "vestra", "Spawned: Vestra");
		addVehOption("Mallard", "stunt", "Spawned: Mallard");
        break;
#pragma endregion
#pragma region Boats_
   case Boats_:
		addTitle("Boats");
		addVehOption("Dinghy", "Dinghy", "Spawned: Dinghy");
		addVehOption("Dinghy2", "Dinghy2", "Spawned: Dinghy2");
		addVehOption("Jetmax", "Jetmax", "Spawned: Jetmax");
		addOption("");
		addOption("");
		addOption("");
		addOption("");
		addOption("");
		addOption("");
		addOption("");
        break;
#pragma endregion
#pragma region All_Vehicle
   case All_Vehicle:
		addTitle("Every Vehicle");
		addVehOption("Adder", "Adder", "Spawned: Adder");
		addVehOption("Airbus", "Airbus", "Spawned: Airbus");
		addVehOption("Airtug", "Airtug", "Spawned: Airtug");
		addVehOption("Akuma", "Akuma", "Spawned: Akuma");
		addVehOption("Alpha", "Alpha", "Spawned: Alpha");
		addVehOption("Ambulance", "Ambulance", "Spawned: Ambulance");
		addVehOption("Annihilator", "Annihilator", "Spawned: Annihilator");
		addVehOption("Armytanker", "Armytanker", "Spawned: Armytanker");
		addVehOption("Armytrailer", "Armytrailer", "Spawned: Armytrailer");
		addVehOption("Armytrailer2", "Armytrailer2", "Spawned: Armytrailer2");
		addVehOption("Asea", "Asea", "Spawned: Asea");
		addVehOption("Asea2", "Asea2", "Spawned: Asea2");
		addVehOption("Asterope", "Asterope", "Spawned: Asterope");
		addVehOption("Bagger", "Bagger", "Spawned: Bagger");
		addVehOption("Baletrailer", "Baletrailer", "Spawned: Baletrailer");
		addVehOption("Baller", "Baller", "Spawned: Baller");
		addVehOption("Baller2", "Baller2", "Spawned: Baller2");
		addVehOption("Banshee", "Banshee", "Spawned: Banshee");
		addVehOption("Barracks", "Barracks", "Spawned: Barracks");
		addVehOption("Barracks2", "Barracks2", "Spawned: Barracks2");
		addVehOption("Bati", "Bati", "Spawned: Bati");
		addVehOption("Bati2", "Bati2", "Spawned: Bati2");
		addVehOption("Benson", "Benson", "Spawned: Benson");
		addVehOption("Bfinjection", "Bfinjection", "Spawned: Bfinjection");
		addVehOption("Biff", "Biff", "Spawned: Biff");
		addVehOption("Bifta", "Bifta", "Spawned: Bifta");
		addVehOption("Bison", "Bison", "Spawned: Bison");
		addVehOption("Bison2", "Bison2", "Spawned: Bison2");
		addVehOption("Bison3", "Bison3", "Spawned: Bison3");
		addVehOption("Bjxl", "Bjxl", "Spawned: Bjxl");
		addVehOption("Blade", "Blade", "Spawned: Blade");
		addVehOption("Blazer", "Blazer", "Spawned: Blazer");
		addVehOption("Blazer2", "Blazer2", "Spawned: Blazer2");
		addVehOption("Blazer3", "Blazer3", "Spawned: Blazer3");
		addVehOption("Blimp", "Blimp", "Spawned: Blimp");
		addVehOption("Blista", "Blista", "Spawned: Blista");
		addVehOption("Blista2", "Blista2", "Spawned: Blista2");
		addVehOption("Blista3", "Blista3", "Spawned: Blista3");
		addVehOption("Bmx", "Bmx", "Spawned: Bmx");
		addVehOption("Boattrailer", "Boattrailer", "Spawned: Boattrailer");
		addVehOption("Bobcatxl", "Bobcatxl", "Spawned: Bobcatxl");
		addVehOption("Bodhi2", "Bodhi2", "Spawned: Bodhi2");
		addVehOption("Boxville", "Boxville", "Spawned: Boxville");
		addVehOption("Boxville2", "Boxville2", "Spawned: Boxville2");
		addVehOption("Boxville3", "Boxville3", "Spawned: Boxville3");
		addVehOption("Btype", "Btype", "Spawned: Btype");
		addVehOption("Buccaneer", "Buccaneer", "Spawned: Buccaneer");
		addVehOption("Buffalo", "Buffalo", "Spawned: Buffalo");
		addVehOption("Buffalo2", "Buffalo2", "Spawned: Buffalo2");
		addVehOption("Buffalo3", "Buffalo3", "Spawned: Buffalo3");
		addVehOption("Bulldozer", "Bulldozer", "Spawned: Bulldozer");
		addVehOption("Bullet", "Bullet", "Spawned: Bullet");
		addVehOption("Burrito", "Burrito", "Spawned: Burrito");
		addVehOption("Burrito2", "Burrito2", "Spawned: Burrito2");
		addVehOption("Burrito3", "Burrito3", "Spawned: Burrito3");
		addVehOption("Burrito4", "Burrito4", "Spawned: Burrito4");
		addVehOption("Burrito5", "Burrito5", "Spawned: Burrito5");
		addVehOption("Bus", "Bus", "Spawned: Bus");
		addVehOption("Buzzard", "Buzzard", "Spawned: Buzzard");
		addVehOption("Buzzard2", "Buzzard2", "Spawned: Buzzard2");
		addVehOption("Cablecar", "Cablecar", "Spawned: Cablecar");
		addVehOption("Caddy", "Caddy", "Spawned: Caddy");
		addVehOption("Caddy2", "Caddy2", "Spawned: Caddy2");
		addVehOption("Camper", "Camper", "Spawned: Camper");
		addVehOption("Carbonizzare", "Carbonizzare", "Spawned: Carbonizzare");
		addVehOption("Carbonrs", "Carbonrs", "Spawned: Carbonrs");
		addVehOption("Cargobob", "Cargobob", "Spawned: Cargobob");
		addVehOption("Cargobob2", "Cargobob2", "Spawned: Cargobob2");
		addVehOption("Cargobob3", "Cargobob3", "Spawned: Cargobob3");
		addVehOption("Cargoplane", "Cargoplane", "Spawned: Cargoplane");
		addVehOption("Casco", "Casco", "Spawned: Casco");
		addVehOption("Cavalcade", "Cavalcade", "Spawned: Cavalcade");
		addVehOption("Cavalcade2", "Cavalcade2", "Spawned: Cavalcade2");
		addVehOption("Cheetah", "Cheetah", "Spawned: Cheetah");
		addVehOption("Coach", "Coach", "Spawned: Coach");
		addVehOption("Cogcabrio", "Cogcabrio", "Spawned: Cogcabrio");
		addVehOption("Comet2", "Comet2", "Spawned: Comet2");
		addVehOption("Coquette", "Coquette", "Spawned: Coquette");
		addVehOption("Coquette2", "Coquette2", "Spawned: Coquette2");
		addVehOption("Cruiser", "Cruiser", "Spawned: Cruiser");
		addVehOption("Crusader", "Crusader", "Spawned: Crusader");
		addVehOption("Cuban800", "Cuban800", "Spawned: Cuban800");
		addVehOption("Cutter", "Cutter", "Spawned: Cutter");
		addVehOption("Daemon", "Daemon", "Spawned: Daemon");
		addVehOption("Dilettante", "Dilettante", "Spawned: Dilettante");
		addVehOption("Dilettante2", "Dilettante2", "Spawned: Dilettante2");
		addVehOption("Dinghy", "Dinghy", "Spawned: Dinghy");
		addVehOption("Dinghy2", "Dinghy2", "Spawned: Dinghy2");
		addVehOption("Dloader", "Dloader", "Spawned: Dloader");
		addVehOption("Docktug", "Docktug", "Spawned: Docktug");
		addVehOption("Dodo", "Dodo", "Spawned: Dodo");
		addVehOption("Dominator", "Dominator", "Spawned: Dominator");
		addVehOption("Dominator2", "Dominator2", "Spawned: Dominator2");
		addVehOption("Double", "Double", "Spawned: Double");
		addVehOption("Dubsta", "Dubsta", "Spawned: Dubsta");
		addVehOption("Dubsta2", "Dubsta2", "Spawned: Dubsta2");
		addVehOption("Dubsta3", "Dubsta3", "Spawned: Dubsta3");
		addVehOption("Dukes", "Dukes", "Spawned: Dukes");
		addVehOption("Dukes2", "Dukes2", "Spawned: Dukes2");
		addVehOption("Dump", "Dump", "Spawned: Dump");
		addVehOption("Dune", "Dune", "Spawned: Dune");
		addVehOption("Dune2", "Dune2", "Spawned: Dune2");
		addVehOption("Duster", "Duster", "Spawned: Duster");
		addVehOption("Elegy2", "Elegy2", "Spawned: Elegy2");
		addVehOption("Emperor", "Emperor", "Spawned: Emperor");
		addVehOption("Emperor2", "Emperor2", "Spawned: Emperor2");
		addVehOption("Emperor3", "Emperor3", "Spawned: Emperor3");
		addVehOption("Enduro", "Enduro", "Spawned: Enduro");
		addVehOption("Entityxf", "Entityxf", "Spawned: Entityxf");
		addVehOption("Exemplar", "Exemplar", "Spawned: Exemplar");
		addVehOption("F620", "F620", "Spawned: F620");
		addVehOption("Faggio2", "Faggio2", "Spawned: Faggio2");
		addVehOption("Fbi", "Fbi", "Spawned: Fbi");
		addVehOption("Fbi2", "Fbi2", "Spawned: Fbi2");
		addVehOption("Felon", "Felon", "Spawned: Felon");
		addVehOption("Felon2", "Felon2", "Spawned: Felon2");
		addVehOption("Feltzer2", "Feltzer2", "Spawned: Feltzer2");
		addVehOption("Firetruk", "Firetruk", "Spawned: Firetruk");
		addVehOption("Fixter", "Fixter", "Spawned: Fixter");
		addVehOption("Flatbed", "Flatbed", "Spawned: Flatbed");
		addVehOption("Forklift", "Forklift", "Spawned: Forklift");
		addVehOption("Fq2", "Fq2", "Spawned: Fq2");
		addVehOption("Frogger", "Frogger", "Spawned: Frogger");
		addVehOption("Frogger2", "Frogger2", "Spawned: Frogger2");
		addVehOption("Fugitive", "Fugitive", "Spawned: Fugitive");
		addVehOption("Furoregt", "Furoregt", "Spawned: Furoregt");
		addVehOption("Fusilade", "Fusilade", "Spawned: Fusilade");
		addVehOption("Futo", "Futo", "Spawned: Futo");
		addVehOption("Gauntlet", "Gauntlet", "Spawned: Gauntlet");
		addVehOption("Gauntlet2 ", "Gauntlet2 ", "Spawned: Gauntlet2 ");
		addVehOption("Gburrito", "Gburrito", "Spawned: Gburrito");
		addVehOption("Glendale", "Glendale", "Spawned: Glendale");
		addVehOption("Graintrailer", "Graintrailer", "Spawned: Graintrailer");
		addVehOption("Granger", "Granger", "Spawned: Granger");
		addVehOption("Gresley", "Gresley", "Spawned: Gresley");
		addVehOption("Guardian", "Guardian", "Spawned: Guardian");
		addVehOption("Habanero", "Habanero", "Spawned: Habanero");
		addVehOption("Hakuchou", "Hakuchou", "Spawned: Hakuchou");
		addVehOption("Handler", "Handler", "Spawned: Handler");
		addVehOption("Hauler", "Hauler", "Spawned: Hauler");
		addVehOption("Hexer", "Hexer", "Spawned: Hexer");
		addVehOption("Hotknife", "Hotknife", "Spawned: Hotknife");
		addVehOption("Huntley", "Huntley", "Spawned: Huntley");
		addVehOption("Hydra ", "Hydra ", "Spawned: Hydra ");
		addVehOption("Infernus", "Infernus", "Spawned: Infernus");
		addVehOption("Ingot", "Ingot", "Spawned: Ingot");
		addVehOption("Innovation", "Innovation", "Spawned: Innovation");
		addVehOption("Insurgent", "Insurgent", "Spawned: Insurgent");
		addVehOption("Insurgent2", "Insurgent2", "Spawned: Insurgent2");
		addVehOption("Intruder", "Intruder", "Spawned: Intruder");
		addVehOption("Issi2", "Issi2", "Spawned: Issi2");
		addVehOption("Jackal", "Jackal", "Spawned: Jackal");
		addVehOption("Jb700", "Jb700", "Spawned: Jb700");
		addVehOption("Jester", "Jester", "Spawned: Jester");
		addVehOption("Jester2", "Jester2", "Spawned: Jester2");
		addVehOption("Jet", "Jet", "Spawned: Jet");
		addVehOption("Jetmax", "Jetmax", "Spawned: Jetmax");
		addVehOption("Journey", "Journey", "Spawned: Journey");
		addVehOption("Kalahari", "Kalahari", "Spawned: Kalahari");
		addVehOption("Khamelion", "Khamelion", "Spawned: Khamelion");
		addVehOption("Kuruma", "Kuruma", "Spawned: Kuruma");
		addVehOption("Kuruma2", "Kuruma2", "Spawned: Kuruma2");
		addVehOption("Landstalker", "Landstalker", "Spawned: Landstalker");
		addVehOption("Lazer", "Lazer", "Spawned: Lazer");
		addVehOption("Lectro", "Lectro", "Spawned: Lectro");
		addVehOption("Lguard", "Lguard", "Spawned: Lguard");
		addVehOption("Luxor", "Luxor", "Spawned: Luxor");
		addVehOption("Mammatus", "Mammatus", "Spawned: Mammatus");
		addVehOption("Manana", "Manana", "Spawned: Manana");
		addVehOption("Marquis", "Marquis", "Spawned: Marquis");
		addVehOption("Marshall", "Marshall", "Spawned: Marshall");
		addVehOption("Massacro ", "Massacro ", "Spawned: Massacro ");
		addVehOption("Massacro2", "Massacro2", "Spawned: Massacro2");
		addVehOption("Maverick", "Maverick", "Spawned: Maverick");
		addVehOption("Mesa", "Mesa", "Spawned: Mesa");
		addVehOption("Mesa2", "Mesa2", "Spawned: Mesa2");
		addVehOption("Mesa3", "Mesa3", "Spawned: Mesa3");
		addVehOption("Miljet", "Miljet", "Spawned: Miljet");
		addVehOption("Minivan", "Minivan", "Spawned: Minivan");
		addVehOption("Mixer", "Mixer", "Spawned: Mixer");
		addVehOption("Mixer2", "Mixer2", "Spawned: Mixer2");
		addVehOption("Monroe", "Monroe", "Spawned: Monroe");
		addVehOption("Monster ", "Monster ", "Spawned: Monster ");
		addVehOption("Mower", "Mower", "Spawned: Mower");
		addVehOption("Mule", "Mule", "Spawned: Mule");
		addVehOption("Mule2", "Mule2", "Spawned: Mule2");
		addVehOption("Nemesis", "Nemesis", "Spawned: Nemesis");
		addVehOption("Ninef", "Ninef", "Spawned: Ninef");
		addVehOption("Ninef2", "Ninef2", "Spawned: Ninef2");
		addVehOption("Oracle", "Oracle", "Spawned: Oracle");
		addVehOption("Oracle2", "Oracle2", "Spawned: Oracle2");
		addVehOption("Packer", "Packer", "Spawned: Packer");
		addVehOption("Panto", "Panto", "Spawned: Panto");
		addVehOption("Paradise", "Paradise", "Spawned: Paradise");
		addVehOption("Patriot", "Patriot", "Spawned: Patriot");
		addVehOption("Pbus", "Pbus", "Spawned: Pbus");
		addVehOption("Pcj", "Pcj", "Spawned: Pcj");
		addVehOption("Penumbra", "Penumbra", "Spawned: Penumbra");
		addVehOption("Peyote", "Peyote", "Spawned: Peyote");
		addVehOption("Phantom", "Phantom", "Spawned: Phantom");
		addVehOption("Phoenix", "Phoenix", "Spawned: Phoenix");
		addVehOption("Picador", "Picador", "Spawned: Picador");
		addVehOption("Pigalle", "Pigalle", "Spawned: Pigalle");
		addVehOption("Police", "Police", "Spawned: Police");
		addVehOption("Police2", "Police2", "Spawned: Police2");
		addVehOption("Police3", "Police3", "Spawned: Police3");
		addVehOption("Police4", "Police4", "Spawned: Police4");
		addVehOption("Policeb", "Policeb", "Spawned: Policeb");
		addVehOption("Policeold1", "Policeold1", "Spawned: Policeold1");
		addVehOption("Policeold2", "Policeold2", "Spawned: Policeold2");
		addVehOption("Policet", "Policet", "Spawned: Policet");
		addVehOption("Polmav", "Polmav", "Spawned: Polmav");
		addVehOption("Pony", "Pony", "Spawned: Pony");
		addVehOption("Pony2", "Pony2", "Spawned: Pony2");
		addVehOption("Pounder", "Pounder", "Spawned: Pounder");
		addVehOption("Prairie", "Prairie", "Spawned: Prairie");
		addVehOption("Pranger", "Pranger", "Spawned: Pranger");
		addVehOption("Predator", "Predator", "Spawned: Predator");
		addVehOption("Premier", "Premier", "Spawned: Premier");
		addVehOption("Primo", "Primo", "Spawned: Primo");
		addVehOption("Proptrailer", "Proptrailer", "Spawned: Proptrailer");
		addVehOption("Radi", "Radi", "Spawned: Radi");
		addVehOption("Raketrailer", "Raketrailer", "Spawned: Raketrailer");
		addVehOption("Rancherxl", "Rancherxl", "Spawned: Rancherxl");
		addVehOption("Rancherxl2", "Rancherxl2", "Spawned: Rancherxl2");
		addVehOption("Rapidgt", "Rapidgt", "Spawned: Rapidgt");
		addVehOption("Rapidgt2", "Rapidgt2", "Spawned: Rapidgt2");
		addVehOption("Ratloader", "Ratloader", "Spawned: Ratloader");
		addVehOption("Ratloader2", "Ratloader2", "Spawned: Ratloader2");
		addVehOption("Rebel", "Rebel", "Spawned: Rebel");
		addVehOption("Rebel2", "Rebel2", "Spawned: Rebel2");
		addVehOption("Regina", "Regina", "Spawned: Regina");
		addVehOption("Rentalbus", "Rentalbus", "Spawned: Rentalbus");
		addVehOption("Rhapsody", "Rhapsody", "Spawned: Rhapsody");
		addVehOption("Rhino", "Rhino", "Spawned: Rhino");
		addVehOption("Riot", "Riot", "Spawned: Riot");
		addVehOption("Ripley", "Ripley", "Spawned: Ripley");
		addVehOption("Rocoto", "Rocoto", "Spawned: Rocoto");
		addVehOption("Romero", "Romero", "Spawned: Romero");
		addVehOption("Rubble", "Rubble", "Spawned: Rubble");
		addVehOption("Ruffian", "Ruffian", "Spawned: Ruffian");
		addVehOption("Ruiner", "Ruiner", "Spawned: Ruiner");
		addVehOption("Rumpo", "Rumpo", "Spawned: Rumpo");
		addVehOption("Rumpo2", "Rumpo2", "Spawned: Rumpo2");
		addVehOption("Sabregt", "Sabregt", "Spawned: Sabregt");
		addVehOption("Sadler", "Sadler", "Spawned: Sadler");
		addVehOption("Sadler2", "Sadler2", "Spawned: Sadler2");
		addVehOption("Sanchez", "Sanchez", "Spawned: Sanchez");
		addVehOption("Sanchez2", "Sanchez2", "Spawned: Sanchez2");
		addVehOption("Sandking", "Sandking", "Spawned: Sandking");
		addVehOption("Sandking2", "Sandking2", "Spawned: Sandking2");
		addVehOption("Savage", "Savage", "Spawned: Savage");
		addVehOption("Schafter2", "Schafter2", "Spawned: Schafter2");
		addVehOption("Schwarzer", "Schwarzer", "Spawned: Schwarzer");
		addVehOption("Scorcher", "Scorcher", "Spawned: Scorcher");
		addVehOption("Scrap", "Scrap", "Spawned: Scrap");
		addVehOption("Seashark", "Seashark", "Spawned: Seashark");
		addVehOption("Seashark2", "Seashark2", "Spawned: Seashark2");
		addVehOption("Seminole", "Seminole", "Spawned: Seminole");
		addVehOption("Sentinel", "Sentinel", "Spawned: Sentinel");
		addVehOption("Sentinel2", "Sentinel2", "Spawned: Sentinel2");
		addVehOption("Serrano", "Serrano", "Spawned: Serrano");
		addVehOption("Shamal", "Shamal", "Spawned: Shamal");
		addVehOption("Sheriff", "Sheriff", "Spawned: Sheriff");
		addVehOption("Sheriff2", "Sheriff2", "Spawned: Sheriff2");
		addVehOption("Skylift", "Skylift", "Spawned: Skylift");
		addVehOption("Slamvan", "Slamvan", "Spawned: Slamvan");
		addVehOption("Slamvan2", "Slamvan2", "Spawned: Slamvan2");
		addVehOption("Sovereign", "Sovereign", "Spawned: Sovereign");
		addVehOption("Speeder", "Speeder", "Spawned: Speeder");
		addVehOption("Speedo", "Speedo", "Spawned: Speedo");
		addVehOption("Speedo2", "Speedo2", "Spawned: Speedo2");
		addVehOption("Squalo", "Squalo", "Spawned: Squalo");
		addVehOption("Stalion", "Stalion", "Spawned: Stalion");
		addVehOption("Stalion2", "Stalion2", "Spawned: Stalion2");
		addVehOption("Stanier", "Stanier", "Spawned: Stanier");
		addVehOption("Stinger", "Stinger", "Spawned: Stinger");
		addVehOption("Stingergt", "Stingergt", "Spawned: Stingergt");
		addVehOption("Stockade", "Stockade", "Spawned: Stockade");
		addVehOption("Stockade3", "Stockade3", "Spawned: Stockade3");
		addVehOption("Stratum", "Stratum", "Spawned: Stratum");
		addVehOption("Stretch", "Stretch", "Spawned: Stretch");
		addVehOption("Stunt", "Stunt", "Spawned: Stunt");
		addVehOption("Submersible", "Submersible", "Spawned: Submersible");
		addVehOption("Submersible2", "Submersible2", "Spawned: Submersible2");
		addVehOption("Sultan", "Sultan", "Spawned: Sultan");
		addVehOption("Suntrap", "Suntrap", "Spawned: Suntrap");
		addVehOption("Superd", "Superd", "Spawned: Superd");
		addVehOption("Surano", "Surano", "Spawned: Surano");
		addVehOption("Surfer", "Surfer", "Spawned: Surfer");
		addVehOption("Surfer2", "Surfer2", "Spawned: Surfer2");
		addVehOption("Surge", "Surge", "Spawned: Surge");
		addVehOption("Taco", "Taco", "Spawned: Taco");
		addVehOption("Tailgater", "Tailgater", "Spawned: Tailgater");
		addVehOption("Tanker", "Tanker", "Spawned: Tanker");
		addVehOption("Taxi", "Taxi", "Spawned: Taxi");
		addVehOption("Technical", "Technical", "Spawned: Technical");
		addVehOption("Thrust", "Thrust", "Spawned: Thrust");
		addVehOption("Tiptruck", "Tiptruck", "Spawned: Tiptruck");
		addVehOption("Tiptruck2", "Tiptruck2", "Spawned: Tiptruck2");
		addVehOption("Titan", "Titan", "Spawned: Titan");
		addVehOption("Tornado", "Tornado", "Spawned: Tornado");
		addVehOption("Tornado2", "Tornado2", "Spawned: Tornado2");
		addVehOption("Tornado3", "Tornado3", "Spawned: Tornado3");
		addVehOption("Tornado4", "Tornado4", "Spawned: Tornado4");
		addVehOption("Tourbus", "Tourbus", "Spawned: Tourbus");
		addVehOption("Towtruck", "Towtruck", "Spawned: Towtruck");
		addVehOption("Towtruck2", "Towtruck2", "Spawned: Towtruck2");
		addVehOption("Tr2", "Tr2", "Spawned: Tr2");
		addVehOption("Tr3", "Tr3", "Spawned: Tr3");
		addVehOption("Tr4", "Tr4", "Spawned: Tr4");
		addVehOption("Tractor", "Tractor", "Spawned: Tractor");
		addVehOption("Tractor2", "Tractor2", "Spawned: Tractor2");
		addVehOption("Tractor3", "Tractor3", "Spawned: Tractor3");
		addVehOption("Trailerlogs", "Trailerlogs", "Spawned: Trailerlogs");
		addVehOption("Trailers", "Trailers", "Spawned: Trailers");
		addVehOption("Trailers2", "Trailers2", "Spawned: Trailers2");
		addVehOption("Trailers3", "Trailers3", "Spawned: Trailers3");
		addVehOption("Trailersmall", "Trailersmall", "Spawned: Trailersmall");
		addVehOption("Trash", "Trash", "Spawned: Trash");
		addVehOption("Trflat", "Trflat", "Spawned: Trflat");
		addVehOption("Tribike", "Tribike", "Spawned: Tribike");
		addVehOption("Tribike2", "Tribike2", "Spawned: Tribike2");
		addVehOption("Tribike3", "Tribike3", "Spawned: Tribike3");
		addVehOption("Tropic", "Tropic", "Spawned: Tropic");
		addVehOption("Turismor", "Turismor", "Spawned: Turismor");
		addVehOption("Tvtrailer", "Tvtrailer", "Spawned: Tvtrailer");
		addVehOption("Utillitruck", "Utillitruck", "Spawned: Utillitruck");
		addVehOption("Utillitruck2", "Utillitruck2", "Spawned: Utillitruck2");
		addVehOption("Utillitruck3", "Utillitruck3", "Spawned: Utillitruck3");
		addVehOption("Vacca", "Vacca", "Spawned: Vacca");
		addVehOption("Vader", "Vader", "Spawned: Vader");
		addVehOption("Valkyrie", "Valkyrie", "Spawned: Valkyrie");
		addVehOption("Velum", "Velum", "Spawned: Velum");
		addVehOption("Velum2 ", "Velum2 ", "Spawned: Velum2 ");
		addVehOption("Vestra", "Vestra", "Spawned: Vestra");
		addVehOption("Vigero", "Vigero", "Spawned: Vigero");
		addVehOption("Voltic", "Voltic", "Spawned: Voltic");
		addVehOption("Voodoo2", "Voodoo2", "Spawned: Voodoo2");
		addVehOption("Warrener", "Warrener", "Spawned: Warrener");
		addVehOption("Washington", "Washington", "Spawned: Washington");
		addVehOption("Youga", "Youga", "Spawned: Youga");
		addVehOption("Zentorno", "Zentorno", "Spawned: Zentorno");
		addVehOption("Zion", "Zion", "Spawned: Zion");
		addVehOption("Zion2", "Zion2", "Spawned: Zion2");
		addVehOption("Ztype", "Ztype", "Spawned: Ztype");
        break;
#pragma endregion
#pragma region Modded_Vehicles
   case Modded_Vehicles:
		addTitle("Modded Vehicles");
		addOption("Trolley");
		addOption("Toilet");
		addOption("Couch");
		addOption("Wheelchair");
		addOption("Bumpercar");
		addOption("Wheelbarrow");
		addOption("Teddy Car");
		addOption("Bat Bike");
		addOption("Minigun Car");
		addOption("Minigun Car 2");
		addOption("Bumper Buggy");
		addOption("GoKart");
		addOption("Star Wars Ship");
		addOption("Bike");
		switch (getOption())
		{
		case 1: doTrolley = true; break;
		case 2: doToilet = true; break;
		case 3: doCouch = true; break;
		case 4: doWheelchair = true; break;
		case 5: doBumpercar = true; break;
		case 6: doWheelbarrow = true; break;
		case 7: doTeddycar = true; break;
		case 8: batbike = true; break;
		case 9: minigun = true; break;
		case 10: minigun2 = true; break;
		case 11: buggy = true; break;
		case 12: kart = true; break;
		case 13: starwars  = true; break;
		case 14: starwars2 = true; break;
		}
		break;
#pragma endregion
#pragma region Teleport
   case Teleport:
		addTitle("Pick A Location");
		addOption("To Waypoint");
		addOption("To Nearest Vehicle");
		addOption("MorsMutual");
		addOption("Police Impound");
		addOption("Ponsonbys");
		addOption("Emergency Heli Pad");
		addOption("LSCustoms");
		addOption("Airport");
		addOption("Vanilla Unicorn");
		addOption("Apartment");
		addOption("Inside FIB Building");
		addOption("Fort Zancudo Tower");
		switch (getOption())
		{
		case 1:  TPtoWaypoint(); break;	
		case 2:  ToNearestCar(); break;
		case 3:  TeleportToLoc(-240.0677, -1164.9530, 23.0176);  break;
		case 4:  TeleportToLoc(399.3267, -1629.9960, 29.2930); break;
		case 5:  TeleportToLoc(-168.7958, -299.1412, 39.1575);  break;
		case 6:  TeleportToLoc(308.9238, -1458.9330, 46.5095);  break;
		case 7:  TeleportToLoc(-368.8527, -130.176, 38.68118);  break;
		case 8:  TeleportToLoc(-1102.2910, -2894.5160, 13.9467);  break;
		case 9:  TeleportToLoc(126.1211, -1278.5130, 29.2696);  break;
		case 10: TeleportToLoc(-878.5444, -445.3285, 125.6352);  break;
		case 11: TeleportToLoc(135.5220, -749.0009, 260.0000);  break;
		case 12: TeleportToLoc(-2354.424, 3249.7632, 101.4504);  break;	
		}
		break;
#pragma endregion
#pragma region Custom Map Options
   case Custom_Map_Options:
		addTitle("Custom Map");
		addOption("Airport 1");
		addOption("Airport 2 ");
		addOption("Airport 3 ");
		addOption("Airport 4");
		addOption("Airport 5");
		addOption(" ");
		addOption(" ");
		addOption(" ");
		addOption(" ");
		addOption(" ");
		addOption(" ");
		addOption(" ");
		switch (getOption())
		{
		case 1: 
				object_x_y_z_pitch_roll_yaw(-1963621339,-1309.400,-3159.366,17.9155,-30.0000,179.8366,-119.7953);
				object_x_y_z_pitch_roll_yaw(-1963621339,-1294.220,-2881.491,15.7663,146.9254,0.1068,61.9997);
				object_x_y_z_pitch_roll_yaw(-1963621339,-1270.687,-2893.178,35.0770,39.8562,177.9906,-115.2656);
				object_x_y_z_pitch_roll_yaw(-1963621339,-1327.276,-2709.746,16.3198,-147.0000,0.0047,15.0046);
				TeleportToLoc(-1311.62, -2875.79, 13.53);  break;
				PRINT("Enjoy ~p~WILDEMODZ ~w~Ramps in Airport"); break;
			
		case 2: object_x_y_z_pitch_roll_yaw(0x9C762726,-1426.886,-2497.702,19.9720, 30.7213,0.1092,  -26.3437);//1
				object_x_y_z_pitch_roll_yaw(0x9C762726,-1413.186,-2469.902,38.3891,30.7213,0.1092,-26.3437);//2
				object_x_y_z_pitch_roll_yaw(0x9C762726,-1399.487,-2442.101,56.8062,30.7213,0.1092,-26.3437);//3
				object_x_y_z_pitch_roll_yaw(0x9C762726,-1385.687,-2414.402,75.1943,30.7213,0.1092,-26.3437);//4
				object_x_y_z_pitch_roll_yaw(0x9C762726,-1371.987, -2386.702, 93.5514, 30.7213,0.1092,-26.3437);//5
				object_x_y_z_pitch_roll_yaw(0x9C762726,-1358.257,-2358.993,111.9185,30.7213,  0.1092, -26.3437);//6
				object_x_y_z_pitch_roll_yaw(0x9C762726,-1344.457,-2331.294,130.3056,30.7213, 0.1092,  -26.3437);//7
				object_x_y_z_pitch_roll_yaw(0x9C762726,-1330.557,-2303.493,148.7926,30.7213,0.1092,-26.3437);//8
				object_x_y_z_pitch_roll_yaw(0x9C762726,-1316.857,-2275.794,167.1497,30.7213,0.1092, -26.3437);//9
				object_x_y_z_pitch_roll_yaw(0x9C762726,-1303.057, -2248.085, 185.5368, 30.7213, 0.1092, -26.3437);//10
				object_x_y_z_pitch_roll_yaw(0x9C762726,-1289.257,  -2220.385,  203.9238, 30.7213,0.1092, -26.3437);//11
				object_x_y_z_pitch_roll_yaw(0x9C762726, -1275.457,  -2192.685,  222.3109,  30.7213,  0.1092,  -26.3437);//12
				object_x_y_z_pitch_roll_yaw(0x9C762726,  -1261.758, -2164.887,  240.7280,  30.7213, 0.1092, -26.3437);//13
				object_x_y_z_pitch_roll_yaw(0x9C762726, -1247.958,  -2137.185,  259.1151,  30.7213,  0.1092, -26.3437);//14
				object_x_y_z_pitch_roll_yaw(0x9C762726, -1234.238, -2109.405, 277.5222,  30.7213,   0.1092,  -26.3437);//15
				object_x_y_z_pitch_roll_yaw(0x9C762726,  -1220.538,  -2081.704,  295.8792,  30.7213, 0.1092, -26.3437);//16
				object_x_y_z_pitch_roll_yaw(0x9C762726, -1206.868, -2054.017, 314.2263,  30.7213,  0.1092, -26.3437);//17
			    object_x_y_z_pitch_roll_yaw(0x9C762726,  -1193.068, -2026.417,  332.5634,  30.7213,   0.1092,  -26.3437);//18
				object_x_y_z_pitch_roll_yaw(0x9C762726,  -1179.368,  -1998.676,  350.9403,  30.7213, 0.1092, -26.3437);//19
				object_x_y_z_pitch_roll_yaw(0x9C762726, -1165.648,  -1970.866,  369.3675, 30.7213,0.1092,  -26.3437);//17
				object_x_y_z_pitch_roll_yaw(0x9C762726,  -1151.948,  -1943.167,  387.7346,  30.7213, 0.1092, -26.3437);//18
				object_x_y_z_pitch_roll_yaw(0x9C762726, -1138.148,  -1915.467,  406.1316,  30.7213,  0.1092, -26.3437);//19
				object_x_y_z_pitch_roll_yaw(0x9C762726,   -1124.449, -1887.667,  424.5489,  30.7213,   0.1092,  -26.3437);//19
				object_x_y_z_pitch_roll_yaw(0x9C762726,   -1110.749, -1859.937,  442.9361, 30.7213,  0.1092,  -26.3437);//19
				object_x_y_z_pitch_roll_yaw(0x9C762726,     -1097.009 , -1832.238,  461.3032,  30.7213,  0.1092 ,-26.3437);//19
				object_x_y_z_pitch_roll_yaw(0x9C762726,    -1082.210,  -1802.338,  470.6203,  0.7213,  0.1092, -26.3437);//19
				object_x_y_z_pitch_roll_yaw(0x9C762726,    -1090.710,  -1798.137,  470.6374,  0.7213,  0.1092, -26.3437);//19
				object_x_y_z_pitch_roll_yaw(0x9C762726,     -1073.909, -1806.737,  470.6545, 0.7213,   0.1092,  -26.3437);//19
				TeleportToLoc(-1436.47,-2519.69,13.54);  break;
				PRINT("Enjoy,~p~WILDEMODZ ~w~Ramps in Airport");   break;

		case 3: object_x_y_z_pitch_roll_yaw(-1818980770,  -2597.453, 3125.512, 32.525, 0.0, 0.0, 173.367);
                object_x_y_z_pitch_roll_yaw(2097329273,   -2477.525, -208.867, 16.784, 0.0, 0.0, -117.600);
                object_x_y_z_pitch_roll_yaw(-1319646748,  -2481.562, -206.710, 17.389, 0.0, 0.0, -117.600);
                object_x_y_z_pitch_roll_yaw(2097329273,   -2685.132, 2481.740, 15.673, 0.0, 0.0, 171.999);
                object_x_y_z_pitch_roll_yaw(1212630005,   -2684.543, 2485.802, 16.214, 0.0, 0.0, 171.999);
                object_x_y_z_pitch_roll_yaw(55777251,     -2675.107, 2477.065, 16.474, 0.0, 0.0, 171.999);
                object_x_y_z_pitch_roll_yaw(55777251,     -2671.113, 2476.502, 16.476, 0.0, 0.0, 171.999);
                object_x_y_z_pitch_roll_yaw(-1319646748,  -3038.431, 1682.043, 34.973, 0.0, 0.0, 177.200);
                object_x_y_z_pitch_roll_yaw(-1319646748,  -3035.268, 1681.864, 34.905, 0.0, 0.0, 177.200);
                object_x_y_z_pitch_roll_yaw(-1319646748, -3035.375, 1678.644, 35.690, 10.240, -0.023, 177.202);
                object_x_y_z_pitch_roll_yaw(-1319646748, -3038.411, 1678.792, 35.691, 10.244, 0.0, 177.200);
                object_x_y_z_pitch_roll_yaw(-1319646748, -3035.539, 1674.926, 37.409, 20.485, -0.024, 177.204);
                object_x_y_z_pitch_roll_yaw(-1319646748, -3038.607, 1675.066, 37.412, 20.489, 0.0, 177.200);
                object_x_y_z_pitch_roll_yaw(-1818980770, -2483.792, -217.599, 17.547, 0.0, 0.0, -116.800);
                object_x_y_z_pitch_roll_yaw(-1818980770, -2485.691, -221.168, 17.501, 0.0, 0.0, -116.800);
                object_x_y_z_pitch_roll_yaw(-1319646748, -2483.274, -222.379, 19.606, 23.344, 0.0, -116.800);
                object_x_y_z_pitch_roll_yaw(-1319646748, -2481.101, -223.451, 21.754, 33.588, 0.0, -116.800);
                object_x_y_z_pitch_roll_yaw(-1319646748, -2481.384, -218.818, 19.651, 23.344, 0.0, -116.800);
                object_x_y_z_pitch_roll_yaw(-1319646748, -2479.283, -219.888, 21.755, 33.588, 0.0, -116.800);
                object_x_y_z_pitch_roll_yaw(1212630005, -920.200, -652.107, 26.964, 0.0, 0.0, -58.800);
                object_x_y_z_pitch_roll_yaw(1212630005, -917.257, -654.974, 27.130, 0.0, 0.0, -58.800);
                object_x_y_z_pitch_roll_yaw(1212630005, -916.583, -649.890, 27.970, 10.244, 0.0, -58.800);
                object_x_y_z_pitch_roll_yaw(1212630005, -914.486, -653.342, 27.992, 10.244, 0.0, -58.800);
                object_x_y_z_pitch_roll_yaw(1212630005, -1657.041, -724.265, 10.977, 0.0, 0.0, -117.600);
                object_x_y_z_pitch_roll_yaw(1212630005, -1652.047, -722.320, 11.930, 10.244, 0.0, -117.600);
                object_x_y_z_pitch_roll_yaw(1212630005, -1433.913, -836.306, 16.088, 3.486, 2.046, -112.862);
                object_x_y_z_pitch_roll_yaw(1212630005, -1430.094, -837.909, 17.833, 18.791, 1.859, -112.306);
                object_x_y_z_pitch_roll_yaw(1212630005, -1427.804, -838.853, 19.750, 29.035, 1.922, -112.496);
                object_x_y_z_pitch_roll_yaw(1212630005, -1428.563, -834.176, 17.966, 18.875, 1.934, -112.954);
                object_x_y_z_pitch_roll_yaw(1212630005, -1426.299, -835.173, 19.882, 29.119, 2.000, -113.151);
                object_x_y_z_pitch_roll_yaw(1212630005, -1432.339, -832.566, 16.219, 3.834, 1.756, -112.859);
                object_x_y_z_pitch_roll_yaw(55777251, -2562.013, 3373.818, 13.104, 0.0, 0.0, 169.600);
                object_x_y_z_pitch_roll_yaw(55777251, -2565.996, 3374.492, 13.123, 0.0, 0.0, 169.600);
                object_x_y_z_pitch_roll_yaw(55777251, -2569.963, 3375.219, 13.121, 0.0, 0.0, 169.600);
                object_x_y_z_pitch_roll_yaw(-1135198622, -2566.440, 3371.892, 15.442, 23.344, 0.0, 169.600);
                object_x_y_z_pitch_roll_yaw(-1135198622, -2562.506, 3371.168, 15.447, 23.344, 0.0, 169.600);
                object_x_y_z_pitch_roll_yaw(-1135198622, -2570.428, 3372.663, 15.422, 23.344, 0.0, 169.600);
                object_x_y_z_pitch_roll_yaw(1212630005, -2566.840, 3369.654, 17.755, 38.380, 0.184, 169.303);
                object_x_y_z_pitch_roll_yaw(1212630005, -2570.825, 3370.405, 17.750, 38.380, 0.184, 169.303);
                object_x_y_z_pitch_roll_yaw(1212630005, -2562.901, 3368.921, 17.766, 38.380, 0.184, 169.303);
                object_x_y_z_pitch_roll_yaw(1212630005, -1480.726, -811.157, 23.233, 0.0, 0.0, -122.800);
                object_x_y_z_pitch_roll_yaw(1212630005, -1478.245, -807.580, 23.256, 0.0, 0.0, -122.800);
                object_x_y_z_pitch_roll_yaw(1212630005, -1655.601, -720.484, 10.890, 0.0, 0.0, -117.600);
                object_x_y_z_pitch_roll_yaw(1212630005, -1653.902, -725.885, 11.933, 10.244, 0.0, -117.600);
                object_x_y_z_pitch_roll_yaw(1212630005, -1483.253, -814.711, 23.215, 0.0, 0.0, -122.800);
                object_x_y_z_pitch_roll_yaw(2097329273, -1969.224, -477.363, 10.715, 0.0, 0.0, -130.000);
                object_x_y_z_pitch_roll_yaw(-1319646748, -1972.821, -474.287, 11.157, 0.0, 0.0, -130.400);
                object_x_y_z_pitch_roll_yaw(-1818980770, -1985.464, -476.831, 11.356, 0.0, 0.0, -130.000);
                object_x_y_z_pitch_roll_yaw(-1818980770, -1982.854, -473.753, 11.367, 0.0, 0.0, -130.000);
                object_x_y_z_pitch_roll_yaw(-1818980770, -2593.446, 3125.055, 32.525, 0.0, 0.0, 173.367); 
				TeleportToLoc(-2597.453, 3125.512, 32.525); break;
				PRINT("Enjoy,~p~WILDEMODZ ~w~Ramps in Airport");   break;

		case 4: object_x_y_z_pitch_roll_yaw( -450918183, -966.034, -2560.265, 33.687, 0.0, 0.0, -28.816);
                object_x_y_z_pitch_roll_yaw( -450918183, -961.401, -2551.893, 33.687, 0.0, 0.0, -28.816);
                object_x_y_z_pitch_roll_yaw( -450918183, -956.786, -2543.505, 33.687, 0.0, 0.0, -28.816);
                object_x_y_z_pitch_roll_yaw( -1818980770, -956.559, -2541.986, 37.379, 0.0, 0.0, -31.216);
                object_x_y_z_pitch_roll_yaw( -450918183, -897.359, -2539.377, 36.620, 0.0, 0.0, -28.816);
                object_x_y_z_pitch_roll_yaw( -450918183, -937.397, -2515.936, 36.620, 0.0, 0.0, -28.816);
                object_x_y_z_pitch_roll_yaw( -450918183, -940.197, -2514.393, 36.620, 0.0, 0.0, -28.816);
                object_x_y_z_pitch_roll_yaw( -1319646748, -955.800, -2540.751, 38.943, 23.344, 0.0, -31.216);
                object_x_y_z_pitch_roll_yaw( -450918183, -906.617, -2556.073, 36.620, 0.0, 0.0, -28.816);
                object_x_y_z_pitch_roll_yaw( -450918183, -901.942, -2547.687, 36.620, 0.0, 0.0, -29.216);
                object_x_y_z_pitch_roll_yaw( -450918183, -923.695, -2584.729, 33.837, 0.0, 0.0, -30.416);
                object_x_y_z_pitch_roll_yaw( -450918183, -920.906, -2586.312, 33.844, 0.0, 0.0, -30.416);
                object_x_y_z_pitch_roll_yaw( -1319646748, -909.422, -2559.946, 40.136, 0.0, 0.0, 150.800);
                object_x_y_z_pitch_roll_yaw( -1319646748, -951.658, -2635.613, 37.627, 0.0, 0.0, -120.016);
                object_x_y_z_pitch_roll_yaw( -1319646748, -983.493, -2616.794, 32.353, -19.766, 0.283, 60.833);
                object_x_y_z_pitch_roll_yaw( -1319646748, -985.306, -2615.815, 32.548, -9.522, 0.274, 60.807);
                object_x_y_z_pitch_roll_yaw( -1319646748, -987.018, -2614.854, 33.112, 0.0, 0.0, 60.784);
                object_x_y_z_pitch_roll_yaw( -1319646748, -989.146, -2613.602, 34.098, 10.244, 0.0, 60.784);
                object_x_y_z_pitch_roll_yaw( -1319646748, -990.633, -2612.712, 35.285, 20.489, 0.0, 60.784);
                object_x_y_z_pitch_roll_yaw( -1319646748, -955.449, -2633.427, 37.627, 0.0, 0.0, 59.584);
                object_x_y_z_pitch_roll_yaw( -1818980770, -987.796, -2757.249, 27.167, 0.0, 0.0, 59.185);
                object_x_y_z_pitch_roll_yaw( -1818980770, -1024.074, -2736.382, 27.167, 0.0, 0.0, 59.185);
                object_x_y_z_pitch_roll_yaw( -1818980770, -1060.309, -2715.419, 27.167, 0.0, 0.0, 59.185);
                object_x_y_z_pitch_roll_yaw( -1818980770, -1074.653, -2707.138, 29.258, 0.0, 0.0, 59.185);
                object_x_y_z_pitch_roll_yaw( -1319646748, -1075.730, -2706.511, 30.734, 23.344, 0.0, 59.185);
                object_x_y_z_pitch_roll_yaw( 779917859, -1089.300, -2696.016, 34.047, 0.0, 0.0, 59.999);
                object_x_y_z_pitch_roll_yaw( -1818980770, -1055.010, -2641.121, 35.033, 0.0, 0.0, -30.016);
                object_x_y_z_pitch_roll_yaw( 1152297372, -943.808, -2691.544, 35.623, 0.0, 0.0, 1.185);
                object_x_y_z_pitch_roll_yaw( -185511650, -939.297, -2642.993, 38.819, 0.0, 0.0, 59.200);
                object_x_y_z_pitch_roll_yaw( -1319646748, -910.824, -2562.387, 41.185, 10.244, 0.0, 150.800);
                object_x_y_z_pitch_roll_yaw( -1319646748, -941.176, -2641.838, 39.857, 15.037, 0.004, 59.184);
                object_x_y_z_pitch_roll_yaw( -173040310, -1000.362, -2555.565, 38.424, 0.0, 0.0, -119.600);
                object_x_y_z_pitch_roll_yaw( -173040310, -990.111, -2561.419, 38.424, 0.0, 0.0, -119.600);
                object_x_y_z_pitch_roll_yaw( -173040310, -979.764, -2567.343, 38.424, 0.0, 0.0, -119.600);
                object_x_y_z_pitch_roll_yaw( -173040310, -969.304, -2573.295, 38.425, 0.0, 0.0, -119.600);
                object_x_y_z_pitch_roll_yaw( -173040310, -1007.450, -2558.349, 36.535, 23.344, 0.0, -29.600);
                object_x_y_z_pitch_roll_yaw( 779917859, -1001.752, -2553.424, 41.345, 0.0, 0.0, -28.800);
                object_x_y_z_pitch_roll_yaw( -1319646748, -1012.315, -2566.525, 35.958, 0.0, 0.0, -28.800);
                object_x_y_z_pitch_roll_yaw( 1172303719, -977.002, -2764.466, 34.357, 0.0, 0.0, 150.000);
                object_x_y_z_pitch_roll_yaw( -185511650, -939.749, -2700.009, 36.318, 0.0, 0.0, 150.800);
                object_x_y_z_pitch_roll_yaw( -185511650, -970.732, -2567.811, 36.319, 0.0, 0.0, -29.215);
                object_x_y_z_pitch_roll_yaw( 1961489851, -931.637, -2643.151, 38.109, 0.0, 0.0, -30.001);
                object_x_y_z_pitch_roll_yaw( -1319646748, -964.338, -2576.117, 41.718, 0.0, 0.0, -118.815);
                object_x_y_z_pitch_roll_yaw( -1319646748, -961.763, -2577.555, 42.791, 10.244, 0.0, -118.815);
                object_x_y_z_pitch_roll_yaw( -1319646748, -959.312, -2578.907, 44.377, 20.489, 0.0, -118.815);
                object_x_y_z_pitch_roll_yaw( -1319646748, -957.129, -2580.128, 46.403, 30.733, 0.0, -118.815);
                object_x_y_z_pitch_roll_yaw( -1319646748, -955.202, -2581.213, 48.864, 40.977, 0.0, -118.815);
                object_x_y_z_pitch_roll_yaw( -450918183, -983.060, -2571.505, 35.606, 0.0, 0.0, -120.400);
                object_x_y_z_pitch_roll_yaw( -1094431857, -1017.875, -2563.840, 35.465, 0.0, 0.0, -120.400);
                object_x_y_z_pitch_roll_yaw( 779917859, -930.783, -2604.163, 35.704, 0.0, 0.0, 150.000);
				//TeleportToLoc(-1016.25, -2573.55, 35.28); break;
				TeleportToLoc(-1004.11, -2553.85, 41.76); break;
				PRINT("Enjoy,~p~WILDEMODZ ~w~Ramps in Airport");   break;
			      break;

		case 5: object_x_y_z_pitch_roll_yaw( 1212630005, -852.329, -2552.542, 27.532, -87.217, -9.937, -40.149);
                object_x_y_z_pitch_roll_yaw( 779917859, -855.821, -2554.279, 18.035, 0.522, -48.802, 59.555);
                object_x_y_z_pitch_roll_yaw( 1212630005, -852.648, -2553.056, 30.694, -77.002, -2.465, -32.642);
                object_x_y_z_pitch_roll_yaw( 1212630005, -853.223, -2553.941, 33.687, -66.761, -1.581, -31.724);
                object_x_y_z_pitch_roll_yaw( 1212630005, -853.944, -2555.240, 36.472, -56.518, -1.245, -31.351);
                object_x_y_z_pitch_roll_yaw( 1212630005, -854.911, -2556.836, 38.963, -46.274, -1.073, -31.140);
                object_x_y_z_pitch_roll_yaw( 779917859, -858.594, -2559.169, 14.256, -0.627, -21.556, 61.599);
                object_x_y_z_pitch_roll_yaw( 1212630005, -934.021, -2689.426, 36.149, 0.0, 0.0, 150.800);
                object_x_y_z_pitch_roll_yaw( 1212630005, -1004.569, -2746.223, 29.088, 0.0, 0.0, 51.318);
                object_x_y_z_pitch_roll_yaw( 1212630005, -988.265, -2506.629, 27.513,-86.943, -26.764, 123.320);
                object_x_y_z_pitch_roll_yaw( 1212630005, -987.955, -2506.107, 30.682, -76.930, -7.035, 143.147);
                object_x_y_z_pitch_roll_yaw( 1212630005, -987.319, -2505.254, 33.681, -66.713, -4.523, 145.761);
                object_x_y_z_pitch_roll_yaw( 1212630005, -986.553, -2503.989, 36.457, -56.479, -3.564, 146.824);
                object_x_y_z_pitch_roll_yaw( 1212630005, -985.551, -2502.410, 38.949, -46.239, -3.072, 147.427);
                object_x_y_z_pitch_roll_yaw( 1212630005, -984.411, -2500.552, 41.073, -35.997, -2.784, 147.835);
                object_x_y_z_pitch_roll_yaw( 1212630005, -983.156, -2498.502, 42.774, -25.754, -2.605, 148.143);
                object_x_y_z_pitch_roll_yaw( 1212630005, -981.774, -2496.337, 44.024, -15.510, -2.495, 148.399);
                object_x_y_z_pitch_roll_yaw( -1363788725, -981.319, -2493.157, 44.353, -6.525, -2.421, 148.780);
                object_x_y_z_pitch_roll_yaw( -1363788725, -973.283, -2483.222, 43.349, 0.0, 0.0, 125.538);
                object_x_y_z_pitch_roll_yaw( -1363788725, -973.304, -2483.251, 46.190, 0.0, 0.0, 125.538);
                object_x_y_z_pitch_roll_yaw( -1363788725, -963.122, -2477.875, 43.399, 0.0, 0.0, 109.538);
                object_x_y_z_pitch_roll_yaw( -1363788725, -963.076, -2477.926, 46.240, 0.0, 0.0, 109.538);
                object_x_y_z_pitch_roll_yaw( -1363788725, -951.846, -2475.599, 43.453, 0.0, 0.0, 93.538);
                object_x_y_z_pitch_roll_yaw( -1363788725, -951.845, -2475.600, 46.293, 0.0, 0.0, 93.538);
                object_x_y_z_pitch_roll_yaw( -173040310, -951.456, -2477.845, 40.835, 0.0, 0.0, -88.062);
                object_x_y_z_pitch_roll_yaw( -173040310, -962.399, -2479.810, 40.896, 0.0, 0.0, -70.862);
                object_x_y_z_pitch_roll_yaw( -173040310, -972.187, -2484.672, 41.053, 0.0, 0.0, -54.862);
                object_x_y_z_pitch_roll_yaw( 1212630005, -1026.568, -2508.115, 19.714, 0.0, 0.0, -176.463);
                object_x_y_z_pitch_roll_yaw( -1135198622, -1043.823, -2533.014, 19.994, 0.0, 0.0, -29.262);
                object_x_y_z_pitch_roll_yaw( 1212630005, -1015.836, -2648.771, 37.219, 10.244, 0.0, -121.292);
                object_x_y_z_pitch_roll_yaw( 1212630005, -1019.197, -2646.742, 36.151, 0.0, 0.0, -121.292);
                object_x_y_z_pitch_roll_yaw( 1212630005, -915.772, -2618.093, 36.149, 0.0, 0.0, -43.200);
                object_x_y_z_pitch_roll_yaw( 1212630005, -980.419, -2761.749, 34.700, 0.0, 0.0, 61.181);
                object_x_y_z_pitch_roll_yaw( 55777251, -1026.187, -2514.058, 21.019, 0.0, 0.0, -176.400);
                object_x_y_z_pitch_roll_yaw( -1363788725, -1029.791, -2500.119, 19.078, 0.0, 0.0, -174.681);
                object_x_y_z_pitch_roll_yaw( 1212630005, -904.466, -2424.873, 20.207, 10.244, 0.0, -117.881);
                object_x_y_z_pitch_roll_yaw( -173040310, -897.470, -2430.087, 21.355, 0.0, 0.0, -142.682);
                object_x_y_z_pitch_roll_yaw( -173040310, -897.609, -2429.948, 24.176, 0.0, 0.0, -142.682);
                object_x_y_z_pitch_roll_yaw( -173040310, -894.325, -2434.201, 21.552, 0.0, 0.0, -163.881);
                object_x_y_z_pitch_roll_yaw( -173040310, -894.271, -2434.326, 24.373, 0.0, 0.0, -163.881);
                object_x_y_z_pitch_roll_yaw( 55777251, -920.744, -2412.385, 13.588, 0.0, 0.0, 80.119);
                object_x_y_z_pitch_roll_yaw( 1212630005, -1026.013, -2516.908, 23.193, 23.344, 0.0, -176.400);
                object_x_y_z_pitch_roll_yaw( -173040310, -912.914, -2658.424, 13.122, 0.0, 0.0, -30.400);
                object_x_y_z_pitch_roll_yaw( -943306241, -926.742, -2578.346, 12.834, 0.0, 0.0, 79.138);
                object_x_y_z_pitch_roll_yaw( -1319646748, -906.235, -2427.923, 19.595, 0.0, 0.0, -117.600);
                object_x_y_z_pitch_roll_yaw( -1818980770, -926.028, -2411.497, 15.936, 0.0, 0.0, 80.800);
                object_x_y_z_pitch_roll_yaw( -1319646748, -988.009, -2506.124, 23.292, 73.975, 0.939, 149.033);
                object_x_y_z_pitch_roll_yaw( -1363788725, -984.288, -2492.087, 13.149, 0.0, 0.0, 151.739);
                object_x_y_z_pitch_roll_yaw( -173040310, -892.490, -2441.041, 21.749, 0.0, 0.0, -172.661);
                object_x_y_z_pitch_roll_yaw( -1319646748, -852.598, -2553.022, 23.357, 74.009, -1.370, -28.568);  
				TeleportToLoc(-852.329, -2552.542, 27.532); break;
				PRINT("Enjoy,~p~WILDEMODZ ~w~Ramps in Airport");   break;
			    break;
		case 6:   break;
		case 7:   break;
		case 8:   break;
		case 9:   break;
		case 10:  break;
		case 11:  break;
		case 12:  break;	
		}
		break;
#pragma endregion
#pragma region Spawn_Peds
   case Spawn_Peds:
        addTitle("Ped Spawner");
	    addOption("Ped Manager");
	    addOption("Imporage");
	    addOption("Justin");
	    addOption("Alien");
	    addOption("Zombie");
	    addOption("Sheriff");
	    addOption("Swat");
	    addOption("Boar");
	    addOption("Chop");
	    addOption("Deer");
	    addOption("Pig");
	    addOption("Custion Input");
	    Vector3 CreatePedCoords = ENTITY::GET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), true);
	    switch (getOption())
	    {
	    case 1: changeSubmenu(Ped_Manager); break;
	    case 2: Create_Ped("u_m_y_imporage", "Imporage", CreatePedCoords.x, CreatePedCoords.y, CreatePedCoords.z,  "Spawned: Imporage"); break;
	    case 3: Create_Ped("u_m_y_justin", "Justin",  CreatePedCoords.x, CreatePedCoords.y, CreatePedCoords.z, "Spawned: Justin"); break;
	    case 4: Create_Ped("s_m_m_movalien_01", "Alien", CreatePedCoords.x, CreatePedCoords.y, CreatePedCoords.z, "Spawned: Alien"); break;
	    case 5: Create_Ped("u_m_y_zombie_01", "Zombie", CreatePedCoords.x, CreatePedCoords.y, CreatePedCoords.z, "Spawned: Zombie"); break;
	    case 6: Create_Ped("s_f_y_sheriff_01", "Sheriff", CreatePedCoords.x, CreatePedCoords.y, CreatePedCoords.z, "Spawned: Sheriff"); break;
	    case 7: Create_Ped("s_m_y_swat_01", "Swat", CreatePedCoords.x, CreatePedCoords.y, CreatePedCoords.z, "Spawned: Swat"); break;
	    case 8: Create_Ped("a_c_boar", "Boar", CreatePedCoords.x, CreatePedCoords.y, CreatePedCoords.z, "Spawned: Boar"); break;
	    case 9: Create_Ped("a_c_chop", "Chop", CreatePedCoords.x, CreatePedCoords.y, CreatePedCoords.z, "Spawned: Chop"); break;
	    case 10: Create_Ped("a_c_deer", "Deer", CreatePedCoords.x, CreatePedCoords.y, CreatePedCoords.z, "Spawned: Deer"); break;
	    case 11: Create_Ped("a_c_pig", "Pig", CreatePedCoords.x, CreatePedCoords.y, CreatePedCoords.z, "Spawned: Pig"); break;
		}
		break;
#pragma endregion
#pragma region Ped_Manager
   case Ped_Manager:
         addTitle("Ped Manager");
	     for (int i = 0; i < 14; i++)
	     {
		 if (ENTITY::DOES_ENTITY_EXIST(SpawnedPed[i]))
			addOption(PedNameArray[i]);
		 else
			addOption("--------");
	     }
	     if (optionPress)
	     {
		 SelectedPed = currentOption - 1;
		 changeSubmenu(Ped_Mods);
	     }
		 break;
#pragma endregion
#pragma region Ped_Mods
    case Ped_Mods:
	addTitle("Ped Mods");
	addOption("Toggle GodMode");
	addOption("Set As BodyGuard");
	addOption("Give MiniGun");
	addOption("Toggle Rape Ped");
	addOption("Explode Ped");
	addOption("Teleport To Ped");
	addOption("Delete Ped");
	addOption("Set Ped on Player");
	addOption("Animations For Peds");
    switch (getOption())
	{
	case 1: SetGMod(SpawnedPed[SelectedPed]); break;
	case 2: BodyGard(SpawnedPed[SelectedPed]); break;
	case 3: GiveWeaponPed(SpawnedPed[SelectedPed], 0x42BF8A85); break;
	case 4: RapePed(PLAYER::PLAYER_PED_ID(), SpawnedPed[SelectedPed]); break;
	case 5: Vector3 Pos1 = ENTITY::GET_ENTITY_COORDS(SpawnedPed[SelectedPed], true); FIRE::ADD_EXPLOSION(Pos1.x, Pos1.y, Pos1.z, 29, 0.5f, true, false, 5.0f); break;
	case 6: Vector3 Coords = ENTITY::GET_ENTITY_COORDS(SpawnedPed[SelectedPed], 1); if (PED::IS_PED_SITTING_IN_ANY_VEHICLE(PLAYER::PLAYER_PED_ID())) ENTITY::SET_ENTITY_COORDS(PED::GET_VEHICLE_PED_IS_USING(PLAYER::PLAYER_PED_ID()), Coords.x, Coords.y, Coords.z, 1, 0, 0, 1); else ENTITY::SET_ENTITY_COORDS(PLAYER::PLAYER_PED_ID(), Coords.x, Coords.y, Coords.z, 1, 0, 0, 1); break;
	case 7: DeleteEntity(SpawnedPed[SelectedPed]); break;
	case 8: changeSubmenu(Players_List3); break;
	case 9: changeSubmenu(Ped_Animations); break;
	    }
	     break;
#pragma endregion
#pragma region Ped_Animations
    case Ped_Animations:
	addTitle("Ped Animations");
	addOption("Stop Anim");
	addOption("Sex Recieve");
	addOption("Play Music");
	addOption("Take Photos");
	addOption("Use Binoculars");
	addOption("Drink Coffee");
	addOption("Play Golf");
	addOption("Lift Weights");
    switch (getOption())
	{
	case 1: pedstopanim = true; break;
	case 2: pedsexr = true; break;
	case 3: AI::TASK_START_SCENARIO_IN_PLACE(SpawnedPed[SelectedPed], "WORLD_HUMAN_MUSICIAN", 0, 1); break;
	case 4:  AI::TASK_START_SCENARIO_IN_PLACE(SpawnedPed[SelectedPed], "WORLD_HUMAN_PAPARAZZI", 0, 1); break;
	case 5:  AI::TASK_START_SCENARIO_IN_PLACE(SpawnedPed[SelectedPed], "WORLD_HUMAN_BINOCULARS", 0, 1); break;
	case 6:  AI::TASK_START_SCENARIO_IN_PLACE(SpawnedPed[SelectedPed], "WORLD_HUMAN_DRINKING", 0, 1); break;
	case 7:  AI::TASK_START_SCENARIO_IN_PLACE(SpawnedPed[SelectedPed], "WORLD_HUMAN_GOLF_PLAYER", 0, 1); break;
	case 8:  AI::TASK_START_SCENARIO_IN_PLACE(SpawnedPed[SelectedPed], "WORLD_HUMAN_MUSCLE_FREE_WEIGHTS", 0, 1); break;
	    }
        		break;
#pragma endregion
#pragma region Players List
   case Players_List3:
		addTitle("set ped on player");
		for (int i = 0; i < 16; i++)
		{
			addOption(PLAYER::GET_PLAYER_NAME(i));
		}
		if (optionPress && PLAYER::IS_PLAYER_PLAYING(currentOption - 1))
		{
			selectedPlayer = currentOption - 1;
			changeSubmenu(set_pedonplayer);
		}
		break;
#pragma endregion
#pragma region set ped on player
   case set_pedonplayer:
		addTitle(PLAYER::GET_PLAYER_NAME(selectedPlayer));
		addOption("Attack");
		switch (getOption())
		{
        case 1: SetPedonPlayer(SpawnedPed[SelectedPed]); break;

        }
		break;
#pragma endregion
#pragma region Weather Options
	case Weather_Options:
		addTitle("Weather Options");
		addOption("CLEAR");
		addOption("Extra Sunny");
		addOption("Light Snow");
		addOption("Blizzard");
		addOption("Fog");
		addOption("Neutral");
		addOption("Cloudy");
		addOption("Overcast");
		addOption("Smog");
		addOption("Thunder");
		addOption("Rain");
		addOption("Snow");
		addIntOption("Change Time of Day", &hours, 0, 12, true);
		switch (getOption())
		{
		case 1:  GAMEPLAY::SET_OVERRIDE_WEATHER("CLEAR"); break;
		case 2:  GAMEPLAY::SET_OVERRIDE_WEATHER("EXTRASUNNY"); break;
		case 3:  GAMEPLAY::SET_OVERRIDE_WEATHER("SNOWLIGHT"); break;
		case 4:  GAMEPLAY::SET_OVERRIDE_WEATHER("BLIZZARD"); break;
		case 5:  GAMEPLAY::SET_OVERRIDE_WEATHER("FOGGY"); break;
		case 6:  GAMEPLAY::SET_OVERRIDE_WEATHER("NEUTRAL"); break;
		case 7:  GAMEPLAY::SET_OVERRIDE_WEATHER("CLOUDS"); break;
		case 8:  GAMEPLAY::SET_OVERRIDE_WEATHER("OVERCAST"); break;
		case 9:  GAMEPLAY::SET_OVERRIDE_WEATHER("SMOG"); break;
		case 10: GAMEPLAY::SET_OVERRIDE_WEATHER("THUNDER"); break;
		case 11: GAMEPLAY::SET_OVERRIDE_WEATHER("RAIN"); break;
		case 12: GAMEPLAY::SET_OVERRIDE_WEATHER("SNOW"); break;
		case 13: NETWORK::NETWORK_OVERRIDE_CLOCK_TIME(hours, 1, 0); break;
		}
		break;
#pragma endregion
#pragma region Change Model
	case Change_Model:
		addTitle("Change Model");
		addSubmenuOption("Females", Change_Model_Females);
		addSubmenuOption("Males", Change_Model_Males);
		break;
#pragma endregion
#pragma region Females
	case Change_Model_Females:
		addTitle("Females");
		addOption("Topless Girl");
		addOption("Beach Braud");
		addOption("Denise Friend");
		addOption("Tonya");
		addOption("Bride");
		addOption("Kerry Mcintosh");
		addOption("Michelle");
		addOption("Tanisha");
		addOption("Street Hooker");
		addOption("Bussiness Women");
		addOption("Spy Actress");
		addOption("BeverlyHills Chick");
		addOption("Suburb Chick");
		addOption("Anita");
		switch (getOption())
		{
		case 1:  changeModel("a_f_y_topless_01"); break;
		case 2:  changeModel("a_f_m_beach_01"); break;
		case 3:  changeModel("csb_denise_friend"); break;
		case 4:  changeModel("csb_tonya"); break;
		case 5:  changeModel("ig_bride"); break;
		case 6:  changeModel("ig_kerrymcintosh"); break;
		case 7:  changeModel("ig_michelle");  break;
		case 8:  changeModel("ig_tanisha");  break;
		case 9:  changeModel("s_f_y_hooker_03");  break;
		case 10:  changeModel("u_f_m_promourn_01"); break; //DoFX("scr_rcbarry2", "scr_clown_appears"); break;
		case 11: changeModel("u_f_y_spyactress"); break; //DoFX("scr_rcbarry2", "scr_clown_appears"); break;
		case 12: changeModel("a_f_y_bevhills_01"); break; //DoFX("scr_rcbarry2", "scr_clown_appears"); break;
		case 13: changeModel("a_f_y_genhot_01");  break;
		case 14: changeModel("csb_anita");  break;
		}
		break;
#pragma endregion
#pragma region Males
	case Change_Model_Males:
		addTitle("Males");
		addOption("Cop");
		addOption("Pogo");
	    addOption("Alien");
		addOption("Zombie");
		addOption("Buff Dude");
		addOption("Impotent Rage");
		addOption("Paparazzi");
		addOption("Beach Guy");
		addOption("Break Dancer");
		addOption("Cletus");
		addOption("Gee");
		addOption("Merry Weather Guard");
		addOption("Prologue Driver");
		addOption("Latin Goon");
		addOption("Chris Formage");
		addOption("Clay Pain");
		addOption("Armoured Guard");
		addOption("LSC Mechanic");
		addOption("Security");
		addOption("CIA Detective");
		addOption("FIB Detective");
		addOption("Pilot");
		addOption("Scientist");
		addOption("Black Ops");
		addOption("Fire Man");
		addOption("Highwat Office");
		addOption("Marine");
		addOption("Prisoner");
		addOption("Swat ");
		addOption("Homeland Security");
		addOption("Jewel Thief");
		addOption("Party Target");
		addOption("Baby Dee");
		addOption("Tattoo Artist");
		addOption("Micheal");
		addOption("Franklin");
		addOption("Trevor");
		switch (getOption())
		{
        case 1:  changeModel("s_m_y_cop_01");  break;
        case 2:  changeModel("u_m_y_pogo_01");  break;
		case 3:  changeModel("s_m_m_movalien_01");  break;
        case 4:  changeModel("u_m_y_zombie_01");  break;
		case 5:  changeModel("u_m_y_babyd");  break;
		case 6:  changeModel("u_m_y_imporage");  break;
		case 7:  changeModel("a_m_m_paparazzi_01");  break;
		case 8:  changeModel("a_m_y_beach_02");  break;
		case 9:  changeModel("a_m_y_breakdance_01");  break;
		case 10:  changeModel("csb_cletus");  break;
		case 11:  changeModel("csb_g");  break;
		case 12:  changeModel("csb_mweather");  break;
		case 13:  changeModel("csb_prologuedriver");  break;
		case 14:  changeModel("g_m_y_mexgoon_03");  break;
		case 15:  changeModel("ig_chrisformage");  break;
		case 16: changeModel("ig_claypain");  break;
		case 17: changeModel("s_m_m_armoured_01");  break;
		case 18: changeModel("s_m_m_autoshop_01");  break;
		case 19: changeModel("s_m_m_chemsec_01");  break;
		case 20: changeModel("s_m_m_ciasec_01");  break;
		case 21: changeModel("s_m_m_fiboffice_01");  break;
		case 22: changeModel("s_m_m_pilot_01");  break;
		case 23: changeModel("s_m_m_scientist_01");  break;
		case 24: changeModel("s_m_y_blackops_01");  break;
		case 25: changeModel("s_m_y_fireman_01");  break;
		case 26: changeModel("s_m_y_hwaycop_01");  break;
		case 27: changeModel("s_m_y_marine_01");  break;
		case 28: changeModel("s_m_y_prismuscl_01");  break;
		case 29: changeModel("s_m_y_swat_01");  break;
		case 30: changeModel("u_m_m_jewelsec_01");  break;
		case 31: changeModel("u_m_m_jewelthief");  break;
		case 32: changeModel("u_m_m_partytarget");  break;
		case 33: changeModel("u_m_y_babyd");  break;
		case 34: changeModel("u_m_y_tattoo_01");  break;
		case 35: changeModel("player_zero");  break;
		case 36: changeModel("player_one");  break;
		case 37: changeModel("player_two");  break;	
		}
		break;
#pragma endregion
#pragma region Animations
	case Animations:
		addTitle("Animations");
		addOption("Clear Player Task");
		addOption("Play Music");
		addOption("Take Photos");
		addOption("Use Binoculars");
		addOption("Drink Coffee");
		addOption("Play Golf");
		addOption("Lift Weights");
		addOption("Smoke Weed");
		addOption("Be Handyman"); 
		addOption("Do Yoga"); 
		addOption("Flex Muscles"); 
		addOption("MUSICIAN");
		switch (getOption())
		{
		case 1:  AI::CLEAR_PED_TASKS_IMMEDIATELY(PLAYER::PLAYER_PED_ID()); break;
		case 2:  AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_MUSICIAN", 0, 1); break;
		case 3:  AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_PAPARAZZI", 0, 1); break;
		case 4:  AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_BINOCULARS", 0, 1); break;
		case 5:  AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_DRINKING", 0, 1); break;
		case 6:  AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_GOLF_PLAYER", 0, 1); break;
		case 7:  AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_MUSCLE_FREE_WEIGHTS", 0, 1); break;
		case 8:  AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_SMOKING_POT", 0, 1); break;
		case 9:  AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_HAMMERING", 0, 1); break;
		case 10: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_YOGA", 0, 1); break;
		case 11: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_MUSCLE_FLEX", 0, 1); break;
		case 12: AI::TASK_START_SCENARIO_IN_PLACE(PLAYER::PLAYER_PED_ID(), "WORLD_HUMAN_MUSICIAN", 0, 1); break;
        }
		break;
#pragma endregion
#pragma region Spawn Objects
	case Spawn_Objects:
		addTitle("Spawn Obects");
		addOption("UFO");
		addOption("Weed");
		addOption("Ferris Wheel");
		addOption("Hot Dog");
		addOption("ATM");
		addOption("Sculpture");
		addOption("Garbage");
		addOption("Bank Safe");
		addOption("Roof Vent");
		addOption("EMP");
		addOption("Alien Egg"); 
		addOption("Test Object");
		switch (getOption())
		{
		case 1:  CreateObject("p_spinning_anus_s"); break;
		case 2:  CreateObject("prop_weed_01"); break;
		case 3:  CreateObject("prop_ld_ferris_wheel"); break;
		case 4:  CreateObject("prop_cs_hotdog_01"); break;
		case 5:  CreateObject("prop_atm_01"); break;
		case 6:  CreateObject("prop_sculpt_fix"); break;
		case 7:  CreateObject("prop_lev_des_barge_01"); break;
		case 8:  CreateObject("p_v_43_safe_s"); break;
		case 9:  CreateObject("prop_roofvent_06a"); break;
		case 10: CreateObject("hei_prop_heist_emp"); break;
		case 11: CreateObject("prop_alien_egg_01"); break;
		case 12: CreateObject("v_ilev_bl_shutter1"); break;
		}
		break;
#pragma endregion
#pragma region Recovery
	case Recovery:
		addTitle("Recovery Options");
		addOption("Set Rank");
		addOption("Unlock All");
		addOption("Fireworks/Armour/Snacks");
		addOption("Max Smokes");
		addOption("Unlock Camos/Parachutes");
		addOption("LSCustoms Unlocks");
		addOption("Tattoo Unlocks");
		addOption("Clothing Unlocks");
		addOption("Unlock All Hairstyles");
		addOption("Unlock Heist Vehicles");
		addOption("Max Skills");
		addOption("Clear All Reports");
		addOption("Reset Appearance");
		addOption("Purchase All Weapons");
		addOption("Enable Roosevelt in Phone");
		addOption("Unlock Trophies/Awards");
		addOption("Free Shopping");
		addOption("Remove Badsport");
		addOption("Give 10 Million");
		addOption("Remove 10 Million");
		addOption("Disable Bad Sport");
		addOption("Clear Mental State");
		addOption("Skip Tutorial", "Tutorial Skiped");
		switch (getOption())
		{
		case 1:  changeSubmenu(Set_Rank); break;
		case 2:  UnlockAll(); break;
		case 3:  FireworksArmourSnacks(); break;
		case 4:  MaxSmokes(); break;
		case 5:  UnlockAllCamosParachutes(); break;
		case 6:  LSCustomsUnlocks(); break;
		case 7:  TattooUnlocks(); break;
		case 8:  ClothingUnlocks(); break;
		case 9:  UnlockAllHairstyles(); break;
		case 10: UnlockHeistVehicles(); break;
		case 11: MaxSkills(); break;
		case 12: ClearAllReports(); break;
		case 13: ResetAppearance(); break;
		case 14: PurchaseAllWeapons(); break;
		case 15: EnableRooseveltinPhone(); break;
		case 16: UnlockTrophiesAwards(); break;	
		case 17: SetTunable(60, 0x00000000), SetTunable(61, 0x00000000), SetTunable(62, 0x00000000), SetTunable(63, 0x00000000), SetTunable(65, 0x00000000), SetTunable(66, 0x00000000), SetTunable(67, 0x00000000), SetTunable(68, 0x00000000), SetTunable(69, 0x00000000); break;
		case 18: RemoveBadSport(); break;	
		case 19: NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(10000000); break;
		case 20: NETWORKCASH::NETWORK_EARN_FROM_ROCKSTAR(-10000000); break;
		case 21: SetTunable(119, 0x00000000), SetTunable(120, 0x00000000), SetTunable(121, 0x00000000), SetTunable(122, 0x00000000), SetTunable(123, 0x00000000), SetTunable(124, 0x00000000), SetTunable(125, 0x00000000), SetTunable(126, 0x00000000), SetTunable(127, 0x00000000), SetTunable(128, 0x00000000); break;
		case 22: ClearMentalState(); break;
		case 23: STATS::STAT_SET_BOOL(GAMEPLAY::GET_HASH_KEY("MP0_NO_MORE_TUTORIALS"), 1, 1); break;
		}
		break;
#pragma endregion
#pragma region Set Rank
   case Set_Rank:
	    addTitle("Set Rank");
	    addOption("50");
	    addOption("100");
	    addOption("150");
	    addOption("200");
	    addOption("250");	
	    addOption("300");
	    addOption("350");
	    addOption("400");
	    addOption("420");
	    addOption("500");
	    switch ( getOption())
	    {
	    case 1: STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), Levels[50], 0); break;
	    case 2: STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), Levels[100], 0); break;
	    case 3: STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), Levels[150], 0); break;
	    case 4: STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), Levels[200], 0); break;
	    case 5: STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), Levels[250], 0); break;
	    case 6: STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), Levels[300], 0); break;
        case 7: STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), Levels[350], 0); break;
	    case 8: STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), Levels[400], 0); break;
        case 9: STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), Levels[420], 0); break;
	    case 10: STATS::STAT_SET_INT(GAMEPLAY::GET_HASH_KEY("MP0_CHAR_XP_FM"), Levels[500], 0); break;
	    }
		break;
#pragma endregion
#pragma region Settings
	case Settings:
		addTitle("Settings");
		addSubmenuOption("Banners", Settings_Banners);
		addSubmenuOption("Body", Settings_Body);
		addSubmenuOption("Scroller", Settings_Scroller);
		addSubmenuOption("Indicators", Settings_Indicators);
		addBoolOption("Sounds", menuSounds);
		addBoolOption("News Bar", newsbar);
		addBoolOption("Instructions", instructions);
		addCustomBoolOption("", menuXCoord, 0.145f);	
		switch (getOption())
		{
		case 5:  menuSounds = !menuSounds; break;
		case 6:  newsbar = !newsbar; break;
		case 7:  instructions = !instructions; break;
		case 8: if (menuXCoord == 0.145f) { menuXCoord = 0.845f, textXCoord = 0.76f; } else { menuXCoord = 0.145f, textXCoord = 0.06f; } break;		
		} 
		break;
	case Settings_Banners:
		addTitle("Banners");
		addIntOption("Text Red", &bannerTextRed, 0, 255, true);
		addIntOption("Text Green", &bannerTextGreen, 0, 255, true);
		addIntOption("Text Blue", &bannerTextBlue, 0, 255, true);
		addIntOption("Text Opacity", &bannerTextOpacity, 0, 255, true);
		addIntOption("Text Font", &bannerTextFont, 0, 7, false);
		addIntOption("Rect Red", &bannerRectRed, 0, 255, true);
		addIntOption("Rect Green", &bannerRectGreen, 0, 255, true);
		addIntOption("Rect Blue", &bannerRectBlue, 0, 255, true);
		addIntOption("Rect Opacity", &bannerRectOpacity, 0, 255, true);
		break;
	case Settings_Body:
		addTitle("Body");
		addIntOption("Text Red", &optionsRed, 0, 255, true);
		addIntOption("Text Green", &optionsGreen, 0, 255, true);
		addIntOption("Text Blue", &optionsBlue, 0, 255, true);
		addIntOption("Text Opacity", &optionsOpacity, 0, 255, true);
		addIntOption("Text Font", &optionsFont, 0, 7, false);
		addIntOption("Rect Red", &backgroundRed, 0, 255, true);
		addIntOption("Rect Green", &backgroundGreen, 0, 255, true);
		addIntOption("Rect Blue", &backgroundBlue, 0, 255, true);
		addIntOption("Rect Opacity", &backgroundOpacity, 0, 255, true);
		break;
	case Settings_Scroller:
		addTitle("Scroller");
		addIntOption("Red", &scrollerRed, 0, 255, true);
		addIntOption("Green", &scrollerGreen, 0, 255, true);
		addIntOption("Blue", &scrollerBlue, 0, 255, true);
		addIntOption("Opacity", &scrollerOpacity, 0, 255, true);
		break;
	case Settings_Indicators:
		addTitle("Indicators");
		addIntOption("Red", &indicatorRed, 0, 255, true);
		addIntOption("Green", &indicatorGreen, 0, 255, true);
		addIntOption("Blue", &indicatorBlue, 0, 255, true);
		addIntOption("Opacity", &indicatorOpacity, 0, 255, true);
        break;
#pragma endregion
#pragma region Tire_Smoke
   case Tire_Smoke:
		addTitle("Tire Smoke");
	    addOption("White");
	    addOption("Black");	
	    addOption("~b~Blue");
	    addOption("~y~Yellow");
	    addOption("~p~Purple");
	    addOption("~o~Orange");
	    addOption("~g~Green");
	    addOption("~r~Red");
	    addOption("~p~Pink");
	    addOption("Patriot");
	    int VehID = PED::GET_VEHICLE_PED_IS_IN(PLAYER::PLAYER_PED_ID(), 0);
	    switch (getOption())
	    {
	    case 1: NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehID);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				VEHICLE::TOGGLE_VEHICLE_MOD(VehID, 20, 1);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(VehID, 0);
				VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(VehID, 254, 254, 254);
				drawNotification("Tire Smoke: White");
		break;
	    case 2: NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehID);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				VEHICLE::TOGGLE_VEHICLE_MOD(VehID, 20, 1);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(VehID, 0);
				VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(VehID, 1, 1, 1);
				drawNotification("Tire Smoke: Black");
		break;
	    case 3: NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehID);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				VEHICLE::TOGGLE_VEHICLE_MOD(VehID, 20, 1);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(VehID, 0);
				VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(VehID, 0, 0, 255);
				drawNotification("Tire Smoke: ~b~Blue");
		break;
	    case 4: NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehID);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				VEHICLE::TOGGLE_VEHICLE_MOD(VehID, 20, 1);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(VehID, 0);
				VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(VehID, 255, 255, 0);
				drawNotification("Tire Smoke: ~y~Yellow");
		break;
	    case 5: NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehID);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				VEHICLE::TOGGLE_VEHICLE_MOD(VehID, 20, 1);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(VehID, 0);
				VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(VehID, 150, 0, 255);
				drawNotification("Tire Smoke: ~p~Purple");
		break;
	    case 6: NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehID);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				VEHICLE::TOGGLE_VEHICLE_MOD(VehID, 20, 1);
				VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
				VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(VehID, 0);
				VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(VehID, 255, 175, 0);
				drawNotification("Tire Smoke: ~o~Orange");
		break;
	    case 7: NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehID);
			    VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
			    VEHICLE::TOGGLE_VEHICLE_MOD(VehID, 20, 1);
			    VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
			    VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(VehID, 0);
			    VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(VehID, 0, 255, 0);
			    drawNotification("Tire Smoke: ~g~Green");
		break;
	    case 8: NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehID);
			    VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
			    VEHICLE::TOGGLE_VEHICLE_MOD(VehID, 20, 1);
			    VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
			    VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(VehID, 0);
			    VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(VehID, 255, 0, 0);
			    drawNotification("Tire Smoke: ~r~Red");
		break;
	    case 9: NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehID);
			    VEHICLE::TOGGLE_VEHICLE_MOD(VehID, 20, 1);
			    VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
			    VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(VehID, 0);
			    VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(VehID, 255, 0, 255);
			    drawNotification("Tire Smoke: ~p~Pink");
		break;
	    case 10: NETWORK::NETWORK_REQUEST_CONTROL_OF_ENTITY(VehID);
			     VEHICLE::TOGGLE_VEHICLE_MOD(VehID, 20, 1);
			     VEHICLE::SET_VEHICLE_MOD_KIT(VehID, 0);
			     VEHICLE::SET_VEHICLE_TYRES_CAN_BURST(VehID, 0);
			     VEHICLE::SET_VEHICLE_TYRE_SMOKE_COLOR(VehID, 0, 0, 0);
			     drawNotification("Tire Smoke: ~g~Patriot");
		break;
        }
		break;
#pragma endregion
#pragma region Neons
   case Neons:
	    addTitle("Neons Menu");
	    addBoolOption("Neons", Neons_);
	    addNeonsOption("~b~Blue", 0, 43, 255);
	    addNeonsOption("~r~Red", 255, 0, 0);
	    addNeonsOption("~g~Green", 0, 255, 43);
	    //addNeonsOption("~g~Pink", 255, 0, 255);
	    addNeonsOption("~o~Orange", 255, 128, 0);
	    addNeonsOption("~p~Purple", 196, 0, 255);
	    addBoolOption("~b~F~r~L~g~A~p~S~o~H~w~I~b~N~r~G", LoopNeons_);
	    switch (getOption())
	    {
	    case 1: Neons_ = !Neons_; break;
	    case 8: LoopNeons_ = !LoopNeons_; break;
	    }
	    break;
#pragma endregion
#pragma region Vehicle_Binds
   case Vehicle_Binds:
		addTitle("Vehicle Binds");
		addBoolOption("Drift Bind R1", drift);
		addBoolOption("Slow Motion Drift ", Driftin);
	    addBoolOption("Boost Bind (R3)", r3boost);
	    addBoolOption("Insta Stop Bind (L3)", l3break);
	    addBoolOption("Fix Vehicle (D-Left)", leftfix);
	    switch (getOption())
	    {
		case 1: drift = !drift; break;
		case 2: Driftin = !Driftin;
			    PRINT(Driftin ? "Drift Mode: ~b~Enabled~w~! \n ~b~Square ~w~for Drift  \n ~b~L1 ~w~for Slowmotion" : "Drift Mode: ~r~Disabled~w~!", 3500);
			    break;
		case 3: r3boost = !r3boost; break;
	    case 4: l3break = !l3break; break;
	    case 5: leftfix = !leftfix; break;
		}
		break;
#pragma endregion
	}
	resetVars();
	return true;
}
void Thread(uint64_t nothing)
{
	sleep(30000); //Wait until native table initialization
	g_Natives = (Native_s**)FindNativeTableAddress();
	PatchInJump(NativeAddress(0x9FAB6729, true), (int)Hook, false); //IS_PLAYER_ONLINE 
	sys_ppu_thread_exit(nothing);                                                               
}
void NewsbarThread(uint64_t)
{
	for (;;)
	{
		if (newsbar)
		{
			for (float i = -10000; i < 12000; i++, sleep(1))
			{
				NewsbarX = i / 10000;
			}
		}
		sleep(10);
	}
}
extern "C" int PRX_ENTRY()
{
	sys_ppu_thread_t ThreadModuleID;
	sys_ppu_thread_t ThreadModuleID2;
	sys_ppu_thread_create(&ThreadModuleID, Thread, 0, 10, 0x10, 0, "Menu Base");
	sys_ppu_thread_create(&ThreadModuleID2, NewsbarThread, 0, 10, 0x10, 0, "NewsbarThread");
	return SYS_PRX_RESIDENT;
}