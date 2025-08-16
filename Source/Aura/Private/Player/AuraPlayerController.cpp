// ChenGangQiang All rights Reserved.


#include "Player/AuraPlayerController.h"
#include "EnhancedInputSubsystems.h"

AAuraPlayerController::AAuraPlayerController()
{
	// 启用网络同步，允许在多人游戏中同步此控制器的状态
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();

	check(AuraContext);

	// 获取本地玩家的增强输入子系统，并添加输入映射上下文
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(AuraContext, 0);

	bShowMouseCursor = true; // 显示鼠标光标
	DefaultMouseCursor = EMouseCursor::Default; // 设置默认鼠标光标样式

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock); // 不锁定鼠标到视口
	InputModeData.SetHideCursorDuringCapture(false); // 在捕获时不隐藏光标
	SetInputMode(InputModeData);
}
