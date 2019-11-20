// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "sidescrolling_action/sidescrolling_actionGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodesidescrolling_actionGameMode() {}
// Cross Module References
	SIDESCROLLING_ACTION_API UClass* Z_Construct_UClass_Asidescrolling_actionGameMode_NoRegister();
	SIDESCROLLING_ACTION_API UClass* Z_Construct_UClass_Asidescrolling_actionGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_sidescrolling_action();
// End Cross Module References
	void Asidescrolling_actionGameMode::StaticRegisterNativesAsidescrolling_actionGameMode()
	{
	}
	UClass* Z_Construct_UClass_Asidescrolling_actionGameMode_NoRegister()
	{
		return Asidescrolling_actionGameMode::StaticClass();
	}
	struct Z_Construct_UClass_Asidescrolling_actionGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_Asidescrolling_actionGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_sidescrolling_action,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_Asidescrolling_actionGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "sidescrolling_actionGameMode.h" },
		{ "ModuleRelativePath", "sidescrolling_actionGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_Asidescrolling_actionGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<Asidescrolling_actionGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_Asidescrolling_actionGameMode_Statics::ClassParams = {
		&Asidescrolling_actionGameMode::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802A8u,
		METADATA_PARAMS(Z_Construct_UClass_Asidescrolling_actionGameMode_Statics::Class_MetaDataParams, ARRAY_COUNT(Z_Construct_UClass_Asidescrolling_actionGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_Asidescrolling_actionGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_Asidescrolling_actionGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(Asidescrolling_actionGameMode, 1399113286);
	template<> SIDESCROLLING_ACTION_API UClass* StaticClass<Asidescrolling_actionGameMode>()
	{
		return Asidescrolling_actionGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_Asidescrolling_actionGameMode(Z_Construct_UClass_Asidescrolling_actionGameMode, &Asidescrolling_actionGameMode::StaticClass, TEXT("/Script/sidescrolling_action"), TEXT("Asidescrolling_actionGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(Asidescrolling_actionGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
