// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "QuestBase.generated.h"

UENUM(BlueprintType)
enum class EQuestType : uint8
{
	//�ɼ�����
	EQT_Collect UMETA(DisplayName = "Collect"),

	//�Ի�����
	EQT_Dialogue UMETA(DisplayName = "Dialogue"),

	//ս������
	EQT_Combat UMETA(DisplayName = "Combat"),

	//��������
	EQT_Puzzle UMETA(DisplayName = "Puzzle"),

	//��������
	EQT_Other UMETA(DisplayName = "Other")
};

UENUM(BlueprintType)
enum class EQuestState : uint8
{
	//δ������ǰ������δ���
	QES_Locked UMETA(DisplayName = "Locked"),
	//�ѽ����������ǰ��������û����
	QES_Unlocked UMETA(DisplayName = "Unlocked"),
	//�ѽ��գ�ͨ���Ի��������񣬻����Զ��������񣬿�ʼִ������
	QES_Received UMETA(DisplayName = "Receieved"),
	//����ɣ������ѽ�����������δ��ȡ
	QES_Completed UMETA(DisplayName = "Completed"),
	//����ȡ����
	QES_RewardReceived UMETA(DisplayName = "RewardReceived"),
};

USTRUCT(BlueprintType)
struct FQuestBase : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()

public:
	// ����id
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	int32 QuestID = -1;

	// ��������
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EQuestType QuestType = EQuestType::EQT_Collect;

	// ��������
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString QuestName = TEXT("QuestName");

	// ��������
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString QuestDescription = TEXT("None");

	// ����ǰ������ -  ͨ���Ի�������ʰȡĳ����Ʒ����  �����л���ʲô ����
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<int32> PreQuestConditions;

	// ����������� - ͨ���Ի��������ʰȡĳ����Ʒ������ĳ����Ʒ�������?
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FString QuestCompleteConditions = TEXT("None");

	// ������ - ��Ʒid������
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TMap<int32, int32> QuestRewards;

	// �Ƿ��Զ���ɣ�����Ҫ�Ի��Ϳ����������
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsAutoComplete = false;

	//���񷢲�����id
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName QuestPublisherID;

	//�����ύ����id
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FName QuestReceivedID;

	//����״̬
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	EQuestState QuestState = EQuestState::QES_Locked;

	//�Ƿ�����������
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool IsMainQuest = true;
};

//UCLASS()
//class DIALOGUEPROJECT_API AQuestBase : public AActor
//{
//	GENERATED_BODY()
//	
//public:	
//	// Sets default values for this actor's properties
//	AQuestBase();
//
//protected:
//	// Called when the game starts or when spawned
//	virtual void BeginPlay() override;
//
//public:	
//	// Called every frame
//	virtual void Tick(float DeltaTime) override;
//
//private:
//	//����ϸ�����ݱ�
//	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "QuestSubsystem | QuestConfigTable", meta = (AllowPrivateAccess = "true"))
//	class UDataTable* FQuestBase;
//
//};