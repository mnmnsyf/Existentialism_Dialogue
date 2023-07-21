// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "Engine/DataTable.h"
#include "ExistentialismBarGameInstance.generated.h"



UCLASS()
class DIALOGUEPROJECT_API UExistentialismBarGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:

	//任务细节数据表
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestSubsystem | QuestConfigTable", meta = (AllowPrivateAccess = "true"))
	class UDataTable* QuestDataTable;

	// 接取任务的声音
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QuestSubsystem | Sound", meta = (AllowPrivateAccess = "true"))
	class USoundCue* PickupSound;

	//完成任务的声音
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QuestSubsystem | Sound", meta = (AllowPrivateAccess = "true"))
	USoundCue* CompletedSound;

public:
	
};
