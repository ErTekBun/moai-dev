// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#ifndef	MOAICOROUTINE_H
#define	MOAICOROUTINE_H

#include <moai-sim/MOAIAction.h>

//================================================================//
// MOAICoroutine
//================================================================//
/**	@name MOAICoroutine
	@text Binds a Lua coroutine to a MOAIAction.
*/
class MOAICoroutine :
	public MOAIAction {
private:

	MOAILuaSharedPtr < MOAIAction > mDefaultParent;

	MOAILuaMemberRef	mRef; // reference to the coroutine
	lua_State*			mState;
	u32					mNarg;
	STLString			mFuncName;
	STLString			mTrackingGroup;
	
	bool				mIsUpdating;
	bool				mIsActive;
	bool				mIsFirstRun;
	
	//----------------------------------------------------------------//
	static int			_blockOnAction			( lua_State* L );
	static int			_currentThread			( lua_State* L );
	static int			_getHistogram			( lua_State* L );
	static int			_getTrackingGroup		( lua_State* L );
	static int			_reportHistogram		( lua_State* L );
	static int			_reportLeaks			( lua_State* L );
	static int			_run					( lua_State* L );
	static int			_setDefaultParent		( lua_State* L );
	static int			_setTrackingGroup		( lua_State* L );
	
	//----------------------------------------------------------------//
	void				OnStart					();
	void				OnStop					();

protected:
	STLString			GetDebugInfo			() const;

public:
	
	DECL_LUA_FACTORY ( MOAICoroutine )
	
	//----------------------------------------------------------------//						
	bool				IsDone					();
						MOAICoroutine			();
						~MOAICoroutine			();
	void				OnUpdate				( float step );
	void				RegisterLuaClass		( MOAILuaState& state );
	void				RegisterLuaFuncs		( MOAILuaState& state );
};

#endif
