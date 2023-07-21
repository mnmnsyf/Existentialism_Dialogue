// Fill out your copyright notice in the Description page of Project Settings.


#include "Quest/QuestSubsystem.h"
#include "Kismet/GameplayStatics.h"
#include "GamePlay/ExistentialismBarGameInstance.h"

void UQuestSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	Super::Initialize(Collection);

	UExistentialismBarGameInstance* MyGameInstance = Cast<UExistentialismBarGameInstance>(GetGameInstance());
	UDataTable* QuestDataTable = MyGameInstance->QuestDataTable;
	TArray<FName> RowNames = QuestDataTable->GetRowNames();
	FString ContextString;

	for (auto& it : RowNames)
	{
		FQuestBase* Quest = QuestDataTable->FindRow<FQuestBase>(it, ContextString);
		EQuestState State = Quest->QuestState;
		if (Quest)
		{
			AllQuestsData.Add(*Quest);
		}
	}
}

void UQuestSubsystem::Deinitialize()
{
	Super::Deinitialize();

}

void UQuestSubsystem::AddLockedQuest(int32 QuestID)
{
	AddUnLockedQuest(QuestID);
}

//�ж��Ƿ��������ѽ�������ǰ����������ɣ�
void UQuestSubsystem::AddUnLockedQuest(int32 QuestID)
{
	FQuestBase Quest = GetQuestInfoByID(QuestID);

	//���ǰ������Ϊ��, �޸�����״̬������checkǰ�������Ƿ������
	if (Quest.PreQuestConditions.IsEmpty())
	{
		SetQuestState(QuestID, EQuestState::QES_Unlocked);
	}
	else
	{
		bool isCompletePrecondition = true;
		for (auto& it : Quest.PreQuestConditions) 
		{
			if ((GetQuestState(it) != EQuestState::QES_Completed) && (GetQuestState(it) != EQuestState::QES_RewardReceived))
			{
				isCompletePrecondition = false;
				break;
			}
		}

		if (isCompletePrecondition == true) 
		{
			SetQuestState(QuestID, EQuestState::QES_Unlocked);
		}
	}

	//��������UI,���"�ѽ�����ִ��"�������б�UI�� ��?��֪��Ҫ��Ҫ�㣬������¶��

}

//��������
void UQuestSubsystem::ReceiveQuest(int32 QuestID)
{
	//�޸�����״̬
	SetQuestState(QuestID, EQuestState::QES_Received);


	//��������UI,���"���ڽ�����"�������б�UI��
}

void UQuestSubsystem::CompleteQuest(int32 QuestID)
{
	//�޸�����״̬
	SetQuestState(QuestID, EQuestState::QES_Completed);

	//��������UI���޸ĵ�"����δ��ȡ"�������б�UI��


	//�ж��Ƿ����ֱ����ȡ����
	if (GetQuestInfoByID(QuestID).IsAutoComplete == true) 
	{
		GetQuestReward(QuestID);
	}

}

void UQuestSubsystem::GetQuestReward(int32 QuestID)
{
	//�޸�����״̬
	SetQuestState(QuestID, EQuestState::QES_RewardReceived);

	FQuestBase Quest = GetQuestInfoByID(QuestID);
	for (auto& it : Quest.QuestRewards)
	{
		//������Ʒ��ί��
		;
	}

	//����UI,��"����δ��ȡ"�������б�UIɾ��

}

FQuestBase UQuestSubsystem::GetQuestInfoByID(int32 QuestID)
{
	FQuestBase Quest;
	for (auto& it : AllQuestsData)
	{
		if (QuestID == it.QuestID)
		{
			Quest = it;
			return Quest;
		}
	}
	return Quest;
}

//��ȡ��ǰ�����ѽ��յ�����
TArray<FQuestBase> UQuestSubsystem::GetReceivedQuests()
{
	TArray<FQuestBase> ReceivedQuestsList;
	for (auto& it : AllQuestsData)
	{
		if (it.QuestState == EQuestState::QES_Received)
		{
			ReceivedQuestsList.Add(it);
		}
	}
	return ReceivedQuestsList;
}

//��ȡ��ǰ��������ɵ�����
TArray<FQuestBase> UQuestSubsystem::GetCompletedQuests()
{
	TArray<FQuestBase> CompletedQuestsList;
	for (auto& it : AllQuestsData)
	{
		if (it.QuestState == EQuestState::QES_Completed)
		{
			CompletedQuestsList.Add(it);
		}
	}
	return CompletedQuestsList;
}

//ͨ��ItemID��鱳���ж��������Ʒ
int32 UQuestSubsystem::GetItemNumByID(int32 ItemID)
{
	int ItemNum = 0;
	//GetItemInfo.BindDynamic(this, &UInventoryManager::FindItemInforByID);
	/*auto ItemDetails = GetItemInfo.ExecuteIfBound(ItemID);
	ItemNum = ItemDetails.CurrentNum;*/
	return ItemNum;
}

EQuestState UQuestSubsystem::GetQuestState(int32 QuestID)
{
	return GetQuestInfoByID(QuestID).QuestState;
}

//�޸�����״̬
void UQuestSubsystem::SetQuestState(int32 QuestID, EQuestState NewState)
{
	for (auto& it : AllQuestsData)
	{
		if (QuestID == it.QuestID)
		{
			it.QuestState = NewState;
			return;
		}
	}
}

void UQuestSubsystem::SetNPCQuestHintIcon()
{

}

