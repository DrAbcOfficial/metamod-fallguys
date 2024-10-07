#pragma once

#include <signatures_template.h>

#ifdef _WIN32
#define build_number_Signature "\xE8\x2A\x2A\x2A\x2A\x50\x68\x2A\x2A\x2A\x2A\x6A\x30\x68"
#define SV_Physics_Signature "\xDD\x05\x2A\x2A\x2A\x2A\x83\xEC\x14\xD9\x1D\x2A\x2A\x2A\x2A\x55\xFF\x15"
#define SV_PushEntity_Signature "\x81\xEC\x2A\x2A\x2A\x2A\xA1\x2A\x2A\x2A\x2A\x33\xC4\x89\x44\x24\x2A\x8B\x84\x24\x2A\x00\x00\x00"
#define SV_PushMove_Signature "\x81\xEC\x2A\x2A\x2A\x2A\xA1\x2A\x2A\x2A\x2A\x33\xC4\x89\x44\x24\x2A\x2A\x8B\xBC\x24\x88\x00\x00\x00\xD9"
#define SV_PushRotate_Signature "\x81\xEC\x2A\x2A\x2A\x2A\xA1\x2A\x2A\x2A\x2A\x33\xC4\x89\x84\x24\x2A\x00\x00\x00\x2A\x8B\xBC\x24\xC0\x00\x00\x00\xD9"
#define SV_TestEntityPosition_Signature "\x81\xEC\x2A\x2A\x00\x00\xA1\x2A\x2A\x2A\x2A\x33\xC4\x89\x84\x24\x2A\x2A\x00\x00\x2A\x8B\x9C\x24\x2A\x2A\x00\x00\x2A\x2A\x2A\x8B\x83\x24\x02\x00\x00"
#define SV_LinkEdict_Signature "\x56\x8B\x74\x24\x08\x8B\x4E\x08\x2A\x8D\x7E\x08\x85\xC9\x74"
#define SV_SingleClipMoveToEntity_Signature "\xFF\x73\x3C\xFF\x73\x1C\xFF\x73\x18\xFF\x73\x38\x55\xE8"
#define SV_SingleClipMoveToEntity_10152_Signature SV_SingleClipMoveToEntity_Signature
#define SV_WriteMovevarsToClient_Signature "\x56\x8B\x74\x24\x08\x6A\x2C\x56\xE8\x2A\x2A\x2A\x2A\xD9\x05"

#define CPlayerMove_PlayStepSound_Signature "\xF3\x0F\x11\x0C\x24\x8B\xCE\x2A\xE8"
#define PM_PlaySoundFX_SERVER_Signature "\xC7\x44\x24\x04\xCD\xCC\x4C\x3F\xC7\x04\x24\x00\x00\x80\x3F\x68\x2A\x2A\x2A\x2A\x6A\x02\x50\x8B\x01\x40\x50\xE8"

#define sv_models_Signature "\x3D\xFE\x1F\x00\x00\x2A\x2A\x0F\xAE\xE8\xFF\x34\x8D"
#define host_frametime_Signature "\xD8\x83\xA8\x00\x00\x00\xD9\x9B\xA8\x00\x00\x00\xE8\x2A\x2A\x2A\x2A\xDD\x05"
#define pmovevars_Signature "\x56\x8B\x74\x24\x08\x6A\x2C\x56\xE8\x2A\x2A\x2A\x2A\xD9\x05"
#define sv_areanodes_Signature "\x8D\x84\x24\xA0\x00\x00\x00\x50\x68\x2A\x2A\x2A\x2A\xE8"
#define pg_groupop_Signature "\xE8\x2A\x2A\x2A\x2A\x83\xC4\x2A\x83\xF8\xFF\x75\x2A\x8B\x0D\x2A\x2A\x2A\x2A\x8B\x15"
#define pg_groupmask_Signature pg_groupop_Signature

#define CLIENT_DLL_NAME "client.dll"

#define CLIENT_DLL_PATH "cl_dlls\\client.dll"

#define FMOD_DLL_NAME "fmodex.dll"

#define FMOD_DLL_PATH "%s\\fmodex.dll"

#else

#define build_number_Symbol "_Z12build_numberv"
#define SV_Physics_Symbol "_Z10SV_Physicsv"
#define SV_PushEntity_Symbol "_Z13SV_PushEntityP7edict_sPf"
#define SV_PushMove_Symbol "_Z11SV_PushMoveP7edict_sf"
#define SV_PushRotate_Symbol "_Z13SV_PushRotateP7edict_sf"
#define SV_WriteMovevarsToClient_Symbol "_Z24SV_WriteMovevarsToClientP9sizebuf_s"
#define SV_TestEntityPosition_Symbol "_Z21SV_TestEntityPositionP7edict_s"
#define SV_SingleClipMoveToEntity_Symbol "_Z25SV_SingleClipMoveToEntityP7edict_sPKfS2_S2_S2_P7trace_t"
#define SV_SingleClipMoveToEntity_10152_Symbol SV_SingleClipMoveToEntity_Symbol
#define SV_LinkEdict_Symbol "_Z12SV_LinkEdictP7edict_si"

#define CPlayerMove_PlayStepSound_Signature "\x89\x2A\x0F\x2A\x2A\x89\x2A\x2A\x2A\xD9\x2A\x2A\x2A\x89\x2A\x2A\x2A\x89\x2A\x2A\xE8"
#define CPlayerMove_PlayStepSound_Symbol "_ZN11CPlayerMove13PlayStepSoundEifb"

#define PM_PlaySoundFX_SERVER_Signature "\xC7\x44\x24\x2A\x02\x00\x00\x00\x8D\x2A\x2A\x89\x2A\x2A\x2A\x8B\x00\x83\xC0\x01\x89\x2A\x2A\xE8"
#define PM_PlaySoundFX_SERVER_Symbol "PM_PlaySoundFX_SERVER"

#define sv_Symbol "sv"
#define sv_models_Symbol "\x8B\x84\x82\x2A\x2A\x2A\x00\x89\x04\x24\xE8"
#define host_frametime_Symbol "host_frametime"
#define pmovevars_Symbol "movevars"
#define sv_areanodes_Symbol "sv_areanodes"
#define pg_groupop_Symbol "g_groupop"
#define pg_groupmask_Symbol "g_groupmask"

#define CLIENT_DLL_NAME "client.so"

#define CLIENT_DLL_PATH "cl_dlls\\client.so"

#define FMOD_DLL_NAME "fmodex.so"

#define FMOD_DLL_PATH "%s\\fmodex.so"

#endif