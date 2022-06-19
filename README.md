# metamod-fallguys

This is a metamod plugin for [Fall Guys in Sven Co-op](https://github.com/hzqst/sven-fallguys) as feature expansion.

# What it does ?

## Better Player vs Brush Entities Interaction

1. Brush entity with `pev.movetype = MOVETYPE_PUSH` , `pev.solid = SOLID_BSP` and `pev.sequence == 114514` is **Super Pusher**.

2. Point entity with `(pev.solid == SOLID_SLIDEBOX or pev.solid == SOLID_BBOX)` and `(pev.movetype == MOVETYPE_STEP or pev.movetype == MOVETYPE_WALK)` is **Pushee**

3. **Pushee** will be pushed backward along with **another Pushee who is trying to block it** instead of getting blocked by **Super Pusher**.

4. `void Touch( CBaseEntity@ pOther )` will get called when **Super Pusher** impacts or hits any **Pushee** positively. `pev.sequence` of **Super Pusher** will be set to `1919810` temporarily in this scenario.

## AngelScript interface expansion

### Hook AddToFullPack

```
g_Hooks.RegisterHook(Hooks::Player::PlayerAddToFullPack, @PlayerAddToFullPack);// register at initialization
```

```
HookReturnCode PlayerAddToFullPack( entity_state_t@ state, int e, edict_t @ent, edict_t@ host, int hostflags, int player, uint& out uiFlags )
{
   //if uiFlags is set to 1, the entity will not be transmitted to client represented by edict_t@ host.
    return HOOK_HANDLED;
}
```

### Hook post call of PlayerPostThink (aka PlayerPostThink_Post)

```
g_Hooks.RegisterHook(Hooks::Player::PlayerPostThinkPost, @PlayerPostThinkPost);// register at initialization
```

```
//You can override player's pev.sequence or some other shit which is updated on every frame in PlayerPostThink
HookReturnCode PlayerPostThinkPost(CBasePlayer@ pPlayer)
{
   return HOOK_CONTINUE;
}
```

### Hook PlayerTouchTrigger

The PlayerTouchTrigger get called when player touches a trigger entity (pev.solid == SOLID_TRIGGER) positively.

pPlayer.pev.velocity will be set to impactvelocity temporarily in this scenario.

Any changes to pPlayer.pev.velocity will be dropped and ignored.

```
g_Hooks.RegisterHook(Hooks::Player::PlayerTouchTrigger, @PlayerTouchTrigger);

```

```

HookReturnCode PlayerTouchTrigger( CBasePlayer@ pPlayer, CBaseEntity@ pOther )
{
    return HOOK_CONTINUE;
}
```

### Hook PlayerTouchImpact

The PlayerTouchImpact get called when player touches a solid entity (pev.solid == SOLID_BBOX or pev.solid == SOLID_SLIDEBOX or pev.solid == SOLID_BSP) positively.

pPlayer.pev.velocity will be set to impactvelocity temporarily in this scenario.

Any changes to pPlayer.pev.velocity will be dropped and ignored.

```
g_Hooks.RegisterHook(Hooks::Player::PlayerTouchImpact, @PlayerTouchImpact);

```

```

HookReturnCode PlayerTouchImpact( CBasePlayer@ pPlayer, CBaseEntity@ pOther )
{
    return HOOK_CONTINUE;
}
```

### Get player's view entity (e.g trigger_camera)

```
//edict_t@ GetViewEntity(edict_t@ pClient)
//Warning: pClient must be a valid client edict

edict_t@viewent = g_EngineFuncs.GetViewEntity(pPlayer.edict());
```

### You are welcome to request for any new hook which is not implemented in Sven Co-op yet.

# Installation

1. Copy everything from `build` directory into `\steamapps\common\Sven Co-op\Sven Co-op\svencoop` *(Warning: `svencoop_addon` and `svencoop_downloads` are not supported)*

# Build Instruction (Windows)

1. You should have Visual Studio 2017 or 2019 with vc141 or vc142 toolset installed.

2. run `build-all-win32.bat`

3. `metamod.dll` and `fallguys.dll` should be generated at `build/addons/metamod/dlls` if no error(s) occours.

# Build Instruction (Linux)

1. Youl should have GNU C++ Build environment installed. Install with `sudo apt-get install make build-essential gcc gcc-multilib g++-multilib` if something is missing.

2. `make OPT=opt install` or `./build-all-linux.sh` (Remember to give execution privilege if permission denied)

3. `metamod.so` and `fallguys.so` should be generated at `build/addons/metamod/dlls` if no error(s) occours.
