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

	//����ϸ�����ݱ�
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestSubsystem | QuestConfigTable", meta = (AllowPrivateAccess = "true"))
	class UDataTable* QuestDataTable;

	// ��ȡ���������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QuestSubsystem | Sound", meta = (AllowPrivateAccess = "true"))
	class USoundCue* PickupSound;

	//������������
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "QuestSubsystem | Sound", meta = (AllowPrivateAccess = "true"))
	USoundCue* CompletedSound;

public:
	
};
