
#pragma once

#include "CoreMinimal.h"
#include "Quest/QuestBase.h"
#include "Engine/DataTable.h"
#include "Subsystems/GameInstanceSubsystem.h"
#include "QuestSubsystem.generated.h"

/*DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FindItemFromInventory, int32, ItemID);
UPROPERTY(BlueprintAssignable)
FindItemFromInventory FindItem;*/

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

	//�ύ����
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	void SubmitQuest(int32 QuestID);

	//��ȡ������
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	void GetRewardQuest(int32 QuestID);

	//ͨ������id����ĳ���������Ϣ
	//UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	//FQuestBase FindQuestInfoByID(int32 QuestID);

	 //��ȡ��ǰ�����ѽ��յ������UI
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	TArray<FQuestBase> GetReceiveQuest();

	 //��ȡ��ǰ��������ɵ������UI
	UFUNCTION(BlueprintCallable, Category = "QuestSubsystem | QuestGameInsSubsystem")
	TArray<FQuestBase> GetCompletedQuest();

private:
	TArray<FQuestBase> LockedQuests;
	TArray<FQuestBase> UnlockedQuests;
	TArray<FQuestBase> ReceivedQuests;
	TArray<FQuestBase> CompletedQuests;
	TArray<FQuestBase> GotRewardQuests;

public:
	
	

};
