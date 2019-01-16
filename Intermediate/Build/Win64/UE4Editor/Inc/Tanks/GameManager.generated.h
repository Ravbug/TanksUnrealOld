// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FColor;
struct FTransform;
class ATank;
#ifdef TANKS_GameManager_generated_h
#error "GameManager.generated.h already included, missing '#pragma once' in GameManager.h"
#endif
#define TANKS_GameManager_generated_h

#define Tanks_Source_Tanks_GameManager_h_17_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FTankTracker_Statics; \
	TANKS_API static class UScriptStruct* StaticStruct();


#define Tanks_Source_Tanks_GameManager_h_29_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execResetTanks) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ResetTanks(); \
		P_NATIVE_END; \
	}


#define Tanks_Source_Tanks_GameManager_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execResetTanks) \
	{ \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		P_THIS->ResetTanks(); \
		P_NATIVE_END; \
	}


#define Tanks_Source_Tanks_GameManager_h_29_EVENT_PARMS \
	struct GameManager_eventSpawnTank_Parms \
	{ \
		FColor color; \
		FTransform pos; \
		ATank* ReturnValue; \
 \
		/** Constructor, initializes return property only **/ \
		GameManager_eventSpawnTank_Parms() \
			: ReturnValue(NULL) \
		{ \
		} \
	};


#define Tanks_Source_Tanks_GameManager_h_29_CALLBACK_WRAPPERS
#define Tanks_Source_Tanks_GameManager_h_29_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGameManager(); \
	friend struct Z_Construct_UClass_AGameManager_Statics; \
public: \
	DECLARE_CLASS(AGameManager, APawn, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Tanks"), NO_API) \
	DECLARE_SERIALIZER(AGameManager)


#define Tanks_Source_Tanks_GameManager_h_29_INCLASS \
private: \
	static void StaticRegisterNativesAGameManager(); \
	friend struct Z_Construct_UClass_AGameManager_Statics; \
public: \
	DECLARE_CLASS(AGameManager, APawn, COMPILED_IN_FLAGS(0), CASTCLASS_None, TEXT("/Script/Tanks"), NO_API) \
	DECLARE_SERIALIZER(AGameManager)


#define Tanks_Source_Tanks_GameManager_h_29_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGameManager(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGameManager) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameManager); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameManager); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGameManager(AGameManager&&); \
	NO_API AGameManager(const AGameManager&); \
public:


#define Tanks_Source_Tanks_GameManager_h_29_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGameManager(AGameManager&&); \
	NO_API AGameManager(const AGameManager&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGameManager); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGameManager); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGameManager)


#define Tanks_Source_Tanks_GameManager_h_29_PRIVATE_PROPERTY_OFFSET
#define Tanks_Source_Tanks_GameManager_h_26_PROLOG \
	Tanks_Source_Tanks_GameManager_h_29_EVENT_PARMS


#define Tanks_Source_Tanks_GameManager_h_29_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Tanks_Source_Tanks_GameManager_h_29_PRIVATE_PROPERTY_OFFSET \
	Tanks_Source_Tanks_GameManager_h_29_RPC_WRAPPERS \
	Tanks_Source_Tanks_GameManager_h_29_CALLBACK_WRAPPERS \
	Tanks_Source_Tanks_GameManager_h_29_INCLASS \
	Tanks_Source_Tanks_GameManager_h_29_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define Tanks_Source_Tanks_GameManager_h_29_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	Tanks_Source_Tanks_GameManager_h_29_PRIVATE_PROPERTY_OFFSET \
	Tanks_Source_Tanks_GameManager_h_29_RPC_WRAPPERS_NO_PURE_DECLS \
	Tanks_Source_Tanks_GameManager_h_29_CALLBACK_WRAPPERS \
	Tanks_Source_Tanks_GameManager_h_29_INCLASS_NO_PURE_DECLS \
	Tanks_Source_Tanks_GameManager_h_29_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID Tanks_Source_Tanks_GameManager_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
