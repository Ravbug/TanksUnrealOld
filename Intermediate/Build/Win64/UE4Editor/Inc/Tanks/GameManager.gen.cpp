// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Tanks/GameManager.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameManager() {}
// Cross Module References
	TANKS_API UScriptStruct* Z_Construct_UScriptStruct_FTankTracker();
	UPackage* Z_Construct_UPackage__Script_Tanks();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FColor();
	TANKS_API UClass* Z_Construct_UClass_AGameManager_NoRegister();
	TANKS_API UClass* Z_Construct_UClass_AGameManager();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	TANKS_API UFunction* Z_Construct_UFunction_AGameManager_ResetTanks();
	TANKS_API UFunction* Z_Construct_UFunction_AGameManager_SpawnTank();
	TANKS_API UClass* Z_Construct_UClass_ATank_NoRegister();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FTransform();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
// End Cross Module References
class UScriptStruct* FTankTracker::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern TANKS_API uint32 Get_Z_Construct_UScriptStruct_FTankTracker_CRC();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FTankTracker, Z_Construct_UPackage__Script_Tanks(), TEXT("TankTracker"), sizeof(FTankTracker), Get_Z_Construct_UScriptStruct_FTankTracker_CRC());
	}
	return Singleton;
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FTankTracker(FTankTracker::StaticStruct, TEXT("/Script/Tanks"), TEXT("TankTracker"), false, nullptr, nullptr);
static struct FScriptStruct_Tanks_StaticRegisterNativesFTankTracker
{
	FScriptStruct_Tanks_StaticRegisterNativesFTankTracker()
	{
		UScriptStruct::DeferCppStructOps(FName(TEXT("TankTracker")),new UScriptStruct::TCppStructOps<FTankTracker>);
	}
} ScriptStruct_Tanks_StaticRegisterNativesFTankTracker;
	struct Z_Construct_UScriptStruct_FTankTracker_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Spawnpoint_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Spawnpoint;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isCOM_MetaData[];
#endif
		static void NewProp_isCOM_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isCOM;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Color_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_Color;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTankTracker_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "ModuleRelativePath", "GameManager.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FTankTracker_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FTankTracker>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTankTracker_Statics::NewProp_Spawnpoint_MetaData[] = {
		{ "Category", "TankTracker" },
		{ "ModuleRelativePath", "GameManager.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FTankTracker_Statics::NewProp_Spawnpoint = { UE4CodeGen_Private::EPropertyClass::Object, "Spawnpoint", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FTankTracker, Spawnpoint), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FTankTracker_Statics::NewProp_Spawnpoint_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FTankTracker_Statics::NewProp_Spawnpoint_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTankTracker_Statics::NewProp_isCOM_MetaData[] = {
		{ "Category", "TankTracker" },
		{ "ModuleRelativePath", "GameManager.h" },
	};
