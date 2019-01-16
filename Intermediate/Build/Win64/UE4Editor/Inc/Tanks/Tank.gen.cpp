// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "Tanks/Tank.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTank() {}
// Cross Module References
	TANKS_API UClass* Z_Construct_UClass_ATank_NoRegister();
	TANKS_API UClass* Z_Construct_UClass_ATank();
	ENGINE_API UClass* Z_Construct_UClass_APawn();
	UPackage* Z_Construct_UPackage__Script_Tanks();
	TANKS_API UFunction* Z_Construct_UFunction_ATank_Damage();
	TANKS_API UFunction* Z_Construct_UFunction_ATank_Die();
	TANKS_API UFunction* Z_Construct_UFunction_ATank_Fire();
	TANKS_API UFunction* Z_Construct_UFunction_ATank_SetSelfVisibility();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
// End Cross Module References
	static FName NAME_ATank_Die = FName(TEXT("Die"));
	void ATank::Die()
	{
		ProcessEvent(FindFunctionChecked(NAME_ATank_Die),NULL);
	}
	static FName NAME_ATank_Fire = FName(TEXT("Fire"));
	void ATank::Fire(int32 power)
	{
		Tank_eventFire_Parms Parms;
		Parms.power=power;
		ProcessEvent(FindFunctionChecked(NAME_ATank_Fire),&Parms);
	}
	static FName NAME_ATank_SetSelfVisibility = FName(TEXT("SetSelfVisibility"));
	void ATank::SetSelfVisibility(bool visible)
	{
		Tank_eventSetSelfVisibility_Parms Parms;
		Parms.visible=visible ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_ATank_SetSelfVisibility),&Parms);
	}
	void ATank::StaticRegisterNativesATank()
	{
		UClass* Class = ATank::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Damage", &ATank::execDamage },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ATank_Damage_Statics
	{
		struct Tank_eventDamage_Parms
		{
			int32 amount;
		};
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_amount;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ATank_Damage_Statics::NewProp_amount = { UE4CodeGen_Private::EPropertyClass::Int, "amount", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Tank_eventDamage_Parms, amount), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATank_Damage_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATank_Damage_Statics::NewProp_amount,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATank_Damage_Statics::Function_MetaDataParams[] = {
		{ "Category", "Actor" },
		{ "ModuleRelativePath", "Tank.h" },
		{ "ToolTip", "the tank gets damaged by explosions" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATank_Damage_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATank, "Damage", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020400, sizeof(Tank_eventDamage_Parms), Z_Construct_UFunction_ATank_Damage_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ATank_Damage_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATank_Damage_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ATank_Damage_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATank_Damage()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATank_Damage_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATank_Die_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATank_Die_Statics::Function_MetaDataParams[] = {
		{ "Category", "Actor" },
		{ "ModuleRelativePath", "Tank.h" },
		{ "ToolTip", "the tank explodes and removes itself" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATank_Die_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATank, "Die", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, 0, nullptr, 0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATank_Die_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ATank_Die_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATank_Die()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATank_Die_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATank_Fire_Statics
	{
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_power;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UFunction_ATank_Fire_Statics::NewProp_power = { UE4CodeGen_Private::EPropertyClass::Int, "power", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, STRUCT_OFFSET(Tank_eventFire_Parms, power), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATank_Fire_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATank_Fire_Statics::NewProp_power,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATank_Fire_Statics::Function_MetaDataParams[] = {
		{ "Category", "Actor" },
		{ "ModuleRelativePath", "Tank.h" },
		{ "ToolTip", "fires a shell" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATank_Fire_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATank, "Fire", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, sizeof(Tank_eventFire_Parms), Z_Construct_UFunction_ATank_Fire_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ATank_Fire_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATank_Fire_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ATank_Fire_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATank_Fire()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATank_Fire_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ATank_SetSelfVisibility_Statics
	{
		static void NewProp_visible_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_visible;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UFunction_ATank_SetSelfVisibility_Statics::NewProp_visible_SetBit(void* Obj)
	{
		((Tank_eventSetSelfVisibility_Parms*)Obj)->visible = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ATank_SetSelfVisibility_Statics::NewProp_visible = { UE4CodeGen_Private::EPropertyClass::Bool, "visible", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000080, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(Tank_eventSetSelfVisibility_Parms), &Z_Construct_UFunction_ATank_SetSelfVisibility_Statics::NewProp_visible_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ATank_SetSelfVisibility_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ATank_SetSelfVisibility_Statics::NewProp_visible,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ATank_SetSelfVisibility_Statics::Function_MetaDataParams[] = {
		{ "Category", "Actor" },
		{ "ModuleRelativePath", "Tank.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ATank_SetSelfVisibility_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ATank, "SetSelfVisibility", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x08020800, sizeof(Tank_eventSetSelfVisibility_Parms), Z_Construct_UFunction_ATank_SetSelfVisibility_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UFunction_ATank_SetSelfVisibility_Statics::PropPointers), 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ATank_SetSelfVisibility_Statics::Function_MetaDataParams, ARRAY_COUNT(Z_Construct_UFunction_ATank_SetSelfVisibility_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ATank_SetSelfVisibility()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ATank_SetSelfVisibility_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ATank_NoRegister()
	{
		return ATank::StaticClass();
	}
	struct Z_Construct_UClass_ATank_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_name_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_name;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_isCOM_MetaData[];
#endif
		static void NewProp_isCOM_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_isCOM;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Mesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Mesh;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATank_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_APawn,
		(UObject* (*)())Z_Construct_UPackage__Script_Tanks,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ATank_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ATank_Damage, "Damage" }, // 3185691086
		{ &Z_Construct_UFunction_ATank_Die, "Die" }, // 3113526882
		{ &Z_Construct_UFunction_ATank_Fire, "Fire" }, // 1664232249
		{ &Z_Construct_UFunction_ATank_SetSelfVisibility, "SetSelfVisibility" }, // 2204673427
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATank_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "Tank.h" },
		{ "ModuleRelativePath", "Tank.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATank_Statics::NewProp_name_MetaData[] = {
		{ "Category", "Tank" },
		{ "ModuleRelativePath", "Tank.h" },
		{ "ToolTip", "the name of this tank" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_ATank_Statics::NewProp_name = { UE4CodeGen_Private::EPropertyClass::Str, "name", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, STRUCT_OFFSET(ATank, name), METADATA_PARAMS(Z_Construct_UClass_ATank_Statics::NewProp_name_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATank_Statics::NewProp_name_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATank_Statics::NewProp_isCOM_MetaData[] = {
		{ "Category", "Tank" },
		{ "ModuleRelativePath", "Tank.h" },
		{ "ToolTip", "whether or not this tank is computer-controlled" },
	};
#endif
	void Z_Construct_UClass_ATank_Statics::NewProp_isCOM_SetBit(void* Obj)
	{
		((ATank*)Obj)->isCOM = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ATank_Statics::NewProp_isCOM = { UE4CodeGen_Private::EPropertyClass::Bool, "isCOM", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000001, 1, nullptr, sizeof(bool), UE4CodeGen_Private::ENativeBool::Native, sizeof(ATank), &Z_Construct_UClass_ATank_Statics::NewProp_isCOM_SetBit, METADATA_PARAMS(Z_Construct_UClass_ATank_Statics::NewProp_isCOM_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATank_Statics::NewProp_isCOM_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATank_Statics::NewProp_Mesh_MetaData[] = {
		{ "Category", "Test" },
		{ "ModuleRelativePath", "Tank.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATank_Statics::NewProp_Mesh = { UE4CodeGen_Private::EPropertyClass::Object, "Mesh", RF_Public|RF_Transient|RF_MarkAsNative, (EPropertyFlags)0x0010000000000005, 1, nullptr, STRUCT_OFFSET(ATank, Mesh), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ATank_Statics::NewProp_Mesh_MetaData, ARRAY_COUNT(Z_Construct_UClass_ATank_Statics::NewProp_Mesh_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATank_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATank_Statics::NewProp_name,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATank_Statics::NewProp_isCOM,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATank_Statics::NewProp_Mesh,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATank_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATank>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ATank_Statics::ClassParams = {
		&ATank::StaticClass,
		DependentSingletons, ARRAY_COUNT(DependentSingletons),
		0x009000A0u,
		FuncInfo, ARRAY_COUNT(FuncInfo),
		Z_Construct_UClass_ATank_Statics::PropPointers, ARRAY_COUNT(Z_Construct_UClass_ATank_Statics::PropPointers),
		nullptr,
		&StaticCppClassTypeInfo,
		nullptr, 0,
		METADATA_PARAMS(Z_Construct_UClass_ATank_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_ATank_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ATank()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ATank_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ATank, 1282306095);
	static FCompiledInDefer Z_CompiledInDefer_UClass_ATank(Z_Construct_UClass_ATank, &ATank::StaticClass, TEXT("/Script/Tanks"), TEXT("ATank"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATank);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
