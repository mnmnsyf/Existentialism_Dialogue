
#pragma once

#include "CoreMinimal.h"
#include "Quest/QuestBase.h"
#include "Engine/DataTable.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "QuestSubsystem.generated.h"

//DECLARE_DYNAMIC_DELEGATE_RetVal_OneParam(int32, FGetItemInfoDelegate, int32);

struct FQuestBase;

UCLASS()
class DIALOGUEPROJECT_API UQuestSubsystem : public UGameInstanceSubsystem
{
	GENERATED_BODY()

public:

	virtual bool ShouldCreateSubsystem(UObject* Outer) const override { return true; }

	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	virtual void Deinitialize() override;
	




	//���δ��������(ǰ������δ��ɣ�
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	void AddLockedQuest(int32 QuestID);

	//����ѽ�������ǰ����������ɣ�
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	void AddUnLockedQuest(int32 QuestID);
	
	//����������
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	void ReceiveQuest(int32 QuestID);

	//�������
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	void CompleteQuest(int32 QuestID);

	//��ȡ�����������佱����Ʒ
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	void GetQuestReward(int32 QuestID);

	//ͨ������id����ĳ���������Ϣ
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	FQuestBase GetQuestInfoByID(int32 QuestID);

	//��ȡ��ǰ�����ѽ��յ�����
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	TArray<FQuestBase> GetReceivedQuests();

	//��ȡ��ǰ��������ɵ�����
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	TArray<FQuestBase> GetCompletedQuests();

	//ͨ��ItemID��鱳���ж��������Ʒ
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	int32 GetItemNumByID(int32 ItemID);

	//��ȡ����״̬
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	EQuestState GetQuestState(int32 QuestID);

	//�޸�����״̬
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	void SetQuestState(int32 QuestID, EQuestState NewState);

	//NPCͷ����ʾ����ͼ��
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | NPC")
	void SetNPCQuestHintIcon();

private:
	//���������ݱ�
	TArray<FQuestBase> AllQuestsData;

	////δ���������
	//TArray<int32> LockedQuests;

	//�ѽ��������
	//TArray<FQuestBase> UnlockedQuests;

	//�ѽ��������
	TArray<FQuestBase> ReceivedQuests;

	//����������
	TArray<FQuestBase> CompletedQuests;

	////����ȡ���������
	//TArray<int32> GotRewardQuests;

	//ɱ�ּ�¼��
	//

public:
	/*UPROPERTY(BlueprintAssignable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	FGetItemInfoDelegate GetItemInfo;*/

	
};