#endif
	void Z_Construct_UScriptStruct_FTankTracker_Statics::NewProp_isCOM_SetBit(void* Obj)
	{
		((FTankTracker*)Obj)->isCOM = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UScriptStruct_FTankTracker_Statics::NewProp_isCOM = { UE4CodeGen_Private::EPropertyClass::Bool, "isCOM", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(FTankTracker), &Z_Construct_UScriptStruct_FTankTracker_Statics::NewProp_isCOM_SetBit, METADATA_PARAMS(Z_Construct_UScriptStruct_FTankTracker_Statics::NewProp_isCOM_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FTankTracker_Statics::NewProp_isCOM_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FTankTracker_Statics::NewProp_Color_MetaData[] = {
		{ "Category", "TankTracker" },
		{ "ModuleRelativePath", "GameManager.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FTankTracker_Statics::NewProp_Color = { UE4CodeGen_Private::EPropertyClass::Struct, "Color", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(FTankTracker, Color), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(Z_Construct_UScriptStruct_FTankTracker_Statics::NewProp_Color_MetaData, ARRAY_COUNT(Z_Construct_UScriptStruct_FTankTracker_Statics::NewProp_Color_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FTankTracker_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTankTracker_Statics::NewProp_Spawnpoint,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTankTracker_Statics::NewProp_isCOM,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FTankTracker_Statics::NewProp_Color,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FTankTracker_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_Tanks,
		nullptr,
		&NewStructOps,
		"TankTracker",
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		sizeof(FTankTracker),
		alignof(FTankTracker),
		Z_Construct_UScriptStruct_FTankTracker_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UScriptStruct_FTankTracker_Statics::PropPointers),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FTankTracker_Statics::Struct_MetaDataParams, ARRAY_COUNT(Z_Construct_UScriptStruct_FTankTracker_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FTankTracker()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FTankTracker_CRC();
		UPackage* Outer = Z_Construct_UPackage__Script_Tanks();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("TankTracker"), sizeof(FTankTracker), Get_Z_Construct_UScriptStruct_FTankTracker_CRC(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FTankTracker_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FTankTracker_CRC() { return 3121550783U; }
	static FName NAME_AGameManager_SpawnTank = FName(TEXT("SpawnTank"));
	ATank* AGameManager::SpawnTank(FColor color, FTransform pos)
	{
		GameManager_eventSpawnTank_Parms Parms;
		Parms.color=color;
		Parms.pos=pos;
		ProcessEvent(FindFunctionChecked(NAME_AGameManager_SpawnTank),&Parms);
		return Parms.ReturnValue;
	}
	void AGameManager::StaticRegisterNativesAGameManager()
	{
		UClass* Class = AGameManager::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ResetTanks", &AGameManager::execResetTanks },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AGameManager_ResetTanks_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGameManager_ResetTanks_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GameManager.h" },
		{ "ToolTip", "resets the tanks after the round ends" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGameManager_ResetTanks_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGameManager, "ResetTanks", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x00080401, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGameManager_ResetTanks_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AGameManager_ResetTanks_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGameManager_ResetTanks()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGameManager_ResetTanks_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AGameManager_SpawnTank_Statics
	{
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_pos;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_color;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AGameManager_SpawnTank_Statics::NewProp_ReturnValue = { UE4CodeGen_Private::EPropertyClass::Object, "ReturnValue", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000580, 1, nullptr, STRUCT_OFFSET(GameManager_eventSpawnTank_Parms, ReturnValue), Z_Construct_UClass_ATank_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGameManager_SpawnTank_Statics::NewProp_pos = { UE4CodeGen_Private::EPropertyClass::Struct, "pos", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(GameManager_eventSpawnTank_Parms, pos), Z_Construct_UScriptStruct_FTransform, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AGameManager_SpawnTank_Statics::NewProp_color = { UE4CodeGen_Private::EPropertyClass::Struct, "color", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(GameManager_eventSpawnTank_Parms, color), Z_Construct_UScriptStruct_FColor, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGameManager_SpawnTank_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGameManager_SpawnTank_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGameManager_SpawnTank_Statics::NewProp_pos,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGameManager_SpawnTank_Statics::NewProp_color,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGameManager_SpawnTank_Statics::Function_MetaDataParams[] = {
		{ "Category", "Event" },
		{ "ModuleRelativePath", "GameManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGameManager_SpawnTank_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGameManager, "SpawnTank", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x0C820800, sizeof(GameManager_eventSpawnTank_Parms), Z_Construct_UFunction_AGameManager_SpawnTank_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_AGameManager_SpawnTank_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGameManager_SpawnTank_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_AGameManager_SpawnTank_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGameManager_SpawnTank()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGameManager_SpawnTank_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AGameManager_NoRegister()
	{
		return AGameManager::StaticClass();
	}
	struct Z_Construct_UClass_AGameManager_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_resetDelay_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_resetDelay;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_camera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_camera;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_cameraMount_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_cameraMount;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TankProperties_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp_TankProperties;
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TankProperties_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_WinsNeeded_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_WinsNeeded;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGameManager_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_Tanks,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AGameManager_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AGameManager_ResetTanks, "ResetTanks" }, // 3416588082
		{ &Z_Construct_UFunction_AGameManager_SpawnTank, "SpawnTank" }, // 442556280
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameManager_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "GameManager.h" },
		{ "ModuleRelativePath", "GameManager.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameManager_Statics::NewProp_resetDelay_MetaData[] = {
		{ "Category", "GameManager" },
		{ "ModuleRelativePath", "GameManager.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGameManager_Statics::NewProp_resetDelay = { UE4CodeGen_Private::EPropertyClass::Float, "resetDelay", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AGameManager, resetDelay), METADATA_PARAMS(Z_Construct_UClass_AGameManager_Statics::NewProp_resetDelay_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameManager_Statics::NewProp_resetDelay_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameManager_Statics::NewProp_camera_MetaData[] = {
		{ "Category", "GameManager" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "GameManager.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGameManager_Statics::NewProp_camera = { UE4CodeGen_Private::EPropertyClass::Object, "camera", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000080009, 1, nullptr, STRUCT_OFFSET(AGameManager, camera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGameManager_Statics::NewProp_camera_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameManager_Statics::NewProp_camera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameManager_Statics::NewProp_cameraMount_MetaData[] = {
		{ "Category", "GameManager" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "GameManager.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGameManager_Statics::NewProp_cameraMount = { UE4CodeGen_Private::EPropertyClass::Object, "cameraMount", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000080009, 1, nullptr, STRUCT_OFFSET(AGameManager, cameraMount), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGameManager_Statics::NewProp_cameraMount_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameManager_Statics::NewProp_cameraMount_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameManager_Statics::NewProp_TankProperties_MetaData[] = {
		{ "Category", "GameManager" },
		{ "ModuleRelativePath", "GameManager.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AGameManager_Statics::NewProp_TankProperties = { UE4CodeGen_Private::EPropertyClass::Array, "TankProperties", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AGameManager, TankProperties), METADATA_PARAMS(Z_Construct_UClass_AGameManager_Statics::NewProp_TankProperties_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameManager_Statics::NewProp_TankProperties_MetaData)) };
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGameManager_Statics::NewProp_TankProperties_Inner = { UE4CodeGen_Private::EPropertyClass::Struct, "TankProperties", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0000000000000000, 1, nullptr, 0, Z_Construct_UScriptStruct_FTankTracker, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameManager_Statics::NewProp_WinsNeeded_MetaData[] = {
		{ "Category", "GameManager" },
		{ "ModuleRelativePath", "GameManager.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AGameManager_Statics::NewProp_WinsNeeded = { UE4CodeGen_Private::EPropertyClass::Int, "WinsNeeded", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(AGameManager, WinsNeeded), METADATA_PARAMS(Z_Construct_UClass_AGameManager_Statics::NewProp_WinsNeeded_MetaData, ARRAY_COUNT(Z_Construct_UClass_AGameManager_Statics::NewProp_WinsNeeded_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGameManager_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameManager_Statics::NewProp_resetDelay,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameManager_Statics::NewProp_camera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameManager_Statics::NewProp_cameraMount,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameManager_Statics::NewProp_TankProperties,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameManager_Statics::NewProp_TankProperties_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameManager_Statics::NewProp_WinsNeeded,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGameManager_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGameManager>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGameManager_Statics::ClassParams = {
		&AGameManager::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_AGameManager_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_AGameManager_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_AGameManager_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_AGameManager_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGameManager()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGameManager_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGameManager, 4019903720);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGameManager(Z_Construct_UClass_AGameManager, &AGameManager::StaticClass, TEXT("/Script/Tanks"), TEXT("AGameManager"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGameManager);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
